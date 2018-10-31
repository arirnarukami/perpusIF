#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H
#include<stdio.h>
#include<string.h>
#include "boolean.h"
#include "buku.h"
#include "peminjam.h"
#include "date.h"

typedef struct{
	buku B;
	int idBuku;
	peminjam P;
	int idPeminjam;
	date Da;
	date Db;
} peminjaman;

typedef struct{
	peminjaman ID[100];
	int neff;
} tabelPem;

void setTabel(tabelPem *T);
void newPjm(tabelPem *T, tabelBuku *BB, tabelPeminjam *PP, date D);
void delPjm(tabelPem *T, tabelBuku *BB, tabelPeminjam *PP, date D);
void cekPjm(tabelPem T);

int hitDnd(tabelPem *T, date A, date B);

#endif
