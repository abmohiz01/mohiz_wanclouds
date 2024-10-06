#!/usr/bin/python3

from bcc import BPF
from time import sleep

# Defining BPF program
program = """
int hello(void *ctx) {
    bpf_trace_printk("Hello, World!\\n");
    return 0;
}
"""


b = BPF(text=program)
clone = b.get_syscall_fnname("clone")
b.attach_kprobe(event = clone, fn_name = "hello")
b.trace_print

# Print header
print("%-18s %-16s %-6s %s" % ("TIME(s)", "COMM", "PID", "MESSAGE"))

# Trace output
while True:
    try:
        (task, pid, cpu, flags, ts, msg) = b.trace_fields()
    except ValueError:
        continue
    except KeyboardInterrupt:
        exit()
    print("%-18.9f %-16s %-6d %s" % (ts, task, pid, msg))
