#include  "header.h";
int main(){
    listRute L;
    adrRute r;
    adrJadwal j;
    jadwal waktu;
    int pilihanMenuUtama;
    string kodeRute;
    createListRute(L);
    while(pilihanMenuUtama != 7){
        cout << "===== Menu Rute dan Jadwal =====" << endl;
        cout << "1. Tambah Rute Baru" << endl;
        cout << "2. Tambah Jadwal ke Rute" << endl;
        cout << "3. Hapus Rute" << endl;
        cout << "4. Hapus Jadwal dari Rute" << endl;
        cout << "5. Tampilkan Rute dan Jadwal" << endl;
        cout << "6. Cari Rute berdasarkan Kota" << endl;
        cout << "   Asal/Tujuan" << endl;
        cout << "7. Keluar" << endl;
        cout << "=================================" << endl;
        cout << "Masukkan pilihan menu: ";
        cin >> pilihanMenuUtama;
        cout << "=================================" << endl;
        switch (pilihanMenuUtama){
            case 1:
                // Tambah Rute Baru
                displayList(L);
                tambahRuteBaru(L, r, j);
                break;
            case 2:
                // Tambah Jadwal ke Rute
                displayList(L);
                cout << endl;
                tambahJadwalKeRute(L, r, j);
                break;
            case 3:
                // Hapus Rute
                displayList(L);
                cout << endl;
                cout << "Masukkan Kode Rute yang akan dihapus: ";
                cin >> kodeRute;
                cout << "================================ " << endl;
                hapusRute(L, r, kodeRute);
                displayList(L);
                break;
            case 4:
                // Hapus jadwal dari rute
                cout << "Masukkan Kode Rute yang jadwalnya akan dihapus: ";
                cin >> kodeRute;
                cout << "================================ " << endl;
                cout << "Masukkan jadwal berangkat yang akan dihapus: ";
                cin >> waktu.waktuKeberangkatan;
                cout << "Masukkan waktu tiba yang akan dihapus: ";
                cin >> waktu.waktuTiba;
                cout << "================================ " << endl;
                hapusjadwal(L, r, kodeRute, waktu);
                displayList(L);
                break;
            case 5:
                // Tampilkan data
                int pilihanTampil;
                cout << "1. Tampilkan semua rute dan jadwal" << endl;
                cout << "2. Tampilkan rute dengan jadwal terbanyak" << endl;
                cout << "3. Kembali" << endl;
                cout << "Masukkan pilihan: ";
                cin >> pilihanTampil;
                if(pilihanTampil == 1){
                    displayList(L);
                    cout << endl;
                }else if(pilihanTampil == 2){
                    jadwalTerbanyak(L);
                }
                break;
            case 6:
                // Cari Rute berdasarkan Kota Asal/Tujuan
                int pilihanCari;
                cout << "1. Cari berdasarkan Kota Asal" << endl;
                cout << "2. Cari berdasarkan Kota Tujuan" << endl;
                cout << "3. Kembali" << endl;
                cout << "Masukkan pilihan: ";
                cin >> pilihanCari;
                if(pilihanCari == 1){
                    string kotaAsal;
                    cout << "Masukkan Kota Asal: ";
                    cin >> kotaAsal;
                    searchByKotaAsal(L, kotaAsal);
                } else if(pilihanCari == 2){
                    string kotaTujuan;
                    cout << "Masukkan Kota Tujuan: ";
                    cin >> kotaTujuan;
                    searchByKotaTujuan(L, kotaTujuan);
                }
                break;
            case 7:
                break;
            default:
                cout << "=================================" << endl;
                cout << "Pilihan tidak valid silahkan ulangi" << endl;
                cout << "=================================" << endl;
                break;
        }
    }
    return 0;
}
