#include "include/tail_lib.c"

int main(int argc, char *argv[]){
	
	if(argc < 2){
		fprintf(stderr, "no arguments provided\n");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);

	int n = 10; // initial value, that's how our code works

	if(argc > 2){
		if(m_strcmp(argv[2], "-n")){

			if(argc == 3) {
				fprintf(stderr, "expected an argument after '-n' flag\n");
				close(fd);
				exit(1);
			}

			if(argc > 3){
				n = stoi(argv[3]);
			}
		}

		else {
			fprintf(stderr, "flag '%s' not recognized\n", argv[2]);
			close(fd);
			exit(1);
		}
	}

	if(fd == -1){
		fprintf(stderr, "no such file named %s found\n", argv[1]);
		close(fd);
		exit(1);
	}

	e_lines(fd, n);
	close(fd);

	exit(0);

}
