# PeachOS Kernel — Boot Pipeline & Components

> Minimal x86 kernel that brings up VGA text I/O, GDT/TSS, paging, IDT/ISR80h, keyboard, FS/disk, and a tiny process loader + scheduler.

## Boot Pipeline (diagram)
If present in your repo, this image will render the sequence at a glance:
![Boot Pipeline](.doc/flowchart.svg)

## Quick Description
- **Console:** VGA text at `0xB8000` with simple `print`, newline, and backspace handling.
- **Protection rings:** 6-entry GDT (null, kernel code/data, user code/data, TSS) with `lgdt`, plus `ltr` to activate the TSS.
- **Memory:** Kernel heap allocator; 4 GB paging (present, writeable, user-accessible). Switch `cr3` then enable paging.
- **Interrupts:** IDT initialized; ISR 0x80 command table registered.
- **I/O device:** Keyboard driver initialized.
- **Storage & FS:** Disks probed; filesystem layer initialized.
- **Userland bootstrap:** Loads `0:/blank.elf` twice, injecting different argv strings; then starts the first task.

## High-Level Sequence (mirrors the diagram)
- `kernel_main` → terminal init → build & load GDT → init TSS → `ltr`
- Heap → FS → Disk → IDT
- Create paging map → `cr3` switch → enable paging
- Register ISR80h commands → keyboard init
- `process_load_switch("0:/blank.elf")` → inject `"Testing!"`
- `process_load_switch("0:/blank.elf")` → inject `"Abc!"`
- `task_run_first_ever_task()` → kernel spins in idle loop

## Default Selectors & Stacks
| Item | Value |
|---|---|
| Kernel code selector | `0x08` |
| Kernel data selector | `0x10` |
| User code selector | `0x18` |
| User data selector | `0x20` |
| TSS selector | `0x28` |
| Ring-0 stack (TSS.esp0) | `0x600000` |

## Files
- `README.md` — this document.
- `flowchart.svg` — optional static flow diagram (no Mermaid dependency).
- `kernel.manifest.toml` — optional human-readable descriptor for boot sequence & defaults.