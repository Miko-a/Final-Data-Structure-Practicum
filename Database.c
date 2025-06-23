#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

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
    getch();
}

void ubah_data() {
 FILE *f = fopen("data.bin", "rb+");
    if (!f) {
        printf("Gagal membuka file.\n");
        return;
    }
    char target[11];
    printf("Masukkan NRP yang ingin diubah: ");
    scanf(" %[^\n]", target);
    Mahasiswa mhs;
    int found = 0;

    while (fread(&mhs, sizeof(Mahasiswa), 1, f)) {
        if (strcmp(mhs.nrp, target) == 0) {
            printf("Data ditemukan. Masukkan data baru:\n");
            printf("Nama                : "); scanf(" %[^\n]", mhs.nama);
            printf("Gender (0=L/1=P)    : "); scanf("%d", &mhs.gender);
            printf("IPK                 : "); scanf("%f", &mhs.ipk);

        fseek(f, -(long)sizeof(Mahasiswa), SEEK_CUR);
        fwrite(&mhs, sizeof(Mahasiswa), 1, f);
        printf("Data Berhasil Diubah\n");
        getch();
        found = 1;
        break;
    }
}
    if (!found) {
    printf("NRP tidak ditemukan.\n");
    getch();
    }
    fclose(f);
}
}

void tampil_data(int idx) {

}

void hapus_data() {

}

int main() {
    int pilihan = 0;
    char key;

    const char* teks[] = {
        "1. Tambah data",
        "2. Ubah data",
        "3. Tampilkan semua data dengan index",
        "4. Tampilkan semua data tanpa index",
        "5. Hapus data",
        "6. Keluar"
    };

    while (1) {
        system("cls");
        printf("Menu Pengelolaan Data Mahasiswa\n");
        for (int i = 0; i < 6; i++) {
            if (i == pilihan)
                printf("-> %s\n", teks[i]);
            else
                printf("   %s\n", teks[i]);
        }

        key = getch();
        if (key == -32 || key == 0) {  // Arrow keys prefix
            
            key = getch();
            if (key == 72) { // Up arrow
                pilihan--;
                if (pilihan < 0) pilihan = 5;
            } 
            else if (key == 80) { // Down arrow
                pilihan++;
                if (pilihan > 5) pilihan = 0;
            }
        } 
        
        else if (key == 13) { // Enter
            switch (pilihan) {
                case 0: tambah_data(); break;
                case 1: ubah_data(); break;
                case 2: tampil_data(1); break;  // dengan index
                case 3: tampil_data(0); break;  // tanpa index
                case 4: hapus_data(); break;
                case 5: return;
            }
        }
    }

}
