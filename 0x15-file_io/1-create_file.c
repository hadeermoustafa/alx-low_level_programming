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

	if (text_content)
	{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ae8802d30f627f29893b0f7ba567f0630b0a083a
		while (text_content[text_length])
			text_length++;

		bytes_written = write(fl, text_content, text_length);
=======
		text_length = strlen(text_content);
		bytes_written = write(file, text_content, text_length);
>>>>>>> parent of b6afad3... debug
		if (bytes_written != text_length)
			return (-1);
	}

	close(file);
	return (1);
}
