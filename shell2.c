/*
    Name: Lim Jing Rong
    Matric: A0114395E

    Name: Leonardo Sjahputra
    Matric: A0114088H
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define MAX_LENGTH 255

extern char **environ;

int main(int argc, char *argv[]) {
  // Function to run command
  // int system(const char *command);
  // Variable to read input
  char input[MAX_LENGTH];
  
  // Infinite loop to await command
  
  while(1) {
    // Read in command
    printf(">");  
    fgets(input, MAX_LENGTH, stdin);
    // get rid of newline
    size_t ln = strlen(input) - 1;
    if (*input && input[ln] == '\n') 
      input[ln] = '\0';
    
    // Process management
    int pid;
    if ((pid = fork()) > 0 ) {
      // Create a new process, printing out the new process’s pid.
      printf("Loading new process with id %d\n", pid);
      wait(0);
    } else if (pid == 0) {
      // In the child, print the pid of the parent, and load and execute the command entered by the user.
      printf("Parent pid: %d\n", getppid());
      // get command and arguments
      char *argsv[16]; // max 15 args
      const char *delim = " ";
      int i = 0;
      char *tok = strtok(input, delim);
      while (tok != NULL)
      {
        argsv[i] = malloc(strlen(tok) + 1);
        strcpy(argsv[i], tok);
        // printf("[%s]\n", tok);
        tok = strtok (NULL, delim);
        i++;
      }

      // set env
      char shellPath[MAX_LENGTH];
      getcwd(shellPath, MAX_LENGTH);
      strcat(shellPath, "/");
      strcat(shellPath, argv[0]);
      int envReturn = setenv("SHELL_PATH", shellPath, 1); // will overwrite the existing value, if exists
      if(envReturn == -1)
      {
        perror("setenv error");
      }
      // Execute command
      // system(input);
      int execReturn = execvp(argsv[0], argsv);
      if(execReturn == -1)
      {
        perror("Shell error");
      }

      printf("\n");
      _exit(0);
    } else {
    // Print an error message if the command cannot be found or some other problem occurs.
      perror("fork failed");
    }
  }
}
