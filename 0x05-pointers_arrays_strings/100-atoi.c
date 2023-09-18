#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer
 *
 * Return: 0
*/

int _atoi(char *s)
{
	int result = 0;
	bool isNegative = false;

    for(int i = 0; s[i] != '\0'; ++i) {
        if(s[i] == '-' && (i == 0 || s[i-1] == '+' || s[i-1] == '-'))
            isNegative = true;
        else if(s[i] == '+' && (i == 0 || s[i-1] == '+' || s[i-1] == '-'))
            isNegative = false;
        else if(s[i] >= '0' && s[i] <= '9')
            result = result * 10 + (s[i] - '0');
    }

    return isNegative ? -result : result;

}
