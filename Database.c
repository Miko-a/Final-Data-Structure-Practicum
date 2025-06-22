#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nrp[11];
char nama[26];
int gender;
float ipk;
} Mahasiswa;

void tambah_data(){
FILE *f = fopen("data.bin","ab");
  if (!f){
  printf("Error 404(Not Found).\n");
  return;
}

Mahasiswa mhs;
printf("NRP                 : "); scanf(" %[^\n]", mhs.nrp);
printf("Nama                : "); scanf(" %[^\n]", mhs.nama);
printf("Gender    (0=L/1=P) : "); scanf("%d", &mhs.gender);
printf("IPK                 : "); scanf("%f", &mhs.ipk);

fwrite(&mhs, sizeof(Mahasiswa),1,f);
fclose(f);
printf("✓Data Ditambahkan\n");
}
