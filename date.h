#ifndef DATE_H
#define DATE_H
#include<stdio.h>
#include "boolean.h"

typedef struct{
	int h;
	int b;
	int t;
} date;

// Konstruktor
void makeDate(date *D);
void sekarang(date *D);

// Selector
int getHari(date D);
int getBulan(date D);
int getTahun(date D);
void tulisDate(date D);

// Edit
void newHari(date *D);
void newBulan(date *D);
void newTahun(date *D);

// Validator
boolean isKabisat(date D);   // mengembalikan TRUE jika tahun kabisat
boolean isDateRight(date D); // mengembalikan TRUE jika tanggal valid,
// seperti september hanya memiliki 30 hari, jika input date isinya (31,09,2018) maka fungsi mengembalikan FALSE
// menggunakan validator isKabisat khusus bulan februari, untuk menentukan maks tanggal pada februari

//
date moveTime(date D, int hari);
int lamaWaktu(date today, date D);
boolean isLate(date today, date D); //TRUE jika today lebih kecil dari D atau D adalah hari besok, lusa, atau beberapa hari berikutnya.

#endif
