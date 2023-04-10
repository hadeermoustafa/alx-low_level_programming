#include "main.h"

/**
 * This function takes a filename and the number of letters to read
 * from the file as input. It opens the file using the open system call, reads the
 * specified number of letters into a buffer using the read system call, and then
 * writes the contents of the buffer to standard output using the write system
 * call.
 *
 * The function returns the actual number of letters read and printed on
 * success, and 0 on failure, which includes cases where the file cannot be
 * opened or read, or if the write operation fails to write the expected amount
 * of bytes to standard output. If the filename is NULL, the function also
 * returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return 0;

	int file = open(filename, O_RDONLY);
	if (file == -1)
		return 0;

	char *buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return 0;
	}

	ssize_t letters_read = read(file, buffer, letters);
	if (letters_read <= 0)
	{
		close(file);
		free(buffer);
		return 0;
	}

	ssize_t letters_written = write(STDOUT_FILENO, buffer, letters_read);
	close(file);
	free(buffer);

	if (letters_written != letters_read)
		return 0;

	return letters_read;
}
