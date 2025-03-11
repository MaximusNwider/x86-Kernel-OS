# Operating System Hierarchy

## 1. **Bootloader**
   - **Responsibilities**:
     - Initialize basic CPU state (e.g., enable the A20 line on x86).
     - Load the kernel image (and possibly modules) from disk/ROM into memory.
     - Transition from real mode to protected mode (32-bit).
     - Set up initial stack, GDT, and minimal IDT for early exception handling.
     - Pass control to the kernel’s entry point (e.g., `_start`).

## 2. **Kernel Initialization**
   - **CPU and Platform Setup**  
     - Configure the **Global Descriptor Table (GDT)**: Segment descriptors, TSS (Task State Segment) if using hardware task-switching.  
     - Initialize the **Interrupt Descriptor Table (IDT)**: Basic handlers for exceptions (divide by zero, page faults) and interrupts (timer, keyboard).  
     - Set up any **APIC / PIC** (Advanced Programmable Interrupt Controller or legacy 8259 PIC) for managing hardware interrupts.  
     - (Optional) **SMP Initialization**: On multi-core systems, boot secondary cores, synchronize them, and create per-CPU structures.
       
   - **Memory Management**
     - **Physical Memory Detection**: Use BIOS memory map or multiboot info to find available RAM regions.  
     - **Page Frame Allocation**: Initialize either a Buddy or Bitmap-based allocator for physical pages.  
     - **Virtual Memory Setup**: Create and enable page directories/page tables, possibly high mapping of kernel (e.g., at 0xC0000000).  
     - **Kernel Heap**: Initialize a dynamic allocator (e.g., slab/SLUB or a simpler kmalloc-based approach).

   - **Device Discovery**  
     - **PCI Enumeration**: Scan PCI buses to detect devices (storage, network, graphics, etc.).  
     - Initialize basic drivers required for kernel operation (e.g., console/serial for logging).

   - **Core Subsystems**  
     - Initialize **Scheduler** data structures (ready queues, idle tasks).  
     - Set up **Process/Thread Management** structures (process list, TCBs, etc.).  
     - Register **Syscall Interface** (interrupt gate or sysenter for user-kernel transitions).

## 3. **Interrupts and Exceptions**
   - **IDT Setup**: Detailed mapping of exception vectors (0–31) and interrupt vectors (32–255).
   - **Interrupt Service Routines (ISRs)**: Provide basic handlers for CPU exceptions (page fault, GPF, etc.).  
   - **Interrupt Request Handling**: Handle hardware interrupts (timer, keyboard, network) and pass control to device drivers or scheduler.  
   - **Exception Handling**: Display error info, possibly kill or signal the faulty process, handle recoverable exceptions (e.g., page fault in on-demand paging).

## 4. **Task/Process Management**
   - **Process Control Blocks (PCB) / Thread Control Blocks (TCB)**:
     - Structures holding CPU state (registers), page tables, open file handles, scheduling info.
   - **Context Switching**:  
     - Save current task’s CPU state and restore the next task’s state.  
     - Possibly use hardware task switching (via TSS) or software-based context switch routines.
   - **Privilege Modes**:
     - Typically Ring 0 (kernel) and Ring 3 (user).  
     - Set up segment descriptors or paging flags to isolate user processes.
   - **Scheduling**:
     - Data structures (run queues, priority queues, MLFQ).  
     - Timer interrupts to periodically preempt running tasks.  
     - Load balancing or per-CPU run queues on SMP systems.
   - **Inter-Process Communication (IPC)**:
     - Shared memory, message queues, signals/events, pipes, or sockets.  
     - Mechanisms for processes/threads to synchronize data or send messages.

## 5. **Synchronization & Concurrency**
   - **Spinlocks**: Used in short critical sections, interrupt-safe locking on SMP.  
   - **Mutexes / Semaphores**: Sleep-based locks for longer sections where spinning would waste CPU.  
   - **Atomic Operations**: Use x86 instructions like `xchg`, `cmpxchg`, `lock` prefix for concurrency.  
   - **Lock-free / Wait-free Data Structures** (Optional advanced feature).

## 6. **Filesystem Layer**
   - **VFS (Virtual File System)** Abstraction:
     - Provides a uniform interface (open, read, write, etc.) regardless of the actual filesystem type.  
   - **Filesystem Implementations**:
     - **Basic**: FAT12/FAT16/FAT32 for simplicity, or ext2 for a more Unix-like approach.  
     - **Advanced**: Ext3/ext4 with journaling, or custom solutions if desired.
   - **Directory & Inode Management**:
     - Store metadata (permissions, ownership, timestamps).  
     - Directory lookup strategies (linear vs. hashed vs. tree-based).
   - **Block and Buffer Caches**:
     - Keep frequently accessed data in memory to reduce disk I/O.

## 7. **Device Drivers**
   - **PCI Bus**: Enumerate devices, set up BARs, manage interrupts.  
   - **Storage Drivers**: e.g., ATA, SATA, NVMe, handling block read/write.  
   - **Input Drivers**: Keyboard, mouse, possibly PS/2 or USB.  
   - **Display/Console**: Text-mode VGA or a framebuffer approach for graphics.  
   - **Network Drivers**: Ethernet (e.g., Intel e1000), Wi-Fi (complex), plus higher network layers (TCP/IP stack).

## 8. **System Call Interface**
   - **Entry Methods**:
     - Software interrupt (`int 0x80` or similar).  
     - Sysenter/sysexit (faster system call mechanism on newer x86).  
   - **System Call Table**:
     - Mapping of function IDs to kernel handlers (e.g., `sys_read`, `sys_write`, `sys_fork`, etc.).  
   - **Parameter Passing**:
     - Registers (EAX, EBX, ECX, EDX) or stack-based.  
   - **User-Kernel Boundary Handling**:
     - Validate pointers from user space, manage copy to/from user buffers.

## 9. **Networking Stack**
   - **Ethernet Layer**: MAC framing, ARP for IP resolution.  
   - **IP (IPv4 or IPv6)**: Basic packet routing, fragmentation, checksums.  
   - **Transport Layers**: TCP/UDP, connection handling, port management.  
   - **Socket Abstraction**: Provide a standard BSD-like socket API for user processes.

## 10. **User Space and Libraries**
   - **Init Process**: The first user-space process, typically sets up environment.  
   - **Shell / Command Interpreter**: Allows user-level commands, script execution.  
   - **System Utilities**: Basic file manipulation (cp, rm, ls), text editors, etc.  
   - **C Library (libc)**: Minimal or full POSIX-like library for user applications.  
   - **Dynamic Linking / ELF Loader** (Advanced): If supporting dynamic executables.

