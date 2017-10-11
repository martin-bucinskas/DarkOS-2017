#ifndef ARCH_I386_VGA_H
#def ARCH_I386_VGA_H

/**
* Brief:
*   16 bit colour scheme to be used.
*/
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

#endif
