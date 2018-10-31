#ifndef BUKU_H
#define BUKU_H
#include<stdio.h>
#include<string.h>
#include "boolean.h"

typedef char text[20];

typedef struct {
	text judul;
	text pengarang;
	text ISBN;
	int tahun;
	boolean status; // TRUE jika tidak dipinjam
} buku;

typedef struct {
	buku ID[100];
	int neff;
} tabelBuku;

//Konstruktor
void setBuku(buku *B);

text *getJudul(buku B);
text *getPengarang(buku B);
text *getISBN(buku B);
int getTahunTerbit(buku B);
boolean getStatus(buku B);

//Selector Edit
void newJudul(buku *B);
void newPengarang(buku *B);
void newISBN(buku *B);
void newTahunTerbit(buku *B);
void newStatus(buku *B, int stat);

//Tabel
void setTabelBuku(tabelBuku *BB);
void insertBuku(tabelBuku *BB);
void editBuku(tabelBuku *BB);
void deleteBuku(tabelBuku *BB);
void cekBuku(tabelBuku BB);

#endif
