#include "header.h";

void tambahRuteBaru(listRute &L, adrRute &r, adrJadwal &j){
    // Menambah rute baru ke dalam list rute dengan input dari user (insert last)
    string kodeRute, kotaAsal, kotaTujuan, namaOperator;
    cout << "======== Tambah Rute Baru =======" << endl;
    cout << "Masukkan Kode Rute     : ";
    cin >> kodeRute;
    cout << "--------------------------" << endl;
    cout << "Masukkan Kota Asal     : ";
    cin >> kotaAsal;
    cout << "--------------------------" << endl;
    cout << "Masukkan Kota Tujuan   : ";
    cin >> kotaTujuan;
    cout << "--------------------------" << endl;
    cout << "Masukkan Nama Operator : ";
    cin >> namaOperator;
    cout << "=================================" << endl;

    cout << endl;
    if(uniqueRute(L, kodeRute)){
        adrRute r = createElemenRute(kodeRute, kotaAsal, kotaTujuan, namaOperator);
        addRute(L, r);
        cout << "=================================" << endl;
        cout << "Rute berhasil ditambahkan." << endl;
        cout << "=================================" << endl;
    } else {
        cout << "=================================" << endl;
        cout << "Kode Rute sudah ada." << endl;
        cout << "Rute tidak ditambahkan." << endl;
        cout << "==========================" << endl;
    }
}

void tambahJadwalKeRute(listRute &L, adrRute &r, adrJadwal &j){
    string kodeRute, waktuKeberangkatan, waktuTiba;

    cout << "=================================" << endl;
    cout << "      TAMBAH JADWAL KE RUTE       " << endl;
    cout << "=================================" << endl;

    cout << "Kode Rute          : ";
    cin >> kodeRute;

    r = searchRute(L, kodeRute);
    if(r != nullptr){
        cout << "Waktu Berangkat    : ";
        cin >> waktuKeberangkatan;
        cout << "Waktu Tiba         : ";
        cin >> waktuTiba;

        j = creteElemenJadwal(waktuKeberangkatan, waktuTiba);
        addJadwal(r, j);

        cout << "Jadwal berhasil ditambahkan." << endl;
    } else {
        cout << "Rute tidak ditemukan." << endl;
    }
    cout << "=================================" << endl;
}

void hapusjadwal(listRute &L,adrRute &r, string kodeRute, jadwal waktu){
    // Implementasi penghapusan rute berdasarkan kodeRute
    if(isEmptyRute(L)){
        cout << "=========================" << endl;
        cout << "List Rute kosong. Tidak ada yang dihapus." << endl;
        cout << "=========================" << endl;
        return;
    }else{
        adrRute r = L.first;
        adrJadwal temp = r->firstJadwal;
        r = (searchRute(L, kodeRute));
        if(r != nullptr){
            while(temp != nullptr && temp->info.waktuKeberangkatan != waktu.waktuKeberangkatan && temp->info.waktuTiba != waktu.waktuTiba){
                temp = temp->next;
            }
            if(temp == nullptr){
                cout <<  "Jadwal tidak ditemukan" << endl;
                cout << "=========================" << endl;
                return;
            }
        // Jika yang dihapus adalah jadwal pertama
            if(temp == r->firstJadwal){
                r->firstJadwal = temp->next;
                if(r->firstJadwal != nullptr){
                    r->firstJadwal->prev = nullptr;
                }
            }
        // Jika yang dihapus di tengah atau akhir
            else{
            temp->prev->next = temp->next;
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
            }
            delete temp;
            cout << "jadwal dengan waktu keberangkatan " << waktu.waktuKeberangkatan <<" dan waktu tiba "<< waktu.waktuTiba << " telah dihapus." << endl;
            cout << "=========================" << endl;
            return;
        }else{
            cout << "Rute dengan kode " << kodeRute << " tidak ditemukan." << endl;
            cout << "=========================" << endl;
        }
    }
}
void hapusRute(listRute &L,adrRute &r, string kodeRute){
    // Implementasi penghapusan rute berdasarkan kodeRute
    if(isEmptyRute(L)){
        cout << "=========================" << endl;
        cout << "List Rute kosong. Tidak ada yang dihapus." << endl;
        cout << "=========================" << endl;
        return;
    }else{
        adrRute r = L.first;
        r = (searchRute(L, kodeRute));
        if(r != nullptr){
                if(L.first == r && L.last == r){
                    // Hanya satu elemen dalam list
                    L.first = nullptr;
                    L.last = nullptr;
                }else if(L.first == r){
                    // Hapus elemen pertama
                    L.first = r->next;
                    L.first->prev = nullptr;
                }else if(L.last == r){
                    // Hapus elemen terakhir
                    L.last = r->prev;
                    L.last->next = nullptr;
                }else{
                    // Hapus elemen di tengah
                    r->prev->next = r->next;
                    r->next->prev = r->prev;
                    r->next = nullptr;
                    r->prev = nullptr;
                }
                cout << "Rute dengan kode " << kodeRute << " telah dihapus." << endl;
                cout << "=========================" << endl;
                return;
    }else{
        cout << "Rute dengan kode " << kodeRute << " tidak ditemukan." << endl;
        cout << "=========================" << endl;
        }
    }
}

void createListRute(listRute &L){
    // Inisiasi list rute
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyRute(listRute L){
    // Cek apakah list rute kosong
    return L.first == nullptr;
}

bool isEmptyJadwal(adrRute r){
    // Cek apakah list jadwal pada rute kosong
    return r->firstJadwal == nullptr;
}

adrRute createElemenRute(string kodeRute, string kotaAsal, string kotaTujuan, string namaOperator){
    // Create new rute element
    adrRute r = new elemenRute;
    r->info.kodeRute = kodeRute;
    r->info.kotaAsal = kotaAsal;
    r->info.kotaTujuan = kotaTujuan;
    r->info.namaOperator = namaOperator;
    r->next = nullptr;
    r->prev = nullptr;
    r->firstJadwal = nullptr;
    return r;
}

adrJadwal creteElemenJadwal(string waktuKeberangkatan, string waktuTiba){
    // Create new jadwal element
    adrJadwal j = new elemenJadwal;
    j->info.waktuKeberangkatan = waktuKeberangkatan;
    j->info.waktuTiba = waktuTiba;
    j->next = nullptr;
    j->prev = nullptr;
    return j;
}

void addRute(listRute &L, adrRute r){
    // Menambahkan rute ke dalam list rute insert last
    if(isEmptyRute(L)){
        L.first = r;
        L.last = r;
    } else {
        L.last->next = r;
        r->prev = L.last;
        L.last = r;
    }
}

void addJadwal(adrRute r, adrJadwal j){
    // Menambahkan jadwal ke dalam rute berdasarkan waktu keberangkatan tercepat
    if(isEmptyJadwal(r)){
        r->firstJadwal = j;
    } else {
        if(j->info.waktuKeberangkatan < r->firstJadwal->info.waktuKeberangkatan){
            // Menambahkan jadwal di awal list jika lebih cepat dari jadwal pertama
            j->next = r->firstJadwal;
            r->firstJadwal->prev = j;
            r->firstJadwal = j;
        } else {
            // Menambahkan jadwal di posisi yang sesuai
            adrJadwal temp = r->firstJadwal;
            while(temp->next != nullptr && temp->next->info.waktuKeberangkatan < j->info.waktuKeberangkatan){
                temp = temp->next;
            }
            j->next = temp->next;
            if(temp->next != nullptr){
                //Jika bukan di akhir list
                temp->next->prev = j;
            }
            temp->next = j;
            j->prev = temp;
        }
    }
}

bool uniqueRute(listRute L, string kodeRute){
    // Cek apakah kodeRute unik dalam list rute
    adrRute temp = L.first;
    while(temp != nullptr){
        if(temp->info.kodeRute == kodeRute){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

adrRute searchRute(listRute L, string kodeRute){
    // Cari rute berdasarkan kodeRute
    adrRute temp = L.first;
    while(temp != nullptr){
        if(temp->info.kodeRute == kodeRute){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void displayList(listRute L){
    // Menampilkan list rute beserta jadwalnya
    adrRute tempRute = L.first;
    int i = 1;
    cout << endl;
    if (isEmptyRute(L)){
        cout << "  tidak ada rute dan jadwal" << endl;
        cout << endl;
        cout << "================================= " << endl;
    }
    while(tempRute != nullptr){
        cout << i << ".Kode Rute        : " << tempRute->info.kodeRute << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Asal        : " << tempRute->info.kotaAsal << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Tujuan      : " << tempRute->info.kotaTujuan << endl;
        cout << "  ------------------------" << endl;
        cout << "  Nama Operator    : " << tempRute->info.namaOperator << endl;
        cout << "  ------------------------" << endl;
        cout << "  Jadwal           :" << endl;
        cout << "=================================" << endl;

        adrJadwal tempJadwal = tempRute->firstJadwal;
        if(tempJadwal == nullptr){
            cout << "  Belum ada jadwal" << endl;
            cout << "=================================" << endl;
        }
        int j = 1;
        while(tempJadwal != nullptr){
            cout << "   " << j << ".Waktu Keberangkatan : " << tempJadwal->info.waktuKeberangkatan << endl;
                          cout << "     Waktu Tiba          : " << tempJadwal->info.waktuTiba << endl;
            tempJadwal = tempJadwal->next;
            j++;
        }
        cout << endl;
        tempRute = tempRute->next;
        i++;
    }
}

void searchByKotaAsal(listRute L, string kotaAsal){
    // Cari rute berdasarkan kotaAsal
    adrRute tempRute = L.first;
    int i = 1;
    bool found = false;
    if(tempRute == nullptr){
        cout << "List Rute Kosong" << endl;
        return;
    }
    while(tempRute != nullptr){
        if(tempRute->info.kotaAsal == kotaAsal){
        found = true;
        cout << "  =========================" << endl;
        cout << i << ".Kode Rute        : " << tempRute->info.kodeRute << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Asal            : " << tempRute->info.kotaAsal << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Tujuan          : " << tempRute->info.kotaTujuan << endl;
        cout << "  ------------------------" << endl;
        cout << "  Nama Operator        : " << tempRute->info.namaOperator << endl;
        cout << "  ------------------------" << endl;
        cout << "  Jadwal               :" << endl;
        cout << "  ========================" << endl;

        adrJadwal tempJadwal = tempRute->firstJadwal;
        int j = 1;
        while(tempJadwal != nullptr){
            cout << "   " << j << ".Waktu Keberangkatan: " << tempJadwal->info.waktuKeberangkatan << ", Waktu Tiba: " << tempJadwal->info.waktuTiba << endl;
            tempJadwal = tempJadwal->next;
            j++;
        }
        cout << "  ========================" << endl;
        }
        tempRute = tempRute->next;
        i++;
    }
    if(found == false){
        cout << "  Rute dengan Kota Asal " << kotaAsal << " tidak ditemukan." << endl;
    }
    //masih salah

}

void searchByKotaTujuan(listRute L,string kotaTujuan){
    // Cari rute berdasarkan kotaTujuan
    adrRute tempRute = L.first;
    int i = 1;
    bool found = false;
    while(tempRute != nullptr){
        if(tempRute->info.kotaTujuan == kotaTujuan){
        found = true;
        cout << "  =========================" << endl;
        cout << i << ".Kode Rute        : " << tempRute->info.kodeRute << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Asal            : " << tempRute->info.kotaAsal << endl;
        cout << "  ------------------------" << endl;
        cout << "  Kota Tujuan          : " << tempRute->info.kotaTujuan << endl;
        cout << "  ------------------------" << endl;
        cout << "  Nama Operator        : " << tempRute->info.namaOperator << endl;
        cout << "  ------------------------" << endl;
        cout << "  Jadwal               :" << endl;
        cout << "  =========================" << endl;

        adrJadwal tempJadwal = tempRute->firstJadwal;
        int j = 1;
        while(tempJadwal != nullptr){
            cout << "   " << j << ".Waktu Keberangkatan: " << tempJadwal->info.waktuKeberangkatan << ", Waktu Tiba: " << tempJadwal->info.waktuTiba << endl;
            tempJadwal = tempJadwal->next;
            j++;
        }
        cout << " =========================" << endl;
        }
    tempRute = tempRute->next;
        i++;
    }
    if(found == false){
        cout << "  Rute dengan Kota Tujuan " << kotaTujuan << " tidak ditemukan." << endl;
        }

    //masih salah
}

void jadwalTerbanyak(listRute L){
    // Menampilkan rute dengan jadwal terbanyak
    adrRute tempRute = L.first;
    adrRute ruteTerbanyak = nullptr;
    int maxJadwal = 0;
    if(isEmptyRute(L)){
        cout << "Tidak ada rute di dalam list" << endl;
    }
    while(tempRute != nullptr){
        int countJadwal = 0;
        adrJadwal tempJadwal = tempRute->firstJadwal;
        while(tempJadwal != nullptr){
            countJadwal++;
            tempJadwal = tempJadwal->next;
        }
        if(countJadwal > maxJadwal){
            maxJadwal = countJadwal;
            ruteTerbanyak = tempRute;
        }
        tempRute = tempRute->next;
    }

    if(ruteTerbanyak != nullptr){
        cout << "Rute dengan jadwal terbanyak adalah:" << endl;
        cout << "Kode Rute      : " << ruteTerbanyak->info.kodeRute << endl;
        cout << "Kota Asal      : " << ruteTerbanyak->info.kotaAsal << endl;
        cout << "Kota Tujuan    : " << ruteTerbanyak->info.kotaTujuan << endl;
        cout << "Jumlah Jadwal  : " << maxJadwal << endl;
    }else{
        displayList(L);
    }
}
