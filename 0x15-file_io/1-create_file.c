#include "main.h"

/**
 * createFile - This function creates a file with the given name and writes the
 * text content to it using system calls.
 *
 * @filename: The name of the file to be created
 * @textContent: The text content to be written to the file
 *
 * Return: 1 on success, -1 on failure
 */

int createFile(const char *filename, char *textContent)
{
	int lenFirst;
	int lenSecond;
	int fileDesc;

	if (!filename)
		return (-1);

	fileDesc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fileDesc < 0)
		return (-1);

	if (textContent)
	{
		while (textContent[lenFirst])
			lenFirst++;

		lenSecond = write(fileDesc, textContent, lenFirst);
		if (lenSecond != lenFirst)
			return (-1);
	}

	close(fileDesc);
	return (1);
}
