#include "wc_lib.c"

int stoi(char *str){
	
	if(!str)
		return -1;
	
	int num = 0;
	while(*str!='\0'){

		if(*str < '0' || *str > '9')
			return -1;

		num += (*str) - '0';
		num*=10;
		str++;
	}
	
	return num/10;
}

void lines(int fd, int n){
	
	int newline_counter = 0;
	char current_character;
	
	int file_size = get_abs_bytes(fd);
	int file_lines = get_lines(fd);

	if(n > file_lines || n <= 0) 
		n = file_lines;

	for(int i = 0; i<file_size && newline_counter < n; i++){
		
		read(fd, &current_character, sizeof(char));
		printf("%c", current_character);

		if(current_character == '\n' || current_character == EOF)
			newline_counter++;
		
	}
}

