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

void head_fp(FILE *fp, char *filename);

char cflag = 0, qflag = 0, zflag = 0;
size_t num = 10;

int main(int argc, char ** argv)
{
    int c;
    while ((c = getopt(argc, argv, "c:n:qvz")) != -1)
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

    char* end;
    num = strtol(optarg,end,10);

    if ((end == optarg))
    

    argc -= optind;
    argv += optind;


}

void head_fp(FILE *fp, char *filename)
{
    if (!qflag)
        printf("%s:\n",filename);

    size_t counter = 0;
    int c;

    while ( ((c = fgetc(fp)) != EOF) && (counter < num))
    {
        fputc(c,stdout);

        if (cflag)
            counter++;
        else if (c == '\n')
            counter++;
    }
}
