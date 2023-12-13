#include "shell.h"

int main(void)
{
    char *line;
    int status;

    do
    {
        printf("($) ");
        line = read_line();

        if (line != NULL)
        {
            status = execute_command(line);
            free(line);
        }
        else
        {
            status = 1; // End of file or error condition
        }

    } while (status);

    return EXIT_SUCCESS;
}

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return NULL; // End of file or error condition
    }

    // Remove the newline character
    if (line[strlen(line) - 1] == '\n')
    {
        line[strlen(line) - 1] = '\0';
    }

    return line;
}

int execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        return 1; // Error condition
    }

    if (child_pid == 0)
    {
        // Child process
        if (execlp(command, command, (char *)NULL) == -1)
        {
            perror("execlp");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status))
        {
            // Child process exited normally
            return 0;
        }
        else
        {
            // Child process did not exit normally
            return 1;
        }
    }
}

