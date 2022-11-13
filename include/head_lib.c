#include "wc_lib.c"

//some argument handling util......
int stoi(char *str){
	
	if(!str)
		return -1;
	
	int num = 0;

	while(*str!='\0'){

		if(*str < '0' || *str > '9')
			return -1; //if an argument that is not a number is passed we recognize that and return -1 (negative values are handled)

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
		
		//we dont really need to error check here since it's sure that we will read a character
		//that is because we are in the bounds of the file at all times

		int byte = read(fd, &current_character, sizeof(char));
		
		//if(!byte == 0)
			//break;

		printf("%c", current_character);

		if(current_character == '\n' || current_character == EOF)
			newline_counter++;
		
	}
}
