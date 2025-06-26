#include "iostream"
using namespace std;

// Class Node to create node in Stack
// InputOfValueInNode function to take value from user and store in node
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
        int value;
        cout << "Enter value : ";
        cin >> value;
        this->value = value;
        next = NULL;
    }
};

// Class StackUsingLinkedList to perform stack operations:
// pop, push, printStack, peek
class StackUsingLinkedList
{
public:
    Node *top;
    StackUsingLinkedList()
    {
        top = NULL;
    }

    // push Method : for insert element in stack
    void Push()
    {
        // allocate memory for new node
        Node *newNode = new Node();
        if (top == NULL)
        {
            newNode->next = NULL;
            top = newNode;
            cout << top->value << " is add in Stack\n";
        }
        else
        {
            newNode->next = top;
            top = newNode;
            cout << top->value << " is add in Stack\n";
        }
    }

    // peek Method : for print the top element
    void Peek()
    {
        if (IsEmpty())
        {
            return ;
        }
        cout << "Value in top is : " << top->value << "\n";
    }

    // pop Method : for remove top element
    void Pop()
    {
        if (IsEmpty())
        {
            return ;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->value << " is Remove from Stack\n";
        delete temp;
    }
    //IsEmpty Method : for check Queue is empty or not 
    bool IsEmpty()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
        }
        return (top == NULL);
    }
    // print Stack Method : to print all the element in stack
    void PrintStack()
    {
        Node *temp = top;
        if (IsEmpty())
        {
            return ;
        }
        while (temp != NULL)
        {
            cout << temp->value << "<-";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main()
{
    // Object
    StackUsingLinkedList S1;
    int choice = -1;
    // Operations based on choice
    cout << endl;
    while (choice != 5)
    {
        // Option to perform operation on Stack
        cout << "==============================\n";
        cout << "         Stack Operations      \n";
        cout << "==============================\n";
        cout << "1. Push (Insert an element)\n";
        cout << "2. Pop (Remove top element)\n";
        cout << "3. Peek (View top element)\n";
        cout << "4. Print Stack\n";
        cout << "5. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        // input of option
        cin >> choice;
        // perform operation
        switch (choice)
        {
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
            cout << "Program is End Final Stack : ";
            S1.PrintStack();
            break;
        default:
            cout << "Enter correct choice\n";
            break;
        }
    }

    return 0;
}
