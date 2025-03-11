# Required/Useful Data Structures

This branch contains the source and header file implementations of necessary data structures utilized by different sections/parts of the kernel and the operating system. All are implemented in C.

## Summary

* ### **Linked Lists**
  1. **Singly Linked List**  
     - **Implementation Outline**: Each node has `data` and a pointer to the next node.  
     - **Notes / OS Usage**: Handy for simple queues, device driver lists, or small collections.

  2. **Doubly Linked List**  
     - **Implementation Outline**: Each node has `data`, a pointer to the next node, and a pointer to the previous node.  
     - **Notes / OS Usage**: Commonly used for scheduling queues, memory region tracking, or any scenario requiring back-and-forth iteration.

  3. **Circular Linked List**  
     - **Implementation Outline**: Tail node’s next pointer points back to the head, forming a ring.  
     - **Notes / OS Usage**: Good for round-robin schedulers or cyclic buffers.

---

* ### **Stacks**
  1. **Array-based Stack**  
     - **Implementation Outline**: Contiguous memory block with a top index that grows/shrinks.  
     - **Notes / OS Usage**: Used for call stacks in user/kernel space, small LIFO tasks.

  2. **Linked-list-based Stack**  
     - **Implementation Outline**: Push/pop at the head of a singly linked list.  
     - **Notes / OS Usage**: Dynamic size; simpler for certain embedded/low-level tasks.

---

* ### **Queues**
  1. **Array-based Queue (Circular Buffer)**  
     - **Implementation Outline**: A circular array with head/tail indices.  
     - **Notes / OS Usage**: Scheduler ready-queues, simple inter-process messaging.

  2. **Linked-list Queue**  
     - **Implementation Outline**: Enqueue at the tail, dequeue at the head via pointers.  
     - **Notes / OS Usage**: Suited for unbounded queues or OS messaging systems.

---

* ### **Priority Queue (Heap)**
  1. **Binary Heap**  
     - **Implementation Outline**: Stored in an array; `heapify` operations ensure O(log n) insertion/deletion.  
     - **Notes / OS Usage**: Priority scheduling (higher-priority tasks), timer event management.

---

* ### **Heaps (Memory Allocators)**
  1. **Buddy Allocator**  
     - **Implementation Outline**: Splits/merges memory blocks in powers of two.  
     - **Notes / OS Usage**: Common for physical page management in many kernels.

  2. **Bitmap-based Page Allocator**  
     - **Implementation Outline**: One bit per page frame; set/clear bits on alloc/free.  
     - **Notes / OS Usage**: Straightforward approach for page-based memory management.

  3. **Slab / SLUB Allocator**  
     - **Implementation Outline**: Caches frequently used kernel objects in slabs to reduce fragmentation.  
     - **Notes / OS Usage**: Linux-like method for efficient kernel object allocations (`kmalloc`).

---

* ### **Trees**
  1. **AVL or Red-Black Tree**  
     - **Implementation Outline**: Self-balancing BST with O(log n) insert, search, delete.  
     - **Notes / OS Usage**: Used in advanced schedulers (e.g., CFS in Linux), file system indexing, or any large ordered dataset.

  2. **Trie / Radix Tree**  
     - **Implementation Outline**: Prefix-based tree structure for storing key strings/bit sequences.  
     - **Notes / OS Usage**: Used for routing tables, or specialized indexing (e.g., networking or fast lookups).

---

* ### **Hash Tables**
  1. **Separate Chaining**  
     - **Implementation Outline**: Array of buckets (often linked lists).  
     - **Notes / OS Usage**: Inode caches, quick lookups for name-resolution in VFS, symbol tables.

  2. **Open Addressing**  
     - **Implementation Outline**: Linear probing, quadratic probing, or double hashing in a single array.  
     - **Notes / OS Usage**: Good for moderate-size lookups with lower memory overhead.

---

* ### **Bitmaps**
  - **Implementation Outline**: An array of bits, each representing a free/used resource.  
  - **Notes / OS Usage**: Page allocation tracking, block allocation in a filesystem.

---

* ### **Ring Buffers**
  - **Implementation Outline**: Circular buffer with head/tail pointers for producer/consumer.  
  - **Notes / OS Usage**: Device drivers (e.g., serial port), IPC channels, logging buffers.

---

* ### **Disjoint Set (Union-Find)**
  - **Implementation Outline**: Array-based parents, path compression, union by rank.  
  - **Notes / OS Usage**: Rare in simple kernels, but useful in advanced or clustered resource management.

---

* ### **Skiplists**
  - **Implementation Outline**: Linked list with multiple “levels” for faster search.  
  - **Notes / OS Usage**: Occasionally used where concurrency or lock-free operations are desired.

---

* ### **String / Buffer Management**
  - **Implementation Outline**: Safe string functions, dynamic resizing buffers, etc.  
  - **Notes / OS Usage**: Managing kernel logs, user input, or internal debugging messages.
