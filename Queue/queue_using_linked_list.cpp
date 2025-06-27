#include "iostream"
using namespace std;

// Class Node to create node in Queue
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
        int value;
        cout << "Enter the value : ";
        cin >> value;
        this->value = value;
        next = NULL;
    }
};
// Class QueueUsingLinkedList to perform Queue operations:
// Enqueue, Dequeue, Front , IsEmpty, PrintQueue
class QueueUsingLinkedList
{
public:
    Node *front, *Rear;
    QueueUsingLinkedList()
    {
        front = NULL;
        Rear = NULL;
    }
    // Enqueue Method : for insert an element in Queue
    void Enqueue()
    {
        // allocate memory for new node
        Node *newNode = new Node();
        if (front == NULL)
        {
            front = newNode;
            Rear = newNode;
            cout << front->value << " is add in Queue\n";
        }
        else
        {
            Rear->next = newNode;
            Rear = newNode;
            cout << Rear->value << " is add in Queue\n";
        }
    }
    // Dequeue Method : for remove an element in Queue;
    void Dequeue()
    {
        if (IsEmpty())
        {
            return;
        }
        else
        {
            Node *temp = front;
            cout << temp->value << " is Remove from Queue \n";
            front = front->next;
            delete temp;
        }
    }
    // Front Method : for View front element in Queue
    void Front()
    {
        Node *temp = front;
        if (IsEmpty())
            return;
        else
        {
            cout << "Front element is: " << front->value << "\n";
        }
    }
    // IsEmpty Method : for check Queue is empty or not
    bool IsEmpty()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty\n";
        }
        return (front == NULL);
    }
    // Print Queue Method : for print Queue element
    void PrintQueue()
    {
        Node *temp = front;
        if (IsEmpty())
            return;
        while (temp != NULL)
        {
            cout << temp->value << "<-";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
// Main function
int main()
{
    // Object
    QueueUsingLinkedList Q1;
    int choice = -1;
    while (choice != 5)
    {
        // Option to perform operation on Queue
        cout << "\n==============================\n";
        cout << "         Queue Operations      \n";
        cout << "==============================\n";
        cout << "1. Enqueue (Insert an element)\n";
        cout << "2. Dequeue (Remove an element)\n";
        cout << "3. Front (View front element)\n";
        cout << "4. Print Queue\n";
        cout << "5. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        // input of option
        cin >> choice;
        // perform operation
        switch (choice)
        {
        case 1:
            Q1.Enqueue();
            break;
        case 2:
            Q1.Dequeue();
            break;
        case 3:
            Q1.Front();
            break;
        case 4:
            Q1.PrintQueue();
            break;
        case 5:
            cout << "Program is End Final Queue : ";
            Q1.PrintQueue();
            break;
        default:
            cout << "Enter correct choice\n";
            break;
        }
    }
    return 0;
}
