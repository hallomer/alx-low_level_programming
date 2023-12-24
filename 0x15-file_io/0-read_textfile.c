#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: file to read
 * @letters: number of letters it should read and print
 *
 * Return: the actual number of letters it read and printed, or 0 if it fails
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int letters_written, file_descriptor, letters_read;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(letters + 1);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}


	letters_read = read(file_descriptor, buffer, letters);
	if (letters_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	letters_written = write(STDOUT_FILENO, buffer, letters_read);
	if (letters_written == -1 || letters_written != letters_read)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	close(file_descriptor);
	free(buffer);

	return (letters_written);
}
