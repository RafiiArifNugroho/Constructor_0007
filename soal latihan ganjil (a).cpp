#include <iostream>
#include <string>
using namespace std;

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim, float nl) : nama(n), NIM(nim), nilai(nl) {}

    // Friend class Dosen agar bisa akses nilai Mahasiswa
    friend class Dosen;

    // Friend function spesifik untuk beriNilai
    friend void beriNilai(Mahasiswa *m, float nilaiBaru);
};

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    double gaji;

public:
    Dosen(string n, string nidn, string p, double g) : nama(n), NIDN(nidn), pangkat(p), gaji(g) {}

    // Friend function agar Staff bisa ubah pangkat Dosen
    friend void ubahPangkat(Dosen *d, string pangkatBaru);

    // Friend function agar Universitas bisa akses gaji Dosen
    friend double lihatGajiDosen(Dosen *d);
};

// Fungsi friend untuk mengubah nilai Mahasiswa
void beriNilai(Mahasiswa *m, float nilaiBaru)
{
    m->nilai = nilaiBaru;
}

// Fungsi friend untuk mengubah pangkat Dosen oleh Staff
void ubahPangkat(Dosen *d, string pangkatBaru)
{
    d->pangkat = pangkatBaru;
}