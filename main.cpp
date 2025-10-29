#include <iostream>

#include <iomanip>
#include <string>
#define max 10
using namespace std;

struct queue {
    int head;
    int tail;
    int no = 0;
    string data[max];
};

struct itemPesanan {
    int kodeMenu, level, harga, jumlah;
    string catatan;
};

struct Menu {
    string nama;
    string deskripsi;
    int harga;
    int hargaLevel[8];
};

struct PelayananAntrian {
    string nomorAntrian;
    string status;
    string nama;
    string nomorMeja;
    string tanggal;
    string waktu;
} dataPelayananAntrian;

// Inisialisasi variabel
queue antri;                // Objek utama queue
itemPesanan itemOrder[100];  // Array objek pesanan

// Daftar Menu Gacoan
Menu menuGacoan[3] = {
    {"Mie Gacoan", "Manis gurih, level disesuaikan", 15000, {15000, 15000, 15000, 15000, 16000, 16000, 16000, 16000}},
    {"Mie Suit", "Gurih, level disesuaikan", 18000},
    {"Mie Hompipa", "Pedas gurih, level disesuaikan", 15000, {15000, 15000, 15000, 15000, 16000, 16000, 16000, 16000}}
};

Menu menuDimsum[5] = {
    {"Pangsit goreng", "Pangsit goreng", 15000},
    {"Udang rambutan", "dimsum digoreng", 14000},
    {"Lumpia Udang", "Lumpia berisikan udang", 15000},
    {"Siomay ayam", "Siomay kukus", 14000},
    {"Udang keju", "berisikan mozarella", 14000}
};

Menu menuMinuman[7] = {
    {"Es Teh", "Teh manis dingin", 6000},
    {"Air Mineral botol", "Botol Vit", 6000},
    {"Es Jeruk", "Jeruk Peras", 7500},
    {"Es Gobak Sodor", "buah campuran", 13000},
    {"Lemon Tea", "Es teh lemon", 9000},
    {"Es Milo", "Milo dingin", 11500},
    {"Es Petak Umpet", "Buah + Jelly", 13000}
};
//     DEKLARASI FUNGSI
void showHeading();
void inisialisasi();
int isEmpty();
int isFull();
void Enqueue();
int dequeue();
void clear();
void showMenuMie();
void showMenuDimsum();
void showMenuMinuman();
void pembelianMakanan();
void pembelianDimsum();
void pembelianMinuman();
void cetakStrukPesanan(int totalItem);
void menuPembelian();

// ==========================
//      FUNGSI ANTRIAN
// ==========================

void inisialisasi() {
    antri.head = -1;
    antri.tail = -1;
}

int isEmpty() {
    if (antri.tail == -1) {
        antri.head = -1;
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (antri.tail == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

void Enqueue() {
    if (!isFull()) {
        antri.head = 0;
        antri.tail += 1;
        antri.no += 1;
        antri.data[antri.tail] = "G" + to_string(antri.no); // ID unik G1, G2, dst
    } else {
        cout << "Antrian penuh";
    }
}

int dequeue() {
    if (!isEmpty()) {
        for (int i = antri.head; i <= antri.tail; i++) {
            antri.data[i] = antri.data[i + 1]; // Geser data ke kiri
        }
        antri.tail--; // Kurangi posisi tail
    }
}

void print() {
    for (int i = 0; i <= antri.tail; i++) {
        cout << "[" << antri.data[i] << "] <- ";
    }
}

void clear() {
    antri.head = -1;
    antri.tail = -1;
    cout << "Semua data terhapus.\n";
}
// ==========================
//      FUNGSI TAMPILAN
// ==========================
void showHeading() {
    cout << "=======================================================" << endl;
    cout << "                MIE GACOAN PURWAKARTA                  " << endl;
    cout << "=======================================================" << endl;
    cout << "Selamat Datang " << dataPelayananAntrian.nama << "\n";
    cout << "Tanggal: " << dataPelayananAntrian.tanggal << "  |  Waktu: " << dataPelayananAntrian.waktu << "\n\n";

    if (!isEmpty()) {
        cout << left << "| " << setw(15) << "Nomor Antrian" << " | " << setw(15) << "Status" << " |" << endl;
        for (int i = 0; i <= antri.tail; i++) {
            if (dataPelayananAntrian.nomorAntrian == antri.data[i]) {
                cout << "| " << left << setw(15) << antri.data[i] << " | " << setw(15) << "Sedang Dilayani" << " |" << endl;
            } else {
                cout << "| " << left << setw(15) << antri.data[i] << " | " << setw(15) << "Menunggu" << " |" << endl;
            }
        }
    } else {
        cout << "Antrian Kosong\n";
    }
}
void showMenuMie() {
    cout << "====================================================================" << endl;
    cout << "                          MENU MIE GACOAN                           " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << left << "| " << setw(3) << "No"
         << " | " << setw(15) << "Nama Menu"
         << " | " << setw(30) << "Deskripsi"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|---------------|---------------------------------|-------------|" << endl;
    for (int i = 0; i < 3; i++) {
        cout << " | " << left << setw(2) << i+1
             << " | " << setw(15) << menuGacoan[i].nama
             << " | " << setw(30) << menuGacoan[i].deskripsi
             << " | Rp." << setw(7) << menuGacoan[i].harga << " |" << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}
void showMenuDimsum() {
    cout << "====================================================================" << endl;
    cout << "                            MENU DIMSUM                             " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << left << " | " << setw(3) << "No"
         << " | " << setw(15) << "Nama Menu"
         << " | " << setw(30) << "Deskripsi"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|----------------|--------------------------------|------------|" << endl;

    for (int i = 0; i < 5; i++) {
        cout << " | " << left << setw(2) << i+1
             << " | " << setw(15) << menuDimsum[i].nama
             << " | " << setw(30) << menuDimsum[i].deskripsi
             << " | Rp." << setw(7) << menuDimsum[i].harga << " |" << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}
void showMenuMinuman() {
    cout << "====================================================================" << endl;
    cout << "                           MENU MINUMAN                             " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << left << " | " << setw(3) << "No"
         << " | " << setw(15) << "Nama Menu"
         << " | " << setw(30) << "Deskripsi"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|----------------|--------------------------------|------------|" << endl;

    for (int i = 0; i < 4; i++) {
        cout << " | " << left << setw(2) << i+1
             << " | " << setw(15) << menuMinuman[i].nama
             << " | " << setw(30) << menuMinuman[i].deskripsi
             << " | Rp." << setw(7) << menuMinuman[i].harga << " |" << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}
// ==========================
//     FUNGSI TRANSAKSI
// ==========================
void pembelianMakanan() {
    int totalItem = 0;
    int pilihan, level, jumlah;
    char tambah;
    int subTotal = 0;
    do {
        system("cls");
        showHeading();
        showMenuMie();

        cout << "\nPilih Menu Mie (1-3): ";cin >> pilihan;
        while (pilihan < 1 || pilihan > 3)
        {
            cout << "Pilihan tidak valid. Masukkan 1-3: ";cin >> pilihan;
        }
        cout << "Pilih Level Pedas (1-8): ";
        cin >> level;
        while (level < 1 || level > 8)
        {
            cout << "Level tidak valid. Masukkan 1-8: ";cin >> level;
        }

        cout << "Jumlah Pesanan: ";
        cin >> jumlah;

        cout << "Catatan (opsional): ";cin.ignore();
        getline(cin, itemOrder[totalItem].catatan);

        // Simpan data pesanan
        itemOrder[totalItem].kodeMenu = pilihan - 1;
        itemOrder[totalItem].level = level;
        itemOrder[totalItem].jumlah = jumlah;

        if (pilihan == 2)
        {
            itemOrder[totalItem].harga = menuGacoan[pilihan - 1].harga * jumlah;
        }
        else
        {
        itemOrder[totalItem].harga = menuGacoan[pilihan - 1].hargaLevel[level - 1] * jumlah;
        }
        subTotal += itemOrder[totalItem].harga;
        totalItem++;

        cout << "\nTambah menu lain? (y/n): ";cin >> tambah;
    }
    while (tambah == 'y' || tambah == 'Y');
    // Proses pembayaran
    bayarUlang:
    system("cls");
    cout << "=======================================================" << endl;
    cout << "                   RINCIAN PESANAN                     " << endl;
    cout << "=======================================================" << endl;
    cout << left << "| " << setw(3) << "No"
         << " | " << setw(15) << "Menu"
         << " | " << setw(5) << "Level"
         << " | " << setw(5) << "Jumlah"
         << " | " << setw(15) << "Catatan"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|----------------|-------|-------|----------------|------------|" << endl;
    for (int i = 0; i < totalItem; i++) {
        cout << " | " << left << setw(2) << i+1
             << " | " << setw(15) << menuGacoan[itemOrder[i].kodeMenu].nama
             << " | " << setw(5) << itemOrder[i].level
             << " | " << setw(5) << itemOrder[i].jumlah
             << " | " << setw(15) << itemOrder[i].catatan
             << " | Rp." << setw(7) << itemOrder[i].harga << " |" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Subtotal                           : Rp." << subTotal << endl;

    // Diskon untuk member
    string member;
    cout << "Apakah Member Gacoan (y/n)?       : ";
    cin >> member;

    int diskon = 0;
    if (member == "y" || member == "Y") {
        diskon = 10;
    }

    int totalDiskon = subTotal * diskon / 100;
    int total = subTotal - totalDiskon;

    cout << "Diskon (" << diskon << "%)                       : Rp." << totalDiskon << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Total Pembayaran                   : Rp." << total << endl;

    // Input pembayaran dan validasi
    int bayar;
    cout << "Masukan Pembayaran                 : Rp.";
    cin >> bayar;
    if (total > bayar)
    {
        cout << "Uang Anda Kurang" << endl;
        system("pause");
        goto bayarUlang;
    }
    cout << "Kembalian                          : Rp." << bayar - total << endl;
    cout << "=======================================================" << endl;
    cout << "            Terima kasih atas pesanan Anda!            " << endl;
    cout << "=======================================================" << endl;
    system("pause");

    // Cetak Struk Pembelian
    cetakStrukPesanan(totalItem);
    system("cls");
    cout << endl;
    cout << "=======================================================" << endl;
    cout << "                 Transaksi Selesai                     " << endl;
    cout << "=======================================================" << endl;
}
void pembelianDimsum() {
    int totalItem = 0;
    int pilihan, jumlah;
    char tambah;
    int subTotal = 0;
    do {
        system("cls");
        showHeading();
        showMenuDimsum();

        cout << "\nPilih Menu Dimsum (1-5): ";cin >> pilihan;
        while (pilihan < 1 || pilihan > 5)
        {
            cout << "Pilihan tidak valid. Masukkan 1-5: ";cin >> pilihan;
        }

        cout << "Jumlah Pesanan: ";cin >> jumlah;

        cout << "Catatan (opsional): ";cin.ignore();
        getline(cin, itemOrder[totalItem].catatan);

        // Simpan data pesanan
        itemOrder[totalItem].kodeMenu = pilihan - 1;
        itemOrder[totalItem].level = 0; // Tidak ada level untuk dimsum
        itemOrder[totalItem].jumlah = jumlah;
        itemOrder[totalItem].harga = menuDimsum[pilihan-1].harga * jumlah;
        subTotal += itemOrder[totalItem].harga;
        totalItem++;

        cout << "\nTambah menu lain? (y/n): ";cin >> tambah;
    } while (tambah == 'y' || tambah == 'Y');

    // Proses pembayaran
    bayarUlang:
    system("cls");
    cout << "=======================================================" << endl;
    cout << "                   RINCIAN PESANAN                     " << endl;
    cout << "=======================================================" << endl;
    cout << left << "| " << setw(3) << "No"
         << " | " << setw(15) << "Menu"
         << " | " << setw(5)  << "Jumlah"
         << " | " << setw(15) << "Catatan"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|----------------|-------|----------------|------------|" << endl;

    for (int i = 0; i < totalItem; i++) {
        cout << " | " << left << setw(2) << i+1
             << " | " << setw(15) << menuDimsum[itemOrder[i].kodeMenu].nama
             << " | " << setw(5)  << itemOrder[i].jumlah
             << " | " << setw(15) << itemOrder[i].catatan
             << " | Rp." << setw(7) << itemOrder[i].harga << " |" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Subtotal                           : Rp." << subTotal << endl;

    // Diskon untuk member
    string member;
    cout << "Apakah Ada Member Gacoan (y/n)?       : ";cin >> member;

    int diskon = 0;
    if (member == "y" || member == "Y") {
        diskon = 10;
    }

    int totalDiskon = subTotal * diskon / 100;
    int total = subTotal - totalDiskon;

    cout << "Diskon (" << diskon << "%)                       : Rp." << totalDiskon << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Total Pembayaran                   : Rp." << total << endl;

    // Input pembayaran dan validasi
    int bayar;
    cout << "Masukan Pembayaran                 : Rp.";cin >> bayar;

    if (total > bayar) {
        cout << "Uang Anda Kurang" << endl;
        system("pause");
        goto bayarUlang;
    }

    cout << "Kembalian                          : Rp." << bayar - total << endl;
    cout << "=======================================================" << endl;
    cout << "            Terima kasih atas pesanan Anda!            " << endl;
    cout << "=======================================================" << endl;
    system("pause");

    // Cetak Struk Pembelian
    cetakStrukPesanan(totalItem);
    system("cls");

    cout << endl;
    cout << "=======================================================" << endl;
    cout << "                 Transaksi Selesai                     " << endl;
    cout << "=======================================================" << endl;
}
void pembelianMinuman() {
    int totalItem = 0;
    int pilihan, jumlah;
    char tambah;
    int subTotal = 0;
    do {
        system("cls");
        showHeading();
        showMenuMinuman();

        cout << "\nPilih Menu Minuman (1-4): ";cin >> pilihan;
        while (pilihan < 1 || pilihan > 4)
        {
            cout << "Pilihan tidak valid. Masukkan 1-4: ";cin >> pilihan;
        }

        cout << "Jumlah Pesanan: ";cin >> jumlah;

        cout << "Catatan (opsional): ";cin.ignore();
        getline(cin, itemOrder[totalItem].catatan);

        // Simpan data pesanan
        itemOrder[totalItem].kodeMenu = pilihan - 1;
        itemOrder[totalItem].level = 0; // Tidak ada level untuk minuman
        itemOrder[totalItem].jumlah = jumlah;
        itemOrder[totalItem].harga = menuMinuman[pilihan-1].harga * jumlah;
        subTotal += itemOrder[totalItem].harga;
        totalItem++;

        cout << "\nTambah menu lain? (y/n): ";cin >> tambah;
    } while (tambah == 'y' || tambah == 'Y');
    // Proses pembayaran
    bayarUlang:
    system("cls");
    cout << "=======================================================" << endl;
    cout << "                   RINCIAN PESANAN                     " << endl;
    cout << "=======================================================" << endl;
    cout << left << "| " << setw(3) << "No"
         << " | " << setw(15) << "Menu"
         << " | " << setw(5) << "Jumlah"
         << " | " << setw(15) << "Catatan"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|----------------|-------|----------------|------------|" << endl;

    for (int i = 0; i < totalItem; i++)
    {
        cout << "| " << left << setw(2) << i+1
             << " | " << setw(15) << menuMinuman[itemOrder[i].kodeMenu].nama
             << " | " << setw(5) << itemOrder[i].jumlah
             << " | " << setw(15) << itemOrder[i].catatan
             << " | Rp." << setw(7) << itemOrder[i].harga << " |" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Subtotal                           : Rp." << subTotal << endl;

    // Diskon untuk member
    string member;
    cout << "Apakah Member Gacoan (y/n)?       : ";cin >> member;

    int diskon = 0;
    if (member == "y" || member == "Y") {
        diskon = 10;
    }

    int totalDiskon = subTotal * diskon / 100;
    int total = subTotal - totalDiskon;

    cout << "Diskon (" << diskon << "%)                       : Rp." << totalDiskon << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Total Pembayaran                   : Rp." << total << endl;

    // Input pembayaran dan validasi
    int bayar;
    cout << "Masukan Pembayaran                 : Rp.";cin >> bayar;

    if (total > bayar) {
        cout << "Uang Anda Kurang" << endl;
        system("pause");
        goto bayarUlang;
    }

    cout << "Kembalian                          : Rp." << bayar - total << endl;
    cout << "=======================================================" << endl;
    cout << "            Terima kasih atas pesanan Anda!            " << endl;
    cout << "=======================================================" << endl;
    system("pause");

    // Cetak Struk Pembelian
    cetakStrukPesanan(totalItem);
    system("cls");

    cout << endl;
    cout << "=======================================================" << endl;
    cout << "                 Pembayaran Selesai                    " << endl;
    cout << "=======================================================" << endl;
}
void cetakStrukPesanan(int totalItem) {
    system("cls");
    cout << "=======================================================" << endl;
    cout << "                   STRUK PEMBELIAN                     " << endl;
    cout << "=======================================================" << endl;
    cout << "Nomor Antrian  : " << dataPelayananAntrian.nomorAntrian << endl;
    cout << "Nama           : " << dataPelayananAntrian.nama << endl;
    cout << "Nomor Meja     : " << dataPelayananAntrian.nomorMeja << endl;
    cout << "Tanggal        : " << __DATE__ << endl;
    cout << "Waktu          : " << __TIME__ << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << left << "| " << setw(3) << "No"
         << " | " << setw(20) << "Menu"
         << " | " << setw(5) << "Level"
         << " | " << setw(5) << "Jumlah"
         << " | " << setw(10) << "Harga" << " |" << endl;
    cout << " |----|---------------------|-------|-------|------------|" << endl;

    int total = 0;
    for (int i = 0; i < totalItem; i++)
        {
        string namaMenu;
        if (itemOrder[i].kodeMenu < 3)
        {
            namaMenu = menuGacoan[itemOrder[i].kodeMenu].nama;
        }
        else if (itemOrder[i].kodeMenu < 8)
        {
            namaMenu = menuDimsum[itemOrder[i].kodeMenu-3].nama;
        }
        else
        {
            namaMenu = menuMinuman[itemOrder[i].kodeMenu-8].nama;
        }

        cout << "| " << left << setw(2) << i+1
             << " | " << setw(20) << namaMenu
             << " | " << setw(5) << (itemOrder[i].level > 0 ? to_string(itemOrder[i].level) : "-")
             << " | " << setw(5) << itemOrder[i].jumlah
             << " | Rp." << setw(7) << itemOrder[i].harga << " |" << endl;
        total += itemOrder[i].harga;
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Total Pembayaran                   : Rp." << total << endl;
    cout << "=======================================================" << endl;
    cout << "           Terima kasih, selamat menikmati!            " << endl;
    cout << "=======================================================" << endl;
    system("pause");
}
// ==========================
//        FUNGSI MENU
// ==========================
void menuPembelian() {
    int pil = 0;
    cin.ignore(); // Supaya tidak terjadi masalah input nama setelah cin sebelumnya

    cout << "Masukkan Tanggal (dd-mm-yyyy): ";getline(cin, dataPelayananAntrian.tanggal);
    cout << "Masukkan Waktu (hh:mm): ";getline(cin, dataPelayananAntrian.waktu);
    cout << "\nMasukkan Nama Customer  : ";getline(cin, dataPelayananAntrian.nama); // Input nama pembeli (bisa menerima spasi)
    cout << "Masukkan Nomor Meja     : ";getline(cin, dataPelayananAntrian.nomorMeja);
    dataPelayananAntrian.nomorAntrian = antri.data[antri.head]; // Simpan nomor antrian yang sedang dilayani
    do {
        system("cls");
        showHeading(); // Tampilkan heading dengan antrian yang sedang dilayani
        cout << "\nPILIH KATEGORI MENU" << endl;
        cout << "1. Mie Gacoan (Level 1-8)" << endl;
        cout << "2. Dimsum" << endl;
        cout << "3. Minuman" << endl;
        cout << "4. Selesai & Bayar\n";
        cout << "-------------------------------------------------------\n";

        cout << "Masukkan pilihan : ";cin >> pil;
        system("cls");
        switch (pil) {
        case 1:
            pembelianMakanan();
            break;
        case 2:
            pembelianDimsum();
            break;
        case 3:
            pembelianMinuman();
            break;
        case 4:
            cout << "-------------------------------------------------------\n";
            cout << "Antrian yang sudah dilayani : " << dataPelayananAntrian.nomorAntrian << endl;
            cout << "Atas nama : " << dataPelayananAntrian.nama << endl;
            cout << "Terima kasih telah berbelanja di Gacoan\n";
            cout << "-------------------------------------------------------\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            break;
        }
        if (pil != 4)
            system("pause");
    } while (pil != 4); // Keluar jika pilih EXIT
}
// ==========================
//         MAIN PROGRAM
// ==========================
int main()
{
    int pil;
    inisialisasi(); // Inisialisasi queue
    do {
        system("cls");
        showHeading(); // Tampilkan heading
        cout << "\nMENU UTAMA MIE GACOAN\n";
        cout << "1. Ambil Nomor Antrian\n";
        cout << "2. Layani Antrian \n";
        cout << "3. Bersihkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "-------------------------------------------------------\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pil;
        system("cls");
        switch (pil) {
        case 1:
            Enqueue();
            cout << "===================================================\n";
            cout << "            AMBIL NOMOR ANTRIAN PELANGGAN          \n";
            cout << "===================================================\n";
            cout << "Nomor Antrian Anda : " << antri.data[antri.tail]<< endl;
            cout << "Silakan tunggu hingga nomor Anda dipanggil         \n";
            cout << "===================================================\n";
            break;
        case 2:
            if (!isEmpty()) {
                cout << "\nMemanggil Antrian Berikutnya" << endl;
                cout << "-------------------------------------------------------\n";
                cout << "Nomor Antrian : " << antri.data[antri.head] << endl;
                cout << "-------------------------------------------------------\n";
                cout << "Silakan ke kasir\n";
                system("pause");
                menuPembelian();    // Tampilkan menu pembelian
                dequeue(); // Hapus antrian yang sudah dilayani

                // Reset data setelah melayani
                dataPelayananAntrian.nama.clear();
                dataPelayananAntrian.nomorAntrian.clear();
                dataPelayananAntrian.nomorMeja.clear();
            } else {
                cout << "Antrian Sedang Kosong" << endl;
            }
            break;
        case 3:
            clear();                                   // Hapus semua antrian
            dataPelayananAntrian.nama.clear();         // Reset nama antrian
            dataPelayananAntrian.nomorAntrian.clear(); // Reset nomor antrian
            dataPelayananAntrian.nomorMeja.clear();    // Reset nomor meja
            cout << "Semua antrian berhasil dibersihkan." << endl;
            break;
        case 4:
            cout << "==================================================\n";
            cout << "         TERIMAKASIH ATAS PEMBELIAN GACOAN        \n";
            cout << "==================================================\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            break;
        }
        if (pil != 4)
            system("pause");
    } while (pil != 4);

    return 0;
}
