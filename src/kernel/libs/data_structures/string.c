#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
* Brief:
*	Returns the length of a string.
*
* Args:
*	char* str: String to be checked.
*
* Returns:
*	size_t length: The length of a string given.
*
*/
size_t strlen(const char* str)
{
	size_t length = 0;

	while (str[length])
		length++;

	return length;
}
