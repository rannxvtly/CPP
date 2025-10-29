#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void tampilkanMenu()
{
    system ("cls");//untuk membersihkan layar sebelum menampilkan menu
    cout << "kode\t\tJudul Film\t\tHarga" << endl;
    cout << "==================================================================\n";
    cout << " 1.\t\tAlmarhum\t\tRp.40000" << endl;
    cout << " 2.\t\tLaura\t\t\tRp.45000" << endl;
    cout << " 3.\t\tKKN Di Desa Penari\tRp.50000" << endl;
    cout << " 4.\t\tSorop\t\t\tRp.45000" << endl;
    cout << " 5.\t\tMiracle in Cell no.7\tRp.40000" <<endl;
    cout << "==================================================================\n";
}


void prosesKodeFilm(char kode, string &judul, int &harga)
{
    switch (kode)
    {
        case '1':
            judul = "Almarhum";
            harga = 40000;
            break;
        case '2':
            judul = "Laura";
            harga = 45000;
            break;
        case '3':
            judul = "KKN Di Desa Penari";
            harga = 50000;
            break;
        case '4':
            judul = "Sorop";
            harga = 45000;
            break;
        case '5':
            judul = "Miracle in Cell No.7";
            harga = 40000;
        default:
            judul = "Kode salah";
            harga = 0;
            break;
    }
}


void cetakDetailPembelian(int bj, char kodefilm[50], string jdlfilm[50], int hrga[50], int bytkt[50], int jmlhharga[40])
{
    cout << "======================================================" << endl;
    cout << "No.\tkode\tJudul Film\t\tharga\t\tJumlah Tiket\t\tJumlah Harga" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int i = 1; i <= bj; i++)
    {
        cout << i << setw(10) << kodefilm[i] << setw(10) << jdlfilm[i]
             << setw(10) << hrga[i] << setw(5) << bytkt[i] << setw(10) << jmlhharga[i] << endl;
    }
    cout << "------------------------------------------------------" << endl;
}

int main()
{
    char pilihan;
    do
    {
    int bj, i, bytkt[50], jmlhharga[50], hrga[50], jmlhbeli = 0, byr, tb, kmbli;
    int jmlhtiket =0;
    char nmkstmr[40], kodefilm[15];
    string jdlfilm[30];

    tampilkanMenu();

    cout << "Nama Customer: ";cin >> nmkstmr;
    cout << "Jumlah banyak jenis ayam: ";cin >> bj;
    cout << endl;

    for (i = 1; i <= bj; i++)
    {
        cout << "Pembelian tiket:" << i << endl;
        cout << "Masukkan kode film [1|2|3|4]: ";cin >> kodefilm[i];
        cout << "Banyaknya Tiket: ";cin >> bytkt[i];
        jmlhtiket += bytkt[i];
        cout << endl;

        prosesKodeFilm(kodefilm[i], jdlfilm[i], hrga[i]);
        jmlhharga[i] = bytkt[i] * hrga[i];
        jmlhbeli += jmlhharga[i];
    }
    //cek diskon 15% jika total tiket >= 3
    float diskon =0;
    if (jmlhtiket >= 3)
    {
        diskon = 0.05 * jmlhbeli;
        cout << "diskon 5% jika membeli 3 tiket atau lebih: Rp" <<diskon<<endl;
        jmlhbeli -= diskon;
    }
    else
    {
        cout << "tidak ada diskon karena jumlah tiket kurang dari 3"<<endl;
    }

    cetakDetailPembelian(bj, kodefilm, jdlfilm, hrga, bytkt, jmlhharga);

    cout << "Jumlah bayar setelah diskon (jika ada): Rp" << jmlhbeli << endl;
    cout << "Diskon 5%: Rp" << diskon << endl;
    cout << "Uang Pembayaran: Rp";cin >> byr;
    kmbli = byr - jmlhbeli;
    cout << "Uang Kembalian Anda: Rp" << kmbli << endl;
    cout << "======================================================" << endl;

    cout<< "Apakah anda ingin membeli lagi? (y/n):";cin >> pilihan;
    }
    while (pilihan == 'y'|| pilihan =='y');

    cout <<"Terimakasih atas pemebelian anda." <<endl;

    return 0;
}
