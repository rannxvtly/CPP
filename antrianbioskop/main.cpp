#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#define max 10
using namespace std;

string password = "admin123"; // Password login

// Struktur data queue untuk menyimpan antrian pelanggan e-commerce
struct queue {
    int head;
    int tail;
    string data[max];
};

queue antri;

// Struktur produk e-commerce
struct Produk {
    string nama;
    int harga;
    int stok;
};

Produk daftarProduk[] = {
    {"Laptop", 7000000, 10},
    {"Smartphone", 4000000, 15},
    {"Headphone", 500000, 20},
    {"Mouse Wireless", 150000, 25},
    {"Keyboard", 300000, 20},
};

struct Pembelian {
    string namaProduk;
    int jumlah;
    int harga;
    int total;
};

Pembelian pesanan[100];

void inisialisasi() {
    antri.head = 0;
    antri.tail = -1;
}

bool isEmpty() {
    return antri.tail < antri.head;
}

bool isFull() {
    return antri.tail - antri.head + 1 == max;
}

void Enqueue() {
    if (!isFull()) {
        antri.tail++;
        antri.data[antri.tail % max] = "P" + to_string(antri.tail + 1);
    } else {
        cout << "Antrian penuh" << endl;
    }
}

void dequeue() {
    if (!isEmpty()) {
        cout << "Melayani pelanggan: " << antri.data[antri.head % max] << endl;
        antri.head++;
    } else {
        cout << "Antrian kosong" << endl;
    }
}

void print() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    for (int i = antri.head; i <= antri.tail; i++) {
        cout << "[" << antri.data[i % max] << "] <- ";
    }
    cout << endl;
}

void clear() {
    antri.head = 0;
    antri.tail = -1;
    cout << "Semua antrian dihapus.\n";
}

void tampilkanProduk() {
    cout << "==============================================================\n";
    cout << "                         DAFTAR PRODUK                       \n";
    cout << "--------------------------------------------------------------\n";
    cout << left << "| No | " << setw(20) << "Nama Produk" << " | " << setw(10) << "Harga" << " | " << setw(6) << "Stok" << " |" << endl;
    cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(20) << daftarProduk[i].nama << " | Rp." << setw(8) << daftarProduk[i].harga << " | " << setw(4) << daftarProduk[i].stok << " |" << endl;
    }
    cout << "==============================================================\n";
}

void urutkanProduk() {
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (daftarProduk[j].harga > daftarProduk[j + 1].harga) {
                swap(daftarProduk[j], daftarProduk[j + 1]);
            }
        }
    }
    cout << "\nProduk berhasil diurutkan berdasarkan harga (terendah ke tertinggi).\n";
}

void cariProduk() {
    string keyword;
    cout << "Masukkan nama produk yang dicari: ";
    cin.ignore();
    getline(cin, keyword);
    bool ditemukan = false;
    for (int i = 0; i < 5; i++) {
        if (daftarProduk[i].nama.find(keyword) != string::npos) {
            cout << "Ditemukan: " << daftarProduk[i].nama << " - Rp." << daftarProduk[i].harga << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Produk tidak ditemukan.\n";
    }
}

void pembelianProduk() {
    int n, subTotal = 0;
    cout << "\nBerapa produk yang ingin dibeli? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        tampilkanProduk();
        int pilih, jumlah;
        do {
            cout << "\nPilih produk ke-" << i + 1 << " (1-5): "; cin >> pilih;
            if (pilih < 1 || pilih > 5) cout << "Pilihan tidak valid!\n";
        } while (pilih < 1 || pilih > 5);
        cout << "Jumlah: "; cin >> jumlah;

        pesanan[i].namaProduk = daftarProduk[pilih - 1].nama;
        pesanan[i].harga = daftarProduk[pilih - 1].harga;
        pesanan[i].jumlah = jumlah;
        pesanan[i].total = pesanan[i].harga * jumlah;

        subTotal += pesanan[i].total;
    }

    cout << "\n========================== STRUK BELANJA ==========================\n";
    cout << left << "| " << setw(20) << "Produk" << " | " << setw(6) << "Jumlah" << " | " << setw(10) << "Harga" << " | " << setw(10) << "Total" << " |" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(20) << pesanan[i].namaProduk << " | " << setw(6) << pesanan[i].jumlah << " | Rp." << setw(8) << pesanan[i].harga << " | Rp." << setw(8) << pesanan[i].total << " |" << endl;
    }
    cout << "------------------------------------------------------------------\n";
    cout << "Subtotal: Rp." << subTotal << endl;

    string member;
    cout << "Apakah pelanggan adalah member? (y/n): "; cin >> member;
    int diskon = (member == "y" || member == "Y") ? 10 : 0;

    int totalDiskon = subTotal * diskon / 100;
    int total = subTotal - totalDiskon;

    cout << "Diskon (" << diskon << "%): Rp." << totalDiskon << endl;
    cout << "Total Pembayaran: Rp." << total << endl;

    int bayar;
    bayarUlang:
    cout << "Masukkan pembayaran: Rp.";
    cin >> bayar;
    if (bayar < total) {
        cout << "Uang tidak cukup!\n";
        goto bayarUlang;
    }
    cout << "Kembalian: Rp." << bayar - total << endl;
    cout << "==================================================================\n";
    cout << "         Terima kasih telah berbelanja di toko kami!              \n" << endl;
    cout << "==================================================================\n" << endl;
}

bool login() {
    string input;
    cout << "Masukkan Password untuk masuk: ";
    cin >> input;
    return input == password;
}

int main() {
    if (!login()) {
        cout << "Password salah. Program keluar.\n";
        return 0;
    }

    inisialisasi();
    char ulang = 'y';
    int pil;

    while (ulang == 'y') {
        system("cls");
        cout << "==================== E-COMMERCE QUEUE SYSTEM ====================\n";
        cout << "1. Masukkan Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Urutkan Produk (Harga)\n";
        cout << "4. Cari Produk\n";
        cout << "5. Bersihkan Antrian\n";
        cout << "6. Keluar\n";
        cout << "================================================================\n";

        if (!isEmpty()) {
            cout << "Antrian Saat Ini: ";
            print();
        } else {
            cout << "Antrian kosong.\n";
        }

        cout << "\nMasukkan pilihan: "; cin >> pil;

        switch (pil) {
            case 1:
                Enqueue();
                cout << "Nomor Antrian Anda: " << antri.data[antri.tail % max] << endl;
                break;
            case 2:
                if (!isEmpty()) {
                    cout << "\nMelayani pelanggan: " << antri.data[antri.head % max] << endl;
                    pembelianProduk();
                    dequeue();
                } else {
                    cout << "Tidak ada antrian saat ini.\n";
                }
                break;
            case 3:
                urutkanProduk();
                break;
            case 4:
                cariProduk();
                break;
            case 5:
                clear();
                break;
            case 6:
                ulang = 'n';
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
        system("pause");
    }
    return 0;
}