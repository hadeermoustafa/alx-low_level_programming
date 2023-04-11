#include "main.h"

/**
 * This function creates a file
 * 
 * Return: 1 if it succeeds, -1 if it fails.
 */
int createFile(const char *filename, char *textContent)
{
	int fileDesc;
	int numLetters;
	int result;

	if (!filename)
		return (-1);

	fileDesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fileDesc == -1)
		return (-1);

	if (!textContent)
		textContent = "";

	for (numLetters = 0; textContent[numLetters]; numLetters++)
		;

	result = write(fileDesc, textContent, numLetters);

	if (result == -1)
		return (-1);

	close(fileDesc);

	return (1);
}
