Bootloader
 └─> Kernel Initialization
      ├─> CPU/Platform Setup
      │    ├─> Basic hardware initialization (A20 gate, GDT, IDT, etc.)
      │    ├─> Switch to 32-bit protected mode
      │    └─> (Optional) SMP/ multicore startup
      ├─> Memory Management
      │    ├─> Physical memory manager (buddy / bitmap / etc.)
      │    ├─> Virtual memory manager (paging, page directory, page tables)
      │    └─> Kernel heap allocator (slab / kmalloc / etc.)
      ├─> Interrupts and Exceptions
      │    ├─> Interrupt Descriptor Table (IDT)
      │    ├─> Interrupt Service Routines (ISRs)
      │    └─> Exception handling (page fault, GPF, etc.)
      ├─> Task/Process Management
      │    ├─> Process control block (PCB) / thread control block (TCB)
      │    ├─> Context switching
      │    ├─> Privilege modes (Ring 0, Ring 3 for x86)
      │    ├─> Scheduling (Round-Robin, Priority, etc.)
      │    └─> Inter-Process Communication (IPC)
      ├─> Synchronization & Concurrency
      │    ├─> Spinlocks, semaphores, mutexes
      │    └─> Atomic operations (x86 `cmpxchg`, `xchg`, etc.)
      ├─> Filesystem Layer
      │    ├─> VFS (Virtual File System) abstraction
      │    ├─> Actual filesystems (FAT, ext2, etc.)
      │    └─> Disk drivers / block layer
      ├─> Device Drivers
      │    ├─> PCI enumeration
      │    ├─> Storage devices (ATA, SATA, NVMe, etc.)
      │    ├─> Input devices (keyboard, mouse)
      │    ├─> Display / Console device
      │    └─> Networking devices (if implementing TCP/IP stack)
      ├─> System Call Interface
      │    └─> Mechanisms to transition from Ring 3 to Ring 0 (int, sysenter, syscall)
      ├─> Networking Stack (if applicable)
      │    ├─> Ethernet, ARP, IP, TCP/UDP, etc.
      │    └─> Sockets, higher-level protocols
      └─> User Space and Libraries
           ├─> Standard C library / minimal libc
           └─> Shell, init process, user programs
