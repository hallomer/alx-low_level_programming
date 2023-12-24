#include "main.h"

#define BUFFER_SIZE 1024


/**
 * handle_error - Handles error messages
 * @exit_code: exit code
 * @error_message: error message
 *
 * Return: nothing
*/
void handle_error(int exit_code, const char *error_message, ...)
{
	va_list args;

	va_start(args, error_message);

	dprintf(STDERR_FILENO, "Error: ");

	switch (exit_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
		case 99:
		case 100:
			dprintf(STDERR_FILENO, error_message, args);
			break;
		default:
			dprintf(STDERR_FILENO, "Unknown error\n");
			break;
	}

	va_end(args);
	exit(exit_code);
}

/**
 * copy_file - Copies the content of one file to another file
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 *
 * Return: nothing
*/
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		handle_error(98, "Can't read from file %s\n", file_from);

	/*Open or create the destination file*/
	fd_to = open(file_to, O_WRONLY | O_CREAT |
			O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		handle_error(99, "Can't write to %s\n", file_to);

	/*Copy the content of the file*/
	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1)
			handle_error(99, "Can't write to %s\n", file_to);
	}

	/*Check for read error*/
	if (read_bytes == -1)
		handle_error(98, "Can't read from file %s\n", file_from);

	/*Close the file descriptors*/
	if (close(fd_from) == -1)
		handle_error(100, "Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		handle_error(100, "Can't close fd %d\n", fd_to);
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
	char *file_from, *file_to;

	if (argc != 3)
		handle_error(97, "Usage: cp file_from file_to\n");

	file_from = argv[1];
	file_to = argv[2];

	copy_file(file_from, file_to);

	return (0);
}
