#include <iostream>

using namespace std;

#define MAX 3

int queue[MAX];
int front = 0;
int lenght = 0;

bool isEmpty(){
    return lenght == 0;
}

bool isFull(){
    return lenght == MAX;
}

void enqueue(int data){
    if (isFull())
    {
        cout << "Queue penuh\n";
    }else{
        int posisi = front + lenght;
        queue[posisi % MAX] = data;
        lenght++;
        cout << "Data " << data << " telah ditambah ke dalam antrian" << endl;
    }
}

void dequeue(){
    if (isEmpty())
    {
        cout << "Queue kosong\n";
    }else{
        cout << "Data " << queue[front] << " telah dikeluarkan dari antrian\n";
        front++;
        front %= MAX;
        lenght--;
    }
}

void cekQueue(){
    for (int i = 0; i < lenght; i++)
    {
        cout << queue[(front+i)%MAX] << " ";
    }
    cout << "\n";
}

int main()
{
    enqueue(12);
    enqueue(98);
    enqueue(5);
    enqueue(7);
    cekQueue();
    dequeue();
    cekQueue();
    enqueue(7);
    dequeue();
    dequeue();
    cekQueue();
    dequeue();
    return 0;
}
