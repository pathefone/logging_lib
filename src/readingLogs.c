#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h> //for strcmp
#include "../lib/logging.h"

int main(int argc, char *argv[])
{
	FILE *fPtr = NULL;
	fPtr = fopen("../logs/info.log", "r");
	

	check_flags(argc, argv, fPtr); //read logs
	fclose(fPtr);
	return 0;
}
