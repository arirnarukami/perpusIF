#include "peminjaman.h"
#include "buku.c"
#include "peminjam.c"
#include "date.c"
#define kembali 5 //Batas waktu peminjaman adalah 5 hari


void setTabel(tabelPem *T){
	(*T).neff = 0;
}


void newPjm(tabelPem *T, tabelBuku *BB, tabelPeminjam *PP, date D){
	int no, ni;
	boolean all = TRUE;
	
	if ((*BB).neff == 0){
		printf("Tidak ada buku yang ter-register.\n");
		all = FALSE;
	}
	if ((*PP).neff == 0){
		printf("Tidak ada anggota perpustakaan yang ter-register.\n");
		all = FALSE;
	}
	if (all){
		printf("Masukkan Nomor Anggota Perpustakaan    : ");
		scanf("%d",&no);
		if (no > (*PP).neff){
			printf("Tidak ada data anggota dengan nomor %d\nSilahkan input kembali, tekan <enter> untuk melanjutkan...\n", no);
			getch();
			return;
		}
		
		printf("Masukkan Nomor Index Buku Perpustakaan : ");
		scanf("%d",&ni);
		if (ni > (*BB).neff){
			printf("Tidak ada buku dengan index %d\nSilahkan input kembali, tekan <enter> untuk melanjutkan...\n", ni);
			getch();
			return;
		}
		
		if ((*BB).ID[ni].status == FALSE){
			printf("Buku tidak sedang dipinjam\n");
		}
		else{
			(*T).neff++;
			(*PP).ID[no].pinjaman++;
			(*T).ID[(*T).neff].B = (*BB).ID[ni];
			newStatus(&(*BB).ID[ni], 0);
			(*T).ID[(*T).neff].P = (*PP).ID[no];
			(*T).ID[(*T).neff].Da = D;
			(*T).ID[(*T).neff].Db = moveTime(D, kembali);
			(*T).ID[(*T).neff].idBuku = ni;
			(*T).ID[(*T).neff].idPeminjam = no;
		}
	}
}

void delPjm(tabelPem *T, tabelBuku *BB, tabelPeminjam *PP, date D){
	int no;
	
	if ((*T).neff == 0) {
		printf("Tidak Pinjaman Buku.\n");
	}
	else {
		site:
		printf("\nMasukkan Nomor Index Peminjaman    : ");
		scanf("%d",&no);
		if (no > (*T).neff){
			printf("Tidak ada pinjaman dengan index nomor %d\nSilahkan input kembali, tekan <enter> untuk melanjutkan...\n", no);
			getch();
			goto site;
		}
		
		(*PP).ID[(*T).ID[no].idPeminjam].pinjaman--;
		newStatus(&(*BB).ID[(*T).ID[no].idBuku], 1);
		while (no != (*T).neff){
			(*T).ID[no] = (*T).ID[no + 1];
			no++;
		}
		(*T).neff--;
	}
}

void cekPjm(tabelPem T){
	int i;
	
	if (T.neff == 0){
		printf("Tidak Ada Pinjaman Buku.\n");
	}
	else{
		for (i = 1; i<=T.neff; i++){
			printf("No. Index Peminjaman         : %d\n", i);
			printf(" No. Anggota Perpustakaan    : %d\n", T.ID[i].idPeminjam);
			printf(" Nama Anggota Perpustakaan   : %s\n", getNama(T.ID[i].P));
			printf(" No. Index Buku Perpustakaan : %d\n", T.ID[i].idBuku);
			printf(" Judul Buku                  : %s\n", getJudul(T.ID[i].B));
			printf(" Tanggal Masuk               : "); tulisDate(T.ID[i].Da); printf("\n");
			printf(" Tanggal Kembali             : "); tulisDate(T.ID[i].Db); printf("\n\n");
			
		}
	}
}

int hitDnd(tabelPem *T, date A, date B);
