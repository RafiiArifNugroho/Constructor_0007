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