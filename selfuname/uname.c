/*
 * uname - Unix name tool reimplementation
 * Largely inspired by OpenBSD utils
 * 
 * Author: gitduck6 on github
 * Date: May 23 2026
 * 
 * (Trying to mimic the format of the other utils)
 * 
 * possible flags -> amnrspv
 *
*/

#define _DEFAULT_SOURCE // For linux portability

#include <sys/param.h>
#include <sys/utsname.h>

#include <stdio.h>
#include <unistd.h>

#define PRINT_SYSNAME       0x01 // -s
#define PRINT_HOSTNAME      0x02 // -n
#define PRINT_RELEASE       0x04 // -r
#define PRINT_VERSION       0x08 // -v
#define PRINT_MACHINE       0x10 // -m
#define PRINT_MACHINE_ARCH  0x20 // -p
#define PRINT_ALL           0x3F // -a

int main(int argc, char **argv)
{
    struct utsname name;
    uname(&name);

    char uname_mask = 0;

    while (getopt(argc,argv,"snrvmpa") != -1)
    {

        switch (*optarg)
        {
        case 's':
            uname_mask |= PRINT_SYSNAME;
            break;
        case 'n':
            uname_mask |= PRINT_HOSTNAME;
            break;
        case 'r':
            uname_mask |= PRINT_RELEASE;
            break;
        case 'v':
            uname_mask |= PRINT_VERSION;
            break;
        case 'm':
            uname_mask |= PRINT_MACHINE;
            break;
        case 'p':
            uname_mask |= PRINT_MACHINE_ARCH;
            break;
        case 'a':
            uname_mask |= PRINT_ALL;
            break;  
        default:
            uname_mask |= PRINT_SYSNAME;
            break;
        }

    }

    return 0;
}