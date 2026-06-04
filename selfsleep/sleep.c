/*\
    * Unix sleep utility - sleeps for the given amount of seconds
    * 
    * Author: gitduck6
    * Date: June 4 2026
\*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void usage(char * program_name);

int main(int argc,char ** argv)
{
    if (argc != 2)
        usage(argv[0]);

    struct timespec time = {0,0};
    char * str = *++argv;
    char is_float;

    for (; isdigit(*str); str++)
    {
        time.tv_sec *= 10;
        time.tv_sec += *str - '0';
    }

    if (*str == '\0')
        is_float = 0;
    else if (*str == '.')
        is_float = 1;
    else
    {
        fprintf(stderr,"\"%s\": Only intigers and floats are allowed\n",*argv);
        exit(2);
    }

    
    printf("inputted intiger is %d\n",time.tv_sec);
}

void usage(char * program_name)
{
    fprintf(stderr,"Usage: %s [seconds]\n",program_name);
    exit(1);
}