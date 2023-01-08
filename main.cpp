#include <cstdlib>
#include <vector>
#include <cstdint>
#include "MemoryPool/MemoryPool.h"

int main() {
    MemoryPool<int> pool;
    pool.initialize(100);  // Initialize the memory pool with 100 objects

    // Allocate some objects from the pool
    int* p1 = pool.allocate();
    *p1 = 1;
    int* p2 = pool.allocate();
    *p2 = 2;
    int* p3 = pool.allocate();
    *p3 = 3;

    // Release an object back to the pool
    pool.release(p2);

    // Allocate another object from the pool
    int* p4 = pool.allocate();
    *p4 = 4;

    return 0;
}
