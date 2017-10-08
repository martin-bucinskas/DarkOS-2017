#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "drivers/vga_driver/vga_driver.c"
#include "programs/monitor_test.c"

#if defined(__linux__)
#error "Not using a cross compiler!"
#endif
 
#if !defined(__i386__)
#error "Not using an x86-i386 compiler!"
#endif

void kernel_main(void)
{
	terminal_initialize();

	terminal_setcolour(vga_entry_colour(RED, BLACK));	
	terminal_writestring("DarkOS");

	terminal_setcolour(vga_entry_colour(BLACK, RED));	
	terminal_writestring("2017\n");

	terminal_setcolour(vga_entry_colour(RED, BLACK));	
	terminal_writestring("Developed by Martin B.");

	test_monitor();
}
