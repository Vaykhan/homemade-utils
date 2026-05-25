/*\
    * Reimplementation of unix pwd
    * Flag options: -LP
    * 
    * L stands for logical,
    * which means this prints the current working directory while accounting for symlink
    * (This is the default option)
    * 
    * P stands for physical,
    * which means it returns the current directory while ignoring symlinks
    * 
    * Author: gitduck6 on github
    * Date: May 25 2026
    * 
\*/
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pflag = 0;

char * getcwd_physical(void);
char * getcwd_logical(void);

int main(int argc, char **argv)
{
    char c;
    while ((c = getopt(argc,argv,"LP")) != -1)
    {
        switch (c)
        {
        case 'L':
            pflag = 0;
            break;
        case 'P':
            pflag = 1;
            break;
        default:
            pflag = 0;
            break;
        }
    }

    char * workdir;
    if (pflag)
        workdir = getcwd_physical();
    else
        workdir = getcwd_logical();

    printf("%s\n",workdir);

    if (pflag) free(workdir);
    // free if pflag (the case we malloced)

    return 0;

}

char * getcwd_physical(void)
{
    size_t size = 8;
    char *buff = malloc(size);

    while (getcwd(buff,size) == NULL)
    {
        size*=2;
        buff = realloc(buff,size);
    }

    return buff;
}

char * getcwd_logical(void)
{
    return getenv("PWD");
}