#include <stdio.h>
#include <string.h>

void print_hex(FILE* binary, int width){
  int c;
  int count = 0;

  while ((c = fgetc(binary)) != EOF) {
    count += 1;
    //printf("Count: %d\n", count);
    printf("%02x ", c);

    if(count == width){
      printf("\n");
      count = 0;
    }
  }

  if(count != 0){
    printf("\n");
  }
  return; 
}
/* todo: add support for multiple files as argument*/
int main(int argc, char *argv[]){
  
  if(argc != 2 || (argc == 2 && strcmp(argv[1],"--help")) == 0){
    printf("myhexdump - make a hex dump\n\nUsage:\n\t %s [arguments]\n", argv[0]);
    return 0;
  }
  
  FILE* binary = fopen(argv[1], "rb");
  if(binary == NULL){
    perror(argv[1]);
    return 1;
  }
  print_hex(binary, 8);

  return 0;
}
