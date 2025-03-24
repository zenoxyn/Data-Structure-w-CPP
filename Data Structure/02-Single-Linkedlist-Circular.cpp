#include <iostream>
using namespace std;

// Define a Node structure for the Circular Single Linked List
// Node has two attributes: data and next
// data stores the value of the node
// next is a pointer to the next node
struct Node {
    int data;
    Node *next;
};

// Define a global pointer head to represent the start of the list
// Initially, head is NULL, meaning the list is empty
Node *head = NULL;

// Function to add a new node to the front of the list
// The new node becomes the first node in the list
void addFront(int newData) {
    Node *newNode = new Node, *helper; // Create a new node and a helper pointer
    newNode->data = newData; // Assign the new data to the new node
    newNode->next = NULL; // Initialize the next pointer of the new node

    // If the list is empty
    if (head == NULL) {
        head = newNode; // The new node becomes the head
        newNode->next = head; // The next pointer points to itself, forming a circular structure
    } else {
        // If the list is not empty
        helper = head; // Use helper to traverse the list
        while (helper->next != head) { // Find the last node
            helper = helper->next;
        }
        newNode->next = head; // The new node points to the current head
        head = newNode; // Update head to the new node
        helper->next = head; // The last node points to the new head
    }
    cout << "Data added successfully\n";
}

// Function to add a new node to the back of the list
// The new node becomes the last node in the list
void addBack(int newData) {
    Node *newNode = new Node, *helper = head; // Create a new node and a helper pointer
    newNode->data = newData; // Assign the new data to the new node

    // If the list is empty
    if (head == NULL) {
        head = newNode; // The new node becomes the head
        newNode->next = head; // The next pointer points to itself, forming a circular structure
    } else {
        // If the list is not empty
        do {
            helper = helper->next; // Traverse the list to find the last node
        } while (helper->next != head);
        helper->next = newNode; // The last node points to the new node
        newNode->next = head; // The new node points to the head
    }
    cout << "Data added successfully\n";
}

// Function to add a new node at a specific position in the list
// The position is determined by the user
void addMiddle(int newData, int position) {
    Node *newNode = new Node, *helper = head; // Create a new node and a helper pointer
    newNode->data = newData; // Assign the new data to the new node

    // If the list is empty
    if (head == NULL) {
        head = newNode; // The new node becomes the head
        newNode->next = head; // The next pointer points to itself
    } else {
        // Traverse the list to find the position
        for (int i = 1; i < position; i++) {
            helper = helper->next;
        }
        newNode->next = helper->next; // The new node points to the next node
        helper->next = newNode; // The current node points to the new node
    }
    cout << "Data added successfully\n";
}

// Function to display all data in the list
// The data is displayed from the first node to the last node
void displayData() {
    Node *helper = head; // Create a helper pointer
    if (head == NULL) {
        cout << "No data available\n"; // If the list is empty
    } else {
        do {
            cout << helper->data << " "; // Print the data of each node
            helper = helper->next; // Move to the next node
        } while (helper != head); // Stop when the head is reached again
    }
    cout << "\n";
}

// Function to delete the first node in the list
void deleteFront() {
    Node *toDelete = head, *helper = head; // Create pointers for deletion and traversal
    if (head == NULL) {
        cout << "No data available\n"; // If the list is empty
    } else {
        do {
            helper = helper->next; // Find the last node
        } while (helper->next != head);
        head = head->next; // Update head to the next node
        helper->next = head; // The last node points to the new head
        cout << "Front data deleted\n";
        delete toDelete; // Delete the old head
    }
}

// Function to delete the last node in the list
void deleteBack() {
    Node *helper = head, *toDelete; // Create pointers for traversal and deletion
    if (head == NULL) {
        cout << "No data available\n"; // If the list is empty
    } else {
        while (helper->next->next != head) { // Find the second last node
            helper = helper->next;
        }
        toDelete = helper->next; // The last node to be deleted
        helper->next = head; // The second last node points to the head
        cout << "Back data deleted\n";
        delete toDelete; // Delete the last node
    }
}

// Function to delete all nodes in the list
void deleteAll() {
    Node *toDelete, *helper = head; // Create pointers for deletion and traversal
    if (head == NULL) {
        cout << "No data available\n"; // If the list is empty
    } else {
        while (helper->next != head) { // Find the last node
            helper = helper->next;
        }
        do {
            toDelete = head; // The node to be deleted
            head = head->next; // Move head to the next node
            helper->next = head; // The last node points to the new head
            cout << toDelete->data << " "; // Print the data of the deleted node
            delete toDelete; // Delete the node
        } while (head != helper); // Stop when only one node is left
        toDelete = head; // Delete the last remaining node
        cout << toDelete->data << "\n";
        delete toDelete;
        head = NULL; // The list is now empty
        cout << "All data deleted\n";
    }
}

// Main function to demonstrate the operations on the Circular Single Linked List
int main() {
    addFront(1); // Add a node to the front
    addFront(3); // Add another node to the front
    addBack(2); // Add a node to the back
    addBack(4); // Add another node to the back
    addMiddle(5, 2); // Add a node at position 2
    displayData(); // Display all data
    deleteFront(); // Delete the first node
    displayData(); // Display all data
    deleteBack(); // Delete the last node
    displayData(); // Display all data
    deleteAll(); // Delete all nodes
    displayData(); // Display all data

    return 0;
}
