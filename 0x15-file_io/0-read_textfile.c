#include <stdio.h>
#include "main.h"

/**
 *  read_textfile- Read text file and print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: x - actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *mem;
	ssize_t fd;
	ssize_t x;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);
	mem = malloc(sizeof(char) * letters);
	t = read(fd, mem, letters);
	x = write(STDOUT_FILENO, mem, t);

	free(mem);
	close(fd);
	return (x);
}
