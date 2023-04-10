#include "main.h"

/**
 * This function takes a filename and a text content string as input.
 * It creates a file with the given name using the open system call, with the
 * permissions rw-------. If the file already exists, its contents are truncated.
 * The text content is then written to the file using the write system call. If
 * text_content is NULL, an empty file is created. The function returns 1 on
 * success and -1 on failure, which includes cases where the file cannot be
 * created, written, or if the write operation fails.
 */

int create_file(const char *filename, char *text_content)
{
	int file;
	int text_length;
	int bytes_written;

	if (filename == NULL)
	{
		return (-1);
	}

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file < 0)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		text_length = strlen(text_content);
		bytes_written = write(file, text_content, text_length);
		close(file);

		if (bytes_written != text_length)
		{
			return (-1);
		}
	}
	else
	{
		close(file);
	}

	return (1);
}
