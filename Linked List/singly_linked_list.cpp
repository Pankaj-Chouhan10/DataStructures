#include "iostream"
using namespace std;

// Class Node to create node in Liked List.
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
// Class LinkedList to perform LinkedList operations :
// InsertAtEnd , InsertAtBeginning , InsertAtPosition , DeleteAtEnd , DeleteAtBeginning , DeleteAtPosition , PrintList , IsEmpty .
class LinkedList
{
public:
    Node *head;
    int sizeOfList = 0;
    LinkedList()
    {
        head = NULL;
    }
    // Insert at end method : for insert an element at end of linked list.
    void InsertAtEnd()
    {
        // creat new node
        Node *newNode = new Node();
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << newNode->value << " is add at end of Linked List\n";
        sizeOfList++;
    }

    // Insert at beginning method : for insert an element at beginning of linked list.
    void InsertAtBeginning()
    {
        Node *newNode = new Node();
        if (IsEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        } // Green
        cout << newNode->value << " is add at start of Linked List\n";
        sizeOfList++;
    }

    // Insert at position method : for insert an element at any position in linked list.
    void InsertAtPosition()
    {
        int position = GetPosition();
        if (position == -1)
            return;
        Node *temp = head;
        // head point to the new node
        if (position == 1)
        {
            InsertAtBeginning();
            return;
        }
        else if (position == sizeOfList + 1)
        {
            InsertAtEnd();
        }
        else
            position--;
        Node *newNode = new Node();
        while (position > 1)
        {
            temp = temp->next;
            position--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << newNode->value << " is add at position of Linked List\n";
        sizeOfList++;
    }

    // Delete at beginning method : for delete element at end of liked list.
    void DeleteAtEnd()
    {
        if (IsEmpty())
        {
            return;
        }
        Node *pre = NULL, *curr = head;
        while (curr->next != NULL)
        {
            pre = curr;
            curr = curr->next;
        }
        if (pre == NULL)
        {
            head = NULL;
        }
        else
        {
            pre->next = NULL;
        }
        cout << curr->value << " is delete at End of Linked List\n";
        delete curr;
        sizeOfList--;
    }

    // Delete at beginning method : for delete element at beginning of liked list.
    void DeleteAtBeginning()
    {
        if (IsEmpty())
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        cout << temp->value << " is delete at Beginning of Linked List\n";
        delete temp;
        sizeOfList--;
    }

    // Delete at position method : for delete element at any position in liked list.
    void DeleteAtPosition()
    {
        if (IsEmpty())
        {
            return;
        }
        int position = GetPosition();
        if (position == -1)
            return;
        if (position == 1)
        {
            DeleteAtBeginning();
            return;
        }
        else if (position == sizeOfList)
        {
            DeleteAtEnd();
            return;
        }
        else
        {
            Node *pre, *curr = head;
            position--;
            while (position)
            {
                pre = curr;
                curr = curr->next;
                position--;
            }
            pre->next = curr->next;
            cout << curr->value << " is delete at position of Linked List\n";
            delete curr;
        }
        sizeOfList--;
    }

    // Print list method : for print liked list element.
    void PrintList()
    {
        Node *temp = this->head;
        if (IsEmpty())
        {
            return;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->value << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    // Get Position for insert and delete the element at position.
    int GetPosition()
    {
        int position;
        // color
        cout << "Enter position : ";
        cin >> position;
        if (position > sizeOfList)
        {
            cout << "Invalid Position \n";
            return -1;
        }
        return position;
    }

    // Is Empty method : for check List is empty or not.
    bool IsEmpty()
    {
        if (head == NULL)
        {
            cout << "Linked list is Empty\n";
        }
        return (head == NULL);
    }
};
// Main function
int main()
{
    LinkedList L1;
    int choice = -1;
    while (choice != 8)
    {
        // Option to perform operation on Linked list.
        cout << "==============================\n";
        cout << "    Linked list Operations    \n";
        cout << "==============================\n";
        cout << "1. Insert at end \n";
        cout << "2. Insert at beginning \n";
        cout << "3. Insert at position \n";
        cout << "4. Delete at end\n";
        cout << "5. Delete at beginning \n";
        cout << "6. Delete at position \n";
        cout << "7. Print Linked List\n";
        cout << "8. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        // input of option.
        cin >> choice;
        // perform operation.
        switch (choice)
        {
        case 1:
            L1.InsertAtEnd();
            break;
        case 2:
            L1.InsertAtBeginning();
            break;
        case 3:
            L1.InsertAtPosition();
            break;
        case 4:
            L1.DeleteAtEnd();
            break;
        case 5:
            L1.DeleteAtBeginning();
            break;
        case 6:
            L1.DeleteAtPosition();
            break;
        case 7:
            L1.PrintList();
            break;
        case 8:
            cout << "Program is End Final Linked List : ";
            L1.PrintList();
            break;
        default:
            cout << "Enter correct choice\n";
            break;
        }
    }

    return 0;
}
