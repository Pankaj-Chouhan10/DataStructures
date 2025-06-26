# Stack Using Linked List

This folder contains two versions of the Stack implementation using Linked List in C++.

---

## Files

| File Name                           | Description                                                                     |
|-------------------------------------|---------------------------------------------------------------------------------|
| `stack_using_linked_list.cpp`       | Plain output, best for most compilers or minimal environments.                  |
| `stack_using_linked_list_color.cpp` | Uses ANSI escape codes for color output, great for visual clarity in terminals. |

---

## Operations Included

- `Push()` : Insert an element into the stack
- `Pop()` : Remove the top element
- `Peek()` : View the top element
- `PrintStack()` : Display all stack elements

---

## How to Run

### Compile:
```bash

# Non-colored version
g++ stack_using_linked_list.cpp -o stack
./stack

# Colored version
g++ stack_using_linked_list_color.cpp -o stack_colored
./stack_colored

