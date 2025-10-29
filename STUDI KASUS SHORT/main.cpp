#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
struct PDAM
{
    char kode[20];
    char nama[50];
    float mt_awal, mt_akhir;
    int pemakaian;
    int total_bayar;
};

int hitungBayar(int pakai)
{
    if (pakai <= 10)
        return pakai * 100;
    else
        return 10 * 100 + (pakai - 10) * 50;
}

void inputData(PDAM a[], int &x)
{
    cout << "Jumlah Data Pelanggan PDAM: ";
    cin >> x;
    cin.ignore();

    for (int i = 0; i < x; i++)
    {
        cout << "\nData ke-[" << i + 1 << "]" << endl;
        cout << "Masukan Kode        : "; cin.getline(a[i].kode, 20);
        cout << "Masukan Nama        : "; cin.getline(a[i].nama, 50);
        cout << "Masukan Meter Awal  : "; cin >> a[i].mt_awal;
        cout << "Masukan Meter Akhir : "; cin >> a[i].mt_akhir;
        cin.ignore();

        a[i].pemakaian = a[i].mt_akhir >= a[i].mt_awal ? a[i].mt_akhir - a[i].mt_awal : 0;
        a[i].total_bayar = hitungBayar(a[i].pemakaian);
    }
}

void tampilkanData(PDAM a[], int x)
{
    int total_semua = 0;
    cout << "=========================================================================" << endl;
    cout << setw(6) << "Kode"
         << setw(15) << "Nama"
         << setw(10) << "Awal"
         << setw(10) << "Akhir"
         << setw(12) << "Pakai"
         << setw(15) << "Total Bayar" << endl;
    cout << "=========================================================================" << endl;

    for (int i = 0; i < x; i++)
    {
        cout << setw(6) << a[i].kode
             << setw(15) << a[i].nama
             << setw(10) << a[i].mt_awal
             << setw(10) << a[i].mt_akhir
             << setw(12) << a[i].pemakaian
             << setw(15) << a[i].total_bayar << endl;
        total_semua += a[i].total_bayar;
    }

    cout << "=========================================================================" << endl;
    cout << setw(49) << "TOTAL SEMUA:" << setw(15) << total_semua << endl;
}

void urutkanData(PDAM a[], int x)
{
    int subPilihan;
    do
    {
        cout << "\n--- SUB MENU PENGURUTAN ---" << endl;
        cout << "1. Urutkan berdasarkan Nama (A-Z)" << endl;
        cout << "2. Urutkan berdasarkan Pemakaian (Kecil ke Besar)" << endl;
        cout << "3. Urutkan berdasarkan Total Bayar (Kecil ke Besar)" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Pilihan Anda: ";
        cin >> subPilihan;

        switch (subPilihan)
        {
            case 1:
                for (int i = 0; i < x - 1; i++)
                {
                    for (int j = 0; j < x - i - 1; j++)
                    {
                        if (strcmp(a[j].nama, a[j + 1].nama) > 0)
                        {
                             swap(a[j], a[j + 1]);
                        }
                    }
                }
                cout << "Data berhasil diurutkan berdasarkan Nama." << endl;
                break;

            case 2:
                for (int i = 0; i < x - 1; i++)
                {
                    for (int j = 0; j < x - i - 1; j++)
                    {
                        if (a[j].pemakaian > a[j + 1].pemakaian)
                        {
                            swap(a[j], a[j + 1]);
                        }
                    }
                }
                cout << "Data berhasil diurutkan berdasarkan Pemakaian." << endl;
                break;

            case 3:
                for (int i = 0; i < x - 1; i++)
                {
                    for (int j = 0; j < x - i - 1; j++)
                    {
                        if (a[j].total_bayar > a[j + 1].total_bayar)
                        {
                             swap(a[j], a[j + 1]);
                        }
                    }
                }
                cout << "Data berhasil diurutkan berdasarkan Total Bayar." << endl;
                break;

            case 4:
                tampilkanData(a, x);
                break;

            case 5:
                cout << "Kembali ke menu utama..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    }
    while (subPilihan != 5);
}

int main()
{
    PDAM a[20];
    int x = 0;
    int pilihan;

    do
    {
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Input Data Pelanggan" << endl;
        cout << "2. Menu Pengurutan & Tampil Data" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
cin.ignore();

        switch (pilihan) {
            case 1:
                inputData(a, x);
                break;
            case 2:
                if (x > 0)
                    urutkanData(a, x);
                else
                    cout << "Data belum diinput. Silakan input data terlebih dahulu." << endl;
                break;
            case 3:
                cout << "Terima kasih! Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 3);

    return 0;
}
