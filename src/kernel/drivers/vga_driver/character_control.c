/**
* Brief:
*	Checks if a character is a control character.
*	Checks if a character is a control character that is defined in an if statement.
*
* Args:
*	char c: Character to check.
*
* Returns:
*	0 - if a character is not a control character.
*	1 - if a character is a control character.
*
* TODO:	
*	Add all control characters in an array and do a loop?
*/
int is_char_a_control_char(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\0' || c == '\a' || c == '\b' || c == '\v' || c == '\f' || c == '\\')
		return 1;
	else
		return 0;
}

/**
* Brief:
*	Evaluates a control character.
*
* Args:
*	char c: Character to be evaluated.
*	struct VGA_Data: Pointer to the VGA_Data used by the VGA Driver.
*/
void handle_control_char(char c, struct VGA_Data *vga_data)
{
	// Create a local copy of vga_data then assign it back to original.
	struct VGA_Data vga_data_copy;	
	vga_data_copy = *vga_data;
	
	if (c == '\n') // Line Feed
	{
		vga_data_copy.terminal_column = 0;
		vga_data_copy.terminal_row++;
	}
	else if (c == '\t') // Horizontal Tab
	{
		vga_data_copy.terminal_column += 4;
	}
	else if (c == '\r') // Carriage Return
	{
		vga_data_copy.terminal_column = 0;
	}
	else if (c == '\0') // Null
	{
		// Ignored character or an end of a string.
		// Temporary just to hold char and not to evaluate it.
	}
	else if (c == '\a') // Bell
	{
		// Rings a bell (makes a sound).
		// Temporary just to hold char and not to evaluate it.
	}
	else if (c == '\b') // Backspace
	{
		vga_data_copy.terminal_column--;
	}
	else if (c == '\v') // Vertical Tab
	{
		vga_data_copy.terminal_row += 4;
	}
	else if (c == '\f') // Form Feed
	{
		char uc = ' ';
		uint16_t vga_clear_entry = (uint16_t) uc | (uint16_t) vga_data_copy.terminal_colour << 8;
		for (size_t y = 0; y < vga_data_copy.VGA_HEIGHT; y++)
		{
			for (size_t x = 0; x < vga_data_copy.VGA_WIDTH; x++)
			{
				const size_t index = y * vga_data_copy.VGA_WIDTH + x;
				vga_data_copy.terminal_buffer[index] = vga_clear_entry;
			}
		}

		vga_data_copy.terminal_column = 0;
		vga_data_copy.terminal_row = 0;
	}
	else if (c == '\\')
	{
		char uc = '\\';
		uint16_t vga_clear_entry = (uint16_t) uc | (uint16_t) vga_data_copy.terminal_colour << 8;
		const size_t index = vga_data_copy.terminal_row * vga_data_copy.VGA_WIDTH + vga_data_copy.terminal_column;
		vga_data_copy.terminal_buffer[index] = vga_clear_entry;
	}

	*vga_data = vga_data_copy;
}
