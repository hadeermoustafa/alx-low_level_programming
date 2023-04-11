#include "main.h"

/**
 * create_file - reads a text file and prints it to the POSIX standard output
 *
 * @filename: name of the file to be read
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int word_count_one = 0, word_count_two, file_descriptor;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_descriptor < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[word_count_one])
			word_count_one++;

		word_count_two = write(file_descriptor, text_content, word_count_one);
		if (word_count_two != word_count_one)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
