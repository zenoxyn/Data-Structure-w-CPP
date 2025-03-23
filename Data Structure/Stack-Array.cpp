#include <iostream>
using namespace std;

#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty(){
    return (top == -1)? 1 : 0;
}

int isFull(){
    return (top == MAX-1)? 1 : 0;
}

void push(int data){
    if (isFull())
    {
        cout << "Stack penuh\n";
    }else{
        top++;
        stack[top] = data;
        cout << "Element " << data << " ditambahkan\n";
    }
}

void pop(){
    if (isEmpty())
    {
        cout << "Stack kosong\n";
    }else{
        cout << "Element " << stack[top] << " dihapus\n";
        top--;
    }
    
}

void showData(){
    if (isEmpty())
    {
        cout << "Data kosong\n";
    }else{
        int temp = top;
        while (temp != -1)
        {
            cout << stack[temp--] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    push(1);
    push(12);
    push(123);
    showData();
    pop();
    push(9);
    showData();
    
    return 0;
}
