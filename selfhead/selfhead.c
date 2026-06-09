/*\
    * selfhead - reimplementation of the unix head command
    *
    * Author: gitduck6 on github
    * Date June 9 2026
    *
    * Supported flags: [cnqvz]
\*/

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char cflag = 0, qflag = 0, zflag = 0;

int main(int argc, char ** argv)
{
    int c;
    while ((c = getopt(argc, argv, "cnqvz")) != -1)
    {
        switch (c)
        {
            case 'c':
                cflag = 1;
                break;
            case 'n':
                cflag = 0;
                break;
            case 'q':
                qflag = 1;
                break;
            case 'v':
                qflag = 0;
                break;
            case 'z':
                zflag = 1;
                break;
            default:
                break;            
        }
    }

    argc -= optind;
    argv += optind;

    
}