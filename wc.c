#include "include/wc_lib.c"

int main(int argc, char *argv[]){
	
	if(argc < 2){
		fprintf(stderr, "no arguments provided\n");
		exit(1);
	}	
	
	//flags if an operation is already done so we dont do it again
	int lines = 0;
	int bytes = 0;

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		fprintf(stderr, "cannot find such file named '%s'\n", argv[1]);
		close(fd);
		exit(1);
	}

	

	//i dont really check if an invalid flag is given 
	//if its one invalid flag we will get no output
	//if there is a valid flag before or following the invalid one we will get either lines or bytes
	

	//these if's are a bunch of bullshit but i'm too lazy to write quality code :D
	
	
	if(argc < 3) {
		
		fprintf(stdout, "%d\n%d\n", 
			get_lines(fd), get_bytes(fd));
		
	}

	else if(argc >= 3){	
		

		if( m_strcmp(argv[2], "-l") ) {
		
			lines = 1;
			fprintf(stdout, "%d\n", get_lines(fd));

		}

		else if( m_strcmp(argv[2], "-c") ) {
		
			bytes = 1;
			fprintf(stdout, "%d\n", get_bytes(fd));
		}

		if (argc >= 4) {
			if ( m_strcmp(argv[3], "-l") && lines != 1) {
		
				lines = 1;
				fprintf(stdout, "%d\n", get_lines(fd));
			}

			else if( m_strcmp(argv[3], "-c") && bytes != 1){
			
				bytes = 1;
				fprintf(stdout, "%d\n", get_bytes(fd));
			}
		}

	}	

	close(fd);



	exit(0);
}
