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

If you noticed in the earlier image, the difference in addresses for both segments are 4 bytes:<br/>
<img width="353" height="139" alt="image" src="https://github.com/user-attachments/assets/83de65cb-cccf-468b-ab1b-6e3dcb26ef72" /><br/>
This is because the addresses here are typically near each other in memory within their respective segments.<br/>
Variables within a segment are usually contiguous, though small gaps may exist due to alignment or compiler optimizations.<br/>

# Text Segment

The text segment contains the compiled functions.<br/>
The function code, everything inside the `{...}` is stored in the text segment, because it is compiled machine code.<br/>
These addresses are usually **fixed and read-only**.<br/>
<br/>

# Heap Allocation Tracker

Similar to what we have already done previously, we have developed a function to allocate memory onto the heap:<br/>
<img width="779" height="444" alt="image" src="https://github.com/user-attachments/assets/03af1747-809e-4326-927c-f7b7d3d1880d" /><br/>
We have also included a loop to perform multiple allocations and record each memory address, allowing us to observe how the heap grows over time.<br/>
<br/>
As shown in the output, the heap addresses do not always increase sequentially; the growth is irregular rather than strictly linear:<br/>
<img width="555" height="404" alt="image" src="https://github.com/user-attachments/assets/ab419d8c-43d9-4f78-8822-78fa5fa1d75b" /><br/>
This irregularity is due to the behavior of the heap allocator. It may:<br/>
- Reuse freed memory blocks
- Allocate non-contiguous chunks for alignment
- Or manage small internal caches, which can cause addresses to appear out of order.<br/>
<br/>

Only consecutive `new` calls without deletion may mostly increase (as we have done in the Heap Segment above), but heap addresses are not guaranteed to always strictly increase.<br/>

<br/>

Alternatively, we created a `HeapTracker` class with the following variables to monitor dynamic memory usage on the heap:<br/>
<img width="503" height="129" alt="image" src="https://github.com/user-attachments/assets/2686fe55-8eca-48ff-87ec-32edbb725556" /><br/>
<br/>
And the following methods:<br/>
<img width="979" height="699" alt="image" src="https://github.com/user-attachments/assets/557b2bce-702b-411b-9e86-3ba39514f970" /><br/>

- `void* allocate()` - Allocates memory of the given size on the heap and tracks it.
- `void deallocate()` - Frees memory and removes it from the tracker.
- `void report()` - Prints a summary of allocations, deallocations, peak usage, and potential memory leaks.

<br/>

In our `main()`, we call the following: <br/>
<img width="264" height="158" alt="image" src="https://github.com/user-attachments/assets/3a19ecdb-4e18-4a31-93b9-bd943986ea30" /><br/>
<br/>
And when we run the results are printed as such: <br/>
<img width="636" height="127" alt="image" src="https://github.com/user-attachments/assets/7bc36d97-0f6b-43ad-bbbf-0f59689c766b" /><br/>

- Allocated memory for pointers `a`, `b` and `c`
- Deallocated only pointer `b`
- Report shows that the memory leak occurred for pointers `a` and `c` at their respective addresses, along with their sizes

<br/>

# Rule of Three

Let us expand on the heap segment of the memory. In the below code, we show a class that owns heap memory:<br/>
<img width="406" height="298" alt="Image" src="https://github.com/user-attachments/assets/629e8d7e-a6c5-42f5-891a-39551874317c" /><br/>
<br/>

And in `main()`:<br/>
<img width="179" height="53" alt="Image" src="https://github.com/user-attachments/assets/0efbbcfd-a8d6-49bc-bb70-b879cecb04aa" /><br/>
Both objects now point to the same heap block.<br/>
- `a.data` → memory
- `b.data` → same memory block

<br/>
When we compile and run the code, an error occurs:<br/>
<img width="407" height="297" alt="Image" src="https://github.com/user-attachments/assets/ac35210d-fa40-4cc8-84fc-b29d613413e5" /><br/>

When the destructors (`~Buffer()`) run, they delete the memory block twice, leading to a crash.<br/>

<br/>

**Hence this is why the Rule of Three exists.**
