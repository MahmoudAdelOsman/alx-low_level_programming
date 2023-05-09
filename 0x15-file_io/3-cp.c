#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int x);

/**
  * create_buffer - copies the content of a file to another file
  * @file: The name of the file buffer is storing chars for
  * Return: A pointer to the newly-allocated buffer
  */

char *create_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
  * close_file - Closes file descriptors
  * @x: The file descriptor to be closed
  */

void close_file(int x)
{
	int a;

	a = close(x);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close x %d\n", x);
		exit(100);
	}
}

/**
  * main - Copies the contents of a file to another file
  * @argc: The number of arguments supplied to the program
  * @argv: An array of pointers to the arguments
  * Return: 0
  * Description: If the argument count is incorrect - exit code 97
  * If file_from does not exist or cannot be read - exit code 98
  * If file_to cannot be created or written to - exit code 99
  * If file_to or file_from cannot be closed - exit code 100
  */

int main(int argc, char *argv[])
{
	int f, t, w, r;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	r = read(f, buf, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		w = write(t, buf, r);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		r = read(f, buf, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(buf);
	close_file(f);
	close_file(t);

	return (0);
}
