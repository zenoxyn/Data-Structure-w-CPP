#include <iostream>

using namespace std;

// Make a Node Struct for Single Linked List
// Node has 2 attributes, data and next
// data is the value of the node
// next is the pointer to the next node
// Node is a type of data
struct Node{
    int data;
    Node *next;
};

// Make a Head Node
// Head is a pointer to the first node
// Head is a global variable
Node *Head;

// Make a function to initialize the Head
// Head is NULL
// NULL because there is no node yet
void init(){
    Head = NULL;
}

// Make a function to add a new node to the front of the list
// The new node is added to the front of the list
void addFront(int newData){
    Node *newNode = new Node; // Create a new node
    newNode->data = newData; // Assign the new data to the new node
    newNode->next = NULL; // The next of the new node is NULL

    // if the list is empty
    if (Head == NULL) 
    {
        Head = newNode; // The new node is the first node
        newNode->next = NULL;  // The next of the new node is NULL, because there is no node after it
    }else{
        // if the list is not empty
        // the new node is added to the front of the list
        newNode->next = Head; // The next of the new node is the Head
        Head = newNode; // and the new node is the Head
    }
    cout << "New Data Has Been Added\n";
}


// Make a function to add a new node to the back of the list
// The new node is added to the back of the list
void addBack(int newData){
    Node *newNode = new Node, *temp; // Create a new node and a temporary node
    newNode->data = newData; // Assign the new data to the new node
    newNode->next = NULL; // The next of the new node is NULL

    // if the list is empty
    if (Head == NULL){
        Head = newNode; // The new node is the first node
        newNode->next = NULL; // The next of the new node is NULL, because there is no node after it
    }else{
        // if the list is not empty
        // the new node is added to the back of the list
        temp = Head; // The temporary node is the Head
        while (temp->next != NULL) // Find the last node
        {
            temp=temp->next; // Move to the next node
        }
        temp->next = newNode; // The next of the last node is the new node
    }
    cout << "New Data Has Been Added\n";
}


// Make a function to add a new node to the middle of the list
// The new node is added to the middle of the list
// The position of the new node is determined by the user
void addMiddle(int newData, int posisi){
    Node *temp = Head, *newNode = new Node; // Create a temporary node and a new node
    newNode->data = newData; // Assign the new data to the new node
    newNode->next = NULL; // The next of the new node is NULL

    // if the list is empty
    // the new node is added to the front of the list
    if (Head == NULL)
    {
        Head = newNode; // The new node is the first node
        newNode->next = NULL; // The next of the new node is NULL, because there is no node after it
    }else{
        // if the list is not empty
        // the new node is added to the middle of the list
        for (int i = 1; i < posisi - 1 && temp != NULL; i++) { // Find the position of the new node
            temp = temp->next; // Move to the next node
        }
        // if the position is not found
        if (temp == NULL || temp->next == NULL) {
            cout << "Position is Not Found\n";
        } else { // if the position is found
            newNode->next = temp->next; // The next of the new node is the next of the temporary node
            temp->next = newNode; // The next of the temporary node is the new node
        }
    }
    cout << "New Data Has Been Added\n";
}


// Make a function to show all data in the list
// The data is shown from the first node to the last node
void showData(){
    Node *temp = Head; // Create a temporary node
    if (Head==NULL) 
    {
        cout << "Data is Empty\n";
    }else{
        while (temp!=NULL) // Show the data from the first node to the last node
        {
            cout << temp->data << " ";
            temp = temp->next; // Move to the next node
        }   
        cout << "\n";
    }
    
}

// Make a function to delete the first node
void deleteFront(){
    Node *deleteNode = Head; // Create a node to be deleted
    if (Head == NULL)
    {
        cout << "Data is Empty\n";
    }else{
        // if the list is not empty
        // the first node is deleted
        Head = Head->next; // The Head is moved to next of the Head
        delete deleteNode;
    }
    cout << "Front data has been deleted\n";
}

// Make a function to delete the last node
void deleteBack(){
    Node *temp = Head, *deleteNode = new Node; // Create a temporary node and a node to be deleted
    if (Head != NULL) // if the list is not empty
    {
        while(temp->next->next!=NULL){ // Find the last node
            temp = temp->next;
        }

        // after while loop, temp is the second last node
        // the last node is the next of the second last node
        deleteNode = temp->next; // The node to be deleted is the last node
        temp->next = NULL; // The next of the second last node is NULL, because the last node is deleted
        delete deleteNode;
        cout << "The last data has been deleted\n";
        
    }else{
        cout <<"Data is Empty\n";
    }
}

// Make a function to delete all data in the list
void deleteAll(){
    Node *deleteNode; // Create a node to be deleted
    while (Head != NULL) {  // Delete all data in the list
        deleteNode = Head; // The node to be deleted is the Head
        Head = Head->next; // The Head is moved to next of the Head
        cout << deleteNode->data << " has been deleted\n"; // Show the data that has been deleted
        delete deleteNode; // Delete the node
    }
    cout << "All data has been deleted\n";
}

int main()
{   
    init(); // Initialize the Head
    showData(); // Show the data in the list
    addFront(90); // Add a new node to the front of the list
    addFront(10); // Add a new node to the front of the list
    addBack(20); // Add a new node to the back of the list
    addMiddle(1, 2); // Add a new node to the middle of the list
    showData(); // Show the data in the list
    deleteFront(); // Delete the first node
    showData(); // Show the data in the list
    deleteBack(); // Delete the last node
    showData(); // Show the data in the list
    deleteAll(); // Delete all data in the list

    return 0;
}
