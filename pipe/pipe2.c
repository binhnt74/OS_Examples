#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
    char pname[] = "./bin/mypipe.p";
	pid_t pid;
	//int fd[2];

	/* create named pipe */
    if (mkfifo(pname, 0664) ==-1){
        fprintf(stderr,"Pipe failed");
		return 1;
    }
	/* now fork a child process */
	pid = fork();
    
	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
    int fd;

	if (pid == 0) {  /* child process */
		/* close the unused end of the pipe */
		//close(fd[READ_END]);
		printf("Child is writing [%s] to pipe...\n", write_msg);
        fd = open(pname, O_WRONLY);
        if (fd == -1){
            fprintf(stderr, "File open failed");
		return 1;
        }
		/* write to the pipe */
		write(fd, write_msg, strlen(write_msg)+1); 

		/* close the write end of the pipe */
		close(fd);
	}
	else { /* parent process */
		/* close the unused end of the pipe */
		//close(fd[WRITE_END]);

		/* read from the pipe */
        fd = open(pname, O_RDONLY);
        if (fd == -1){
            fprintf(stderr, "File open failed in child");
		return 1;
        }
		read(fd, read_msg, BUFFER_SIZE);
		printf("Parent read from pipe: %s\n",read_msg);

		/* close the write end of the pipe */
		close(fd);
	}

	return 0;
}
