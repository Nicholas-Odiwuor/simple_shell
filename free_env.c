/**
 * Nicholas-Odiwuor
 */

#include "main.h"

/**
* free_env - To free tokenized path directories and user arguments
* @env_args: Tokenized environment directories
* @args: Tokenized user commands
* Return: Nothing
*/

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		freedom(2, env_args);
	}
	freedom(2, args);
}


/**
 * Nicholas-Odiwuor
 */
