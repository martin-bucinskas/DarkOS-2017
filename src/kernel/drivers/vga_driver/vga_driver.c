#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga_data.c"
#include "character_control.c"

#include "../../libs/data_structures/string.c"

enum vga_colour
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

static inline uint8_t vga_entry_colour(enum vga_colour fg, enum vga_colour bg)
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t colour)
{
	return (uint16_t) uc | (uint16_t) colour << 8;
}

struct VGA_Data vga_data = {0, 0, 0, 0, 80, 25};

void terminal_initialize(void)
{
	vga_data.terminal_row = 0;
	vga_data.terminal_column = 0;
	vga_data.terminal_colour = vga_entry_colour(LIGHT_GREEN, BLACK);
	vga_data.terminal_buffer = (uint16_t*) 0xB8000;

	for (size_t y = 0; y < vga_data.VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < vga_data.VGA_WIDTH; x++)
		{
			const size_t index = y * vga_data.VGA_WIDTH + x;
			vga_data.terminal_buffer[index] = vga_entry(' ', vga_data.terminal_colour);
		}
	}
}

void terminal_setcolour(uint8_t colour)
{
	vga_data.terminal_colour = colour;
}

void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y)
{
	const size_t index = y * vga_data.VGA_WIDTH + x;
	vga_data.terminal_buffer[index] = vga_entry(c, colour);
}

void terminal_scroll(void)
{
	for (size_t y = 0; y < vga_data.VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < vga_data.VGA_WIDTH; x++)
		{
			vga_data.terminal_row = 0;
			vga_data.terminal_column = 0;
		}
	}
}

void terminal_putchar(char c)
{
	//handle_control_char(c);

	if (is_char_a_control_char(c) > 0)
	{
		// Pass the VGA_Data struct by reference rather than by value.
		handle_control_char(c, &vga_data);
	}
	else
	{
		terminal_putentryat(c, vga_data.terminal_colour, vga_data.terminal_column, vga_data.terminal_row);
	}

	// If terminal is full, it will start at 0,0.
	if (++vga_data.terminal_column == vga_data.VGA_WIDTH)
	{
		vga_data.terminal_column = 0;
		if (++vga_data.terminal_row == vga_data.VGA_HEIGHT)
		{
			terminal_scroll();
			//TODO: Move all of the text 1 row above, place cursor at new line.
			//vga_data.terminal_row = 0;
		}
	}
}

void terminal_write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}
