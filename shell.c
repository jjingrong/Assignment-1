/*
    Name: Lim Jing Rong
    Matric: A0114395E
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_LENGTH 255

int main() {
  // Function to run command
  int system(const char *command);
  // Variable to read input
  char input[MAX_LENGTH];
  
  // Infinite loop to await command
  while(1) {
    // Read in command
    printf(">");
    fgets(input, MAX_LENGTH, stdin);
    
    // Process management
    int pid;
    if ((pid = fork()) > 0 ) {
      // Create a new process, printing out the new process’s pid.
      printf("Loading new process with id %d\n", pid);
    } else if (pid == 0) {
      // In the child, print the pid of the parent, and load and execute the command entered by the user.
      printf("Parent pid: %d\n", getppid());
      // Execute command
      system(input);
      printf("\n");
    } else {
    // Print an error message if the command cannot be found or some other problem occurs.
      perror("fork failed");
    }
  }
}
