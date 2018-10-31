#include<stdio.h>
#include "peminjaman.c"
#define batas 100

date D;


void border(){
	int i;
	
	for (i = 0; i<batas; i++) printf("=");
	printf("\n");
}

void head(){
	int i;
	system("cls");
	border();
	for (i = 0; i<batas/2 - 8; i++) printf(" ");
	sekarang(&D);
	printf("ADT PEMINJAMAN\n");
	for (i = 0; i<batas/2 - 6; i++) printf(" ");
	tulisDate(D);
	printf("\n");
	border();
	printf("\n");
}

void input(int *in){
	fflush(stdin);
	printf("\nInput  = ");
	scanf("%d",&(*in));
}

void done(){
	printf("Tekan <Enter> untuk melanjutkan...");
	getch();
}

int main(){
	int in, i;
	tabelBuku BB;
	setTabelBuku(&BB);
	tabelPeminjam PP;
	setTabelMember(&PP);
	tabelPem TT;
	setTabel(&TT);
	sekarang(&D);
	
			
	menuAwal:
		head();
		printf("Menu:\n");
		printf("  1. Data\n");
		printf("  2. Peminjaman\n");
		printf("  3. Cek Data Peminjaman\n");
		printf("  4. Pengembalian\n");
		printf("  5. Exit\n");
		input(&in);
		
		switch(in){
			case 1:
				goto menu1;
			case 2:
				head();
				newPjm(&TT, &BB, &PP, D);
				done();
				goto menuAwal;
			case 3:
				head();
				cekPjm(TT);
				done();
				goto menuAwal;
			case 4:
				head();
				delPjm(&TT, &BB, &PP, D);
				done();
				goto menuAwal;
			case 5:
				goto exit;
			default:
				printf("Input Salah\n");
				done();
		}
		head();
		goto menuAwal;
		
	menu1: 
		head();
		printf("Menu:\n");
		printf("  1. Register Buku\n");
		printf("  2. Edit Buku\n");
		printf("  3. Delete Buku\n");
		printf("  4. Cek Buku\n");
		printf("  5. Register Member\n");
		printf("  6. Edit Member\n");
		printf("  7. Delete Member\n");
		printf("  8. Cek Member\n");
		printf("  9. Kembali\n");
		input(&in);
		
		switch(in){
			case 1:
				head();
				insertBuku(&BB);
				done();
				break;
			case 2:
				head();
				editBuku(&BB);
				done();
				break;
			case 3:
				head();
				deleteBuku(&BB);
				done();
				break;
			case 4:
				head();
				cekBuku(BB);
				done();
				break;
			case 5:
				head();
				insertMember(&PP);
				done();
				break;
			case 6:
				head();
				editMember(&PP);
				done();
				break;
			case 7:
				head();
				deleteMember(&PP);
				done();
				break;
			case 8:
				head();
				cekMember(PP);
				done();
				break;
			case 9:
				goto menuAwal;
			default:
				printf("Input Salah\n");
				done();
		}
		head();
		goto menu1;
		
		
	exit:
		border();
		for (i = 0; i<batas/2-6; i++) printf(" ");
		printf("Terimakasih!\n");
		border();
}
