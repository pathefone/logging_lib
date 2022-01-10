

FILE *create_log_file();

void write_log(FILE *fPtr, char *log_msg);

void read_logs(char *program, FILE *log_file);

char* get_second_token(char str[], char second_token[]);

void read_all_logs(FILE *log_file);

void check_flags(int argc, char *argv[], FILE *log_file);
