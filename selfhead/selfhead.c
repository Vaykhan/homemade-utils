/*\
    * selfhead - reimplementation of the unix head command
    *
    * Author: gitduck6 on github
    * Date June 9 2026
    *
    * Supported flags: [cnqvz]
    * 
    * Flags:
    * c: -c num : number of characters to print
    * n: -n num : number of lines to print, default
    * q: -q : quiet mode (doesnt tell name of the file)
    * v: -v : verbose mode (does tell name of the file, default)
    * z: -z : zero seperating mode, (prints a newline upon a nullbyte, FROM MY UNDERSTANDING ATLEAST)
    * i mean, my version does that for z but im unsure if this is the default behaviour
    * 
    * Simple by design and my stupidity
    * 
\*/

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

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
                num = strtoul(optarg, NULL, 10);
                cflag = 1;
                break;
            case 'n':
                num = strtoul(optarg, NULL, 10);
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

    do 
    {
        FILE* fp = stdin;

        if (*argv)
        {
            if (!strcmp(*argv,"-"))
            {
                fp = stdin;
            }
            else
            {
                fp = fopen(*argv, "r");
                if (fp == NULL)
                {
                    perror("fopen");
                    continue;
                }
            }
            
        }
        head_fp(fp,*argv);
        if (fp != stdin)
            fclose(fp);

    } while (*(++argv));

    return 0;
}

void head_fp(FILE *fp, char *filename)
{
    if (!qflag)
    {
        if (filename == NULL)
            filename = "standart input";
        printf("%s:\n",filename);
    }

    size_t counter = 0;
    int c;

    while ( ((c = fgetc(fp)) != EOF) && (counter < num))
    {
        if ((c == '\0') && (zflag))
        {
            fputc('\n',stdout);
        } else
            fputc(c,stdout);

        if (cflag)
            counter++;
        else if (c == '\n')
            counter++;
    }

    fputc('\n',stdout);
}
