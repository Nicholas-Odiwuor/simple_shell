/**
 * Nicholas-Odiwuor
 */

#include <stdio.h>

/**
 * _compare - Compares two strings at a given position
 * @x: String to be compared
 * @y: String to compare
 * Return: Returns nothing
*/
int _compare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * _strstr - Compares two strings at a given position
 * @x: String to be compared
 * @y: String to compare
 * Return: The pointer to the first occurence
*/
char *_strstr(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && _compare(x, y))
			return (x);
		x++;
	}

	return (NULL);
}


/**
 * _strcpy - Function to copy the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}

/**
 * Nicholas-Odiwuor
 */
