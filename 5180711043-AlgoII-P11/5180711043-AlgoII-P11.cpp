#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace::std;

struct data
    {
        int harga;
        char barang[100];
        int jml_barang;
    };



data pembeli[100];

data temp;
double jml;
double jum,total,diskon;



void prolog()
    {
        cout<<" =============================================\n";
        cout<<"             PEMBAYARAN  MINI MARKET\n";
        cout<<"                  TOKO SEBELAH\n";
        cout<<"    Jl. Aku Padamu No.13 telp. (0271) 56789\n";
        cout<<" =============================================\n";
    }

void itung()
{
    int i;


    cout<<" Jumlah Barang Dibeli\t: ";cin>>jml;
    cout<<" =============================================\n";
            for (i=0;i<jml;i++)
            {
                cout<<" Barang ke - "<<i+1;
                cout<<"\n ---------------------------------------------\n";
                cout<<" Nama Barang\t: ";cin>>pembeli[i].barang;
                cout<<" Harga Barang\t: ";cin>>pembeli[i].harga;
                cout<<" Jumlah barang\t: " ;cin>>pembeli[i].jml_barang;
                cout<<" ---------------------------------------------\n";
                jum+=pembeli[i].harga*pembeli[i].jml_barang;
                diskon=(jum*5)/100;
                total=jum-((jum*5)/100);
            }
}

void sorting()
{
    int r,u;

                for(r=0;r<jml;r++)
                {
                    for(u=0;u<jml-1;u++)
                        {
                            if(pembeli[u].harga > pembeli[u+1].harga)
                                {
                                     temp.harga=pembeli[u].harga;
                                     pembeli[u].harga=pembeli[u+1].harga;
                                     pembeli[u+1].harga=temp.harga;

                                     strcpy(temp.barang,pembeli[u].barang);
                                     strcpy(pembeli[u].barang,pembeli[u+1].barang);
                                     strcpy(pembeli[u+1].barang,temp.barang);

                                     temp.jml_barang=pembeli[u].jml_barang;
                                     pembeli[u].jml_barang=pembeli[u+1].jml_barang;
                                     pembeli[u+1].jml_barang=temp.jml_barang;
                                }
                        }
                }

            for(u=0;u<jml;u++)
                {
                    cout<<"\n =============================================\n";
                    cout<<" Data Barang ke- "<<u+1;
                    cout<<"\n ---------------------------------------------\n";
                    cout<<" Harga Barang\t: "<<pembeli[u].harga;
                    cout<<"\n Nama Barang\t: "<<pembeli[u].barang;
                    cout<<"\n Jumlah Barang\t: "<<pembeli[u].jml_barang;
                }
cout<<"\n =============================================\n";
}



main()
{
cout<<"\n\n";
prolog();

string jawab;
int i;
string nama;

proses:
cout<<" Member Atau Non Member [Y|N]: ";cin>>jawab;
system("CLS");

prolog();
if (jawab=="Y")
    {


string nomor_member;
string no_member[5]={"A001","A002","A003","A007","A008"};
string pelanggan[5]={"Banu","Irvan","Susiati","Diana","Banu"};
int indeks;
bool status=false;

awal:
cout<<" Masukan No. Member\t: ";cin>>nomor_member;
    for (int i=0;i<5;i++)
        {
            if (nomor_member==no_member[i])
                {
                    indeks=i;
                    status=true;
                }
        }

    if (status)
        {
            pelanggan[indeks];
        }

    else
        {
            system("CLS");
            prolog();
            cout<<"      -MEMBER TIDAK TERSEDIA INPUT KEMBALI-";
            cout<<"\n =============================================\n";
            goto awal;
        }
            itung();
            system ("CLS");
            prolog();

            cout<<"                PELANGGAN MEMBER\n";
            cout<<" =============================================\n";
            cout<<" Nama Pelanggan\t: "<<pelanggan[indeks];
            sorting();
            cout<<" Total Tanpa Diskon\t: Rp. "<<jum;
            cout<<"\n Total Diskon\t\t: Rp. "<<diskon;
            cout<<"\n Total Pembayaran\t: Rp. "<<total;
    }



else if (jawab=="N")
{
        cout<<" Masukan Nama Pelanggan: ";cin>>nama;
        itung();
        system ("CLS");
        prolog();

        cout<<"              PELANGGAN NON MEMBER\n";
        cout<<" =============================================\n";
        cout<<" Nama Pelanggan\t: "<<nama;
        sorting();
        cout<<" Total Tanpa Diskon\t: Rp. "<<jum;
        cout<<"\n Total Diskon\t\t: Rp. 0";
        cout<<"\n Total Pembayaran\t: Rp. "<<jum;}

else
    {
        cout<<"                 -INPUTAN SALAH-";
        cout<<"\n =============================================\n";
        goto proses;
    }


cout<<"\n =============================================";
cout<<"\n                 -TERIMA KASIH-";
cout<<"\n =============================================";

cout<<"\n\n\n";
return 0;
}
