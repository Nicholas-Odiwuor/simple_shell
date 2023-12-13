/**
 * Nicholas-Odiwuor
 */


#include "main.h"
/**
 * env_func - Prints eviroment variables
 * Return: 0 On success
*/
int env_func(void)
{
	int counter = 0, lenght = 0;

	while (environ[counter] != NULL)
	{
		lenght = strlarge(environ[counter]);
		write(STDOUT_FILENO, environ[counter], lenght);
		write(STDOUT_FILENO, "\n", 1);
		counter++;
	}
	return (0);
}



/**
 * Nicholas-Odiwuor
 */
