#include <iostream>
using namespace std;

struct stack{
    int data;
    stack* next;
};



stack *head = nullptr;

bool isEmpty(){
    return head == NULL;
}

void push(int dataBaru){
    stack *baru = new stack;
    baru->data = dataBaru;
    baru->next = NULL;
    if (isEmpty())
    {
        head = baru;
    }else{
        baru->data = dataBaru;
        baru->next = head;
        head = baru;
    }
    cout << "Data " << dataBaru << " telah ditambahkan\n";    
}

void pop(){
    stack *hapus = head;
    if (isEmpty())
    {
        cout << "Data kosong\n";
    }else{
        head = head->next;
        cout << "Data " << hapus->data << " telah dihapus\n";
        delete hapus;
    }
}

void hapusSemua(){
    stack *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        cout << hapus->data << " dihapus\n";
        delete hapus;
    }
    head = NULL;
    cout << "Semua data terhapus\n";
}

void showData(){
    stack *bantu = head;
    while (bantu != NULL)
    {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    push(91);
    push(92);
    showData();
    pop();
    push(93);
    push(94);
    showData();
    return 0;
}
