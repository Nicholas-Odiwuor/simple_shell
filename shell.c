#include "main.h"
/**
 * main - Entry point of Shell
 * @ac: Arguments counter
 * @av: Argument values
 * Return: Exit if success = 0
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{

	int int_mode = 1;
	int errcode = 0;


	errcode = errcode + 0;

	int_mode = isatty(STDIN_FILENO);
	if (int_mode == 0)
	{
		notty(av);
	}
	else
	{

		_interactive(av);
	}
	return (0);
}
