#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>



void test_monitor(void)
{
	terminal_initialize();

	terminal_setcolour(vga_entry_colour(BLACK, WHITE));

	while(0 == 0)
	{
		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("|");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("/");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("-");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("\\");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("|");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("/");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("-");
			}
		}

		terminal_initialize();

		for (size_t y = 0; y < 25; y++)
		{
			for (size_t x = 0; x < 80; x++)
			{
				terminal_writestring("\\");
			}
		}
	}
}
