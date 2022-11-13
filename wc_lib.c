#include "include.h"

int get_lines(int fd);

int m_strcmp(char *str1, char *str2){
	
	if(!str1 || !str2)
		return 0;
	
	
	for(str1, str2 ; *str1 != '\0' && *str2 != '\0' ; str1++, str2++)
		if(*str1 != *str2)
			return 0;
	
	//ternary fuckery (not so bad here) that we will see in other parts of the code
	//will explain where needed 
	//not good practice tbh but once again i'm too lazy to write quality code (and its shorter :D)
	
	return (*str1 == '\0' && *str2 == '\0') ? 1 : 0;

}

int get_abs_bytes(int fd){
	
	int bytes = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	return bytes;
}	

int get_bytes(int fd){
	//i wasnt really sure what the convention for total bytes is so i used to subtract the number of newlines
	
	int bytes = get_abs_bytes(fd);
	
	//ternary shits (handling the possibility of lseek returning -1)
	return (bytes == -1 ) ? 0 : bytes /*- get_lines(fd)*/; 
}

int get_lines(int fd){

	int file_size = get_abs_bytes(fd);
	if(file_size == -1)
		return 0;

	char a; //current character

	int lines = 0;

	for(int i=0 ; i<file_size ; i++){
		
		int byte = read(fd, &a, sizeof(char));
		if(byte == 0)
			break;

		if(a == '\n' || a == EOF)
			lines++;
	}

	if( lseek(fd, 0, SEEK_SET) == -1)
		return 0;

	return lines;
}

