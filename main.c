#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Exit status.
 */
int main(int argc, char *argv[])
{
    char *input_line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 1)
    {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Check if shell is in interactive mode */
            write(STDOUT_FILENO, "($) ", 4);

        read = getline(&input_line, &len, stdin);
        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Process the input line using your shell functionality */
        process_input(input_line);

        /* Free allocated memory for getline */
        free(input_line);
        input_line = NULL;
        len = 0;
    }

    /* Free memory and perform any necessary cleanup before exiting */
    free(input_line);

    return EXIT_SUCCESS;
}

