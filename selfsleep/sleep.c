/*\
    * Unix sleep utility - sleeps for the given amount of seconds
    * 
    * Author: gitduck6
    * Date: June 4 2026
    * ----
    * The software is very minimal and only takes seconds. but it does handle decimal points which is great
    * I hope the code is readible, simplified it as much as i could
\*/

#define _DEFAULT_SOURCE

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
    char * str = argv[1];
    char is_float;

    for (;isdigit(*str); str++)
    {
        time.tv_sec *= 10; // moves the previous digit 1 index left
        time.tv_sec += *str - '0'; // subtracting '0' turns an ascii value to the intiger value (if it IS a digit)
    }

    if (*str == '\0')
        is_float = 0;
    else if (*str == '.')
        is_float = 1;
    else
    {
        fprintf(stderr,"\"%s\": Only positive intigers and floats are allowed\n",argv[1]);
        return 2;
    }

    
    if (is_float)
    {
        str++; 

        for (int multiplier = 100000000;isdigit(*str);multiplier /= 10)
        {
            time.tv_nsec += multiplier * (*str - '0'); // the very small values will be ignored since the multiplier will become a zero
            str++;
        }

        if (*str != '\0')
        {
            fprintf(stderr,"\"%s\": Only positive intigers and floats are allowed\n",argv[1]);
            return 3;
        }
    }

    nanosleep(&time,NULL);
    // finally this uses our timespec function

    return 0;

}

void usage(char * program_name)
{
    fprintf(stderr,"Usage: %s [seconds]\n",program_name);
    exit(1);
}