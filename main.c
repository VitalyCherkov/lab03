#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doProg.h"

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Arguments: two names of files\n");
    return EXIT_FAILURE;
  }
  return doProg(argv[1], argv[2]);
}
