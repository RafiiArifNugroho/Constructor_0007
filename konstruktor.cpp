#include <iostream>
#include <string>
using namespace std;

class mahasiswa
{
private:
    int nim;
    string nama;

public:
    mahasiswa();
    mahasiswa(int);
    mahasiswa(string);
    mahasiswa(int, iNim, string iNama);
    void cetak();
};

mahasiswa ::mahasiswa(int iNim)
{
    nim = 0;
    nama = "";
}

mahasiswa ::mahasiswa(int iNim)
{
    nim = iNim;
}

mahasiswa ::mahasiswa(string iNama)
{
    nama = iNim;
}

mahasiswa :: mahasiswa9int iNim, string iNama)
{
    nim = iNim;
    nama = iNama;
}
void mahasiswa::cetak()
{
    cout << endl
         << "Nim =" << nim << endl;
    cout << "Nama = " << nama << endl;
}
