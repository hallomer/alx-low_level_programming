#include "main.h"

#define MAXSIZE 1024


/**
 * handle_error - Handles error messages
 * @error: error code
 * @str: string to print
 * @fd: file descriptor
 *
 * Return: 0 on success
*/
int handle_error(int error, char *str, int fd)
{
	switch (error)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(error);
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
			exit(error);
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
			exit(error);
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(error);
		default:
			return (0);
	}
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
	int file_from, file_to, read_stat, write_stat, close_from, close_to;
	char buffer[MAXSIZE];

	if (argc != 3)
		handle_error(97, NULL, 0);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		handle_error(98, argv[1], 0);

	file_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_to == -1)
		handle_error(99, argv[2], 0);

	while ((read_stat = read(file_from, buffer, MAXSIZE)) != 0)
	{
		if (read_stat == -1)
			handle_error(98, argv[1], 0);

		write_stat = write(file_to, buffer, read_stat);
		if (write_stat == -1)
			handle_error(99, argv[2], 0);
	}
	close_from = close(file_from);
	if (close_from == -1)
		handle_error(100, NULL, file_from);

	close_to = close(file_to);
	if (close_to == -1)
		handle_error(100, NULL, file_to);

	return (0);
}
