/*
 * hexdump - make a hexdump(no endianness considered, straight up bytes only)
 *
 * very clanky but probably works 
 *
 * Author: Vaykhan
 * Date: 2026
 *
 */

// Todo: add support for reversing hexdumps, and processing multiple files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
int print_equivalent(char byte){
  if(isprint((unsigned char)byte) && ( (unsigned char)byte == ' ' || !isspace((unsigned char)byte) )){
    return byte;
  }
  else {
    return '.';
  }
}

void offset_line(uint64_t offset){
  printf("%08lx: ", offset);
}

void hexadecimal_line(unsigned char buffer[], size_t n, size_t width ){
  for(size_t i = 0; i<n; i++){
    printf("%02x ", buffer[i]);

    if(i == width / 2 - 1){
      printf(" ");
    }
  }
    return;
}

void ascii_line(unsigned char buffer[], size_t n){
  printf("|");
  for(size_t i = 0; i<n;i++){
    printf("%c",print_equivalent(buffer[i]));
  }
  printf("|");
}


void print_hex(FILE* binary, int width){
  unsigned char *buffer;
  uint64_t n;
  long long int offset = 0;
  buffer = malloc(sizeof(unsigned char[width]));
  while((n = fread(buffer, 1, width, binary)) > 0 ){ //n is the number of bytes read
    if(ferror(binary)){
      perror("fread");
    }
    offset_line(offset);
    hexadecimal_line(buffer, n, width);
    ascii_line(buffer,n);
    offset += width;
    printf("\n");
  }
  printf("\n");
  free(buffer);
}


int main(int argc, char *argv[]){
  if(argc == 1){
    print_hex(stdin, 16); //use stdin if no argument provided
    return 0;
  }
  if(argc != 2 || strcmp(argv[1],"--help") == 0){
    printf("myhexdump - make a hex dump\n\nUsage:\n\t %s [arguments]\n", argv[0]);
    return 0;
  }

  
  FILE* binary = fopen(argv[1], "rb");
  if(binary == NULL){
    perror(argv[1]);
    return 1;
  }

  print_hex(binary, 16); //modify the width according to your needs


  fclose(binary);
  
  return 0;
}
