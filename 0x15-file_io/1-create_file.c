#include "main.h"

/**
 * create_file - This function creates a file with the given name and writes the
 * text content to it using system calls.
 *
 * @filename: The name of the file to be created
 * @text_content: The text content to be written to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int t_length = 0;
	int tc;
	int file_descriptor;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_descriptor < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[text_length])
			text_length++;

		tc = write(file_descriptor, text_content, t_length);
		if (tc != t_length)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
