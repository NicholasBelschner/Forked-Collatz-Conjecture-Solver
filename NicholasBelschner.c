/* 
  This program takes an argument from the command line in order to execute the Collatz conjecture. 
  Using the fork() method to create two child processes that will execute two instances of the Collatz conjecture. 
  As a learning activity I inclued when the parent was waiting for her child process and a messeage saying they are done executing. 
  Task 2: The child processes are not guaranteed to execute in the order it is forked because of the wait(NULL) function. 
  The reason being is becasue it is dependent on the scheduling and execution of the processes by the operating system.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){

  pid_t pid = fork(); /* Creating the child using the fork method */
  int num1 = atoi(argv[1]); /* Changing the command argument into a integer */
  int num2 = num1 + 4;

  if(pid == -1){  /* Preparing for error in the creation of the child process */
    fprintf(stderr, "Fork Failed");
    return 1;
  
  }else if (pid == 0){  /* The child process will execute the block */
    printf("From Child1: pid = %d init: number = %d\n", getpid(), num1);
    while(num1 != 1){  /* While loop for the Collatz conjecture sequence */
      printf("From Child1: number = %d\n", num1);
      if(num1%2 == 0){ 
        num1 /= 2;  
      }else{
        num1 = (num1 * 3) + 1;
      }   
    }
    printf("From Child1: pid = %d Im done!\n", getpid());
  
  }else{  /* Now moving onto the second process */
    printf("This is the parent waiting\n");
    wait(NULL);  /* Telling the parent to wait for child2 using the wait() function */
    pid = fork();  /* Creating a child process */
    
    if(pid < 0){  /* Preparing for error in the creation of the child process */
      fprintf(stderr, "Fork Failed");
      return 1;

    }else if (pid == 0){  /* The child process will execute the block */
       printf("From Child2: pid = %d init: number = %d\n", getpid(), num2);
      while(num2 != 1){  /* While loop for the Collatz conjecture sequence */
        printf("From Child2: number = %d\n", num2);
        if(num2%2 == 0){
          num2 /= 2;
        }else{
          num2 = (num2 * 3) + 1;
        }
      }
      printf("From Child2: pid = %d Im done!\n", getpid());

    }else{  /* Telling user that all the child processes are completed */
      wait(NULL);
      printf("All of my children are complete\n");
    }
  }

  return 0;
}
