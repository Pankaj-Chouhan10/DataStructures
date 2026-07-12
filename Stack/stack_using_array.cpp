#include <iostream>
using namespace std;

class StackUsingArray {
 
private:
    int top;        // Index of current top element
    int* stack;     // Dynamic array for stack storage
    int size;       // Maximum capacity of stack

public:

    // Constructor: Allocate memory and initialize stack
    StackUsingArray(int size) {
        this->stack = new int[size];
        this->top = -1;
        this->size = size;
    }

    // Destructor: Free dynamically allocated memory
    ~StackUsingArray() {
        delete[] stack;
    }

    void Push() {

        // Prevent overflow
        if (isFull()) {
            cout << "Stack is Full\n";
            return;
        }

        int val;
        cout << "Enter the val : ";
        cin >> val;

        // Increment top first, then insert element
        stack[++top] = val;

        cout << stack[top] << " Element is push in the stack\n";
    }

    void Pop() {

        // Prevent underflow
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "The pop element is : " << stack[top] << '\n';

        // Remove top element by moving top pointer
        top--;
    }

    int Peek() {

        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        cout << "Top Element of the Stack : " << stack[top] << '\n';
        return stack[top];
    }

    void PrintStack() {

        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        int tempTop = 0;

        cout << "Element in the stack : ";

        // Traverse from bottom to top
        while (tempTop < top) {
            cout << stack[tempTop] << " , ";
            tempTop++;
        }

        cout << stack[top] << " (top element)\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

int main() {

    int size;

    cout << "Enter size of the Stack : ";
    cin >> size;

    StackUsingArray S1(size);

    int choice = -1;

    while (choice != 5) {

        cout << "\n==============================\n";
        cout << "      Stack Operations\n";
        cout << "==============================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        // Menu-driven implementation
        switch (choice) {

        case 1:
            S1.Push();
            break;

        case 2:
            S1.Pop();
            break;

        case 3:
            S1.Peek();
            break;

        case 4:
            S1.PrintStack();
            break;

        case 5:
            cout << "Program is End. Final Stack:\n";
            S1.PrintStack();
            break;

        default:
            cout << "Enter correct choice\n";
        }
    }

    return 0;
}
