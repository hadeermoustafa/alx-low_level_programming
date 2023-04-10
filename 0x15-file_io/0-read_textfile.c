#include "main.h"

/**
 * Write a function that reads a text file and prints it to the POSIX standard output.
 * where letters is the number of letters it should read and print
 *
 * returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 *
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int file;
	int letters_read;
	int letters_written;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}

	letters_read = read(file, buffer, letters);
	if (letters_read <= 0)
	{
		close(file);
		free(buffer);
		return (0);
	}

	letters_written = write(STDOUT_FILENO, buffer, letters_read);
	close(file);
	free(buffer);

	if (letters_written != letters_read)
		return (0);

	return (letters_read);
}
