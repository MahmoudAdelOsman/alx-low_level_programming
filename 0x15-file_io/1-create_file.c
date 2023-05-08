#include "main.h"

/**
 * create_file - Creates a file
 * @filename: A pointer to the name of the file
 * @text_content: A pointer to a string to write to the file
 * Return: If the function fails -1
 * or 1 if not.
 */

int create_file(const char *filename, char *text_content)
{
	int x, y, z = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (z = 0; text_content[z];)
			z++;
	}

	x = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	y = write(x, text_content, z);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
