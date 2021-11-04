#include <stdio.h>
#include <mach/mach_vm.h>
#include <mach/mach_init.h>
#include <mach-o/dyld.h>

void inject() __attribute__((constructor));

uintptr_t getBase() {
  return _dyld_get_image_vmaddr_slide(0)+0x100000000;
}

void inject() {
  uintptr_t base = getBase();
  char bytes[2] = {0x90, 0x90}; // nop nop
  char byte[1] = {0xC3}; // ret

  // turn off anticheat, stolen from camila which stole it from absolute
  mach_vm_protect(mach_task_self(), base+0x72351, 2, FALSE, 7 | VM_PROT_COPY);
  mach_vm_write(mach_task_self(), base+0x72351, &bytes, 2);

  // make PlayLayer::DestroyPlayer do nothing
  mach_vm_protect(mach_task_self(), base+0x7ab80, 1, FALSE, 7 | VM_PROT_COPY);
  mach_vm_write(mach_task_self(), base+0x7ab80, &byte, 1);
}