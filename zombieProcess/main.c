/*
    Will be creating a zombie process.
        - A process that finished its task, but failed to report back to parent
        - can be fixed using wait()
        - can be created if we use exit(0) on child and not use wait() for parent
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    printf("Before forking\n");
    printf("Parent process ID: %d\n", getpid());

    // forking a child process
    pid_t proc1 = fork();

    // if process is a child
    if (proc1 == 0) {
        printf("I am a child zombie process!!\n");
        printf("Zombie process ID:%d\n", getpid());
        printf("Child process exiting...\n");
        exit(0);
    } else {
        printf("I am parent process with ID %d\n", getpid());
        sleep(2); // sims work
        printf("Parent process wait for child process...\n");
    }
    //wait(NULL); // note we didn't call wait(), thus creating a zombie process
    printf("Parent process is exiting....\n");
    exit(0);
}
