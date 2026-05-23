/*
 * uname - Unix name tool reimplementation
 * Largely inspired by OpenBSD utils
 * 
 * Author: gitduck6 on github
 * Date: May 23 2026
 * 
 * (Trying to mimic the format of the other utils)
 *
*/

#include <sys/param.h>
#include <sys/utsname.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    struct utsname name;
    uname(&name);

    printf("%s",name.sysname);
    
    return 0;
}