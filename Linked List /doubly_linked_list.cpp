#include "iostream"
using namespace std;

// Class Node to create node in Doubly Liked List.
class Node{
    public:
        int value;
        Node* next;
        Node* pre;
        Node(){
            int val;
            cout<<"Enter the value : ";
            cin>>val;
            value = val;
            next = NULL;
            pre = NULL;
        }
};
// Class DoublyLinkedList to perform Doubly Linked List operations :
// InsertAtEnd , InsertAtBeginning , InsertAtPosition , DeleteAtEnd , DeleteAtBeginning , DeleteAtPosition , PrintList , IsEmpty .
class DoublyLinkedList{
    Node *head;
    public:
        int sizeOfList;

        DoublyLinkedList(){
            sizeOfList = 0;
            head = NULL;
        }

        //Insert at end : for insert at end of Doubly linked list.
        void InsertAtEnd(){
            Node* newNode = new Node();
            if(IsEmpty()){
               head = newNode;
            }
            else{
                Node *temp = GetLastNode();
                temp->next = newNode;
                newNode->pre = temp;
            }
            sizeOfList++;
        }

        //Insert at end : for insert at end of Doubly linked list.
        void InsertAtBeginning(){
            Node* newNode = new Node();
            if(IsEmpty()){
                head = newNode;
            }
            else{
                newNode->next = head;
                head->pre = newNode;
                head = newNode;
            }
            sizeOfList++;
        }

        //Insert at position : for insert at position in Doubly linked list.
        void InsertAtPosition(){
            //Get postion for user.
            int position;
            cout<<"Enter position between 0 to "<<sizeOfList<<" : ";
            cin>>position;
            while(position < 0 || position > sizeOfList){
                cout<<"Invalid position try agin\n";
                cout<<"Enter position between 0 to "<<sizeOfList<<" : ";
                cin>>position;
            }
            
            if(position == 0) {
                InsertAtBeginning();
                return;
            }
            else if(position == sizeOfList){
                InsertAtEnd();
                return ;
            }
            Node* temp  = head;
            position--;
            while(position) {
                temp = temp->next;
                position--;
            }
            Node* newNode = new Node();

            newNode->next = temp->next;
            newNode->pre = temp;
            temp->next->pre = newNode;
            temp->next = newNode;

            sizeOfList++;
        }

        //Delete at end : for delete the element at end of Doubly linked list.
        void DeleteAtEnd(){
            if(IsEmpty()){
                cout<<"List is Empty\n";
                return ;
            }
            Node* lastNode = GetLastNode();
            //handling the error of Null Pointer Exception
            if(head == lastNode){
                head = NULL;
                sizeOfList = 0;
                return ;
            }
            lastNode->pre->next = NULL;
            sizeOfList--;
            delete lastNode;
        }

        //Delete at beginning : for delete the element at beginning of Doubly linked list.
        void DeleteAtBeginning(){
            if(IsEmpty()){
                cout<<"List is Empty\n";
                return ;
            }
            //handling the error of Null Pointer Exception
            if(sizeOfList == 1){
                head = NULL;
                sizeOfList = 0;
                return ;
            }
            Node* temp = head;
            head = head->next;
            head->pre = NULL;
            sizeOfList--;
            delete temp;
        }

        //Delete at position : for belete the element at position in Doubly linked list.
        void DeleteAtPosition(){
            if(IsEmpty()){
                cout<<"List is Empty\n";
                return ;
            }
            //Get the position form user.
            int position;
            cout<<"Enter position between 0 to "<<sizeOfList-1<<" : ";
            cin>>position;
            while(position < 0 || position >= sizeOfList){
                cout<<"Invalid position try agin\n";
                cout<<"Enter position between 0 to "<<sizeOfList<<" : ";
                cin>>position;
            }

            if(position == 0){
                DeleteAtBeginning();
                return ;
            }
            else if(position == sizeOfList-1){
                DeleteAtEnd();
                return ;
            }
            
            Node* temp = head;
            while(position){
                temp = temp->next;
                position--;
            }
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            sizeOfList--;
            delete temp;
        }

        //Print list : for print every element of Doubly linked list.
        void PrintList(){
            if(IsEmpty()){
                cout<<"List is Empty\n";
                return ;
            }
            Node* temp = head;
            cout<<"List print format\n";
            cout<<"| previous value | current value | next value | \n";
            while(temp != NULL){
                if(temp->pre == NULL) cout<<"| NULL | ";
                else cout<< " | " << temp->pre->value <<" | ";
                cout<<temp->value<<" | ";
                if(temp->next == NULL) cout<<"NULL | \n";
                else cout<< temp->next->value <<" | ->";
                temp = temp->next;
            }
        }

        //Is empty : for check Doubly linked list is empty or not.
        bool IsEmpty(){
            return (sizeOfList == 0);
        }

        //Get last Node : for insert or delete the last element Doubly linked list.
        Node* GetLastNode(){
            if(IsEmpty()){
                return head;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            return temp;
        }
};

// Main function
int main(){
DoublyLinkedList D1;

    int choice = -1;
    while (choice != 8)
    {
        // Option to perform operation on Linked list.
        cout << "==============================\n";
        cout << " Doubly Linked list Operations \n";
        cout << "==============================\n";
        cout << "1. Insert at beginning \n";
        cout << "2. Insert at end \n";
        cout << "3. Insert at position \n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end \n";
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
            D1.InsertAtBeginning();
            break;
        case 2:
            D1.InsertAtEnd();
            break;
        case 3:
            D1.InsertAtPosition();
            break;
        case 4:
            D1.DeleteAtBeginning();
            break;
        case 5:
            D1.DeleteAtEnd();
            break;
        case 6:
            D1.DeleteAtPosition();
            break;
        case 7:
            D1.PrintList();
            break;
        case 8:
            cout << "Program is End Final Linked List : ";
            D1.PrintList();
            break;
        default:
            cout << "Enter correct choice\n";
            break;
        }
    }
    return 0;

}

