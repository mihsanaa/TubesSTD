#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elemenRute *adrRute;
typedef struct elemenJadwal *adrJadwal;

struct rute{
    string kodeRute;
    string kotaAsal;
    string kotaTujuan;
    string namaOperator;
};

struct jadwal{
    string waktuKeberangkatan;
    string waktuTiba;
};

struct elemenRute{
    rute info;
    adrRute next;
    adrRute prev;
    adrJadwal firstJadwal;
};

struct elemenJadwal{
    jadwal info;
    adrJadwal next;
    adrJadwal prev;
};

struct listRute{
    adrRute first;
    adrRute last;
};

void createListRute(listRute &L);
bool isEmptyRute(listRute L);
bool isEmptyJadwal(adrRute r);
adrRute createElemenRute(string kodeRute, string kotaAsal, string kotaTujuan, string namaOperator);
adrJadwal creteElemenJadwal(string waktuKeberangkatan, string waktuTiba);
void addRute(listRute &L, adrRute r);
void addJadwal(adrRute r, adrJadwal j);
bool uniqueRute(listRute L, string kodeRute);
void displayList(listRute L);
void searchByKotaAsal(listRute L, string kotaAsal);
void searchByKotaTujuan(listRute L,string kotaTujuan);
void tambahJadwalKeRute(listRute &L, adrRute &r, adrJadwal &j);
void tambahRuteBaru(listRute &L, adrRute &r, adrJadwal &j);
void hapusjadwal(listRute &L,adrRute &r, string kodeRute, jadwal waktu);
void hapusRute(listRute &L,adrRute &r, string kodeRute);
adrRute searchRute(listRute L, string kodeRute);
void jadwalTerbanyak(listRute L);
#endif // HEADER_H_INCLUDED
