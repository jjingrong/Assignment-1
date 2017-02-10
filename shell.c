#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#define CHUNK 255

int main() {
  int system(const char *command);
  
  char input[CHUNK];
  while(1) {
    printf(">");
    scanf("%s", input);
    printf("Input: %s",input);
    printf("\n");
    
    // Execute command
    system(input);
  }
}
