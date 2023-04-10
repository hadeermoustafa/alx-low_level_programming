#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 *
 * @filename: The name of the file to read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 *
 * Description: This function takes a filename and the number of letters to read
 * as input. It opens the file using the open system call, reads the specified
 * number of letters from the file into a buffer using the read system call, and
 * then writes the contents of the buffer to the standard output using the write
 * system call. The function returns the actual number of letters read and
 * printed. If the file cannot be opened or read, or if the write operation
 * fails, the function returns 0. If filename is NULL, the function also returns 0.
 */
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
