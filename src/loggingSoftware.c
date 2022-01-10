#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h> //for strcmp
#include "../lib/logging.h"

int main(int argc, char *argv[])
{

	FILE *fPtr = create_log_file();
	FILE *log_messages = NULL;
	log_messages = fopen("../data/log_messages1.csv", "r");
	char chunk[128];
    
    	while(fgets(chunk, sizeof(chunk), log_messages) != NULL) {
		
		chunk[strcspn(chunk, "\n")] = 0;
		write_log(fPtr, chunk);	//write log messages using lib	
		sleep(1);
	}
    
    	fclose(log_messages);
	fclose(fPtr);

	return 0;
}
