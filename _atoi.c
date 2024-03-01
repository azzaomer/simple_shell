#include "shell.h"

/**
<<<<<<< HEAD
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
=======
 * _atoi - convert string to integer
 * @s: the string
 * Return: integer
>>>>>>> 1f3bcad18655b25f551e5308149ec66393471cef
 */

int _atoi(char *s)
{
<<<<<<< HEAD
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
=======
	unsigned int num = 0, sign = 1, started = 0;

	while (*s)
	{
		if (started && !(*s >= '0' && *s <= '9'))
			break;
		if (*s == '-')
			sign *= -1;
		if ((*s >= '0' && *s <= '9'))
		{
			started = 1;
			num =  num * 10 + (int)*s - 48;
		}
		s++;
	}
	return (sign * num);
>>>>>>> 1f3bcad18655b25f551e5308149ec66393471cef
}
