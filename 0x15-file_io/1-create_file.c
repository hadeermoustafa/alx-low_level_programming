#include "main.h"

/**
 * This function takes a filename and a text content string as input.
 * 
 * if filename is NULL return -1
 *if text_content is NULL create an empty file
 */

int create_file(const char *filename, char *text_content)
{
	int fl;
	int text_length;
	int bytes_written;

	if (!filename)
		return (-1);

	fl = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fl < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[text_length])
			text_length++;

		bytes_written = write(fl, text_content, text_length);
		if (bytes_written != text_length)
			return (-1);
	}

	close(fl);
	return (1);
}
