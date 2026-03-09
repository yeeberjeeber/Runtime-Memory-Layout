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
Each memory address is simply a numeric value; higher numbers indicate higher locations in virtual memory, and lower numbers indicate lower locations.<br/>
Larger numbers → **higher in virtual memory**, smaller numbers → **lower**.<br/>
<br/>
Memory in a process is divided into segments: 
- **Text segment** holds code
- **Data/BSS segments** hold global variables
- **Heap segment** stores dynamically allocated memory
- **Stack segment** stores local variables and function frames.
<br/>

# Stack Segment

Now we shall test out a recursive function to see the effects that it has on the stack:<br/>
<img width="480" height="196" alt="image" src="https://github.com/user-attachments/assets/7d76caaf-b81a-445f-b9b8-74a6d97dc5a1" /><br/>
<br/>
Notice that in our recursive function, each deeper call has a smaller address. This confirms that the stack **grows downward**, meaning newer frames are allocated at lower addresses:<br/>
<img width="324" height="271" alt="image" src="https://github.com/user-attachments/assets/d2b5214e-f2ad-4dd4-b5fb-f17f9d1e20b1" /><br/>

# Heap Segment

Let us now compare to the growth in the heap segment:<br/>
<img width="495" height="208" alt="image" src="https://github.com/user-attachments/assets/9c6e124b-e6fc-4b07-950f-72f8f9493bdd" /><br/>
<br/>
The output shows a larger address for each new variable declared on the heap segment:<br/>
<img width="371" height="294" alt="image" src="https://github.com/user-attachments/assets/95c8bbe3-91b4-46cf-a8d2-eb04c2564119" /><br/>
This tells us that the heap **grows upward**, meaning newer allocations are placed at higher addresses in contrast to the stack, which **grows downward**.<br/>

# Data / BSS Segments

If you noticed in the earlier screenshot, the difference in addresses for both segments are 4 bytes:<br/>
<img width="353" height="139" alt="image" src="https://github.com/user-attachments/assets/83de65cb-cccf-468b-ab1b-6e3dcb26ef72" /><br/>
This is because the addresses here are typically near each other in memory within their respective segments.<br/>
Variables within a segment are usually contiguous, though small gaps may exist due to alignment or compiler optimizations.<br/>

