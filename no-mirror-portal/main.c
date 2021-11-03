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
	char byte[1] = {0xC3};

	// make PlayLayer::toggleFlipped do nothing
	mach_vm_protect(mach_task_self(), base+0x7bdc0, 1, FALSE, 7 | VM_PROT_COPY);
	mach_vm_write(mach_task_self(), base+0x7bdc0, &byte, 1);
}