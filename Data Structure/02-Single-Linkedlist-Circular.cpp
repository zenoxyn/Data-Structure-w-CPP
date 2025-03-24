#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void tambahDepan(int dataBaru){
    Node *baru = new Node, *bantu;
    baru->data = dataBaru;
    baru->next = NULL;
    if (head == NULL)
    {
        head = baru;
        baru->next = head;
    }else{
        bantu = head;
        while (bantu->next != head)
        {
            bantu = bantu->next;
        }
        baru->next = head;
        head = baru;
        bantu->next = head;
    }
    cout << "Data berhasil ditambahkan\n";
}

void tambahBelakang(int dataBaru){
    Node *baru = new Node, *bantu = head;
    baru->data = dataBaru;
    if(head == NULL){
        head = baru;
    }else{
        do
        {
            bantu = bantu->next;
        } while (bantu->next != head);
        bantu->next = baru;
        baru->next = head;
    }
    cout << "Data berhasil ditambahkan\n";
}

void tambahTengah(int dataBaru, int posisi){
    Node *baru = new Node, *bantu = head;
    baru->data = dataBaru;
    if(head == NULL){
        head = baru;
    }else{
        for (int i = 1; i < posisi; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    cout << "Data berhasil ditambahkan\n";
}


void TampilkanData(){
    Node *bantu = head;
    if (head == NULL)
    {
        cout << "Data kosong kocak\n";
    }else{


        do
        {

            cout << bantu->data << " ";
            bantu = bantu->next;

        }while (bantu != head);
    }
    
    cout << "\n";
}

void hapusDepan(){
    Node *hapus = head, *bantu = head;
    if(head == NULL){
        cout << "Data kosong\n";
    }else{
        do
        {
            bantu = bantu->next;
        } while (bantu->next != head);
        
    }
    head = head->next;
    bantu->next = head;
    cout << "Data paling depan terhapus\n";
    delete hapus;
}

void hapusBelakang(){
    Node *bantu = head, *hapus;
    if(head == NULL){
        cout << "Data kosong\n";
    }else{
        while (bantu->next->next != head)
        {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = head;
        cout << "Data paling belakang terhapus\n";
    }
}

void hapusSemua(){
    Node *hapus, *bantu = head;
    if(head == NULL){
        cout << "Data kosong\n";
    }else{
        while (bantu->next != head){
            bantu = bantu->next;
        }
        
        do
        {
            hapus = head;
            head = head->next;
            bantu->next = head;
            cout << hapus->data  << " ";
            delete hapus;
        }while (head != bantu);
        hapus = head;
        cout << hapus->data << "\n";
        delete hapus;
        head = NULL;
        cout << "Semua data terhapus\n";
    }
}


int main()
{

    tambahDepan(1);
    tambahDepan(3);
    tambahBelakang(2);
    tambahBelakang(4);
    tambahTengah(5,2);
    TampilkanData();
    hapusDepan();
    TampilkanData();
    hapusBelakang();
    TampilkanData();
    hapusSemua();
    TampilkanData();
    
    return 0;
}
