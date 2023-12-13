#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

/* Maximum length for a command */
#define MAX_COMMAND_LENGTH 1024

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);

#endif /* SHELL_H */

