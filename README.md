# Concurrency 2

**CS 444 - Operating Systems II**

**Tarren Engberg April 29th, 2018**

## 1. Produce the Executable File

To build the executable file for this assignment, simply navigate to the directory of this assignment's files in a terminal and type 'make'. An executable file titled "concurrency2_engbergt" will be generated. To run it in the terminal, type "./concurrency2_engbergt". The program will begin to execute and you will see an output of philosopers getting and putting forks throughout the course of their dinner. This program will execute indefinitely, to stop it, simply type 'control + c'.
Note that some string output looks strange as occasionally multiple threads of execution are printing to cout at the same time.