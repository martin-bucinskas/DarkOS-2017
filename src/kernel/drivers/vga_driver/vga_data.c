struct VGA_Data
{
	size_t terminal_row;
	size_t terminal_column;
	uint8_t terminal_colour;
	uint16_t* terminal_buffer;
	size_t VGA_WIDTH;
	size_t VGA_HEIGHT;
};
