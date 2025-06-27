# Queue Using Linked List

This folder contains two versions of the Queue implementation using Linked List in C++.

---

## Files

| File Name                           | Description                                                                     |
|-------------------------------------|---------------------------------------------------------------------------------|
| `queue_using_linked_list.cpp`       | Plain output, best for most compilers or minimal environments.                  |
| `queue_using_linked_list_color.cpp` | Uses ANSI escape codes for color output, great for visual clarity in terminals. |

---

## Operations Included

- `Enqueue()` : Insert an element into the Queue
- `Dequeue()` : Remove the front element 
- `Front()` : View the front element
- `PrintQueue()` : Display all Queue elements

---

## How to Run

### Compile:
```bash

# Non-colored version
g++ queue_using_linked_list.cpp -o queue
./queue

# Colored version
g++ queue_using_linked_list_color.cpp -o queue_colored
./queue_colored

