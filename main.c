/*
    Program will create a simple process with a parent with a child
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
    /*
        Data type that will hold id(int) for process
        - can view ID with getpid()
    */
    printf("Before fork\n");

    pid_t proc1 = fork(); // forking proc, will include the unique iD

    // if the process is a child
    if (proc1 == 0) {
        printf("I am a child with ID %d\n", getpid());
        printf("My parent's ID is %d\n", getppid());
    } else { // if the proc is a parent
        printf("My child's ID is %d\n", proc1);
        printf("I am parent having an ID %d\n", getpid());
    }

}