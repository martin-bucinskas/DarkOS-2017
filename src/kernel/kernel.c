#include <stdio.h>
#include <kernel/tty.h>

#if defined(__linux__)
#error "Not using a cross compiler!"
#endif

#if !defined(__i386__)
#error "Not using an x86-i386 compiler!"
#endif

void kernel_main(void)
{
  terminal_initialize();
  printf("printf works?\n");
}
