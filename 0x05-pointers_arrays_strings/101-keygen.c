#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/**
 * main - enerates random valid passwords the program 101-crackme
 *
 * Return: 0
*/

int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	int i;
	
	srand(time(NULL));

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		password[i] = rand() % ('~' - '!') + '!';
	}

	password[PASSWORD_LENGTH] = '\0';
	
	printf("%s\n", password);
	return (0);
}
