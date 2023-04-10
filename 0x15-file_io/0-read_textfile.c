#include "main.h"

/**
 * Description: This function takes a filename and the number of letters to read
 * from the file as input. It opens the file, reads the specified number of letters
 * into a buffer, and then writes the contents of the buffer to standard output.
 * The function returns the actual number of letters read and printed on success,
 * and 0 on failure, which includes cases where the file cannot be opened or read,
 * or if the write operation fails to write the expected amount of bytes to standard
 * output. If the filename is NULL, the function also returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		return 0;
	}

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}

	char buffer[letters];
	ssize_t letters_read = fread(buffer, sizeof(char), letters, file);

	if (letters_read <= 0)
	{
		fclose(file);
		return 0;
	}

	ssize_t letters_written = fwrite(buffer, sizeof(char), letters_read, stdout);
	fclose(file);

	if (letters_written != letters_read)
	{
		return 0;
	}

	return letters_read;
}

