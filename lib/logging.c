#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "logging.h"
#include <unistd.h>

FILE *create_log_file()
{	
	FILE *fPtr = NULL;
	
	if(access("../logs/info.log", F_OK) == 0) {
		//file exists, append
		fPtr = fopen("../logs/info.log", "a");
	}
	else {
		fPtr = fopen("../logs/info.log", "w");
	}


	if(fPtr == NULL) {
		printf("Unable to create file\n");
		exit(EXIT_FAILURE);
	}


	return fPtr;

}

void write_log(FILE *fPtr, char *log_msg)
{		
	char date[1024];
	char log_message[1024];
	struct tm tm; //rename?
	time_t t;
	
	t = time(NULL);
	tm = *localtime(&t);
	snprintf(date, sizeof(date), "%d-%02d-%02dT%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	snprintf(log_message, sizeof(log_message), "%s %s", date, log_msg);

	fputs(log_message, fPtr);
	fputs("\n", fPtr);
	
}

char* get_second_token(char str[], char second_token[])
{	
 	strcpy(second_token, str);
    	second_token = strtok(second_token, " ");
    	second_token = strtok(NULL, " ");
    	return second_token;
}


void read_logs(char *program, FILE *log_file)
{
    	char chunk[128], second_token[128];
    
    	while(fgets(chunk, sizeof(chunk), log_file) != NULL) {
		char log[128];
		
		
		if(chunk != NULL && chunk[0] != '\0') {
			strncpy(log, get_second_token(chunk, second_token), 128);
			}
		
		
		if(strcmp(log,program) == 0) {
			fputs(chunk, stdout);
		}
		
    }
    
}

void read_all_logs(FILE *log_file)
{
    	char chunk[128];
    
    	while(fgets(chunk, sizeof(chunk), log_file) != NULL) {
			fputs(chunk, stdout);
    		}
    
}

void check_flags(int argc, char *argv[], FILE *log_file) {


		if(argc < 2) {
		//no arguments given
		read_all_logs(log_file);
		}
		else {
			if(strcmp(argv[1],"-P") == 0 || strcmp(argv[1],"--program") == 0) {
				if(argc < 3) {
				printf("You need to provide program's name\n");
			}
				else {
				//printf("Program you selected %s\n", argv[2]);
				read_logs(argv[2], log_file);
			} 
			
		}
	}


}















