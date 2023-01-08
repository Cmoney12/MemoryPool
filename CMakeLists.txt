cmake_minimum_required(VERSION 3.24)
project(memory_pool)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory_pool main.cpp MemoryPool/MemoryPool.h MemoryPool/MemoryPool.cpp
        ThreadSafeMemoryPool/MemoryPool.h ThreadSafeMemoryPool/MemoryPool.cpp
        MoreEfficientMemoryPool/MemoryPool.cpp MoreEfficientMemoryPool/MemoryPool.h
        ThreadSafeEfficientMemoryPool/MemoryPool.cpp ThreadSafeEfficientMemoryPool/MemoryPool.h)
