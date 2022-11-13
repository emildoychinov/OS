#include "wc_lib.c"

int main(int argc, char *argv[]){
	
	if(!argv[1]){
		fprintf(stdout, "no arguments provided\n");
		exit(1);
	}	
	
	//flags if an operation is already done so we dont do it again
	int lines = 0;
	int bytes = 0;

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		fprintf(stdout, "cannot find such file named '%s'\n", argv[1]);
		exit(1);
	}

	

	//i dont really check if an invalid flag is given 
	//if that's the case our output will be either the bytes & lines of the file
	//or either the bytes or lines (depends if we were given one flag that is valid and one that is not)
	

	//these if's are a bunch of bullshit but i'm too lazy to write quality code :D
	
	if( !m_strcmp(argv[2], "-l") && !m_strcmp(argv[2], "-c") && !m_strcmp(argv[3], "-l") && !m_strcmp(argv[3], "-c") ) {
		
		fprintf(stdout, "%d\n%d\n", 
			get_lines(fd), get_bytes(fd));
		
		exit(0);
	}

	if( m_strcmp(argv[2], "-l") ) {
		
		lines = 1;
		fprintf(stdout, "%d\n", get_lines(fd));

	}

	else if( m_strcmp(argv[2], "-c") ) {
		
		bytes = 1;
		fprintf(stdout, "%d\n", get_bytes(fd));
	}

	if ( m_strcmp(argv[3], "-l") && lines != 1) {
		
		lines = 1;
		fprintf(stdout, "%d\n", get_lines(fd));
	}

	else if( m_strcmp(argv[3], "-c") && bytes != 1){
		
		bytes = 1;
		fprintf(stdout, "%d\n", get_bytes(fd));
	}	
	
	close(fd);



	exit(0);
}
