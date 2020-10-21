#include <pthread.h> // for thread functions
#include <stdio.h> // for i/o
#include <sys/wait.h> // for wait() 
#include <unistd.h> // for fork() 
#include <stdlib.h> // for exit()

pthread_mutex_t tlock; // lock for thread functions to run in order (as an exercise).
pthread_mutex_t lock; // lock for printf resource.

void* print1(void* msg) {
    pthread_mutex_lock(&tlock);
    pthread_mutex_lock(&lock);
    printf("%s \n", (char*)msg);
    pthread_mutex_unlock(&lock);
    sleep(1);
    pid_t id = fork();
    if (id > 0) {
        //Parent if id is positive
        int status;
        wait(&status);
        pthread_mutex_lock(&lock);
        printf("Child exited successfully with status: %i !\n", status);
        pthread_mutex_unlock(&lock);
    }
    else if (id == 0) {
        //Child if id is zero
        pthread_mutex_lock(&lock);
        printf("Hello from the child!\n");
        pthread_mutex_unlock(&lock);
        return 0;
    }
    else {
        //id is negative meaning the fork was unsuccessful.
        pthread_mutex_lock(&lock);
        printf("Failed to make child process. :(\n");
        pthread_mutex_unlock(&lock);
    }
    pthread_mutex_lock(&lock);
    printf("Message 1.2 \n");
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&tlock);
}

void* print2(void* msg) {
    pthread_mutex_lock(&tlock);
    pthread_mutex_lock(&lock);
    printf("%s \n", (char*)msg);
    printf("Message 2.2 \n");
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&tlock);
}

int main() {
    pthread_t  th1, th2;
    char* msg1 = "Thread 1: ";
    char* msg2 = "Thread 2: ";
    (void)pthread_create(&th1, NULL, print1, (void*)msg1);
    (void)pthread_create(&th2, NULL, print2, (void*)msg2);
    //Should be in order
    (void)pthread_join(th1, NULL);
    (void)pthread_join(th2, NULL);
    return 0;
}