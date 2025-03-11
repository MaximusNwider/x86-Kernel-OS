# Required/Useful Algorithms

This branch includes essential algorithms that help in process scheduling, memory management, data integrity, and overall OS operations.

## Summary

* ### **Sorting**
  1. **Merge Sort**  
     - **Implementation Outline**: Divide-and-conquer, stable sort, O(n log n).  
     - **Notes / OS Usage**: Useful for sorted data in kernel modules, e.g., sorted device lists.

  2. **Quick Sort**  
     - **Implementation Outline**: Average O(n log n), worst O(n²), partition-based.  
     - **Notes / OS Usage**: Often used due to good average performance; watch out for worst-case.

  3. **Heap Sort**  
     - **Implementation Outline**: Builds a binary heap, repeatedly extracts min/max.  
     - **Notes / OS Usage**: Consistently O(n log n), easy in-place implementation.

---

* ### **Searching**
  1. **Linear Search**  
     - **Implementation Outline**: O(n) scan.  
     - **Notes / OS Usage**: Simple fallback for small arrays or unsorted data.

  2. **Binary Search**  
     - **Implementation Outline**: O(log n) on sorted arrays.  
     - **Notes / OS Usage**: Kernel symbol lookup, table lookups, or quick config searches.

  3. **Hash Lookup**  
     - **Implementation Outline**: O(1) average if well-dispersed hash.  
     - **Notes / OS Usage**: Inode cache lookups, name resolution, symbol tables.

---

* ### **Graph Traversals**
  1. **BFS (Breadth-First Search)**  
     - **Implementation Outline**: Uses a queue, visits neighbors layer by layer.  
     - **Notes / OS Usage**: Rare in small kernels, useful for network route analysis or complex dependency graphs.

  2. **DFS (Depth-First Search)**  
     - **Implementation Outline**: Recursion or explicit stack.  
     - **Notes / OS Usage**: Similar to BFS usage; can be used for advanced dependency checks.

---

* ### **Checksums & Hashing**
  1. **CRC**  
     - **Implementation Outline**: Polynomial-based checksum.  
     - **Notes / OS Usage**: Data integrity for file systems, network packets.

  2. **MD5 / SHA-1 / SHA-256**  
     - **Implementation Outline**: Cryptographic hash computations.  
     - **Notes / OS Usage**: More secure integrity checks or security-sensitive features.

---

* ### **String / Pattern Matching**
  1. **Naive**  
     - **Implementation Outline**: O(n·m) scanning.  
     - **Notes / OS Usage**: Simple usage in logs or error messages when performance is not critical.

  2. **KMP (Knuth-Morris-Pratt)**  
     - **Implementation Outline**: O(n + m) with preprocessing of the pattern.  
     - **Notes / OS Usage**: Faster string searches in kernel logs, user input checks.

  3. **Boyer-Moore**  
     - **Implementation Outline**: Typically fast in practice with large alphabets.  
     - **Notes / OS Usage**: Potentially used for advanced text searching in debugging or shell command parsing.

---

* ### **Locking Mechanisms**
  1. **Spinlocks**  
     - **Implementation Outline**: Busy-wait loop, typically `xchg`, `cmpxchg` on x86.  
     - **Notes / OS Usage**: Short critical sections, interrupt context in SMP kernels.

  2. **Mutexes / Semaphores**  
     - **Implementation Outline**: Sleep-based locks, track lock ownership or resource count.  
     - **Notes / OS Usage**: Longer critical sections, user-level or kernel-level concurrency.

---

* ### **Lock-free / Wait-free Structures**
  - **Implementation Outline**: Atomic operations (CAS) for enqueue/dequeue, hazard pointers for memory safety.  
  - **Notes / OS Usage**: High-performance concurrency, advanced SMP kernels.

---

* ### **Memory Allocation (Page Frames)**
  1. **Buddy Allocator**  
     - **Implementation Outline**: Splits memory into power-of-two blocks, merges buddies on free.  
     - **Notes / OS Usage**: Widely adopted for physical memory management.

  2. **Bitmap-based**  
     - **Implementation Outline**: 1 bit per page frame, set/clear on alloc/free.  
     - **Notes / OS Usage**: Simple approach, good for learning or smaller kernels.

---

* ### **Kernel Heap Allocation**
  1. **Slab / SLUB Allocator**  
     - **Implementation Outline**: Maintains slabs of objects of the same size.  
     - **Notes / OS Usage**: Reduces fragmentation, speeds up frequent allocations (e.g., task structs).

  2. **Simple “kmalloc”**  
     - **Implementation Outline**: Single large area with first-fit or best-fit approach.  
     - **Notes / OS Usage**: Easier to implement; can later evolve into a slab or buddy system.

---

* ### **Virtual Memory Paging**
  - **Implementation Outline**: 32-bit x86 uses page directories and page tables; handle page faults and TLB flushes.  
  - **Notes / OS Usage**: Core of process isolation, kernel-user separation, and dynamic memory.

---

* ### **CPU Scheduling**
  1. **Round-Robin**  
     - **Implementation Outline**: Simple cyclic queue of ready tasks, time-sliced.  
     - **Notes / OS Usage**: Good for basic time-sharing among processes.

  2. **Priority Scheduling**  
     - **Implementation Outline**: Assign priorities and pick the highest first.  
     - **Notes / OS Usage**: Real-time tasks or kernel threads with different importance levels.

  3. **Multi-Level Feedback Queue (MLFQ)**  
     - **Implementation Outline**: Multiple queues with aging, dynamic priority adjustment.  
     - **Notes / OS Usage**: More sophisticated, used in many general-purpose OSes.

---

* ### **I/O Scheduling**
  1. **FIFO**  
     - **Implementation Outline**: Process requests in arrival order.  
     - **Notes / OS Usage**: Very simple but may be suboptimal for seek times.

  2. **Elevator (SCAN / C-SCAN)**  
     - **Implementation Outline**: Move across the disk in one direction to minimize seek times.  
     - **Notes / OS Usage**: Improves disk performance by reducing head movement.

---

* ### **Filesystem Algorithms**
  1. **Directory Search**  
     - **Implementation Outline**: Linear scan vs. hashing for directory entries.  
     - **Notes / OS Usage**: Affects how quickly files are located in a directory.

  2. **Space Allocation**  
     - **Implementation Outline**: Linked blocks, indexed (inodes), or extent-based.  
     - **Notes / OS Usage**: Core of file storage; performance and fragmentation handling.

---

* ### **IPC Mechanisms**
  1. **Message Queues**  
     - **Implementation Outline**: Producer-consumer with ring buffer or linked list.  
     - **Notes / OS Usage**: Safe communication between processes or kernel subsystems.

  2. **Pipes**  
     - **Implementation Outline**: Unnamed pipe or FIFO with circular buffer.  
     - **Notes / OS Usage**: Common Unix-like IPC for unstructured data streams.

  3. **Shared Memory**  
     - **Implementation Outline**: Shared page frames with synchronization primitives.  
     - **Notes / OS Usage**: Fast data sharing, must handle concurrency carefully.

---
