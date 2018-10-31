#include "date.h"
#include<time.h>

// Konstruktor
void makeDate(date *D){
	int hh,bb,tt;
	make:
	printf("Masukkan Hari (HH) : ");
	scanf("%d",&hh);
	(*D).h = hh;
	printf("Masukkan Bulan (BB): ");
	scanf("%d",&bb);
	(*D).b = bb;
	printf("Masukkan Tahun (TT): ");
	scanf("%d",&tt);
	(*D).t = tt;
}

void sekarang(date *D){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	(*D).h = tm.tm_mday;
	(*D).b = tm.tm_mon + 1;
	(*D).t = tm.tm_year + 1900;
}

// Selector
int getHari(date D){
	return D.h;
}
int getBulan(date D){
	return D.b;
}
int getTahun(date D){
	return D.t;
}

void tulisDate(date D){
	printf("%d/",getHari(D));
	switch(D.b){
		case 1:
			printf("Jan");
			break;
		case 2:
			printf("Feb");
			break;
		case 3:
			printf("Mar");
			break;
		case 4:
			printf("Apr");
			break;
		case 5:
			printf("Mei");
			break;
		case 6:
			printf("Jun");
			break;
		case 7:
			printf("Jul");
			break;
		case 8:
			printf("Aug");
			break;
		case 9:
			printf("Sep");
			break;
		case 10:
			printf("Oct");
			break;
		case 11:
			printf("Nov");
			break;
		case 12:
			printf("Dec");
			break;
	}
	printf("/%d",getTahun(D));
}

// Edit
void newHari(date *D){
	int h;
	ddd:
	printf("Masukkan Hari Baru (HH) : ");
	scanf("%d",&h);
	(*D).h = h;
	if (!isDateRight(*D)){
		printf("  == INPUT ERROR ==\n");
		printf("  Tekan <enter> untuk melanjutkan...\n\n");
		getch();
		goto ddd;
	}
}

void newBulan(date *D){
	int b;
	bbb:
	printf("Masukkan Bulan Baru (BB) : ");
	scanf("%d",&b);
	if ((b <= 0)||(b > 12)){
		printf("  == INPUT ERROR ==\n");
		printf("  Tekan <enter> untuk melanjutkan...\n\n");
		getch();
		goto bbb;
	}
	(*D).b = b;
}

void newTahun(date *D){
	int t;
	ttt:
	printf("Masukkan Tahun Baru (TTTT) : ");
	scanf("%d",&t);
	if (t <= 0){
		printf("  == INPUT ERROR ==\n");
		printf("  Tekan <enter> untuk melanjutkan...\n\n");
		getch();
		goto ttt;
	}
	(*D).t = t;
}



// Validator
boolean isKabisat(date D){   // mengembalikan TRUE jika tahun kabisat
	if (D.t % 4 == 0){
		return TRUE;
	}
	else return FALSE;
}
boolean isDateRight(date D){ // mengembalikan TRUE jika tanggal valid,
// seperti september hanya memiliki 30 hari, jika input date isinya (31,09,2018) maka fungsi mengembalikan FALSE
// menggunakan validator isKabisat khusus bulan februari, untuk menentukan maks tanggal pada februari
	if ((D.h<=0)||(D.b<=0)||(D.t<=0)){
		return FALSE;
	}
	else{
		switch (D.b){
			case 1:
				if (D.h > 31) return FALSE;
			case 2:
				if ((isKabisat(D))&&(D.h > 29)) return FALSE;
				else if (D.h > 28) return FALSE;
			case 3:
				if (D.h > 31) return FALSE;
			case 4:
				if (D.h > 30) return FALSE;
			case 5:
				if (D.h > 31) return FALSE;
			case 6:
				if (D.h > 30) return FALSE;
			case 7:
				if (D.h > 31) return FALSE;
			case 8:
				if (D.h > 31) return FALSE;
			case 9:
				if (D.h > 30) return FALSE;
			case 10:
				if (D.h > 31) return FALSE;
			case 11:
				if (D.h > 30) return FALSE;
			case 12:
				if (D.h > 31) return FALSE;			
		}
		return TRUE;
	}

}


// Controller
date moveTime(date D, int hari){
	D.h += hari;
	if (hari >= 0){
		while (!isDateRight(D)){
			switch (D.b){
				case 1:
					D.h -= 31;
					D.b += 1;
					break;
				case 2:
					if (isKabisat(D)) D.h -= 29;
					else D.h -= 28;
					D.b += 1;
					break;
				case 3:
					D.h -= 31;
					D.b += 1;
					break;
				case 4:
					D.h -= 30;
					D.b += 1;
					break;
				case 5:
					D.h -= 31;
					D.b += 1;
					break;
				case 6:
					D.h -= 30;
					D.b += 1;
					break;
				case 7:
					D.h -= 31;
					D.b += 1;
					break;
				case 8:
					D.h -= 31;
					D.b += 1;
					break;
				case 9:
					D.h -= 30;
					D.b += 1;
					break;
				case 10:
					D.h -= 31;
					D.b += 1;
					break;
				case 11:
					D.h -= 30;
					D.b += 1;
					break;
				case 12:
					D.h -= 31;
					D.b = 1;
					D.t += 1;
					break;
			}
		}
	}
	else{
		while (!isDateRight(D)){
			switch (D.b){
				case 1:
					D.h += 31;
					D.b = 12;
					D.t -= 1;
					break;
				case 2:
					D.h += 31;
					D.b -= 1;
					break;
				case 3:
					if (isKabisat(D)) D.h += 29;
					else D.h += 28;
					D.b -= 1;
					break;
				case 4:
					D.h += 31;
					D.b -= 1;
					break;
				case 5:
					D.h += 30;
					D.b -= 1;
					break;
				case 6:
					D.h += 31;
					D.b -= 1;
					break;
				case 7:
					D.h += 30;
					D.b -= 1;
					break;
				case 8:
					D.h += 31;
					D.b -= 1;
					break;
				case 9:
					D.h += 31;
					D.b -= 1;
					break;
				case 10:
					D.h += 30;
					D.b -= 1;
					break;
				case 11:
					D.h += 31;
					D.b -= 1;
					break;
				case 12:
					D.h += 30;
					D.b -= 1;
					break;
			}
		}
	}
	return D;
}

int lamaWaktu(date today, date D){
	int jumlah = 0;
	date tmp;
	
	if ((today.t > D.t)||((today.t == D.t)&&(today.b > D.b))||((today.t == D.t)&&(today.b == D.b)&&(today.h > D.h))) {
		tmp = today;
		today = D;
		D = tmp;
	}
	while (((today.b) != D.b)||(today.t != D.t)){
		switch (D.b){
			case 1:
				jumlah += 31;
				D.b = 12;
				D.t -= 1;
				break;
			case 2:
				jumlah += 31;
				D.b -= 1;
				break;
			case 3:
				if (isKabisat(D)) jumlah += 29;
				else jumlah += 28;
				D.b -= 1;
				break;
			case 4:
				jumlah += 31;
				D.b -= 1;
				break;
			case 5:
				jumlah += 30;
				D.b -= 1;
				break;
			case 6:
				jumlah += 31;
				D.b -= 1;
				break;
			case 7:
				jumlah += 30;
				D.b -= 1;
				break;
			case 8:
				jumlah += 31;
				D.b -= 1;
				break;
			case 9:
				jumlah += 31;
				D.b -= 1;
				break;
			case 10:
				jumlah += 30;
				D.b -= 1;
				break;
			case 11:
				jumlah += 31;
				D.b -= 1;
				break;
			case 12:
				jumlah += 30;
				D.b -= 1;
				break;
		}
	}
	if (today.h > D.h){
		switch(today.b){
			case 1:
				jumlah += (31 - today.h);
				break;
			case 2:
				if (isKabisat(today)) jumlah += (29 - today.h);
				else jumlah += (28 - today.h);
				break;
			case 3:
				jumlah += (31 - today.h);
				break;
			case 4:
				jumlah += (30 - today.h);
				break;
			case 5:
				jumlah += (31 - today.h);
				break;
			case 6:
				jumlah += (30 - today.h);
				break;
			case 7:
				jumlah += (31 - today.h);
				break;
			case 8:
				jumlah += (31 - today.h);
				break;
			case 9:
				jumlah += (30 - today.h);
				break;
			case 10:
				jumlah += (31 - today.h);
				break;
			case 11:
				jumlah += (30 - today.h);
				break;
			case 12:
				jumlah += (31 - today.h);
				break;
		}
	}
	else jumlah += (D.h - today.h);
	return jumlah;
}

boolean isLate(date today, date D){
	if ((today.t > D.t)||((today.t == D.t)&&(today.b > D.b))||((today.t == D.t)&&(today.b == D.b)&&(today.h > D.h))) {
		return TRUE;
	}
	else return FALSE;
}
