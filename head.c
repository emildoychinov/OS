#include "include/head_lib.c"

int main(int argc, char *argv[]){
	
	if(!argv[1]){
		fprintf(stderr, "no arguments provided\n");
		exit(0);
	}
	
	int fd = open(argv[1], O_RDONLY);
	int n = stoi(argv[2]); //the number of lines that we want 

	if(fd == -1){
		fprintf(stderr, "no such file named %s found\n", argv[1]);
		exit(0);
	}

	lines(fd, n);
	close(fd);

	exit(1);
}
