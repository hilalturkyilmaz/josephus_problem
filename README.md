This project provides a solution to the Josephus problem using C. The Josephus problem involves n people standing in a circle, with every second person being eliminated until only one survives. This solution includes both a standard C version and a Linux version that utilizes fork() to manage child processes for each elimination.

Project Structure
josephus.c: The standard C version of the Josephus problem (no fork()).
josephus_linux.c: The Linux version of the program that uses fork() and child processes to handle eliminations.
Operating_System_Assignment1.pdf: The assignment documentation (PDF format) explaining the task and solution.

Problem Description
In this version of the Josephus problem, n people stand in a circle, and every second person is eliminated until only one person remains. The solution employs fork() to create a new child process each time a person is eliminated. The parent process waits for the child process to finish before marking the eliminated person and reducing the circle size.

The parent process is responsible for determining the survivor once all eliminations are completed.

How to Compile and Run

Linux Version (with fork()):
Clone the Repository:
git clone https://github.com/yourusername/josephus-problem.git cd josephus-problem

Compile the Linux Program:
gcc -o josephus_linux josephus_linux.c

Run the Program:
Run the program by passing the number of people as a command line argument:
./josephus_linux <number_of_people>

Example:
./josephus_linux 10
The program will print the eliminated people in order and finally display the survivor.

Normal C Version (No fork()):
Clone the Repository:
git clone https://github.com/yourusername/josephus-problem.git cd josephus-problem

Compile the normal C version without fork():
gcc -o josephus josephus.c

Run the Program:
Run the program by passing the number of people as a command line argument:
./josephus <number_of_people>

Example:
./josephus 10

This version works without fork() and provides a simpler approach, eliminating people in a loop and determining the survivor.
