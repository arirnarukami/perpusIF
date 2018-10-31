#include "buku.h"

//Konstruktor
void setBuku(buku *B){
	text ans;
	int thn;
	
	newJudul(&(*B));
	newPengarang(&(*B));
	newISBN(&(*B));
	newTahunTerbit(&(*B));
	(*B).status = TRUE;
}

//Selector Get
text* getJudul(buku B){
	return B.judul;
}

text *getPengarang(buku B){
	return B.pengarang;
}

text *getISBN(buku B){
	return B.ISBN;
}

int getTahunTerbit(buku B){
	return B.tahun;
}

boolean getStatus(buku B){
	return B.status;
}

//Selector Edit
void newJudul(buku *B){
	fflush(stdin);
	printf("Masukkan judul buku         : ");
	text judul;
	gets(judul);
	strcpy((*B).judul,judul);
}
void newPengarang(buku *B){
	printf("Masukkan nama pengarang     : ");
	text pengarang;
	gets(pengarang);
	strcpy((*B).pengarang,pengarang);
}
void newISBN(buku *B){
	printf("Masukkan ISBN buku          : ");
	text ISBN;
	gets(ISBN);
	strcpy((*B).ISBN,ISBN);
}
void newTahunTerbit(buku *B){
	printf("Masukkan tahun terbit buku  : ");
	int tahun;
	scanf("%d",&tahun);
	(*B).tahun = tahun;
}

void newStatus(buku *B, int stat){
	if (stat == 1) (*B).status = TRUE;
	else if (stat == 0) (*B).status = FALSE;
}

void setTabelBuku(tabelBuku *BB){
	(*BB).neff = 0;
}

void insertBuku(tabelBuku *BB){
	buku B;
	setBuku(&B);
	(*BB).neff++;
	(*BB).ID[(*BB).neff] = B;
}

void editBuku(tabelBuku *BB){
	int x;
	buku B;
	
	if ((*BB).neff == 0) printf("Tidak ada buku yang ter-register.\n");
	else {
		printf("Masukkan no index buku      : ");
		scanf("%d",&x);
		if (x > (*BB).neff) printf("Tidak ada buku dengan index %d\n", x);
		else {
			setBuku(&B);
			(*BB).ID[x] = B;
			printf("\nBuku berhasil diubah.\n");
		}
	}
}

void deleteBuku(tabelBuku *BB){
	int x;
	
	if ((*BB).neff == 0) printf("Tidak ada buku yang ter-register.\n");
	else {
		printf("Masukkan nomor index buku yang ingin dihapus  : ");
		scanf("%d",&x);
		if (x > (*BB).neff) printf("Tidak ada buku pada index %d\n", x);
		else {
			while (x != (*BB).neff){
				(*BB).ID[x] = (*BB).ID[x+1];
				x++;
			}
			(*BB).neff--;
			printf("Buku berhasil dihapus.\n");
		}
	}
}

void cekBuku(tabelBuku BB){
	int i, j;
	
	if (BB.neff == 0){
		printf("Tidak ada buku yang terdaftar...\n");
	}
	else
	for (i = 1; i <=BB.neff; i++){
		printf("Index Buku %d\n", i);
		printf(" Judul Buku        : ",i);
		printf("%s\n",getJudul(BB.ID[i])); 
		printf(" ISBN Buku         : ");
		printf("%s\n",getISBN(BB.ID[i]));
		printf(" Tahun Terbit Buku : ");
		printf("%d\n",getTahunTerbit(BB.ID[i]));
		printf(" Pengarang Buku    : ");
		printf("%s\n",getPengarang(BB.ID[i]));
		printf(" Status Buku       :");
		if (getStatus(BB.ID[i]) == TRUE) printf(" Tersedia\n");
		else printf(" Sedang Dipinjam\n");
		printf("\n");
	}
}
