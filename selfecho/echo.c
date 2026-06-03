/*\
 * Minimal implementation of the unix echo command
 *
 * Author: gitduck6 from github
 * Date: May 25
 * 
 * minimal by design and my stupidity :>
 *
\*/

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
	int nflag = 0;

	argv++;
	if (*argv && !strcmp(*argv, "-n"))
	{
		nflag = 1;
		argv++;
	}

	while (*argv)
	{
		printf("%s",*argv);
		if (*++argv) putchar(' ');
	}

	if (!nflag) putchar('\n');

	return 0;
}
