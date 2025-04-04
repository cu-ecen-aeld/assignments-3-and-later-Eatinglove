#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void write_file(const char *filename, const char *content){
	FILE *file = fopen(filename, "w");
	if(file == NULL){
		syslog(LOG_ERR, "Error when open %s", filename);
		perror("Error opening");
		exit(EXIT_FAILURE);
	}

	if(fputs(content, file)== EOF){
	    syslog(LOG_ERR, "Error writing to %s", filename);
	    perror("Error writing");
	    fclose(file);
	    exit(EXIT_FAILURE);
	}

        syslog(LOG_DEBUG, "Writing \"%s\" to %s", content, filename);
	fclose(file);
}


int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr, "Error: Two arguments required: <file_path> <writing_string>\n");
		exit(EXIT_FAILURE);
	}

	const char *file_path = argv[1];
	const char *content = argv[2];
	openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
	write_file(file_path,content);
	closelog();
}
