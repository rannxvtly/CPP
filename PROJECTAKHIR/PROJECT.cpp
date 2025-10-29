#include <iostream>
using namespace std;
int main ()

{
    int bj, i, bytkt[50], jmlhharga[50], hrga[50], jmlhbeli[50], tb, pajak, byr, kmbli;
    char nmkstmr[40], kodefilm[15];
    string jdlfilm[25];

    cout<<"kode\t\tJudul Film\t\tHarga"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    cout<<" 1.\t\tAlmarhum\tRp.40000"<<endl;
    cout<<" 2.\t\tLaura\t\tRp.45000"<<endl;
    cout<<" 3.\t\tKKN Di Desa Penari\tRp.50000"<<endl;
    cout<<" 4.\t\tSorop\t\tRp.45000"<<endl;
    cout<<"-----------------------------------------------------------------\n";

    cout<<"Nama Customer: ";cin>>nmkstmr;
    cout<<"Jumlah banyak jenis film: ";cin>>bj;
    cout<<endl;
    jmlhbeli[bj]=0;
    for(i=1;i<=bj;i++)
{
    cout<<"Pembelian tiket:"<<i<<endl;
    cout<<"Masukkan kode film [1|2|3|4]:";cin>>kodefilm[i];
    cout<<"Banyaknya Tiket:";cin>>bytkt[i];
    cout<<endl;

    if(kodefilm[i]=='1'||kodefilm[i]=='1')
    {
        jdlfilm[i]="Almarhum";
        hrga[i]=40000;
    }
    else if(kodefilm[i]=='2'||kodefilm[i]=='2')
    {
        jdlfilm[i]="Laura";
        hrga[i]=45000;
    }
    else if(kodefilm[i]=='3'||kodefilm[i]=='3')
    {
        jdlfilm[i]="KKN Di Desa Penari";
        hrga[i]=50000;
    }
    else if (kodefilm[i]=='4'||kodefilm[i]=='4')
    {
        jdlfilm[i]="Sorop";
        hrga[i]=45000;
    }
    else
    {
        jdlfilm[i]="salah masukkan";
        hrga[i]=0;
    }
    jmlhharga[i]=bytkt[i]*hrga[i];
    jmlhbeli[bj]=jmlhbeli[bj]+jmlhharga[i];
}
 pajak=0.1*jmlhbeli[bj];
 tb=pajak+jmlhbeli[bj];

 cout<<"======================================================"<<endl;
 cout<<"NO.\tkode\tJudul Film\t\tharga\t\tJumlah Tiket\t\tJumlah Harga"<<endl;
 cout<<"------------------------------------------------------"<<endl;
 for(i=1;i<=bj;i)

     cout<<i<<"\t"<<kodefilm[i]"\t"<<jdlfilm[i]<<"\tRp."<<hrga[i]<<"\t\t"<<bytkt[i]<<"\tRp."<<jmlhharga[i];
     cout<<endl;
 }
 cout<<"------------------------------------------------------"<<endl;
 cout<<"Jumlah bayar:Rp"<<jmlhbeli[bj]<<endl;
 cout<<"pajak 10%:Rp"<<pajak<<endl;
 cout<<"Total Bayar:Rp"<<tb<<endl;
 cout<<"Uang Pembayaran:Rp";cin>>bayar;
 cout<<"Uang Kembalian Anda:Rp"<<byr-tb<<endl;
 cout<<"------------------------------------------------------"<<endl;

