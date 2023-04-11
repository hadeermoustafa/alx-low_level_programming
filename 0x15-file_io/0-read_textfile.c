#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, or 0 on failure
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
