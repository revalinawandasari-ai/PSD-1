#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nomor;
    Node* left;
    Node* right;

    Node(string n, string no) {
        nama = n;
        nomor = no;
        left = right = nullptr;
    }
};

Node* insert(Node* root, string nama, string nomor) {
    if (!root) return new Node(nama, nomor);
    if (nama < root->nama)
        root->left = insert(root->left, nama, nomor);
    else if (nama > root->nama)
        root->right = insert(root->right, nama, nomor);
    else
        cout << "Kontak dengan nama tersebut sudah ada!\n";
    return root;
}

Node* search(Node* root, string nama) {
    if (!root || root->nama == nama) return root;
    if (nama < root->nama) return search(root->left, nama);
    return search(root->right, nama);
}

void tampilkanKontak(Node* root) {
    if (!root) return;
    tampilkanKontak(root->left);
    cout << root->nama << " - " << root->nomor << endl;
    tampilkanKontak(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string nama, nomor;

    do {
        cout << "\n=== Daftar Kontak (BST) ===\n";
        cout << "1. Tambah kontak\n";
        cout << "2. Cari kontak\n";
        cout << "3. Tampilkan semua kontak\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan nomor telepon: ";
            getline(cin, nomor);
            root = insert(root, nama, nomor);
        } else if (pilih == 2) {
            cout << "Cari nama: ";
            getline(cin, nama);
            Node* hasil = search(root, nama);
            if (hasil)
                cout << "Nomor " << hasil->nama << ": " << hasil->nomor << endl;
            else
                cout << "Kontak tidak ditemukan.\n";
        } else if (pilih == 3) {
            cout << "\n=== Semua Kontak ===\n";
            tampilkanKontak(root);
        }
    } while (pilih != 4);

    cout << "Program selesai.\n";
    return 0;
}