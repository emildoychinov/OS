#include "include.h"

int get_lines(int fd);

int m_strcmp(char *str1, char *str2){
	
	if(!str1 || !str2)
		return 0;

	for(str1, str2 ; *str1 != '\0' && *str2 != '\0' ; str1++, str2++)
		if(*str1 != *str2)
			return 0;

	return (*str1 == '\0' && *str2 == '\0') ? 1 : 0;

}

int get_abs_bytes(int fd){
	
	int bytes = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	return bytes;
}	

int get_bytes(int fd){
	return get_abs_bytes(fd) - get_lines(fd);
}

int get_lines(int fd){

	int file_size = get_abs_bytes(fd);
	char a; //current character

	int lines = 0;

	for(int i=0 ; i<file_size ; i++){
		
		int byte = read(fd, &a, sizeof(char));
		if(byte == 0)
			break;

		if(a == '\n' || a == EOF)
			lines++;
	}

	lseek(fd, 0, SEEK_SET);

	return lines;
}

