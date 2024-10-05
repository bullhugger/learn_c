#include <stdio.h>
#include <string.h>
#include "functions.h"

void hello_world() {
  printf("%s", get_message());
}

void get_file_name() {
  printf("Enter the file name in this directory\n");
  char file_name[256];
  if(fgets(file_name, sizeof(file_name), stdin)) {
    size_t len = strlen(file_name);
    if(len > 0 && file_name[len-1] == '\n') {
      file_name[len-1] = '\0';
    }
    printf("File name is: %s\n", file_name);
  }
  else {
    printf("Error reading file name input\n");
  }
}
