#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>
#include <stropts.h>

typedef enum {false, true} bool;

int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
int main(){
    printf("Hello processes\n");
    int p;
    p = fork();
    if (p==0){
        printf("Child process %d running..\n", getpid());
        printf("Child process stopped\n");
        exit(0);
    }
    else if (p>0){
        printf("Parent process %d running..\n", getppid());
        //sleep(10);
        while (1){
            if (_kbhit()) break;
        }
        wait(NULL);
        printf("Child terminated!\n");
    }
    else {
        printf("fork failed\n");
        return -1;
    }
    printf("Both processes finished.\n");
    return 0;
}