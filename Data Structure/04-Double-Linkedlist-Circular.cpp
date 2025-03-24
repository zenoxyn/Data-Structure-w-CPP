#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void tambahDepan(int dataBaru){
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(head == NULL){
        head = baru;
        head->next = baru;
        head->prev = baru;
    }else{
        baru->next = head;
        baru->prev = head->prev;
        head->prev->next = baru;
        head->prev = baru;
        head = baru;
    }
    cout << "Data masuk\n";
}

void tambahBelakang(int dataBaru){
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(head == NULL){
        head = baru;
        head->next = baru;
        head->prev = baru;
    }else{
        baru->next = head;
        baru->prev = head->prev;
        head->prev->next = baru;
        head->prev = baru;
    }
    cout << "Data masuk\n";
}

void tambahTengah(int dataBaru, int posisi){
    Node *baru = new Node, *bantu;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(head == NULL){
        head = baru;
        head->next = baru;
        head->prev = baru;
    }else{
        --posisi;
        bantu = head;
        for (int i = 1; i < posisi; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        baru->prev = bantu;
        bantu->next->prev = baru;
        bantu->next = baru;
    }
    cout << "Data masuk\n";
}

void tampilkanData(){
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node *bantu = head;
    do
    {
        cout << bantu->data <<" ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << "\n";
}

void hapusDepan(){
    Node *hapus = head;
    if(head == NULL){
        cout <<  "Data kosong\n";
    }else{
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete hapus;
        cout << "Data paling depan dihapus\n";
        tampilkanData();
    }
}

void hapusBelakang(){
    Node *hapus = head->prev;
    if(head == NULL){
        cout <<  "Data kosong\n";
    }else{
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        delete hapus;
        cout << "Data paling belakang dihapus\n";
        tampilkanData();
    }
}

void hapusSemua(){
    Node *hapus, *bantu = head;
    if(head == NULL){
        cout <<  "Data kosong\n";
    }else{
        do
        {
            hapus = bantu;
            bantu = bantu->next;
            cout << hapus->data <<" ";
            delete hapus;
        }while (bantu != head);
        head = NULL;
        cout << "\nSemua data telah dihapus\n"; 
    }
}

int main(){
    tambahDepan(98);
    tambahDepan(2);
    tambahDepan(7);
    tambahBelakang(4);
    tambahTengah(55,3);
    tampilkanData();
    hapusDepan();
    hapusBelakang();
    hapusSemua();

    return 0;
}
