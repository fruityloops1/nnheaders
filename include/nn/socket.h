/**
 * @file socket.h
 * @brief Functions for opening sockets for wireless communication.
 */

#pragma once

#ifdef __cplusplus

#include <nn/types.h>
#include <nn/util.h>
#include <sys/socket.h>

struct in_addr;

namespace nn {
namespace socket {

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
    struct InAddr {
        u32 addr;
    };
#else
    using InAddr = ::in_addr;
#endif

    Result Initialize(void* pool, ulong poolSize, ulong allocPoolSize, int concurLimit);
    Result Finalize();
    s32 SetSockOpt(s32 socket, s32 socketLevel, s32 option, void const*, u32 len);
    s32 GetSockOpt(s32, s32, s32, void*, unsigned int*);
    u64 Send(s32 socket, void const* buffer, u64 bufferLength, s32 flags);
    s32 SendTo(s32 socket, const void* data, ulong dataLen, s32 flags, const sockaddr* address,
        u32 addressLen);
    u32 Recv(s32 socket, void* buffer, u64 bufferLength, s32 flags);
    u32 RecvFrom(s32 socket, void* buffer, u64 bufferLength, s32 flags, sockaddr* srcAddress,
        u32* addressLen);
    s32 Socket(s32 domain, s32 type, s32 proto);
    u16 InetHtons(u16);
    u32 InetAton(const char* str, InAddr*);
    u32 Connect(s32 socket, const sockaddr* addr, u32 addrLen);
    u32 Bind(s32 socket, const sockaddr* addr, u32 addrLen);
    u32 Listen(s32 socket, s32 backlog);
    u32 Accept(s32 socket, sockaddr* addrOut, u32* addrLenOut);
    u32 GetLastErrno();
    u32 Close(s32);
    s32 Shutdown(s32, s32);
    s32 Poll(pollfd*, u64, s32);

} // namespace socket
} // namespace nn

extern "C" {
#endif

#include <stdint.h>

uint16_t nnsocketInetHtons(uint16_t x);
uint32_t nnsocketInetHtonl(uint32_t x);
uint16_t nnsocketInetNtohs(uint16_t x);
uint32_t nnsocketInetNtohl(uint32_t x);

#ifdef __cplusplus
}
#endif
