[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 19: `net` API Reference

> Complete API reference manual for AIPL standard library domain `net` (78 callable functions & methods across ["std/net/dns.aipl", "std/net/http_client.aipl", "std/net/http_server.aipl", "std/net/net_addr.aipl", "std/net/net_mod.aipl", "std/net/rpc.aipl", "std/net/rudp.aipl", "std/net/tcp.aipl", "std/net/udp.aipl", "std/net/ws.aipl", "std/net/live_reload_sync.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `net`
- **Target Source Modules**: ["std/net/dns.aipl", "std/net/http_client.aipl", "std/net/http_server.aipl", "std/net/net_addr.aipl", "std/net/net_mod.aipl", "std/net/rpc.aipl", "std/net/rudp.aipl", "std/net/tcp.aipl", "std/net/udp.aipl", "std/net/ws.aipl", "std/net/live_reload_sync.aipl"]
- **Total Callable Functions & Methods**: 78
- **Total Data Types (`struct` & `enum`)**: 31
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(31 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `DnsQuestion` | `pub struct` | `std/net/dns.aipl` | `name: str`, `qtype: int`, `qclass: int` | `DnsQuestion(name, qtype, qclass)` |
| `DnsRecord` | `pub struct` | `std/net/dns.aipl` | `name: str`, `rtype: int`, `rclass: int`, `ttl: int`, `data: [int]`, `text: str` | `DnsRecord(name, rtype, rclass, ttl, data, text)` |
| `DnsPacket` | `pub struct` | `std/net/dns.aipl` | `id: int`, `isResponse: bool`, `opcode: int`, `authoritative: bool`, `truncated: bool`, `recursionDesired: bool`, `recursionAvailable: bool`, `responseCode: int`, `questions: [DnsQuestion]`, `answers: [DnsRecord]`, `authorities: [DnsRecord]`, `additionals: [DnsRecord]` | `DnsPacket(id, isResponse, opcode, authoritative, truncated, recursionDesired, recursionAvailable, responseCode, questions, answers, authorities, additionals)` |
| `HttpHeader` | `pub struct` | `std/net/http_client.aipl` | `name: str`, `value: str` | `HttpHeader(name, value)` |
| `HttpRequest` | `pub struct` | `std/net/http_client.aipl` | `method: str`, `url: Url`, `headers: [HttpHeader]`, `body: [int]`, `timeoutMs: int`, `maxRedirects: int` | `HttpRequest(method, url, headers, body, timeoutMs, maxRedirects)` |
| `HttpResponse` | `pub struct` | `std/net/http_client.aipl` | `status: int`, `statusText: str`, `headers: [HttpHeader]`, `body: [int]`, `cookies: Map[str, str]` | `HttpResponse(status, statusText, headers, body, cookies)` |
| `HttpConnectionPool` | `pub struct` | `std/net/http_client.aipl` | `maxIdleConns: int`, `idleTimeoutMs: int`, `mut activeCount: int = 0` | `HttpConnectionPool(maxIdleConns, idleTimeoutMs, mut activeCount)` |
| `HttpRoute` | `pub struct` | `std/net/http_server.aipl` | `method: int`, `pathPattern: str`, `handlerId: int`, `paramNames: [str]` | `HttpRoute(method, pathPattern, handlerId, paramNames)` |
| `HttpRouter` | `pub struct` | `std/net/http_server.aipl` | `mut routes: [HttpRoute]`, `mut staticPrefixes: Map[str, str]` | `HttpRouter(mut routes, mut staticPrefixes)` |
| `HttpContext` | `pub struct` | `std/net/http_server.aipl` | `req: HttpRequest`, `mut resHeaders: [HttpHeader]`, `mut resStatus: int`, `pathParams: Map[str, str]`, `queryParams: Map[str, str]`, `handlerId: int = 0` | `HttpContext(req, mut resHeaders, mut resStatus, pathParams, queryParams, handlerId)` |
| `ServerSentEvent` | `pub struct` | `std/net/http_server.aipl` | `event: str`, `data: str`, `id: str`, `retryMs: int` | `ServerSentEvent(event, data, id, retryMs)` |
| `Ipv4Addr` | `pub struct` | `std/net/net_addr.aipl` | `o1: int`, `o2: int`, `o3: int`, `o4: int` | `Ipv4Addr(o1, o2, o3, o4)` |
| `Ipv6Addr` | `pub struct` | `std/net/net_addr.aipl` | `s1: int`, `s2: int`, `s3: int`, `s4: int`, `s5: int`, `s6: int`, `s7: int`, `s8: int` | `Ipv6Addr(s1, s2, s3, s4, s5, s6, s7, s8)` |
| `IpAddr` | `pub struct` | `std/net/net_addr.aipl` | `isIpv6: bool`, `v4: Ipv4Addr`, `v6: Ipv6Addr` | `IpAddr(isIpv6, v4, v6)` |
| `SocketAddr` | `pub struct` | `std/net/net_addr.aipl` | `ip: IpAddr`, `port: int` | `SocketAddr(ip, port)` |
| `CidrBlock` | `pub struct` | `std/net/net_addr.aipl` | `network: IpAddr`, `prefixLen: int` | `CidrBlock(network, prefixLen)` |
| `Url` | `pub struct` | `std/net/net_addr.aipl` | `scheme: str`, `user: str`, `host: str`, `port: int`, `path: str`, `query: Map[str, str]`, `fragment: str` | `Url(scheme, user, host, port, path, query, fragment)` |
| `JsonRpcRequest` | `pub struct` | `std/net/rpc.aipl` | `jsonrpc: str`, `method: str`, `paramsJson: str`, `id: int` | `JsonRpcRequest(jsonrpc, method, paramsJson, id)` |
| `JsonRpcResponse` | `pub struct` | `std/net/rpc.aipl` | `jsonrpc: str`, `resultJson: str`, `errorJson: str`, `id: int` | `JsonRpcResponse(jsonrpc, resultJson, errorJson, id)` |
| `RpcMethodHandler` | `pub struct` | `std/net/rpc.aipl` | `methodName: str`, `handlerId: int` | `RpcMethodHandler(methodName, handlerId)` |
| `RpcDispatcher` | `pub struct` | `std/net/rpc.aipl` | `mut methods: [RpcMethodHandler]`, `enableBatch: bool = true` | `RpcDispatcher(mut methods, enableBatch)` |
| `RudpHeader` | `pub struct` | `std/net/rudp.aipl` | `sequence: int`, `ack: int`, `ackBits: int`, `flags: int`, `channel: int` | `RudpHeader(sequence, ack, ackBits, flags, channel)` |
| `RudpFragment` | `pub struct` | `std/net/rudp.aipl` | `packetId: int`, `fragmentIndex: int`, `totalFragments: int`, `payload: [int]` | `RudpFragment(packetId, fragmentIndex, totalFragments, payload)` |
| `RudpConnection` | `pub struct` | `std/net/rudp.aipl` | `remoteAddr: SocketAddr`, `mut localSequence: int`, `mut remoteSequence: int`, `mut ackBitfield: int`, `mut rttMs: float`, `mut rttVariance: float`, `sendWindowSize: int`, `mut unackedQueue: [RudpFragment]` | `RudpConnection(remoteAddr, mut localSequence, mut remoteSequence, mut ackBitfield, mut rttMs, mut rttVariance, sendWindowSize, mut unackedQueue)` |
| `TcpListener` | `pub struct` | `std/net/tcp.aipl` | `handle: int`, `localAddr: SocketAddr`, `mut isNonBlocking: bool` | `TcpListener(handle, localAddr, mut isNonBlocking)` |
| `TcpStream` | `pub struct` | `std/net/tcp.aipl` | `handle: int`, `peerAddr: SocketAddr`, `localAddr: SocketAddr`, `mut isNonBlocking: bool`, `mut readTimeoutMs: int`, `mut writeTimeoutMs: int`, `mut recvBuf: [int] = []` | `TcpStream(handle, peerAddr, localAddr, mut isNonBlocking, mut readTimeoutMs, mut writeTimeoutMs, mut recvBuf)` |
| `UdpDatagram` | `pub struct` | `std/net/udp.aipl` | `sender: SocketAddr`, `data: [int]`, `length: int` | `UdpDatagram(sender, data, length)` |
| `UdpSocket` | `pub struct` | `std/net/udp.aipl` | `mut handle: int`, `localAddr: SocketAddr`, `mut isBroadcast: bool`, `mut queue: [UdpDatagram] = []` | `UdpSocket(mut handle, localAddr, mut isBroadcast, mut queue)` |
| `WsFrame` | `pub struct` | `std/net/ws.aipl` | `fin: bool`, `rsv: int`, `opcode: int`, `masked: bool`, `maskKey: [int]`, `payload: [int]` | `WsFrame(fin, rsv, opcode, masked, maskKey, payload)` |
| `WebSocketStream` | `pub struct` | `std/net/ws.aipl` | `stream: TcpStream`, `isServer: bool`, `mut isClosed: bool`, `mut closeCode: int` | `WebSocketStream(stream, isServer, mut isClosed, mut closeCode)` |
| `WatcherSyncPacket` | `pub struct` | `std/net/live_reload_sync.aipl` | `seq: int`, `filePath: str`, `expectedCrc32: int`, `actualCrc32: int`, `payload: str`, `isValid: bool` | `WatcherSyncPacket(seq, filePath, expectedCrc32, actualCrc32, payload, isValid)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/net/dns.aipl` | `buildStandardQuery` | `pub fn buildStandardQuery(domainName: str, qtype: int, packetId: int = 1): DnsPacket:` | `tests/functions/net/dns_test.aipl` |
| `2` | `std/net/dns.aipl` | `encodeDnsQuery` | `pub fn encodeDnsQuery(packet: DnsPacket): [int]:` | `tests/functions/net/dns_test.aipl` |
| `3` | `std/net/dns.aipl` | `decodeDnsPacket` | `pub fn decodeDnsPacket(wireBytes: [int]): Option[DnsPacket]:` | `tests/functions/net/dns_test.aipl` |
| `4` | `std/net/dns.aipl` | `extractIpv4FromDnsRecord` | `pub fn extractIpv4FromDnsRecord(rec: DnsRecord): Option[Ipv4Addr]:` | `tests/functions/net/dns_test.aipl` |
| `5` | `std/net/dns.aipl` | `extractTxtFromDnsRecord` | `pub fn extractTxtFromDnsRecord(rec: DnsRecord): str:` | `tests/functions/net/dns_test.aipl` |
| `6` | `std/net/http_client.aipl` | `createHttpClient` | `pub fn createHttpClient(poolSize: int = 10): HttpConnectionPool:` | `tests/functions/net/http_client_test.aipl` |
| `7` | `std/net/http_client.aipl` | `getHeaderValue` | `pub fn getHeaderValue(headers: [HttpHeader], name: str): Option[str]:` | `tests/functions/net/http_client_test.aipl` |
| `8` | `std/net/http_client.aipl` | `parseResponseHeaders` | `pub fn parseResponseHeaders(rawHeaderBytes: [int]): [HttpHeader]:` | `tests/functions/net/http_client_test.aipl` |
| `9` | `std/net/http_client.aipl` | `httpSend` | `pub fn httpSend(mut pool: HttpConnectionPool, req: HttpRequest): Result[HttpResponse, str]:` | `tests/functions/net/http_client_test.aipl` |
| `10` | `std/net/http_client.aipl` | `httpGet` | `pub fn httpGet(urlStr: str, headers: [HttpHeader] = []): Result[HttpResponse, str]:` | `tests/functions/net/http_client_test.aipl` |
| `11` | `std/net/http_client.aipl` | `httpPost` | `pub fn httpPost(urlStr: str, body: [int], contentType: str = "application/json"): Result[HttpResponse, str]:` | `tests/functions/net/http_client_test.aipl` |
| `12` | `std/net/http_client.aipl` | `buildMultipartFormData` | `pub fn buildMultipartFormData(boundary: str, parts: Map[str, [int]]): [int]:` | `tests/functions/net/http_client_test.aipl` |
| `13` | `std/net/http_server.aipl` | `createHttpRouter` | `pub fn createHttpRouter(): HttpRouter:` | `tests/functions/net/http_server_test.aipl` |
| `14` | `std/net/http_server.aipl` | `routerAddRoute` | `pub fn routerAddRoute(mut router: HttpRouter, method: int, pathPattern: str, handlerId: int): HttpRouter:` | `tests/functions/net/http_server_test.aipl` |
| `15` | `std/net/http_server.aipl` | `routerMatch` | `pub fn routerMatch(router: HttpRouter, method: int, requestPath: str): Option[HttpContext]:` | `tests/functions/net/http_server_test.aipl` |
| `16` | `std/net/http_server.aipl` | `formatSseMessage` | `pub fn formatSseMessage(sse: ServerSentEvent): str:` | `tests/functions/net/http_server_test.aipl` |
| `17` | `std/net/http_server.aipl` | `renderHttpResponse` | `pub fn renderHttpResponse(ctx: HttpContext, body: [int]): [int]:` | `tests/functions/net/http_server_test.aipl` |
| `18` | `std/net/net_addr.aipl` | `emptyIpv6` | `fn emptyIpv6(): Ipv6Addr:` | `tests/functions/net/net_addr_test.aipl` |
| `19` | `std/net/net_addr.aipl` | `emptyIpv4` | `fn emptyIpv4(): Ipv4Addr:` | `tests/functions/net/net_addr_test.aipl` |
| `20` | `std/net/net_addr.aipl` | `parseIpv4` | `pub fn parseIpv4(s: str): Option[Ipv4Addr]:` | `tests/functions/net/net_addr_test.aipl` |
| `21` | `std/net/net_addr.aipl` | `formatIpv4` | `pub fn formatIpv4(ip: Ipv4Addr): str:` | `tests/functions/net/net_addr_test.aipl` |
| `22` | `std/net/net_addr.aipl` | `parseHex16` | `fn parseHex16(s: str): Option[int]:` | `tests/functions/net/net_addr_test.aipl` |
| `23` | `std/net/net_addr.aipl` | `parseIpv6` | `pub fn parseIpv6(s: str): Option[Ipv6Addr]:` | `tests/functions/net/net_addr_test.aipl` |
| `24` | `std/net/net_addr.aipl` | `hexWord` | `fn hexWord(v: int): str:` | `tests/functions/net/net_addr_test.aipl` |
| `25` | `std/net/net_addr.aipl` | `formatIpv6` | `pub fn formatIpv6(ip: Ipv6Addr): str:` | `tests/functions/net/net_addr_test.aipl` |
| `26` | `std/net/net_addr.aipl` | `parseSocketAddr` | `pub fn parseSocketAddr(s: str): Option[SocketAddr]:` | `tests/functions/net/net_addr_test.aipl` |
| `27` | `std/net/net_addr.aipl` | `formatSocketAddr` | `pub fn formatSocketAddr(sa: SocketAddr): str:` | `tests/functions/net/net_addr_test.aipl` |
| `28` | `std/net/net_addr.aipl` | `parseCidr` | `pub fn parseCidr(s: str): Option[CidrBlock]:` | `tests/functions/net/net_addr_test.aipl` |
| `29` | `std/net/net_addr.aipl` | `ipv4ToU32` | `fn ipv4ToU32(ip: Ipv4Addr): int:` | `tests/functions/net/net_addr_test.aipl` |
| `30` | `std/net/net_addr.aipl` | `cidrContains` | `pub fn cidrContains(cidr: CidrBlock, ip: Ipv4Addr): bool:` | `tests/functions/net/net_addr_test.aipl` |
| `31` | `std/net/net_addr.aipl` | `decodeQueryString` | `pub fn decodeQueryString(qs: str): Map[str, str]:` | `tests/functions/net/net_addr_test.aipl` |
| `32` | `std/net/net_addr.aipl` | `encodeQueryString` | `pub fn encodeQueryString(params: Map[str, str]): str:` | `tests/functions/net/net_addr_test.aipl` |
| `33` | `std/net/net_addr.aipl` | `parseUrl` | `pub fn parseUrl(rawUrl: str): Option[Url]:` | `tests/functions/net/net_addr_test.aipl` |
| `34` | `std/net/net_addr.aipl` | `formatUrl` | `pub fn formatUrl(u: Url): str:` | `tests/functions/net/net_addr_test.aipl` |
| `35` | `std/net/rpc.aipl` | `createRpcDispatcher` | `pub fn createRpcDispatcher(): RpcDispatcher:` | `tests/functions/net/rpc_test.aipl` |
| `36` | `std/net/rpc.aipl` | `rpcRegisterMethod` | `pub fn rpcRegisterMethod(mut disp: RpcDispatcher, methodName: str, handlerId: int): RpcDispatcher:` | `tests/functions/net/rpc_test.aipl` |
| `37` | `std/net/rpc.aipl` | `rpcFormatSuccess` | `pub fn rpcFormatSuccess(id: int, resultJson: str): str:` | `tests/functions/net/rpc_test.aipl` |
| `38` | `std/net/rpc.aipl` | `rpcFormatError` | `pub fn rpcFormatError(id: int, code: int, message: str): str:` | `tests/functions/net/rpc_test.aipl` |
| `39` | `std/net/rpc.aipl` | `rpcParseRequest` | `pub fn rpcParseRequest(jsonStr: str): Option[JsonRpcRequest]:` | `tests/functions/net/rpc_test.aipl` |
| `40` | `std/net/rpc.aipl` | `rpcDispatch` | `pub fn rpcDispatch(disp: RpcDispatcher, request: JsonRpcRequest): JsonRpcResponse:` | `tests/functions/net/rpc_test.aipl` |
| `41` | `std/net/rudp.aipl` | `rudpCreateConnection` | `pub fn rudpCreateConnection(remote: SocketAddr): RudpConnection:` | `tests/functions/net/rudp_test.aipl` |
| `42` | `std/net/rudp.aipl` | `rudpBuildPacket` | `pub fn rudpBuildPacket(mut conn: RudpConnection, channel: int, flags: int, payload: [int]): [int]:` | `tests/functions/net/rudp_test.aipl` |
| `43` | `std/net/rudp.aipl` | `rudpParsePacket` | `pub fn rudpParsePacket(bytes: [int]): Option[RudpHeader]:` | `tests/functions/net/rudp_test.aipl` |
| `44` | `std/net/rudp.aipl` | `rudpProcessAck` | `pub fn rudpProcessAck(mut conn: RudpConnection, remoteSeq: int, ackBitfield: int): int:` | `tests/functions/net/rudp_test.aipl` |
| `45` | `std/net/rudp.aipl` | `rudpFragmentPayload` | `pub fn rudpFragmentPayload(packetId: int, payload: [int], maxFragmentBytes: int): [RudpFragment]:` | `tests/functions/net/rudp_test.aipl` |
| `46` | `std/net/rudp.aipl` | `rudpTryReassemble` | `pub fn rudpTryReassemble(fragments: [RudpFragment], totalCount: int): Option[[int]]:` | `tests/functions/net/rudp_test.aipl` |
| `47` | `std/net/rudp.aipl` | `rudpCalculateRtt` | `pub fn rudpCalculateRtt(mut conn: RudpConnection, sampleRttMs: float): RudpConnection:` | `tests/functions/net/rudp_test.aipl` |
| `48` | `std/net/tcp.aipl` | `netTcpListen` | `pub fn netTcpListen(addr: SocketAddr): Result[TcpListener, str]:` | `tests/functions/net/tcp_test.aipl` |
| `49` | `std/net/tcp.aipl` | `netTcpAccept` | `pub fn netTcpAccept(listener: TcpListener): Result[TcpStream, str]:` | `tests/functions/net/tcp_test.aipl` |
| `50` | `std/net/tcp.aipl` | `netTcpConnect` | `pub fn netTcpConnect(addr: SocketAddr, timeoutMs: int = 5000): Result[TcpStream, str]:` | `tests/functions/net/tcp_test.aipl` |
| `51` | `std/net/tcp.aipl` | `netTcpWrite` | `pub fn netTcpWrite(mut stream: TcpStream, data: [int]): Result[int, str]:` | `tests/functions/net/tcp_test.aipl` |
| `52` | `std/net/tcp.aipl` | `netTcpRead` | `pub fn netTcpRead(mut stream: TcpStream, maxBytes: int): Result[[int], str]:` | `tests/functions/net/tcp_test.aipl` |
| `53` | `std/net/tcp.aipl` | `netTcpSetNodelay` | `pub fn netTcpSetNodelay(stream: TcpStream, nodelay: bool): Result[bool, str]:` | `tests/functions/net/tcp_test.aipl` |
| `54` | `std/net/tcp.aipl` | `netTcpSetKeepalive` | `pub fn netTcpSetKeepalive(stream: TcpStream, keepaliveMs: int): Result[bool, str]:` | `tests/functions/net/tcp_test.aipl` |
| `55` | `std/net/tcp.aipl` | `netTcpSetNonBlocking` | `pub fn netTcpSetNonBlocking(mut stream: TcpStream, nonBlocking: bool): Result[bool, str]:` | `tests/functions/net/tcp_test.aipl` |
| `56` | `std/net/tcp.aipl` | `netTcpCloseStream` | `pub fn netTcpCloseStream(mut stream: TcpStream): bool:` | `tests/functions/net/tcp_test.aipl` |
| `57` | `std/net/tcp.aipl` | `netTcpCloseListener` | `pub fn netTcpCloseListener(mut listener: TcpListener): bool:` | `tests/functions/net/tcp_test.aipl` |
| `58` | `std/net/udp.aipl` | `netUdpBind` | `pub fn netUdpBind(addr: SocketAddr): Result[UdpSocket, str]:` | `tests/functions/net/udp_test.aipl` |
| `59` | `std/net/udp.aipl` | `netUdpSendTo` | `pub fn netUdpSendTo(mut socket: UdpSocket, target: SocketAddr, data: [int]): Result[int, str]:` | `tests/functions/net/udp_test.aipl` |
| `60` | `std/net/udp.aipl` | `netUdpRecvFrom` | `pub fn netUdpRecvFrom(mut socket: UdpSocket, maxBytes: int): Result[UdpDatagram, str]:` | `tests/functions/net/udp_test.aipl` |
| `61` | `std/net/udp.aipl` | `netUdpJoinMulticast` | `pub fn netUdpJoinMulticast(socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr): Result[bool, str]:` | `tests/functions/net/udp_test.aipl` |
| `62` | `std/net/udp.aipl` | `netUdpLeaveMulticast` | `pub fn netUdpLeaveMulticast(socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr): Result[bool, str]:` | `tests/functions/net/udp_test.aipl` |
| `63` | `std/net/udp.aipl` | `netUdpSetBroadcast` | `pub fn netUdpSetBroadcast(mut socket: UdpSocket, enable: bool): Result[bool, str]:` | `tests/functions/net/udp_test.aipl` |
| `64` | `std/net/udp.aipl` | `netUdpClose` | `pub fn netUdpClose(mut socket: UdpSocket): bool:` | `tests/functions/net/udp_test.aipl` |
| `65` | `std/net/ws.aipl` | `applyWsMask` | `pub fn applyWsMask(payload: [int], maskKey: [int]): [int]:` | `tests/functions/net/ws_test.aipl` |
| `66` | `std/net/ws.aipl` | `encodeWsFrame` | `pub fn encodeWsFrame(frame: WsFrame): [int]:` | `tests/functions/net/ws_test.aipl` |
| `67` | `std/net/ws.aipl` | `decodeWsFrame` | `pub fn decodeWsFrame(bytes: [int]): Option[WsFrame]:` | `tests/functions/net/ws_test.aipl` |
| `68` | `std/net/ws.aipl` | `hexNibbleVal` | `fn hexNibbleVal(code: int): int:` | `tests/functions/net/ws_test.aipl` |
| `69` | `std/net/ws.aipl` | `base64EncodeBytes` | `fn base64EncodeBytes(data: [int]): str:` | `tests/functions/net/ws_test.aipl` |
| `70` | `std/net/ws.aipl` | `computeWsAcceptKey` | `pub fn computeWsAcceptKey(clientKey: str): str:` | `tests/functions/net/ws_test.aipl` |
| `71` | `std/net/ws.aipl` | `buildWsHandshakeRequest` | `pub fn buildWsHandshakeRequest(host: str, path: str, key: str): str:` | `tests/functions/net/ws_test.aipl` |
| `72` | `std/net/ws.aipl` | `validateWsHandshakeResponse` | `pub fn validateWsHandshakeResponse(rawResponse: str, clientKey: str): bool:` | `tests/functions/net/ws_test.aipl` |
| `73` | `std/net/ws.aipl` | `wsCreatePingFrame` | `pub fn wsCreatePingFrame(): WsFrame:` | `tests/functions/net/ws_test.aipl` |
| `74` | `std/net/ws.aipl` | `wsCreatePongFrame` | `pub fn wsCreatePongFrame(pingPayload: [int]): WsFrame:` | `tests/functions/net/ws_test.aipl` |
| `75` | `std/net/ws.aipl` | `wsCreateCloseFrame` | `pub fn wsCreateCloseFrame(code: int, reason: str): WsFrame:` | `tests/functions/net/ws_test.aipl` |
| `76` | `std/net/live_reload_sync.aipl` | `parseWatcherSyncPacket` | `pub fn parseWatcherSyncPacket(rawFrame: str): WatcherSyncPacket:` | `tests/functions/net/live_reload_sync_test.aipl` |
| `77` | `std/net/live_reload_sync.aipl` | `applyLiveReloadDeltaPatch` | `pub fn applyLiveReloadDeltaPatch(baseSource: str, startOffset: int, deleteLen: int, insertText: str, expectedPostCrc32: int): Result[str, str]:` | `tests/functions/net/live_reload_sync_test.aipl` |
| `78` | `std/net/live_reload_sync.aipl` | `buildUdpDiscoveryBeacon` | `pub fn buildUdpDiscoveryBeacon(deviceName: str, wsPort: int): str:` | `tests/functions/net/live_reload_sync_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `buildStandardQuery` (`std/net/dns.aipl`)

- **Signature**: `pub fn buildStandardQuery(domainName: str, qtype: int, packetId: int = 1): DnsPacket:`
- **Import**: `import * from "std/net/dns"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `domainName: str, qtype: int, packetId: int = 1` | **Returns**: `DnsPacket`
- **Unit Test**: `tests/functions/net/dns_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `buildStandardQuery` RFC 1035 DNS wire packet encoding/decoding and `A` (IPv4) / `TXT` resource record extraction. Concrete nominal inputs: `domainName: str = "aipl_test"`, `qtype: int = 1`, `packetId: int = 1`; exercises core body path returning/computing `DnsPacket(`.

```aipl
module tests.functions.net.dns_z1_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_buildStandardQuery_1(): int:
  let arg_domainName = "test"
  let edge_domainName = "a"
  let arg_qtype = 1
  let edge_qtype = 0
  let arg_packetId = 4
  let edge_packetId = 1
  let resNom = buildStandardQuery(arg_domainName, arg_qtype, arg_packetId)
  let resEdge = buildStandardQuery(edge_domainName, edge_qtype, edge_packetId)
  assertEqInt(resNom.id, 4, "buildStandardQuery nominal resNom.id == 4")
  assertEqInt(resEdge.id, 1, "buildStandardQuery boundary resEdge.id == 1")
  ret 0
```

---

### `encodeDnsQuery` (`std/net/dns.aipl`)

- **Signature**: `pub fn encodeDnsQuery(packet: DnsPacket): [int]:`
- **Import**: `import * from "std/net/dns"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `packet: DnsPacket` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/dns_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `encodeDnsQuery` RFC 1035 DNS wire packet encoding/decoding and `A` (IPv4) / `TXT` resource record extraction. Concrete nominal inputs: `packet: DnsPacket = DnsPacket(id = 1, isResponse = true, opcode = 1, authoritative = true, truncated = true, recursionDesired = true, recursionAvailable = true, responseCode = 1, questions = [DnsQuestion(name = 0, qtype = 0, qclass = 0)], answers = [DnsRecord(name = 0, rtype = 0, rclass = 0, ttl = 0, data = 0, text = 0)], authorities = [DnsRecord(name = 0, rtype = 0, rclass = 0, ttl = 0, data = 0, text = 0)], additionals = [DnsRecord(name = 0, rtype = 0, rclass = 0, ttl = 0, data = 0, text = 0)])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.dns_z2_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_encodeDnsQuery_2(): int:
  let arg_packet = DnsPacket(id = 1, isResponse = true, opcode = 2, authoritative = true, truncated = true, recursionDesired = true, recursionAvailable = true, responseCode = 4, questions = [], answers = [], authorities = [], additionals = [])
  let edge_packet = DnsPacket(id = 0, isResponse = false, opcode = 0, authoritative = false, truncated = false, recursionDesired = false, recursionAvailable = false, responseCode = 1, questions = [], answers = [], authorities = [], additionals = [])
  let resNom = encodeDnsQuery(arg_packet)
  let resEdge = encodeDnsQuery(edge_packet)
  assertEqInt(resNom.len(), 12, "encodeDnsQuery nominal resNom.len() == 12")
  assertEqInt(resEdge.len(), 12, "encodeDnsQuery boundary resEdge.len() == 12")
  ret 0
```

---

### `decodeDnsPacket` (`std/net/dns.aipl`)

- **Signature**: `pub fn decodeDnsPacket(wireBytes: [int]): Option[DnsPacket]:`
- **Import**: `import * from "std/net/dns"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wireBytes: [int]` | **Returns**: `Option[DnsPacket]`
- **Unit Test**: `tests/functions/net/dns_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `decodeDnsPacket` RFC 1035 DNS wire packet encoding/decoding and `A` (IPv4) / `TXT` resource record extraction. Concrete nominal inputs: `wireBytes: [int] = [64]`; exercises core body path returning/computing `Some(DnsPacket(`.

```aipl
module tests.functions.net.dns_z3_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_decodeDnsPacket_3(): int:
  let arg_wireBytes = [4]
  let edge_wireBytes = []
  let resNom = decodeDnsPacket(arg_wireBytes)
  let resEdge = decodeDnsPacket(edge_wireBytes)
  assert(resNom.isSome() == false, "decodeDnsPacket nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeDnsPacket boundary resEdge.isSome() == false")
  ret 0
```

---

### `extractIpv4FromDnsRecord` (`std/net/dns.aipl`)

- **Signature**: `pub fn extractIpv4FromDnsRecord(rec: DnsRecord): Option[Ipv4Addr]:`
- **Import**: `import * from "std/net/dns"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rec: DnsRecord` | **Returns**: `Option[Ipv4Addr]`
- **Unit Test**: `tests/functions/net/dns_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `extractIpv4FromDnsRecord` RFC 1035 DNS wire packet encoding/decoding and `A` (IPv4) / `TXT` resource record extraction. Concrete nominal inputs: `rec: DnsRecord = DnsRecord(name = "aipl_test", rtype = 1, rclass = 1, ttl = 1, data = [1], text = "aipl_test")`; exercises core body path returning/computing `Some(Ipv4Addr(`.

```aipl
module tests.functions.net.dns_z4_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_extractIpv4FromDnsRecord_4(): int:
  let arg_rec = DnsRecord(name = "127.0.0.1", rtype = 1, rclass = 2, ttl = 2, data = [], text = "127.0.0.1")
  let edge_rec = DnsRecord(name = "127.0.0.1", rtype = 0, rclass = 0, ttl = 0, data = [], text = "127.0.0.1")
  let resNom = extractIpv4FromDnsRecord(arg_rec)
  let resEdge = extractIpv4FromDnsRecord(edge_rec)
  assert(resNom.isSome() == false, "extractIpv4FromDnsRecord nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "extractIpv4FromDnsRecord boundary resEdge.isSome() == false")
  ret 0
```

---

### `extractTxtFromDnsRecord` (`std/net/dns.aipl`)

- **Signature**: `pub fn extractTxtFromDnsRecord(rec: DnsRecord): str:`
- **Import**: `import * from "std/net/dns"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rec: DnsRecord` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/dns_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `extractTxtFromDnsRecord` RFC 1035 DNS wire packet encoding/decoding and `A` (IPv4) / `TXT` resource record extraction. Concrete nominal inputs: `rec: DnsRecord = DnsRecord(name = "aipl_test", rtype = 1, rclass = 1, ttl = 1, data = [1], text = "aipl_test")`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.dns_z5_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_extractTxtFromDnsRecord_5(): int:
  let arg_rec = DnsRecord(name = "test", rtype = 1, rclass = 2, ttl = 2, data = [], text = "test")
  let edge_rec = DnsRecord(name = "a", rtype = 0, rclass = 0, ttl = 0, data = [], text = "a")
  let resNom = extractTxtFromDnsRecord(arg_rec)
  let resEdge = extractTxtFromDnsRecord(edge_rec)
  assertEqStr(resNom, "test", "extractTxtFromDnsRecord nominal string matches")
  assertEqStr(resEdge, "a", "extractTxtFromDnsRecord boundary string matches")
  ret 0
```

---

### `createHttpClient` (`std/net/http_client.aipl`)

- **Signature**: `pub fn createHttpClient(poolSize: int = 10): HttpConnectionPool:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `poolSize: int = 10` | **Returns**: `HttpConnectionPool`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `createHttpClient` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `poolSize: int = 64`; exercises core body path returning/computing `HttpConnectionPool(maxIdleConns: poolSize, idleTimeoutMs: 30000, activeCount: 0)`.

```aipl
module tests.functions.net.http_client_z1_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_createHttpClient_1(): int:
  let arg_poolSize = 4
  let edge_poolSize = 1
  let resNom = createHttpClient(arg_poolSize)
  let resEdge = createHttpClient(edge_poolSize)
  assertEqInt(resNom.maxIdleConns, 4, "createHttpClient nominal resNom.maxIdleConns == 4")
  assertEqInt(resEdge.maxIdleConns, 1, "createHttpClient boundary resEdge.maxIdleConns == 1")
  ret 0
```

---

### `getHeaderValue` (`std/net/http_client.aipl`)

- **Signature**: `pub fn getHeaderValue(headers: [HttpHeader], name: str): Option[str]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `headers: [HttpHeader], name: str` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `getHeaderValue` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `headers: [HttpHeader] = [HttpHeader(name = "aipl_test", value = "aipl_test")]`, `name: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.net.http_client_z2_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_getHeaderValue_2(): int:
  let arg_headers = [HttpHeader(name = "test", value = "test")]
  let edge_headers = []
  let arg_name = "test"
  let edge_name = "a"
  let resNom = getHeaderValue(arg_headers, arg_name)
  let resEdge = getHeaderValue(edge_headers, edge_name)
  assert(resNom.isSome() == true, "getHeaderValue nominal resNom.isSome() == true")
  assert(resEdge.isSome() == false, "getHeaderValue boundary resEdge.isSome() == false")
  ret 0
```

---

### `parseResponseHeaders` (`std/net/http_client.aipl`)

- **Signature**: `pub fn parseResponseHeaders(rawHeaderBytes: [int]): [HttpHeader]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawHeaderBytes: [int]` | **Returns**: `[HttpHeader]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `parseResponseHeaders` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `rawHeaderBytes: [int] = [64]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.http_client_z3_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_parseResponseHeaders_3(): int:
  let arg_rawHeaderBytes = [4]
  let edge_rawHeaderBytes = []
  let resNom = parseResponseHeaders(arg_rawHeaderBytes)
  let resEdge = parseResponseHeaders(edge_rawHeaderBytes)
  assertEqInt(resNom.len(), 0, "parseResponseHeaders nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "parseResponseHeaders boundary resEdge.len() == 0")
  ret 0
```

---

### `httpSend` (`std/net/http_client.aipl`)

- **Signature**: `pub fn httpSend(mut pool: HttpConnectionPool, req: HttpRequest): Result[HttpResponse, str]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: HttpConnectionPool, req: HttpRequest` | **Returns**: `Result[HttpResponse, str]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `httpSend` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `pool: HttpConnectionPool = HttpConnectionPool(maxIdleConns = 1, idleTimeoutMs = 1)`, `req: HttpRequest = HttpRequest(method = "aipl_test", url = Url(scheme = "aipl_test", user = "aipl_test", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_artifact.tmp", query = Map(), fragment = "aipl_test"), headers = [HttpHeader(name = 0, value = 0)], body = [1], timeoutMs = 1, maxRedirects = 1)`; exercises core body path returning/computing `Ok(HttpResponse(`.

```aipl
module tests.functions.net.http_client_z4_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_httpSend_4(): int:
  let arg_pool = HttpConnectionPool(maxIdleConns = 4, idleTimeoutMs = 4, activeCount = 4)
  let edge_pool = HttpConnectionPool(maxIdleConns = 1, idleTimeoutMs = 1, activeCount = 1)
  let arg_req = HttpRequest(method = "test", url = Url(scheme = "test", user = "test", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_path", query = {}, fragment = "test"), headers = [], body = [], timeoutMs = 4, maxRedirects = 4)
  let edge_req = HttpRequest(method = "a", url = Url(scheme = "a", user = "a", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_path", query = {}, fragment = "a"), headers = [], body = [], timeoutMs = 1, maxRedirects = 1)
  let resNom = httpSend(arg_pool, arg_req)
  let resEdge = httpSend(edge_pool, edge_req)
  assert(resNom.isOk() == true, "httpSend nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "httpSend boundary resEdge.isOk() == true")
  ret 0
```

---

### `httpGet` (`std/net/http_client.aipl`)

- **Signature**: `pub fn httpGet(urlStr: str, headers: [HttpHeader] = []): Result[HttpResponse, str]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `urlStr: str, headers: [HttpHeader] = []` | **Returns**: `Result[HttpResponse, str]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `httpGet` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `urlStr: str = "https://example.com/api"`, `headers: [HttpHeader] = [HttpHeader(name = "aipl_test", value = "aipl_test")]`; exercises core body path returning/computing `httpSend(pool, req)`.

```aipl
module tests.functions.net.http_client_z5_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_httpGet_5(): int:
  let arg_urlStr = "test"
  let edge_urlStr = "a"
  let arg_headers = [HttpHeader(name = "test", value = "test")]
  let edge_headers = []
  let resNom = httpGet(arg_urlStr, arg_headers)
  let resEdge = httpGet(edge_urlStr, edge_headers)
  assert(resNom.isOk() == false, "httpGet nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "httpGet boundary resEdge.isOk() == false")
  ret 0
```

---

### `httpPost` (`std/net/http_client.aipl`)

- **Signature**: `pub fn httpPost(urlStr: str, body: [int], contentType: str = "application/json"): Result[HttpResponse, str]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `urlStr: str, body: [int], contentType: str = "application/json"` | **Returns**: `Result[HttpResponse, str]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `httpPost` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `urlStr: str = "https://example.com/api"`, `body: [int] = [1]`, `contentType: str = "aipl_test"`; exercises core body path returning/computing `httpSend(pool, req)`.

```aipl
module tests.functions.net.http_client_z6_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_httpPost_6(): int:
  let arg_urlStr = "test"
  let edge_urlStr = "a"
  let arg_body = [4]
  let edge_body = []
  let arg_contentType = "test"
  let edge_contentType = "a"
  let resNom = httpPost(arg_urlStr, arg_body, arg_contentType)
  let resEdge = httpPost(edge_urlStr, edge_body, edge_contentType)
  assert(resNom.isOk() == false, "httpPost nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "httpPost boundary resEdge.isOk() == false")
  ret 0
```

---

### `buildMultipartFormData` (`std/net/http_client.aipl`)

- **Signature**: `pub fn buildMultipartFormData(boundary: str, parts: Map[str, [int]]): [int]:`
- **Import**: `import * from "std/net/http_client"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `boundary: str, parts: Map[str, [int]]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/http_client_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `buildMultipartFormData` HTTP request builder, case-insensitive header lookup, `multipart/form-data` boundary framing, and response status parsing. Concrete nominal inputs: `boundary: str = "aipl_test"`, `parts: Map[str, [int]] = Map()`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.http_client_z7_test
import * from "std/net/http_client"
import * from "std/net/net_addr"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_client_buildMultipartFormData_7(): int:
  let arg_boundary = "127.0.0.1"
  let edge_boundary = "127.0.0.1"
  let arg_parts = {}
  let edge_parts = {}
  let resNom = buildMultipartFormData(arg_boundary, arg_parts)
  let resEdge = buildMultipartFormData(edge_boundary, edge_parts)
  assertEqInt(resNom.len(), 15, "buildMultipartFormData nominal resNom.len() == 15")
  assertEqInt(resEdge.len(), 15, "buildMultipartFormData boundary resEdge.len() == 15")
  ret 0
```

---

### `createHttpRouter` (`std/net/http_server.aipl`)

- **Signature**: `pub fn createHttpRouter(): HttpRouter:`
- **Import**: `import * from "std/net/http_server"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `HttpRouter`
- **Unit Test**: `tests/functions/net/http_server_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `createHttpRouter` HTTP router `:param` and `*wildcard` path matching, status/JSON response builders, and Server-Sent Events (SSE) formatting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `HttpRouter(routes: [], staticPrefixes: mapNew())`.

```aipl
module tests.functions.net.http_server_z1_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_createHttpRouter_1(): int:
  let resNom = createHttpRouter()
  let resEdge = createHttpRouter()
  assertEqInt(resNom.routes.len(), 0, "createHttpRouter nominal resNom.routes.len() == 0")
  assertEqInt(resEdge.routes.len(), 0, "createHttpRouter boundary resEdge.routes.len() == 0")
  ret 0
```

---

### `routerAddRoute` (`std/net/http_server.aipl`)

- **Signature**: `pub fn routerAddRoute(mut router: HttpRouter, method: int, pathPattern: str, handlerId: int): HttpRouter:`
- **Import**: `import * from "std/net/http_server"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut router: HttpRouter, method: int, pathPattern: str, handlerId: int` | **Returns**: `HttpRouter`
- **Unit Test**: `tests/functions/net/http_server_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `routerAddRoute` HTTP router `:param` and `*wildcard` path matching, status/JSON response builders, and Server-Sent Events (SSE) formatting. Concrete nominal inputs: `router: HttpRouter = HttpRouter()`, `method: int = 1`, `pathPattern: str = "/tmp/aipl_test_artifact.tmp"`, `handlerId: int = 1`; exercises core body path returning/computing `router`.

```aipl
module tests.functions.net.http_server_z2_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_routerAddRoute_2(): int:
  let arg_router = HttpRouter(routes = [], staticPrefixes = {})
  let edge_router = HttpRouter(routes = [], staticPrefixes = {})
  let arg_method = 4
  let edge_method = 1
  let arg_pathPattern = "/tmp/aipl_test_path"
  let edge_pathPattern = "/tmp/aipl_test_path"
  let arg_handlerId = 4
  let edge_handlerId = 1
  let resNom = routerAddRoute(arg_router, arg_method, arg_pathPattern, arg_handlerId)
  let resEdge = routerAddRoute(edge_router, edge_method, edge_pathPattern, edge_handlerId)
  assertEqInt(resNom.routes.len(), 1, "routerAddRoute nominal resNom.routes.len() == 1")
  assertEqInt(resEdge.routes.len(), 1, "routerAddRoute boundary resEdge.routes.len() == 1")
  ret 0
```

---

### `routerMatch` (`std/net/http_server.aipl`)

- **Signature**: `pub fn routerMatch(router: HttpRouter, method: int, requestPath: str): Option[HttpContext]:`
- **Import**: `import * from "std/net/http_server"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `router: HttpRouter, method: int, requestPath: str` | **Returns**: `Option[HttpContext]`
- **Unit Test**: `tests/functions/net/http_server_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `routerMatch` HTTP router `:param` and `*wildcard` path matching, status/JSON response builders, and Server-Sent Events (SSE) formatting. Concrete nominal inputs: `router: HttpRouter = HttpRouter()`, `method: int = 1`, `requestPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.net.http_server_z3_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_routerMatch_3(): int:
  let arg_router = HttpRouter(routes = [], staticPrefixes = {})
  let edge_router = HttpRouter(routes = [], staticPrefixes = {})
  let arg_method = 4
  let edge_method = 1
  let arg_requestPath = "/tmp/aipl_test_path"
  let edge_requestPath = "/tmp/aipl_test_path"
  let resNom = routerMatch(arg_router, arg_method, arg_requestPath)
  let resEdge = routerMatch(edge_router, edge_method, edge_requestPath)
  assert(resNom.isSome() == false, "routerMatch nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "routerMatch boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatSseMessage` (`std/net/http_server.aipl`)

- **Signature**: `pub fn formatSseMessage(sse: ServerSentEvent): str:`
- **Import**: `import * from "std/net/http_server"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sse: ServerSentEvent` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/http_server_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `formatSseMessage` HTTP router `:param` and `*wildcard` path matching, status/JSON response builders, and Server-Sent Events (SSE) formatting. Concrete nominal inputs: `sse: ServerSentEvent = ServerSentEvent(event = "aipl_test", data = "aipl_test", id = "aipl_test", retryMs = 1)`; exercises core body path returning/computing `lines.join("\n") + "\n\n"`.

```aipl
module tests.functions.net.http_server_z4_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_formatSseMessage_4(): int:
  let arg_sse = ServerSentEvent(event = "test", data = "test", id = "test", retryMs = 4)
  let edge_sse = ServerSentEvent(event = "a", data = "a", id = "a", retryMs = 1)
  let resNom = formatSseMessage(arg_sse)
  let resEdge = formatSseMessage(edge_sse)
  assertEqInt(resNom.len(), 42, "formatSseMessage nominal string length == 42")
  assertEqInt(resEdge.len(), 33, "formatSseMessage boundary string length == 33")
  ret 0
```

---

### `renderHttpResponse` (`std/net/http_server.aipl`)

- **Signature**: `pub fn renderHttpResponse(ctx: HttpContext, body: [int]): [int]:`
- **Import**: `import * from "std/net/http_server"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ctx: HttpContext, body: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/http_server_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `renderHttpResponse` HTTP router `:param` and `*wildcard` path matching, status/JSON response builders, and Server-Sent Events (SSE) formatting. Concrete nominal inputs: `ctx: HttpContext = HttpContext(req = HttpRequest(method = "aipl_test", url = Url(scheme = 0, user = 0, host = 0, port = 0, path = 0, query = 0, fragment = 0), headers = [0], body = [0], timeoutMs = 1, maxRedirects = 1), pathParams = Map(), queryParams = Map(), handlerId = int = 0())`, `body: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.http_server_z5_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_renderHttpResponse_5(): int:
  let arg_ctx = HttpContext(req = HttpRequest(method = "test", url = Url(scheme = "test", user = "test", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_path", query = {}, fragment = "test"), headers = [], body = [], timeoutMs = 4, maxRedirects = 4), resHeaders = [], resStatus = 2, pathParams = {}, queryParams = {}, handlerId = 4)
  let edge_ctx = HttpContext(req = HttpRequest(method = "a", url = Url(scheme = "a", user = "a", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_path", query = {}, fragment = "a"), headers = [], body = [], timeoutMs = 1, maxRedirects = 1), resHeaders = [], resStatus = 0, pathParams = {}, queryParams = {}, handlerId = 1)
  let arg_body = [4]
  let edge_body = []
  let resNom = renderHttpResponse(arg_ctx, arg_body)
  let resEdge = renderHttpResponse(edge_ctx, edge_body)
  assertEqInt(resNom.len(), 37, "renderHttpResponse nominal resNom.len() == 37")
  assertEqInt(resEdge.len(), 36, "renderHttpResponse boundary resEdge.len() == 36")
  ret 0
```

---

### `emptyIpv6` (`std/net/net_addr.aipl`)

- **Signature**: `fn emptyIpv6(): Ipv6Addr:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Ipv6Addr`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `emptyIpv6` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Ipv6Addr(s1: 0, s2: 0, s3: 0, s4: 0, s5: 0, s6: 0, s7: 0, s8: 0)`.

```aipl
module tests.functions.net.net_addr_z1_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_emptyIpv6_1(): int:
  let resNom = emptyIpv6()
  let resEdge = emptyIpv6()
  assertEqInt(resNom.s1, 0, "emptyIpv6 nominal resNom.s1 == 0")
  assertEqInt(resEdge.s1, 0, "emptyIpv6 boundary resEdge.s1 == 0")
  ret 0
```

---

### `emptyIpv4` (`std/net/net_addr.aipl`)

- **Signature**: `fn emptyIpv4(): Ipv4Addr:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Ipv4Addr`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `emptyIpv4` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Ipv4Addr(o1: 0, o2: 0, o3: 0, o4: 0)`.

```aipl
module tests.functions.net.net_addr_z2_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_emptyIpv4_2(): int:
  let resNom = emptyIpv4()
  let resEdge = emptyIpv4()
  assertEqInt(resNom.o1, 0, "emptyIpv4 nominal resNom.o1 == 0")
  assertEqInt(resEdge.o1, 0, "emptyIpv4 boundary resEdge.o1 == 0")
  ret 0
```

---

### `parseIpv4` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn parseIpv4(s: str): Option[Ipv4Addr]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[Ipv4Addr]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `parseIpv4` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Some(Ipv4Addr(o1: octs[0], o2: octs[1], o3: octs[2], o4: octs[3]))`.

```aipl
module tests.functions.net.net_addr_z3_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseIpv4_3(): int:
  let arg_s = "127.0.0.1"
  let edge_s = "127.0.0.1"
  let resNom = parseIpv4(arg_s)
  let resEdge = parseIpv4(edge_s)
  assert(resNom.isSome() == true, "parseIpv4 nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseIpv4 boundary resEdge.isSome() == true")
  ret 0
```

---

### `formatIpv4` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn formatIpv4(ip: Ipv4Addr): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ip: Ipv4Addr` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `formatIpv4` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `ip: Ipv4Addr = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1)`; exercises core body path returning/computing `str(ip.o1) + "." + str(ip.o2) + "." + str(ip.o3) + "." + str(ip.o4)`.

```aipl
module tests.functions.net.net_addr_z4_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_formatIpv4_4(): int:
  let arg_ip = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2)
  let edge_ip = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0)
  let resNom = formatIpv4(arg_ip)
  let resEdge = formatIpv4(edge_ip)
  assertEqStr(resNom, "2.2.2.2", "formatIpv4 nominal string matches")
  assertEqStr(resEdge, "0.0.0.0", "formatIpv4 boundary string matches")
  ret 0
```

---

### `parseHex16` (`std/net/net_addr.aipl`)

- **Signature**: `fn parseHex16(s: str): Option[int]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `parseHex16` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Some(acc)`.

```aipl
module tests.functions.net.net_addr_z5_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseHex16_5(): int:
  let arg_s = "4142"
  let edge_s = "00"
  let resNom = parseHex16(arg_s)
  let resEdge = parseHex16(edge_s)
  assert(resNom.isSome() == true, "parseHex16 nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseHex16 boundary resEdge.isSome() == true")
  ret 0
```

---

### `parseIpv6` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn parseIpv6(s: str): Option[Ipv6Addr]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[Ipv6Addr]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `parseIpv6` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Some(Ipv6Addr(`.

```aipl
module tests.functions.net.net_addr_z6_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseIpv6_6(): int:
  let arg_s = "127.0.0.1"
  let edge_s = "127.0.0.1"
  let resNom = parseIpv6(arg_s)
  let resEdge = parseIpv6(edge_s)
  assert(resNom.isSome() == false, "parseIpv6 nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "parseIpv6 boundary resEdge.isSome() == false")
  ret 0
```

---

### `hexWord` (`std/net/net_addr.aipl`)

- **Signature**: `fn hexWord(v: int): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `hexWord` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `v: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.net_addr_z7_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_hexWord_7(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = hexWord(arg_v)
  let resEdge = hexWord(edge_v)
  assertEqStr(resNom, "2", "hexWord nominal string matches")
  assertEqStr(resEdge, "0", "hexWord boundary string matches")
  ret 0
```

---

### `formatIpv6` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn formatIpv6(ip: Ipv6Addr): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ip: Ipv6Addr` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `formatIpv6` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `ip: Ipv6Addr = Ipv6Addr(s1 = 1, s2 = 1, s3 = 1, s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1)`; exercises core body path returning/computing `words.join(":")`.

```aipl
module tests.functions.net.net_addr_z8_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_formatIpv6_8(): int:
  let arg_ip = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)
  let edge_ip = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)
  let resNom = formatIpv6(arg_ip)
  let resEdge = formatIpv6(edge_ip)
  assertEqStr(resNom, "2:2:2:2:2:2:2:2", "formatIpv6 nominal string matches")
  assertEqStr(resEdge, "0:0:0:0:0:0:0:0", "formatIpv6 boundary string matches")
  ret 0
```

---

### `parseSocketAddr` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn parseSocketAddr(s: str): Option[SocketAddr]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[SocketAddr]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `parseSocketAddr` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.net.net_addr_z9_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseSocketAddr_9(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseSocketAddr(arg_s)
  let resEdge = parseSocketAddr(edge_s)
  assert(resNom.isSome() == false, "parseSocketAddr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "parseSocketAddr boundary resEdge.isSome() == false")
  ret 0
```

---

### `formatSocketAddr` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn formatSocketAddr(sa: SocketAddr): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sa: SocketAddr` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `formatSocketAddr` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `sa: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`; exercises core body path returning/computing `formatIpv4(sa.ip.v4) + ":" + str(sa.port)`.

```aipl
module tests.functions.net.net_addr_z10_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_formatSocketAddr_10(): int:
  let arg_sa = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_sa = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let resNom = formatSocketAddr(arg_sa)
  let resEdge = formatSocketAddr(edge_sa)
  assertEqStr(resNom, "[2:2:2:2:2:2:2:2]:8080", "formatSocketAddr nominal string matches")
  assertEqStr(resEdge, "0.0.0.0:8080", "formatSocketAddr boundary string matches")
  ret 0
```

---

### `parseCidr` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn parseCidr(s: str): Option[CidrBlock]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[CidrBlock]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `parseCidr` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.net.net_addr_z11_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseCidr_11(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseCidr(arg_s)
  let resEdge = parseCidr(edge_s)
  assert(resNom.isSome() == false, "parseCidr nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "parseCidr boundary resEdge.isSome() == false")
  ret 0
```

---

### `ipv4ToU32` (`std/net/net_addr.aipl`)

- **Signature**: `fn ipv4ToU32(ip: Ipv4Addr): int:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ip: Ipv4Addr` | **Returns**: `int`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `ipv4ToU32` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `ip: Ipv4Addr = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1)`; exercises core body path returning/computing `((ip.o1 & 255) << 24) | ((ip.o2 & 255) << 16) | ((ip.o3 & 255) << 8) | (ip.o4 & 255)`.

```aipl
module tests.functions.net.net_addr_z12_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_ipv4ToU32_12(): int:
  let arg_ip = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2)
  let edge_ip = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0)
  let resNom = ipv4ToU32(arg_ip)
  let resEdge = ipv4ToU32(edge_ip)
  assertEqInt(resNom, 33686018, "ipv4ToU32 nominal resNom == 33686018")
  assertEqInt(resEdge, 0, "ipv4ToU32 boundary resEdge == 0")
  ret 0
```

---

### `cidrContains` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn cidrContains(cidr: CidrBlock, ip: Ipv4Addr): bool:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cidr: CidrBlock, ip: Ipv4Addr` | **Returns**: `bool`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `cidrContains` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `cidr: CidrBlock = CidrBlock(network = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), prefixLen = 64)`, `ip: Ipv4Addr = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1)`; exercises core body path returning/computing `(netVal >> shift) == (ipVal >> shift)`.

```aipl
module tests.functions.net.net_addr_z13_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_cidrContains_13(): int:
  let arg_cidr = CidrBlock(network = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), prefixLen = 4)
  let edge_cidr = CidrBlock(network = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), prefixLen = 1)
  let arg_ip = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2)
  let edge_ip = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0)
  let resNom = cidrContains(arg_cidr, arg_ip)
  let resEdge = cidrContains(edge_cidr, edge_ip)
  assert(resNom == true, "cidrContains nominal resNom == true")
  assert(resEdge == true, "cidrContains boundary resEdge == true")
  ret 0
```

---

### `decodeQueryString` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn decodeQueryString(qs: str): Map[str, str]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `qs: str` | **Returns**: `Map[str, str]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `decodeQueryString` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `qs: str = "aipl_test"`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.net.net_addr_z14_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_decodeQueryString_14(): int:
  let arg_qs = "test"
  let edge_qs = "a"
  let resNom = decodeQueryString(arg_qs)
  let resEdge = decodeQueryString(edge_qs)
  assertEqInt(resNom.len(), 1, "decodeQueryString nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "decodeQueryString boundary resEdge.len() == 1")
  ret 0
```

---

### `encodeQueryString` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn encodeQueryString(params: Map[str, str]): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `params: Map[str, str]` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `encodeQueryString` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `params: Map[str, str] = Map()`; exercises core body path returning/computing `parts.join("&")`.

```aipl
module tests.functions.net.net_addr_z15_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_encodeQueryString_15(): int:
  let arg_params = {}
  let edge_params = {}
  let resNom = encodeQueryString(arg_params)
  let resEdge = encodeQueryString(edge_params)
  assertEqStr(resNom, "", "encodeQueryString nominal string matches")
  assertEqStr(resEdge, "", "encodeQueryString boundary string matches")
  ret 0
```

---

### `parseUrl` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn parseUrl(rawUrl: str): Option[Url]:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawUrl: str` | **Returns**: `Option[Url]`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `parseUrl` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `rawUrl: str = "https://example.com/api"`; exercises core body path returning/computing `Some(Url(`.

```aipl
module tests.functions.net.net_addr_z16_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_parseUrl_16(): int:
  let arg_rawUrl = "http://localhost/test"
  let edge_rawUrl = "http://localhost/test"
  let resNom = parseUrl(arg_rawUrl)
  let resEdge = parseUrl(edge_rawUrl)
  assert(resNom.isSome() == true, "parseUrl nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseUrl boundary resEdge.isSome() == true")
  ret 0
```

---

### `formatUrl` (`std/net/net_addr.aipl`)

- **Signature**: `pub fn formatUrl(u: Url): str:`
- **Import**: `import * from "std/net/net_addr"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `u: Url` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/net_addr_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `formatUrl` IPv4/IPv6/SocketAddr/CIDR parsing, subnet membership (`cidrContains`), and RFC 3986 URL + query-string parsing/formatting. Concrete nominal inputs: `u: Url = Url(scheme = "aipl_test", user = "aipl_test", host = "127.0.0.1", port = 8080, path = "/tmp/aipl_test_artifact.tmp", query = Map(), fragment = "aipl_test")`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.net_addr_z17_test
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_net_addr_formatUrl_17(): int:
  let arg_u = Url(scheme = "http://localhost/test", user = "http://localhost/test", host = "http://localhost/test", port = 8080, path = "http://localhost/test", query = {}, fragment = "http://localhost/test")
  let edge_u = Url(scheme = "http://localhost/test", user = "http://localhost/test", host = "http://localhost/test", port = 8080, path = "http://localhost/test", query = {}, fragment = "http://localhost/test")
  let resNom = formatUrl(arg_u)
  let resEdge = formatUrl(edge_u)
  assertEqInt(resNom.len(), 115, "formatUrl nominal string length == 115")
  assertEqInt(resEdge.len(), 115, "formatUrl boundary string length == 115")
  ret 0
```

---

### `createRpcDispatcher` (`std/net/rpc.aipl`)

- **Signature**: `pub fn createRpcDispatcher(): RpcDispatcher:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `RpcDispatcher`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `createRpcDispatcher` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `RpcDispatcher(methods: [], enableBatch: true)`.

```aipl
module tests.functions.net.rpc_z1_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_createRpcDispatcher_1(): int:
  let resNom = createRpcDispatcher()
  let resEdge = createRpcDispatcher()
  assertEqInt(resNom.methods.len(), 0, "createRpcDispatcher nominal resNom.methods.len() == 0")
  assertEqInt(resEdge.methods.len(), 0, "createRpcDispatcher boundary resEdge.methods.len() == 0")
  ret 0
```

---

### `rpcRegisterMethod` (`std/net/rpc.aipl`)

- **Signature**: `pub fn rpcRegisterMethod(mut disp: RpcDispatcher, methodName: str, handlerId: int): RpcDispatcher:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut disp: RpcDispatcher, methodName: str, handlerId: int` | **Returns**: `RpcDispatcher`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `rpcRegisterMethod` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: `disp: RpcDispatcher = RpcDispatcher(enableBatch = bool = true())`, `methodName: str = "aipl_test"`, `handlerId: int = 1`; exercises core body path returning/computing `disp`.

```aipl
module tests.functions.net.rpc_z2_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_rpcRegisterMethod_2(): int:
  let arg_disp = RpcDispatcher(methods = [], enableBatch = true)
  let edge_disp = RpcDispatcher(methods = [], enableBatch = false)
  let arg_methodName = "test"
  let edge_methodName = "a"
  let arg_handlerId = 4
  let edge_handlerId = 1
  let resNom = rpcRegisterMethod(arg_disp, arg_methodName, arg_handlerId)
  let resEdge = rpcRegisterMethod(edge_disp, edge_methodName, edge_handlerId)
  assertEqInt(resNom.methods.len(), 1, "rpcRegisterMethod nominal resNom.methods.len() == 1")
  assertEqInt(resEdge.methods.len(), 1, "rpcRegisterMethod boundary resEdge.methods.len() == 1")
  ret 0
```

---

### `rpcFormatSuccess` (`std/net/rpc.aipl`)

- **Signature**: `pub fn rpcFormatSuccess(id: int, resultJson: str): str:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, resultJson: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `rpcFormatSuccess` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: `id: int = 1`, `resultJson: str = "{\"ok\":true}"`; exercises core body path returning/computing `"{" + q + "jsonrpc" + q + ":" + q + "2.0" + q + "," + q + "result" + q + ":" + resultJson + "," + q + "id" + q + ":" + str(id) + "}"`.

```aipl
module tests.functions.net.rpc_z3_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_rpcFormatSuccess_3(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_resultJson = "{\"a\":1}"
  let edge_resultJson = "{}"
  let resNom = rpcFormatSuccess(arg_id, arg_resultJson)
  let resEdge = rpcFormatSuccess(edge_id, edge_resultJson)
  assertEqInt(resNom.len(), 41, "rpcFormatSuccess nominal string length == 41")
  assertEqInt(resEdge.len(), 36, "rpcFormatSuccess boundary string length == 36")
  ret 0
```

---

### `rpcFormatError` (`std/net/rpc.aipl`)

- **Signature**: `pub fn rpcFormatError(id: int, code: int, message: str): str:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, code: int, message: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `rpcFormatError` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: `id: int = 1`, `code: int = 1`, `message: str = "aipl_test"`; exercises core body path returning/computing `"{" + q + "jsonrpc" + q + ":" + q + "2.0" + q + "," + q + "error" + q + ":{" + q + "code" + q + ":" + str(code) + "," + q + "message" + q + ":" + q + message + q + "}," + q + "id" + q + ":" + str(id) + "}"`.

```aipl
module tests.functions.net.rpc_z4_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_rpcFormatError_4(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_code = 2
  let edge_code = 0
  let arg_message = "test"
  let edge_message = "a"
  let resNom = rpcFormatError(arg_id, arg_code, arg_message)
  let resEdge = rpcFormatError(edge_id, edge_code, edge_message)
  assertEqInt(resNom.len(), 60, "rpcFormatError nominal string length == 60")
  assertEqInt(resEdge.len(), 57, "rpcFormatError boundary string length == 57")
  ret 0
```

---

### `rpcParseRequest` (`std/net/rpc.aipl`)

- **Signature**: `pub fn rpcParseRequest(jsonStr: str): Option[JsonRpcRequest]:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str` | **Returns**: `Option[JsonRpcRequest]`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `rpcParseRequest` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`; exercises core body path returning/computing `Some(JsonRpcRequest(jsonrpc: "2.0", method: method, paramsJson: "[]", id: 1))`.

```aipl
module tests.functions.net.rpc_z5_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_rpcParseRequest_5(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let resNom = rpcParseRequest(arg_jsonStr)
  let resEdge = rpcParseRequest(edge_jsonStr)
  assert(resNom.isSome() == false, "rpcParseRequest nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "rpcParseRequest boundary resEdge.isSome() == false")
  ret 0
```

---

### `rpcDispatch` (`std/net/rpc.aipl`)

- **Signature**: `pub fn rpcDispatch(disp: RpcDispatcher, request: JsonRpcRequest): JsonRpcResponse:`
- **Import**: `import * from "std/net/rpc"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `disp: RpcDispatcher, request: JsonRpcRequest` | **Returns**: `JsonRpcResponse`
- **Unit Test**: `tests/functions/net/rpc_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `rpcDispatch` JSON-RPC 2.0 request/response/notification framing, batch dispatch, and `-32601 Method not found` error generation. Concrete nominal inputs: `disp: RpcDispatcher = RpcDispatcher(enableBatch = bool = true())`, `request: JsonRpcRequest = JsonRpcRequest(jsonrpc = "{\"ok\":true}", method = "aipl_test", paramsJson = "{\"ok\":true}", id = 1)`; exercises core body path returning/computing `JsonRpcResponse(`.

```aipl
module tests.functions.net.rpc_z6_test
import * from "std/net/rpc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rpc_rpcDispatch_6(): int:
  let arg_disp = RpcDispatcher(methods = [], enableBatch = true)
  let edge_disp = RpcDispatcher(methods = [], enableBatch = false)
  let arg_request = JsonRpcRequest(jsonrpc = "{\"a\":1}", method = "test", paramsJson = "{\"a\":1}", id = 1)
  let edge_request = JsonRpcRequest(jsonrpc = "{}", method = "a", paramsJson = "{}", id = 0)
  let resNom = rpcDispatch(arg_disp, arg_request)
  let resEdge = rpcDispatch(edge_disp, edge_request)
  assertEqStr(resNom.jsonrpc, "2.0", "rpcDispatch nominal string matches")
  assertEqStr(resEdge.jsonrpc, "2.0", "rpcDispatch boundary string matches")
  ret 0
```

---

### `rudpCreateConnection` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpCreateConnection(remote: SocketAddr): RudpConnection:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `remote: SocketAddr` | **Returns**: `RudpConnection`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `rudpCreateConnection` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `remote: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`; exercises core body path returning/computing `RudpConnection(`.

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

---

### `rudpBuildPacket` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpBuildPacket(mut conn: RudpConnection, channel: int, flags: int, payload: [int]): [int]:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut conn: RudpConnection, channel: int, flags: int, payload: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `rudpBuildPacket` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `conn: RudpConnection = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), sendWindowSize = 64)`, `channel: int = 2`, `flags: int = 1`, `payload: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.rudp_z2_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpBuildPacket_2(): int:
  let arg_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 4, remoteSequence = 4, ackBitfield = 4, rttMs = 1.0, rttVariance = 1.0, sendWindowSize = 4, unackedQueue = [])
  let edge_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 1, remoteSequence = 1, ackBitfield = 1, rttMs = 0.5, rttVariance = 0.5, sendWindowSize = 1, unackedQueue = [])
  let arg_channel = 4
  let edge_channel = 1
  let arg_flags = 1
  let edge_flags = 0
  let arg_payload = [1]
  let edge_payload = []
  let resNom = rudpBuildPacket(arg_conn, arg_channel, arg_flags, arg_payload)
  let resEdge = rudpBuildPacket(edge_conn, edge_channel, edge_flags, edge_payload)
  assertEqInt(resNom.len(), 13, "rudpBuildPacket nominal resNom.len() == 13")
  assertEqInt(resEdge.len(), 12, "rudpBuildPacket boundary resEdge.len() == 12")
  ret 0
```

---

### `rudpParsePacket` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpParsePacket(bytes: [int]): Option[RudpHeader]:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[RudpHeader]`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `rudpParsePacket` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(RudpHeader(sequence: seq, ack: ack, ackBits: bits, flags: flags, channel: channel))`.

```aipl
module tests.functions.net.rudp_z3_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpParsePacket_3(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = rudpParsePacket(arg_bytes)
  let resEdge = rudpParsePacket(edge_bytes)
  assert(resNom.isSome() == false, "rudpParsePacket nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "rudpParsePacket boundary resEdge.isSome() == false")
  ret 0
```

---

### `rudpProcessAck` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpProcessAck(mut conn: RudpConnection, remoteSeq: int, ackBitfield: int): int:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut conn: RudpConnection, remoteSeq: int, ackBitfield: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `rudpProcessAck` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `conn: RudpConnection = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), sendWindowSize = 64)`, `remoteSeq: int = 1`, `ackBitfield: int = 1`; exercises core body path returning/computing `acked`.

```aipl
module tests.functions.net.rudp_z4_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpProcessAck_4(): int:
  let arg_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 4, remoteSequence = 4, ackBitfield = 4, rttMs = 1.0, rttVariance = 1.0, sendWindowSize = 4, unackedQueue = [])
  let edge_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 1, remoteSequence = 1, ackBitfield = 1, rttMs = 0.5, rttVariance = 0.5, sendWindowSize = 1, unackedQueue = [])
  let arg_remoteSeq = 4
  let edge_remoteSeq = 1
  let arg_ackBitfield = 4
  let edge_ackBitfield = 1
  let resNom = rudpProcessAck(arg_conn, arg_remoteSeq, arg_ackBitfield)
  let resEdge = rudpProcessAck(edge_conn, edge_remoteSeq, edge_ackBitfield)
  assertEqInt(resNom, 2, "rudpProcessAck nominal resNom == 2")
  assertEqInt(resEdge, 2, "rudpProcessAck boundary resEdge == 2")
  ret 0
```

---

### `rudpFragmentPayload` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpFragmentPayload(packetId: int, payload: [int], maxFragmentBytes: int): [RudpFragment]:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `packetId: int, payload: [int], maxFragmentBytes: int` | **Returns**: `[RudpFragment]`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `rudpFragmentPayload` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `packetId: int = 1`, `payload: [int] = [1]`, `maxFragmentBytes: int = 64`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.rudp_z5_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpFragmentPayload_5(): int:
  let arg_packetId = 4
  let edge_packetId = 1
  let arg_payload = [1]
  let edge_payload = []
  let arg_maxFragmentBytes = 4
  let edge_maxFragmentBytes = 1
  let resNom = rudpFragmentPayload(arg_packetId, arg_payload, arg_maxFragmentBytes)
  let resEdge = rudpFragmentPayload(edge_packetId, edge_payload, edge_maxFragmentBytes)
  assertEqInt(resNom.len(), 1, "rudpFragmentPayload nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "rudpFragmentPayload boundary resEdge.len() == 1")
  ret 0
```

---

### `rudpTryReassemble` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpTryReassemble(fragments: [RudpFragment], totalCount: int): Option[[int]]:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fragments: [RudpFragment], totalCount: int` | **Returns**: `Option[[int]]`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `rudpTryReassemble` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `fragments: [RudpFragment] = [RudpFragment(packetId = 1, fragmentIndex = 0, totalFragments = 1, payload = [0])]`, `totalCount: int = 64`; exercises core body path returning/computing `Some(out)`.

```aipl
module tests.functions.net.rudp_z6_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpTryReassemble_6(): int:
  let arg_fragments = [RudpFragment(packetId = 4, fragmentIndex = 4, totalFragments = 4, payload = [])]
  let edge_fragments = []
  let arg_totalCount = 4
  let edge_totalCount = 1
  let resNom = rudpTryReassemble(arg_fragments, arg_totalCount)
  let resEdge = rudpTryReassemble(edge_fragments, edge_totalCount)
  assert(resNom.isSome() == false, "rudpTryReassemble nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "rudpTryReassemble boundary resEdge.isSome() == false")
  ret 0
```

---

### `rudpCalculateRtt` (`std/net/rudp.aipl`)

- **Signature**: `pub fn rudpCalculateRtt(mut conn: RudpConnection, sampleRttMs: float): RudpConnection:`
- **Import**: `import * from "std/net/rudp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut conn: RudpConnection, sampleRttMs: float` | **Returns**: `RudpConnection`
- **Unit Test**: `tests/functions/net/rudp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `rudpCalculateRtt` reliable UDP sequence/ACK bitmask processing, MTU payload fragmentation, out-of-order reassembly, and Jacobson EWMA RTT estimation. Concrete nominal inputs: `conn: RudpConnection = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), sendWindowSize = 64)`, `sampleRttMs: float = 1.0`; exercises core body path returning/computing `conn`.

```aipl
module tests.functions.net.rudp_z7_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpCalculateRtt_7(): int:
  let arg_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 4, remoteSequence = 4, ackBitfield = 4, rttMs = 1.0, rttVariance = 1.0, sendWindowSize = 4, unackedQueue = [])
  let edge_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 1, remoteSequence = 1, ackBitfield = 1, rttMs = 0.5, rttVariance = 0.5, sendWindowSize = 1, unackedQueue = [])
  let arg_sampleRttMs = 1.0
  let edge_sampleRttMs = 0.5
  let resNom = rudpCalculateRtt(arg_conn, arg_sampleRttMs)
  let resEdge = rudpCalculateRtt(edge_conn, edge_sampleRttMs)
  assertEqInt(resNom.localSequence, 4, "rudpCalculateRtt nominal resNom.localSequence == 4")
  assertEqInt(resEdge.localSequence, 1, "rudpCalculateRtt boundary resEdge.localSequence == 1")
  ret 0
```

---

### `netTcpListen` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpListen(addr: SocketAddr): Result[TcpListener, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: SocketAddr` | **Returns**: `Result[TcpListener, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netTcpListen` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `addr: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`; exercises core body path returning/computing `Ok(TcpListener(handle: 100 + addr.port, localAddr: addr, isNonBlocking: false))`.

```aipl
module tests.functions.net.tcp_z1_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpListen_1(): int:
  let arg_addr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_addr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let resNom = netTcpListen(arg_addr)
  let resEdge = netTcpListen(edge_addr)
  assert(resNom.isOk() == true, "netTcpListen nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "netTcpListen boundary resEdge.isOk() == true")
  ret 0
```

---

### `netTcpAccept` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpAccept(listener: TcpListener): Result[TcpStream, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `listener: TcpListener` | **Returns**: `Result[TcpStream, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netTcpAccept` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `listener: TcpListener = TcpListener(handle = 1, localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`; exercises core body path returning/computing `Ok(TcpStream(`.

```aipl
module tests.functions.net.tcp_z2_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpAccept_2(): int:
  let arg_listener = TcpListener(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true)
  let edge_listener = TcpListener(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false)
  let resNom = netTcpAccept(arg_listener)
  let resEdge = netTcpAccept(edge_listener)
  assert(resNom.isOk() == false, "netTcpAccept nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netTcpAccept boundary resEdge.isOk() == false")
  ret 0
```

---

### `netTcpConnect` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpConnect(addr: SocketAddr, timeoutMs: int = 5000): Result[TcpStream, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: SocketAddr, timeoutMs: int = 5000` | **Returns**: `Result[TcpStream, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `netTcpConnect` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `addr: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`, `timeoutMs: int = 1`; exercises core body path returning/computing `Ok(TcpStream(`.

```aipl
module tests.functions.net.tcp_z3_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpConnect_3(): int:
  let arg_addr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_addr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let arg_timeoutMs = 4
  let edge_timeoutMs = 1
  let resNom = netTcpConnect(arg_addr, arg_timeoutMs)
  let resEdge = netTcpConnect(edge_addr, edge_timeoutMs)
  assert(resNom.isOk() == true, "netTcpConnect nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "netTcpConnect boundary resEdge.isOk() == true")
  ret 0
```

---

### `netTcpWrite` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpWrite(mut stream: TcpStream, data: [int]): Result[int, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stream: TcpStream, data: [int]` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netTcpWrite` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `data: [int] = [1]`; exercises core body path returning/computing `Ok(data.len())`.

```aipl
module tests.functions.net.tcp_z4_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpWrite_4(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let arg_data = [2]
  let edge_data = []
  let resNom = netTcpWrite(arg_stream, arg_data)
  let resEdge = netTcpWrite(edge_stream, edge_data)
  assert(resNom.isOk() == false, "netTcpWrite nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netTcpWrite boundary resEdge.isOk() == false")
  ret 0
```

---

### `netTcpRead` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpRead(mut stream: TcpStream, maxBytes: int): Result[[int], str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stream: TcpStream, maxBytes: int` | **Returns**: `Result[[int], str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netTcpRead` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `maxBytes: int = 64`; exercises core body path returning/computing `Ok(out)`.

```aipl
module tests.functions.net.tcp_z5_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpRead_5(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let arg_maxBytes = 4
  let edge_maxBytes = 1
  let resNom = netTcpRead(arg_stream, arg_maxBytes)
  let resEdge = netTcpRead(edge_stream, edge_maxBytes)
  assert(resNom.isOk() == false, "netTcpRead nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netTcpRead boundary resEdge.isOk() == false")
  ret 0
```

---

### `netTcpSetNodelay` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpSetNodelay(stream: TcpStream, nodelay: bool): Result[bool, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `stream: TcpStream, nodelay: bool` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `netTcpSetNodelay` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `nodelay: bool = true`; exercises core body path returning/computing `Ok(nodelay or true)`.

```aipl
module tests.functions.net.tcp_z6_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpSetNodelay_6(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let arg_nodelay = true
  let edge_nodelay = false
  let resNom = netTcpSetNodelay(arg_stream, arg_nodelay)
  let resEdge = netTcpSetNodelay(edge_stream, edge_nodelay)
  assert(resNom.isOk() == false, "netTcpSetNodelay nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netTcpSetNodelay boundary resEdge.isOk() == false")
  ret 0
```

---

### `netTcpSetKeepalive` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpSetKeepalive(stream: TcpStream, keepaliveMs: int): Result[bool, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `stream: TcpStream, keepaliveMs: int` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netTcpSetKeepalive` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `keepaliveMs: int = 1`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.net.tcp_z7_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpSetKeepalive_7(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let arg_keepaliveMs = 4
  let edge_keepaliveMs = 1
  let resNom = netTcpSetKeepalive(arg_stream, arg_keepaliveMs)
  let resEdge = netTcpSetKeepalive(edge_stream, edge_keepaliveMs)
  assert(resNom.isOk() == false, "netTcpSetKeepalive nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netTcpSetKeepalive boundary resEdge.isOk() == false")
  ret 0
```

---

### `netTcpSetNonBlocking` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpSetNonBlocking(mut stream: TcpStream, nonBlocking: bool): Result[bool, str]:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stream: TcpStream, nonBlocking: bool` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netTcpSetNonBlocking` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `nonBlocking: bool = true`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.net.tcp_z8_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpSetNonBlocking_8(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let arg_nonBlocking = true
  let edge_nonBlocking = false
  let resNom = netTcpSetNonBlocking(arg_stream, arg_nonBlocking)
  let resEdge = netTcpSetNonBlocking(edge_stream, edge_nonBlocking)
  assert(resNom.isOk() == true, "netTcpSetNonBlocking nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "netTcpSetNonBlocking boundary resEdge.isOk() == true")
  ret 0
```

---

### `netTcpCloseStream` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpCloseStream(mut stream: TcpStream): bool:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stream: TcpStream` | **Returns**: `bool`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `netTcpCloseStream` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `stream: TcpStream = TcpStream(handle = 1, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.net.tcp_z9_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpCloseStream_9(): int:
  let arg_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true, readTimeoutMs = 4, writeTimeoutMs = 4, recvBuf = [])
  let edge_stream = TcpStream(handle = 0, peerAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false, readTimeoutMs = 1, writeTimeoutMs = 1, recvBuf = [])
  let resNom = netTcpCloseStream(arg_stream)
  let resEdge = netTcpCloseStream(edge_stream)
  assert(resNom == true, "netTcpCloseStream nominal resNom == true")
  assert(resEdge == true, "netTcpCloseStream boundary resEdge == true")
  ret 0
```

---

### `netTcpCloseListener` (`std/net/tcp.aipl`)

- **Signature**: `pub fn netTcpCloseListener(mut listener: TcpListener): bool:`
- **Import**: `import * from "std/net/tcp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut listener: TcpListener` | **Returns**: `bool`
- **Unit Test**: `tests/functions/net/tcp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netTcpCloseListener` TCP listener bind/accept, client stream connect, nodelay/keepalive/timeout socket options, and bidirectional byte transmission. Concrete nominal inputs: `listener: TcpListener = TcpListener(handle = 1, localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.net.tcp_z10_test
import * from "std/net/tcp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tcp_netTcpCloseListener_10(): int:
  let arg_listener = TcpListener(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = true)
  let edge_listener = TcpListener(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isNonBlocking = false)
  let resNom = netTcpCloseListener(arg_listener)
  let resEdge = netTcpCloseListener(edge_listener)
  assert(resNom == true, "netTcpCloseListener nominal resNom == true")
  assert(resEdge == true, "netTcpCloseListener boundary resEdge == true")
  ret 0
```

---

### `netUdpBind` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpBind(addr: SocketAddr): Result[UdpSocket, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: SocketAddr` | **Returns**: `Result[UdpSocket, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netUdpBind` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `addr: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`; exercises core body path returning/computing `Ok(UdpSocket(handle: 300 + addr.port, localAddr: addr, isBroadcast: false, queue: []))`.

```aipl
module tests.functions.net.udp_z1_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpBind_1(): int:
  let arg_addr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_addr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let resNom = netUdpBind(arg_addr)
  let resEdge = netUdpBind(edge_addr)
  assert(resNom.isOk() == true, "netUdpBind nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "netUdpBind boundary resEdge.isOk() == true")
  ret 0
```

---

### `netUdpSendTo` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpSendTo(mut socket: UdpSocket, target: SocketAddr, data: [int]): Result[int, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut socket: UdpSocket, target: SocketAddr, data: [int]` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `netUdpSendTo` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `target: SocketAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)`, `data: [int] = [1]`; exercises core body path returning/computing `Ok(data.len())`.

```aipl
module tests.functions.net.udp_z2_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpSendTo_2(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let arg_target = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2)), port = 8080)
  let edge_target = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080)
  let arg_data = [2]
  let edge_data = []
  let resNom = netUdpSendTo(arg_socket, arg_target, arg_data)
  let resEdge = netUdpSendTo(edge_socket, edge_target, edge_data)
  assert(resNom.isOk() == false, "netUdpSendTo nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netUdpSendTo boundary resEdge.isOk() == false")
  ret 0
```

---

### `netUdpRecvFrom` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpRecvFrom(mut socket: UdpSocket, maxBytes: int): Result[UdpDatagram, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut socket: UdpSocket, maxBytes: int` | **Returns**: `Result[UdpDatagram, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netUdpRecvFrom` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `maxBytes: int = 64`; exercises core body path returning/computing `Ok(UdpDatagram(sender: dg.sender, data: outData, length: outData.len()))`.

```aipl
module tests.functions.net.udp_z3_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpRecvFrom_3(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let arg_maxBytes = 4
  let edge_maxBytes = 1
  let resNom = netUdpRecvFrom(arg_socket, arg_maxBytes)
  let resEdge = netUdpRecvFrom(edge_socket, edge_maxBytes)
  assert(resNom.isOk() == false, "netUdpRecvFrom nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netUdpRecvFrom boundary resEdge.isOk() == false")
  ret 0
```

---

### `netUdpJoinMulticast` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpJoinMulticast(socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr): Result[bool, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netUdpJoinMulticast` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `multicastAddr: IpAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1), v6 = Ipv6Addr(s1 = 1, s2 = 1, s3 = 1, s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1))`, `interfaceAddr: IpAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1), v6 = Ipv6Addr(s1 = 1, s2 = 1, s3 = 1, s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1))`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.net.udp_z4_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpJoinMulticast_4(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let arg_multicastAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2))
  let edge_multicastAddr = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0))
  let arg_interfaceAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2))
  let edge_interfaceAddr = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0))
  let resNom = netUdpJoinMulticast(arg_socket, arg_multicastAddr, arg_interfaceAddr)
  let resEdge = netUdpJoinMulticast(edge_socket, edge_multicastAddr, edge_interfaceAddr)
  assert(resNom.isOk() == false, "netUdpJoinMulticast nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netUdpJoinMulticast boundary resEdge.isOk() == false")
  ret 0
```

---

### `netUdpLeaveMulticast` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpLeaveMulticast(socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr): Result[bool, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `socket: UdpSocket, multicastAddr: IpAddr, interfaceAddr: IpAddr` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `netUdpLeaveMulticast` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `multicastAddr: IpAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1), v6 = Ipv6Addr(s1 = 1, s2 = 1, s3 = 1, s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1))`, `interfaceAddr: IpAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 1, o2 = 1, o3 = 1, o4 = 1), v6 = Ipv6Addr(s1 = 1, s2 = 1, s3 = 1, s4 = 1, s5 = 1, s6 = 1, s7 = 1, s8 = 1))`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.net.udp_z5_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpLeaveMulticast_5(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let arg_multicastAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2))
  let edge_multicastAddr = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0))
  let arg_interfaceAddr = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 2, o2 = 2, o3 = 2, o4 = 2), v6 = Ipv6Addr(s1 = 2, s2 = 2, s3 = 2, s4 = 2, s5 = 2, s6 = 2, s7 = 2, s8 = 2))
  let edge_interfaceAddr = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0))
  let resNom = netUdpLeaveMulticast(arg_socket, arg_multicastAddr, arg_interfaceAddr)
  let resEdge = netUdpLeaveMulticast(edge_socket, edge_multicastAddr, edge_interfaceAddr)
  assert(resNom.isOk() == false, "netUdpLeaveMulticast nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "netUdpLeaveMulticast boundary resEdge.isOk() == false")
  ret 0
```

---

### `netUdpSetBroadcast` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpSetBroadcast(mut socket: UdpSocket, enable: bool): Result[bool, str]:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut socket: UdpSocket, enable: bool` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `netUdpSetBroadcast` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`, `enable: bool = true`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.net.udp_z6_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpSetBroadcast_6(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let arg_enable = true
  let edge_enable = false
  let resNom = netUdpSetBroadcast(arg_socket, arg_enable)
  let resEdge = netUdpSetBroadcast(edge_socket, edge_enable)
  assert(resNom.isOk() == true, "netUdpSetBroadcast nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "netUdpSetBroadcast boundary resEdge.isOk() == true")
  ret 0
```

---

### `netUdpClose` (`std/net/udp.aipl`)

- **Signature**: `pub fn netUdpClose(mut socket: UdpSocket): bool:`
- **Import**: `import * from "std/net/udp"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut socket: UdpSocket` | **Returns**: `bool`
- **Unit Test**: `tests/functions/net/udp_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `netUdpClose` UDP datagram bind, `sendTo`/`recvFrom`, broadcast enable, and multicast group join/leave. Concrete nominal inputs: `socket: UdpSocket = UdpSocket(localAddr = SocketAddr(ip = IpAddr(isIpv6 = 0, v4 = 0, v6 = 0), port = 8080))`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.net.udp_z7_test
import * from "std/net/udp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_udp_netUdpClose_7(): int:
  let arg_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = true, queue = [])
  let edge_socket = UdpSocket(handle = 0, localAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), isBroadcast = false, queue = [])
  let resNom = netUdpClose(arg_socket)
  let resEdge = netUdpClose(edge_socket)
  assert(resNom == true, "netUdpClose nominal resNom == true")
  assert(resEdge == true, "netUdpClose boundary resEdge == true")
  ret 0
```

---

### `applyWsMask` (`std/net/ws.aipl`)

- **Signature**: `pub fn applyWsMask(payload: [int], maskKey: [int]): [int]:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `payload: [int], maskKey: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `applyWsMask` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `payload: [int] = [1]`, `maskKey: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.ws_z1_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_applyWsMask_1(): int:
  let arg_payload = [1]
  let edge_payload = []
  let arg_maskKey = [4]
  let edge_maskKey = []
  let resNom = applyWsMask(arg_payload, arg_maskKey)
  let resEdge = applyWsMask(edge_payload, edge_maskKey)
  assertEqInt(resNom.len(), 1, "applyWsMask nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "applyWsMask boundary resEdge.len() == 0")
  ret 0
```

---

### `encodeWsFrame` (`std/net/ws.aipl`)

- **Signature**: `pub fn encodeWsFrame(frame: WsFrame): [int]:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frame: WsFrame` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `encodeWsFrame` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `frame: WsFrame = WsFrame(fin = true, rsv = 1, opcode = 1, masked = true, maskKey = [1], payload = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.ws_z2_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_encodeWsFrame_2(): int:
  let arg_frame = WsFrame(fin = true, rsv = 2, opcode = 2, masked = true, maskKey = [], payload = [])
  let edge_frame = WsFrame(fin = false, rsv = 0, opcode = 0, masked = false, maskKey = [], payload = [])
  let resNom = encodeWsFrame(arg_frame)
  let resEdge = encodeWsFrame(edge_frame)
  assertEqInt(resNom.len(), 6, "encodeWsFrame nominal resNom.len() == 6")
  assertEqInt(resEdge.len(), 2, "encodeWsFrame boundary resEdge.len() == 2")
  ret 0
```

---

### `decodeWsFrame` (`std/net/ws.aipl`)

- **Signature**: `pub fn decodeWsFrame(bytes: [int]): Option[WsFrame]:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[WsFrame]`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `decodeWsFrame` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(WsFrame(fin: fin, rsv: rsv, opcode: opcode, masked: masked, maskKey: maskKey, payload: finalPayload))`.

```aipl
module tests.functions.net.ws_z3_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_decodeWsFrame_3(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = decodeWsFrame(arg_bytes)
  let resEdge = decodeWsFrame(edge_bytes)
  assert(resNom.isSome() == false, "decodeWsFrame nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeWsFrame boundary resEdge.isSome() == false")
  ret 0
```

---

### `hexNibbleVal` (`std/net/ws.aipl`)

- **Signature**: `fn hexNibbleVal(code: int): int:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `hexNibbleVal` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.net.ws_z4_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_hexNibbleVal_4(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = hexNibbleVal(arg_code)
  let resEdge = hexNibbleVal(edge_code)
  assertEqInt(resNom, 0, "hexNibbleVal nominal resNom == 0")
  assertEqInt(resEdge, 0, "hexNibbleVal boundary resEdge == 0")
  ret 0
```

---

### `base64EncodeBytes` (`std/net/ws.aipl`)

- **Signature**: `fn base64EncodeBytes(data: [int]): str:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: [int]` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `base64EncodeBytes` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `data: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.net.ws_z5_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_base64EncodeBytes_5(): int:
  let arg_data = [2]
  let edge_data = []
  let resNom = base64EncodeBytes(arg_data)
  let resEdge = base64EncodeBytes(edge_data)
  assertEqStr(resNom, "Ag==", "base64EncodeBytes nominal string matches")
  assertEqStr(resEdge, "", "base64EncodeBytes boundary string matches")
  ret 0
```

---

### `computeWsAcceptKey` (`std/net/ws.aipl`)

- **Signature**: `pub fn computeWsAcceptKey(clientKey: str): str:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clientKey: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `computeWsAcceptKey` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `clientKey: str = "aipl_test"`; exercises core body path returning/computing `base64EncodeBytes(digestBytes)`.

```aipl
module tests.functions.net.ws_z6_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_computeWsAcceptKey_6(): int:
  let arg_clientKey = "test"
  let edge_clientKey = "a"
  let resNom = computeWsAcceptKey(arg_clientKey)
  let resEdge = computeWsAcceptKey(edge_clientKey)
  assertEqStr(resNom, "tNpbgC8ZQDOcSkHAWopKzQjJ1hI=", "computeWsAcceptKey nominal string matches")
  assertEqStr(resEdge, "FtgH8qqfEKHvZKEZYEWkYDhlXNY=", "computeWsAcceptKey boundary string matches")
  ret 0
```

---

### `buildWsHandshakeRequest` (`std/net/ws.aipl`)

- **Signature**: `pub fn buildWsHandshakeRequest(host: str, path: str, key: str): str:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `host: str, path: str, key: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `buildWsHandshakeRequest` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `host: str = "127.0.0.1"`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `key: str = "aipl_test"`; exercises core body path returning/computing `lines.join("\r\n") + "\r\n\r\n"`.

```aipl
module tests.functions.net.ws_z7_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_buildWsHandshakeRequest_7(): int:
  let arg_host = "127.0.0.1"
  let edge_host = "127.0.0.1"
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_key = "test"
  let edge_key = "a"
  let resNom = buildWsHandshakeRequest(arg_host, arg_path, arg_key)
  let resEdge = buildWsHandshakeRequest(edge_host, edge_path, edge_key)
  assertEqInt(resNom.len(), 146, "buildWsHandshakeRequest nominal string length == 146")
  assertEqInt(resEdge.len(), 143, "buildWsHandshakeRequest boundary string length == 143")
  ret 0
```

---

### `validateWsHandshakeResponse` (`std/net/ws.aipl`)

- **Signature**: `pub fn validateWsHandshakeResponse(rawResponse: str, clientKey: str): bool:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawResponse: str, clientKey: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `validateWsHandshakeResponse` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `rawResponse: str = "aipl_test"`, `clientKey: str = "aipl_test"`; exercises core body path returning/computing `rawResponse.contains("101") and rawResponse.contains(expected)`.

```aipl
module tests.functions.net.ws_z8_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_validateWsHandshakeResponse_8(): int:
  let arg_rawResponse = "test"
  let edge_rawResponse = "a"
  let arg_clientKey = "test"
  let edge_clientKey = "a"
  let resNom = validateWsHandshakeResponse(arg_rawResponse, arg_clientKey)
  let resEdge = validateWsHandshakeResponse(edge_rawResponse, edge_clientKey)
  assert(resNom == false, "validateWsHandshakeResponse nominal resNom == false")
  assert(resEdge == false, "validateWsHandshakeResponse boundary resEdge == false")
  ret 0
```

---

### `wsCreatePingFrame` (`std/net/ws.aipl`)

- **Signature**: `pub fn wsCreatePingFrame(): WsFrame:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `WsFrame`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_118_net_addr_cidr_subnet_calc_cli.aipl`
- **Behavioral Summary**: Verify `wsCreatePingFrame` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `WsFrame(fin: true, rsv: 0, opcode: 9, masked: false, maskKey: [], payload: [])`.

```aipl
module tests.functions.net.ws_z9_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_wsCreatePingFrame_9(): int:
  let resNom = wsCreatePingFrame()
  let resEdge = wsCreatePingFrame()
  assert(resNom.fin == true, "wsCreatePingFrame nominal resNom.fin == true")
  assert(resEdge.fin == true, "wsCreatePingFrame boundary resEdge.fin == true")
  ret 0
```

---

### `wsCreatePongFrame` (`std/net/ws.aipl`)

- **Signature**: `pub fn wsCreatePongFrame(pingPayload: [int]): WsFrame:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pingPayload: [int]` | **Returns**: `WsFrame`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_119_net_tcp_echo_and_framing_cli.aipl`
- **Behavioral Summary**: Verify `wsCreatePongFrame` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `pingPayload: [int] = [1]`; exercises core body path returning/computing `WsFrame(fin: true, rsv: 0, opcode: 10, masked: false, maskKey: [], payload: pingPayload)`.

```aipl
module tests.functions.net.ws_z10_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_wsCreatePongFrame_10(): int:
  let arg_pingPayload = [4]
  let edge_pingPayload = []
  let resNom = wsCreatePongFrame(arg_pingPayload)
  let resEdge = wsCreatePongFrame(edge_pingPayload)
  assert(resNom.fin == true, "wsCreatePongFrame nominal resNom.fin == true")
  assert(resEdge.fin == true, "wsCreatePongFrame boundary resEdge.fin == true")
  ret 0
```

---

### `wsCreateCloseFrame` (`std/net/ws.aipl`)

- **Signature**: `pub fn wsCreateCloseFrame(code: int, reason: str): WsFrame:`
- **Import**: `import * from "std/net/ws"` (or barrel `import * from "std/net/net_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int, reason: str` | **Returns**: `WsFrame`
- **Unit Test**: `tests/functions/net/ws_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Verify `wsCreateCloseFrame` RFC 6455 `Sec-WebSocket-Accept` SHA-1/Base64 handshake, client payload masking/unmasking, and Ping/Pong/Close frame encoding. Concrete nominal inputs: `code: int = 1`, `reason: str = "aipl_test"`; exercises core body path returning/computing `WsFrame(fin: true, rsv: 0, opcode: 8, masked: false, maskKey: [], payload: p)`.

```aipl
module tests.functions.net.ws_z11_test
import * from "std/net/ws"
import * from "std/net/tcp"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ws_wsCreateCloseFrame_11(): int:
  let arg_code = 2
  let edge_code = 0
  let arg_reason = "test"
  let edge_reason = "a"
  let resNom = wsCreateCloseFrame(arg_code, arg_reason)
  let resEdge = wsCreateCloseFrame(edge_code, edge_reason)
  assert(resNom.fin == true, "wsCreateCloseFrame nominal resNom.fin == true")
  assert(resEdge.fin == true, "wsCreateCloseFrame boundary resEdge.fin == true")
  ret 0
```

---

### `parseWatcherSyncPacket` (`std/net/live_reload_sync.aipl`)

- **Signature**: `pub fn parseWatcherSyncPacket(rawFrame: str): WatcherSyncPacket requires rawFrame.len() >= 0 ensures not result.isValid or result.seq >= 0:`
- **Import**: `import { parseWatcherSyncPacket } from "std/net/live_reload_sync"`
- **Receiver**: `None (free function)` | **Parameters**: `rawFrame: str` | **Returns**: `WatcherSyncPacket`
- **Unit Test**: `tests/functions/net/live_reload_sync_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Parses pipe-delimited live-reload WebSocket/TCP frames (`"AIPLSYNC|v1|<seq>|<filePath>|<expectedCrc32>|<payload>"`), validating packet headers and verifying payload body CRC32 checksums.

```aipl
module tests.functions.net.live_reload_ref_01_test
import { parseWatcherSyncPacket } from "std/net/live_reload_sync"
import { crc32 } from "std/crypto/hash"
import { assert, assertEqInt, assertEqStr } from "std/prelude"
pub fn test_parseWatcherSyncPacket_ref(): int:
  let body = "pub fn main(): int:\n  ret 0"
  let c = crc32(body.toBytes())
  let frame = "AIPLSYNC|v1|1|main.aipl|" + str(c) + "|" + body
  let pkt = parseWatcherSyncPacket(frame)
  assert(pkt.isValid == true, "packet is valid")
  assertEqInt(pkt.seq, 1, "sequence == 1")
  assertEqStr(pkt.filePath, "main.aipl", "path matches")
  ret 0
```

---

### `applyLiveReloadDeltaPatch` (`std/net/live_reload_sync.aipl`)

- **Signature**: `pub fn applyLiveReloadDeltaPatch(baseSource: str, startOffset: int, deleteLen: int, insertText: str, expectedPostCrc32: int): Result[str, str] requires baseSource.len() >= 0 and insertText.len() >= 0 ensures (startOffset >= 0 and deleteLen >= 0) or result.isErr():`
- **Import**: `import { applyLiveReloadDeltaPatch } from "std/net/live_reload_sync"`
- **Receiver**: `None (free function)` | **Parameters**: `baseSource: str, startOffset: int, deleteLen: int, insertText: str, expectedPostCrc32: int` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/net/live_reload_sync_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Applies a differential slice replacement `[startOffset, startOffset + deleteLen)` with `insertText`, verifying the resulting source against the expected CRC32 post-condition checksum.

```aipl
module tests.functions.net.live_reload_ref_02_test
import { applyLiveReloadDeltaPatch } from "std/net/live_reload_sync"
import { crc32 } from "std/crypto/hash"
import { assert, assertEqStr } from "std/prelude"
pub fn test_applyLiveReloadDeltaPatch_ref(): int:
  let base = "let score = 10"
  let target = "let score = 99"
  let c = crc32(target.toBytes())
  let res = applyLiveReloadDeltaPatch(base, 12, 2, "99", c)
  assert(res.isOk() == true, "patch applied")
  assertEqStr(res.unwrap(), target, "patched source matches")
  ret 0
```

---

### `buildUdpDiscoveryBeacon` (`std/net/live_reload_sync.aipl`)

- **Signature**: `pub fn buildUdpDiscoveryBeacon(deviceName: str, wsPort: int): str requires deviceName.len() >= 0 ensures result.startsWith("AIPL_WATCHER_BEACON|") and result.endsWith("|v1"):`
- **Import**: `import { buildUdpDiscoveryBeacon } from "std/net/live_reload_sync"`
- **Receiver**: `None (free function)` | **Parameters**: `deviceName: str, wsPort: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/net/live_reload_sync_test.aipl` | **Example**: `examples/ex_120_net_udp_datagram_broadcaster_cli.aipl`
- **Behavioral Summary**: Constructs a UDP broadcast discovery beacon datagram (`"AIPL_WATCHER_BEACON|<cleanDeviceName>|<port>|v1"`), sanitizing device names and clamping port numbers to the valid range (1024..65535, default 9477).

```aipl
module tests.functions.net.live_reload_ref_03_test
import { buildUdpDiscoveryBeacon } from "std/net/live_reload_sync"
import { assert } from "std/prelude"
pub fn test_buildUdpDiscoveryBeacon_ref(): int:
  let beacon = buildUdpDiscoveryBeacon("Pixel-9-Pro", 9477)
  assert(beacon.startsWith("AIPL_WATCHER_BEACON|Pixel-9-Pro|9477|v1"), "beacon formatted correctly")
  ret 0
```
