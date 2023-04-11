#include "main.h"

/**
 * This function takes a filename and a text content string as input.
 * 
 * if filename is NULL return -1
 *if text_content is NULL create an empty file
 */

int create_file(const char *filename, char *text_content)
{
	int file;
	int text_length;
	int bytes_written;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file < 0)
		return (-1);

	if (text_content != NULL)
	{
		text_length = strlen(text_content);
		bytes_written = write(file, text_content, text_length);
		if (bytes_written != text_length)
			return (-1);
	}

	close(file);
	return (1);
}
