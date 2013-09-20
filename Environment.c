#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	char *chArr;
       	if(NULL != getenv(argv[1]) )
	{
		chArr = getenv(argv[1]);
		printf("%s\n",chArr);
	}

	else
	{
		printf("don't have this Envi\n");
	}

	exit(0);
}
