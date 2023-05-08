#include "main.h"
#include <stdlib.h>

/**
  * read_textfile - Read reads a text file and prints it
  * to the POSIX standard output.
  * @filename: Text file being read
  * @letters: Number of letters to be read
  * Return: Actual number of letters it could read and print
  * or 0 if not
  */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *a;
	ssize_t x;
	ssize_t y;
	ssize_t z;

	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);

	a = malloc(sizef(char) * letters);
	y = write(STDOUT_FILENO, a, z);
	z = read(x, a, letters);

	free(a);
	close(x);
	return (y);
}
