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
    if (head == NULL)
    {
        head = baru;

    }else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data berhasil ditambahkan\n";
}

void tambahBelakang(int dataBaru){
    Node *baru = new Node, *bantu = head;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        
    }else{
        do
        {
            bantu = bantu->next;

        } while (bantu->next != NULL);

        baru->prev = bantu;
        bantu->next = baru;
        
    }
    cout << "Data berhasil ditambahkan\n";
}

void tambahTengah(int dataBaru, int posisi){
    Node *baru = new Node, *bantu = head;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        
    }else{
        --posisi;
        for (int i = 1; i < posisi; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        baru->prev = bantu;
        bantu->next->prev = baru;
        bantu->next = baru;
    }
    cout << "Data berhasil ditambahkan\n";
}

void tampilkanData(){
    Node *bantu = head;
    if (head == NULL)
    {
        cout << "Data kosong\n";
    }else{
        
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << "\n";
    }
    
}

void hapusDepan(){
    Node *hapus = head;
    head = head->next;
    head->prev = NULL;
    delete hapus;
    tampilkanData();
}

void hapusSemuaData(){
    Node *hapus;
    while (head->next != NULL)
    {
        hapus = head;
        head = head->next;
        cout << hapus->data << " ";
        delete hapus;
    }
    cout << "\n";
    head = NULL;
    tampilkanData();
}

void hapusBelakang(){
    Node *bantu = head, *hapus;
    while (bantu->next->next != NULL)
    {
        bantu = bantu->next;
    }
    hapus = bantu->next;
    bantu->next = NULL;
    tampilkanData();
}

int main()
{
    tambahDepan(32);
    tambahDepan(12);
    tambahBelakang(9);
    tambahBelakang(5);
    tambahTengah(999,4);
    tampilkanData();
    hapusDepan();
    hapusBelakang();
    hapusSemuaData();
    return 0;
}
