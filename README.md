
# Task 1: eBPF Process Monitoring




## Overview


This Task contains an eBPF program developed in Python using the BPF Compiler Collection (BCC) framework. The program monitors processes that invoke the clone system call, logging custom messages to the console when executed.

Task Objectives

* Monitor system calls made by processes containing a specific name in their command line arguments.

* Log and trace system calls to understand process behaviors.




## Run Locally

To run the eBPF program, ensure you have the necessary dependencies installed on an Ubuntu system. You can install them using the following commands:

```bash
  sudo apt update
sudo apt install bpfcc-tools python3-bpfcc


```

Save the program in a file called helloworld.py or whatever you like:

```bash
  sudo nano helloworld.py

```

After writing, you can run the program using the following command:

```bash
  sudo python3 helloworld.py
```


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

