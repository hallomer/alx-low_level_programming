#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, len = 0, write_result;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len] != '\0')
			len++;

		write_result = write(file_descriptor, text_content, len);
		if ((write_result == -1) | (write_result != len))
		{
			close(file_descriptor);
			return (-1);
		}

	}

	close(file_descriptor);
	return (1);
}
