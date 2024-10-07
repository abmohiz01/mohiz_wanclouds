

# Task 1: eBPF Process Monitoring




## Overview


This program implements a real-time process monitoring system using eBPF (Extended Berkeley Packet Filter) to trace process creation events in the Linux kernel. 

The solution utilizes Python with the bcc (BPF Compiler Collection) library to log process names as they are created via the clone system call.

The task is divided into two components:

* BPF Program: A kernel probe (kprobe) monitors process creation using the clone syscall. It captures the name of each new process and logs it.

* C Program Simulation: A C program simulates process activity. It takes a user-provided name, runs a loop to simulate work, and prints the status with the name provided.




## Run Locally

Set up Ubuntu: I installed VMware and Ubuntu 20.04 to ensure the program ran smoothly in a virtual environment.

Installed the BPF Compiler Collection (bcc) using:
bash

```bash
sudo apt-get install bpfcc-tools linux-headers-$(uname -r) python3-bpfcc
```

Run the Program:

I created a Python script (task_1.py) with the eBPF program and a small C program for simulation.
The script was executed using:
```bash
sudo python3 task_1.py <your_name>

```
The program successfully accepted the name argument, created a process with that name, and monitored its activity.


sudo apt update
sudo apt install bpfcc-tools python3-bpfcc


you can run the program hello world for printing helloworld and loging it system calls using the following command:

```bash
  sudo python3 helloworld.py
```


## Achievments

* eBPF Monitoring: The program successfully monitored process creation using the clone syscall, logging the process names.

* Simulated Work: The C program simulated a process performing work and displayed the progress, successfully taking the user’s name as input.


## Areas for Improvement

- Process Filtering: Currently, the program logs all process creation events. Adding filtering for specific processes would improve the utility.

- Kernel Compatibility: Some issues related to kprobe compatibility with different kernel versions delayed full implementation.




# Task 2: Doubly Linked List Program with Insertion, Deletion and sorting.




## Overview

This C program implements a doubly linked list with several functionalities such as inserting, deleting, sorting, and displaying nodes. Each node in the list contains a Person structure with an ID (integer) and a name (string). 

Additionally, the program includes:

* Logging messages that describe every operation (e.g., when a node is created, inserted, deleted, or the list is sorted).

* Error handling for user input, ensuring only valid integers are accepted for ID values. It will ask the user to re-enter the ID if the input is invalid.

* Display functionality that prints both the ID and the name of each node in the linked list.




## Run Locally

GCC compiler should be installed on your system. If not, install it using the following command:

```bash
  sudo apt update
  sudo apt install build-essential

```

Save the program in a file called task2.c or whatever you like:

```bash
  nano task2.c
```

After saving the program, compile it using GCC:

```bash
  gcc task2.c -o task2

```

After compiling, you can run the program using the following command:

```bash
  ./task2
```


## Usage/Examples

```javascript
1. Insert
2. Delete
3. Sort
4. Display
5. Exit
Choose an option: 1
Enter ID: abc
Invalid input! Please enter a valid integer.
Enter ID: 23
Enter Name: abmohiz
Log: Created node with ID 23 and Name abmohiz.
Log: Inserted node with ID 23 as the head.

1. Insert
2. Delete
3. Sort
4. Display
5. Exit
Choose an option: 4
List: 23(abmohiz)->NULL

```

