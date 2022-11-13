#include "head_lib.c"

int get_cursor_position(int fd, int n){
	
	int file_size = get_abs_bytes(fd);
	int newlines = 0;
	int bytes = 1; //bytes we go back by
	char a;
	
	if(n > file_size || n <= 0)
		n = file_size;

	for(int i=0; i<file_size, newlines < n+1; i++){
		
		lseek(fd, -bytes * sizeof(char), SEEK_END);

		int status = read(fd, &a, sizeof(char));		
		
		if(status == 0)
			break;

		if(a == '\n' || a == EOF)	
			newlines++;

		bytes++;

	}
	
	if( lseek(fd, 0, SEEK_SET) == -1)
		return 0;

	return bytes-2;	
	
}

void e_lines(int fd, int n){ //end lines
	
	int file_size = get_abs_bytes(fd);
	char a;
	int cur_pos = get_cursor_position(fd, n);
	
	lseek(fd, -cur_pos * sizeof(char), SEEK_END);

	while(read(fd, &a, sizeof(char)))
		write(1, &a, sizeof(char)); 


}
