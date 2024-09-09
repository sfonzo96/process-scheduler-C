# OS process scheduler simulator

#### About Me

Hello! I'm a software development student from Argentina 🇦🇷, and I aspire to become a software engineer. This project is
my final submission for CS50x.

#### Video demo: [URL HERE]

#### Why a process scheduler simulator?

During the Operative Systems course, the professor challenged us (just joking though) to create a process scheduler in
order to better understand how process scheduling works. I decided to take on this challenge and make it my CS50x final
project. I'm proud of the outcome, as it not only pushed me to improve my C programming skills but also became a useful
tool for my classmates to grasp scheduling algorithms more easily.

#### Why C?

Although I have experience in web development using JavaScript, I chose C for this project because process schedulers
are inherently "mid to low-level" tools. Additionally, this project gave me the opportunity to deepen my understanding
of C, which is more challenging and suitable for this type of task.

#### Description:

The OS process scheduler simulator is a command-line tool written in C that simulates various process scheduling
algorithms found in operating systems. This tool is designed to help students understand how different scheduling
strategies work by allowing them to see how processes are handled in real time. The simulator currently supports three
main scheduling algorithms:

1. **Round Robin (RR)**
2. **Priority scheduling**
3. **FIFO (First In, First Out)**

#### Design

To keep the focus on educational value, I implemented processes as structs in memory rather than creating actual system
processes. While this approach is less complex than a real-world implementation, it effectively demonstrates key
concepts and differences between scheduling algorithms.

#### Features

-   **Process creation:**

    -   Manual input: Enter process details such as title, duration, status, and priority directly.
    -   File input: Load process data from a CSV-like formatted text file (see
        [sample](https://github.com/sfonzo96/process_scheduler-C/blob/main/processesList.txt)).

-   **Scheduling algorithms:**

    -   Round Robin: Distributes CPU time equally among processes. Each process receives a fixed time slice in a cyclic
        order.
    -   Priority scheduling: Executes processes according to their priority values, with higher priority being lower
        numeric values..
    -   FIFO scheduling: Processes are executed in the order they arrive.

-   **Status display:** Provides real-time updates on the status of each process during execution.

#### Project structure and files

The project is simple and organized as follows:

-   **[main.c file](https://github.com/sfonzo96/process_scheduler-C/blob/main/main.c)**: Contains the main program that
    prompts a menu and starts the simulator
-   **[procesos_functions.h file](https://github.com/sfonzo96/process_scheduler-C/blob/main/procesos_functions.h)**:
    Includes function prototypes and some enums for clarity.
-   **[procesos_functions.c file](https://github.com/sfonzo96/process_scheduler-C/blob/main/procesos_functions.c)**:
    Contains the function definitions for the simulator's operations.
-   **[processesList.txt file](https://github.com/sfonzo96/process_scheduler-C/blob/main/processesList.txt)**: Provides
    sample data for the simulator, though users can load their own data files.

#### How did I make scheduling algorithms work here

##### Process struct

In the program, each process is represented as a struct:

```c
struct Process {
	char title[20];
	float timeLeft;
	char status[10];
	int priority;
};
```

In this struct:

-   **timeLeft**: The remaining time the process needs to complete its execution..
-   **status**: The current state of the process. It can take one of the following values:
    -   "Ready": The process is loaded into memory but hasn't started yet.
    -   "Running": The process is currently being executed.
    -   "Waiting": The process has started but is not currently executing (e.g., it's waiting its turn in Round Robin).
    -   "Completed": The process has finished its execution.
-   **priority**: Indicates the urgency of the process (lower values mean higher priority).
-   **title**: A label for easy identification.

##### Round Robin

When the Round Robin algorithm is selected:

1.  **Quantum time definition**: The user is prompted to define the quantum of time, which representes the fixed amount
    of CPU time allocated to each process per cycle.

2.  **Time management**:

    -   The current time is captured using C's clock() function when a process begins execution. This time is stored as
        the starting point.
    -   A while loop runs, repeatedly checking the elapsed time by comparing the current time to the start time. This
        elapsed time is stored in the elapsedTime variable.
    -   Once the elapsedTime reaches the defined quantum, the process's timeLeft is reduced by the quantum value. The
        process's status is then updated to reflect its new state ("Waiting" if it's not finished, "Completed" if it
        is).

3.  **Cycle continuation**: The next process in line then starts its execution, and the cycle repeats until all
    processes have a timeLeft of 0, meaning they are all completed.

##### Priority

When the Priority scheduling algorithm is selected:

1.  **Process sorting**:

    -   The processes are sorted in ascending order based on their priority values using a selection sort algorithm.
        Processes with lower priority values (e.g., 1) are executed first.

2.  **Execution**:

    -   For each process, a while loop runs, continuously checking if the required time for completion (timeLeft) has
        passed.This is done using C's clock() function to update the elapsedTime variable during each iteration.
    -   Once the required time has elapsed, the timeLeft for that process is set to 0, marking it as "Completed", and
        the next process in the priority queue begins its execution.

##### FIFO

When the FIFO algorithm is selected:

1.  **Sequential Execution**:
    -   The processes are executed strictly in the order they were added to the list by the user.
    -   No additional sorting or time management is required beyond the simple sequential execution.
    -   Each process runs until its timeLeft is 0, at which point it is marked as "Completed", and the next process in
        the list begins.

### Additional Notes

-   Language and encoding: The messages displayed during program execution are in Spanish. Please note that some
    characters, such as accented vowels, might not display correctly due to encoding issues. If you encounter any
    problems with character display, it may be related to the character encoding settings of your terminal or text
    editor.

-   Code Style: While CS50x encourages placing opening curly braces on the next line, my personal coding style prefers
    them openning on the same line as the statement or function definition. I apologize if this causes any
    inconvenience; it's simply a matter of personal preference and habit :D.

### Getting started

To start using the simulator, follow these instructions:

#### Prerequisites

-   **C compiler:** Make sure you have a C compiler (e.g., GCC) installed.

#### Compilation

Compile the source code with the following command:

```bash
gcc -o process_scheduler main.c procesos_functions.c
```

#### Execution

Run the CLI tool with the following command:

```bash
./process_scheduler
```
