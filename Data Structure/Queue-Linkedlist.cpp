#include <iostream>

using namespace std;


struct Queue
{
    int data;
    Queue*next;
};

Queue *head = NULL;

bool isEmpty(){
    return head == NULL;
}

void enqueue(int dataBaru){
    Queue*baru = new Queue,*bantu = head;
    baru->data = dataBaru;
    if (isEmpty())
    {
        head = baru;
    }else{
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        };
        bantu->next = baru;
        baru->next = NULL;
    }
    cout << "Data masuk\n";
}

void dequeue(){
    Queue *bantu = head;
    if (isEmpty())
    {
        cout << "Data kosong\n";
    }else{
        head = head->next;
        cout << bantu->data << " telah dihapus\n";
        delete bantu;
    }
}

void cekQueue(){
    Queue *bantu = head;
    if (isEmpty())
    {
        cout << "Data kosong\n";
    }else{
        while (bantu!=NULL){
            cout << bantu->data << " ";
            bantu = bantu->next;
        };
    } 
    cout << endl;
}

int main()
{
    enqueue(1);
    enqueue(12);
    enqueue(13);
    cekQueue();
    dequeue();
    dequeue();
    cekQueue();
    return 0;
}
