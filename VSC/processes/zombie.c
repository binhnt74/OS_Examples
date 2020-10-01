#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/ioctl.h>
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
void main(){
    printf("Hello processes\n");
    int p;
    p = fork();
    if (p==0){
        printf("Child process %d running..\n", getpid());
        while (1){
            if (_kbhit()) break;
        }
        printf("Child process stopped\n");
    }
    else if (p>0){
        printf("Parent process %d running..\n", getppid());
        //exit(0);
        wait(NULL);
    }
    else {
        printf("fork failed\n");
        return;
    }
    printf("Both processes running..\n");
}