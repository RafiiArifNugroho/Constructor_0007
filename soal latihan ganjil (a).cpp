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

// Fungsi friend untuk mengakses gaji Dosen
double lihatGajiDosen(Dosen *d)
{
    return d->gaji;
}

class Staff
{
private:
    string nama;
    string idStaff;
    double gaji;

public:
    Staff(string n, string id, double g) : nama(n), idStaff(id), gaji(g) {}

    // Friend function agar Universitas bisa akses gaji Staff
    friend double lihatGajiStaff(Staff *s);
};

double lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

class Universitas
{
public:
    void infoGaji(Dosen *d, Staff *s)
    {
        cout << "Gaji Dosen: " << lihatGajiDosen(d) << endl;
        cout << "Gaji Staff: " << lihatGajiStaff(s) << endl;
    }
};

int main()
{
    Mahasiswa mhs("Budi", "12345", 80);
    Dosen dsn("Pak Joko", "N123", "Lektor", 10000000);
    Staff stf("Bu Siti", "S001", 5000000);

    cout << "== Sebelum perubahan ==" << endl;
    Universitas univ;
    univ.infoGaji(&dsn, &stf);

    cout << "\n== Perubahan nilai Mahasiswa ==" << endl;
    beriNilai(&mhs, 95);
    cout << "Nilai Mahasiswa berhasil diubah oleh Dosen ke 95 (tidak bisa ditampilkan langsung karena private)\n";

    cout << "\n== Perubahan pangkat Dosen oleh Staff ==" << endl;
    ubahPangkat(&dsn, "Guru Besar");
    cout << "Pangkat Dosen berhasil diubah menjadi Guru Besar (tidak bisa ditampilkan langsung karena private)\n";

    cout << "\n== Sesudah perubahan ==" << endl;
    univ.infoGaji(&dsn, &stf);

    return 0;
}
