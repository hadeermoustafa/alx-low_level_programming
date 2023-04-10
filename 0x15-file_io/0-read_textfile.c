#include "main.h"

/**
 * The function that reads a text file 
 * and prints it to the POSIX standard output.
 *
 * it returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 *
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 * */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	char *buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}

	ssize_t letters_read = read(file, buffer, letters);
	if (letters_read <= 0)
	{
		close(file);
		free(buffer);
		return (0);
	}

	ssize_t letters_written = write(STDOUT_FILENO, buffer, letters_read);
	close(file);
	free(buffer);

	if (letters_written != letters_read)
		return (0);

	return (letters_read);
}
