#include "shell.h"

/**
 * lexer - Tokenizes the input line into commands and arguments.
 * @buffer: Input line to be tokenized.
 *
 * Return: Array of strings containing commands and arguments.
 */
char **lexer(char *buffer)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t bufsize = 0;
	size_t position = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (!tokens)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the input line using spaces as delimiters */
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		tokens[position++] = _strdup(token);

		/* Resize the tokens array if needed */
		if (position >= bufsize)
		{
			bufsize += MAX_TOKENS;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\n");
	}

	tokens[position] = NULL; /* Null-terminate the array of tokens */
	return tokens;
}

