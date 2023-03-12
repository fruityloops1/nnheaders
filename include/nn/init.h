/**
 * @file init.h
 * @brief Initialization functions for OS related functions.
 */

#pragma once

#include <nn/mem.h>
#include <nn/types.h>

namespace nn {
namespace init {
    void InitializeAllocator(void* addr, u64 size);
    extern nn::mem::StandardAllocator s_Allocator;
    inline nn::mem::StandardAllocator* GetAllocator() { return &s_Allocator; }

    namespace detail {
        void* DefaultAllocatorForThreadLocal(u64, u64);
        void* DefaultDeallocatorForThreadLocal(void*, u64);
    } // namespace detail
} // namespace init
} // namespace nn
