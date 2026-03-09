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
If it looks confusing to read, just know that memory addresses are just numbers. Larger numbers → **higher in virtual memory**, smaller numbers → **lower**.<br/>
Memory in a process is divided into segments: 
- the **text segment** holds code
- **Data/BSS segments** hold global variables
- the **heap segment** stores dynamically allocated memory
- the **stack segment** stores local variables and function frames.
<br/>
Now we shall test out a recursive function to see the effects that it has on the stack:<br/>
<img width="480" height="196" alt="image" src="https://github.com/user-attachments/assets/7d76caaf-b81a-445f-b9b8-74a6d97dc5a1" /><br/>
<br/>
Notice that in our recursive function, each deeper call has a smaller address. This confirms that the stack **grows downward**, meaning newer frames are allocated at lower addresses:<br/>
<img width="324" height="271" alt="image" src="https://github.com/user-attachments/assets/d2b5214e-f2ad-4dd4-b5fb-f17f9d1e20b1" /><br/>

