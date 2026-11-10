[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 07: I/O, Filesystem, Concurrency & Networking

> **Chapter Summary**: Buffered stream I/O, directory traversal prevention, CLI subcommand parsing, ANSI terminal UIs, atomics, bounded MPSC channels, work-stealing job DAGs, and TCP/UDP/RUDP/HTTP/WebSocket networking.

## Table of Contents
- [Chapter 07.1: Buffered Streaming I/O, Path Traversal Defense & Filesystem Watchers (std/io/*, std/fs/*)](#chapter-071-buffered-streaming-io-path-traversal-defense--filesystem-watchers-stdio-stdfs)
- [Chapter 07.2: CLI Subcommands, Environment Resolution, Subprocesses & ANSI Terminal UI (std/os/*)](#chapter-072-cli-subcommands-environment-resolution-subprocesses--ansi-terminal-ui-stdos)
- [Chapter 07.3: Atomics, Mutex/RwLock, Bounded MPSC Channels, Stackful Fibers & Work-Stealing Jobs (std/sync/*, std/thread/*)](#chapter-073-atomics-mutexrwlock-bounded-mpsc-channels-stackful-fibers--work-stealing-jobs-stdsync-stdthread)
- [Chapter 07.4: TCP/UDP Sockets, Reliable UDP (rudp), HTTP/1.1, WebSockets & JSON-RPC 2.0 (std/net/*)](#chapter-074-tcpudp-sockets-reliable-udp-rudp-http11-websockets--json-rpc-20-stdnet)

---

### Chapter 07.1: Buffered Streaming I/O, Path Traversal Defense & Filesystem Watchers (std/io/*, std/fs/*)

#### 1. Concept in 30 Seconds
Teach `std/io/buf_io`, `cursor`, `pipe`, `stream` and `std/fs/path`, `file`, `dir`, `metadata`, `watch` with strict `..` traversal rejection.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn unifySlashes(p: str): str:` from `std/fs/path.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.fs.path_z1_test
import * from "std/fs/path"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_path_unifySlashes_1(): int:
  let arg_p = "test"
  let edge_p = "a"
  let resNom = unifySlashes(arg_p)
  let resEdge = unifySlashes(edge_p)
  assertEqStr(resNom, "test", "unifySlashes nominal string matches")
  assertEqStr(resEdge, "a", "unifySlashes boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_097` | [examples/ex_097_io_byte_cursor_binary_parser_cli.aipl](../../examples/ex_097_io_byte_cursor_binary_parser_cli.aipl) | `tests/examples/ex_097_io_byte_cursor_binary_parser_cli_test.aipl` | `./bin/aipl test tests/examples/ex_097_io_byte_cursor_binary_parser_cli_test.aipl` |
| `ex_098` | [examples/ex_098_io_copy_and_stream_pipe_cli.aipl](../../examples/ex_098_io_copy_and_stream_pipe_cli.aipl) | `tests/examples/ex_098_io_copy_and_stream_pipe_cli_test.aipl` | `./bin/aipl test tests/examples/ex_098_io_copy_and_stream_pipe_cli_test.aipl` |
| `ex_099` | [examples/ex_099_fs_path_normalizer_cli.aipl](../../examples/ex_099_fs_path_normalizer_cli.aipl) | `tests/examples/ex_099_fs_path_normalizer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_099_fs_path_normalizer_cli_test.aipl` |
| `ex_100` | [examples/ex_100_fs_file_atomic_write_cli.aipl](../../examples/ex_100_fs_file_atomic_write_cli.aipl) | `tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` | `./bin/aipl test tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` |
| `ex_101` | [examples/ex_101_fs_dir_find_and_tree_cli.aipl](../../examples/ex_101_fs_dir_find_and_tree_cli.aipl) | `tests/examples/ex_101_fs_dir_find_and_tree_cli_test.aipl` | `./bin/aipl test tests/examples/ex_101_fs_dir_find_and_tree_cli_test.aipl` |
| `ex_102` | [examples/ex_102_fs_metadata_stat_du_cli.aipl](../../examples/ex_102_fs_metadata_stat_du_cli.aipl) | `tests/examples/ex_102_fs_metadata_stat_du_cli_test.aipl` | `./bin/aipl test tests/examples/ex_102_fs_metadata_stat_du_cli_test.aipl` |

---

### Chapter 07.2: CLI Subcommands, Environment Resolution, Subprocesses & ANSI Terminal UI (std/os/*)

#### 1. Concept in 30 Seconds
Teach `std/os/cli_args`, `env`, `process`, `signal`, and `tty` for building rich interactive command-line tools.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn cliAppNew(name: str): CliApp:` from `std/os/cli_args.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.os.cli_args_z1_test
import * from "std/os/cli_args"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cli_args_cliAppNew_1(): int:
  let arg_name = "test"
  let edge_name = "a"
  let resNom = cliAppNew(arg_name)
  let resEdge = cliAppNew(edge_name)
  assertEqStr(resNom.name, "test", "cliAppNew nominal string matches")
  assertEqStr(resEdge.name, "a", "cliAppNew boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_104` | [examples/ex_104_os_cli_args_subcommands_cli.aipl](../../examples/ex_104_os_cli_args_subcommands_cli.aipl) | `tests/examples/ex_104_os_cli_args_subcommands_cli_test.aipl` | `./bin/aipl test tests/examples/ex_104_os_cli_args_subcommands_cli_test.aipl` |
| `ex_105` | [examples/ex_105_os_env_config_resolver_cli.aipl](../../examples/ex_105_os_env_config_resolver_cli.aipl) | `tests/examples/ex_105_os_env_config_resolver_cli_test.aipl` | `./bin/aipl test tests/examples/ex_105_os_env_config_resolver_cli_test.aipl` |
| `ex_106` | [examples/ex_106_os_process_pipeline_runner_cli.aipl](../../examples/ex_106_os_process_pipeline_runner_cli.aipl) | `tests/examples/ex_106_os_process_pipeline_runner_cli_test.aipl` | `./bin/aipl test tests/examples/ex_106_os_process_pipeline_runner_cli_test.aipl` |
| `ex_107` | [examples/ex_107_os_signal_graceful_shutdown_cli.aipl](../../examples/ex_107_os_signal_graceful_shutdown_cli.aipl) | `tests/examples/ex_107_os_signal_graceful_shutdown_cli_test.aipl` | `./bin/aipl test tests/examples/ex_107_os_signal_graceful_shutdown_cli_test.aipl` |
| `ex_108` | [examples/ex_108_os_ansi_term_dashboard_cli.aipl](../../examples/ex_108_os_ansi_term_dashboard_cli.aipl) | `tests/examples/ex_108_os_ansi_term_dashboard_cli_test.aipl` | `./bin/aipl test tests/examples/ex_108_os_ansi_term_dashboard_cli_test.aipl` |

---

### Chapter 07.3: Atomics, Mutex/RwLock, Bounded MPSC Channels, Stackful Fibers & Work-Stealing Jobs (std/sync/*, std/thread/*)

#### 1. Concept in 30 Seconds
Teach lock-free `atomic`, `mutex`, `rwlock`, `semaphore`, `channel`, cooperative `fiber`, and DAG `job_system`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn mpscChannelNew(capacity: int): MpscChannel:` from `std/sync/channel.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.sync.channel_z1_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscChannelNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = mpscChannelNew(arg_capacity)
  let resEdge = mpscChannelNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "mpscChannelNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "mpscChannelNew boundary resEdge.capacity == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_109` | [examples/ex_109_os_system_monitor_top_cli.aipl](../../examples/ex_109_os_system_monitor_top_cli.aipl) | `tests/examples/ex_109_os_system_monitor_top_cli_test.aipl` | `./bin/aipl test tests/examples/ex_109_os_system_monitor_top_cli_test.aipl` |
| `ex_110` | [examples/ex_110_sync_atomic_lockfree_counter_cli.aipl](../../examples/ex_110_sync_atomic_lockfree_counter_cli.aipl) | `tests/examples/ex_110_sync_atomic_lockfree_counter_cli_test.aipl` | `./bin/aipl test tests/examples/ex_110_sync_atomic_lockfree_counter_cli_test.aipl` |
| `ex_111` | [examples/ex_111_sync_mutex_shared_ledger_cli.aipl](../../examples/ex_111_sync_mutex_shared_ledger_cli.aipl) | `tests/examples/ex_111_sync_mutex_shared_ledger_cli_test.aipl` | `./bin/aipl test tests/examples/ex_111_sync_mutex_shared_ledger_cli_test.aipl` |
| `ex_112` | [examples/ex_112_sync_rwlock_concurrent_cache_cli.aipl](../../examples/ex_112_sync_rwlock_concurrent_cache_cli.aipl) | `tests/examples/ex_112_sync_rwlock_concurrent_cache_cli_test.aipl` | `./bin/aipl test tests/examples/ex_112_sync_rwlock_concurrent_cache_cli_test.aipl` |
| `ex_113` | [examples/ex_113_sync_barrier_phased_sim_cli.aipl](../../examples/ex_113_sync_barrier_phased_sim_cli.aipl) | `tests/examples/ex_113_sync_barrier_phased_sim_cli_test.aipl` | `./bin/aipl test tests/examples/ex_113_sync_barrier_phased_sim_cli_test.aipl` |
| `ex_114` | [examples/ex_114_sync_channel_mpmc_pipeline_cli.aipl](../../examples/ex_114_sync_channel_mpmc_pipeline_cli.aipl) | `tests/examples/ex_114_sync_channel_mpmc_pipeline_cli_test.aipl` | `./bin/aipl test tests/examples/ex_114_sync_channel_mpmc_pipeline_cli_test.aipl` |

---

### Chapter 07.4: TCP/UDP Sockets, Reliable UDP (rudp), HTTP/1.1, WebSockets & JSON-RPC 2.0 (std/net/*)

#### 1. Concept in 30 Seconds
Teach `addr`, `dns`, `tcp`, `udp`, sequence-acked `rudp`, `http_client`, `http_server`, `websocket`, and `rpc`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn rudpCreateConnection(remote: SocketAddr): RudpConnection:` from `std/net/rudp.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.net.rudp_z1_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpCreateConnection_1(): int:
  let arg_remote = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_remote = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let resNom = rudpCreateConnection(arg_remote)
  let resEdge = rudpCreateConnection(edge_remote)
  assertEqInt(resNom.localSequence, 1, "rudpCreateConnection nominal resNom.localSequence == 1")
  assertEqInt(resEdge.localSequence, 1, "rudpCreateConnection boundary resEdge.localSequence == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_118` | [examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl](../../examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl) | `tests/examples/ex_118_net_addr_cidr_subnet_calc_cli_test.aipl` | `./bin/aipl test tests/examples/ex_118_net_addr_cidr_subnet_calc_cli_test.aipl` |
| `ex_119` | [examples/ex_119_net_tcp_echo_and_framing_cli.aipl](../../examples/ex_119_net_tcp_echo_and_framing_cli.aipl) | `tests/examples/ex_119_net_tcp_echo_and_framing_cli_test.aipl` | `./bin/aipl test tests/examples/ex_119_net_tcp_echo_and_framing_cli_test.aipl` |
| `ex_120` | [examples/ex_120_net_udp_datagram_broadcaster_cli.aipl](../../examples/ex_120_net_udp_datagram_broadcaster_cli.aipl) | `tests/examples/ex_120_net_udp_datagram_broadcaster_cli_test.aipl` | `./bin/aipl test tests/examples/ex_120_net_udp_datagram_broadcaster_cli_test.aipl` |
| `ex_121` | [examples/ex_121_net_rudp_reliable_game_netcode_cli.aipl](../../examples/ex_121_net_rudp_reliable_game_netcode_cli.aipl) | `tests/examples/ex_121_net_rudp_reliable_game_netcode_cli_test.aipl` | `./bin/aipl test tests/examples/ex_121_net_rudp_reliable_game_netcode_cli_test.aipl` |
| `ex_122` | [examples/ex_122_net_dns_packet_resolver_cli.aipl](../../examples/ex_122_net_dns_packet_resolver_cli.aipl) | `tests/examples/ex_122_net_dns_packet_resolver_cli_test.aipl` | `./bin/aipl test tests/examples/ex_122_net_dns_packet_resolver_cli_test.aipl` |
| `ex_123` | [examples/ex_123_net_http_client_rest_inspector_cli.aipl](../../examples/ex_123_net_http_client_rest_inspector_cli.aipl) | `tests/examples/ex_123_net_http_client_rest_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_123_net_http_client_rest_inspector_cli_test.aipl` |
