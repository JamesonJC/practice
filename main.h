#ifndef MAIN_H
#define MAIN_H

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <string.h>
#include <signal.h>

/*Global variable decleration*/
#define RECIEVEDSIG 0
#define BUFFER 1024
#define PROMPT "cisfun$ "

/*Functions prototypes*/
void non_interactive(void);
void interactive(char **av, char **env);
pid_t exe(char **argv,char **av,char **env);

#endif
