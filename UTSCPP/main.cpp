#include <iostream>

using namespace std;

int main()
{

  int sld = 300000;
  int pilihan;
  string pin;
  const string pinbtl = "123";

  cout << "Masukkan PIN: "; cin >> pin;

  if (pin != pinbtl)
    {
    cout << "PIN salah." << endl;
    }

  do
    {


    cout << "Menu" <<endl;
    cout << "1. Hitung Biaya Komik:"<<endl;
    cout << "2. Hitung biaya belanja:"<<endl;
    cout << "3. Cek saldo:"<<endl;
    cout << "pilih menu nomor berapa:" ;cin>>pilihan;
    switch (pilihan)
    {
           case 1:
        {
        int h, tb, biaya, dskn, sld;
        strin sts;
        cout << "Masukkan jumlah hari peminjaman: "; cin >> h;
        cout << "Masukkan status (m= member, bm= bukan member) : ";cin >> sts;
     if (h <= 2)
        {
              biaya = h * 2000;
        }
     else
        {
              biaya = 2 * 2000 + ((h - 2) * 1000);
        }

        if (sts == "M")
        {
          if (biaya > 50000)
          {
            dskn = tb * 0.10;
          }
          else
          {
            dskn = tb * 0.05;
          }
        }


        if (sld >= biaya)
        {
          sld -= biaya;
          cout << "Biaya total: " << biaya << endl;
          cout << "Diskon:" << dskn<<endl;
          cout << "Saldo setelah transaksi: " << sld << endl;
        }
        else
        {
          cout << "Saldo tidak cukup." << endl;
        }
        break;
    }

    case 2: {

        int jmlhb, harba, tb, dskn;
        cout << "Masukkan jumlah barang: "; cin >> jmlhb;
        cout << "Masukkan harga barang satuan: "; cin >> harba;

        tb = jmlhb * harba;


        if (tb > 50000 && tb < 100000)
        {
          dskn = tb * 0.05;
        }
        else if (tb >= 100000)
        {
          dskn = tb * 0.10;
        }


        if (sld >= tb)
        {
          sld -= tb;
          cout << "Total belanja sesudah diskon: " << tb << endl;
          cout << "Total diskon: " << dskn << endl;
          cout << "Saldo sesudah transaksi: " << sld << endl;
        }
        else
        {
          cout << "Saldo tidak mencukupi." << endl;
        }
        break;
      }

      case 3:

        cout << "Saldo saat ini: " << sld << endl;
        break;

      default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }
  } while (pilihan!= 4);
    while ("");

  return 0;
}
