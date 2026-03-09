# Runtime Memory Layout & Resource Management Analyzer

Project designed for personal C++ learning.

# Purpose

This is a project that explores how programs use memory at runtime and how C++ manages resources through object lifecycle rules.

# Learning Goals:

This project aims to build an understanding of:
- Process memory layout
- Stack vs heap behavior
- Static vs dynamic storage duration
- Object copy semantics
- Move semantics
- Memory leaks and how they occur
- Proper resource ownership patterns

# Memory Layout Inspection

We begin this project by first identifying the memory addresses for objects stored in different segments:<br/>
<img width="376" height="315" alt="image" src="https://github.com/user-attachments/assets/a6a1e76e-659f-43b3-9aae-459e5d363d7f" /><br/>
<br/>
The image above shows us **how different segments are arranged in memory**.<br/>
If it looks confusing to read, just know that Memory addresses are just numbers. Larger numbers → **higher in virtual memory**, smaller numbers → **lower**.<br/>
<br/>
For example, we compare `initializedGlobal` against `sampleFunction`:<br/>
- 0x00007FF7FFCFF000 (`initializedGlobal`)
- 0x00007FF7FFCF11EA (`sampleFunction`)
The first is higher than the second because 0x00007FF7FFCFF000 > 0x00007FF7FFCF11EA.
