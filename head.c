#include "include/head_lib.c"

int main(int argc, char *argv[]){
	
	if(argc < 2){
		fprintf(stderr, "no arguments provided\n");
		exit(1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	int n = (argc >=2 ) ? stoi(argv[2]) : -1; //the number of lines that we want 

	if(fd == -1){
		fprintf(stderr, "no such file named %s found\n", argv[1]);
		exit(1);
	}

	lines(fd, n);
	close(fd);

	exit(0);
}
