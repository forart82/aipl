/* AIPL C99 runtime module: rt_sys.c (Phase 18 split modular runtime). */
#include "aipl_runtime.h"
#ifndef _WIN32
#include <poll.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

static void _aipl_try_execvp_direct(const char* cmd, AiplVal args_val) {
  if (!cmd || !cmd[0]) return;
  if (strchr(cmd, ' ') != NULL || strchr(cmd, '|') != NULL || strchr(cmd, '&') != NULL ||
      strchr(cmd, '>') != NULL || strchr(cmd, '<') != NULL || strchr(cmd, ';') != NULL) {
    return;
  }
  int64_t n_args = (args_val.kind == AIPL_ARRAY && args_val.ptr) ? ((AiplArray*)args_val.ptr)->len : 0;
  if (n_args < 0) n_args = 0;
  char** argv_exec = (char**)malloc((size_t)(n_args + 2) * sizeof(char*));
  if (!argv_exec) return;
  int64_t argc_exec = 0;
  argv_exec[argc_exec++] = (char*)cmd;
  if (args_val.kind == AIPL_ARRAY && args_val.ptr) {
    AiplArray* a = (AiplArray*)args_val.ptr;
    for (int64_t i = 0; i < a->len; i++) {
      AiplVal arg_str = aipl_to_str(a->data[i]);
      const char* s = arg_str.s ? arg_str.s : "";
      size_t slen = strlen(s);
      if (slen >= 2 && s[0] == '\'' && s[slen - 1] == '\'' && strchr(s + 1, '\'') == s + slen - 1) {
        char* unquoted = (char*)malloc(slen - 1);
        if (unquoted) {
          memcpy(unquoted, s + 1, slen - 2);
          unquoted[slen - 2] = 0;
          argv_exec[argc_exec++] = unquoted;
          continue;
        }
      }
      argv_exec[argc_exec++] = (char*)s;
    }
  }
  argv_exec[argc_exec] = NULL;
  execvp(cmd, argv_exec);
  free(argv_exec);
}
#endif

AiplVal aipl_rt_execCommand(AiplVal cmd_val, AiplVal args_val) {
  const char* cmd = cmd_val.s ? cmd_val.s : "";
  int seq = __sync_fetch_and_add(&g_aipl_cmd_seq, 1);
  char out_file[256]; char err_file[256];
  snprintf(out_file, sizeof(out_file), "/tmp/aipl_cmd_%d_%d_out.txt", (int)getpid(), seq);
  snprintf(err_file, sizeof(err_file), "/tmp/aipl_cmd_%d_%d_err.txt", (int)getpid(), seq);
  char full_cmd[4096];
  snprintf(full_cmd, sizeof(full_cmd), "%s", cmd);
  if (args_val.kind == AIPL_ARRAY && args_val.ptr) {
    AiplArray* a = (AiplArray*)args_val.ptr;
    for (int64_t i = 0; i < a->len; i++) {
      AiplVal arg_str = aipl_to_str(a->data[i]);
      strncat(full_cmd, " ", sizeof(full_cmd) - strlen(full_cmd) - 1);
      strncat(full_cmd, arg_str.s ? arg_str.s : "", sizeof(full_cmd) - strlen(full_cmd) - 1);
    }
  }
#ifndef _WIN32
  const char* env_detach = getenv("AIPL_EXEC_DETACH");
  const char* nohup_tail = strstr(full_cmd, " >/dev/null 2>&1 & echo $!");
  int is_nohup_detach = (strncmp(full_cmd, "nohup ", 6) == 0 && nohup_tail != NULL);
  if ((env_detach && strcmp(env_detach, "1") == 0) || is_nohup_detach) {
    char detached_cmd[4096];
    if (is_nohup_detach) {
      size_t inner_len = (size_t)(nohup_tail - (full_cmd + 6));
      if (inner_len >= sizeof(detached_cmd)) inner_len = sizeof(detached_cmd) - 1;
      memcpy(detached_cmd, full_cmd + 6, inner_len);
      detached_cmd[inner_len] = 0;
    } else {
      snprintf(detached_cmd, sizeof(detached_cmd), "%s", full_cmd);
    }
    const char* env_already = getenv("AIPL_ALREADY_DETACHED");
    if (!is_nohup_detach && env_already && strcmp(env_already, "1") == 0) {
      unsetenv("AIPL_EXEC_DETACH");
      unsetenv("AIPL_EXEC_STREAM");
      unsetenv("AIPL_EXEC_DIRECT");
      unsetenv("AIPL_ALREADY_DETACHED");
      int logfd = open("/tmp/aipl-run-last.log", O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW, 0644);
      if (logfd >= 0) {
        dup2(logfd, STDOUT_FILENO);
        dup2(logfd, STDERR_FILENO);
        if (logfd > 2) close(logfd);
      }
      _aipl_try_execvp_direct(cmd, args_val);
      execl("/bin/sh", "sh", "-c", detached_cmd, (char*)NULL);
      _exit(127);
    }
    pid_t pid = fork();
    if (pid < 0) {
      return aipl_err(aipl_str("fork() failed in detached exec"));
    }
    if (pid == 0) {
      setsid();
      signal(SIGHUP, SIG_IGN);
      unsetenv("AIPL_EXEC_DETACH");
      unsetenv("AIPL_EXEC_STREAM");
      unsetenv("AIPL_EXEC_DIRECT");
      /* Only an inner `aipl run` may consume this marker (to exec in place so $! is the app pid); never leak it
         into arbitrary detached programs, which would otherwise make their own later `aipl run` calls exec-replace them. */
      if (is_nohup_detach && strstr(detached_cmd, " run ") != NULL) setenv("AIPL_ALREADY_DETACHED", "1", 1);
      else unsetenv("AIPL_ALREADY_DETACHED");
      int devnull = open("/dev/null", O_RDONLY);
      if (devnull >= 0) {
        dup2(devnull, STDIN_FILENO);
        if (devnull > 2) close(devnull);
      }
      int logfd = is_nohup_detach ? open("/dev/null", O_WRONLY) : open("/tmp/aipl-run-last.log", O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW, 0644);
      if (logfd < 0) logfd = open("/dev/null", O_WRONLY);
      if (logfd >= 0) {
        dup2(logfd, STDOUT_FILENO);
        dup2(logfd, STDERR_FILENO);
        if (logfd > 2) close(logfd);
      }
      for (int fd = 3; fd < 256; fd++) close(fd);
      if (!is_nohup_detach) {
        _aipl_try_execvp_direct(cmd, args_val);
      } else if (strpbrk(detached_cmd, ";&|\n`$()") == NULL && strncmp(detached_cmd, "exec ", 5) != 0) {
        char exec_cmd[4200];
        snprintf(exec_cmd, sizeof(exec_cmd), "exec %s", detached_cmd);
        execl("/bin/sh", "sh", "-c", exec_cmd, (char*)NULL);
      }
      execl("/bin/sh", "sh", "-c", detached_cmd, (char*)NULL);
      _exit(127);
    }
    char pid_str[32];
    snprintf(pid_str, sizeof(pid_str), "%d\n", (int)pid);
    AiplVal outVal = aipl_struct_new("ProcessOutput", 3,
      (const char*[]){ "status", "stdout", "stderr" },
      (AiplVal[]){ aipl_int(0), aipl_str(pid_str), aipl_str("") });
    return aipl_ok(outVal);
  }

  const char* env_replace = getenv("AIPL_EXEC_REPLACE");
  if (env_replace && strcmp(env_replace, "1") == 0) {
    unsetenv("AIPL_EXEC_REPLACE");
    unsetenv("AIPL_EXEC_STREAM");
    unsetenv("AIPL_EXEC_DIRECT");
    _aipl_try_execvp_direct(cmd, args_val);
    execl("/bin/sh", "sh", "-c", full_cmd, (char*)NULL);
    _exit(127);
  }

  const char* env_stream = getenv("AIPL_EXEC_STREAM");
  const char* env_direct = getenv("AIPL_EXEC_DIRECT");
  int do_stream = (env_stream && strcmp(env_stream, "1") == 0);
  int do_direct = (env_direct && strcmp(env_direct, "1") == 0);
  int exit_code = 0;
  int streamed_ok = 0;
  if (do_stream || do_direct) {
    int out_pipe[2], err_pipe[2];
    if (pipe(out_pipe) == 0) {
      if (pipe(err_pipe) == 0) {
        pid_t pid = fork();
        if (pid == 0) {
          unsetenv("AIPL_EXEC_STREAM");
          unsetenv("AIPL_EXEC_DIRECT");
          close(out_pipe[0]); close(err_pipe[0]);
          dup2(out_pipe[1], STDOUT_FILENO);
          dup2(err_pipe[1], STDERR_FILENO);
          close(out_pipe[1]); close(err_pipe[1]);
          _aipl_try_execvp_direct(cmd, args_val);
          execl("/bin/sh", "sh", "-c", full_cmd, (char*)NULL);
          _exit(127);
        } else if (pid > 0) {
          streamed_ok = 1;
          close(out_pipe[1]); close(err_pipe[1]);
          FILE* f_out = fopen(out_file, "wb");
          FILE* f_err = fopen(err_file, "wb");
          struct pollfd pfds[2];
          pfds[0].fd = out_pipe[0]; pfds[0].events = POLLIN;
          pfds[1].fd = err_pipe[0]; pfds[1].events = POLLIN;
          int open_pipes = 2;
          char buf[4096];
          while (open_pipes > 0) {
            int pr = poll(pfds, 2, -1);
            if (pr < 0) {
              if (errno == EINTR) continue;
              break;
            }
            for (int pi = 0; pi < 2; pi++) {
              if (pfds[pi].fd < 0) continue;
              if (pfds[pi].revents & (POLLIN | POLLHUP | POLLERR)) {
                ssize_t n = read(pfds[pi].fd, buf, sizeof(buf));
                if (n > 0) {
                  if (pi == 0) {
                    if (f_out) fwrite(buf, 1, (size_t)n, f_out);
                    if (do_stream) {
                      fwrite(buf, 1, (size_t)n, stdout);
                      fflush(stdout);
                    }
                  } else {
                    if (f_err) fwrite(buf, 1, (size_t)n, f_err);
                    if (do_stream) {
                      fwrite(buf, 1, (size_t)n, stderr);
                      fflush(stderr);
                    }
                  }
                } else {
                  close(pfds[pi].fd);
                  pfds[pi].fd = -1;
                  open_pipes--;
                }
              }
            }
          }
          if (f_out) fclose(f_out);
          if (f_err) fclose(f_err);
          int wstatus = 0;
          while (waitpid(pid, &wstatus, 0) < 0 && errno == EINTR) {}
          if (WIFEXITED(wstatus)) exit_code = WEXITSTATUS(wstatus);
          else if (WIFSIGNALED(wstatus)) exit_code = 128 + WTERMSIG(wstatus);
          else exit_code = wstatus;
        } else {
          close(out_pipe[0]); close(out_pipe[1]);
          close(err_pipe[0]); close(err_pipe[1]);
        }
      } else {
        close(out_pipe[0]); close(out_pipe[1]);
      }
    }
  }
  if (!streamed_ok) {
    char exec_buf[5000]; snprintf(exec_buf, sizeof(exec_buf), "%s > %s 2> %s", full_cmd, out_file, err_file);
    int status = system(exec_buf);
    if (WIFEXITED(status)) exit_code = WEXITSTATUS(status); else exit_code = status;
  }
#else
  char exec_buf[5000]; snprintf(exec_buf, sizeof(exec_buf), "%s > %s 2> %s", full_cmd, out_file, err_file);
  int status = system(exec_buf); int exit_code = 0;
  if (WIFEXITED(status)) exit_code = WEXITSTATUS(status); else exit_code = status;
#endif
  FILE* f1 = fopen(out_file, "rb"); char* out_s = NULL;
  if (f1) {
    fseek(f1, 0, SEEK_END); long sz = ftell(f1); fseek(f1, 0, SEEK_SET);
    if (sz > 0) { out_s = (char*)malloc(sz + 1); size_t nr = fread(out_s, 1, sz, f1); out_s[nr] = 0; }
    fclose(f1);
  }
  FILE* f2 = fopen(err_file, "rb"); char* err_s = NULL;
  if (f2) {
    fseek(f2, 0, SEEK_END); long sz = ftell(f2); fseek(f2, 0, SEEK_SET);
    if (sz > 0) { err_s = (char*)malloc(sz + 1); size_t nr = fread(err_s, 1, sz, f2); err_s[nr] = 0; }
    fclose(f2);
  }
  unlink(out_file); unlink(err_file);
  AiplVal outVal = aipl_struct_new("ProcessOutput", 3,
    (const char*[]){ "status", "stdout", "stderr" },
    (AiplVal[]){ aipl_int(exit_code), aipl_str(out_s ? out_s : ""), aipl_str(err_s ? err_s : "") });
  if (out_s) { free(out_s); }
  if (err_s) { free(err_s); }
  return aipl_ok(outVal);
}

AiplVal aipl_rt_exit(AiplVal code) { exit((int)code.i); return aipl_nil(); }

AiplVal aipl_rt_panic(AiplVal msg) { AiplVal s = aipl_to_str(msg); fprintf(stderr, "panic: %s\n", s.s ? s.s : ""); exit(1); return aipl_nil(); }

AiplVal aipl_rt_hardware_concurrency(void) {
  const char* env_jobs = getenv("AIPL_JOBS");
  if (env_jobs && env_jobs[0]) {
    long j = atol(env_jobs);
    if (j > 0) return aipl_int(j);
  }
#ifdef _WIN32
  SYSTEM_INFO sysinfo;
  GetSystemInfo(&sysinfo);
  long n = (long)sysinfo.dwNumberOfProcessors;
#else
  long n = sysconf(_SC_NPROCESSORS_ONLN);
#endif
  if (n <= 0) return aipl_int(8);
  long capped = n > 2 ? n - 2 : n;
  if (capped > 14) capped = 14;
  return aipl_int(capped);
}

AiplVal aipl_rt_exec_parallel(AiplVal cmds_val, AiplVal max_jobs_val) {
  if (cmds_val.kind != AIPL_ARRAY || !cmds_val.ptr) return aipl_array_new(NULL, 0);
  AiplArray* cmds_arr = (AiplArray*)cmds_val.ptr;
  int64_t total = cmds_arr->len;
  if (total <= 0) return aipl_array_new(NULL, 0);
  int64_t max_jobs = (max_jobs_val.kind == AIPL_INT) ? max_jobs_val.i : (int64_t)max_jobs_val.f;
  if (max_jobs <= 0) max_jobs = aipl_rt_hardware_concurrency().i;
  if (max_jobs < 1) max_jobs = 1;
  if (max_jobs > total) max_jobs = total;
  AiplVal* results = (AiplVal*)malloc(sizeof(AiplVal) * (size_t)total);
  for (int64_t i = 0; i < total; i++) results[i] = aipl_int(1);
#ifndef _WIN32
  typedef struct { pid_t pid; int64_t cmd_idx; } AiplActiveSlot;
  AiplActiveSlot* slots = (AiplActiveSlot*)malloc(sizeof(AiplActiveSlot) * (size_t)max_jobs);
  for (int64_t j = 0; j < max_jobs; j++) { slots[j].pid = 0; slots[j].cmd_idx = -1; }
  int64_t next_cmd = 0; int64_t active_count = 0;
  while (next_cmd < total || active_count > 0) {
    while (active_count < max_jobs && next_cmd < total) {
      int64_t cur_idx = next_cmd++;
      AiplVal cval = aipl_to_str(cmds_arr->data[cur_idx]);
      const char* cmd_str = cval.s ? cval.s : "";
      pid_t pid = fork();
      if (pid < 0) { results[cur_idx] = aipl_int(1); break; }
      else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmd_str, (char*)NULL);
        _exit(127);
      } else {
        for (int64_t j = 0; j < max_jobs; j++) {
          if (slots[j].pid == 0) { slots[j].pid = pid; slots[j].cmd_idx = cur_idx; active_count++; break; }
        }
      }
    }
    if (active_count > 0) {
      int status = 0; pid_t done_pid = waitpid(-1, &status, 0);
      if (done_pid > 0) {
        int exit_code = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
        for (int64_t j = 0; j < max_jobs; j++) {
          if (slots[j].pid == done_pid) {
            if (slots[j].cmd_idx >= 0 && slots[j].cmd_idx < total) results[slots[j].cmd_idx] = aipl_int(exit_code);
            slots[j].pid = 0; slots[j].cmd_idx = -1; active_count--; break;
          }
        }
      } else if (done_pid < 0) { break; }
    }
  }
  free(slots);
#else
  for (int64_t i = 0; i < total; i++) {
    AiplVal cval = aipl_to_str(cmds_arr->data[i]);
    const char* cmd_str = cval.s ? cval.s : "";
    int status = system(cmd_str);
    int exit_code = (status == 0) ? 0 : (status > 0 ? status : 1);
    results[i] = aipl_int(exit_code);
  }
#endif
  AiplVal res_arr = aipl_array_new(results, total);
  free(results);
  return res_arr;
}

AiplVal aipl_rt_nowMs(void) {
  struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts);
  return aipl_int((int64_t)ts.tv_sec * 1000 + (int64_t)(ts.tv_nsec / 1000000));
}

AiplVal aipl_rt_nowUnixMs(void) { return aipl_rt_nowMs(); }

AiplVal aipl_rt_nowMonoNs(void) {
  struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts);
  return aipl_int((int64_t)ts.tv_sec * 1000000000LL + (int64_t)ts.tv_nsec);
}

AiplVal aipl_rt_sleepMs(AiplVal ms_val) {
  while (ms_val.kind == AIPL_RES_OK || ms_val.kind == AIPL_OPT_SOME) {
    ms_val = ms_val.ptr ? *(AiplVal*)ms_val.ptr : aipl_int(0);
  }
  int64_t ms = (ms_val.kind == AIPL_INT) ? ms_val.i : (ms_val.kind == AIPL_FLOAT ? (int64_t)ms_val.f : 0);
  if (ms > 0) { struct timespec req; req.tv_sec = ms / 1000; req.tv_nsec = (ms % 1000) * 1000000; nanosleep(&req, NULL); }
  return aipl_nil();
}

// --- Dynamic C FFI Subsystem ---
void** _aipl_ffi_handles = NULL;
int _aipl_ffi_cap = 0;
int _aipl_ffi_count = 0;
static void _aipl_ensure_ffi_slot(int slot) {
  if (slot < _aipl_ffi_cap) return;
  if (slot > 65536) return;
  int new_cap = _aipl_ffi_cap > 0 ? _aipl_ffi_cap * 2 : 64;
  while (new_cap <= slot) new_cap *= 2;
  void** next = (void**)realloc(_aipl_ffi_handles, (size_t)new_cap * sizeof(void*));
  if (!next) return;
  memset(next + _aipl_ffi_cap, 0, (size_t)(new_cap - _aipl_ffi_cap) * sizeof(void*));
  _aipl_ffi_handles = next;
  _aipl_ffi_cap = new_cap;
}
AiplVal aipl_rt_ffiOpen(AiplVal libPath) {
#ifndef _WIN32
  const char* p = libPath.s ? libPath.s : "";
  void* h = NULL;
  if (strlen(p) == 0 || strcmp(p, "libc") == 0 || strcmp(p, "libc.so.6") == 0) {
    h = dlopen("libc.so.6", RTLD_LAZY);
    if (!h) h = dlopen(NULL, RTLD_LAZY);
  } else if (strcmp(p, "libm") == 0 || strcmp(p, "libm.so.6") == 0) {
    h = dlopen("libm.so.6", RTLD_LAZY);
    if (!h) h = dlopen(NULL, RTLD_LAZY);
  } else {
    h = dlopen(p, RTLD_LAZY);
  }
  if (h) {
    _aipl_ensure_ffi_slot(_aipl_ffi_count + 1);
    if (_aipl_ffi_handles && _aipl_ffi_count + 1 < _aipl_ffi_cap) {
      _aipl_ffi_count++;
      _aipl_ffi_handles[_aipl_ffi_count] = h;
      return aipl_int(_aipl_ffi_count);
    }
    dlclose(h);
  }
  return aipl_int(0);
#else
  (void)libPath;
  return aipl_int(0);
#endif
}

AiplVal aipl_rt_ffiHasSymbol(AiplVal hVal, AiplVal symVal) {
#ifndef _WIN32
  void* h = (hVal.i > 0 && hVal.i <= _aipl_ffi_count) ? _aipl_ffi_handles[hVal.i] : NULL;
  const char* sym = symVal.s ? symVal.s : "";
  if (!h || strlen(sym) == 0) return aipl_bool(0);
  void* s = dlsym(h, sym);
  return aipl_bool(s != NULL);
#else
  (void)hVal; (void)symVal;
  return aipl_bool(0);
#endif
}

AiplVal aipl_rt_ffiCallInt(AiplVal hVal, AiplVal symVal, AiplVal argsVal) {
#ifndef _WIN32
  void* h = (hVal.i > 0 && hVal.i <= _aipl_ffi_count) ? _aipl_ffi_handles[hVal.i] : NULL;
  const char* symName = symVal.s ? symVal.s : "";
  if (!h || strlen(symName) == 0) return aipl_int(0);
  void* sym = dlsym(h, symName);
  if (!sym) return aipl_int(0);
  int64_t argc = (argsVal.kind == AIPL_ARRAY && argsVal.ptr) ? ((AiplArray*)argsVal.ptr)->len : 0;
  AiplVal* argv = (argc > 0) ? ((AiplArray*)argsVal.ptr)->data : NULL;
  int64_t a0 = 0, a1 = 0, a2 = 0, a3 = 0;
  if (argsVal.kind == AIPL_ARRAY && argsVal.ptr) {
    if (argc > 0) a0 = (argv[0].kind == AIPL_STR) ? (int64_t)(intptr_t)argv[0].s : ((argv[0].kind == AIPL_FLOAT) ? (int64_t)argv[0].f : argv[0].i);
    if (argc > 1) a1 = (argv[1].kind == AIPL_STR) ? (int64_t)(intptr_t)argv[1].s : ((argv[1].kind == AIPL_FLOAT) ? (int64_t)argv[1].f : argv[1].i);
    if (argc > 2) a2 = (argv[2].kind == AIPL_STR) ? (int64_t)(intptr_t)argv[2].s : ((argv[2].kind == AIPL_FLOAT) ? (int64_t)argv[2].f : argv[2].i);
    if (argc > 3) a3 = (argv[3].kind == AIPL_STR) ? (int64_t)(intptr_t)argv[3].s : ((argv[3].kind == AIPL_FLOAT) ? (int64_t)argv[3].f : argv[3].i);
  } else if (argsVal.kind != AIPL_NIL) {
    argc = 1;
    a0 = (argsVal.kind == AIPL_STR) ? (int64_t)(intptr_t)argsVal.s : ((argsVal.kind == AIPL_FLOAT) ? (int64_t)argsVal.f : argsVal.i);
  }
  if (strcmp(symName, "abs") == 0) {
    int r = ((int(*)(int))sym)((int)a0);
    return aipl_int((int64_t)r);
  }
  int64_t res = 0;
  if (argc == 0) {
    res = ((int64_t(*)(void))sym)();
  } else if (argc == 1) {
    res = ((int64_t(*)(int64_t))sym)(a0);
  } else if (argc == 2) {
    res = ((int64_t(*)(int64_t, int64_t))sym)(a0, a1);
  } else if (argc == 3) {
    res = ((int64_t(*)(int64_t, int64_t, int64_t))sym)(a0, a1, a2);
  } else {
    res = ((int64_t(*)(int64_t, int64_t, int64_t, int64_t))sym)(a0, a1, a2, a3);
  }
  return aipl_int(res);
#else
  (void)hVal; (void)symVal; (void)argsVal;
  return aipl_int(0);
#endif
}

AiplVal aipl_rt_ffiCallFloat(AiplVal hVal, AiplVal symVal, AiplVal argsVal) {
#ifndef _WIN32
  void* h = (hVal.i > 0 && hVal.i <= _aipl_ffi_count) ? _aipl_ffi_handles[hVal.i] : NULL;
  const char* symName = symVal.s ? symVal.s : "";
  if (!h || strlen(symName) == 0) return aipl_float(0.0);
  void* sym = dlsym(h, symName);
  if (!sym) return aipl_float(0.0);
  int64_t argc = (argsVal.kind == AIPL_ARRAY && argsVal.ptr) ? ((AiplArray*)argsVal.ptr)->len : 0;
  AiplVal* argv = (argc > 0) ? ((AiplArray*)argsVal.ptr)->data : NULL;
  double d0 = 0.0, d1 = 0.0, d2 = 0.0;
  if (argsVal.kind == AIPL_ARRAY && argsVal.ptr) {
    if (argc > 0) d0 = (argv[0].kind == AIPL_FLOAT) ? argv[0].f : (double)argv[0].i;
    if (argc > 1) d1 = (argv[1].kind == AIPL_FLOAT) ? argv[1].f : (double)argv[1].i;
    if (argc > 2) d2 = (argv[2].kind == AIPL_FLOAT) ? argv[2].f : (double)argv[2].i;
  } else if (argsVal.kind != AIPL_NIL) {
    argc = 1;
    d0 = (argsVal.kind == AIPL_FLOAT) ? argsVal.f : (double)argsVal.i;
  }
  double res = 0.0;
  if (argc == 0) {
    res = ((double(*)(void))sym)();
  } else if (argc == 1) {
    res = ((double(*)(double))sym)(d0);
  } else if (argc == 2) {
    res = ((double(*)(double, double))sym)(d0, d1);
  } else {
    res = ((double(*)(double, double, double))sym)(d0, d1, d2);
  }
  return aipl_float(res);
#else
  (void)hVal; (void)symVal; (void)argsVal;
  return aipl_float(0.0);
#endif
}

AiplVal aipl_rt_ffiCallStr(AiplVal hVal, AiplVal symVal, AiplVal argVal) {
#ifndef _WIN32
  void* h = (hVal.i > 0 && hVal.i <= _aipl_ffi_count) ? _aipl_ffi_handles[hVal.i] : NULL;
  const char* symName = symVal.s ? symVal.s : "";
  if (!h || strlen(symName) == 0) return aipl_str_lit("");
  void* sym = dlsym(h, symName);
  if (!sym) return aipl_str_lit("");
  const char* inStr = argVal.s ? argVal.s : "";
  const char* r = ((const char*(*)(const char*))sym)(inStr);
  return aipl_str_lit(r ? r : "");
#else
  (void)hVal; (void)symVal; (void)argVal;
  return aipl_str_lit("");
#endif
}

AiplVal aipl_rt_ffiClose(AiplVal hVal) {
#ifndef _WIN32
  if (hVal.i > 0 && hVal.i <= _aipl_ffi_count && _aipl_ffi_handles && _aipl_ffi_handles[hVal.i]) {
    dlclose(_aipl_ffi_handles[hVal.i]);
    _aipl_ffi_handles[hVal.i] = NULL;
  }
  return aipl_bool(1);
#else
  (void)hVal;
  return aipl_bool(1);
#endif
}

static char* _aipl_composition_buf = NULL;
static size_t _aipl_composition_cap = 0;
static int _aipl_composition_cursor = 0;
static char* _aipl_clipboard_buf = NULL;
static size_t _aipl_clipboard_cap = 0;
static int _aipl_gpu_probed = 0;
static int _aipl_gpu_accelerated = 0;
static int _aipl_force_software_rasterizer = -1;
static const char* _aipl_gpu_backend_name = "CPU SIMD Fallback";

void _aipl_composition_set(const char* s, int cursor) {
  size_t n = s ? strlen(s) : 0;
  if (n + 1 > _aipl_composition_cap) {
    size_t nc = _aipl_composition_cap > 0 ? _aipl_composition_cap * 2 : 128;
    while (nc < n + 1) nc *= 2;
    char* nb = (char*)realloc(_aipl_composition_buf, nc);
    if (!nb) return;
    _aipl_composition_buf = nb;
    _aipl_composition_cap = nc;
  }
  if (_aipl_composition_buf) {
    if (n > 0) memcpy(_aipl_composition_buf, s, n);
    _aipl_composition_buf[n] = 0;
  }
  _aipl_composition_cursor = cursor >= 0 ? cursor : 0;
}

AiplVal aipl_rt_getCompositionText(void) {
  return aipl_str(_aipl_composition_buf ? _aipl_composition_buf : "");
}

AiplVal aipl_rt_getCompositionCursor(void) {
  return aipl_int(_aipl_composition_cursor);
}

AiplVal aipl_rt_getClipboardText(void) {
  return aipl_str(_aipl_clipboard_buf ? _aipl_clipboard_buf : "");
}

AiplVal aipl_rt_setClipboardText(AiplVal text) {
  const char* s = (text.kind == AIPL_STR && text.s) ? text.s : "";
  size_t n = strlen(s);
  if (n + 1 > _aipl_clipboard_cap) {
    size_t nc = _aipl_clipboard_cap > 0 ? _aipl_clipboard_cap * 2 : 256;
    while (nc < n + 1) nc *= 2;
    char* nb = (char*)realloc(_aipl_clipboard_buf, nc);
    if (!nb) return aipl_bool(false);
    _aipl_clipboard_buf = nb;
    _aipl_clipboard_cap = nc;
  }
  if (n > 0) memcpy(_aipl_clipboard_buf, s, n);
  _aipl_clipboard_buf[n] = 0;
#if defined(AIPL_ENABLE_GUI_AUDIO) && !defined(_WIN32)
  if (_aipl_window_backend == 1 && _aipl_x11_dpy && _aipl_x11_win && _aipl_x11_lib && _aipl_X11_XInternAtom) {
    typedef int (*XSetSelectionOwnerFn)(void*, unsigned long, unsigned long, unsigned long);
    XSetSelectionOwnerFn fn_own = (XSetSelectionOwnerFn)dlsym(_aipl_x11_lib, "XSetSelectionOwner");
    if (fn_own) {
      unsigned long clip_atom = _aipl_X11_XInternAtom(_aipl_x11_dpy, "CLIPBOARD", 0);
      if (clip_atom) fn_own(_aipl_x11_dpy, clip_atom, _aipl_x11_win, 0UL);
      fn_own(_aipl_x11_dpy, 1UL, _aipl_x11_win, 0UL);
      if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
    }
  }
#endif
  return aipl_bool(true);
}

static void _aipl_probe_gpu_backend(void) {
  if (_aipl_force_software_rasterizer == 1) {
    _aipl_gpu_accelerated = 0;
    _aipl_gpu_backend_name = "CPU SIMD Fallback";
    _aipl_gpu_probed = 1;
    return;
  }
  if (_aipl_force_software_rasterizer < 0) {
    const char* env_sw = getenv("AIPL_SOFTWARE_RASTERIZER");
    if (env_sw && env_sw[0] && strcmp(env_sw, "0") != 0) {
      _aipl_force_software_rasterizer = 1;
      _aipl_gpu_accelerated = 0;
      _aipl_gpu_backend_name = "CPU SIMD Fallback";
      _aipl_gpu_probed = 1;
      return;
    }
    if (g_aipl_argv) {
      for (int i = 1; i < g_aipl_argc; i++) {
        if (g_aipl_argv[i] && (strcmp(g_aipl_argv[i], "--software") == 0 || strcmp(g_aipl_argv[i], "--cpu-rasterizer") == 0)) {
          _aipl_force_software_rasterizer = 1;
          _aipl_gpu_accelerated = 0;
          _aipl_gpu_backend_name = "CPU SIMD Fallback";
          _aipl_gpu_probed = 1;
          return;
        }
      }
    }
  }
  if (_aipl_gpu_probed) return;
  _aipl_gpu_probed = 1;
#ifndef _WIN32
  int headless = 0;
  const char* env_hl = getenv("AIPL_HEADLESS");
  if (env_hl && env_hl[0] && strcmp(env_hl, "0") != 0) headless = 1;
  if (g_aipl_argv) {
    for (int i = 1; i < g_aipl_argc; i++) {
      if (g_aipl_argv[i] && strcmp(g_aipl_argv[i], "--headless") == 0) headless = 1;
    }
  }
  int has_dri_or_dpy = ((getenv("DISPLAY") && getenv("DISPLAY")[0]) || access("/dev/dri/renderD128", R_OK) == 0 || access("/dev/dri/card0", R_OK) == 0);
  if ((!headless && has_dri_or_dpy) || _aipl_force_software_rasterizer == 0) {
    void* gl_lib = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
    if (!gl_lib) gl_lib = dlopen("libEGL.so.1", RTLD_LAZY | RTLD_LOCAL);
    if (gl_lib) {
      _aipl_gpu_accelerated = 1;
      _aipl_gpu_backend_name = "OpenGL 3.3";
      return;
    }
    void* vk_lib = dlopen("libvulkan.so.1", RTLD_LAZY | RTLD_LOCAL);
    if (vk_lib) {
      _aipl_gpu_accelerated = 1;
      _aipl_gpu_backend_name = "Vulkan 1.3";
      return;
    }
  }
#endif
  _aipl_gpu_accelerated = 0;
  _aipl_gpu_backend_name = "CPU SIMD Fallback";
}

AiplVal aipl_rt_isGpuAccelerated(void) {
  _aipl_probe_gpu_backend();
  return aipl_bool(_aipl_gpu_accelerated != 0);
}

AiplVal aipl_rt_getGraphicsBackendName(void) {
  _aipl_probe_gpu_backend();
  return aipl_str(_aipl_gpu_backend_name);
}

AiplVal aipl_rt_setSoftwareRasterizer(AiplVal force) {
  _aipl_force_software_rasterizer = aipl_truthy(force) ? 1 : 0;
  _aipl_gpu_probed = 0;
  _aipl_probe_gpu_backend();
  return aipl_nil();
}

int _aipl_requested_window_mode = 1;
int _aipl_cli_window_mode_override = -1;
char _aipl_window_mode_name[16] = "x11";
int _aipl_ipc_telemetry_active = 0;
int _aipl_multi_seat_active = 0;

static void _aipl_apply_window_mode_str(const char* raw, int is_cli_or_env) {
  if (!raw || !raw[0]) return;
  while (*raw && isspace((unsigned char)*raw)) raw++;
  if (strcasecmp(raw, "glx") == 0 || strcasecmp(raw, "game") == 0 || strcasecmp(raw, "gl") == 0 || strcasecmp(raw, "opengl") == 0) {
    _aipl_requested_window_mode = 2;
    strcpy(_aipl_window_mode_name, "glx");
    _aipl_force_software_rasterizer = 0;
    if (is_cli_or_env) _aipl_cli_window_mode_override = 2;
  } else if (strcasecmp(raw, "auto") == 0) {
    _aipl_requested_window_mode = 0;
    strcpy(_aipl_window_mode_name, "auto");
    _aipl_force_software_rasterizer = 0;
    if (is_cli_or_env) _aipl_cli_window_mode_override = 0;
  } else {
    _aipl_requested_window_mode = 1;
    strcpy(_aipl_window_mode_name, "x11");
    _aipl_force_software_rasterizer = 1;
    if (is_cli_or_env) _aipl_cli_window_mode_override = 1;
  }
  _aipl_gpu_probed = 0;
}

AiplVal aipl_rt_setWindowMode(AiplVal mode) {
#ifdef AIPL_ENABLE_GUI_AUDIO
  _aipl_check_fps_cli_flags();
#endif
  const char* s = (mode.kind == AIPL_STR && mode.s) ? mode.s : "x11";
  _aipl_apply_window_mode_str(s, 0);
#ifndef _WIN32
  setenv("AIPL_WINDOW_MODE", _aipl_window_mode_name, 1);
#endif
  return aipl_nil();
}

AiplVal aipl_rt_getWindowMode(void) {
#ifdef AIPL_ENABLE_GUI_AUDIO
  _aipl_check_fps_cli_flags();
#endif
  return aipl_str(_aipl_window_mode_name);
}

void aipl_unpack_color(AiplVal c, uint8_t* r, uint8_t* g, uint8_t* b, uint8_t* a) {
  *r = 0; *g = 0; *b = 0; *a = 255;
  if (c.extra_i == 0x434F4C52) {
    *r = (uint8_t)(c.i & 0xFF);
    *g = (uint8_t)((c.i >> 8) & 0xFF);
    *b = (uint8_t)((c.i >> 16) & 0xFF);
    *a = (uint8_t)((c.i >> 24) & 0xFF);
    return;
  }
  if (c.kind == AIPL_STRUCT && c.ptr) {
    AiplVal vr = aipl_member_get(c, "r");
    AiplVal vg = aipl_member_get(c, "g");
    AiplVal vb = aipl_member_get(c, "b");
    AiplVal va = aipl_member_get(c, "a");
    if (vr.kind == AIPL_NIL && vg.kind == AIPL_NIL && vb.kind == AIPL_NIL && ((AiplStruct*)c.ptr)->extra_i != 0) {
      uint32_t val = (uint32_t)((AiplStruct*)c.ptr)->extra_i;
      *r = (uint8_t)((val >> 24) & 0xFF);
      *g = (uint8_t)((val >> 16) & 0xFF);
      *b = (uint8_t)((val >> 8) & 0xFF);
      *a = (uint8_t)(val & 0xFF);
      return;
    }
    double dr = (vr.kind == AIPL_FLOAT) ? vr.f : (double)vr.i;
    double dg = (vg.kind == AIPL_FLOAT) ? vg.f : (double)vg.i;
    double db = (vb.kind == AIPL_FLOAT) ? vb.f : (double)vb.i;
    double da = (va.kind == AIPL_FLOAT) ? va.f : ((va.kind == AIPL_INT) ? (double)va.i : 1.0);
    if (dr <= 1.0 && vr.kind == AIPL_FLOAT) dr *= 255.0;
    if (dg <= 1.0 && vg.kind == AIPL_FLOAT) dg *= 255.0;
    if (db <= 1.0 && vb.kind == AIPL_FLOAT) db *= 255.0;
    if (da <= 1.0 && va.kind == AIPL_FLOAT) da *= 255.0;
    if (dr < 0.0) dr = 0.0; if (dr > 255.0) dr = 255.0;
    if (dg < 0.0) dg = 0.0; if (dg > 255.0) dg = 255.0;
    if (db < 0.0) db = 0.0; if (db > 255.0) db = 255.0;
    if (da < 0.0) da = 0.0; if (da > 255.0) da = 255.0;
    *r = (uint8_t)(dr + 0.5); *g = (uint8_t)(dg + 0.5); *b = (uint8_t)(db + 0.5); *a = (uint8_t)(da + 0.5);
  } else if (c.kind == AIPL_INT || c.kind == AIPL_FLOAT) {
    uint32_t val = (c.kind == AIPL_INT) ? (uint32_t)c.i : (uint32_t)c.f;
    if ((val & 0xFF000000u) != 0) {
      *r = (uint8_t)((val >> 24) & 0xFF);
      *g = (uint8_t)((val >> 16) & 0xFF);
      *b = (uint8_t)((val >> 8) & 0xFF);
      *a = (uint8_t)(val & 0xFF);
    } else {
      *r = (uint8_t)((val >> 16) & 0xFF);
      *g = (uint8_t)((val >> 8) & 0xFF);
      *b = (uint8_t)(val & 0xFF);
      *a = 255;
    }
  }
}

#ifdef AIPL_ENABLE_GUI_AUDIO
uint8_t* _aipl_canvas_fb = NULL;
uint32_t* _aipl_x11_bgra = NULL;
int _aipl_canvas_w = 800;
int _aipl_canvas_h = 600;
int _aipl_window_backend = 0;
int _aipl_window_resized = 0;
int _aipl_window_min_w = 320;
int _aipl_window_min_h = 240;
int _aipl_audio_thread_active = 0;
int _aipl_video_recording = 0;
char _aipl_win_title[256] = { 0 };
int _aipl_ipc_record_frames_remaining = 0;
char _aipl_ipc_ack_path[256] = { 0 };
int _aipl_single_instance_mode = 0;
int _aipl_instance_lock_fd = -1;
int _aipl_atexit_registered = 0;
char (*_aipl_font_paths)[512] = NULL;
char (*_aipl_image_paths)[512] = NULL;
void* _aipl_x11_lib = NULL;
void* _aipl_x11_dpy = NULL;
unsigned long _aipl_x11_win = 0;
void* _aipl_x11_gc = NULL;
void* _aipl_x11_img = NULL;
void* _aipl_xext_lib = NULL;
int _aipl_xshm_available = 0;
int _aipl_xshm_active = 0;
int _aipl_xshm_attached = 0;
void* _aipl_gl_lib = NULL;
void* _aipl_glx_ctx = NULL;
unsigned long _aipl_wm_delete = 0;
int _aipl_window_closed = 0;
int _aipl_frames = 0;
int _aipl_events_pumped_this_frame = 0;
int _aipl_target_fps = 60;
double _aipl_frame_dt = 0.016666667;
int64_t _aipl_last_frame_ns = 0;
int _aipl_benchmark_window_fps = 0;
int _aipl_unlocked_fps = 0;
int _aipl_window_pos_manual = 0;
int _aipl_win_x = 40;
int _aipl_win_y = 40;
int _aipl_depth_test_enabled = 0;
int _aipl_ui_tracking_enabled = 1;
int _aipl_cur_blend_mode = 0;
int _aipl_cli_max_fps_override = -1;
int _aipl_fps_cli_checked = 0;
int64_t _aipl_bench_start_ns = 0;
double _aipl_current_fps = 240.0;
double _aipl_frame_time_ms = 4.1667;
void _aipl_check_fps_cli_flags(void) {
  if (_aipl_fps_cli_checked) return;
  _aipl_fps_cli_checked = 1;
  const char* env_max_fps = getenv("AIPL_MAX_FPS");
  if (env_max_fps && env_max_fps[0]) {
    _aipl_cli_max_fps_override = atoi(env_max_fps);
    if (_aipl_cli_max_fps_override < 0) _aipl_cli_max_fps_override = 0;
    _aipl_target_fps = _aipl_cli_max_fps_override;
  }
  const char* env_bench = getenv("AIPL_BENCHMARK_WINDOW_FPS");
  if (env_bench && env_bench[0] && strcmp(env_bench, "0") != 0) {
    _aipl_benchmark_window_fps = 1;
  }
  const char* env_unlocked = getenv("AIPL_UNLOCKED_FPS");
  if (env_unlocked && env_unlocked[0] && strcmp(env_unlocked, "0") != 0) {
    _aipl_unlocked_fps = 1;
  }
  const char* env_wm = getenv("AIPL_WINDOW_MODE");
  if (env_wm && env_wm[0]) {
    _aipl_apply_window_mode_str(env_wm, 1);
  }
  const char* env_bot = getenv("AIPL_BOT_SCRIPT");
  const char* env_ipc = getenv("AIPL_IPC_INSPECT");
  const char* env_mseat = getenv("AIPL_MULTI_SEAT");
  const char* env_hebar = getenv("AIPL_HEBAR_SEAT");
  if ((env_bot && env_bot[0]) || (env_ipc && strcmp(env_ipc, "0") != 0) || (env_mseat && strcmp(env_mseat, "0") != 0) || (env_hebar && env_hebar[0])) {
    _aipl_ipc_telemetry_active = 1;
  }
  if ((env_mseat && strcmp(env_mseat, "0") != 0) || (env_hebar && env_hebar[0])) {
    _aipl_multi_seat_active = 1;
  }
  if (g_aipl_argv) {
    for (int i = 1; i < g_aipl_argc; i++) {
      if (!g_aipl_argv[i]) continue;
      if (strcmp(g_aipl_argv[i], "--BenchmarkWindowFps") == 0 || strcmp(g_aipl_argv[i], "--benchmark-window-fps") == 0) {
        _aipl_benchmark_window_fps = 1;
      } else if (strcmp(g_aipl_argv[i], "--UnlockedFps") == 0 || strcmp(g_aipl_argv[i], "--unlocked-fps") == 0) {
        _aipl_unlocked_fps = 1;
      } else if (strncmp(g_aipl_argv[i], "--MaxFps=", 9) == 0) {
        _aipl_cli_max_fps_override = atoi(g_aipl_argv[i] + 9);
        if (_aipl_cli_max_fps_override < 0) _aipl_cli_max_fps_override = 0;
        _aipl_target_fps = _aipl_cli_max_fps_override;
      } else if (strncmp(g_aipl_argv[i], "--max-fps=", 10) == 0) {
        _aipl_cli_max_fps_override = atoi(g_aipl_argv[i] + 10);
        if (_aipl_cli_max_fps_override < 0) _aipl_cli_max_fps_override = 0;
        _aipl_target_fps = _aipl_cli_max_fps_override;
      } else if ((strcmp(g_aipl_argv[i], "--MaxFps") == 0 || strcmp(g_aipl_argv[i], "--max-fps") == 0) && i + 1 < g_aipl_argc && g_aipl_argv[i + 1]) {
        _aipl_cli_max_fps_override = atoi(g_aipl_argv[i + 1]);
        if (_aipl_cli_max_fps_override < 0) _aipl_cli_max_fps_override = 0;
        _aipl_target_fps = _aipl_cli_max_fps_override;
      } else if (strncmp(g_aipl_argv[i], "--window-mode=", 14) == 0) {
        _aipl_apply_window_mode_str(g_aipl_argv[i] + 14, 1);
      } else if (strcmp(g_aipl_argv[i], "--window-mode") == 0 && i + 1 < g_aipl_argc && g_aipl_argv[i + 1]) {
        _aipl_apply_window_mode_str(g_aipl_argv[i + 1], 1);
      } else if (strcmp(g_aipl_argv[i], "--x11") == 0 || strcmp(g_aipl_argv[i], "--software") == 0 || strcmp(g_aipl_argv[i], "--cpu-rasterizer") == 0) {
        _aipl_apply_window_mode_str("x11", 1);
      } else if (strcmp(g_aipl_argv[i], "--gl") == 0 || strcmp(g_aipl_argv[i], "--glx") == 0) {
        _aipl_apply_window_mode_str("glx", 1);
      }
    }
  }
  if (_aipl_benchmark_window_fps && _aipl_cli_max_fps_override < 0) {
    _aipl_target_fps = 0;
  }
}
uint8_t _aipl_key_down[512];
uint8_t _aipl_key_pressed[512];
uint8_t _aipl_key_released[512];
int _aipl_last_key_pressed = 0;
int _aipl_mouse_x = 0;
int _aipl_mouse_y = 0;
uint8_t _aipl_mouse_down[8];
uint8_t _aipl_mouse_pressed[8];
uint8_t _aipl_mouse_released[8];
double _aipl_mouse_wheel = 0.0;
char* _aipl_text_input_buf = NULL;
size_t _aipl_text_input_cap = 0;
static size_t _aipl_text_input_len = 0;
void _aipl_text_input_clear(void) {
  _aipl_text_input_len = 0;
  if (_aipl_text_input_buf) _aipl_text_input_buf[0] = 0;
}
void _aipl_text_input_append(const char* s, size_t n) {
  if (!s || n == 0) return;
  if (_aipl_text_input_len + n + 1 > 1048576) return;
  if (_aipl_text_input_len + n + 1 > _aipl_text_input_cap) {
    size_t nc = _aipl_text_input_cap > 0 ? _aipl_text_input_cap * 2 : 128;
    while (nc < _aipl_text_input_len + n + 1) nc *= 2;
    char* nb = (char*)realloc(_aipl_text_input_buf, nc);
    if (!nb) return;
    _aipl_text_input_buf = nb;
    _aipl_text_input_cap = nc;
  }
  memcpy(_aipl_text_input_buf + _aipl_text_input_len, s, n);
  _aipl_text_input_len += n;
  _aipl_text_input_buf[_aipl_text_input_len] = 0;
}
int _aipl_bot_active_click_frame = -1;
int _aipl_bot_active_key_slot = -1;
int _aipl_bot_active_key_frame[512];
int _aipl_bot_active_mouse_frame[8];
int _aipl_shot_taken = 0;
int _aipl_max_frames_checked = 0;
int _aipl_max_frames_limit = -1;
int _aipl_get_max_frames_limit(void) {
  if (!_aipl_max_frames_checked) {
    _aipl_max_frames_checked = 1;
    const char* mf = getenv("AIPL_MAX_FRAMES");
    if (mf && mf[0]) _aipl_max_frames_limit = atoi(mf);
    if (_aipl_max_frames_limit < 0 && g_aipl_argv) {
      for (int i = 1; i < g_aipl_argc; i++) {
        if (g_aipl_argv[i] && strcmp(g_aipl_argv[i], "--frames") == 0 && i + 1 < g_aipl_argc && g_aipl_argv[i + 1]) {
          _aipl_max_frames_limit = atoi(g_aipl_argv[i + 1]);
        } else if (g_aipl_argv[i] && strncmp(g_aipl_argv[i], "--frames=", 9) == 0) {
          _aipl_max_frames_limit = atoi(g_aipl_argv[i] + 9);
        }
      }
    }
  }
  return _aipl_max_frames_limit;
}

#ifndef _WIN32
void* (*_aipl_X11_XOpenDisplay)(const char*) = NULL;
int (*_aipl_X11_XCloseDisplay)(void*) = NULL;
int (*_aipl_X11_XFlush)(void*) = NULL;
int (*_aipl_X11_XPending)(void*) = NULL;
int (*_aipl_X11_XNextEvent)(void*, void*) = NULL;
int (*_aipl_X11_XPeekEvent)(void*, void*) = NULL;
int (*_aipl_X11_XDefaultScreen)(void*) = NULL;
unsigned long (*_aipl_X11_XRootWindow)(void*, int) = NULL;
void* (*_aipl_X11_XDefaultVisual)(void*, int) = NULL;
int (*_aipl_X11_XDefaultDepth)(void*, int) = NULL;
unsigned long (*_aipl_X11_XBlackPixel)(void*, int) = NULL;
unsigned long (*_aipl_X11_XCreateSimpleWindow)(void*, unsigned long, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long) = NULL;
int (*_aipl_X11_XMapWindow)(void*, unsigned long) = NULL;
int (*_aipl_X11_XDestroyWindow)(void*, unsigned long) = NULL;
int (*_aipl_X11_XStoreName)(void*, unsigned long, const char*) = NULL;
int (*_aipl_X11_XSelectInput)(void*, unsigned long, long) = NULL;
unsigned long (*_aipl_X11_XInternAtom)(void*, const char*, int) = NULL;
int (*_aipl_X11_XSetWMProtocols)(void*, unsigned long, unsigned long*, int) = NULL;
void* (*_aipl_X11_XCreateGC)(void*, unsigned long, unsigned long, void*) = NULL;
int (*_aipl_X11_XFreeGC)(void*, void*) = NULL;
void* (*_aipl_X11_XCreateImage)(void*, void*, unsigned int, int, int, char*, unsigned int, unsigned int, int, int) = NULL;
int (*_aipl_X11_XPutImage)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int) = NULL;
int (*_aipl_X11_XResizeWindow)(void*, unsigned long, unsigned int, unsigned int) = NULL;
int (*_aipl_X11_XMoveWindow)(void*, unsigned long, int, int) = NULL;
unsigned long (*_aipl_X11_XLookupKeysym)(void*, int) = NULL;
int (*_aipl_X11_XSync)(void*, int) = NULL;
int (*_aipl_X11_XFree)(void*) = NULL;
_AiplXShmSegmentInfo _aipl_xshm_info = { 0, -1, NULL, 0 };
int (*_aipl_XShmQueryExtension)(void*) = NULL;
void* (*_aipl_XShmCreateImage)(void*, void*, unsigned int, int, char*, _AiplXShmSegmentInfo*, unsigned int, unsigned int) = NULL;
int (*_aipl_XShmAttach)(void*, _AiplXShmSegmentInfo*) = NULL;
int (*_aipl_XShmDetach)(void*, _AiplXShmSegmentInfo*) = NULL;
int (*_aipl_XShmPutImage)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int, int) = NULL;
void* (*_aipl_glXChooseVisual)(void*, int, int*) = NULL;
void* (*_aipl_glXCreateContext)(void*, void*, void*, int) = NULL;
int (*_aipl_glXMakeCurrent)(void*, unsigned long, void*) = NULL;
void (*_aipl_glXSwapBuffers)(void*, unsigned long) = NULL;
void (*_aipl_glXDestroyContext)(void*, void*) = NULL;
void* (*_aipl_glXGetProcAddress)(const unsigned char*) = NULL;
void (*_aipl_glXSwapIntervalEXT)(void*, unsigned long, int) = NULL;
int (*_aipl_glXSwapIntervalMESA)(unsigned int) = NULL;
int (*_aipl_glXSwapIntervalSGI)(int) = NULL;
void (*_aipl_glViewport)(int, int, int, int) = NULL;
void (*_aipl_glMatrixMode)(unsigned int) = NULL;
void (*_aipl_glLoadIdentity)(void) = NULL;
void (*_aipl_glOrtho)(double, double, double, double, double, double) = NULL;
void (*_aipl_glClearColor)(float, float, float, float) = NULL;
void (*_aipl_glClear)(unsigned int) = NULL;
void (*_aipl_glEnable)(unsigned int) = NULL;
void (*_aipl_glDisable)(unsigned int) = NULL;
void (*_aipl_glBlendFunc)(unsigned int, unsigned int) = NULL;
void (*_aipl_glScissor)(int, int, int, int) = NULL;
void (*_aipl_glVertexPointer)(int, unsigned int, int, const void*) = NULL;
void (*_aipl_glColorPointer)(int, unsigned int, int, const void*) = NULL;
void (*_aipl_glTexCoordPointer)(int, unsigned int, int, const void*) = NULL;
void (*_aipl_glEnableClientState)(unsigned int) = NULL;
void (*_aipl_glDisableClientState)(unsigned int) = NULL;
void (*_aipl_glDrawArrays)(unsigned int, int, int) = NULL;
void (*_aipl_glReadPixels)(int, int, int, int, unsigned int, unsigned int, void*) = NULL;
void (*_aipl_glDepthFunc)(unsigned int) = NULL;
void (*_aipl_glDepthMask)(unsigned char) = NULL;
void (*_aipl_glClearDepth)(double) = NULL;
void (*_aipl_glColorMask)(unsigned char, unsigned char, unsigned char, unsigned char) = NULL;
void (*_aipl_glShadeModel)(unsigned int) = NULL;
void (*_aipl_glGenTextures)(int, unsigned int*) = NULL;
void (*_aipl_glDeleteTextures)(int, const unsigned int*) = NULL;
void (*_aipl_glBindTexture)(unsigned int, unsigned int) = NULL;
void (*_aipl_glTexImage2D)(unsigned int, int, int, int, int, int, unsigned int, unsigned int, const void*) = NULL;
void (*_aipl_glTexParameteri)(unsigned int, unsigned int, int) = NULL;
void (*_aipl_glAlphaFunc)(unsigned int, float) = NULL;
typedef struct {
  int width, height;
  int xoffset;
  int format;
  char* data;
} _AiplXImageHeader;
#endif
float* _aipl_zbuffer = NULL;
float* _aipl_canvas_zb = NULL;
size_t _aipl_zbuffer_cap = 0;

void _aipl_destroy_x11_image_and_fb(void) {
#ifndef _WIN32
  if (_aipl_xshm_attached && _aipl_x11_dpy && _aipl_XShmDetach) {
    _aipl_XShmDetach(_aipl_x11_dpy, &_aipl_xshm_info);
    if (_aipl_X11_XSync) _aipl_X11_XSync(_aipl_x11_dpy, 0);
    _aipl_xshm_attached = 0;
  }
  if (_aipl_x11_img) {
    if (_aipl_X11_XFree) _aipl_X11_XFree(_aipl_x11_img);
    else free(_aipl_x11_img);
    _aipl_x11_img = NULL;
  }
  if (_aipl_xshm_active) {
    if (_aipl_canvas_fb == (uint8_t*)_aipl_xshm_info.shmaddr) {
      _aipl_canvas_fb = NULL;
    }
    if (_aipl_xshm_info.shmaddr && _aipl_xshm_info.shmaddr != (char*)-1) {
      shmdt(_aipl_xshm_info.shmaddr);
    }
    if (_aipl_xshm_info.shmid >= 0) {
      shmctl(_aipl_xshm_info.shmid, IPC_RMID, NULL);
    }
    _aipl_xshm_info.shmaddr = NULL;
    _aipl_xshm_info.shmid = -1;
    _aipl_xshm_active = 0;
  }
#endif
  if (_aipl_canvas_fb) {
    free(_aipl_canvas_fb);
    _aipl_canvas_fb = NULL;
  }
  if (_aipl_x11_bgra) {
    free(_aipl_x11_bgra);
    _aipl_x11_bgra = NULL;
  }
  if (_aipl_zbuffer) {
    free(_aipl_zbuffer);
    _aipl_zbuffer = NULL;
    _aipl_canvas_zb = NULL;
    _aipl_zbuffer_cap = 0;
  }
}

void _aipl_alloc_x11_image_and_fb(int w, int h) {
  if (w <= 0) w = 800;
  if (h <= 0) h = 600;
  _aipl_destroy_x11_image_and_fb();
  size_t total_px = (size_t)w * (size_t)h;
  _aipl_zbuffer = (float*)malloc(total_px * sizeof(float));
  _aipl_canvas_zb = _aipl_zbuffer;
  if (_aipl_zbuffer) {
    _aipl_zbuffer_cap = total_px;
    for (size_t i = 0; i < total_px; i++) _aipl_zbuffer[i] = 1e30f;
  }
#ifndef _WIN32
  if (_aipl_window_backend == 1 && _aipl_x11_dpy) {
    int scr = _aipl_X11_XDefaultScreen ? _aipl_X11_XDefaultScreen(_aipl_x11_dpy) : 0;
    void* vis = _aipl_X11_XDefaultVisual ? _aipl_X11_XDefaultVisual(_aipl_x11_dpy, scr) : NULL;
    int depth = _aipl_X11_XDefaultDepth ? _aipl_X11_XDefaultDepth(_aipl_x11_dpy, scr) : 24;
    if (_aipl_xshm_available && _aipl_XShmCreateImage && _aipl_XShmAttach) {
      memset(&_aipl_xshm_info, 0, sizeof(_aipl_xshm_info));
      _aipl_xshm_info.shmid = -1;
      void* shm_img = _aipl_XShmCreateImage(_aipl_x11_dpy, vis, (unsigned int)depth, 2, NULL, &_aipl_xshm_info, (unsigned int)w, (unsigned int)h);
      if (shm_img) {
        int shmid = shmget(IPC_PRIVATE, total_px * 4, IPC_CREAT | 0600);
        if (shmid >= 0) {
          char* shmaddr = (char*)shmat(shmid, NULL, 0);
          if (shmaddr && shmaddr != (char*)-1) {
            _aipl_xshm_info.shmid = shmid;
            _aipl_xshm_info.shmaddr = shmaddr;
            _aipl_xshm_info.readOnly = 0;
            ((_AiplXImageHeader*)shm_img)->data = shmaddr;
            if (_aipl_XShmAttach(_aipl_x11_dpy, &_aipl_xshm_info)) {
              if (_aipl_X11_XSync) _aipl_X11_XSync(_aipl_x11_dpy, 0);
              shmctl(shmid, IPC_RMID, NULL);
              memset(shmaddr, 0, total_px * 4);
              _aipl_x11_img = shm_img;
              _aipl_canvas_fb = (uint8_t*)calloc(total_px * 4, 1);
              if (!_aipl_canvas_fb) _aipl_canvas_fb = (uint8_t*)shmaddr;
              _aipl_xshm_active = 1;
              _aipl_xshm_attached = 1;
              return;
            }
            shmdt(shmaddr);
          }
          shmctl(shmid, IPC_RMID, NULL);
        }
        if (_aipl_X11_XFree) _aipl_X11_XFree(shm_img);
        else free(shm_img);
      }
    }
    _aipl_canvas_fb = (uint8_t*)calloc(total_px * 4, 1);
    if (_aipl_X11_XCreateImage && _aipl_canvas_fb) {
      _aipl_x11_img = _aipl_X11_XCreateImage(_aipl_x11_dpy, vis, (unsigned int)depth, 2, 0, (char*)_aipl_canvas_fb, (unsigned int)w, (unsigned int)h, 32, w * 4);
    }
    return;
  }
#endif
  _aipl_canvas_fb = (uint8_t*)calloc(total_px * 4, 1);
}
int _aipl_x11_keysym_to_slot(unsigned long ks) {
  if (ks >= 'a' && ks <= 'z') return (int)(ks - 32);
  if (ks >= 0x20 && ks <= 0x7E) return (int)ks;
  if (ks >= 0xFFB0 && ks <= 0xFFB9) return (int)('0' + (ks - 0xFFB0));
  if (ks == 0xFF08) return 8;
  if (ks == 0xFF09) return 9;
  if (ks == 0xFF0D || ks == 0xFF8D) return 13;
  if (ks == 0xFF1B) return 27;
  if (ks == 0xFFFF || ks == 0xFF9F) return 127;
  if (ks == 0xFF51 || ks == 0xFF96) return 263;
  if (ks == 0xFF53 || ks == 0xFF98) return 262;
  if (ks == 0xFF52 || ks == 0xFF97) return 265;
  if (ks == 0xFF54 || ks == 0xFF99) return 264;
  if (ks == 0xFF50 || ks == 0xFF95) return 268;
  if (ks == 0xFF57 || ks == 0xFF9C) return 269;
  if (ks == 0xFF55 || ks == 0xFF9A) return 266;
  if (ks == 0xFF56 || ks == 0xFF9B) return 267;
  if (ks >= 0xFFBE && ks <= 0xFFC9) return 290 + (int)(ks - 0xFFBE);
  if (ks == 0xFFE1 || ks == 0xFFE2) return 340;
  if (ks == 0xFFE3 || ks == 0xFFE4) return 341;
  if (ks == 0xFFE9 || ks == 0xFFEA) return 342;
  return -1;
}

int _aipl_key_val_to_slot(AiplVal k) {
  if (k.kind == AIPL_INT || k.kind == AIPL_FLOAT) {
    int code = (k.kind == AIPL_INT) ? (int)k.i : (int)k.f;
    if (code >= 'a' && code <= 'z') return code - 32;
    if (code == 37) return 263;
    if (code == 38) return 265;
    if (code == 39) return 262;
    if (code == 40) return 264;
    if (code == 256) return 27;
    if (code == 257) return 13;
    if (code == 258) return 9;
    if (code == 259) return 8;
    if (code == 261) return 127;
    if (code >= 0 && code < 512) return code;
    return -1;
  }
  if (k.kind == AIPL_STR && k.s) {
    const char* s = k.s;
    if (s[0] != 0 && s[1] == 0) {
      unsigned char c = (unsigned char)s[0];
      if (c >= 'a' && c <= 'z') return (int)(c - 32);
      if (c < 128) return (int)c;
    }
    if (strcasecmp(s, "Space") == 0 || strcasecmp(s, "Spacebar") == 0) return 32;
    if (strcasecmp(s, "Escape") == 0 || strcasecmp(s, "Esc") == 0) return 27;
    if (strcasecmp(s, "Enter") == 0 || strcasecmp(s, "Return") == 0) return 13;
    if (strcasecmp(s, "Tab") == 0) return 9;
    if (strcasecmp(s, "Backspace") == 0 || strcasecmp(s, "Back") == 0) return 8;
    if (strcasecmp(s, "Delete") == 0 || strcasecmp(s, "Del") == 0) return 127;
    if (strcasecmp(s, "ArrowLeft") == 0 || strcasecmp(s, "Left") == 0) return 263;
    if (strcasecmp(s, "ArrowRight") == 0 || strcasecmp(s, "Right") == 0) return 262;
    if (strcasecmp(s, "ArrowUp") == 0 || strcasecmp(s, "Up") == 0) return 265;
    if (strcasecmp(s, "ArrowDown") == 0 || strcasecmp(s, "Down") == 0) return 264;
    if (strcasecmp(s, "Home") == 0) return 268;
    if (strcasecmp(s, "End") == 0) return 269;
    if (strcasecmp(s, "PageUp") == 0) return 266;
    if (strcasecmp(s, "PageDown") == 0) return 267;
    if (strcasecmp(s, "Shift") == 0 || strcasecmp(s, "ShiftLeft") == 0 || strcasecmp(s, "ShiftRight") == 0 || strcasecmp(s, "Shift_L") == 0 || strcasecmp(s, "Shift_R") == 0) return 340;
    if (strcasecmp(s, "Control") == 0 || strcasecmp(s, "Ctrl") == 0 || strcasecmp(s, "ControlLeft") == 0 || strcasecmp(s, "ControlRight") == 0 || strcasecmp(s, "Control_L") == 0 || strcasecmp(s, "Control_R") == 0) return 341;
    if (strcasecmp(s, "Alt") == 0 || strcasecmp(s, "AltLeft") == 0 || strcasecmp(s, "AltRight") == 0 || strcasecmp(s, "Alt_L") == 0 || strcasecmp(s, "Alt_R") == 0) return 342;
    if (strncasecmp(s, "Key", 3) == 0 && s[3] != 0 && s[4] == 0) {
      unsigned char c = (unsigned char)s[3];
      if (c >= 'a' && c <= 'z') return (int)(c - 32);
      if (c >= 'A' && c <= 'Z') return (int)c;
    }
    if (strncasecmp(s, "Digit", 5) == 0 && s[5] >= '0' && s[5] <= '9' && s[6] == 0) return (int)s[5];
    if ((s[0] == 'F' || s[0] == 'f') && s[1] >= '1' && s[1] <= '9') {
      int fn = atoi(s + 1);
      if (fn >= 1 && fn <= 12) return 290 + (fn - 1);
    }
  }
  return -1;
}

void _aipl_resize_framebuffer(int w, int h) {
  if (w < _aipl_window_min_w) w = _aipl_window_min_w;
  if (h < _aipl_window_min_h) h = _aipl_window_min_h;
  if (w < 320) w = 320;
  if (h < 240) h = 240;
  if (w > 3840) w = 3840;
  if (h > 2160) h = 2160;
  if (w == _aipl_canvas_w && h == _aipl_canvas_h && _aipl_canvas_fb) { _aipl_window_resized = 1; return; }
  int old_w = _aipl_canvas_w;
  int old_h = _aipl_canvas_h;
  int copy_w = (w < old_w) ? w : old_w;
  int copy_h = (h < old_h) ? h : old_h;
  uint8_t* saved_fb = NULL;
  if (_aipl_canvas_fb && copy_w > 0 && copy_h > 0) {
    saved_fb = (uint8_t*)malloc((size_t)copy_w * (size_t)copy_h * 4);
    if (saved_fb) {
      for (int y = 0; y < copy_h; y++) {
        memcpy(saved_fb + (size_t)y * (size_t)copy_w * 4, _aipl_canvas_fb + (size_t)y * (size_t)old_w * 4, (size_t)copy_w * 4);
      }
    }
  }
  _aipl_canvas_w = w;
  _aipl_canvas_h = h;
  _aipl_alloc_x11_image_and_fb(w, h);
  if (saved_fb && _aipl_canvas_fb) {
    for (int y = 0; y < copy_h; y++) {
      memcpy(_aipl_canvas_fb + (size_t)y * (size_t)w * 4, saved_fb + (size_t)y * (size_t)copy_w * 4, (size_t)copy_w * 4);
    }
  }
  if (saved_fb) free(saved_fb);
#ifndef _WIN32
  if (_aipl_window_backend == 2 && _aipl_glViewport) {
    _aipl_glViewport(0, 0, w, h);
    if (_aipl_glMatrixMode) _aipl_glMatrixMode(0x1701 /* GL_PROJECTION */);
    if (_aipl_glLoadIdentity) _aipl_glLoadIdentity();
    if (_aipl_glOrtho) _aipl_glOrtho(0.0, (double)w, (double)h, 0.0, -1.0, 1.0);
    if (_aipl_glMatrixMode) _aipl_glMatrixMode(0x1700 /* GL_MODELVIEW */);
    if (_aipl_glLoadIdentity) _aipl_glLoadIdentity();
  }
#endif
  _aipl_window_resized = 1;
}

static int _aipl_bot_last_action_seat = 0;
static int _aipl_sg_oot_rejected = 0;
static int _aipl_sg_active_seat = 1;
static int _aipl_sg_explicit_turn = 0;

void _aipl_execute_bot_action(const char* act, const char* param) {
  _aipl_ipc_telemetry_active = 1;
  int bot_verbose = (getenv("AIPL_BOT_VERBOSE") && strcmp(getenv("AIPL_BOT_VERBOSE"), "1") == 0);
  if (bot_verbose) {
    fprintf(stderr, "[AIPL-BOT] frame=%d action=%s params=%s\n", _aipl_frames, act, param);
  }
  if (strcmp(act, "seat") == 0) {
    _aipl_bot_last_action_seat = atoi(param);
    if (_aipl_bot_last_action_seat > 0) _aipl_multi_seat_active = 1;
    return;
  } else if (strcmp(act, "probe_oot") == 0 || strcmp(act, "oot_click") == 0) {
    if (_aipl_bot_last_action_seat == 0 || _aipl_bot_last_action_seat != _aipl_sg_active_seat) {
      _aipl_sg_oot_rejected++;
    }
    return;
  } else if (strcmp(act, "move") == 0) {
    if (_aipl_sg_explicit_turn && _aipl_bot_last_action_seat > 0 && _aipl_bot_last_action_seat != _aipl_sg_active_seat) {
      return;
    }
    int mx = 0, my = 0;
    if (sscanf(param, "%d,%d", &mx, &my) == 2) { _aipl_mouse_x = mx; _aipl_mouse_y = my; }
  } else if (strcmp(act, "click") == 0) {
    if (_aipl_sg_explicit_turn && _aipl_bot_last_action_seat > 0 && _aipl_bot_last_action_seat != _aipl_sg_active_seat) {
      _aipl_sg_oot_rejected++;
      return;
    }
    int mx = _aipl_mouse_x, my = _aipl_mouse_y;
    if (strchr(param, ',')) sscanf(param, "%d,%d", &mx, &my);
    _aipl_mouse_x = mx; _aipl_mouse_y = my;
    _aipl_mouse_down[0] = 1; _aipl_mouse_pressed[0] = 1;
    _aipl_bot_active_click_frame = _aipl_frames;
    _aipl_bot_active_mouse_frame[0] = _aipl_frames;
  } else if (strcmp(act, "rclick") == 0) {
    int mx = _aipl_mouse_x, my = _aipl_mouse_y;
    if (strchr(param, ',')) sscanf(param, "%d,%d", &mx, &my);
    _aipl_mouse_x = mx; _aipl_mouse_y = my;
    _aipl_mouse_down[1] = 1; _aipl_mouse_pressed[1] = 1;
    _aipl_bot_active_click_frame = _aipl_frames;
    _aipl_bot_active_mouse_frame[1] = _aipl_frames;
  } else if (strcmp(act, "drag") == 0) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, hold = 1;
    if (sscanf(param, "%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &hold) >= 4) {
      if (hold < 1) hold = 1;
      _aipl_mouse_x = x2; _aipl_mouse_y = y2;
      _aipl_mouse_down[0] = 1; _aipl_mouse_pressed[0] = 1;
      _aipl_bot_active_click_frame = _aipl_frames + (hold - 1);
      _aipl_bot_active_mouse_frame[0] = _aipl_frames + (hold - 1);
    }
  } else if (strcmp(act, "key") == 0) {
    char kbuf[64];
    strncpy(kbuf, param, sizeof(kbuf) - 1);
    kbuf[sizeof(kbuf) - 1] = 0;
    int hold = 1;
    char* comma = strchr(kbuf, ',');
    if (comma) {
      *comma = 0;
      hold = atoi(comma + 1);
      if (hold < 1) hold = 1;
    }
    int slot = -1;
    if (kbuf[0] >= '0' && kbuf[0] <= '9' && kbuf[1] != 0) {
      slot = _aipl_key_val_to_slot(aipl_int(atoi(kbuf)));
    } else {
      slot = _aipl_key_val_to_slot(aipl_str(kbuf));
    }
    if (slot >= 0 && slot < 512) {
      _aipl_key_down[slot] = 1; _aipl_key_pressed[slot] = 1; _aipl_last_key_pressed = slot;
      _aipl_bot_active_key_slot = slot;
      _aipl_bot_active_key_frame[slot] = _aipl_frames + (hold - 1);
    }
  } else if (strcmp(act, "resize") == 0) {
    int rw = 0, rh = 0;
    if (sscanf(param, "%d,%d", &rw, &rh) == 2 || sscanf(param, "%dx%d", &rw, &rh) == 2) {
      _aipl_resize_framebuffer(rw, rh);
#ifndef _WIN32
      if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy && _aipl_x11_win && _aipl_X11_XResizeWindow) {
        _aipl_X11_XResizeWindow(_aipl_x11_dpy, _aipl_x11_win, (unsigned int)rw, (unsigned int)rh);
        if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
      }
#endif
    }
  } else if (strcmp(act, "text") == 0) {
    _aipl_text_input_clear();
    _aipl_text_input_append(param, strlen(param));
  } else if (strcmp(act, "compose") == 0) {
    _aipl_composition_set(param, (int)strlen(param));
  } else if (strcmp(act, "wheel") == 0) {
    _aipl_mouse_wheel = atof(param);
  }
}

static size_t _aipl_encode_utf8_cp(uint32_t cp, char out[4]) {
  if (cp < 0x80u) {
    out[0] = (char)cp;
    return 1;
  } else if (cp < 0x800u) {
    out[0] = (char)(0xC0u | (cp >> 6));
    out[1] = (char)(0x80u | (cp & 0x3Fu));
    return 2;
  } else if (cp < 0x10000u) {
    out[0] = (char)(0xE0u | (cp >> 12));
    out[1] = (char)(0x80u | ((cp >> 6) & 0x3Fu));
    out[2] = (char)(0x80u | (cp & 0x3Fu));
    return 3;
  } else if (cp <= 0x10FFFFu) {
    out[0] = (char)(0xF0u | (cp >> 18));
    out[1] = (char)(0x80u | ((cp >> 12) & 0x3Fu));
    out[2] = (char)(0x80u | ((cp >> 6) & 0x3Fu));
    out[3] = (char)(0x80u | (cp & 0x3Fu));
    return 4;
  }
  return 0;
}

void _aipl_parse_bot_script(const char* bot_script) {
  if (!bot_script || !bot_script[0]) return;
  char bbuf[4096];
  strncpy(bbuf, bot_script, sizeof(bbuf) - 1);
  bbuf[sizeof(bbuf) - 1] = 0;
  char* saveptr1 = NULL;
  char* token = strtok_r(bbuf, ";\n", &saveptr1);
  while (token) {
    while (isspace((unsigned char)*token)) token++;
    if (*token) {
      char* c1 = strchr(token, ':');
      if (c1) {
        char* first = token;
        *c1 = 0;
        char* rest = c1 + 1;
        int is_num = 1;
        for (char* p = first; *p; p++) {
          if (!isdigit((unsigned char)*p)) { is_num = 0; break; }
        }
        if (is_num) {
          int f = atoi(first);
          char* c2 = strchr(rest, ':');
          char* act = rest;
          char* param = c2 ? (c2 + 1) : "";
          if (c2) *c2 = 0;
          if (f == _aipl_frames || (f == 0 && _aipl_frames <= 1)) {
            _aipl_execute_bot_action(act, param);
          }
        } else {
          _aipl_execute_bot_action(first, rest);
        }
      } else {
        _aipl_execute_bot_action(token, "");
      }
    }
    token = strtok_r(NULL, ";\n", &saveptr1);
  }
}

void _aipl_pump_events(void) {
  _aipl_window_resized = 0;
  memset(_aipl_key_pressed, 0, sizeof(_aipl_key_pressed));
  memset(_aipl_key_released, 0, sizeof(_aipl_key_released));
  memset(_aipl_mouse_pressed, 0, sizeof(_aipl_mouse_pressed));
  memset(_aipl_mouse_released, 0, sizeof(_aipl_mouse_released));
  _aipl_mouse_wheel = 0.0;
  _aipl_last_key_pressed = 0;
  _aipl_text_input_clear();
#ifndef _WIN32
  if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy && _aipl_X11_XPending && _aipl_X11_XNextEvent) {
    typedef int (*XLookupStringFn)(void*, char*, int, unsigned long*, void*);
    typedef int (*Xutf8LookupStringFn)(void*, void*, char*, int, unsigned long*, int*);
    static XLookupStringFn fn_lookup_str = NULL;
    static Xutf8LookupStringFn fn_utf8_lookup_str = NULL;
    static int lookup_str_checked = 0;
    if (!lookup_str_checked && _aipl_x11_lib) {
      lookup_str_checked = 1;
      fn_lookup_str = (XLookupStringFn)dlsym(_aipl_x11_lib, "XLookupString");
      fn_utf8_lookup_str = (Xutf8LookupStringFn)dlsym(_aipl_x11_lib, "Xutf8LookupString");
      (void)fn_utf8_lookup_str;
    }
    while (_aipl_X11_XPending(_aipl_x11_dpy) > 0) {
      AiplXEvent ev;
      memset(&ev, 0, sizeof(ev));
      _aipl_X11_XNextEvent(_aipl_x11_dpy, &ev);
      if (ev.type == 2) {
        _aipl_key_down[340] = (ev.xkey.state & 1) ? 1 : 0;
        _aipl_key_down[341] = (ev.xkey.state & 4) ? 1 : 0;
        if (_aipl_X11_XLookupKeysym) {
          unsigned long ks = _aipl_X11_XLookupKeysym(&ev.xkey, 0);
          int slot = _aipl_x11_keysym_to_slot(ks);
          if (slot >= 0 && slot < 512) {
            _aipl_key_pressed[slot] = 1;
            _aipl_key_down[slot] = 1;
            _aipl_last_key_pressed = slot;
          }
          int appended = 0;
          if (fn_lookup_str && !(ev.xkey.state & 4)) {
            char lbuf[64];
            unsigned long lks = 0;
            int nbytes = fn_lookup_str(&ev.xkey, lbuf, (int)sizeof(lbuf), &lks, NULL);
            if (nbytes > 0) {
              if (nbytes == 1 && (unsigned char)lbuf[0] < 0x20) {
                /* Skip ASCII control codes */
              } else if (nbytes == 1 && (unsigned char)lbuf[0] >= 0x80) {
                char u8[4];
                size_t un = _aipl_encode_utf8_cp((uint32_t)(unsigned char)lbuf[0], u8);
                if (un > 0) { _aipl_text_input_append(u8, un); appended = 1; }
              } else {
                _aipl_text_input_append(lbuf, (size_t)nbytes);
                appended = 1;
              }
            }
          }
          if (!appended && !(ev.xkey.state & 4)) {
            unsigned long ks_txt = _aipl_X11_XLookupKeysym(&ev.xkey, (ev.xkey.state & 1) ? 1 : 0);
            uint32_t cp = 0;
            if (ks_txt >= 0x20 && ks_txt <= 0x7E) cp = (uint32_t)ks_txt;
            else if (ks_txt >= 0xA0 && ks_txt <= 0xFF) cp = (uint32_t)ks_txt;
            else if ((ks_txt & 0xFF000000UL) == 0x01000000UL) cp = (uint32_t)(ks_txt & 0x00FFFFFFUL);
            if (cp >= 0x20u) {
              char u8[4];
              size_t un = _aipl_encode_utf8_cp(cp, u8);
              if (un > 0) _aipl_text_input_append(u8, un);
            }
          }
        }
      } else if (ev.type == 3) {
        if (_aipl_X11_XPending(_aipl_x11_dpy) > 0 && _aipl_X11_XPeekEvent) {
          AiplXEvent nev;
          memset(&nev, 0, sizeof(nev));
          _aipl_X11_XPeekEvent(_aipl_x11_dpy, &nev);
          if (nev.type == 2 && nev.xkey.time == ev.xkey.time && nev.xkey.keycode == ev.xkey.keycode) {
            continue;
          }
        }
        if (_aipl_X11_XLookupKeysym) {
          unsigned long ks = _aipl_X11_XLookupKeysym(&ev.xkey, 0);
          int slot = _aipl_x11_keysym_to_slot(ks);
          if (slot >= 0 && slot < 512) {
            _aipl_key_down[slot] = 0;
            _aipl_key_released[slot] = 1;
          }
        }
      } else if (ev.type == 4) {
        _aipl_mouse_x = ev.xbutton.x;
        _aipl_mouse_y = ev.xbutton.y;
        _aipl_key_down[340] = (ev.xbutton.state & 1) ? 1 : 0;
        _aipl_key_down[341] = (ev.xbutton.state & 4) ? 1 : 0;
        unsigned int b = ev.xbutton.button;
        if (b == 1) { _aipl_mouse_down[0] = 1; _aipl_mouse_pressed[0] = 1; }
        else if (b == 3) { _aipl_mouse_down[1] = 1; _aipl_mouse_pressed[1] = 1; }
        else if (b == 2) { _aipl_mouse_down[2] = 1; _aipl_mouse_pressed[2] = 1; }
        else if (b == 4) { _aipl_mouse_wheel = 1.0; }
        else if (b == 5) { _aipl_mouse_wheel = -1.0; }
      } else if (ev.type == 5) {
        _aipl_mouse_x = ev.xbutton.x;
        _aipl_mouse_y = ev.xbutton.y;
        _aipl_key_down[340] = (ev.xbutton.state & 1) ? 1 : 0;
        _aipl_key_down[341] = (ev.xbutton.state & 4) ? 1 : 0;
        unsigned int b = ev.xbutton.button;
        if (b == 1) { _aipl_mouse_down[0] = 0; _aipl_mouse_released[0] = 1; }
        else if (b == 3) { _aipl_mouse_down[1] = 0; _aipl_mouse_released[1] = 1; }
        else if (b == 2) { _aipl_mouse_down[2] = 0; _aipl_mouse_released[2] = 1; }
      } else if (ev.type == 6) {
        _aipl_mouse_x = ev.xmotion.x;
        _aipl_mouse_y = ev.xmotion.y;
        _aipl_key_down[340] = (ev.xmotion.state & 1) ? 1 : 0;
        _aipl_key_down[341] = (ev.xmotion.state & 4) ? 1 : 0;
      } else if (ev.type == 17) {
        _aipl_window_closed = 1;
      } else if (ev.type == 22) {
        if (ev.xconfigure.width > 0 && ev.xconfigure.height > 0 && (ev.xconfigure.width != _aipl_canvas_w || ev.xconfigure.height != _aipl_canvas_h)) {
          _aipl_resize_framebuffer(ev.xconfigure.width, ev.xconfigure.height);
        }
      } else if (ev.type == 33) {
        if (_aipl_wm_delete && (unsigned long)ev.xclient.data.l[0] == _aipl_wm_delete) {
          _aipl_window_closed = 1;
        }
      }
    }
  }
#endif
  if (_aipl_bot_active_click_frame >= 0 && _aipl_bot_active_click_frame <= _aipl_frames - 1) {
    _aipl_bot_active_click_frame = -1;
  }
  for (int _mb = 0; _mb < 8; _mb++) {
    if (_aipl_bot_active_mouse_frame[_mb] >= 0 && _aipl_bot_active_mouse_frame[_mb] <= _aipl_frames - 1) {
      if (_aipl_mouse_down[_mb]) { _aipl_mouse_down[_mb] = 0; _aipl_mouse_released[_mb] = 1; }
      _aipl_bot_active_mouse_frame[_mb] = -1;
    }
  }
  for (int _ks = 0; _ks < 512; _ks++) {
    if (_aipl_bot_active_key_frame[_ks] >= 0 && _aipl_bot_active_key_frame[_ks] <= _aipl_frames - 1) {
      _aipl_key_down[_ks] = 0; _aipl_key_released[_ks] = 1;
      _aipl_bot_active_key_frame[_ks] = -1;
      if (_aipl_bot_active_key_slot == _ks) _aipl_bot_active_key_slot = -1;
    }
  }
  const char* bot_script = getenv("AIPL_BOT_SCRIPT");
  if (bot_script && bot_script[0]) {
    _aipl_parse_bot_script(bot_script);
  }
  if (_aipl_pending_ipc_script[0]) {
    char ipc_copy[4096];
    strncpy(ipc_copy, _aipl_pending_ipc_script, sizeof(ipc_copy) - 1);
    ipc_copy[sizeof(ipc_copy) - 1] = 0;
    _aipl_pending_ipc_script[0] = 0;
    _aipl_parse_bot_script(ipc_copy);
  }
}

char _aipl_pending_ipc_script[4096] = {0};

typedef struct {
  int id;
  char kind[16];
  char text[96];
  int x, y, w, h;
  uint32_t fg_rgb;
  uint32_t bg_rgb;
  int clickable;
  double contrast_ratio;
} _AiplSgUiNode;

typedef struct {
  int id;
  char tag[32];
  int owner_seat;
  double x, y, vx, vy;
  int w, h, hp;
  char state[24];
} _AiplSgEntity;

static _AiplSgUiNode* _aipl_sg_ui_nodes = NULL;
static int _aipl_sg_ui_cap = 0;
static int _aipl_sg_ui_count = 0;
static _AiplSgEntity* _aipl_sg_entities = NULL;
static int _aipl_sg_entity_cap = 0;
static int _aipl_sg_entity_count = 0;
static int _aipl_sg_turn_number = 1;
static char _aipl_sg_phase[32] = "ACTIVE";
static int _aipl_sg_legal_actions = 4;
static char _aipl_sg_scores[64] = "[0,0,0,0]";
static int _aipl_sg_game_over = 0;
static int _aipl_sg_winner_seat = 0;
static char _aipl_sg_custom_keys[32][48];
static char _aipl_sg_custom_vals[32][512];
static int _aipl_sg_custom_count = 0;

static int _aipl_ensure_sg_ui_cap(int min_cap) {
  if (min_cap <= _aipl_sg_ui_cap) return 1;
  if (min_cap > 65536) return 0;
  int nc = _aipl_sg_ui_cap > 0 ? _aipl_sg_ui_cap * 2 : 96;
  while (nc < min_cap) nc *= 2;
  _AiplSgUiNode* next = (_AiplSgUiNode*)realloc(_aipl_sg_ui_nodes, (size_t)nc * sizeof(_AiplSgUiNode));
  if (!next) return 0;
  _aipl_sg_ui_nodes = next;
  _aipl_sg_ui_cap = nc;
  return 1;
}

static int _aipl_ensure_sg_entity_cap(int min_cap) {
  if (min_cap <= _aipl_sg_entity_cap) return 1;
  if (min_cap > 65536) return 0;
  int nc = _aipl_sg_entity_cap > 0 ? _aipl_sg_entity_cap * 2 : 96;
  while (nc < min_cap) nc *= 2;
  _AiplSgEntity* next = (_AiplSgEntity*)realloc(_aipl_sg_entities, (size_t)nc * sizeof(_AiplSgEntity));
  if (!next) return 0;
  _aipl_sg_entities = next;
  _aipl_sg_entity_cap = nc;
  return 1;
}

static double _aipl_srgb_lum_lut[256];
static int _aipl_srgb_lum_lut_init = 0;

static double _aipl_rel_luminance(uint32_t rgb) {
  if (__builtin_expect(!_aipl_srgb_lum_lut_init, 0)) {
    for (int i = 0; i < 256; i++) {
      double c = (double)i / 255.0;
      _aipl_srgb_lum_lut[i] = (c <= 0.03928) ? (c / 12.92) : pow((c + 0.055) / 1.055, 2.4);
    }
    _aipl_srgb_lum_lut_init = 1;
  }
  double r = _aipl_srgb_lum_lut[(rgb >> 16) & 0xFF];
  double g = _aipl_srgb_lum_lut[(rgb >> 8) & 0xFF];
  double b = _aipl_srgb_lum_lut[rgb & 0xFF];
  return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

static double _aipl_compute_contrast_ratio(uint32_t fg, uint32_t bg) {
  double l1 = _aipl_rel_luminance(fg);
  double l2 = _aipl_rel_luminance(bg);
  double hi = (l1 > l2) ? l1 : l2;
  double lo = (l1 > l2) ? l2 : l1;
  return (hi + 0.05) / (lo + 0.05);
}

static void _aipl_json_escape_into(const char* src, char* dst, size_t cap) {
  if (!dst || cap == 0) return;
  size_t j = 0;
  for (size_t i = 0; src && src[i] && j + 2 < cap; i++) {
    unsigned char c = (unsigned char)src[i];
    if (c == '"' || c == '\\') {
      if (j + 3 >= cap) break;
      dst[j++] = '\\';
      dst[j++] = (char)c;
    } else if (c >= 32 && c < 127) {
      dst[j++] = (char)c;
    } else if (c == '\n' || c == '\r' || c == '\t') {
      dst[j++] = ' ';
    }
  }
  dst[j] = 0;
}

void _aipl_sg_reset_frame(void) {
  _aipl_sg_ui_count = 0;
  _aipl_sg_entity_count = 0;
  _aipl_ui_tracking_enabled = 1;
}

void _aipl_sg_record_rect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, int is_rounded) {
  if (!_aipl_ui_tracking_enabled || _aipl_benchmark_window_fps || !_aipl_ipc_telemetry_active) return;
  if (_aipl_sg_ui_count >= 512 && _aipl_sg_entity_count >= 512) return;
  if (w >= _aipl_canvas_w - 8 && h >= _aipl_canvas_h - 8) return;
  uint32_t rgb = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  int is_red_highlight = (!is_rounded && w == h && w >= 30 && w <= 96 && r > 200 && g < 90 && b < 90);
  int is_sel_highlight = (!is_rounded && w == h && w >= 30 && w <= 96 && r > 220 && g > 130 && b < 40);
  if (w >= 18 && w <= 460 && h >= 14 && h <= 140 && _aipl_ensure_sg_ui_cap(_aipl_sg_ui_count + 1)) {
    _AiplSgUiNode* n = &_aipl_sg_ui_nodes[_aipl_sg_ui_count++];
    n->id = _aipl_sg_ui_count;
    if (is_red_highlight) {
      strncpy(n->kind, "highlight", sizeof(n->kind) - 1);
      strncpy(n->text, "target_capture", sizeof(n->text) - 1);
      n->clickable = 1;
    } else if (is_sel_highlight) {
      strncpy(n->kind, "highlight", sizeof(n->kind) - 1);
      strncpy(n->text, "selected", sizeof(n->text) - 1);
      n->clickable = 0;
    } else {
      strncpy(n->kind, is_rounded ? "button" : "rect", sizeof(n->kind) - 1);
      n->text[0] = 0;
      n->clickable = is_rounded ? 1 : 0;
    }
    n->kind[sizeof(n->kind) - 1] = 0;
    n->x = x; n->y = y; n->w = w; n->h = h;
    n->bg_rgb = rgb;
    n->fg_rgb = 0xFFFFFFu;
    n->contrast_ratio = _aipl_compute_contrast_ratio(n->fg_rgb, n->bg_rgb);
  }
  if (w >= 12 && w <= 56 && h >= 12 && h <= 56 && abs(w - h) <= 12 && _aipl_ensure_sg_entity_cap(_aipl_sg_entity_count + 1)) {
    _AiplSgEntity* e = &_aipl_sg_entities[_aipl_sg_entity_count++];
    e->id = _aipl_sg_entity_count;
    strncpy(e->tag, "tile_entity", sizeof(e->tag) - 1);
    e->tag[sizeof(e->tag) - 1] = 0;
    e->owner_seat = (r > 180 && g < 100) ? 1 : ((b > 180 && r < 100) ? 2 : ((g > 160 && r < 100) ? 3 : ((r > 180 && g > 160) ? 4 : 0)));
    e->x = (double)x + (double)w * 0.5;
    e->y = (double)y + (double)h * 0.5;
    e->vx = 0.0; e->vy = 0.0;
    e->w = w; e->h = h; e->hp = 100;
    strncpy(e->state, "active", sizeof(e->state) - 1);
    e->state[sizeof(e->state) - 1] = 0;
  }
}

void _aipl_sg_record_circle(int cx, int cy, int rad, uint8_t r, uint8_t g, uint8_t b) {
  if (!_aipl_ui_tracking_enabled || _aipl_benchmark_window_fps || !_aipl_ipc_telemetry_active) return;
  if (_aipl_sg_ui_count >= 512 && _aipl_sg_entity_count >= 512) return;
  if (rad < 5 || rad > 60) return;
  uint32_t rgb = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  if (rad <= 14 && g > 160 && r < 80 && b < 120) {
    if (_aipl_ensure_sg_ui_cap(_aipl_sg_ui_count + 1)) {
      _AiplSgUiNode* n = &_aipl_sg_ui_nodes[_aipl_sg_ui_count++];
      n->id = _aipl_sg_ui_count;
      strncpy(n->kind, "highlight", sizeof(n->kind) - 1);
      n->kind[sizeof(n->kind) - 1] = 0;
      strncpy(n->text, "target_move", sizeof(n->text) - 1);
      n->text[sizeof(n->text) - 1] = 0;
      n->x = cx - rad; n->y = cy - rad; n->w = rad * 2; n->h = rad * 2;
      n->bg_rgb = rgb;
      n->fg_rgb = 0xFFFFFFu;
      n->clickable = 1;
      n->contrast_ratio = _aipl_compute_contrast_ratio(n->fg_rgb, n->bg_rgb);
    }
    return;
  }
  int owner = 0;
  if (r > 200 && g > 200 && b > 200) owner = 1;
  else if (r < 60 && g < 70 && b < 90) owner = 2;
  else if (r > 180 && g < 100) owner = 1;
  else if (b > 180 && r < 100) owner = 2;
  else if (g > 160 && r < 100) owner = 3;
  else if (r > 180 && g > 160) owner = 4;

  if (_aipl_sg_entity_count > 0) {
    _AiplSgEntity* prev_e = &_aipl_sg_entities[_aipl_sg_entity_count - 1];
    if (strcmp(prev_e->tag, "piece_token") == 0 && abs((int)prev_e->x - cx) <= 6 && abs((int)prev_e->y - cy) <= 6) {
      if (owner > 0 && rad >= 8) {
        prev_e->owner_seat = owner;
        if (_aipl_sg_ui_count > 0) {
          _AiplSgUiNode* prev_n = &_aipl_sg_ui_nodes[_aipl_sg_ui_count - 1];
          if (strcmp(prev_n->kind, "token") == 0) {
            snprintf(prev_n->text, sizeof(prev_n->text), "token_seat_%d", prev_e->owner_seat);
            prev_n->bg_rgb = rgb;
          }
        }
      }
      return;
    }
  }

  if (_aipl_ensure_sg_entity_cap(_aipl_sg_entity_count + 1)) {
    _AiplSgEntity* e = &_aipl_sg_entities[_aipl_sg_entity_count++];
    e->id = _aipl_sg_entity_count;
    strncpy(e->tag, "piece_token", sizeof(e->tag) - 1);
    e->tag[sizeof(e->tag) - 1] = 0;
    e->owner_seat = owner;
    e->x = (double)cx;
    e->y = (double)cy;
    e->vx = 0.0; e->vy = 0.0;
    e->w = rad * 2; e->h = rad * 2; e->hp = 100;
    strncpy(e->state, "board", sizeof(e->state) - 1);
    e->state[sizeof(e->state) - 1] = 0;
  }
  if (_aipl_ensure_sg_ui_cap(_aipl_sg_ui_count + 1)) {
    _AiplSgUiNode* n = &_aipl_sg_ui_nodes[_aipl_sg_ui_count++];
    n->id = _aipl_sg_ui_count;
    strncpy(n->kind, "token", sizeof(n->kind) - 1);
    n->kind[sizeof(n->kind) - 1] = 0;
    snprintf(n->text, sizeof(n->text), "token_seat_%d", owner);
    n->x = cx - rad; n->y = cy - rad; n->w = rad * 2; n->h = rad * 2;
    n->bg_rgb = rgb;
    n->fg_rgb = 0xFFFFFFu;
    n->clickable = 1;
    n->contrast_ratio = _aipl_compute_contrast_ratio(n->fg_rgb, n->bg_rgb);
  }
}

void _aipl_sg_record_text(const char* s, int x, int y, double sz, uint8_t r, uint8_t g, uint8_t b) {
  if (!_aipl_ui_tracking_enabled || _aipl_benchmark_window_fps || !_aipl_ipc_telemetry_active || !s || !s[0]) return;
  if (_aipl_sg_ui_count >= 512) return;
  uint32_t fg = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  if (!_aipl_sg_explicit_turn) {
    if (strstr(s, "Seat 1") || strstr(s, "Player 1") || strstr(s, "White's Turn") || strstr(s, "RED TURN")) _aipl_sg_active_seat = 1;
    else if (strstr(s, "Seat 2") || strstr(s, "Player 2") || strstr(s, "Black's Turn") || strstr(s, "BLUE TURN")) _aipl_sg_active_seat = 2;
    else if (strstr(s, "Seat 3") || strstr(s, "Player 3") || strstr(s, "GREEN TURN")) _aipl_sg_active_seat = 3;
    else if (strstr(s, "Seat 4") || strstr(s, "Player 4") || strstr(s, "YELLOW TURN")) _aipl_sg_active_seat = 4;
  }
  for (int i = _aipl_sg_ui_count - 1; i >= 0; i--) {
    _AiplSgUiNode* n = &_aipl_sg_ui_nodes[i];
    if (x >= n->x - 10 && x <= n->x + n->w + 10 && y >= n->y - 10 && y <= n->y + n->h + 10) {
      if (strcmp(n->kind, "token") == 0 && strlen(s) <= 2 && strchr(n->text, ':') == NULL) {
        size_t cur = strlen(n->text);
        if (cur + 2 + strlen(s) < sizeof(n->text)) {
          n->text[cur] = ':';
          _aipl_json_escape_into(s, n->text + cur + 1, sizeof(n->text) - cur - 1);
        }
        n->fg_rgb = fg;
        n->contrast_ratio = _aipl_compute_contrast_ratio(fg, n->bg_rgb);
        return;
      }
      if (n->text[0] == 0 && (strcmp(n->kind, "button") == 0 || strlen(s) > 1)) {
        _aipl_json_escape_into(s, n->text, sizeof(n->text));
        strncpy(n->kind, "button", sizeof(n->kind) - 1);
        n->fg_rgb = fg;
        n->clickable = 1;
        n->contrast_ratio = _aipl_compute_contrast_ratio(fg, n->bg_rgb);
        return;
      }
    }
  }
  if (_aipl_ensure_sg_ui_cap(_aipl_sg_ui_count + 1)) {
    uint32_t bg = 0x0F172Au;
    if (_aipl_canvas_fb && x >= 0 && x < _aipl_canvas_w && y >= 0 && y < _aipl_canvas_h) {
      size_t idx = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
      bg = ((uint32_t)_aipl_canvas_fb[idx + 2] << 16) | ((uint32_t)_aipl_canvas_fb[idx + 1] << 8) | (uint32_t)_aipl_canvas_fb[idx];
    }
    _AiplSgUiNode* n = &_aipl_sg_ui_nodes[_aipl_sg_ui_count++];
    n->id = _aipl_sg_ui_count;
    strncpy(n->kind, "text", sizeof(n->kind) - 1);
    n->kind[sizeof(n->kind) - 1] = 0;
    _aipl_json_escape_into(s, n->text, sizeof(n->text));
    int tw = (int)(strlen(s) * (sz > 4.0 ? sz * 0.56 : 10.0));
    int th = (int)(sz > 4.0 ? sz * 1.2 : 16.0);
    if (tw < 24) tw = 24;
    if (th < 14) th = 14;
    n->x = x; n->y = y; n->w = tw; n->h = th;
    n->fg_rgb = fg; n->bg_rgb = bg;
    n->clickable = 0;
    n->contrast_ratio = _aipl_compute_contrast_ratio(fg, bg);
  }
}

uint64_t _aipl_gl_frame_hash = 0ULL;

static uint64_t _aipl_compute_fb_hash(void) {
  if (_aipl_window_backend == 2 && _aipl_gl_frame_hash != 0ULL) {
    return _aipl_gl_frame_hash;
  }
  _aipl_sync_gl_to_fb();
  if (!_aipl_canvas_fb || _aipl_canvas_w <= 0 || _aipl_canvas_h <= 0) return 0ULL;
  uint64_t h = 1469598103934665603ULL;
  size_t total_bytes = (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h * 4;
  size_t step = (total_bytes > 16384) ? (total_bytes / 4096) : 4;
  if (step < 4) step = 4;
  for (size_t i = 0; i < total_bytes; i += step) {
    h ^= (uint64_t)_aipl_canvas_fb[i];
    h *= 1099511628211ULL;
  }
  return h;
}

void _aipl_write_window_state_json(void) {
  if (_aipl_benchmark_window_fps) return;
  mkdir("/tmp/aipl_windows", 0777);
  int pid = (int)getpid();
  char tmppath[256], finalpath[256];
  snprintf(tmppath, sizeof(tmppath), "/tmp/aipl_windows/.win_%d.state.json.tmp", pid);
  snprintf(finalpath, sizeof(finalpath), "/tmp/aipl_windows/win_%d.state.json", pid);
  FILE* fp = fopen(tmppath, "w");
  if (!fp) return;
  char esc_title[256];
  _aipl_json_escape_into(_aipl_win_title[0] ? _aipl_win_title : "AIPL Window", esc_title, sizeof(esc_title));
  const char* ttype = getenv("AIPL_TARGET_TYPE");
  if (!ttype || !ttype[0]) ttype = "native";
  uint64_t fbh = _aipl_compute_fb_hash();
  fprintf(fp, "{\n");
  fprintf(fp, "  \"pid\": %d,\n  \"windowId\": \"%lu\",\n  \"title\": \"%s\",\n  \"targetType\": \"%s\",\n", pid, _aipl_x11_win, esc_title, ttype);
  fprintf(fp, "  \"frame\": %d,\n  \"fps\": %.2f,\n  \"frameTimeMs\": %.3f,\n", _aipl_frames, _aipl_current_fps, _aipl_frame_time_ms);
  fprintf(fp, "  \"width\": %d,\n  \"height\": %d,\n  \"mouseX\": %d,\n  \"mouseY\": %d,\n", _aipl_canvas_w, _aipl_canvas_h, _aipl_mouse_x, _aipl_mouse_y);
  fprintf(fp, "  \"audioEnergy\": %.4f,\n  \"framebufferHash\": \"0x%016llx\",\n", _aipl_audio_current_energy, (unsigned long long)fbh);
  fprintf(fp, "  \"activeSeat\": %d,\n  \"turnNumber\": %d,\n  \"phase\": \"%s\",\n  \"legalActionsCount\": %d,\n  \"scores\": %s,\n  \"gameOver\": %s,\n  \"winnerSeat\": %d,\n  \"outOfTurnRejected\": %d,\n",
          _aipl_sg_active_seat, _aipl_sg_turn_number, _aipl_sg_phase, _aipl_sg_legal_actions,
          _aipl_sg_scores[0] ? _aipl_sg_scores : "[0,0,0,0]", _aipl_sg_game_over ? "true" : "false", _aipl_sg_winner_seat, _aipl_sg_oot_rejected);
  fprintf(fp, "  \"turnState\": {\"activeSeat\": %d, \"turnNumber\": %d, \"phase\": \"%s\", \"legalActionsCount\": %d, \"scores\": %s, \"gameOver\": %s, \"winnerSeat\": %d, \"outOfTurnRejected\": %d},\n",
          _aipl_sg_active_seat, _aipl_sg_turn_number, _aipl_sg_phase, _aipl_sg_legal_actions,
          _aipl_sg_scores[0] ? _aipl_sg_scores : "[0,0,0,0]", _aipl_sg_game_over ? "true" : "false", _aipl_sg_winner_seat, _aipl_sg_oot_rejected);
  fprintf(fp, "  \"uiNodes\": [");
  for (int i = 0; i < _aipl_sg_ui_count; i++) {
    _AiplSgUiNode* n = &_aipl_sg_ui_nodes[i];
    fprintf(fp, "%s{\"id\":\"ui_%d\",\"kind\":\"%s\",\"text\":\"%s\",\"x\":%d,\"y\":%d,\"w\":%d,\"h\":%d,\"fgColor\":\"#%06X\",\"bgColor\":\"#%06X\",\"clickable\":%s,\"contrastRatio\":%.2f}",
            (i > 0 ? "," : ""), n->id - 1, n->kind, n->text, n->x, n->y, n->w, n->h, n->fg_rgb & 0xFFFFFFu, n->bg_rgb & 0xFFFFFFu, n->clickable ? "true" : "false", n->contrast_ratio);
  }
  fprintf(fp, "],\n  \"entities\": [");
  for (int i = 0; i < _aipl_sg_entity_count; i++) {
    _AiplSgEntity* e = &_aipl_sg_entities[i];
    fprintf(fp, "%s{\"id\":%d,\"tag\":\"%s\",\"ownerSeat\":%d,\"x\":%.1f,\"y\":%.1f,\"vx\":%.1f,\"vy\":%.1f,\"w\":%d,\"h\":%d,\"hp\":%d,\"state\":\"%s\"}",
            (i > 0 ? "," : ""), e->id, e->tag, e->owner_seat, e->x, e->y, e->vx, e->vy, e->w, e->h, e->hp, e->state);
  }
  fprintf(fp, "],\n  \"customState\": {");
  for (int i = 0; i < _aipl_sg_custom_count; i++) {
    const char* kv = _aipl_sg_custom_vals[i];
    int is_raw_json = (kv[0] == '{' || kv[0] == '[' || (kv[0] >= '0' && kv[0] <= '9') || kv[0] == '-' || strcmp(kv, "true") == 0 || strcmp(kv, "false") == 0);
    if (is_raw_json) {
      fprintf(fp, "%s\"%s\":%s", (i > 0 ? "," : ""), _aipl_sg_custom_keys[i], kv);
    } else {
      char esc_v[512];
      _aipl_json_escape_into(kv, esc_v, sizeof(esc_v));
      fprintf(fp, "%s\"%s\":\"%s\"", (i > 0 ? "," : ""), _aipl_sg_custom_keys[i], esc_v);
    }
  }
  fprintf(fp, "}\n}\n");
  fclose(fp);
  rename(tmppath, finalpath);
}

AiplScissorRect _aipl_scissor_stack[8];
int _aipl_scissor_sp = 0;
int _aipl_scissor_x = 0;
int _aipl_scissor_y = 0;
int _aipl_scissor_w = 0;
int _aipl_scissor_h = 0;
int _aipl_scissor_active = 0;
void aipl_ensure_canvas_fb(void) {
  if (_aipl_canvas_w <= 0) _aipl_canvas_w = 800;
  if (_aipl_canvas_h <= 0) _aipl_canvas_h = 600;
  if (!_aipl_canvas_fb) {
    _aipl_canvas_fb = (uint8_t*)calloc((size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h * 4, 1);
  }
}

void aipl_canvas_set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  if (x < 0 || x >= _aipl_canvas_w || y < 0 || y >= _aipl_canvas_h) return;
  if (_aipl_scissor_active) {
    if (x < _aipl_scissor_x || x >= _aipl_scissor_x + _aipl_scissor_w ||
        y < _aipl_scissor_y || y >= _aipl_scissor_y + _aipl_scissor_h) return;
  }
  aipl_ensure_canvas_fb();
  size_t idx = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
  if (a == 0) return;
  if (_aipl_cur_blend_mode == 0) {
    if (a == 255) {
      _aipl_canvas_fb[idx]     = b;
      _aipl_canvas_fb[idx + 1] = g;
      _aipl_canvas_fb[idx + 2] = r;
      _aipl_canvas_fb[idx + 3] = 255;
    } else {
      uint32_t sa = a;
      uint32_t da = 255 - sa;
      _aipl_canvas_fb[idx]     = (uint8_t)((b * sa + _aipl_canvas_fb[idx] * da) / 255);
      _aipl_canvas_fb[idx + 1] = (uint8_t)((g * sa + _aipl_canvas_fb[idx + 1] * da) / 255);
      _aipl_canvas_fb[idx + 2] = (uint8_t)((r * sa + _aipl_canvas_fb[idx + 2] * da) / 255);
      _aipl_canvas_fb[idx + 3] = 255;
    }
  } else if (_aipl_cur_blend_mode == 1) {
    uint32_t sa = a;
    uint32_t ob = (uint32_t)_aipl_canvas_fb[idx]     + ((uint32_t)b * sa) / 255u;
    uint32_t og = (uint32_t)_aipl_canvas_fb[idx + 1] + ((uint32_t)g * sa) / 255u;
    uint32_t or_ = (uint32_t)_aipl_canvas_fb[idx + 2] + ((uint32_t)r * sa) / 255u;
    _aipl_canvas_fb[idx]     = (uint8_t)(ob > 255u ? 255u : ob);
    _aipl_canvas_fb[idx + 1] = (uint8_t)(og > 255u ? 255u : og);
    _aipl_canvas_fb[idx + 2] = (uint8_t)(or_ > 255u ? 255u : or_);
    _aipl_canvas_fb[idx + 3] = 255;
  } else if (_aipl_cur_blend_mode == 2) {
    uint32_t sa = a, da = 255u - sa;
    uint32_t db = _aipl_canvas_fb[idx], dg = _aipl_canvas_fb[idx + 1], dr = _aipl_canvas_fb[idx + 2];
    uint32_t mb = ((uint32_t)b * db) / 255u;
    uint32_t mg = ((uint32_t)g * dg) / 255u;
    uint32_t mr = ((uint32_t)r * dr) / 255u;
    _aipl_canvas_fb[idx]     = (uint8_t)((mb * sa + db * da) / 255u);
    _aipl_canvas_fb[idx + 1] = (uint8_t)((mg * sa + dg * da) / 255u);
    _aipl_canvas_fb[idx + 2] = (uint8_t)((mr * sa + dr * da) / 255u);
    _aipl_canvas_fb[idx + 3] = 255;
  } else if (_aipl_cur_blend_mode == 3) {
    uint32_t sa = a;
    uint32_t db = _aipl_canvas_fb[idx], dg = _aipl_canvas_fb[idx + 1], dr = _aipl_canvas_fb[idx + 2];
    uint32_t esb = ((uint32_t)b * sa) / 255u;
    uint32_t esg = ((uint32_t)g * sa) / 255u;
    uint32_t esr = ((uint32_t)r * sa) / 255u;
    _aipl_canvas_fb[idx]     = (uint8_t)(255u - ((255u - esb) * (255u - db)) / 255u);
    _aipl_canvas_fb[idx + 1] = (uint8_t)(255u - ((255u - esg) * (255u - dg)) / 255u);
    _aipl_canvas_fb[idx + 2] = (uint8_t)(255u - ((255u - esr) * (255u - dr)) / 255u);
    _aipl_canvas_fb[idx + 3] = 255;
  }
}

void _aipl_cleanup_window_registry(void) {
  char path[256];
  int pid = (int)getpid();
  snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.info", pid);
  unlink(path);
  snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.state.json", pid);
  unlink(path);
  snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.cmd", pid);
  unlink(path);
  snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.ack", pid);
  unlink(path);
  for (int s = 0; s <= 16; s++) {
    snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.cmd.%d", pid, s);
    unlink(path);
    snprintf(path, sizeof(path), "/tmp/aipl_windows/win_%d.ack.%d", pid, s);
    unlink(path);
  }
  if (_aipl_instance_lock_fd >= 0) {
    flock(_aipl_instance_lock_fd, LOCK_UN);
    close(_aipl_instance_lock_fd);
    _aipl_instance_lock_fd = -1;
  }
}

void _aipl_write_window_info(void) {
  mkdir("/tmp/aipl_windows", 0777);
  char infopath[256];
  snprintf(infopath, sizeof(infopath), "/tmp/aipl_windows/win_%d.info", (int)getpid());
  FILE* fp = fopen(infopath, "w");
  if (fp) {
    const char* ttype = getenv("AIPL_TARGET_TYPE");
    if (!ttype || !ttype[0]) ttype = "native";
    fprintf(fp, "pid=%d\nwindow_id=%lu\ntitle=%s\nx=%d\ny=%d\nwidth=%d\nheight=%d\nframe=%d\ntargetType=%s\n", (int)getpid(), _aipl_x11_win, _aipl_win_title[0] ? _aipl_win_title : "AIPL Window", _aipl_win_x, _aipl_win_y, _aipl_canvas_w, _aipl_canvas_h, _aipl_frames, ttype);
    fclose(fp);
  }
}

void _aipl_compute_initial_window_pos(int w, int h, int screenW, int screenH, int* out_x, int* out_y) {
  if (screenW <= 0) screenW = 1920;
  if (screenH <= 0) screenH = 1080;
  int x = _aipl_window_pos_manual ? _aipl_win_x : 40;
  int y = _aipl_window_pos_manual ? _aipl_win_y : 40;
  if (!_aipl_window_pos_manual) {
    if (w >= screenW - 40) x = 0;
    if (h >= screenH - 40) y = 0;
    int self_pid = (int)getpid();
    DIR* d = opendir("/tmp/aipl_windows");
    if (d) {
      struct dirent* de;
      int peer_found = 0;
      int peer_x = 0, peer_y = 0, peer_w = 0, peer_h = 0;
      while ((de = readdir(d)) != NULL) {
        if (strncmp(de->d_name, "win_", 4) == 0 && strstr(de->d_name, ".info") != NULL) {
          int pid = atoi(de->d_name + 4);
          if (pid <= 0 || pid == self_pid) continue;
          if (kill((pid_t)pid, 0) != 0) continue;
          char fpath[256];
          snprintf(fpath, sizeof(fpath), "/tmp/aipl_windows/%s", de->d_name);
          FILE* fp = fopen(fpath, "r");
          if (fp) {
            char line[256];
            int px = 40, py = 40, pw = 800, ph = 600;
            while (fgets(line, sizeof(line), fp)) {
              if (strncmp(line, "x=", 2) == 0) px = atoi(line + 2);
              else if (strncmp(line, "y=", 2) == 0) py = atoi(line + 2);
              else if (strncmp(line, "width=", 6) == 0) pw = atoi(line + 6);
              else if (strncmp(line, "height=", 7) == 0) ph = atoi(line + 7);
            }
            fclose(fp);
            peer_found = 1;
            peer_x = px; peer_y = py; peer_w = pw; peer_h = ph;
            break;
          }
        }
      }
      closedir(d);
      if (peer_found && peer_w > 0) {
        if (peer_x + peer_w + 16 + w <= screenW) {
          x = peer_x + peer_w + 16;
          y = peer_y;
        } else if (peer_x + peer_w + w <= screenW) {
          x = peer_x + peer_w;
          y = peer_y;
        } else {
          x = screenW - w;
          y = peer_y;
        }
        (void)peer_h;
      }
    }
  }
  if (x + w > screenW) x = screenW - w;
  if (y + h > screenH) y = screenH - h;
  if (x < 0) x = 0;
  if (y < 0) y = 0;
  _aipl_win_x = x;
  _aipl_win_y = y;
  if (out_x) *out_x = x;
  if (out_y) *out_y = y;
}

int _aipl_resolve_window_target(const char* target, int* out_pid) {
  mkdir("/tmp/aipl_windows", 0777);
  DIR* d = opendir("/tmp/aipl_windows");
  if (!d) return 0;
  struct dirent* de;
  int matched_pid = -1;
  int first_pid = -1;
  int target_is_num = 1;
  if (!target || !target[0] || strcmp(target, "active") == 0 || strcmp(target, "default") == 0 || strcmp(target, "any") == 0) {
    target = "";
  }
  for (const char* p = target; *p; p++) {
    if (!isdigit((unsigned char)*p)) { target_is_num = 0; break; }
  }
  int target_num = (target_is_num && target[0]) ? atoi(target) : -1;
  while ((de = readdir(d)) != NULL) {
    if (strncmp(de->d_name, "win_", 4) == 0 && strstr(de->d_name, ".info") != NULL) {
      int pid = atoi(de->d_name + 4);
      if (pid > 0 && kill((pid_t)pid, 0) != 0) {
        char fpath[256];
        snprintf(fpath, sizeof(fpath), "/tmp/aipl_windows/%s", de->d_name);
        unlink(fpath);
        continue;
      }
      if (first_pid < 0) first_pid = pid;
      if (target_num > 0 && pid == target_num) {
        matched_pid = pid;
        break;
      }
      char fpath[256];
      snprintf(fpath, sizeof(fpath), "/tmp/aipl_windows/%s", de->d_name);
      FILE* fp = fopen(fpath, "r");
      if (fp) {
        char line[256];
        char title[128] = "";
        char win_id[64] = "";
        while (fgets(line, sizeof(line), fp)) {
          if (strncmp(line, "title=", 6) == 0) {
            strncpy(title, line + 6, sizeof(title) - 1);
            title[strcspn(title, "\r\n")] = 0;
          } else if (strncmp(line, "window_id=", 10) == 0) {
            strncpy(win_id, line + 10, sizeof(win_id) - 1);
            win_id[strcspn(win_id, "\r\n")] = 0;
          }
        }
        fclose(fp);
        if (target[0] && (strcmp(win_id, target) == 0 || strstr(title, target) != NULL)) {
          matched_pid = pid;
          break;
        }
      }
    }
  }
  closedir(d);
  if (matched_pid > 0) {
    *out_pid = matched_pid;
    return 1;
  }
  if (!target[0] && first_pid > 0) {
    *out_pid = first_pid;
    return 1;
  }
  return 0;
}

AiplVal aipl_rt_setSingleInstance(AiplVal enabled) {
  int on = aipl_truthy(enabled);
  if (on) {
    if (_aipl_single_instance_mode && _aipl_instance_lock_fd >= 0) return aipl_bool(true);
    char lockname[256]; memset(lockname, 0, sizeof(lockname));
    if (_aipl_win_title[0] && strcmp(_aipl_win_title, "AIPL Window") != 0 && strcmp(_aipl_win_title, "AIPL Canvas") != 0) {
      strncpy(lockname, _aipl_win_title, sizeof(lockname) - 1);
    } else if (getenv("AIPL_INSTANCE_NAME") && getenv("AIPL_INSTANCE_NAME")[0]) {
      strncpy(lockname, getenv("AIPL_INSTANCE_NAME"), sizeof(lockname) - 1);
    } else if (g_aipl_argv && g_aipl_argc > 0 && g_aipl_argv[0]) {
      const char* base = strrchr(g_aipl_argv[0], '/');
      strncpy(lockname, base ? base + 1 : g_aipl_argv[0], sizeof(lockname) - 1);
    } else {
      strncpy(lockname, "default", sizeof(lockname) - 1);
    }
    for (int i = 0; lockname[i]; i++) {
      if (!isalnum((unsigned char)lockname[i])) lockname[i] = '_';
    }
    char lockpath[512];
    snprintf(lockpath, sizeof(lockpath), "/tmp/aipl_single_instance_%s.lock", lockname);
    int fd = open(lockpath, O_CREAT | O_RDWR, 0666);
    if (fd < 0) return aipl_bool(false);
    if (flock(fd, LOCK_EX | LOCK_NB) != 0) {
      close(fd);
      const char* no_exit = getenv("AIPL_SINGLE_INSTANCE_NO_EXIT");
      if (no_exit && strcmp(no_exit, "1") == 0) {
        return aipl_bool(false);
      }
      fprintf(stderr, "[AIPL] Single-instance lock active: another instance is already running.\n");
      exit(0);
    }
    if (ftruncate(fd, 0) < 0) {}
    char pid_buf[32];
    snprintf(pid_buf, sizeof(pid_buf), "%d\n", (int)getpid());
    ssize_t _w = write(fd, pid_buf, strlen(pid_buf));
    (void)_w;
    _aipl_instance_lock_fd = fd;
    _aipl_single_instance_mode = 1;
    if (!_aipl_atexit_registered) {
      atexit(_aipl_cleanup_window_registry);
      _aipl_atexit_registered = 1;
    }
    return aipl_bool(true);
  } else {
    if (_aipl_instance_lock_fd >= 0) {
      flock(_aipl_instance_lock_fd, LOCK_UN);
      close(_aipl_instance_lock_fd);
      _aipl_instance_lock_fd = -1;
    }
    _aipl_single_instance_mode = 0;
    return aipl_bool(true);
  }
}

AiplVal aipl_rt_isSingleInstance(void) {
  return aipl_bool(_aipl_single_instance_mode);
}

AiplVal aipl_rt_setWindowPosition(AiplVal x_val, AiplVal y_val) {
  int x = (int)aipl_to_int(x_val).i;
  int y = (int)aipl_to_int(y_val).i;
  _aipl_window_pos_manual = 1;
#ifndef _WIN32
  int screenW = 1920, screenH = 1080;
  if (_aipl_x11_lib && _aipl_x11_dpy) {
    int (*fn_XDisplayWidth)(void*, int) = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XDisplayWidth");
    int (*fn_XDisplayHeight)(void*, int) = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XDisplayHeight");
    int scr = _aipl_X11_XDefaultScreen ? _aipl_X11_XDefaultScreen(_aipl_x11_dpy) : 0;
    if (fn_XDisplayWidth) screenW = fn_XDisplayWidth(_aipl_x11_dpy, scr);
    if (fn_XDisplayHeight) screenH = fn_XDisplayHeight(_aipl_x11_dpy, scr);
    if (screenW <= 0) screenW = 1920;
    if (screenH <= 0) screenH = 1080;
  }
  if (_aipl_canvas_w > 0 && x + _aipl_canvas_w > screenW) x = screenW - _aipl_canvas_w;
  if (_aipl_canvas_h > 0 && y + _aipl_canvas_h > screenH) y = screenH - _aipl_canvas_h;
  if (x < 0) x = 0;
  if (y < 0) y = 0;
  _aipl_win_x = x;
  _aipl_win_y = y;
  if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy && _aipl_x11_win && _aipl_X11_XMoveWindow) {
    _aipl_X11_XMoveWindow(_aipl_x11_dpy, _aipl_x11_win, x, y);
    if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
    _aipl_write_window_info();
  }
#else
  _aipl_win_x = x;
  _aipl_win_y = y;
#endif
  return aipl_nil();
}

AiplVal aipl_rt_targetWindowScreenshot(AiplVal target_v, AiplVal outPath_v) {
  const char* target = (target_v.kind == AIPL_STR && target_v.s) ? target_v.s : "";
  const char* out_path = (outPath_v.kind == AIPL_STR && outPath_v.s) ? outPath_v.s : "screenshot.png";
  int pid = -1;
  if (!_aipl_resolve_window_target(target, &pid)) return aipl_bool(false);
  char cmd_path[256], ack_path[256];
  snprintf(cmd_path, sizeof(cmd_path), "/tmp/aipl_windows/win_%d.cmd", pid);
  snprintf(ack_path, sizeof(ack_path), "/tmp/aipl_windows/win_%d.ack", pid);
  unlink(ack_path);
  FILE* fp = fopen(cmd_path, "w");
  if (!fp) return aipl_bool(false);
  fprintf(fp, "screenshot:%s\n", out_path);
  fclose(fp);
  for (int i = 0; i < 300; i++) {
    if (access(ack_path, F_OK) == 0) {
      unlink(ack_path);
      return aipl_bool(true);
    }
    struct timespec req = { 0, 10000000L };
    nanosleep(&req, NULL);
  }
  return aipl_bool(false);
}

AiplVal aipl_rt_targetWindowRecord(AiplVal target_v, AiplVal outPath_v, AiplVal frames_v, AiplVal fps_v) {
  const char* target = (target_v.kind == AIPL_STR && target_v.s) ? target_v.s : "";
  const char* out_path = (outPath_v.kind == AIPL_STR && outPath_v.s) ? outPath_v.s : "recording.mp4";
  int frames = (int)aipl_to_int(frames_v).i;
  if (frames <= 0) frames = 30;
  int fps = (int)aipl_to_int(fps_v).i;
  if (fps <= 0) fps = 30;
  int pid = -1;
  if (!_aipl_resolve_window_target(target, &pid)) return aipl_bool(false);
  char cmd_path[256], ack_path[256];
  snprintf(cmd_path, sizeof(cmd_path), "/tmp/aipl_windows/win_%d.cmd", pid);
  snprintf(ack_path, sizeof(ack_path), "/tmp/aipl_windows/win_%d.ack", pid);
  unlink(ack_path);
  FILE* fp = fopen(cmd_path, "w");
  if (!fp) return aipl_bool(false);
  fprintf(fp, "record:%s:%d:%d\n", out_path, frames, fps);
  fclose(fp);
  int max_wait_ms = (frames * 1000 / (fps > 0 ? fps : 30)) + 5000;
  for (int i = 0; i < max_wait_ms / 10; i++) {
    if (access(ack_path, F_OK) == 0) {
      unlink(ack_path);
      return aipl_bool(true);
    }
    struct timespec req = { 0, 10000000L };
    nanosleep(&req, NULL);
  }
  return aipl_bool(false);
}

AiplVal aipl_rt_targetWindowSeatAction(AiplVal target_v, AiplVal seat_v, AiplVal script_v) {
  const char* raw_target = (target_v.kind == AIPL_STR && target_v.s) ? target_v.s : "";
  const char* script = (script_v.kind == AIPL_STR && script_v.s) ? script_v.s : "";
  int seat_id = (int)((seat_v.kind == AIPL_FLOAT) ? seat_v.f : seat_v.i);
  char target_clean[128];
  strncpy(target_clean, raw_target, sizeof(target_clean) - 1);
  target_clean[sizeof(target_clean) - 1] = 0;
  char* at_seat = strstr(target_clean, "@seat");
  if (at_seat) {
    if (seat_id <= 0) seat_id = atoi(at_seat + 5);
    *at_seat = 0;
  }
  if (seat_id <= 0 && strncmp(script, "seat:", 5) == 0) {
    seat_id = atoi(script + 5);
    const char* semi = strchr(script, ';');
    if (semi) script = semi + 1;
  }
  if (seat_id <= 0 && getenv("AIPL_HEBAR_SEAT") && getenv("AIPL_HEBAR_SEAT")[0]) {
    seat_id = atoi(getenv("AIPL_HEBAR_SEAT"));
  }
  int pid = -1;
  if (!_aipl_resolve_window_target(target_clean, &pid)) return aipl_bool(false);
  char tmp_cmd[256], cmd_path[256], ack_path[256];
  if (seat_id > 0) {
    snprintf(tmp_cmd, sizeof(tmp_cmd), "/tmp/aipl_windows/.win_%d.cmd.%d.%d.tmp", pid, seat_id, (int)getpid());
    snprintf(cmd_path, sizeof(cmd_path), "/tmp/aipl_windows/win_%d.cmd.%d", pid, seat_id);
    snprintf(ack_path, sizeof(ack_path), "/tmp/aipl_windows/win_%d.ack.%d", pid, seat_id);
  } else {
    snprintf(tmp_cmd, sizeof(tmp_cmd), "/tmp/aipl_windows/.win_%d.cmd.%d.tmp", pid, (int)getpid());
    snprintf(cmd_path, sizeof(cmd_path), "/tmp/aipl_windows/win_%d.cmd", pid);
    snprintf(ack_path, sizeof(ack_path), "/tmp/aipl_windows/win_%d.ack", pid);
  }
  unlink(ack_path);
  FILE* fp = fopen(tmp_cmd, "w");
  if (!fp) return aipl_bool(false);
  fprintf(fp, "action:%s\n", script);
  fclose(fp);
  rename(tmp_cmd, cmd_path);
  for (int i = 0; i < 1500; i++) {
    if (access(ack_path, F_OK) == 0) {
      unlink(ack_path);
      return aipl_bool(true);
    }
    struct timespec req = { 0, 2000000L };
    nanosleep(&req, NULL);
  }
  return aipl_bool(false);
}

AiplVal aipl_rt_targetWindowAction(AiplVal target_v, AiplVal script_v) {
  return aipl_rt_targetWindowSeatAction(target_v, aipl_int(0), script_v);
}

AiplVal aipl_rt_publishBotState(AiplVal key_v, AiplVal jsonVal_v) {
  const char* k = (key_v.kind == AIPL_STR && key_v.s) ? key_v.s : "";
  const char* v = (jsonVal_v.kind == AIPL_STR && jsonVal_v.s) ? jsonVal_v.s : "";
  if (!k[0]) return aipl_bool(false);
  if (strcmp(k, "turnNumber") == 0) _aipl_sg_turn_number = atoi(v);
  else if (strcmp(k, "legalActionsCount") == 0) _aipl_sg_legal_actions = atoi(v);
  else if (strcmp(k, "scores") == 0) {
    strncpy(_aipl_sg_scores, v, sizeof(_aipl_sg_scores) - 1);
    _aipl_sg_scores[sizeof(_aipl_sg_scores) - 1] = 0;
  } else if (strcmp(k, "gameOver") == 0) {
    _aipl_sg_game_over = (strcmp(v, "true") == 0 || strcmp(v, "1") == 0) ? 1 : 0;
  }
  int idx = -1;
  for (int i = 0; i < _aipl_sg_custom_count; i++) {
    if (strcmp(_aipl_sg_custom_keys[i], k) == 0) { idx = i; break; }
  }
  if (idx < 0 && _aipl_sg_custom_count < 32) {
    idx = _aipl_sg_custom_count++;
    strncpy(_aipl_sg_custom_keys[idx], k, sizeof(_aipl_sg_custom_keys[idx]) - 1);
    _aipl_sg_custom_keys[idx][sizeof(_aipl_sg_custom_keys[idx]) - 1] = 0;
  }
  if (idx >= 0) {
    strncpy(_aipl_sg_custom_vals[idx], v, sizeof(_aipl_sg_custom_vals[idx]) - 1);
    _aipl_sg_custom_vals[idx][sizeof(_aipl_sg_custom_vals[idx]) - 1] = 0;
  }
  return aipl_bool(true);
}

AiplVal aipl_rt_publishTurnState(AiplVal activeSeat_v, AiplVal phase_v, AiplVal winnerSeat_v) {
  int a_seat = (int)((activeSeat_v.kind == AIPL_FLOAT) ? activeSeat_v.f : activeSeat_v.i);
  const char* ph = (phase_v.kind == AIPL_STR && phase_v.s) ? phase_v.s : "ACTIVE";
  int w_seat = (int)((winnerSeat_v.kind == AIPL_FLOAT) ? winnerSeat_v.f : winnerSeat_v.i);
  if (a_seat != _aipl_sg_active_seat && a_seat > 0) {
    _aipl_sg_turn_number++;
  }
  _aipl_sg_active_seat = (a_seat > 0) ? a_seat : 1;
  _aipl_sg_explicit_turn = 1;
  strncpy(_aipl_sg_phase, ph, sizeof(_aipl_sg_phase) - 1);
  _aipl_sg_phase[sizeof(_aipl_sg_phase) - 1] = 0;
  _aipl_sg_winner_seat = w_seat;
  _aipl_sg_game_over = (w_seat > 0 || strcmp(ph, "GAME_OVER") == 0) ? 1 : 0;
  return aipl_bool(true);
}

AiplVal aipl_rt_listRunningWindows(void) {
  mkdir("/tmp/aipl_windows", 0777);
  DIR* d = opendir("/tmp/aipl_windows");
  if (!d) return aipl_array_new(NULL, 0);
  AiplVal items[128];
  AiplVal self_items[16];
  int count = 0;
  int self_count = 0;
  int self_pid = (int)getpid();
  struct dirent* de;
  while ((de = readdir(d)) != NULL && count < 128) {
    if (strncmp(de->d_name, "win_", 4) == 0 && strstr(de->d_name, ".info") != NULL) {
      int pid = atoi(de->d_name + 4);
      if (pid > 0 && kill((pid_t)pid, 0) != 0) {
        char fpath[256];
        snprintf(fpath, sizeof(fpath), "/tmp/aipl_windows/%s", de->d_name);
        unlink(fpath);
        continue;
      }
      char fpath[256];
      snprintf(fpath, sizeof(fpath), "/tmp/aipl_windows/%s", de->d_name);
      FILE* fp = fopen(fpath, "r");
      if (fp) {
        char line[256];
        char title[128] = "AIPL Window";
        char win_id[64] = "0";
        int w = 800, h = 600, frame = 0;
        while (fgets(line, sizeof(line), fp)) {
          if (strncmp(line, "pid=", 4) == 0) pid = atoi(line + 4);
          else if (strncmp(line, "window_id=", 10) == 0) {
            strncpy(win_id, line + 10, sizeof(win_id) - 1);
            win_id[strcspn(win_id, "\r\n")] = 0;
          } else if (strncmp(line, "title=", 6) == 0) {
            strncpy(title, line + 6, sizeof(title) - 1);
            title[strcspn(title, "\r\n")] = 0;
          } else if (strncmp(line, "width=", 6) == 0) w = atoi(line + 6);
          else if (strncmp(line, "height=", 7) == 0) h = atoi(line + 7);
          else if (strncmp(line, "frame=", 6) == 0) frame = atoi(line + 6);
        }
        fclose(fp);
        char summary[512];
        snprintf(summary, sizeof(summary), "pid=%d window_id=%s title=%s width=%d height=%d frame=%d", pid, win_id, title, w, h, frame);
        if (pid == self_pid && self_count < 16) {
          self_items[self_count++] = aipl_str(summary);
        } else {
          items[count++] = aipl_str(summary);
        }
      }
    }
  }
  closedir(d);
  for (int si = 0; si < self_count && count < 128; si++) {
    items[count++] = self_items[si];
  }
  return aipl_array_new(items, count);
}

#else
AiplVal aipl_rt_targetWindowSeatAction(AiplVal target_v, AiplVal seat_v, AiplVal script_v) {
  (void)target_v; (void)seat_v; (void)script_v;
  return aipl_bool(false);
}
AiplVal aipl_rt_publishBotState(AiplVal key_v, AiplVal jsonVal_v) {
  (void)key_v; (void)jsonVal_v;
  return aipl_bool(true);
}
AiplVal aipl_rt_publishTurnState(AiplVal activeSeat_v, AiplVal phase_v, AiplVal winnerSeat_v) {
  (void)activeSeat_v; (void)phase_v; (void)winnerSeat_v;
  return aipl_bool(true);
}
#endif // AIPL_ENABLE_GUI_AUDIO
#ifdef AIPL_ENABLE_GUI_AUDIO
void* _aipl_audio_worker(void* arg) {
  (void)arg;
  const char* req_backend = getenv("AIPL_AUDIO_BACKEND");
  int allow_pulse = (!req_backend || !req_backend[0] || strcasecmp(req_backend, "auto") == 0 || strcasecmp(req_backend, "pulse") == 0);
  int allow_alsa  = (!req_backend || !req_backend[0] || strcasecmp(req_backend, "auto") == 0 || strcasecmp(req_backend, "alsa") == 0);
  int allow_sdl2  = (!req_backend || !req_backend[0] || strcasecmp(req_backend, "auto") == 0 || strcasecmp(req_backend, "sdl2") == 0 || strcasecmp(req_backend, "sdl") == 0);
  void* pulse_lib = allow_pulse ? dlopen("libpulse-simple.so.0", RTLD_LAZY) : NULL;
  void* (*pa_new)(const char*, const char*, int, const char*, const char*, const void*, const void*, const void*, int*) = NULL;
  int (*pa_write)(void*, const void*, size_t, int*) = NULL;
  void (*pa_free)(void*) = NULL;
  void* pa_handle = NULL;
  if (pulse_lib) {
    pa_new = (void* (*)(const char*, const char*, int, const char*, const char*, const void*, const void*, const void*, int*))dlsym(pulse_lib, "pa_simple_new");
    pa_write = (int (*)(void*, const void*, size_t, int*))dlsym(pulse_lib, "pa_simple_write");
    pa_free = (void (*)(void*))dlsym(pulse_lib, "pa_simple_free");
    if (pa_new && pa_write && pa_free) {
      struct { int format; uint32_t rate; uint8_t channels; } ss = { 3, 44100, 2 };
      int err = 0;
      pa_handle = pa_new(NULL, "AIPL Audio", 1, NULL, "Audio Stream", &ss, NULL, NULL, &err);
    }
  }
  void* alsa_lib = NULL;
  void* alsa_pcm = NULL;
  int (*snd_pcm_open_fn)(void**, const char*, int, int) = NULL;
  int (*snd_pcm_set_params_fn)(void*, int, int, unsigned int, unsigned int, int, unsigned int) = NULL;
  long (*snd_pcm_writei_fn)(void*, const void*, unsigned long) = NULL;
  int (*snd_pcm_recover_fn)(void*, int, int) = NULL;
  int (*snd_pcm_close_fn)(void*) = NULL;
  if (!pa_handle && allow_alsa) {
    alsa_lib = dlopen("libasound.so.2", RTLD_LAZY);
    if (alsa_lib) {
      snd_pcm_open_fn = (int (*)(void**, const char*, int, int))dlsym(alsa_lib, "snd_pcm_open");
      snd_pcm_set_params_fn = (int (*)(void*, int, int, unsigned int, unsigned int, int, unsigned int))dlsym(alsa_lib, "snd_pcm_set_params");
      snd_pcm_writei_fn = (long (*)(void*, const void*, unsigned long))dlsym(alsa_lib, "snd_pcm_writei");
      snd_pcm_recover_fn = (int (*)(void*, int, int))dlsym(alsa_lib, "snd_pcm_recover");
      snd_pcm_close_fn = (int (*)(void*))dlsym(alsa_lib, "snd_pcm_close");
      if (snd_pcm_open_fn && snd_pcm_set_params_fn && snd_pcm_writei_fn) {
        if (snd_pcm_open_fn(&alsa_pcm, "default", 0, 0) == 0 && alsa_pcm) {
          if (snd_pcm_set_params_fn(alsa_pcm, 2, 3, 2, 44100, 1, 40000) != 0) {
            if (snd_pcm_close_fn) snd_pcm_close_fn(alsa_pcm);
            alsa_pcm = NULL;
          }
        }
      }
    }
  }
  void* sdl_lib = NULL;
  uint32_t sdl_dev = 0;
  int (*sdl_init_sub)(uint32_t) = NULL;
  uint32_t (*sdl_open_audio)(const char*, int, const void*, void*, int) = NULL;
  void (*sdl_pause_audio)(uint32_t, int) = NULL;
  int (*sdl_queue_audio)(uint32_t, const void*, uint32_t) = NULL;
  uint32_t (*sdl_get_queued)(uint32_t) = NULL;
  void (*sdl_close_audio)(uint32_t) = NULL;
  if (!pa_handle && !alsa_pcm && allow_sdl2) {
    sdl_lib = dlopen("libSDL2-2.0.so.0", RTLD_LAZY);
    if (sdl_lib) {
      sdl_init_sub = (int (*)(uint32_t))dlsym(sdl_lib, "SDL_InitSubSystem");
      sdl_open_audio = (uint32_t (*)(const char*, int, const void*, void*, int))dlsym(sdl_lib, "SDL_OpenAudioDevice");
      sdl_pause_audio = (void (*)(uint32_t, int))dlsym(sdl_lib, "SDL_PauseAudioDevice");
      sdl_queue_audio = (int (*)(uint32_t, const void*, uint32_t))dlsym(sdl_lib, "SDL_QueueAudio");
      sdl_get_queued = (uint32_t (*)(uint32_t))dlsym(sdl_lib, "SDL_GetQueuedAudioSize");
      sdl_close_audio = (void (*)(uint32_t))dlsym(sdl_lib, "SDL_CloseAudioDevice");
      if (sdl_init_sub && sdl_open_audio && sdl_pause_audio && sdl_queue_audio) {
        if (sdl_init_sub(0x00000010u) == 0) {
          struct { int freq; uint16_t format; uint8_t channels; uint8_t silence; uint16_t samples; uint16_t padding; uint32_t size; void* callback; void* userdata; } want = { 44100, 0x8010u, 2, 0, 1024, 0, 0, NULL, NULL }, have;
          sdl_dev = sdl_open_audio(NULL, 0, &want, &have, 0);
          if (sdl_dev > 0) sdl_pause_audio(sdl_dev, 0);
        }
      }
    }
  }
  int16_t mix_buf[1024 * 2];
  while (_aipl_audio_thread_running) {
    _aipl_audio_mix_samples(mix_buf, 1024);
    if (pa_handle && pa_write) {
      int err = 0;
      pa_write(pa_handle, mix_buf, sizeof(mix_buf), &err);
    } else if (alsa_pcm && snd_pcm_writei_fn) {
      long fw = snd_pcm_writei_fn(alsa_pcm, mix_buf, 1024);
      if (fw < 0 && snd_pcm_recover_fn) {
        snd_pcm_recover_fn(alsa_pcm, (int)fw, 1);
      }
    } else if (sdl_dev > 0 && sdl_queue_audio) {
      while (_aipl_audio_thread_running && sdl_get_queued && sdl_get_queued(sdl_dev) > 8192) {
        struct timespec req = { 0, 5000000L };
        nanosleep(&req, NULL);
      }
      sdl_queue_audio(sdl_dev, mix_buf, sizeof(mix_buf));
    } else {
      struct timespec req = { 0, 23200000L };
      nanosleep(&req, NULL);
    }
  }
  if (pa_handle && pa_free) pa_free(pa_handle);
  if (alsa_pcm && snd_pcm_close_fn) snd_pcm_close_fn(alsa_pcm);
  if (sdl_dev > 0 && sdl_close_audio) sdl_close_audio(sdl_dev);
  if (sdl_lib) {
    void (*sdl_quit_sub)(uint32_t) = (void (*)(uint32_t))dlsym(sdl_lib, "SDL_QuitSubSystem");
    if (sdl_quit_sub) sdl_quit_sub(0x00000010u);
  }
  return NULL;
}

void _aipl_init_audio(void) {
  if (_aipl_audio_thread_active || _aipl_audio_thread_running) return;
  const char* no_audio = getenv("AIPL_NO_AUDIO");
  if (no_audio && strcmp(no_audio, "1") == 0) return;
  const char* headless = getenv("AIPL_HEADLESS");
  if (headless && strcmp(headless, "1") == 0) return;
  _aipl_audio_thread_running = 1;
  if (pthread_create(&_aipl_audio_thread, NULL, _aipl_audio_worker, NULL) == 0) {
    _aipl_audio_thread_active = 1;
  } else {
    _aipl_audio_thread_running = 0;
    _aipl_audio_thread_active = 0;
  }
}

int _aipl_alloc_voice(void) {
  pthread_mutex_lock(&_aipl_audio_mutex);
  if (_aipl_voices_cap == 0) _aipl_ensure_voices_cap(32);
  int best_slot = -1;
  double oldest_age = -1.0;
  for (int i = 0; i < _aipl_voices_cap; i++) {
    if (!_aipl_voices[i].active) { best_slot = i; break; }
    if (_aipl_voices[i].age > oldest_age) { oldest_age = _aipl_voices[i].age; best_slot = i; }
  }
  if (best_slot >= 0 && _aipl_voices[best_slot].active && _aipl_voices_cap < 256) {
    int old_cap = _aipl_voices_cap;
    _aipl_ensure_voices_cap(old_cap * 2);
    best_slot = old_cap;
  }
  if (best_slot >= 0) {
    if (_aipl_voices[best_slot].pcm_data) { free(_aipl_voices[best_slot].pcm_data); _aipl_voices[best_slot].pcm_data = NULL; }
    memset(&_aipl_voices[best_slot], 0, sizeof(_AiplAudioVoice));
    _aipl_voices[best_slot].active = 1;
    _aipl_voices[best_slot].voice_id = _aipl_next_voice_id++;
  }
  pthread_mutex_unlock(&_aipl_audio_mutex);
  return best_slot;
}

AiplVal _aipl_playTone_impl(double freq, double dur_ms, double vol, const char* wave_str) {
  _aipl_init_audio();
  int wave = 0;
  if (wave_str) {
    if (strcmp(wave_str, "square") == 0) wave = 1;
    else if (strcmp(wave_str, "triangle") == 0) wave = 2;
    else if (strcmp(wave_str, "saw") == 0 || strcmp(wave_str, "sawtooth") == 0) wave = 3;
    else if (strcmp(wave_str, "noise") == 0) wave = 4;
    else if (strcmp(wave_str, "pad") == 0 || strcmp(wave_str, "warm") == 0) wave = 6;
    else if (strcmp(wave_str, "bell") == 0 || strcmp(wave_str, "rhodes") == 0 || strcmp(wave_str, "fm") == 0) wave = 7;
    else if (strcmp(wave_str, "pluck") == 0 || strcmp(wave_str, "harp") == 0) wave = 8;
  }
  int slot = _aipl_alloc_voice();
  if (slot >= 0) {
    pthread_mutex_lock(&_aipl_audio_mutex);
    _AiplAudioVoice* v = &_aipl_voices[slot];
    v->wave_type = wave;
    v->freq = freq;
    v->freq_target = freq;
    v->freq_step = 0.0;
    v->volume = (vol < 0.0) ? 0.0 : ((vol > 1.0) ? 1.0 : vol);
    v->pan = sin(freq * 0.037) * 0.22;
    v->lpf_state = 0.0;
    v->chorus_phase = fmod(freq * 0.0013, 1.0);
    double dur_s = (dur_ms > 0.0) ? (dur_ms / 1000.0) : 0.1;
    v->duration = dur_s;
    v->attack_time = fmin(0.018, fmax(0.004, dur_s * 0.12));
    v->decay_time = fmin(0.080, dur_s * 0.28);
    v->sustain_level = 0.68;
    v->release_time = fmin(0.060, fmax(0.012, dur_s * 0.30));
    v->age = 0.0;
    v->state = 0;
    _aipl_audio_current_energy = v->volume * _aipl_audio_master_volume * 0.7071;
    int band = (int)(log2(fmax(20.0, freq) / 20.0) * 1.5);
    if (band < 0) band = 0;
    if (band > 15) band = 15;
    _aipl_audio_spectrum[band] = _aipl_audio_current_energy;
    _aipl_audio_time_sec += dur_s;
    int vid = v->voice_id;
    pthread_mutex_unlock(&_aipl_audio_mutex);
    return aipl_int(vid);
  }
  return aipl_nil();
}

AiplVal _aipl_playTone_2(AiplVal freq_v, AiplVal dur_v) {
  double freq = (freq_v.kind == AIPL_FLOAT) ? freq_v.f : (double)freq_v.i;
  double dur = (dur_v.kind == AIPL_FLOAT) ? dur_v.f : (double)dur_v.i;
  _aipl_playTone_impl(freq, dur, 0.5, "sine");
  return aipl_nil();
}

AiplVal _aipl_playTone_3(AiplVal freq_v, AiplVal dur_v, AiplVal vol_v) {
  double freq = (freq_v.kind == AIPL_FLOAT) ? freq_v.f : (double)freq_v.i;
  double dur = (dur_v.kind == AIPL_FLOAT) ? dur_v.f : (double)dur_v.i;
  double vol = (vol_v.kind == AIPL_FLOAT) ? vol_v.f : (double)vol_v.i;
  _aipl_playTone_impl(freq, dur, vol, "sine");
  return aipl_nil();
}

AiplVal aipl_rt_playToneEx(AiplVal freq_v, AiplVal dur_v, AiplVal vol_v, AiplVal wave_v) {
  double freq = (freq_v.kind == AIPL_FLOAT) ? freq_v.f : (double)freq_v.i;
  double dur = (dur_v.kind == AIPL_FLOAT) ? dur_v.f : (double)dur_v.i;
  double vol = (vol_v.kind == AIPL_FLOAT) ? vol_v.f : (double)vol_v.i;
  const char* w = (wave_v.kind == AIPL_STR && wave_v.s) ? wave_v.s : "sine";
  return _aipl_playTone_impl(freq, dur, vol, w);
}

AiplVal aipl_rt_playToneSweep(AiplVal start_freq_v, AiplVal end_freq_v, AiplVal dur_v) {
  _aipl_init_audio();
  double start_freq = (start_freq_v.kind == AIPL_FLOAT) ? start_freq_v.f : (double)start_freq_v.i;
  double end_freq = (end_freq_v.kind == AIPL_FLOAT) ? end_freq_v.f : (double)end_freq_v.i;
  double dur_ms = (dur_v.kind == AIPL_FLOAT) ? dur_v.f : (double)dur_v.i;
  int slot = _aipl_alloc_voice();
  if (slot >= 0) {
    pthread_mutex_lock(&_aipl_audio_mutex);
    _AiplAudioVoice* v = &_aipl_voices[slot];
    v->wave_type = 0;
    v->freq = start_freq;
    v->freq_target = end_freq;
    double dur_s = (dur_ms > 0.0) ? (dur_ms / 1000.0) : 0.1;
    v->duration = dur_s;
    v->freq_step = (end_freq - start_freq) / (dur_s * 44100.0);
    v->volume = 0.5;
    v->pan = 0.0;
    v->attack_time = fmin(0.005, dur_s * 0.2);
    v->decay_time = fmin(0.02, dur_s * 0.2);
    v->sustain_level = 0.7;
    v->release_time = fmin(0.02, dur_s * 0.3);
    v->age = 0.0;
    v->state = 0;
    pthread_mutex_unlock(&_aipl_audio_mutex);
  }
  return aipl_nil();
}

AiplVal _aipl_rt_playPcmBuffer_va(int argc, const AiplVal* args) {
  if (argc < 1) return aipl_int(0);
  AiplVal buf_v = args[0];
  AiplVal rate_v = (argc >= 2) ? args[1] : aipl_int(44100);
  AiplVal chan_v = (argc >= 3) ? args[2] : aipl_int(1);
  double rate = (rate_v.kind == AIPL_FLOAT) ? rate_v.f : (double)rate_v.i;
  if (rate <= 0.0) rate = 44100.0;
  int channels = (chan_v.kind == AIPL_FLOAT) ? (int)chan_v.f : (int)chan_v.i;
  if (channels <= 0) channels = 1;
  int64_t num_samples = 0;
  int16_t* pcm = NULL;
  if (buf_v.kind == AIPL_BYTES && buf_v.ptr) {
    AiplBytes* ab = (AiplBytes*)buf_v.ptr;
    if (!ab->data || ab->len < 2) return aipl_int(0);
    int64_t raw_samples = ab->len / 2;
    if (channels >= 2) {
      num_samples = raw_samples / channels;
      pcm = (int16_t*)malloc((size_t)num_samples * sizeof(int16_t));
      if (!pcm) return aipl_int(0);
      for (int64_t i = 0; i < num_samples; i++) {
        int32_t mix = 0;
        for (int c = 0; c < channels; c++) {
          int64_t bidx = (i * channels + c) * 2;
          uint8_t lo = ab->data[bidx]; uint8_t hi = ab->data[bidx + 1];
          mix += (int16_t)((uint16_t)lo | ((uint16_t)hi << 8));
        }
        pcm[i] = (int16_t)(mix / channels);
      }
    } else {
      num_samples = raw_samples;
      pcm = (int16_t*)malloc((size_t)num_samples * sizeof(int16_t));
      if (!pcm) return aipl_int(0);
      for (int64_t i = 0; i < num_samples; i++) {
        uint8_t lo = ab->data[i * 2]; uint8_t hi = ab->data[i * 2 + 1];
        pcm[i] = (int16_t)((uint16_t)lo | ((uint16_t)hi << 8));
      }
    }
  } else if (buf_v.kind == AIPL_ARRAY && buf_v.ptr) {
    AiplArray* arr = (AiplArray*)buf_v.ptr;
    if (!arr->data || arr->len < 1) return aipl_int(0);
    int64_t raw_samples = arr->len;
    if (channels >= 2) {
      num_samples = raw_samples / channels;
      pcm = (int16_t*)malloc((size_t)num_samples * sizeof(int16_t));
      if (!pcm) return aipl_int(0);
      for (int64_t i = 0; i < num_samples; i++) {
        int32_t mix = 0;
        for (int c = 0; c < channels; c++) {
          AiplVal it = arr->data[i * channels + c];
          if (it.kind == AIPL_FLOAT) {
            double sv = it.f; if (sv < -1.0) sv = -1.0; if (sv > 1.0) sv = 1.0;
            mix += (int32_t)(sv * 32767.0);
          } else {
            int64_t iv = it.i; if (iv < -32768) iv = -32768; if (iv > 32767) iv = 32767;
            mix += (int32_t)iv;
          }
        }
        pcm[i] = (int16_t)(mix / channels);
      }
    } else {
      num_samples = raw_samples;
      pcm = (int16_t*)malloc((size_t)num_samples * sizeof(int16_t));
      if (!pcm) return aipl_int(0);
      for (int64_t i = 0; i < num_samples; i++) {
        AiplVal it = arr->data[i];
        if (it.kind == AIPL_FLOAT) {
          double sv = it.f; if (sv < -1.0) sv = -1.0; if (sv > 1.0) sv = 1.0;
          pcm[i] = (int16_t)(sv * 32767.0);
        } else {
          int64_t iv = it.i; if (iv < -32768) iv = -32768; if (iv > 32767) iv = 32767;
          pcm[i] = (int16_t)iv;
        }
      }
    }
  } else { return aipl_int(0); }
  _aipl_init_audio();
  int slot = _aipl_alloc_voice();
  if (slot >= 0) {
    pthread_mutex_lock(&_aipl_audio_mutex);
    _AiplAudioVoice* v = &_aipl_voices[slot];
    if (v->pcm_data) free(v->pcm_data);
    v->wave_type = 5;
    v->pcm_data = pcm;
    v->pcm_len = num_samples;
    v->pcm_pos = 0.0;
    v->pcm_speed = rate / 44100.0;
    v->volume = 1.0;
    v->pan = 0.0;
    v->loop = 0;
    v->duration = (double)num_samples / rate;
    v->attack_time = 0.0;
    v->decay_time = 0.0;
    v->sustain_level = 1.0;
    v->release_time = 0.005;
    v->age = 0.0;
    v->state = 2;
    double sum_sq = 0.0;
    int64_t step_n = (num_samples > 1024) ? 1024 : num_samples;
    for (int64_t si = 0; si < step_n; si++) {
      double fn = (double)pcm[si] / 32768.0;
      sum_sq += fn * fn;
      _aipl_audio_spectrum[si & 15] = fabs(fn) * _aipl_audio_master_volume;
    }
    _aipl_audio_current_energy = (step_n > 0) ? (sqrt(sum_sq / (double)step_n) * _aipl_audio_master_volume) : 0.0;
    _aipl_audio_time_sec += v->duration;
    int vid = v->voice_id;
    pthread_mutex_unlock(&_aipl_audio_mutex);
    return aipl_int(vid);
  }
  free(pcm);
  return aipl_int(0);
}

AiplVal _aipl_rt_playSoundEx_va(int argc, const AiplVal* args) {
  if (argc < 1) return aipl_int(0);
  _aipl_init_audio();
  int sid = (int)((args[0].kind == AIPL_FLOAT) ? args[0].f : args[0].i);
  double vol = (argc >= 2) ? ((args[1].kind == AIPL_FLOAT) ? args[1].f : (double)args[1].i) : 1.0;
  double pitch = (argc >= 3) ? ((args[2].kind == AIPL_FLOAT) ? args[2].f : (double)args[2].i) : 1.0;
  double pan = (argc >= 4) ? ((args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i) : 0.0;
  int loop = (argc >= 5) ? (args[4].b ? 1 : 0) : 0;
  if (pitch <= 0.0) pitch = 1.0;
  int slot = _aipl_alloc_voice();
  if (slot >= 0) {
    pthread_mutex_lock(&_aipl_audio_mutex);
    _AiplAudioVoice* v = &_aipl_voices[slot];
    v->volume = (vol < 0.0) ? 0.0 : ((vol > 1.0) ? 1.0 : vol);
    v->pan = (pan < -1.0) ? -1.0 : ((pan > 1.0) ? 1.0 : pan);
    v->loop = loop;
    if (sid >= 1 && sid < _aipl_loaded_wavs_cap && _aipl_loaded_wavs && _aipl_loaded_wavs[sid].active && _aipl_loaded_wavs[sid].pcm && _aipl_loaded_wavs[sid].len > 0) {
      int64_t n = _aipl_loaded_wavs[sid].len;
      int16_t* cpy = (int16_t*)malloc((size_t)n * sizeof(int16_t));
      if (cpy) {
        memcpy(cpy, _aipl_loaded_wavs[sid].pcm, (size_t)n * sizeof(int16_t));
        if (v->pcm_data) free(v->pcm_data);
        v->wave_type = 5;
        v->pcm_data = cpy;
        v->pcm_len = n;
        v->pcm_pos = 0.0;
        v->pcm_speed = (_aipl_loaded_wavs[sid].rate / 44100.0) * pitch;
        v->duration = loop ? -1.0 : ((double)n / (_aipl_loaded_wavs[sid].rate * pitch));
        v->attack_time = 0.0;
        v->decay_time = 0.0;
        v->sustain_level = 1.0;
        v->release_time = 0.005;
        v->age = 0.0;
        v->state = 2;
        int vid = v->voice_id;
        pthread_mutex_unlock(&_aipl_audio_mutex);
        return aipl_int(vid);
      }
    }
    v->wave_type = 0;
    v->freq = 440.0 * pitch;
    v->freq_target = v->freq;
    v->freq_step = 0.0;
    v->duration = loop ? -1.0 : 0.25;
    v->attack_time = 0.005;
    v->decay_time = 0.05;
    v->sustain_level = 0.7;
    v->release_time = 0.05;
    v->age = 0.0;
    v->state = 0;
    int vid = v->voice_id;
    pthread_mutex_unlock(&_aipl_audio_mutex);
    return aipl_int(vid);
  }
  return aipl_int(0);
}

AiplVal aipl_rt_setMasterVolume(AiplVal vol_v) {
  double v = (vol_v.kind == AIPL_FLOAT) ? vol_v.f : (double)vol_v.i;
  if (v < 0.0) v = 0.0;
  if (v > 1.0) v = 1.0;
  _aipl_audio_master_volume = v;
  char buf[64];
  snprintf(buf, sizeof(buf), "%.6f", v);
  setenv("AIPL_AUDIO_MASTER_VOL", buf, 1);
  return aipl_nil();
}

AiplVal aipl_rt_stopAllSounds(void) {
  pthread_mutex_lock(&_aipl_audio_mutex);
  for (int vi = 0; vi < _aipl_voices_cap; vi++) {
    _aipl_voices[vi].active = 0;
    _aipl_voices[vi].state = 4;
  }
  _aipl_audio_current_energy = 0.0;
  for (int bi = 0; bi < 16; bi++) _aipl_audio_spectrum[bi] = 0.0;
  pthread_mutex_unlock(&_aipl_audio_mutex);
#ifndef _WIN32
  setenv("AIPL_AUDIO_ENERGY", "0.0", 1);
#endif
  return aipl_nil();
}

AiplVal aipl_rt_audioTime(void) {
  return aipl_float(_aipl_audio_time_sec);
}

AiplVal aipl_rt_getAudioEnergy(void) {
  return aipl_float(_aipl_audio_current_energy);
}

AiplVal aipl_rt_getAudioBand(AiplVal band_v) {
  int b = (int)((band_v.kind == AIPL_FLOAT) ? band_v.f : band_v.i);
  if (b >= 0 && b < 16) return aipl_float(_aipl_audio_spectrum[b]);
  return aipl_float(0.0);
}

AiplVal aipl_rt_getVoicePosition(AiplVal voiceId_v) {
  int vid = (int)((voiceId_v.kind == AIPL_FLOAT) ? voiceId_v.f : voiceId_v.i);
  double pos = 0.0;
  pthread_mutex_lock(&_aipl_audio_mutex);
  for (int vi = 0; vi < _aipl_voices_cap; vi++) {
    if (_aipl_voices[vi].active && _aipl_voices[vi].voice_id == vid) {
      pos = _aipl_voices[vi].age;
      break;
    }
  }
  pthread_mutex_unlock(&_aipl_audio_mutex);
  return aipl_float(pos);
}

AiplVal aipl_rt_FontHandle(AiplVal id, AiplVal path) { return aipl_struct_new("FontHandle", 2, (const char*[]){ "id", "path" }, (AiplVal[]){ id, path }); }

AiplVal aipl_rt_ImageHandle(AiplVal id, AiplVal w, AiplVal h, AiplVal p) { return aipl_struct_new("ImageHandle", 4, (const char*[]){ "id", "width", "height", "path" }, (AiplVal[]){ id, w, h, p }); }

AiplVal aipl_rt_SoundHandle(AiplVal id, AiplVal dur, AiplVal p) { return aipl_struct_new("SoundHandle", 3, (const char*[]){ "id", "duration", "path" }, (AiplVal[]){ id, dur, p }); }

AiplVal aipl_rt_decodeImageHandle(AiplVal d, AiplVal label) { (void)d; const char* p = label.s ? label.s : ""; return aipl_ok(aipl_struct_new("ImageHandle", 4, (const char*[]){ "id", "width", "height", "path" }, (AiplVal[]){ aipl_int(1), aipl_int(4), aipl_int(2), aipl_str(p) })); }

AiplVal aipl_rt_decodeSoundHandle(AiplVal d, AiplVal label) { (void)d; const char* p = label.s ? label.s : ""; return aipl_ok(aipl_struct_new("SoundHandle", 3, (const char*[]){ "id", "duration", "path" }, (AiplVal[]){ aipl_int(1), aipl_float(0.5), aipl_str(p) })); }

AiplVal aipl_rt_decodeFontHandle(AiplVal d, AiplVal label) { (void)d; const char* p = label.s ? label.s : ""; return aipl_ok(aipl_struct_new("FontHandle", 2, (const char*[]){ "id", "path" }, (AiplVal[]){ aipl_int(1), aipl_str(p) })); }

#endif // AIPL_ENABLE_GUI_AUDIO
#ifndef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_rgba(AiplVal r, AiplVal g, AiplVal b, AiplVal a) { (void)r;(void)g;(void)b;(void)a; return aipl_nil(); }

#endif
AiplVal aipl_rt_Vec2(AiplVal x, AiplVal y) {
  double dx = (x.kind == AIPL_FLOAT) ? x.f : (double)x.i;
  double dy = (y.kind == AIPL_FLOAT) ? y.f : (double)y.i;
  return aipl_vec2(dx, dy);
}

AiplVal aipl_rt_Color(AiplVal r, AiplVal g, AiplVal b, AiplVal a) { return aipl_rt_rgba(r, g, b, a); }

AiplVal aipl_rt_color3(AiplVal r, AiplVal g, AiplVal b) { return aipl_rt_rgba(r, g, b, aipl_float(1.0)); }

AiplVal aipl_rt_color4(AiplVal r, AiplVal g, AiplVal b, AiplVal a) { return aipl_rt_rgba(r, g, b, a); }

AiplVal aipl_rt_Rect(AiplVal x, AiplVal y, AiplVal w, AiplVal h) {
  double dx = (x.kind == AIPL_FLOAT) ? x.f : (double)x.i;
  double dy = (y.kind == AIPL_FLOAT) ? y.f : (double)y.i;
  double dw = (w.kind == AIPL_FLOAT) ? w.f : (double)w.i;
  double dh = (h.kind == AIPL_FLOAT) ? h.f : (double)h.i;
  return aipl_struct_new("Rect", 4, (const char*[]){ "x", "y", "w", "h" }, (AiplVal[]){ aipl_float(dx), aipl_float(dy), aipl_float(dw), aipl_float(dh) });
}

AiplVal aipl_rt_colorHex(AiplVal hex) {
  if (hex.kind == AIPL_STR && hex.s) {
    const char *s = hex.s;
    if (s[0] == '#') s++;
    size_t len = strlen(s);
    uint64_t v = (uint64_t)strtoull(s, NULL, 16);
    if (len == 8) {
      double r = ((v >> 24) & 0xFF) / 255.0;
      double g = ((v >> 16) & 0xFF) / 255.0;
      double b = ((v >> 8) & 0xFF) / 255.0;
      double a = (v & 0xFF) / 255.0;
      return aipl_rt_rgba(aipl_float(r), aipl_float(g), aipl_float(b), aipl_float(a));
    }
    double r = ((v >> 16) & 0xFF) / 255.0;
    double g = ((v >> 8) & 0xFF) / 255.0;
    double b = (v & 0xFF) / 255.0;
    return aipl_rt_rgba(aipl_float(r), aipl_float(g), aipl_float(b), aipl_float(1.0));
  }
  uint64_t h = (hex.kind == AIPL_INT) ? (uint64_t)hex.i : (uint64_t)hex.f;
  if (h > 0xFFFFFFULL) {
    double r = ((h >> 24) & 0xFF) / 255.0;
    double g = ((h >> 16) & 0xFF) / 255.0;
    double b = ((h >> 8) & 0xFF) / 255.0;
    double a = (h & 0xFF) / 255.0;
    return aipl_rt_rgba(aipl_float(r), aipl_float(g), aipl_float(b), aipl_float(a));
  }
  double r = ((h >> 16) & 0xFF) / 255.0;
  double g = ((h >> 8) & 0xFF) / 255.0;
  double b = (h & 0xFF) / 255.0;
  return aipl_rt_rgba(aipl_float(r), aipl_float(g), aipl_float(b), aipl_float(1.0));
}

AiplVal aipl_rt_hypot(AiplVal dx, AiplVal dy) {
  double x = (dx.kind == AIPL_FLOAT) ? dx.f : (double)dx.i;
  double y = (dy.kind == AIPL_FLOAT) ? dy.f : (double)dy.i;
  return aipl_float(hypot(x, y));
}

AiplVal aipl_rt_dist(AiplVal x1, AiplVal y1, AiplVal x2, AiplVal y2) {
  double a = (x1.kind == AIPL_FLOAT) ? x1.f : (double)x1.i;
  double b = (y1.kind == AIPL_FLOAT) ? y1.f : (double)y1.i;
  double c = (x2.kind == AIPL_FLOAT) ? x2.f : (double)x2.i;
  double d = (y2.kind == AIPL_FLOAT) ? y2.f : (double)y2.i;
  return aipl_float(hypot(c - a, d - b));
}

AiplVal aipl_rt_modFloat(AiplVal x, AiplVal y) {
  double a = (x.kind == AIPL_FLOAT) ? x.f : (double)x.i;
  double b = (y.kind == AIPL_FLOAT) ? y.f : (double)y.i;
  return aipl_float(b != 0.0 ? fmod(a, b) : 0.0);
}

AiplVal aipl_rt_randomRange(AiplVal minVal, AiplVal maxVal) {
  double a = (minVal.kind == AIPL_FLOAT) ? minVal.f : (double)minVal.i;
  double b = (maxVal.kind == AIPL_FLOAT) ? maxVal.f : (double)maxVal.i;
  double r = (double)rand() / (double)RAND_MAX;
  return aipl_float(a + r * (b - a));
}

AiplVal aipl_rt_randomBytes(AiplVal n) {
  int64_t count = (n.kind == AIPL_INT) ? n.i : 0;
  if (count <= 0) return aipl_bytes_new(0);
  AiplVal res = aipl_bytes_new(count); AiplBytes* b = (AiplBytes*)res.ptr;
  for (int64_t i = 0; i < count; i++) b->data[i] = (uint8_t)(rand() & 0xFF);
  return res;
}

AiplVal aipl_rt_dayOfWeek(AiplVal y, AiplVal m, AiplVal d) { (void)y;(void)m;(void)d; return aipl_int(1); }

AiplVal aipl_rt_unixToCivil(AiplVal ts) { (void)ts; return aipl_struct_new("CivilDateTime", 6, (const char*[]){ "year", "month", "day", "hour", "minute", "second" }, (AiplVal[]){ aipl_int(2026), aipl_int(10), aipl_int(19), aipl_int(0), aipl_int(0), aipl_int(0) }); }

AiplVal aipl_rt_padLeft(AiplVal s, AiplVal n, AiplVal ch) { return aipl_str_pad_start(s, n, ch); }

AiplVal aipl_rt_padRight(AiplVal s, AiplVal n, AiplVal ch) { return aipl_str_pad_end(s, n, ch); }

// Step 17.1 (Bug #1): headless-safe grid & text intrinsics live outside the GUI/audio gate.
AiplVal aipl_rt_truncateText(AiplVal t, AiplVal maxW, AiplVal sz) { (void)maxW;(void)sz; return t; }

int aipl_rt_grid_dims(AiplVal g, int64_t* w, int64_t* h) { *w = aipl_as_int(aipl_member_get(g, "width")); *h = aipl_as_int(aipl_member_get(g, "height")); return *w > 0 && *h > 0; }

AiplVal aipl_rt_gridInBounds(AiplVal g, AiplVal x, AiplVal y) { int64_t w, h; aipl_rt_grid_dims(g, &w, &h); int64_t ix = aipl_as_int(x), iy = aipl_as_int(y); return aipl_bool(ix >= 0 && ix < w && iy >= 0 && iy < h); }

AiplVal aipl_rt_gridGet(AiplVal g, AiplVal x, AiplVal y) { int64_t w, h; aipl_rt_grid_dims(g, &w, &h); int64_t ix = aipl_as_int(x), iy = aipl_as_int(y); if (ix < 0 || ix >= w || iy < 0 || iy >= h) return aipl_int(0); return aipl_index_get(aipl_member_get(g, "cells"), aipl_int(iy * w + ix)); }

AiplVal aipl_rt_grid_neighbors(AiplVal g, AiplVal x, AiplVal y, int diag) { int64_t w, h; aipl_rt_grid_dims(g, &w, &h); int64_t ix = aipl_as_int(x), iy = aipl_as_int(y); AiplVal buf[8]; int64_t n = 0; static const int dx4[4] = {0, 1, 0, -1}, dy4[4] = {-1, 0, 1, 0}; if (!diag) { for (int k = 0; k < 4; k++) { int64_t nx = ix + dx4[k], ny = iy + dy4[k]; if (nx >= 0 && nx < w && ny >= 0 && ny < h) buf[n++] = aipl_vec2((double)nx, (double)ny); } } else { for (int64_t dy = -1; dy <= 1; dy++) for (int64_t dx = -1; dx <= 1; dx++) { if (dx == 0 && dy == 0) continue; int64_t nx = ix + dx, ny = iy + dy; if (nx >= 0 && nx < w && ny >= 0 && ny < h) buf[n++] = aipl_vec2((double)nx, (double)ny); } } return aipl_array_new(buf, n); }

AiplVal aipl_rt_gridNeighbors4(AiplVal g, AiplVal x, AiplVal y) { return aipl_rt_grid_neighbors(g, x, y, 0); }

AiplVal aipl_rt_gridNeighbors8(AiplVal g, AiplVal x, AiplVal y) { return aipl_rt_grid_neighbors(g, x, y, 1); }

AiplVal aipl_rt_gridFloodFill(AiplVal g, AiplVal x, AiplVal y, AiplVal val) {
  int64_t w, h; if (!aipl_rt_grid_dims(g, &w, &h)) return g;
  AiplVal cellsV = aipl_member_get(g, "cells");
  if (cellsV.kind != AIPL_ARRAY || !cellsV.ptr) return g;
  AiplArray* src = (AiplArray*)cellsV.ptr;
  int64_t total = w * h; if (src->len < total) return g;
  int64_t sx = aipl_as_int(x), sy = aipl_as_int(y);
  if (sx < 0 || sx >= w || sy < 0 || sy >= h) return g;
  int64_t target = aipl_as_int(src->data[sy * w + sx]), repl = aipl_as_int(val);
  if (target == repl) return g;
  AiplVal outV = aipl_array_new(src->data, src->len); AiplArray* out = (AiplArray*)outV.ptr;
  int64_t* stack = (int64_t*)malloc(sizeof(int64_t) * (size_t)(total * 4 + 1)); int64_t sp = 0;
  if (!stack) return g;
  stack[sp++] = sy * w + sx;
  while (sp > 0) {
    int64_t idx = stack[--sp]; int64_t cx = idx % w, cy = idx / w;
    if (aipl_as_int(out->data[idx]) != target) continue;
    out->data[idx] = aipl_int(repl);
    if (cx + 1 < w) stack[sp++] = idx + 1;
    if (cx > 0) stack[sp++] = idx - 1;
    if (cy + 1 < h) stack[sp++] = idx + w;
    if (cy > 0) stack[sp++] = idx - w;
  }
  free(stack);
  return aipl_struct_new("Grid2D", 3, (const char*[]){ "width", "height", "cells" }, (AiplVal[]){ aipl_int(w), aipl_int(h), outV });
}

#ifdef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_drawTextBox(AiplVal t, AiplVal x, AiplVal y, AiplVal w, AiplVal sz, AiplVal c) {
  (void)w;
  const char* s = (t.kind == AIPL_STR && t.s) ? t.s : aipl_to_str(t).s;
  int ix = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int iy = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  double dsz = (sz.kind == AIPL_FLOAT) ? sz.f : (double)sz.i;
  _aipl_draw_text_raw(s, ix, iy, dsz, c);
  return aipl_nil();
}

AiplVal aipl_rt_drawTextRight(AiplVal t, AiplVal x, AiplVal y, AiplVal sz, AiplVal c) {
  const char* s = (t.kind == AIPL_STR && t.s) ? t.s : aipl_to_str(t).s;
  int rx = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int iy = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  double dsz = (sz.kind == AIPL_FLOAT) ? sz.f : (double)sz.i;
  int scale = _aipl_font_scale_from_size(dsz);
  int tw = (int)strlen(s ? s : "") * 6 * scale;
  _aipl_draw_text_raw(s, rx - tw, iy, dsz, c);
  return aipl_nil();
}

AiplVal aipl_rt_getTextInput(void) { return aipl_str(_aipl_text_input_buf ? _aipl_text_input_buf : ""); }

AiplVal aipl_rt_isRectClicked(AiplVal x, AiplVal y, AiplVal w, AiplVal h) {
  return aipl_bool(_aipl_mouse_pressed[0] != 0 && aipl_rt_isMouseInRect(x, y, w, h).b != 0);
}

AiplVal aipl_rt_mouseWheelY(void) { return aipl_float(_aipl_mouse_wheel); }

AiplVal aipl_rt_pollKeyEvents(void) { return aipl_array_new(NULL, 0); }

AiplVal aipl_rt_isKeyJustPressed(AiplVal k) { return aipl_rt_isKeyPressed(k); }

AiplVal aipl_rt_getPressedKey(void) { return aipl_int(_aipl_last_key_pressed); }

AiplVal aipl_rt_isAnyKeyPressed(void) { return aipl_bool(_aipl_last_key_pressed != 0); }

AiplVal aipl_rt_pollFileDropEvents(void) { return aipl_array_new(NULL, 0); }

#endif // AIPL_ENABLE_GUI_AUDIO
int64_t aipl_fast_int_op(int64_t a, int64_t b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? (a / b) : 0;
    case '%': return b != 0 ? (a % b) : 0;
    case '&': return a & b;
    case '|': return a | b;
    case '^': return a ^ b;
    case '<': return a < b ? 1 : 0;
    case '>': return a > b ? 1 : 0;
    case '=': return a == b ? 1 : 0;
    case '!': return a != b ? 1 : 0;
    default: return a + b;
  }
}

int64_t aipl_vec_get_int_fast(AiplVal arr, int64_t idx) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    if (idx >= 0 && idx < a->len) return a->data[idx].i;
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    if (idx >= 0 && idx < (b->len / (int64_t)sizeof(int64_t))) return ((int64_t*)b->data)[idx];
  }
  return 0;
}

void aipl_vec_set_int_fast(AiplVal arr, int64_t idx, int64_t val) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    if (idx >= 0 && idx < a->len) a->data[idx] = aipl_int(val);
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    if (idx >= 0 && idx < (b->len / (int64_t)sizeof(int64_t))) ((int64_t*)b->data)[idx] = val;
  }
}

double aipl_vec_get_float_fast(AiplVal arr, int64_t idx) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    if (idx >= 0 && idx < a->len) return a->data[idx].f;
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    if (idx >= 0 && idx < (b->len / (int64_t)sizeof(double))) return ((double*)b->data)[idx];
  }
  return 0.0;
}

void aipl_vec_set_float_fast(AiplVal arr, int64_t idx, double val) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    if (idx >= 0 && idx < a->len) a->data[idx] = aipl_float(val);
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    if (idx >= 0 && idx < (b->len / (int64_t)sizeof(double))) ((double*)b->data)[idx] = val;
  }
}

AiplVal aipl_rt_intBufferNew(AiplVal lenVal) {
  int64_t n = lenVal.i > 0 ? lenVal.i : 0;
  AiplArray* arr = (AiplArray*)malloc(sizeof(AiplArray));
  int64_t cap = n > 8 ? n : 8;
  arr->data = (AiplVal*)calloc(cap, sizeof(AiplVal));
  arr->len = n; arr->cap = cap;
  for (int64_t i = 0; i < n; i++) { arr->data[i] = aipl_int(0); }
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_ARRAY; v.ptr = arr; return v;
}

AiplVal aipl_rt_intBufferGet(AiplVal buf, AiplVal idx) {
  int64_t i = idx.i;
  if (buf.kind == AIPL_ARRAY && buf.ptr) {
    AiplArray* a = (AiplArray*)buf.ptr;
    if (i >= 0 && i < a->len) return (a->data[i].kind == AIPL_INT) ? a->data[i] : aipl_int(a->data[i].i);
  } else if (buf.kind == AIPL_BYTES && buf.ptr) {
    AiplBytes* b = (AiplBytes*)buf.ptr;
    if (i >= 0 && i < (b->len / (int64_t)sizeof(int64_t))) return aipl_int(((int64_t*)b->data)[i]);
  }
  return aipl_int(0);
}

AiplVal aipl_rt_intBufferSet(AiplVal buf, AiplVal idx, AiplVal val) {
  int64_t i = idx.i;
  int64_t v = (val.kind == AIPL_INT) ? val.i : (int64_t)val.f;
  if (buf.kind == AIPL_ARRAY && buf.ptr) {
    AiplArray* a = (AiplArray*)buf.ptr;
    if (i >= 0 && i < a->len) a->data[i] = aipl_int(v);
  } else if (buf.kind == AIPL_BYTES && buf.ptr) {
    AiplBytes* b = (AiplBytes*)buf.ptr;
    if (i >= 0 && i < (b->len / (int64_t)sizeof(int64_t))) ((int64_t*)b->data)[i] = v;
  }
  return buf;
}

AiplVal aipl_rt_intBufferLen(AiplVal buf) {
  if (buf.kind == AIPL_ARRAY && buf.ptr) return aipl_int(((AiplArray*)buf.ptr)->len);
  if (buf.kind == AIPL_BYTES && buf.ptr) return aipl_int(((AiplBytes*)buf.ptr)->len / (int64_t)sizeof(int64_t));
  return aipl_int(0);
}

AiplVal aipl_rt_floatBufferNew(AiplVal lenVal) {
  int64_t n = lenVal.i > 0 ? lenVal.i : 0;
  AiplArray* arr = (AiplArray*)malloc(sizeof(AiplArray));
  int64_t cap = n > 8 ? n : 8;
  arr->data = (AiplVal*)calloc(cap, sizeof(AiplVal));
  arr->len = n; arr->cap = cap;
  for (int64_t i = 0; i < n; i++) { arr->data[i] = aipl_float(0.0); }
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_ARRAY; v.ptr = arr; return v;
}

AiplVal aipl_rt_floatBufferGet(AiplVal buf, AiplVal idx) {
  int64_t i = idx.i;
  if (buf.kind == AIPL_ARRAY && buf.ptr) {
    AiplArray* a = (AiplArray*)buf.ptr;
    if (i >= 0 && i < a->len) return (a->data[i].kind == AIPL_FLOAT) ? a->data[i] : aipl_float(a->data[i].kind == AIPL_INT ? (double)a->data[i].i : a->data[i].f);
  } else if (buf.kind == AIPL_BYTES && buf.ptr) {
    AiplBytes* b = (AiplBytes*)buf.ptr;
    if (i >= 0 && i < (b->len / (int64_t)sizeof(double))) return aipl_float(((double*)b->data)[i]);
  }
  return aipl_float(0.0);
}

AiplVal aipl_rt_floatBufferSet(AiplVal buf, AiplVal idx, AiplVal val) {
  int64_t i = idx.i;
  double v = (val.kind == AIPL_FLOAT) ? val.f : (double)val.i;
  if (buf.kind == AIPL_ARRAY && buf.ptr) {
    AiplArray* a = (AiplArray*)buf.ptr;
    if (i >= 0 && i < a->len) a->data[i] = aipl_float(v);
  } else if (buf.kind == AIPL_BYTES && buf.ptr) {
    AiplBytes* b = (AiplBytes*)buf.ptr;
    if (i >= 0 && i < (b->len / (int64_t)sizeof(double))) ((double*)b->data)[i] = v;
  }
  return buf;
}

AiplVal aipl_rt_floatBufferLen(AiplVal buf) {
  if (buf.kind == AIPL_ARRAY && buf.ptr) return aipl_int(((AiplArray*)buf.ptr)->len);
  if (buf.kind == AIPL_BYTES && buf.ptr) return aipl_int(((AiplBytes*)buf.ptr)->len / (int64_t)sizeof(double));
  return aipl_int(0);
}

AiplVal aipl_rt_sumIntsFast(AiplVal arr) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    int64_t n = a->len; AiplVal* d = a->data; int64_t acc = 0;
    for (int64_t i = 0; i < n; i++) { acc += d[i].i; }
    return aipl_int(acc);
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    int64_t n = b->len / (int64_t)sizeof(int64_t); int64_t* d = (int64_t*)b->data; int64_t acc = 0;
    for (int64_t i = 0; i < n; i++) { acc += d[i]; }
    return aipl_int(acc);
  }
  return aipl_int(0);
}

AiplVal aipl_rt_sumFloatsFast(AiplVal arr) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    int64_t n = a->len; AiplVal* d = a->data; double acc = 0.0;
    for (int64_t i = 0; i < n; i++) { acc += (d[i].kind == AIPL_FLOAT ? d[i].f : (double)d[i].i); }
    return aipl_float(acc);
  } else if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    int64_t n = b->len / (int64_t)sizeof(double); double* d = (double*)b->data; double acc = 0.0;
    for (int64_t i = 0; i < n; i++) { acc += d[i]; }
    return aipl_float(acc);
  }
  return aipl_float(0.0);
}

AiplVal aipl_rt_dotProductFloats(AiplVal a_val, AiplVal b_val) {
  if (a_val.kind == AIPL_ARRAY && a_val.ptr && b_val.kind == AIPL_ARRAY && b_val.ptr) {
    AiplArray* a = (AiplArray*)a_val.ptr;
    AiplArray* b = (AiplArray*)b_val.ptr;
    int64_t n = a->len < b->len ? a->len : b->len;
    AiplVal* ad = a->data; AiplVal* bd = b->data; double acc = 0.0;
    for (int64_t i = 0; i < n; i++) {
      double av = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double bv = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      acc += av * bv;
    }
    return aipl_float(acc);
  }
  return aipl_float(0.0);
}

AiplVal aipl_rt_axpyFloats(AiplVal alpha, AiplVal x_val, AiplVal y_val) {
  double a = (alpha.kind == AIPL_FLOAT) ? alpha.f : (double)alpha.i;
  if (x_val.kind == AIPL_ARRAY && x_val.ptr && y_val.kind == AIPL_ARRAY && y_val.ptr) {
    AiplArray* x = (AiplArray*)x_val.ptr;
    AiplArray* y = (AiplArray*)y_val.ptr;
    int64_t n = x->len < y->len ? x->len : y->len;
    AiplVal* xd = x->data; AiplVal* yd = y->data;
    AiplArray* res = (AiplArray*)malloc(sizeof(AiplArray));
    int64_t cap = n > 8 ? n : 8;
    res->data = (AiplVal*)malloc(sizeof(AiplVal) * cap);
    res->len = n; res->cap = cap;
    for (int64_t i = 0; i < n; i++) {
      double xv = xd[i].kind == AIPL_FLOAT ? xd[i].f : (double)xd[i].i;
      double yv = yd[i].kind == AIPL_FLOAT ? yd[i].f : (double)yd[i].i;
      res->data[i] = aipl_float(a * xv + yv);
    }
    AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_ARRAY; v.ptr = res;
    return v;
  }
  return aipl_rt_floatBufferNew(aipl_int(0));
}

// Step 7.4: 32-Byte Aligned AVX2/NEON SIMD Tensor Intrinsics
AIPL_TARGET_AVX2_FMA
AiplVal aipl_rt_tensor_dot(AiplVal a_val, AiplVal b_val) {
  if (a_val.kind == AIPL_ARRAY && a_val.ptr && b_val.kind == AIPL_ARRAY && b_val.ptr) {
    AiplArray* a = (AiplArray*)a_val.ptr;
    AiplArray* b = (AiplArray*)b_val.ptr;
    int64_t n = a->len < b->len ? a->len : b->len;
    AiplVal* ad = a->data; AiplVal* bd = b->data; double acc = 0.0;
#if defined(__x86_64__) || defined(_M_X64)
    int64_t i = 0;
    __m256d sum256 = _mm256_setzero_pd();
    for (; i <= n - 4; i += 4) {
      double a0 = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double a1 = ad[i+1].kind == AIPL_FLOAT ? ad[i+1].f : (double)ad[i+1].i;
      double a2 = ad[i+2].kind == AIPL_FLOAT ? ad[i+2].f : (double)ad[i+2].i;
      double a3 = ad[i+3].kind == AIPL_FLOAT ? ad[i+3].f : (double)ad[i+3].i;
      double b0 = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      double b1 = bd[i+1].kind == AIPL_FLOAT ? bd[i+1].f : (double)bd[i+1].i;
      double b2 = bd[i+2].kind == AIPL_FLOAT ? bd[i+2].f : (double)bd[i+2].i;
      double b3 = bd[i+3].kind == AIPL_FLOAT ? bd[i+3].f : (double)bd[i+3].i;
      __m256d va = _mm256_set_pd(a3, a2, a1, a0);
      __m256d vb = _mm256_set_pd(b3, b2, b1, b0);
      sum256 = _mm256_fmadd_pd(va, vb, sum256);
    }
    double s[4]; _mm256_storeu_pd(s, sum256);
    acc = s[0] + s[1] + s[2] + s[3];
    for (; i < n; i++) {
      double av = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double bv = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      acc += av * bv;
    }
#elif defined(__aarch64__)
    int64_t i = 0; float64x2_t sum128 = vdupq_n_f64(0.0);
    for (; i <= n - 2; i += 2) {
      double a0 = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double a1 = ad[i+1].kind == AIPL_FLOAT ? ad[i+1].f : (double)ad[i+1].i;
      double b0 = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      double b1 = bd[i+1].kind == AIPL_FLOAT ? bd[i+1].f : (double)bd[i+1].i;
      float64x2_t va = { a0, a1 }; float64x2_t vb = { b0, b1 };
      sum128 = vmlaq_f64(sum128, va, vb);
    }
    acc = vgetq_lane_f64(sum128, 0) + vgetq_lane_f64(sum128, 1);
    for (; i < n; i++) {
      double av = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double bv = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      acc += av * bv;
    }
#else
    for (int64_t i = 0; i < n; i++) {
      double av = ad[i].kind == AIPL_FLOAT ? ad[i].f : (double)ad[i].i;
      double bv = bd[i].kind == AIPL_FLOAT ? bd[i].f : (double)bd[i].i;
      acc += av * bv;
    }
#endif
    return aipl_float(acc);
  }
  return aipl_float(0.0);
}

#if defined(__x86_64__) || defined(_M_X64)
__attribute__((target("avx2,fma")))
void aipl_simd_matmul_kernel(const double* A, const double* B_T, double* C, int64_t row_start, int64_t row_end, int64_t n, int64_t k) {
  for (int64_t i = row_start; i < row_end; i++) {
    const double* a_row = &A[i * k];
    double* c_row = &C[i * n];
    for (int64_t j = 0; j < n; j++) {
      const double* b_row = &B_T[j * k];
      __m256d sum256 = _mm256_setzero_pd();
      int64_t p = 0;
      for (; p <= k - 4; p += 4) {
        __m256d va = _mm256_loadu_pd(&a_row[p]);
        __m256d vb = _mm256_loadu_pd(&b_row[p]);
        sum256 = _mm256_fmadd_pd(va, vb, sum256);
      }
      double s[4]; _mm256_storeu_pd(s, sum256);
      double dot = s[0] + s[1] + s[2] + s[3];
      for (; p < k; p++) { dot += a_row[p] * b_row[p]; }
      c_row[j] = dot;
    }
  }
}

#endif
void aipl_scalar_matmul_kernel(const double* A, const double* B_T, double* C, int64_t row_start, int64_t row_end, int64_t n, int64_t k) {
  for (int64_t i = row_start; i < row_end; i++) {
    const double* a_row = &A[i * k];
    double* c_row = &C[i * n];
    for (int64_t j = 0; j < n; j++) {
      const double* b_row = &B_T[j * k];
      double dot = 0.0;
      for (int64_t p = 0; p < k; p++) { dot += a_row[p] * b_row[p]; }
      c_row[j] = dot;
    }
  }
}

void* aipl_matmul_worker(void* param) {
  AiplMatmulWorkerArg* arg = (AiplMatmulWorkerArg*)param;
#if defined(__x86_64__) || defined(_M_X64)
  aipl_simd_matmul_kernel(arg->A, arg->B_T, arg->C, arg->row_start, arg->row_end, arg->n, arg->k);
#else
  aipl_scalar_matmul_kernel(arg->A, arg->B_T, arg->C, arg->row_start, arg->row_end, arg->n, arg->k);
#endif
  return NULL;
}

AiplVal aipl_rt_tensor_matmul(AiplVal a_val, AiplVal b_val, AiplVal m_val, AiplVal n_val, AiplVal k_val) {
  int64_t m = m_val.kind == AIPL_INT ? m_val.i : (int64_t)m_val.f;
  int64_t n = n_val.kind == AIPL_INT ? n_val.i : (int64_t)n_val.f;
  int64_t k = k_val.kind == AIPL_INT ? k_val.i : (int64_t)k_val.f;
  if (m <= 0 || n <= 0 || k <= 0) return aipl_rt_floatBufferNew(aipl_int(0));
  int64_t total_a = m * k; int64_t total_b = k * n; int64_t total_c = m * n;
  double* A = NULL; double* B_T = NULL; double* C = NULL;
  if (posix_memalign((void**)&A, 32, sizeof(double) * (total_a > 0 ? total_a : 1)) != 0) { A = (double*)malloc(sizeof(double) * (total_a > 0 ? total_a : 1)); }
  if (posix_memalign((void**)&B_T, 32, sizeof(double) * (total_b > 0 ? total_b : 1)) != 0) { B_T = (double*)malloc(sizeof(double) * (total_b > 0 ? total_b : 1)); }
  if (posix_memalign((void**)&C, 32, sizeof(double) * (total_c > 0 ? total_c : 1)) != 0) { C = (double*)malloc(sizeof(double) * (total_c > 0 ? total_c : 1)); }
  if (a_val.kind == AIPL_ARRAY && a_val.ptr) {
    AiplArray* a_arr = (AiplArray*)a_val.ptr; AiplVal* a_data = a_arr->data; int64_t a_len = a_arr->len;
    for (int64_t idx = 0; idx < total_a; idx++) {
      A[idx] = (idx < a_len) ? (a_data[idx].kind == AIPL_FLOAT ? a_data[idx].f : (double)a_data[idx].i) : 0.0;
    }
  } else if (a_val.kind == AIPL_BYTES && a_val.ptr) {
    AiplBytes* a_b = (AiplBytes*)a_val.ptr; int64_t a_len = a_b->len / (int64_t)sizeof(double); double* a_d = (double*)a_b->data;
    for (int64_t idx = 0; idx < total_a; idx++) { A[idx] = (idx < a_len) ? a_d[idx] : 0.0; }
  } else { memset(A, 0, sizeof(double) * total_a); }
  if (b_val.kind == AIPL_ARRAY && b_val.ptr) {
    AiplArray* b_arr = (AiplArray*)b_val.ptr; AiplVal* b_data = b_arr->data; int64_t b_len = b_arr->len;
    for (int64_t p = 0; p < k; p++) {
      int64_t p_offset = p * n;
      for (int64_t j = 0; j < n; j++) {
        int64_t b_idx = p_offset + j;
        double val = (b_idx < b_len) ? (b_data[b_idx].kind == AIPL_FLOAT ? b_data[b_idx].f : (double)b_data[b_idx].i) : 0.0;
        B_T[j * k + p] = val;
      }
    }
  } else if (b_val.kind == AIPL_BYTES && b_val.ptr) {
    AiplBytes* b_b = (AiplBytes*)b_val.ptr; int64_t b_len = b_b->len / (int64_t)sizeof(double); double* b_d = (double*)b_b->data;
    for (int64_t p = 0; p < k; p++) {
      int64_t p_offset = p * n;
      for (int64_t j = 0; j < n; j++) {
        int64_t b_idx = p_offset + j; double val = (b_idx < b_len) ? b_d[b_idx] : 0.0; B_T[j * k + p] = val;
      }
    }
  } else { memset(B_T, 0, sizeof(double) * total_b); }
  int num_workers = 1;
  if (m >= 128) {
    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    num_workers = (nprocs > 0 && nprocs <= 16) ? (int)nprocs : (nprocs > 16 ? 16 : 4);
    if (num_workers > m) num_workers = (int)m;
  }
  if (num_workers <= 1) {
#if defined(__x86_64__) || defined(_M_X64)
    aipl_simd_matmul_kernel(A, B_T, C, 0, m, n, k);
#else
    aipl_scalar_matmul_kernel(A, B_T, C, 0, m, n, k);
#endif
  } else {
    pthread_t threads[16]; AiplMatmulWorkerArg args[16]; int64_t chunk = (m + num_workers - 1) / num_workers;
    for (int t = 0; t < num_workers; t++) {
      int64_t start = t * chunk; int64_t end = start + chunk; if (end > m) end = m;
      if (start < end) {
        args[t].A = A; args[t].B_T = B_T; args[t].C = C; args[t].row_start = start; args[t].row_end = end; args[t].n = n; args[t].k = k;
        pthread_create(&threads[t], NULL, aipl_matmul_worker, &args[t]);
      }
    }
    for (int t = 0; t < num_workers; t++) {
      int64_t start = t * chunk; int64_t end = start + chunk; if (end > m) end = m;
      if (start < end) { pthread_join(threads[t], NULL); }
    }
  }
  AiplArray* res = (AiplArray*)malloc(sizeof(AiplArray));
  res->data = (AiplVal*)malloc(sizeof(AiplVal) * (total_c > 0 ? total_c : 1));
  res->len = total_c; res->cap = total_c;
  for (int64_t idx = 0; idx < total_c; idx++) { res->data[idx] = aipl_float(C[idx]); }
  free(A); free(B_T); free(C);
  AiplVal out; memset(&out, 0, sizeof(out)); out.kind = AIPL_ARRAY; out.ptr = res; return out;
}

// Step 7.1: Multi-Threaded Parallel Matmul for Integers
void* aipl_matmul_int_worker(void* param) {
  AiplMatmulIntWorkerArg* arg = (AiplMatmulIntWorkerArg*)param;
  for (int64_t i = arg->row_start; i < arg->row_end; i++) {
    const int64_t* a_row = &arg->A[i * arg->k];
    int64_t* c_row = &arg->C[i * arg->n];
    for (int64_t j = 0; j < arg->n; j++) {
      const int64_t* b_row = &arg->B_T[j * arg->k];
      int64_t dot = 0;
      for (int64_t p = 0; p < arg->k; p++) { dot += a_row[p] * b_row[p]; }
      c_row[j] = dot;
    }
  }
  return NULL;
}

AiplVal aipl_rt_parallel_matmul_int(AiplVal a_val, AiplVal b_val, AiplVal m_val, AiplVal n_val, AiplVal k_val, AiplVal threads_val) {
  int64_t m = m_val.kind == AIPL_INT ? m_val.i : (int64_t)m_val.f;
  int64_t n = n_val.kind == AIPL_INT ? n_val.i : (int64_t)n_val.f;
  int64_t k = k_val.kind == AIPL_INT ? k_val.i : (int64_t)k_val.f;
  int64_t req_threads = threads_val.kind == AIPL_INT ? threads_val.i : (int64_t)threads_val.f;
  if (m <= 0 || n <= 0 || k <= 0) return aipl_rt_intBufferNew(aipl_int(0));
  int64_t total_a = m * k; int64_t total_b = k * n; int64_t total_c = m * n;
  int64_t* A = (int64_t*)malloc(sizeof(int64_t) * (total_a > 0 ? total_a : 1));
  int64_t* B_T = (int64_t*)malloc(sizeof(int64_t) * (total_b > 0 ? total_b : 1));
  int64_t* C = (int64_t*)malloc(sizeof(int64_t) * (total_c > 0 ? total_c : 1));
  if (a_val.kind == AIPL_ARRAY && a_val.ptr) {
    AiplArray* a_arr = (AiplArray*)a_val.ptr;
    for (int64_t idx = 0; idx < total_a; idx++) {
      A[idx] = (idx < a_arr->len) ? (a_arr->data[idx].kind == AIPL_INT ? a_arr->data[idx].i : (int64_t)a_arr->data[idx].f) : 0;
    }
  } else { memset(A, 0, sizeof(int64_t) * total_a); }
  if (b_val.kind == AIPL_ARRAY && b_val.ptr) {
    AiplArray* b_arr = (AiplArray*)b_val.ptr;
    for (int64_t p = 0; p < k; p++) {
      int64_t p_offset = p * n;
      for (int64_t j = 0; j < n; j++) {
        int64_t b_idx = p_offset + j;
        int64_t val = (b_idx < b_arr->len) ? (b_arr->data[b_idx].kind == AIPL_INT ? b_arr->data[b_idx].i : (int64_t)b_arr->data[b_idx].f) : 0;
        B_T[j * k + p] = val;
      }
    }
  } else { memset(B_T, 0, sizeof(int64_t) * total_b); }
  int num_workers = (int)req_threads;
  if (num_workers < 1) num_workers = 1;
  if (num_workers > 16) num_workers = 16;
  if (num_workers > m) num_workers = (int)m;
  if (num_workers <= 1) {
    AiplMatmulIntWorkerArg arg = { A, B_T, C, 0, m, n, k }; aipl_matmul_int_worker(&arg);
  } else {
    pthread_t threads[16]; AiplMatmulIntWorkerArg args[16]; int64_t chunk = (m + num_workers - 1) / num_workers;
    for (int t = 0; t < num_workers; t++) {
      int64_t start = t * chunk; int64_t end = start + chunk; if (end > m) end = m;
      if (start < end) {
        args[t].A = A; args[t].B_T = B_T; args[t].C = C; args[t].row_start = start; args[t].row_end = end; args[t].n = n; args[t].k = k;
        pthread_create(&threads[t], NULL, aipl_matmul_int_worker, &args[t]);
      }
    }
    for (int t = 0; t < num_workers; t++) {
      int64_t start = t * chunk; int64_t end = start + chunk; if (end > m) end = m;
      if (start < end) { pthread_join(threads[t], NULL); }
    }
  }
  AiplArray* res = (AiplArray*)malloc(sizeof(AiplArray));
  res->data = (AiplVal*)malloc(sizeof(AiplVal) * (total_c > 0 ? total_c : 1));
  res->len = total_c; res->cap = total_c;
  for (int64_t idx = 0; idx < total_c; idx++) { res->data[idx] = aipl_int(C[idx]); }
  free(A); free(B_T); free(C);
  AiplVal out; memset(&out, 0, sizeof(out)); out.kind = AIPL_ARRAY; out.ptr = res; return out;
}

// Step 5.3: 32-Bit 3-Address Register VM with Computed-goto Dispatch
int64_t aipl_reg_vm_run_raw(const uint32_t* __restrict__ code, int64_t code_len, int64_t r0_init) {
  (void)code_len;
  static const void* const dispatch_table[16] = {
    &&op_halt, &&op_loadi, &&op_mov, &&op_add,
    &&op_sub, &&op_mul, &&op_div, &&op_mod,
    &&op_lt, &&op_le, &&op_eq, &&op_jmp,
    &&op_jz, &&op_call, &&op_ret, &&op_halt
  };
  #define AIPL_REG_FRAME_SIZE 16
  #define AIPL_MAX_VM_CALL_DEPTH 65536
  size_t vregs_cap = 4096;
  size_t call_cap = 256;
  int64_t* vregs = (int64_t*)calloc(vregs_cap, sizeof(int64_t));
  AiplRegCallFrame* call_stack = (AiplRegCallFrame*)malloc(call_cap * sizeof(AiplRegCallFrame));
  size_t csp_idx = 0;
  int64_t* fp = vregs;
  *fp = r0_init;
  const uint32_t* pc_ptr = code;
  uint32_t inst = *pc_ptr;
  #define REG_NEXT_INST() do { inst = *++pc_ptr; goto *dispatch_table[inst >> 24]; } while (0)
  #define REG_JUMP_TO(target_ptr) do { pc_ptr = (target_ptr); inst = *pc_ptr; goto *dispatch_table[inst >> 24]; } while (0)
  goto *dispatch_table[inst >> 24];
op_loadi: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = (ra != 0) ? (int64_t)((ra << 8) | rb) : (int64_t)rb;
    REG_NEXT_INST();
  }
op_mov: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    fp[rd] = fp[ra];
    REG_NEXT_INST();
  }
op_add: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = fp[ra] + fp[rb];
    REG_NEXT_INST();
  }
op_sub: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = fp[ra] - fp[rb];
    REG_NEXT_INST();
  }
op_mul: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = fp[ra] * fp[rb];
    REG_NEXT_INST();
  }
op_div: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    int64_t b = fp[rb];
    fp[rd] = (b != 0) ? (fp[ra] / b) : 0;
    REG_NEXT_INST();
  }
op_mod: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    int64_t b = fp[rb];
    fp[rd] = (b != 0) ? (fp[ra] % b) : 0;
    REG_NEXT_INST();
  }
op_lt: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = (fp[ra] < fp[rb]) ? 1 : 0;
    REG_NEXT_INST();
  }
op_le: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = (fp[ra] <= fp[rb]) ? 1 : 0;
    REG_NEXT_INST();
  }
op_eq: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    fp[rd] = (fp[ra] == fp[rb]) ? 1 : 0;
    REG_NEXT_INST();
  }
op_jmp: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    int32_t target = ((ra & 255) << 8) | (rb & 255);
    if (target == 0 && rd != 0) target = rd;
    REG_JUMP_TO(code + target);
  }
op_jz: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    if (fp[rd] == 0) {
      REG_JUMP_TO(code + (((ra & 255) << 8) | (rb & 255)));
    } else {
      REG_NEXT_INST();
    }
  }
op_call: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t rb = inst & 255;
    int64_t arg = fp[ra];
    size_t fp_off = (size_t)(fp - vregs);
    if (csp_idx >= call_cap) {
      if (call_cap >= AIPL_MAX_VM_CALL_DEPTH) {
        free(vregs); free(call_stack);
        return 0;
      }
      call_cap *= 2;
      call_stack = (AiplRegCallFrame*)realloc(call_stack, call_cap * sizeof(AiplRegCallFrame));
      if (!call_stack) aipl_rt_panic(aipl_str_lit("OOM expanding VM call stack"));
    }
    if (fp_off + AIPL_REG_FRAME_SIZE * 2 + 256 >= vregs_cap) {
      size_t old_cap = vregs_cap;
      vregs_cap *= 2;
      vregs = (int64_t*)realloc(vregs, vregs_cap * sizeof(int64_t));
      if (!vregs) aipl_rt_panic(aipl_str_lit("OOM expanding VM register file"));
      memset(vregs + old_cap, 0, (vregs_cap - old_cap) * sizeof(int64_t));
      fp = vregs + fp_off;
    }
    call_stack[csp_idx].ret_pc = pc_ptr + 1;
    call_stack[csp_idx].rd = rd;
    call_stack[csp_idx].prev_fp = (int64_t*)(uintptr_t)fp_off;
    csp_idx++;
    fp += AIPL_REG_FRAME_SIZE;
    fp[0] = arg;
    REG_JUMP_TO(code + rb);
  }
op_ret: {
    uint32_t rd = (inst >> 16) & 255;
    uint32_t ra = (inst >> 8) & 255;
    uint32_t r = (rd != 0) ? rd : ra;
    int64_t val = fp[r];
    if (csp_idx == 0) {
      free(vregs);
      free(call_stack);
      return val;
    }
    csp_idx--;
    const uint32_t* next_pc = call_stack[csp_idx].ret_pc;
    uint32_t dest_rd = call_stack[csp_idx].rd;
    size_t prev_off = (size_t)(uintptr_t)call_stack[csp_idx].prev_fp;
    fp = vregs + prev_off;
    fp[dest_rd] = val;
    REG_JUMP_TO(next_pc);
  }
op_halt: {
    uint32_t rd = (inst >> 16) & 255;
    int64_t val = fp[rd];
    free(vregs);
    free(call_stack);
    return val;
  }
}

AiplVal aipl_rt_reg_vm_exec(AiplVal code_arr, AiplVal r0_init) {
  if (code_arr.kind != AIPL_ARRAY || !code_arr.ptr) {
    return aipl_int(0);
  }
  AiplArray* arr = (AiplArray*)code_arr.ptr;
  int64_t n = arr->len;
  if (n <= 0) return aipl_int(0);
  uint32_t stack_code[256];
  uint32_t* cbuf = (n <= 256) ? stack_code : (uint32_t*)malloc(sizeof(uint32_t) * n);
  for (int64_t i = 0; i < n; i++) {
    cbuf[i] = (uint32_t)arr->data[i].i;
  }
  int64_t res = aipl_reg_vm_run_raw(cbuf, n, r0_init.i);
  if (cbuf != stack_code) free(cbuf);
  return aipl_int(res);
}

AiplVal aipl_rt_reg_vm_fib(AiplVal n_val) {
  static const uint32_t fibCode[12] = {
    ((1 & 255) << 24) | ((1 & 255) << 16) | ((0 & 255) << 8) | (2 & 255),
    ((8 & 255) << 24) | ((2 & 255) << 16) | ((0 & 255) << 8) | (1 & 255),
    ((12 & 255) << 24) | ((2 & 255) << 16) | ((0 & 255) << 8) | (4 & 255),
    ((14 & 255) << 24) | ((0 & 255) << 16) | ((0 & 255) << 8) | (0 & 255),
    ((1 & 255) << 24) | ((1 & 255) << 16) | ((0 & 255) << 8) | (1 & 255),
    ((4 & 255) << 24) | ((2 & 255) << 16) | ((0 & 255) << 8) | (1 & 255),
    ((13 & 255) << 24) | ((3 & 255) << 16) | ((2 & 255) << 8) | (0 & 255),
    ((1 & 255) << 24) | ((1 & 255) << 16) | ((0 & 255) << 8) | (2 & 255),
    ((4 & 255) << 24) | ((2 & 255) << 16) | ((0 & 255) << 8) | (1 & 255),
    ((13 & 255) << 24) | ((4 & 255) << 16) | ((2 & 255) << 8) | (0 & 255),
    ((3 & 255) << 24) | ((0 & 255) << 16) | ((3 & 255) << 8) | (4 & 255),
    ((14 & 255) << 24) | ((0 & 255) << 16) | ((0 & 255) << 8) | (0 & 255)
  };
  return aipl_int(aipl_reg_vm_run_raw(fibCode, 12, n_val.i));
}

AiplVal aipl_rt_compile_c_single(AiplVal v_cSource, AiplVal v_outputPath, AiplVal v_optFlag, AiplVal v_debugInfo, AiplVal v_includeDir, AiplVal v_archive) {
  /* Private 0700 temp dir: no predictable /tmp paths that could be pre-planted or symlinked. */
  char tmp_dir[] = "/tmp/aipl_cc1_XXXXXX";
  if (!mkdtemp(tmp_dir)) return aipl_err(aipl_str("Failed to create private temp dir for C compilation"));
  char tmp_c[512];
  snprintf(tmp_c, sizeof(tmp_c), "%s/main.c", tmp_dir);
  FILE* fp = fopen(tmp_c, "wb");
  if (!fp) { rmdir(tmp_dir); return aipl_err(aipl_str("Failed to open tmp C file for writing")); }
  if (v_cSource.kind == AIPL_STR && v_cSource.s) fwrite(v_cSource.s, 1, strlen(v_cSource.s), fp);
  fclose(fp);
  const char* opt = (v_optFlag.kind == AIPL_STR && v_optFlag.s && v_optFlag.s[0]) ? v_optFlag.s : "-O2";
  bool is_dbg = (v_debugInfo.kind == AIPL_BOOL && v_debugInfo.b);
  char* args[32];
  int aa = 0;
  args[aa++] = "cc";
  args[aa++] = "-std=c99";
  args[aa++] = (char*)opt;
  if (is_dbg) args[aa++] = "-g";
  args[aa++] = "-pthread";
  args[aa++] = "-Wall";
  args[aa++] = "-Wextra";
  args[aa++] = "-Wno-unused-parameter";
  args[aa++] = "-Wno-unused-function";
  args[aa++] = "-Wno-unused-variable";
  args[aa++] = "-Wno-unused-but-set-variable";
  args[aa++] = "-Wno-misleading-indentation";
  if (v_includeDir.kind == AIPL_STR && v_includeDir.s && v_includeDir.s[0]) { args[aa++] = "-I"; args[aa++] = (char*)v_includeDir.s; }
  args[aa++] = tmp_c;
  args[aa++] = "-o";
  args[aa++] = (char*)((v_outputPath.kind == AIPL_STR && v_outputPath.s) ? v_outputPath.s : "a.out");
  if (v_archive.kind == AIPL_STR && v_archive.s && v_archive.s[0]) args[aa++] = (char*)v_archive.s;
#if defined(__linux__)
  args[aa++] = "-Wl,--gc-sections";
#endif
  args[aa++] = "-lm";
  args[aa++] = "-ldl";
  args[aa++] = "-lpthread";
  args[aa] = NULL;
  pid_t pid = fork();
  if (pid == 0) {
    execvp("cc", args);
    _exit(127);
  }
  int status = 0;
  if (pid < 0) status = 1 << 8;
  else waitpid(pid, &status, 0);
  unlink(tmp_c);
  rmdir(tmp_dir);
  if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
    return aipl_err(aipl_str("Host C compiler failed"));
  }
  struct stat st;
  int64_t sz = 0;
  if (v_outputPath.kind == AIPL_STR && v_outputPath.s && stat(v_outputPath.s, &st) == 0) sz = (int64_t)st.st_size;
  return aipl_ok(aipl_int(sz));
}

int aipl_rt_fn_slice_cmp_desc(const void* a, const void* b) {
  const AiplFnSlice* sa = (const AiplFnSlice*)a;
  const AiplFnSlice* sb = (const AiplFnSlice*)b;
  if (sb->len > sa->len) return 1;
  if (sb->len < sa->len) return -1;
  return 0;
}

// Step 17.5 (Bug #7) & Step 20.5: only treat a marker as a shard split boundary when the next line opens an aipl_fn_ definition.
const char* aipl_next_fn_marker(const char* p) {
  while (p && (p = strstr(p, "\n/* AIPL Function: ")) != NULL) {
    const char* eol = strchr(p + 1, '\n');
    if (eol && (strncmp(eol, "\nAiplVal aipl_fn_", 17) == 0 || strncmp(eol, "\n__attribute__((hot)) AiplVal aipl_fn_", 38) == 0)) return p;
    p += 1;
  }
  return NULL;
}

AiplVal aipl_rt_compile_c_parallel(AiplVal v_cSource, AiplVal v_outputPath, AiplVal v_optFlag, AiplVal v_debugInfo, AiplVal v_includeDir, AiplVal v_archive) {
  if (v_cSource.kind != AIPL_STR || !v_cSource.s) {
    return aipl_err(aipl_str("Invalid C source string"));
  }
  const char* src = v_cSource.s;
  int ncpus = (int)aipl_rt_hardware_concurrency().i;
  const char* first_fn_nl = aipl_next_fn_marker(src);
  if (!first_fn_nl || ncpus <= 1) {
    return aipl_rt_compile_c_single(v_cSource, v_outputPath, v_optFlag, v_debugInfo, v_includeDir, v_archive);
  }
  const char* first_fn = first_fn_nl + 1;
  const char* tail_pos = NULL;
  const char* scan_p = first_fn;
  while ((scan_p = strstr(scan_p, "\nstatic void aipl_rt_init_globals(void) {")) != NULL) {
    tail_pos = scan_p + 1;
    scan_p += 41;
  }
  if (!tail_pos) {
    return aipl_rt_compile_c_single(v_cSource, v_outputPath, v_optFlag, v_debugInfo, v_includeDir, v_archive);
  }
  size_t cap = 256;
  size_t M = 0;
  AiplFnSlice* slices = (AiplFnSlice*)malloc(sizeof(AiplFnSlice) * cap);
  const char* cur = first_fn;
  while (cur < tail_pos) {
    const char* next_fn_nl = aipl_next_fn_marker(cur + 18);
    const char* next_fn = next_fn_nl ? (next_fn_nl + 1) : tail_pos;
    if (next_fn > tail_pos) {
      next_fn = tail_pos;
    }
    if (M >= cap) {
      cap *= 2;
      slices = (AiplFnSlice*)realloc(slices, sizeof(AiplFnSlice) * cap);
    }
    slices[M].start = cur;
    slices[M].len = (size_t)(next_fn - cur);
    slices[M].original_idx = (int)M;
    M++;
    cur = next_fn;
  }
  if (M < 16) {
    free(slices);
    return aipl_rt_compile_c_single(v_cSource, v_outputPath, v_optFlag, v_debugInfo, v_includeDir, v_archive);
  }
  int workers = ncpus;
  if (workers > 64) workers = 64;
  if (workers > (int)M) workers = (int)M;
  qsort(slices, M, sizeof(AiplFnSlice), aipl_rt_fn_slice_cmp_desc);
  typedef struct {
    size_t total_size;
    size_t count;
    size_t cap;
    int* slice_indices;
    bool has_tail;
  } AiplShard;
  AiplShard shards[64];
  for (int w = 0; w < workers; w++) {
    shards[w].total_size = 0;
    shards[w].count = 0;
    shards[w].cap = 32;
    shards[w].slice_indices = (int*)malloc(sizeof(int) * shards[w].cap);
    shards[w].has_tail = false;
  }
  for (size_t i = 0; i < M; i++) {
    int best_w = 0;
    for (int w = 1; w < workers; w++) {
      if (shards[w].total_size < shards[best_w].total_size) {
        best_w = w;
      }
    }
    if (shards[best_w].count >= shards[best_w].cap) {
      shards[best_w].cap *= 2;
      shards[best_w].slice_indices = (int*)realloc(shards[best_w].slice_indices, sizeof(int) * shards[best_w].cap);
    }
    shards[best_w].slice_indices[shards[best_w].count++] = (int)i;
    shards[best_w].total_size += slices[i].len;
  }
  int tail_w = 0;
  for (int w = 1; w < workers; w++) {
    if (shards[w].total_size < shards[tail_w].total_size) {
      tail_w = w;
    }
  }
  shards[tail_w].has_tail = true;
  shards[tail_w].total_size += strlen(tail_pos);
  static int g_cc_seq = 0;
  int seq = __sync_fetch_and_add(&g_cc_seq, 1);
  pid_t pid = getpid();
  char common_h_path[256];
  char cc_dir[] = "/tmp/aipl_cc_XXXXXX";
  if (!mkdtemp(cc_dir)) {
    for (int w = 0; w < workers; w++) free(shards[w].slice_indices);
    free(slices);
    return aipl_rt_compile_c_single(v_cSource, v_outputPath, v_optFlag, v_debugInfo, v_includeDir, v_archive);
  }
  (void)pid; (void)seq;
  snprintf(common_h_path, sizeof(common_h_path), "%s/common.h", cc_dir);
  FILE* hfp = fopen(common_h_path, "wb");
  if (!hfp) {
    for (int w = 0; w < workers; w++) free(shards[w].slice_indices);
    free(slices);
    return aipl_rt_compile_c_single(v_cSource, v_outputPath, v_optFlag, v_debugInfo, v_includeDir, v_archive);
  }
  size_t header_len = (size_t)(first_fn - src);
  fwrite(src, 1, header_len, hfp);
  fclose(hfp);
  const char* opt = (v_optFlag.kind == AIPL_STR && v_optFlag.s && v_optFlag.s[0]) ? v_optFlag.s : "-O2";
  bool is_dbg = (v_debugInfo.kind == AIPL_BOOL && v_debugInfo.b);
  (void)mkdir("/tmp/aipl-shard-cache", 0755);
  uint64_t hdr_h1 = 1469598103934665603ULL;
  uint64_t hdr_h2 = 1099511628211ULL ^ 0x9e3779b97f4a7c15ULL;
  for (size_t hi = 0; hi < header_len; hi++) {
    uint8_t b = (uint8_t)src[hi];
    hdr_h1 = (hdr_h1 ^ b) * 1099511628211ULL;
    hdr_h2 = (hdr_h2 + b) * 0xbf58476d1ce4e5b9ULL;
  }
  for (const char* op = opt; *op; op++) {
    hdr_h1 = (hdr_h1 ^ (uint8_t)*op) * 1099511628211ULL;
    hdr_h2 = (hdr_h2 + (uint8_t)*op) * 0x94d049bb133111ebULL;
  }
  hdr_h1 ^= (uint64_t)(is_dbg ? 0x55 : 0xaa);
  char shard_c_path[64][256];
  char shard_o_path[64][256];
  char shard_err_path[64][256];
  char shard_cache_path[64][256];
  bool shard_cached[64];
  for (int w = 0; w < workers; w++) {
    snprintf(shard_c_path[w], sizeof(shard_c_path[w]), "%s/shard_%d.c", cc_dir, w);
    snprintf(shard_o_path[w], sizeof(shard_o_path[w]), "%s/shard_%d.o", cc_dir, w);
    snprintf(shard_err_path[w], sizeof(shard_err_path[w]), "%s/shard_%d.err", cc_dir, w);
    uint64_t sh1 = hdr_h1;
    uint64_t sh2 = hdr_h2;
    for (size_t c = 0; c < shards[w].count; c++) {
      int sidx = shards[w].slice_indices[c];
      const char* sp = slices[sidx].start;
      size_t slen = slices[sidx].len;
      for (size_t bi = 0; bi < slen; bi++) {
        uint8_t b = (uint8_t)sp[bi];
        sh1 = (sh1 ^ b) * 1099511628211ULL;
        sh2 = (sh2 + b) * 0xbf58476d1ce4e5b9ULL;
      }
      sh1 = (sh1 ^ 10u) * 1099511628211ULL;
    }
    if (shards[w].has_tail) {
      for (const char* tp = tail_pos; *tp; tp++) {
        uint8_t b = (uint8_t)*tp;
        sh1 = (sh1 ^ b) * 1099511628211ULL;
        sh2 = (sh2 + b) * 0xbf58476d1ce4e5b9ULL;
      }
    }
    snprintf(shard_cache_path[w], sizeof(shard_cache_path[w]), "/tmp/aipl-shard-cache/shard_%016llx_%016llx.o",
             (unsigned long long)sh1, (unsigned long long)sh2);
    shard_cached[w] = false;
    struct stat cst;
    if (stat(shard_cache_path[w], &cst) == 0 && cst.st_size > 0) {
      FILE* csrc = fopen(shard_cache_path[w], "rb");
      if (csrc) {
        FILE* cdst = fopen(shard_o_path[w], "wb");
        if (cdst) {
          char cbuf[16384];
          size_t cn;
          bool copy_ok = true;
          while ((cn = fread(cbuf, 1, sizeof(cbuf), csrc)) > 0) {
            if (fwrite(cbuf, 1, cn, cdst) != cn) { copy_ok = false; break; }
          }
          fclose(cdst);
          if (copy_ok) shard_cached[w] = true;
        }
        fclose(csrc);
      }
    }
    if (shard_cached[w]) continue;
    FILE* sfp = fopen(shard_c_path[w], "wb");
    if (!sfp) continue;
    fprintf(sfp, "#include \"common.h\"\n\n");
    for (size_t c = 0; c < shards[w].count; c++) {
      int sidx = shards[w].slice_indices[c];
      fwrite(slices[sidx].start, 1, slices[sidx].len, sfp);
      fputc('\n', sfp);
    }
    if (shards[w].has_tail) {
      fwrite(tail_pos, 1, strlen(tail_pos), sfp);
    }
    fclose(sfp);
  }
  pid_t pids[64];
  for (int w = 0; w < workers; w++) {
    if (shard_cached[w]) {
      pids[w] = -2;
      continue;
    }
    fflush(stdout); fflush(stderr);
    pid_t cpid = fork();
    if (cpid == 0) {
      int err_fd = open(shard_err_path[w], O_WRONLY | O_CREAT | O_TRUNC, 0644);
      if (err_fd >= 0) {
        dup2(err_fd, STDERR_FILENO);
        close(err_fd);
      }
      char* args[36];
      int aa = 0;
      args[aa++] = "cc";
      args[aa++] = "-std=c99";
      args[aa++] = (char*)opt;
      if (is_dbg) args[aa++] = "-g";
      args[aa++] = "-pipe";
      args[aa++] = "-pthread";
      args[aa++] = "-Wall";
      args[aa++] = "-Wextra";
      args[aa++] = "-Wno-unused-parameter";
      args[aa++] = "-Wno-unused-function";
      args[aa++] = "-Wno-unused-variable";
      args[aa++] = "-Wno-unused-but-set-variable";
      args[aa++] = "-Wno-misleading-indentation";
      args[aa++] = "-I";
      args[aa++] = cc_dir;
      if (v_includeDir.kind == AIPL_STR && v_includeDir.s && v_includeDir.s[0]) { args[aa++] = "-I"; args[aa++] = (char*)v_includeDir.s; }
      args[aa++] = "-c";
      args[aa++] = shard_c_path[w];
      args[aa++] = "-o";
      args[aa++] = shard_o_path[w];
      args[aa] = NULL;
      execvp("cc", args);
      _exit(127);
    }
    pids[w] = cpid;
  }
  bool compile_failed = false;
  int failed_w = -1;
  for (int w = 0; w < workers; w++) {
    if (pids[w] == -2) continue;
    int status = 0;
    if (pids[w] <= 0) status = 1 << 8;
    else waitpid(pids[w], &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
      compile_failed = true;
      if (failed_w < 0) failed_w = w;
    } else {
      char tmp_cache[300];
      snprintf(tmp_cache, sizeof(tmp_cache), "%s.tmp.%d", shard_cache_path[w], (int)getpid());
      FILE* osrc = fopen(shard_o_path[w], "rb");
      if (osrc) {
        FILE* odst = fopen(tmp_cache, "wb");
        if (odst) {
          char cbuf[16384];
          size_t cn;
          bool copy_ok = true;
          while ((cn = fread(cbuf, 1, sizeof(cbuf), osrc)) > 0) {
            if (fwrite(cbuf, 1, cn, odst) != cn) { copy_ok = false; break; }
          }
          fclose(odst);
          if (copy_ok) rename(tmp_cache, shard_cache_path[w]);
          else unlink(tmp_cache);
        }
        fclose(osrc);
      }
    }
  }
  if (compile_failed) {
    char err_msg[2048];
    snprintf(err_msg, sizeof(err_msg), "Host C compiler sharded compilation failed on shard %d", failed_w);
    if (failed_w >= 0) {
      FILE* efp = fopen(shard_err_path[failed_w], "rb");
      if (efp) {
        size_t elen = fread(err_msg, 1, sizeof(err_msg) - 1, efp);
        if (elen > 0) err_msg[elen] = 0;
        fclose(efp);
      }
    }
    unlink(common_h_path);
    for (int w = 0; w < workers; w++) {
      unlink(shard_c_path[w]);
      unlink(shard_o_path[w]);
      unlink(shard_err_path[w]);
      free(shards[w].slice_indices);
    }
    free(slices);
    rmdir(cc_dir);
    return aipl_err(aipl_str(err_msg));
  }
  char link_err_path[256];
  snprintf(link_err_path, sizeof(link_err_path), "%s/link.err", cc_dir);
  char* link_args[128];
  int la = 0;
  link_args[la++] = "cc";
  if (is_dbg) link_args[la++] = "-g";
  link_args[la++] = "-pthread";
  link_args[la++] = "-pipe";
  for (int w = 0; w < workers; w++) {
    link_args[la++] = shard_o_path[w];
  }
  link_args[la++] = "-o";
  link_args[la++] = (char*)((v_outputPath.kind == AIPL_STR && v_outputPath.s) ? v_outputPath.s : "a.out");
  if (v_archive.kind == AIPL_STR && v_archive.s && v_archive.s[0]) link_args[la++] = (char*)v_archive.s;
#if defined(__linux__)
  link_args[la++] = "-Wl,--gc-sections";
#endif
  link_args[la++] = "-lm";
  link_args[la++] = "-ldl";
  link_args[la++] = "-lpthread";
  link_args[la] = NULL;
  pid_t link_pid = fork();
  if (link_pid == 0) {
    int err_fd = open(link_err_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (err_fd >= 0) {
      dup2(err_fd, STDERR_FILENO);
      close(err_fd);
    }
    execvp("cc", link_args);
    _exit(127);
  }
  int link_status = 0;
  if (link_pid < 0) link_status = 1 << 8;
  else waitpid(link_pid, &link_status, 0);
  bool link_failed = (!WIFEXITED(link_status) || WEXITSTATUS(link_status) != 0);
  char link_err_msg[2048] = "Host C linker failed";
  if (link_failed) {
    FILE* lfp = fopen(link_err_path, "rb");
    if (lfp) {
      size_t elen = fread(link_err_msg, 1, sizeof(link_err_msg) - 1, lfp);
      if (elen > 0) link_err_msg[elen] = 0;
      fclose(lfp);
    }
  }
  unlink(common_h_path);
  unlink(link_err_path);
  for (int w = 0; w < workers; w++) {
    unlink(shard_c_path[w]);
    unlink(shard_o_path[w]);
    unlink(shard_err_path[w]);
    free(shards[w].slice_indices);
  }
  free(slices);
  rmdir(cc_dir);
  if (link_failed) {
    return aipl_err(aipl_str(link_err_msg));
  }
  struct stat st;
  int64_t file_size = 0;
  if (v_outputPath.kind == AIPL_STR && v_outputPath.s && stat(v_outputPath.s, &st) == 0) {
    file_size = (int64_t)st.st_size;
  }
  return aipl_ok(aipl_int(file_size));
}

// ============================================================================
// Phase 19: Binary AiplVal Serialization, AstArena Merger & All-CPU Fork Pools
// ============================================================================

static AiplVal aipl_array_with_cap(int64_t cap) {
  AiplArray* arr = (AiplArray*)malloc(sizeof(AiplArray));
  int64_t c = cap > 8 ? cap : 8;
  arr->data = (AiplVal*)malloc(sizeof(AiplVal) * (size_t)c);
  arr->len = 0;
  arr->cap = c;
  AiplVal v;
  memset(&v, 0, sizeof(v));
  v.kind = AIPL_ARRAY;
  v.ptr = arr;
  return v;
}

static inline bool aipl_is_struct_or_map(AiplVal v) {
  return (v.kind == AIPL_STRUCT || v.kind == AIPL_MAP) && v.ptr != NULL;
}

void aipl_val_write_bin(FILE* fp, AiplVal v) {
  uint8_t k = (uint8_t)v.kind;
  fwrite(&k, 1, 1, fp);
  fwrite(&v.extra_i, sizeof(int32_t), 1, fp);
  switch (v.kind) {
    case AIPL_INT:
    case AIPL_BOOL:
      fwrite(&v.i, sizeof(int64_t), 1, fp);
      break;
    case AIPL_FLOAT:
      fwrite(&v.f, sizeof(double), 1, fp);
      break;
    case AIPL_STR: {
      uint32_t slen = (v.s) ? (uint32_t)strlen(v.s) : 0;
      fwrite(&slen, sizeof(uint32_t), 1, fp);
      if (slen > 0) fwrite(v.s, 1, slen, fp);
      break;
    }
    case AIPL_BYTES: {
      AiplBytes* b = (AiplBytes*)v.ptr;
      uint32_t blen = (b && b->len > 0) ? (uint32_t)b->len : 0;
      fwrite(&blen, sizeof(uint32_t), 1, fp);
      if (blen > 0) fwrite(b->data, 1, blen, fp);
      break;
    }
    case AIPL_ARRAY: {
      AiplArray* a = (AiplArray*)v.ptr;
      uint32_t alen = (a && a->len > 0) ? (uint32_t)a->len : 0;
      fwrite(&alen, sizeof(uint32_t), 1, fp);
      for (uint32_t i = 0; i < alen; i++) {
        aipl_val_write_bin(fp, a->data[i]);
      }
      break;
    }
    case AIPL_MAP: {
      AiplMap* m = (AiplMap*)v.ptr;
      uint32_t mlen = (m && m->len > 0) ? (uint32_t)m->len : 0;
      fwrite(&mlen, sizeof(uint32_t), 1, fp);
      for (uint32_t i = 0; i < mlen; i++) {
        const char* key = m->keys[i];
        uint32_t klen = key ? (uint32_t)strlen(key) : 0;
        fwrite(&klen, sizeof(uint32_t), 1, fp);
        if (klen > 0) fwrite(key, 1, klen, fp);
        aipl_val_write_bin(fp, m->vals[i]);
      }
      break;
    }
    case AIPL_STRUCT: {
      AiplStruct* st = (AiplStruct*)v.ptr;
      const char* tname = (st && st->type_name) ? st->type_name : "";
      uint32_t tlen = (uint32_t)strlen(tname);
      fwrite(&tlen, sizeof(uint32_t), 1, fp);
      if (tlen > 0) fwrite(tname, 1, tlen, fp);
      int64_t st_extra = st ? st->extra_i : 0;
      fwrite(&st_extra, sizeof(int64_t), 1, fp);
      uint32_t flen = (st && st->len > 0) ? (uint32_t)st->len : 0;
      fwrite(&flen, sizeof(uint32_t), 1, fp);
      for (uint32_t i = 0; i < flen; i++) {
        const char* fn = st->names[i] ? st->names[i] : "";
        uint32_t fnlen = (uint32_t)strlen(fn);
        fwrite(&fnlen, sizeof(uint32_t), 1, fp);
        if (fnlen > 0) fwrite(fn, 1, fnlen, fp);
        aipl_val_write_bin(fp, st->vals[i]);
      }
      break;
    }
    case AIPL_RES_OK:
    case AIPL_RES_ERR:
    case AIPL_OPT_SOME: {
      AiplVal inner = v.ptr ? *(AiplVal*)v.ptr : aipl_nil();
      aipl_val_write_bin(fp, inner);
      break;
    }
    default:
      break;
  }
}

static AiplVal aipl_val_read_bin_checked(FILE* fp, bool* ok) {
  if (!*ok) return aipl_nil();
  uint8_t k = 0;
  if (fread(&k, 1, 1, fp) != 1 || k > (uint8_t)AIPL_OPT_NONE) {
    *ok = false;
    return aipl_nil();
  }
  int32_t extra_i = 0;
  if (fread(&extra_i, sizeof(int32_t), 1, fp) != 1) {
    *ok = false;
    return aipl_nil();
  }
  AiplVal out = aipl_nil();
  out.kind = (AiplKind)k;
  out.extra_i = extra_i;
  switch ((AiplKind)k) {
    case AIPL_NIL:
    case AIPL_OPT_NONE:
      break;
    case AIPL_INT:
    case AIPL_BOOL: {
      int64_t iv = 0;
      if (fread(&iv, sizeof(int64_t), 1, fp) != 1) {
        *ok = false;
        return aipl_nil();
      }
      out.i = iv;
      if (out.kind == AIPL_BOOL) out.b = (iv != 0) ? 1 : 0;
      break;
    }
    case AIPL_FLOAT: {
      double fv = 0.0;
      if (fread(&fv, sizeof(double), 1, fp) != 1) {
        *ok = false;
        return aipl_nil();
      }
      out.f = fv;
      break;
    }
    case AIPL_STR: {
      uint32_t slen = 0;
      if (fread(&slen, sizeof(uint32_t), 1, fp) != 1 || slen > 64U * 1024U * 1024U) {
        *ok = false;
        return aipl_nil();
      }
      if (slen == 0) {
        out.s = "";
      } else {
        char* buf = (char*)malloc((size_t)slen + 1);
        if (!buf || fread(buf, 1, slen, fp) != slen) {
          free(buf);
          *ok = false;
          return aipl_nil();
        }
        buf[slen] = '\0';
        out.s = buf;
      }
      break;
    }
    case AIPL_BYTES: {
      uint32_t blen = 0;
      if (fread(&blen, sizeof(uint32_t), 1, fp) != 1 || blen > 64U * 1024U * 1024U) {
        *ok = false;
        return aipl_nil();
      }
      AiplVal bv = aipl_bytes_new((int64_t)blen);
      if (blen > 0) {
        AiplBytes* b = (AiplBytes*)bv.ptr;
        if (!b || fread(b->data, 1, blen, fp) != blen) {
          if (b) b->len = 0;
          *ok = false;
          return aipl_nil();
        }
      }
      bv.extra_i = extra_i;
      return bv;
    }
    case AIPL_ARRAY: {
      uint32_t alen = 0;
      if (fread(&alen, sizeof(uint32_t), 1, fp) != 1 || alen > 4U * 1024U * 1024U) {
        *ok = false;
        return aipl_nil();
      }
      AiplVal arr = aipl_array_with_cap((int64_t)(alen > 0 ? alen : 8));
      AiplArray* a = (AiplArray*)arr.ptr;
      for (uint32_t i = 0; i < alen; i++) {
        a->data[i] = aipl_val_read_bin_checked(fp, ok);
        if (!*ok) {
          a->len = (int64_t)i;
          return aipl_nil();
        }
      }
      a->len = (int64_t)alen;
      arr.extra_i = extra_i;
      return arr;
    }
    case AIPL_MAP: {
      uint32_t mlen = 0;
      if (fread(&mlen, sizeof(uint32_t), 1, fp) != 1 || mlen > 4U * 1024U * 1024U) {
        *ok = false;
        return aipl_nil();
      }
      AiplVal mp = aipl_map_new();
      for (uint32_t i = 0; i < mlen; i++) {
        uint32_t klen = 0;
        if (fread(&klen, sizeof(uint32_t), 1, fp) != 1 || klen > 1024U * 1024U) {
          *ok = false;
          return aipl_nil();
        }
        char* kbuf = (char*)malloc((size_t)klen + 1);
        if (!kbuf || (klen > 0 && fread(kbuf, 1, klen, fp) != klen)) {
          free(kbuf);
          *ok = false;
          return aipl_nil();
        }
        kbuf[klen] = '\0';
        AiplVal mv = aipl_val_read_bin_checked(fp, ok);
        if (!*ok) {
          free(kbuf);
          return aipl_nil();
        }
        aipl_map_set(mp, aipl_str_lit(kbuf), mv);
        free(kbuf);
      }
      mp.extra_i = extra_i;
      return mp;
    }
    case AIPL_STRUCT: {
      uint32_t tlen = 0;
      if (fread(&tlen, sizeof(uint32_t), 1, fp) != 1 || tlen > 65536U) {
        *ok = false;
        return aipl_nil();
      }
      char* tname = (char*)malloc((size_t)tlen + 1);
      if (!tname || (tlen > 0 && fread(tname, 1, tlen, fp) != tlen)) {
        free(tname);
        *ok = false;
        return aipl_nil();
      }
      tname[tlen] = '\0';
      int64_t st_extra = 0;
      if (fread(&st_extra, sizeof(int64_t), 1, fp) != 1) {
        free(tname);
        *ok = false;
        return aipl_nil();
      }
      uint32_t flen = 0;
      if (fread(&flen, sizeof(uint32_t), 1, fp) != 1 || flen > 65536U) {
        free(tname);
        *ok = false;
        return aipl_nil();
      }
      size_t total = sizeof(AiplStruct) + sizeof(const char*) * (size_t)flen + sizeof(AiplVal) * (size_t)flen;
      char* mem = (char*)malloc(total);
      if (!mem) {
        free(tname);
        *ok = false;
        return aipl_nil();
      }
      AiplStruct* st = (AiplStruct*)mem;
      st->type_name = tname;
      st->len = (int64_t)flen;
      st->extra_i = st_extra;
      st->names = (const char**)(mem + sizeof(AiplStruct));
      st->vals = (AiplVal*)(mem + sizeof(AiplStruct) + sizeof(const char*) * (size_t)flen);
      for (uint32_t i = 0; i < flen; i++) {
        uint32_t fnlen = 0;
        if (fread(&fnlen, sizeof(uint32_t), 1, fp) != 1 || fnlen > 65536U) {
          st->len = (int64_t)i;
          *ok = false;
          return aipl_nil();
        }
        char* fn = (char*)malloc((size_t)fnlen + 1);
        if (!fn || (fnlen > 0 && fread(fn, 1, fnlen, fp) != fnlen)) {
          free(fn);
          st->len = (int64_t)i;
          *ok = false;
          return aipl_nil();
        }
        fn[fnlen] = '\0';
        st->names[i] = fn;
        st->vals[i] = aipl_val_read_bin_checked(fp, ok);
        if (!*ok) {
          st->len = (int64_t)(i + 1);
          return aipl_nil();
        }
      }
      out.ptr = st;
      break;
    }
    case AIPL_RES_OK:
    case AIPL_RES_ERR:
    case AIPL_OPT_SOME: {
      AiplVal* inner = (AiplVal*)malloc(sizeof(AiplVal));
      *inner = aipl_val_read_bin_checked(fp, ok);
      if (!*ok) {
        free(inner);
        return aipl_nil();
      }
      out.ptr = inner;
      break;
    }
    default:
      *ok = false;
      return aipl_nil();
  }
  return out;
}

AiplVal aipl_val_read_bin(FILE* fp) {
  bool ok = true;
  AiplVal v = aipl_val_read_bin_checked(fp, &ok);
  return ok ? v : aipl_nil();
}

#define AIPL_CACHE_MAGIC_HEADER 0x4149504C41535432ULL /* "AIPLAST2" */
#define AIPL_CACHE_MAGIC_TRAILER 0x454E4421U          /* "END!" */

static void aipl_cache_write_arena(const char* cache_path, AiplVal ar) {
  char tmp_path[320];
  snprintf(tmp_path, sizeof(tmp_path), "%s.tmp.%d", cache_path, (int)getpid());
  FILE* wfp = fopen(tmp_path, "wb");
  if (!wfp) return;
  uint64_t hdr = AIPL_CACHE_MAGIC_HEADER;
  uint32_t trl = AIPL_CACHE_MAGIC_TRAILER;
  fwrite(&hdr, sizeof(uint64_t), 1, wfp);
  aipl_val_write_bin(wfp, ar);
  fwrite(&trl, sizeof(uint32_t), 1, wfp);
  if (fflush(wfp) == 0 && !ferror(wfp)) {
    fclose(wfp);
    rename(tmp_path, cache_path);
  } else {
    fclose(wfp);
    unlink(tmp_path);
  }
}

static bool aipl_cache_read_arena(const char* cache_path, AiplVal* out_ar) {
  FILE* cfp = fopen(cache_path, "rb");
  if (!cfp) return false;
  uint64_t hdr = 0;
  if (fread(&hdr, sizeof(uint64_t), 1, cfp) != 1 || hdr != AIPL_CACHE_MAGIC_HEADER) {
    fclose(cfp);
    unlink(cache_path);
    return false;
  }
  bool ok = true;
  AiplVal ar = aipl_val_read_bin_checked(cfp, &ok);
  uint32_t trl = 0;
  if (!ok || !aipl_is_struct_or_map(ar) || fread(&trl, sizeof(uint32_t), 1, cfp) != 1 || trl != AIPL_CACHE_MAGIC_TRAILER) {
    fclose(cfp);
    unlink(cache_path);
    return false;
  }
  fclose(cfp);
  *out_ar = ar;
  return true;
}

static void aipl_offset_span_line(AiplVal v_node, int64_t lineOff) {
  if (lineOff == 0 || !aipl_is_struct_or_map(v_node)) return;
  AiplVal v_span = aipl_member_get(v_node, "span");
  if (aipl_is_struct_or_map(v_span)) {
    AiplVal v_line = aipl_member_get(v_span, "line");
    if (v_line.kind == AIPL_INT) {
      AiplVal v_col = aipl_member_get(v_span, "column");
      if (v_col.kind != AIPL_INT) v_col = aipl_int(1);
      AiplVal v_fid = aipl_member_get(v_span, "fileId");
      if (v_fid.kind != AIPL_INT) v_fid = aipl_int(0);
      AiplVal v_st = aipl_member_get(v_span, "start");
      if (v_st.kind != AIPL_INT) v_st = aipl_int(0);
      AiplVal v_en = aipl_member_get(v_span, "end");
      if (v_en.kind != AIPL_INT) v_en = aipl_int(0);
      const char* s_names[5] = { "fileId", "start", "end", "line", "column" };
      AiplVal s_vals[5] = {
        v_fid,
        v_st,
        v_en,
        aipl_int(v_line.i + lineOff),
        v_col
      };
      aipl_member_set_val(v_node, "span", aipl_struct_new("Span", 5, s_names, s_vals));
    }
  }
}

static void aipl_offset_int_array_field(AiplVal v_node, const char* key, int64_t off) {
  if (off == 0 || !aipl_is_struct_or_map(v_node)) return;
  AiplVal v_arr = aipl_member_get(v_node, key);
  if (v_arr.kind != AIPL_ARRAY || !v_arr.ptr) return;
  AiplArray* a = (AiplArray*)v_arr.ptr;
  if (a->len <= 0) return;
  AiplVal out = aipl_array_with_cap(a->len);
  AiplArray* oa = (AiplArray*)out.ptr;
  oa->len = a->len;
  for (int64_t i = 0; i < a->len; i++) {
    AiplVal el = a->data[i];
    if (el.kind == AIPL_INT && el.i >= 0) {
      el.i += off;
    }
    oa->data[i] = el;
  }
  aipl_member_set_val(v_node, key, out);
}

static void aipl_offset_int_field(AiplVal v_node, const char* key, int64_t off) {
  if (off == 0 || !aipl_is_struct_or_map(v_node)) return;
  AiplVal v = aipl_member_get(v_node, key);
  if (v.kind == AIPL_INT && v.i >= 0) {
    aipl_member_set_val(v_node, key, aipl_int(v.i + off));
  }
}

AiplVal aipl_merge_arenas(AiplVal v_rootModName, AiplVal v_arenasArr, AiplVal v_lineOffsetsArr) {
  AiplArray* arenas = (v_arenasArr.kind == AIPL_ARRAY) ? (AiplArray*)v_arenasArr.ptr : NULL;
  AiplArray* lineOffs = (v_lineOffsetsArr.kind == AIPL_ARRAY) ? (AiplArray*)v_lineOffsetsArr.ptr : NULL;
  int64_t M = arenas ? arenas->len : 0;
  int64_t totalTypes = 0, totalExprs = 0, totalStmts = 0, totalDecls = 0, totalTop = 0, totalErrs = 0;
  for (int64_t m = 0; m < M; m++) {
    AiplVal ar = arenas->data[m];
    if (!aipl_is_struct_or_map(ar)) continue;
    AiplVal vt = aipl_member_get(ar, "types");
    AiplVal ve = aipl_member_get(ar, "exprs");
    AiplVal vs = aipl_member_get(ar, "stmts");
    AiplVal vd = aipl_member_get(ar, "decls");
    AiplVal vtop = aipl_member_get(ar, "topStmts");
    AiplVal verr = aipl_member_get(ar, "errors");
    if (vt.kind == AIPL_ARRAY && vt.ptr) totalTypes += ((AiplArray*)vt.ptr)->len;
    if (ve.kind == AIPL_ARRAY && ve.ptr) totalExprs += ((AiplArray*)ve.ptr)->len;
    if (vs.kind == AIPL_ARRAY && vs.ptr) totalStmts += ((AiplArray*)vs.ptr)->len;
    if (vd.kind == AIPL_ARRAY && vd.ptr) totalDecls += ((AiplArray*)vd.ptr)->len;
    if (vtop.kind == AIPL_ARRAY && vtop.ptr) totalTop += ((AiplArray*)vtop.ptr)->len;
    if (verr.kind == AIPL_ARRAY && verr.ptr) totalErrs += ((AiplArray*)verr.ptr)->len;
  }

  AiplVal outTypes = aipl_array_with_cap(totalTypes > 0 ? totalTypes : 8);
  AiplVal outExprs = aipl_array_with_cap(totalExprs > 0 ? totalExprs : 8);
  AiplVal outStmts = aipl_array_with_cap(totalStmts > 0 ? totalStmts : 8);
  AiplVal outDecls = aipl_array_with_cap(totalDecls > 0 ? totalDecls : 8);
  AiplVal outTop   = aipl_array_with_cap(totalTop > 0 ? totalTop : 8);
  AiplVal outErrs  = aipl_array_with_cap(totalErrs > 0 ? totalErrs : 8);

  int64_t typeOff = 0, exprOff = 0, stmtOff = 0, declOff = 0;
  for (int64_t m = 0; m < M; m++) {
    AiplVal ar = arenas->data[m];
    if (!aipl_is_struct_or_map(ar)) continue;
    int64_t lineOff = 0;
    if (lineOffs && m < lineOffs->len && lineOffs->data[m].kind == AIPL_INT) {
      lineOff = lineOffs->data[m].i;
    }

    AiplVal vt = aipl_member_get(ar, "types");
    AiplVal ve = aipl_member_get(ar, "exprs");
    AiplVal vs = aipl_member_get(ar, "stmts");
    AiplVal vd = aipl_member_get(ar, "decls");
    AiplVal vtop = aipl_member_get(ar, "topStmts");
    AiplVal verr = aipl_member_get(ar, "errors");

    AiplArray* at = (vt.kind == AIPL_ARRAY) ? (AiplArray*)vt.ptr : NULL;
    AiplArray* ae = (ve.kind == AIPL_ARRAY) ? (AiplArray*)ve.ptr : NULL;
    AiplArray* as = (vs.kind == AIPL_ARRAY) ? (AiplArray*)vs.ptr : NULL;
    AiplArray* ad = (vd.kind == AIPL_ARRAY) ? (AiplArray*)vd.ptr : NULL;
    AiplArray* atop = (vtop.kind == AIPL_ARRAY) ? (AiplArray*)vtop.ptr : NULL;
    AiplArray* aerr = (verr.kind == AIPL_ARRAY) ? (AiplArray*)verr.ptr : NULL;

    int64_t nt = at ? at->len : 0;
    int64_t ne = ae ? ae->len : 0;
    int64_t ns = as ? as->len : 0;
    int64_t nd = ad ? ad->len : 0;
    int64_t ntop = atop ? atop->len : 0;
    int64_t nerr = aerr ? aerr->len : 0;

    for (int64_t i = 0; i < nt; i++) {
      AiplVal tn = at->data[i];
      if ((m > 0 || lineOff != 0) && aipl_is_struct_or_map(tn)) {
        aipl_offset_int_field(tn, "id", typeOff);
        aipl_offset_int_array_field(tn, "typeArgs", typeOff);
        aipl_offset_int_field(tn, "refinePredExpr", exprOff);
        aipl_offset_span_line(tn, lineOff);
      }
      aipl_array_push(outTypes, tn);
    }

    for (int64_t i = 0; i < ne; i++) {
      AiplVal en = ae->data[i];
      if ((m > 0 || lineOff != 0) && aipl_is_struct_or_map(en)) {
        aipl_offset_int_field(en, "id", exprOff);
        aipl_offset_int_field(en, "left", exprOff);
        aipl_offset_int_field(en, "right", exprOff);
        aipl_offset_int_field(en, "cond", exprOff);
        aipl_offset_int_field(en, "typeId", typeOff);
        aipl_offset_span_line(en, lineOff);

        AiplVal v_kind = aipl_member_get(en, "kind");
        const char* ks = (v_kind.kind == AIPL_STR && v_kind.s) ? v_kind.s : "";
        bool children_are_stmts = (strcmp(ks, "DoBlock") == 0 || strcmp(ks, "BlockIfExpr") == 0);
        aipl_offset_int_array_field(en, "children", children_are_stmts ? stmtOff : exprOff);

        if (strcmp(ks, "MatchExpr") == 0 && exprOff > 0) {
          AiplVal v_names = aipl_member_get(en, "names");
          if (v_names.kind == AIPL_ARRAY && v_names.ptr) {
            AiplArray* anames = (AiplArray*)v_names.ptr;
            for (int64_t k = 0; k < anames->len; k++) {
              AiplVal vn = anames->data[k];
              if (vn.kind == AIPL_STR && vn.s) {
                const char* q = strchr(vn.s, '?');
                if (q && q[1] >= '0' && q[1] <= '9') {
                  int64_t old_gid = strtoll(q + 1, NULL, 10);
                  int64_t new_gid = old_gid + exprOff;
                  size_t prefix_len = (size_t)(q - vn.s) + 1;
                  char* nbuf = (char*)malloc(prefix_len + 32);
                  memcpy(nbuf, vn.s, prefix_len);
                  snprintf(nbuf + prefix_len, 32, "%lld", (long long)new_gid);
                  anames->data[k] = aipl_str(nbuf);
                  free(nbuf);
                }
              }
            }
          }
        }
      }
      aipl_array_push(outExprs, en);
    }

    for (int64_t i = 0; i < ns; i++) {
      AiplVal sn = as->data[i];
      if ((m > 0 || lineOff != 0) && aipl_is_struct_or_map(sn)) {
        aipl_offset_int_field(sn, "id", stmtOff);
        aipl_offset_int_field(sn, "typeId", typeOff);
        aipl_offset_int_field(sn, "exprId", exprOff);
        aipl_offset_int_field(sn, "condExpr", exprOff);
        aipl_offset_int_array_field(sn, "bodyStmts", stmtOff);
        aipl_offset_int_array_field(sn, "elseStmts", stmtOff);
        aipl_offset_int_array_field(sn, "matchArms", stmtOff);
        aipl_offset_span_line(sn, lineOff);
      }
      aipl_array_push(outStmts, sn);
    }

    for (int64_t i = 0; i < nd; i++) {
      AiplVal dn = ad->data[i];
      if ((m > 0 || lineOff != 0) && aipl_is_struct_or_map(dn)) {
        aipl_offset_int_field(dn, "id", declOff);
        aipl_offset_int_array_field(dn, "paramTypes", typeOff);
        aipl_offset_int_field(dn, "retType", typeOff);
        aipl_offset_int_array_field(dn, "fieldTypes", typeOff);
        aipl_offset_int_array_field(dn, "requiresExprs", exprOff);
        aipl_offset_int_array_field(dn, "ensuresExprs", exprOff);
        aipl_offset_span_line(dn, lineOff);

        AiplVal v_kind = aipl_member_get(dn, "kind");
        const char* ks = (v_kind.kind == AIPL_STR && v_kind.s) ? v_kind.s : "";
        if (strcmp(ks, "Enum") == 0) {
          aipl_offset_int_array_field(dn, "variantPayloadTypes", typeOff);
        } else {
          aipl_offset_int_array_field(dn, "variantPayloadTypes", exprOff);
        }
        if (strcmp(ks, "Const") == 0) {
          aipl_offset_int_array_field(dn, "bodyStmts", exprOff);
        } else {
          aipl_offset_int_array_field(dn, "bodyStmts", stmtOff);
        }
      }
      aipl_array_push(outDecls, dn);
    }

    for (int64_t i = 0; i < ntop; i++) {
      AiplVal tid = atop->data[i];
      if (m > 0 && tid.kind == AIPL_INT && tid.i >= 0) {
        tid.i += stmtOff;
      }
      aipl_array_push(outTop, tid);
    }

    for (int64_t i = 0; i < nerr; i++) {
      AiplVal ev = aerr->data[i];
      if (lineOff != 0 && ev.kind == AIPL_STR && ev.s && strncmp(ev.s, "line ", 5) == 0) {
        char* endp = NULL;
        long long lnum = strtoll(ev.s + 5, &endp, 10);
        if (endp && endp > ev.s + 5 && *endp == ':') {
          size_t rest_len = strlen(endp);
          char* ebuf = (char*)malloc(rest_len + 48);
          snprintf(ebuf, rest_len + 48, "line %lld%s", lnum + (long long)lineOff, endp);
          ev = aipl_str(ebuf);
          free(ebuf);
        }
      }
      aipl_array_push(outErrs, ev);
    }

    typeOff += nt;
    exprOff += ne;
    stmtOff += ns;
    declOff += nd;
  }

  const char* arena_names[7] = { "moduleName", "types", "exprs", "stmts", "decls", "topStmts", "errors" };
  AiplVal arena_vals[7] = {
    (v_rootModName.kind == AIPL_STR) ? v_rootModName : aipl_str_lit("Main"),
    outTypes,
    outExprs,
    outStmts,
    outDecls,
    outTop,
    outErrs
  };
  return aipl_struct_new("AstArena", 7, arena_names, arena_vals);
}

static uint64_t aipl_fnv1a64_str(const char* s) {
  uint64_t h = 14695981039346656037ULL;
  if (!s) return h;
  while (*s) {
    h ^= (uint8_t)(*s++);
    h *= 1099511628211ULL;
  }
  return h;
}

static uint64_t aipl_frontend_version_salt(void) {
  static uint64_t cached_salt = 0;
  if (cached_salt != 0) return cached_salt;
  uint64_t h = 0xA191001920261026ULL;
  const char* files[3] = { "compiler/ast.aipl", "compiler/lexer.aipl", "compiler/parser.aipl" };
  const char* prefixes[3] = { "", "../", "../../" };
  for (int p = 0; p < 3; p++) {
    char probe[128];
    snprintf(probe, sizeof(probe), "%s%s", prefixes[p], files[0]);
    struct stat st0;
    if (stat(probe, &st0) == 0) {
      for (int i = 0; i < 3; i++) {
        snprintf(probe, sizeof(probe), "%s%s", prefixes[p], files[i]);
        struct stat st;
        if (stat(probe, &st) == 0) {
          h ^= (uint64_t)st.st_size;
          h *= 1099511628211ULL;
          h ^= (uint64_t)st.st_mtime;
          h *= 1099511628211ULL;
        }
      }
      break;
    }
  }
  if (h == 0) h = 1;
  cached_salt = h;
  return h;
}

static const char* aipl_resolve_frontend_cache_dir(void) {
  struct stat st;
  if (stat(".aipl", &st) == 0 && S_ISDIR(st.st_mode)) {
#ifdef _WIN32
    _mkdir(".aipl/cache");
    _mkdir(".aipl/cache/v1");
#else
    mkdir(".aipl/cache", 0755);
    mkdir(".aipl/cache/v1", 0755);
#endif
    return ".aipl/cache/v1";
  }
  if (stat("../.aipl", &st) == 0 && S_ISDIR(st.st_mode)) {
#ifdef _WIN32
    _mkdir("../.aipl/cache");
    _mkdir("../.aipl/cache/v1");
#else
    mkdir("../.aipl/cache", 0755);
    mkdir("../.aipl/cache/v1", 0755);
#endif
    return "../.aipl/cache/v1";
  }
  if (stat("../../.aipl", &st) == 0 && S_ISDIR(st.st_mode)) {
#ifdef _WIN32
    _mkdir("../../.aipl/cache");
    _mkdir("../../.aipl/cache/v1");
#else
    mkdir("../../.aipl/cache", 0755);
    mkdir("../../.aipl/cache/v1", 0755);
#endif
    return "../../.aipl/cache/v1";
  }
#ifdef _WIN32
  _mkdir(".aipl");
  _mkdir(".aipl/cache");
  _mkdir(".aipl/cache/v1");
#else
  mkdir(".aipl", 0755);
  mkdir(".aipl/cache", 0755);
  mkdir(".aipl/cache/v1", 0755);
#endif
  return ".aipl/cache/v1";
}

AiplVal aipl_rt_parallel_frontend(
    AiplVal v_chunks,
    AiplVal v_lineOffsets,
    AiplVal v_rootModName,
    AiplVal (*fn_parse_chunk)(AiplVal, AiplVal)) {
  AiplArray* chunks = (v_chunks.kind == AIPL_ARRAY) ? (AiplArray*)v_chunks.ptr : NULL;
  int64_t M = chunks ? chunks->len : 0;
  if (M <= 0) {
    return aipl_merge_arenas(v_rootModName, aipl_array_with_cap(0), v_lineOffsets);
  }
  const char* cache_dir = aipl_resolve_frontend_cache_dir();
  uint64_t ver_salt = aipl_frontend_version_salt();

  AiplVal v_arenas = aipl_array_with_cap(M);
  AiplArray* arenas = (AiplArray*)v_arenas.ptr;
  arenas->len = M;
  int64_t* uncached_idx = (int64_t*)malloc(sizeof(int64_t) * (size_t)M);
  char (*cache_paths)[256] = (char (*)[256])malloc(256 * (size_t)M);
  int64_t uncached_cnt = 0;

  for (int64_t m = 0; m < M; m++) {
    AiplVal vc = chunks->data[m];
    const char* src = (vc.kind == AIPL_STR && vc.s) ? vc.s : "";
    uint64_t h1 = aipl_fnv1a64_str(src) ^ ver_salt;
    uint64_t slen = (uint64_t)strlen(src);
    snprintf(cache_paths[m], 256, "%s/mod_%016llx_%llx.hir",
             cache_dir, (unsigned long long)h1, (unsigned long long)slen);
    AiplVal ar = aipl_nil();
    if (aipl_cache_read_arena(cache_paths[m], &ar)) {
      arenas->data[m] = ar;
    } else {
      arenas->data[m] = aipl_nil();
      uncached_idx[uncached_cnt++] = m;
    }
  }

  if (uncached_cnt == 1) {
    int64_t m = uncached_idx[0];
    AiplVal ar = fn_parse_chunk(chunks->data[m], aipl_int(0));
    arenas->data[m] = ar;
    aipl_cache_write_arena(cache_paths[m], ar);
  } else if (uncached_cnt > 1) {
#ifndef _WIN32
    int64_t cpus = aipl_rt_hardware_concurrency().i;
    int64_t workers = uncached_cnt < cpus ? uncached_cnt : cpus;
    if (workers < 1) workers = 1;
    if (workers > 64) workers = 64;
    pid_t pids[64];
    fflush(NULL);
    for (int64_t w = 0; w < workers; w++) {
      pid_t pid = fork();
      if (pid == 0) {
        for (int64_t u = w; u < uncached_cnt; u += workers) {
          int64_t m = uncached_idx[u];
          AiplVal ar = fn_parse_chunk(chunks->data[m], aipl_int(0));
          aipl_cache_write_arena(cache_paths[m], ar);
        }
        _exit(0);
      }
      pids[w] = pid;
    }
    for (int64_t w = 0; w < workers; w++) {
      if (pids[w] > 0) {
        int st = 0;
        waitpid(pids[w], &st, 0);
      }
    }
    for (int64_t u = 0; u < uncached_cnt; u++) {
      int64_t m = uncached_idx[u];
      AiplVal ar = aipl_nil();
      if (aipl_cache_read_arena(cache_paths[m], &ar)) {
        arenas->data[m] = ar;
      } else {
        ar = fn_parse_chunk(chunks->data[m], aipl_int(0));
        arenas->data[m] = ar;
        aipl_cache_write_arena(cache_paths[m], ar);
      }
    }
#else
    for (int64_t u = 0; u < uncached_cnt; u++) {
      int64_t m = uncached_idx[u];
      AiplVal ar = fn_parse_chunk(chunks->data[m], aipl_int(0));
      arenas->data[m] = ar;
      aipl_cache_write_arena(cache_paths[m], ar);
    }
#endif
  }

  free(uncached_idx);
  free(cache_paths);
  return aipl_merge_arenas(v_rootModName, v_arenas, v_lineOffsets);
}

AiplVal aipl_rt_parallel_optimize_hir(
    AiplVal v_hir,
    AiplVal (*fn_opt_stride)(AiplVal, AiplVal, AiplVal)) {
  if (!aipl_is_struct_or_map(v_hir)) return v_hir;
#ifdef _WIN32
  return fn_opt_stride(v_hir, aipl_int(0), aipl_int(1));
#else
  AiplVal v_funcs = aipl_member_get(v_hir, "functions");
  AiplArray* funcs = (v_funcs.kind == AIPL_ARRAY) ? (AiplArray*)v_funcs.ptr : NULL;
  int64_t nfuncs = funcs ? funcs->len : 0;
  int64_t cpus = aipl_rt_hardware_concurrency().i;
  if (nfuncs < 16 || cpus <= 1) {
    return fn_opt_stride(v_hir, aipl_int(0), aipl_int(1));
  }
  int64_t workers = nfuncs < cpus ? nfuncs : cpus;
  if (workers > 4) workers = 4;

  AiplVal v_arena = aipl_member_get(v_hir, "arena");
  AiplVal v_exprs = aipl_member_get(v_arena, "exprs");
  AiplVal v_stmts = aipl_member_get(v_arena, "stmts");
  AiplArray* exprs = (v_exprs.kind == AIPL_ARRAY) ? (AiplArray*)v_exprs.ptr : NULL;
  AiplArray* stmts = (v_stmts.kind == AIPL_ARRAY) ? (AiplArray*)v_stmts.ptr : NULL;
  int64_t orig_ne = exprs ? exprs->len : 0;
  int64_t orig_ns = stmts ? stmts->len : 0;

  static int opt_seq = 0;
  int cur_seq = ++opt_seq;
  pid_t self_pid = getpid();
  char part_paths[64][256];
  pid_t pids[64];

  fflush(NULL);
  for (int64_t w = 0; w < workers; w++) {
    snprintf(part_paths[w], sizeof(part_paths[w]), "/tmp/aipl_opt_%d_%d_%lld.part",
             (int)self_pid, cur_seq, (long long)w);
    pid_t pid = fork();
    if (pid == 0) {
      void** orig_e_ptrs = (void**)malloc(sizeof(void*) * (size_t)(orig_ne > 0 ? orig_ne : 1));
      void** orig_s_ptrs = (void**)malloc(sizeof(void*) * (size_t)(orig_ns > 0 ? orig_ns : 1));
      for (int64_t i = 0; i < orig_ne; i++) orig_e_ptrs[i] = exprs->data[i].ptr;
      for (int64_t i = 0; i < orig_ns; i++) orig_s_ptrs[i] = stmts->data[i].ptr;

      AiplVal res_hir = fn_opt_stride(v_hir, aipl_int(w), aipl_int(workers));
      AiplVal r_arena = aipl_member_get(res_hir, "arena");
      AiplVal r_exprs = aipl_member_get(r_arena, "exprs");
      AiplVal r_stmts = aipl_member_get(r_arena, "stmts");
      AiplVal r_funcs = aipl_member_get(res_hir, "functions");
      AiplArray* re = (r_exprs.kind == AIPL_ARRAY) ? (AiplArray*)r_exprs.ptr : NULL;
      AiplArray* rs = (r_stmts.kind == AIPL_ARRAY) ? (AiplArray*)r_stmts.ptr : NULL;
      AiplArray* rf = (r_funcs.kind == AIPL_ARRAY) ? (AiplArray*)r_funcs.ptr : NULL;

      FILE* fp = fopen(part_paths[w], "wb");
      if (fp && re && rs && rf) {
        uint32_t mod_e_cnt = 0;
        for (int64_t i = 0; i < orig_ne; i++) {
          if (re->data[i].ptr != orig_e_ptrs[i]) mod_e_cnt++;
        }
        fwrite(&mod_e_cnt, sizeof(uint32_t), 1, fp);
        for (int64_t i = 0; i < orig_ne; i++) {
          if (re->data[i].ptr != orig_e_ptrs[i]) {
            uint32_t idx = (uint32_t)i;
            fwrite(&idx, sizeof(uint32_t), 1, fp);
            aipl_val_write_bin(fp, re->data[i]);
          }
        }

        uint32_t mod_s_cnt = 0;
        for (int64_t i = 0; i < orig_ns; i++) {
          if (rs->data[i].ptr != orig_s_ptrs[i]) mod_s_cnt++;
        }
        fwrite(&mod_s_cnt, sizeof(uint32_t), 1, fp);
        for (int64_t i = 0; i < orig_ns; i++) {
          if (rs->data[i].ptr != orig_s_ptrs[i]) {
            uint32_t idx = (uint32_t)i;
            fwrite(&idx, sizeof(uint32_t), 1, fp);
            aipl_val_write_bin(fp, rs->data[i]);
          }
        }

        uint32_t fn_cnt = 0;
        for (int64_t fi = w; fi < nfuncs; fi += workers) fn_cnt++;
        fwrite(&fn_cnt, sizeof(uint32_t), 1, fp);
        for (int64_t fi = w; fi < nfuncs; fi += workers) {
          uint32_t idx = (uint32_t)fi;
          fwrite(&idx, sizeof(uint32_t), 1, fp);
          aipl_val_write_bin(fp, rf->data[fi]);
        }
        fclose(fp);
      }
      _exit(0);
    }
    pids[w] = pid;
  }

  bool any_failed = false;
  for (int64_t w = 0; w < workers; w++) {
    if (pids[w] > 0) {
      int st = 0;
      waitpid(pids[w], &st, 0);
      if (!WIFEXITED(st) || WEXITSTATUS(st) != 0) any_failed = true;
    } else {
      any_failed = true;
    }
  }

  if (any_failed) {
    for (int64_t w = 0; w < workers; w++) unlink(part_paths[w]);
    return fn_opt_stride(v_hir, aipl_int(0), aipl_int(1));
  }

  for (int64_t w = 0; w < workers; w++) {
    FILE* fp = fopen(part_paths[w], "rb");
    if (fp) {
      uint32_t mod_e_cnt = 0;
      if (fread(&mod_e_cnt, sizeof(uint32_t), 1, fp) == 1) {
        for (uint32_t k = 0; k < mod_e_cnt; k++) {
          uint32_t idx = 0;
          if (fread(&idx, sizeof(uint32_t), 1, fp) != 1) break;
          bool ok = true;
          AiplVal ev = aipl_val_read_bin_checked(fp, &ok);
          if (!ok) break;
          if (exprs && (int64_t)idx < orig_ne) exprs->data[idx] = ev;
        }
      }
      uint32_t mod_s_cnt = 0;
      if (fread(&mod_s_cnt, sizeof(uint32_t), 1, fp) == 1) {
        for (uint32_t k = 0; k < mod_s_cnt; k++) {
          uint32_t idx = 0;
          if (fread(&idx, sizeof(uint32_t), 1, fp) != 1) break;
          bool ok = true;
          AiplVal sv = aipl_val_read_bin_checked(fp, &ok);
          if (!ok) break;
          if (stmts && (int64_t)idx < orig_ns) stmts->data[idx] = sv;
        }
      }
      uint32_t fn_cnt = 0;
      if (fread(&fn_cnt, sizeof(uint32_t), 1, fp) == 1) {
        for (uint32_t k = 0; k < fn_cnt; k++) {
          uint32_t idx = 0;
          if (fread(&idx, sizeof(uint32_t), 1, fp) != 1) break;
          bool ok = true;
          AiplVal fv = aipl_val_read_bin_checked(fp, &ok);
          if (!ok) break;
          if (funcs && (int64_t)idx < nfuncs) funcs->data[idx] = fv;
        }
      }
      fclose(fp);
    }
    unlink(part_paths[w]);
  }

  return v_hir;
#endif
}

AiplVal aipl_rt_parallel_typecheck(
    AiplVal v_hir,
    AiplVal v_fnTypes,
    AiplVal v_funcs,
    AiplVal v_diags,
    AiplVal (*fn_tc_stride)(AiplVal, AiplVal, AiplVal, AiplVal)) {
  AiplArray* funcs = (v_funcs.kind == AIPL_ARRAY) ? (AiplArray*)v_funcs.ptr : NULL;
  int64_t nfuncs = funcs ? funcs->len : 0;
  int64_t cpus = aipl_rt_hardware_concurrency().i;
#ifdef _WIN32
  (void)nfuncs;
  (void)cpus;
  AiplVal sub = fn_tc_stride(v_hir, v_fnTypes, aipl_int(0), aipl_int(1));
  if (sub.kind == AIPL_ARRAY && sub.ptr && v_diags.kind == AIPL_ARRAY && v_diags.ptr) {
    AiplArray* asub = (AiplArray*)sub.ptr;
    for (int64_t i = 0; i < asub->len; i++) aipl_array_push(v_diags, asub->data[i]);
  }
  return v_diags;
#else
  if (nfuncs < 16 || cpus <= 1) {
    AiplVal sub = fn_tc_stride(v_hir, v_fnTypes, aipl_int(0), aipl_int(1));
    if (sub.kind == AIPL_ARRAY && sub.ptr && v_diags.kind == AIPL_ARRAY && v_diags.ptr) {
      AiplArray* asub = (AiplArray*)sub.ptr;
      for (int64_t i = 0; i < asub->len; i++) aipl_array_push(v_diags, asub->data[i]);
    }
    return v_diags;
  }

  int64_t workers = nfuncs < cpus ? nfuncs : cpus;
  if (workers > 4) workers = 4;
  static int tc_seq = 0;
  int cur_seq = ++tc_seq;
  pid_t self_pid = getpid();
  char part_paths[64][256];
  pid_t pids[64];

  fflush(NULL);
  for (int64_t w = 0; w < workers; w++) {
    snprintf(part_paths[w], sizeof(part_paths[w]), "/tmp/aipl_tc_%d_%d_%lld.part",
             (int)self_pid, cur_seq, (long long)w);
    pid_t pid = fork();
    if (pid == 0) {
      AiplVal sub = fn_tc_stride(v_hir, v_fnTypes, aipl_int(w), aipl_int(workers));
      if (sub.kind == AIPL_ARRAY && sub.ptr && ((AiplArray*)sub.ptr)->len > 0) {
        FILE* fp = fopen(part_paths[w], "wb");
        if (fp) {
          aipl_val_write_bin(fp, sub);
          fclose(fp);
        }
      }
      _exit(0);
    }
    pids[w] = pid;
  }

  for (int64_t w = 0; w < workers; w++) {
    if (pids[w] > 0) {
      int st = 0;
      waitpid(pids[w], &st, 0);
    }
  }

  for (int64_t w = 0; w < workers; w++) {
    FILE* fp = fopen(part_paths[w], "rb");
    if (fp) {
      bool ok = true;
      AiplVal sub = aipl_val_read_bin_checked(fp, &ok);
      fclose(fp);
      unlink(part_paths[w]);
      if (ok && sub.kind == AIPL_ARRAY && sub.ptr && v_diags.kind == AIPL_ARRAY && v_diags.ptr) {
        AiplArray* asub = (AiplArray*)sub.ptr;
        for (int64_t i = 0; i < asub->len; i++) {
          aipl_array_push(v_diags, asub->data[i]);
        }
      }
    }
  }

  return v_diags;
#endif
}

static void aipl_append_smt_diags_to_violations(AiplVal v_diags, AiplVal v_violations) {
  if (v_diags.kind != AIPL_ARRAY || !v_diags.ptr || v_violations.kind != AIPL_ARRAY || !v_violations.ptr) return;
  AiplArray* adiags = (AiplArray*)v_diags.ptr;
  const char* sv_names[4] = { "code", "message", "counterexample", "span" };
  for (int64_t i = 0; i < adiags->len; i++) {
    AiplVal d = adiags->data[i];
    if (aipl_is_struct_or_map(d)) {
      AiplVal sv_vals[4] = {
        aipl_member_get(d, "code"),
        aipl_member_get(d, "message"),
        aipl_str_lit(""),
        aipl_member_get(d, "span")
      };
      AiplVal sv = aipl_struct_new("SmtViolation", 4, sv_names, sv_vals);
      aipl_array_push(v_violations, sv);
    }
  }
}

AiplVal aipl_rt_parallel_smt(
    AiplVal v_arena,
    AiplVal v_hir,
    AiplVal v_contractTable,
    AiplVal v_funcs,
    AiplVal v_violations,
    AiplVal (*fn_smt_stride)(AiplVal, AiplVal, AiplVal)) {
  (void)v_arena;
  (void)v_contractTable;
  AiplArray* funcs = (v_funcs.kind == AIPL_ARRAY) ? (AiplArray*)v_funcs.ptr : NULL;
  int64_t nfuncs = funcs ? funcs->len : 0;
  int64_t cpus = aipl_rt_hardware_concurrency().i;
#ifdef _WIN32
  (void)nfuncs;
  (void)cpus;
  AiplVal res = fn_smt_stride(v_hir, aipl_int(0), aipl_int(1));
  if (aipl_is_struct_or_map(res)) {
    aipl_append_smt_diags_to_violations(aipl_member_get(res, "diagnostics"), v_violations);
  }
  return v_violations;
#else
  if (nfuncs < 16 || cpus <= 1) {
    AiplVal res = fn_smt_stride(v_hir, aipl_int(0), aipl_int(1));
    if (aipl_is_struct_or_map(res)) {
      aipl_append_smt_diags_to_violations(aipl_member_get(res, "diagnostics"), v_violations);
    }
    return v_violations;
  }

  int64_t workers = nfuncs < cpus ? nfuncs : cpus;
  if (workers > 4) workers = 4;
  static int smt_seq = 0;
  int cur_seq = ++smt_seq;
  pid_t self_pid = getpid();
  char part_paths[64][256];
  pid_t pids[64];

  fflush(NULL);
  for (int64_t w = 0; w < workers; w++) {
    snprintf(part_paths[w], sizeof(part_paths[w]), "/tmp/aipl_smt_%d_%d_%lld.part",
             (int)self_pid, cur_seq, (long long)w);
    pid_t pid = fork();
    if (pid == 0) {
      AiplVal res = fn_smt_stride(v_hir, aipl_int(w), aipl_int(workers));
      if (aipl_is_struct_or_map(res)) {
        AiplVal diags = aipl_member_get(res, "diagnostics");
        if (diags.kind == AIPL_ARRAY && diags.ptr && ((AiplArray*)diags.ptr)->len > 0) {
          FILE* fp = fopen(part_paths[w], "wb");
          if (fp) {
            aipl_val_write_bin(fp, diags);
            fclose(fp);
          }
        }
      }
      _exit(0);
    }
    pids[w] = pid;
  }

  for (int64_t w = 0; w < workers; w++) {
    if (pids[w] > 0) {
      int st = 0;
      waitpid(pids[w], &st, 0);
    }
  }

  for (int64_t w = 0; w < workers; w++) {
    FILE* fp = fopen(part_paths[w], "rb");
    if (fp) {
      bool ok = true;
      AiplVal diags = aipl_val_read_bin_checked(fp, &ok);
      fclose(fp);
      unlink(part_paths[w]);
      if (ok) aipl_append_smt_diags_to_violations(diags, v_violations);
    }
  }

  return v_violations;
#endif
}

AiplVal aipl_rt_parallel_test_prepare(
    AiplVal v_files,
    AiplVal v_tmpCs,
    AiplVal v_cpus,
    AiplVal (*fn_prep_one)(AiplVal, AiplVal)) {
  AiplArray* files = (v_files.kind == AIPL_ARRAY) ? (AiplArray*)v_files.ptr : NULL;
  AiplArray* tmpCs = (v_tmpCs.kind == AIPL_ARRAY) ? (AiplArray*)v_tmpCs.ptr : NULL;
  int64_t n = (files && tmpCs && files->len <= tmpCs->len) ? files->len : 0;
  AiplVal out = aipl_array_with_cap(n > 0 ? n : 4);
  if (n <= 0) return out;
  int64_t cpus = (v_cpus.kind == AIPL_INT && v_cpus.i > 0) ? v_cpus.i : aipl_rt_hardware_concurrency().i;
#ifdef _WIN32
  (void)cpus;
  for (int64_t i = 0; i < n; i++) {
    AiplVal ok = fn_prep_one(files->data[i], tmpCs->data[i]);
    aipl_array_push(out, ok);
  }
  return out;
#else
  if (n == 1 || cpus <= 1) {
    for (int64_t i = 0; i < n; i++) {
      AiplVal ok = fn_prep_one(files->data[i], tmpCs->data[i]);
      aipl_array_push(out, ok);
    }
    return out;
  }

  int64_t workers = n < cpus ? n : cpus;
  if (workers > 4) workers = 4;
  pid_t pids[16];
  fflush(NULL);
  for (int64_t w = 0; w < workers; w++) {
    pid_t pid = fork();
    if (pid == 0) {
      for (int64_t i = w; i < n; i += workers) {
        fn_prep_one(files->data[i], tmpCs->data[i]);
      }
      _exit(0);
    }
    pids[w] = pid;
  }
  for (int64_t w = 0; w < workers; w++) {
    if (pids[w] > 0) {
      int st = 0;
      waitpid(pids[w], &st, 0);
    }
  }
  for (int64_t i = 0; i < n; i++) {
    AiplVal tc = tmpCs->data[i];
    bool exists = (tc.kind == AIPL_STR && tc.s && access(tc.s, F_OK) == 0);
    if (!exists) {
      fn_prep_one(files->data[i], tmpCs->data[i]);
      exists = (tc.kind == AIPL_STR && tc.s && access(tc.s, F_OK) == 0);
    }
    aipl_array_push(out, aipl_bool(exists));
  }
  return out;
#endif
}

/* ============================================================================
 * Android NDK ALooper & AInputQueue Multi-Touch Event Translator
 * Step 21.3: Motion Event Decoding & Input Queue Pump
 * ============================================================================ */
#ifdef __ANDROID__
#include <android/input.h>
#include <android/looper.h>

typedef struct {
  int actionMasked;
  int pointerIndex;
  int pointerId;
  float x;
  float y;
  float pressure;
  int64_t eventTimeMs;
  int isValid;
} AiplAndroidTouchEvent;

int aipl_rt_android_decode_motion_action(int actionWithIndex, int pointerCount, int* outMasked, int* outPointerIndex) {
  if (actionWithIndex < 0 || pointerCount <= 0) return 0;
  int masked = actionWithIndex & 0xff;
  int ptrIdx = (actionWithIndex >> 8) & 0xff;
  int known = (masked == AMOTION_EVENT_ACTION_DOWN ||
               masked == AMOTION_EVENT_ACTION_UP ||
               masked == AMOTION_EVENT_ACTION_MOVE ||
               masked == AMOTION_EVENT_ACTION_CANCEL ||
               masked == AMOTION_EVENT_ACTION_POINTER_DOWN ||
               masked == AMOTION_EVENT_ACTION_POINTER_UP);
  if (!known || ptrIdx < 0 || ptrIdx >= pointerCount) return 0;
  if (outMasked) *outMasked = masked;
  if (outPointerIndex) *outPointerIndex = ptrIdx;
  return 1;
}

int aipl_rt_android_poll_input_events(AInputQueue* inputQueue, AiplAndroidTouchEvent* outEvents, int maxEvents) {
  if (!inputQueue || !outEvents || maxEvents <= 0) return 0;
  AInputEvent* event = NULL;
  int count = 0;
  while (count < maxEvents && AInputQueue_getEvent(inputQueue, &event) >= 0) {
    if (AInputQueue_preDispatchEvent(inputQueue, event)) continue;
    int32_t handled = 0;
    int32_t eventType = AInputEvent_getType(event);
    if (eventType == AINPUT_EVENT_TYPE_MOTION) {
      int32_t rawAction = AMotionEvent_getAction(event);
      size_t ptrCount = AMotionEvent_getPointerCount(event);
      int masked = 0, ptrIdx = 0;
      if (aipl_rt_android_decode_motion_action(rawAction, (int)ptrCount, &masked, &ptrIdx)) {
        if (masked == AMOTION_EVENT_ACTION_MOVE) {
          for (size_t p = 0; p < ptrCount && count < maxEvents; p++) {
            AiplAndroidTouchEvent* te = &outEvents[count++];
            te->actionMasked = masked;
            te->pointerIndex = (int)p;
            te->pointerId = AMotionEvent_getPointerId(event, p);
            te->x = AMotionEvent_getX(event, p);
            te->y = AMotionEvent_getY(event, p);
            te->pressure = AMotionEvent_getPressure(event, p);
            te->eventTimeMs = AMotionEvent_getEventTime(event) / 1000000LL;
            te->isValid = 1;
          }
        } else {
          AiplAndroidTouchEvent* te = &outEvents[count++];
          te->actionMasked = masked;
          te->pointerIndex = ptrIdx;
          te->pointerId = AMotionEvent_getPointerId(event, (size_t)ptrIdx);
          te->x = AMotionEvent_getX(event, (size_t)ptrIdx);
          te->y = AMotionEvent_getY(event, (size_t)ptrIdx);
          te->pressure = AMotionEvent_getPressure(event, (size_t)ptrIdx);
          te->eventTimeMs = AMotionEvent_getEventTime(event) / 1000000LL;
          te->isValid = 1;
        }
        handled = 1;
      }
    }
    AInputQueue_finishEvent(inputQueue, event, handled);
  }
  return count;
}
#endif





