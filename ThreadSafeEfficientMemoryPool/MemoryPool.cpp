//
// Created by corey on 1/8/23.
//

#include "MemoryPool.h"

template <typename T>
MemoryPool<T>::MemoryPool(std::size_t block_size, std::size_t num_blocks)
        : block_size_(block_size), memory_(new T[block_size * num_blocks]) {
    // Initialize the freelist
    //freelist_.reserve(num_blocks);
    for (std::size_t i = 0; i < num_blocks; i++) {
        freelist_.emplace(i);
    }
}

template <typename T>
MemoryPool<T>::~MemoryPool() {
    // Free the memory block
    delete[] memory_;
}

template <typename T>
T* MemoryPool<T>::allocate() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (freelist_.empty()) {
        // No free blocks available
        return nullptr;
    }

    // Take the first available block from the freelist
    std::size_t index = freelist_.top();
    freelist_.pop();
    return &memory_[index * block_size_];
}

template <typename T>
void MemoryPool<T>::deallocate(T* p) {
    std::lock_guard<std::mutex> lock(mutex_);
    // Find the block corresponding to the pointer
    std::ptrdiff_t index = p - memory_;
    if (index < 0 || static_cast<std::size_t>(index) % block_size_ != 0) {
        // The pointer does not belong to this memory pool
        return;
    }

    // Add the block to the freelist
    freelist_.emplace(index / block_size_);
}