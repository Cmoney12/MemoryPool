//
// Created by corey on 1/8/23.
//

#ifndef MEMORY_POOL_MEMORYPOOL_H
#define MEMORY_POOL_MEMORYPOOL_H

#include <cstddef>
#include <mutex>
#include <new>
#include <stack>

template <typename T>
class MemoryPool {
public:
    MemoryPool(std::size_t block_size, std::size_t num_blocks);
    ~MemoryPool();

    T* allocate();
    void deallocate(T* p);

private:
    std::size_t block_size_;
    T* memory_;
    std::stack<std::size_t> freelist_;
    std::mutex mutex_;
};


#endif //MEMORY_POOL_MEMORYPOOL_H
