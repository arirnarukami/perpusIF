#ifndef PEMNIJAM_H
#define PEMNIJAM_H
#include<stdio.h>
#include<string.h>

typedef char text[20];

typedef struct{
	text id;
	text nama;
	int angkatan;
	int pinjaman; //jumlah buku yang dipinjam, dapat diubah pada adt peminjaman
	int denda; //total akumulasi denda yang harus dibayar, nilai dapat diubah pada adt peminjaman
} peminjam;

typedef struct{
	peminjam ID[100];
	int neff;
} tabelPeminjam;

// Konstruktor
void setMember(peminjam *P);

//Selector Get
text *getIdPeminjam(peminjam p);
text *getNama(peminjam p);
int getAngkatan(peminjam p);
int getPinjaman(peminjam p);
int getDenda(peminjam p);

//Selector Edit
void newId(peminjam *P);
void newNama(peminjam *P);
void newAngkatan(peminjam *P);

//Tabel
void setTabelMember(tabelPeminjam *PP);
void insertMember(tabelPeminjam *PP);
void editMember(tabelPeminjam *PP);
void deleteMember(tabelPeminjam *PP);
void cekMember(tabelPeminjam PP);

#endif
