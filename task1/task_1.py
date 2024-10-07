#!/usr/bin/python3

from bcc import BPF
from time import sleep
import sys
import os

# Check if the name argument is provided
if len(sys.argv) != 2:
    print("Usage: sudo python3 task_1.py <your_name>")
    exit(1)

name = sys.argv[1]

# Defining BPF program
program = """
int taskOne(void *ctx) {
    char name[16];
    bpf_get_current_comm(&name, sizeof(name));
    bpf_trace_printk("Running process with name: %s\\n", name);
    return 0;
}
"""

b = BPF(text=program)
clone = b.get_syscall_fnname("clone")
b.attach_kprobe(event=clone, fn_name="taskOne")
b.trace_print


print("%-18s %-16s %-6s %s" % ("TIME(s)", "COMM", "PID", "MESSAGE"))

# Compiling the C program
c_program = """
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <your_name>\\n", argv[0]);
        return 1;
    }
    char *name = argv[1];
    printf("Running process with name: %s\\n", name);
    // Simulate some activity by calling a system call in a loop
    for (int i = 0; i < 8; i++) {
        printf("Process %s is doing some work... (%d)\\n", name, i + 1);
        sleep(1); // Simulating work with sleep
    }
    printf("Process %s completed its work.\\n", name);
    return 0;
}
"""

with open("program_1.c", "w") as f:
    f.write(c_program)

os.system(f"gcc -o program_1 program_1.c")
os.system(f"./program_1 {name}")

# Trace output
while True:
    try:
        (task, pid, cpu, flags, ts, msg) = b.trace_fields()
    except ValueError:
        continue
    except KeyboardInterrupt:
        exit()
    print(b"%-18.9f %-16s %-6d %s" % (ts, task, pid, msg))
