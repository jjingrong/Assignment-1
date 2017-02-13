/*
  Name: Lim Jing Rong
  Matric: A0114395E

  Name: Leonardo Sjahputra
  Matric: A0114088H
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char** envp) {
  char** env;
  char *searchTermValue;
  char *tempString;
  char *searchTerm = "SHELL_PATH=";
  
  // Printing all environmental vars (b)
  for (env = envp; *env != 0; env++) {
    char* line = *env;
    printf("%s\n", line);
    
    // Finding Search Term
    tempString = strstr(line, searchTerm);
    if (tempString) { // Found
      // Storing the value, excluding the 'SEARCHTERM='
      searchTermValue = tempString + strlen(searchTerm);
    }
  }
  
  printf("\n");
  // Print Search Term
  if (!searchTermValue) {
    searchTermValue= "UNKNOWN";
  } 
  
  printf("SHELL_PATH value is %s\n", searchTermValue);
  printf("\n");
  
  return(0);
}
