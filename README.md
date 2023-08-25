# Forked-Collatz-Conjecture-Solver
Implementation of the Collatz conjecture using the fork() method to create two child processes.
This program takes an argument from the command line in order to execute the Collatz conjecture. 
Using the fork() method to create two child processes that will execute two instances of the Collatz conjecture. 
As a learning activity I inclued when the parent was waiting for her child process and a messeage saying they are done executing.
Task 2: The child processes are not guaranteed to execute in the order it is forked because of the wait(NULL) function. 
The reason being is becasue it is dependent on the scheduling and execution of the processes by the operating system.
