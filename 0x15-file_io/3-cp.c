#include "main.h"

#define BUFFER_SIZE 1024

/**
 * copy_file - Copies the content of one file to another file
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 *
 * Return: 0 on success
 */
int copy_file(int file_from, int file_to)
{
	int bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to file descriptor %d\n", file_to);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file descriptor %d\n", file_from);
		exit(98);
	}

	return (0);
}

/**
 * main - Copies the content of a file to another file
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT |
			O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	copy_file(file_from, file_to);

	if (close(file_from) == -1)
	{
		dprintf(2, "Error: Can't close file descriptor %d\n", file_from);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(2, "Error: Can't close file descriptor %d\n", file_to);
		exit(100);
	}

	return (0);
}
