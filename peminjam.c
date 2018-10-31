#include "peminjam.h"

// Konstruktor
void setMember(peminjam *P){
	newId(&(*P));
	newNama(&(*P));
	newAngkatan(&(*P));
	(*P).pinjaman = 0;
	(*P).denda = 0;
}

//Selector Get
text *getIdPeminjam(peminjam p){
	return p.id;
}

text *getNama(peminjam p){
	return p.nama;
}

int getAngkatan(peminjam p){
	return p.angkatan;
}
int getPinjaman(peminjam p){
	return p.pinjaman;
}

int getDenda(peminjam p){
	return p.denda;
}

void newId(peminjam *P){
	fflush(stdin);
	printf("Masukkan Nomor Induk Mahasiswa  : ");
	text id;
	gets(id);
	strcpy((*P).id,id);
}

void newNama(peminjam *P){
	printf("Masukkan Nama Anggota           : ");
	text nama;
	gets(nama);
	strcpy((*P).nama,nama);
}

void newAngkatan(peminjam *P){
	printf("Masukkan Tahun Angkatan Anggota : ");
	int ang;
	scanf("%d",&ang);
	(*P).angkatan = ang;
}

void setTabelMember(tabelPeminjam *PP){
	(*PP).neff = 0;
}

void insertMember(tabelPeminjam *PP){
	peminjam P;
	setMember(&P);
	(*PP).neff++;
	(*PP).ID[(*PP).neff] = P;
}

void editMember(tabelPeminjam *PP){
	int x;
	peminjam P;
	
	if ((*PP).neff == 0) printf("Tidak ada anggota yang ter-register.\n");
	else {
		printf("Masukkan nomor anggota         : ");
		scanf("%d",&x);
		if (x > (*PP).neff) printf("Tidak ada anggota dengan nomor anggota %d\n", x);
		else {
			setMember(&P);
			(*PP).ID[x] = P;
			printf("\nData anggota berhasil diubah.\n");
		}
	}
	
}

void deleteMember(tabelPeminjam *PP){
	int x;
	
	if ((*PP).neff == 0) printf("Tidak ada anggota yang ter-register.\n");
	else {
		printf("Masukkan nomor anggota yang ingin dihapus  : ");
		scanf("%d",&x);
		if (x > (*PP).neff) printf("Tidak ada data anggota pada nomor %d\n", x);
		else {
			while (x != (*PP).neff){
				(*PP).ID[x] = (*PP).ID[x+1];
				x++;
			}
			(*PP).neff--;
			printf("Data berhasil dihapus.\n");
		}
	}
}

void cekMember(tabelPeminjam PP){
	int i, j;
	
	if (PP.neff == 0){
		printf("Tidak ada anggota yang terdaftar...\n");
	}
	else
	for (i = 1; i <=PP.neff; i++){
		printf("Nomor Anggota Perpustakaan    : %d\n", i);
		printf("Nama Anggota                  : ",i);
		printf("%s\n",getNama(PP.ID[i])); 
		printf("Nomor Induk Mahasiswa         : ");
		printf("%s\n",getIdPeminjam(PP.ID[i]));
		printf("Tahun Angkatan                : ");
		printf("%d\n",getAngkatan(PP.ID[i]));
		printf("Banyak Pinjaman               : ");
		printf("%d\n",getPinjaman(PP.ID[i]));
		printf("Denda                         : ");
		printf("%d\n",getDenda(PP.ID[i]));
		printf("\n");
	}
}
