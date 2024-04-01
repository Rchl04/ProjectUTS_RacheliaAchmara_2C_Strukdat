#include <iostream>
#include <iomanip>
using namespace std;

int dataMahasiswa = 100;

struct Mahasiswa{
    string npm;
    string nama;
    string kelas;
    string minatBidangIT;
};

int main(){
    Mahasiswa mhs;
    Mahasiswa daftarMahasiswa[dataMahasiswa];
    int jmlh_mhs = 0;
    char menuProgram;

    cout << "------------------------------------------------" << endl;
    cout << "                 DATA MAHASISWA                 " << endl;
    cout << "------------------------------------------------" << endl;
    //tersedia 5 menu Program
    while (true){
    cout<<endl;
    cout<<"Pilih menu program :"<<endl;
    cout<<"C (Input Data Mahasiswa)"<<endl; //ketik C untuk menginput data mahasiswa
    cout<<"R (Tampilkan Data Mahasiswa)"<<endl; //ketik R untuk menampilkan data mahasiswa
    cout<<"U (Edit Data Mahasiswa)"<<endl; //ketik U untuk mengedit data mahasiswa
    cout<<"D (Hapus Data Mahasiswa)"<<endl; //ketik D untuk menghapus data mahasiswa
    cout<<"E (Exit/Keluar)"<<endl<<endl; //ketik D untuk menghapus data mahasiswa
    cout<<"Input pilihan menggunakan huruf kapital (C/R/U/D) : ";
    cin>>menuProgram;
    cout<<endl;

    switch (menuProgram){
        case 'C': //untuk menginput data mahasiswa
        cout<<"Anda memilih C (Input Data Mahasiswa)"<<endl;
        if (jmlh_mhs < dataMahasiswa){
            cout << "Input NPM \t\t : ";
            cin >> daftarMahasiswa[jmlh_mhs].npm;
            cout << "Input Nama \t\t : ";
            cin >> daftarMahasiswa[jmlh_mhs].nama;
            cout << "Input Kelas \t\t : ";
            cin >> daftarMahasiswa[jmlh_mhs].kelas;
            cout << "Input Bidang IT yang diminat: ";
            cin.ignore();
            getline(cin,  daftarMahasiswa[jmlh_mhs].minatBidangIT);
        jmlh_mhs++;
        } else {
            cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
                }
        break; //break untuk membatasi gerakan dari case satu ke case lainnya

    case 'R': //untuk menampilkan data mahasiswa
        cout<<"Anda memilih R (Tampilkan Data Mahasiswa)" <<endl;
        //jika mengetik R pada pilihan sebelumnya, maka kalimat ini akan muncul
        cout << left << setw(20) << "NPM" << setw(20) << "Nama" << setw(20) << "Kelas" << setw(20) << "Minat Bidang IT" << endl;
            for (int i = 0; i < jmlh_mhs; ++i) {
                cout << left << setw(20) << daftarMahasiswa[i].npm << setw(20) << daftarMahasiswa[i].nama << setw(20) << daftarMahasiswa[i].kelas << setw(20) << daftarMahasiswa[i].minatBidangIT << endl;
                }
                break;

        for (int i = 0; i < jmlh_mhs; ++i) {
                cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
                cout << "NPM: " << daftarMahasiswa[i].npm << endl;
                cout << "Nama: " << daftarMahasiswa[i].nama << endl;
                cout << "Kelas: " << daftarMahasiswa[i].kelas << endl;
                cout << "Minat: " << daftarMahasiswa[i].minatBidangIT << endl;
        }
        break; //break untuk membatasi gerakan dari case satu ke case lainnya

    case 'U': //untuk mengedit data mahasiswa
        cout<<"Anda memilih U (Edit Data Mahasiswa)"<<endl; //jika mengetik U pada pilihan sebelumnya, maka kalimat ini akan muncul
        {
        string npmEdit;
        cout << "Masukkan NPM mahasiswa yang ingin diedit: ";
        cin >> npmEdit;

        bool found = false;
        for (int i = 0; i < jmlh_mhs; ++i) {
            if (daftarMahasiswa[i].npm == npmEdit) {
                found = true;
                cout << "Data mahasiswa ditemukan. Silakan masukkan data baru:" << endl;
                cout << "Input Kelas \t : ";
                cin >> daftarMahasiswa[i].kelas;
                cout << "Input Bidang IT yang diminati \t : ";
                cin >> daftarMahasiswa[i].minatBidangIT;
                cout << "Data mahasiswa berhasil diubah." << endl;
                break;
                }
            }
        if (!found) {
            cout << "Data mahasiswa tidak ditemukan." << endl;
            }
        }
        break;

    case 'D': //untuk menghapus data mahasiswa
    {
        cout << "Anda memilih D (Hapus Data Mahasiswa)" << endl; //jika mengetik D pada pilihan sebelumnya, maka kalimat ini akan muncul
        string npmDelete;
        cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
        cin >> npmDelete;

        bool found = false;
        for (int i = 0; i < jmlh_mhs; ++i) {
            if (daftarMahasiswa[i].npm == npmDelete) {
                found = true;
                // Geser elemen-elemen array ke posisi sebelumnya
                for (int j = i; j < jmlh_mhs - 1; ++j) {
                    daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                }
                // Kurangi jumlah mahasiswa
                jmlh_mhs--;
                cout << "Data mahasiswa berhasil dihapus." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Data mahasiswa tidak ditemukan." << endl;
        }
    }
    break;//break untuk membatasi gerakan dari case satu ke case lainnya

    case 'E':
        cout << "Terimakasih telah menggunakan program ini ^-^." << endl;
        //jika mengetik D pada pilihan sebelumnya, maka kalimat ini akan muncul
        break;

    default:
        cout<<"Pilihan tidak tersedia."<<endl; //jika pilihan yang diinput tidak sesuai, maka kalimat ini akan muncul
        cout<<endl;
    }
    }
    return 0;
}
