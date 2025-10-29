#include <iostream>
#include <string>
using namespace std;

const int SIZE = 7;

struct Node {
    int id;
    string nama;
    int stok;
    Node* next;
};

int hashFunction(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; ++i)
        table[i] = nullptr;
}

void insert(Node* table[], int id, string nama, int stok) {
    int idx = hashFunction(id);
    Node* newNode = new Node{id, nama, stok, nullptr};

    if (!table[idx]) {
        table[idx] = newNode;
    } else {
        Node* temp = table[idx];
        while (temp) {
            if (temp->id == id) { 
                temp->nama = nama;
                temp->stok = stok;
                delete newNode;
                cout << "Data dengan ID " << id << " diperbarui.\n";
                return;
            }
            if (!temp->next) break;
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Barang " << nama << " (ID " << id << ") berhasil ditambahkan di slot " << idx << endl;
}

Node* search(Node* table[], int id) {
    int idx = hashFunction(id);
    Node* temp = table[idx];
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void display(Node* table[]) {
    cout << "\n=== Data Barang di Gudang ===\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Slot " << i << ": ";
        Node* temp = table[i];
        if (!temp) {
            cout << "Kosong\n";
            continue;
        }
        while (temp) {
            cout << "(ID:" << temp->id << ", " << temp->nama << ", Stok:" << temp->stok << ")";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node* gudang[SIZE];
    initTable(gudang);

    insert(gudang, 101, "Beras", 25);
    insert(gudang, 108, "Gula", 15);
    insert(gudang, 115, "Minyak", 40);
    insert(gudang, 202, "Telur", 60);
    insert(gudang, -14, "Garam", 12);

    display(gudang);

    cout << "\nMencari barang dengan ID 108...\n";
    Node* hasil = search(gudang, 108);
    if (hasil)
        cout << "Ditemukan: " << hasil->nama << " (Stok: " << hasil->stok << ")\n";
    else
        cout << "Barang tidak ditemukan.\n";

    return 0;
}