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
	terminal_writestring("Developed by \tMartin B.");

	terminal_setcolour(vga_entry_colour(RED, BLACK));	
	terminal_writestring("Testing double back slash \\this is working?\n");

	for (size_t i = 0; i < 30; i++)
	{
		terminal_writestring("Testing terminal scrolling...\n");
	}

	terminal_writestring("Should display on screen!\n");
}
