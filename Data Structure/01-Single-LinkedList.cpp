#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};



Node *Head;

void init(){
    Head = NULL;
}



void tambahDepan(int dataBaru){
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;
    if (Head == NULL)
    {
        Head = baru;
        baru->next = NULL;  
    }else{
        baru->next = Head;
        Head = baru;
    }
    cout << "Data baru ditambahkan\n";
}

void tambahBelakang(int dataBaru){
    Node *baru = new Node, *bantu;
    baru->data = dataBaru;
    baru->next = NULL;
    if (Head == NULL){
        Head = baru;
    }else{
        bantu = Head;
        while (bantu->next != NULL)
        {
            bantu=bantu->next;   
        }
        bantu->next = baru;
    }
    cout << "Data baru ditambahkan\n";
}

void tambahTengah(int dataBaru, int posisi){
    Node *bantu = Head, *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;
    if (Head==NULL)
    {
        cout << "Data kosong\n";
    }else{
        for (int i = 1; i < posisi - 1 && bantu != NULL; i++) {
            bantu = bantu->next;
        }
        if (bantu == NULL || bantu->next == NULL) {
            cout << "Posisi tidak ditemukan\n";
        } else {
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    cout << "Data baru ditambahkan\n";
}

void tampilkanData(){
    Node *bantu = Head;
    if (Head==NULL)
    {
        cout << "Data kosong\n";
    }else{
        while (bantu!=NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }   
        cout << "\n";
    }
    
}

void hapusDepan(){
    Node *bantu = Head;
    if (Head == NULL)
    {
        cout << "Data kosong\n";
    }else{
        Head = Head->next;
        delete bantu;
    }
    cout << "Data paling depan terhapus\n";
}

void hapusbelakang(){
    Node *bantu = Head, *hapus = new Node;
    if (Head != NULL)
    {
        while(bantu->next->next!=NULL){
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = NULL;
        delete hapus;
        cout << "Data paling belakang terhapus\n";
        
    }else{
        cout <<"data kosong";
    }
}

void hapusSemua(){
    Node *hapus;
    while (Head != NULL) {
        hapus = Head;
        Head = Head->next;
        cout << hapus->data << " dihapus\n";
        delete hapus;
    }
    cout << "Semua data terhapus\n";
}

int main()
{   
    
    init();
    tampilkanData();
    tambahDepan(90);
    tambahDepan(10);
    tambahBelakang(20);
    tambahTengah(1,2);
    tampilkanData();
    hapusDepan();
    tampilkanData();
    hapusbelakang();
    tampilkanData();
    hapusSemua();

    return 0;
}
