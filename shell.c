#include <stdio.h>
#define CHUNK 200
int main() {
  char command[CHUNK];
  while(1) {
    printf(">");
    scanf("%s", command);
    printf("Input: %s",command);
    printf("\n");
  }
}
