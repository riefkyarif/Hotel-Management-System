//Kelompok Sayur Asem

//Riefky Arif Ibrahim 1806194725
//Kevin Geovany 1806147956

//Kelas Algoritma & Pemrograman 1

#include <stdio.h>
#include <string.h>
#include <conio.h>

int pilihan, ad, i, mak, min, j, t;
int checkin, checkout, bulancheckin, bulancheckout, lantai, totalawal, totalakhir, kodekupon;
int jumlahkamar, jumlahad, jumlahmak, jumlahmin, jumlahhari;
float kupon, pajak;

char temp[100];
char pencarian[100][100];

char tipekamar[100][100] = {"Single Bedroom", "Double Bedroom", "President"};
int hargatipekamar[3] = {200000, 300000, 400000};
char additionalservice[100][100] = {"-", "Handuk Tambahan", "Bantal Tambahan", "Guling Tambahan", "Spa", "Gym Pass"};
int hargaadditionalservice[6] = {0, 15000, 20000, 20000, 30000, 30000};

char makanan[100][100] = {"-", "Nasi Goreng", "Mie Goreng", "Salad Buah", "Nasi Ayam", "Nasi Kucing", "Sate Ayam"};
char minuman[100][100] = {"-", "Es Teh", "Air Putih", "Kopi", "Jus Mangga", "Jus Jambu", "Jus Pisang", "Es Batu"};
int hargamakanan[7] = {0, 20000, 10000, 15000, 25000, 18000, 26000};
int hargaminuman[8] = {0, 3000, 2000, 5000, 10000, 12000, 11000, 1500};

//////////	( Menu Utama )
int main(){																	//Fungsi main ditunjukkan pada awal program
	system("cls");
	printf("\n                                               =  HOTEL SAYUR ASEM  =\n");
	printf("                                               ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("=======================================  Selamat Datang di Hotel Sayur Asem!  ========================================\n\n\n\n");
	printf("====================================================  Menu Hotel  ====================================================\n\n");
	printf("  (1) Reservasi Hotel\n\n  (2) Fasilitas Hotel\n\n  (3) Cari dan Urutkan\n\n  (4) Tukarkan Kode Diskon\n\n  (5) Help\n\n  (6) Keluar Program\n\n");
	printf("-----------\n Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)													//jika pilihan 1 akan beralih ke fungsi reservasi hotel
		reservasi_hotel();
	else if(pilihan == 2)												//jika pilihan 2 akan beralih ke fungsi additional
		additional();
	else if(pilihan == 3)												//jika pilihan 3 akan beralih ke fungsi sorting dan searching
		pilihan_sorting();
	else if(pilihan == 4)												//jika pilihan 4 akan beralih ke fungsi tukar diskon
		tukardiskon();
	else if(pilihan == 5)												//jika pilihan 5 akan beralih ke fungsi help
		help();
	else if(pilihan == 6)												//jika pilihan 6 akan beralih ke fungsi keluar program
		return keluarprogram();
	else
		return pengulanganmain_error();
}
int pengulanganmain_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return main();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganmain_error();
}


//////////	( Menu Reservasi Hotel )
int reservasi_hotel(){														//Fungsi Ini digunakan untuk Kalkulasi Reservasi Hotel serta outputnya menampilkan Receipt pemesanan Hotel.
	system("cls");
	jumlahhari = 0;
	totalawal = 0;
	totalakhir = 0;
	pajak = 0;
	kupon = 0;
	printf("\n                                               =  HOTEL SAYUR ASEM  =\n");
	printf("                                               ~~~~~~~~~~~~~~~~~~~~~~\n");	
	printf("\n===============================================  Menu Reservasi Hotel  ===============================================\n\n\n");
	printf("\t* Selamat Datang di Kolom Reservasi Hotel Kami.\n\t* Silakan Isi Data Berikut.\n\n\tNote:\n");
	printf("\t* Check-in dihitung dari pukul 13.00 hari check-in dan check-out dihitung hingga pukul 13.00 hari check-out.\n");
	printf("\t* Keterlambatan check-out akan dikenakan biaya tambahan yang akan ditagih oleh pihak Hotel pada hari\n\t  keterlambatan.\n\n");
	printf("\t\t> Bulan check-in : ");
	scanf("%d", &bulancheckin);
	printf("\t\t> Tanggal check-in : ");
	scanf("%d", &checkin);								//Memasukkan tanggal checkin
	printf("\t\t> Bulan check-out: ");
	scanf("%d", &bulancheckout);
	printf("\t\t> Tanggal check-out: ");
	scanf("%d", &checkout);								//Memasukkan tanggal checkout
	total_hari(checkin, checkout, bulancheckin, bulancheckout);						//Fungsi total_hari digunakan untuk menghitung total hari inap hotel
	printf("\n\t* total hari: %d", jumlahhari);			//Print jumlah hari setelah dikalkulasi
	printf("\n\n=====================================================================================================================\n");
	
	tabeltipekamar();								//Menampilkan tabel tipe kamar yang tersedia
	printf("\n\t\t> Pilih Tipe Kamar: ");
	scanf("%d", &i);								//Memasukkan nomor untuk tipe kamar yang bersesuaian
	printf("\t\t> Jumlah: ");
	scanf("%d", &jumlahkamar);						//Input jumlah kamar yang ingin dipesan
	lantaipilihan();
	printf("\n\t* Kamar Pilihan: %s, jumlah kamar: %d, Pada lantai: %d", tipekamar[i-1], jumlahkamar, lantai);	//print tipe kamar, jumlah kamar, dan lantai yang dipesan
	printf("\n\n=====================================================================================================================\n");
	
	printf("\n\t* Ingin membeli additional services?\n\t(1)	Ya\n\t(2)	Tidak\n\n\t\t> Pilihan: ");
	scanf("%d", &pilihan);							//pilihan ingin membeli additional atau tidak
	
	if(pilihan == 1){
		tabeladditionalservice();					//Menampilkan tabel additional services
		printf("\t\t> Pilih additional services: ");
		scanf("%d", &ad);							//input nomor untuk additional services yang bersesuaian
		printf("\t\t> Jumlah: ");
		scanf("%d", &jumlahad);						//input jumlah additional services yang diinginkan
				
		tabelmakanan();								//Menampilkan tabel makanan
		printf("\t\tPilih Makanan: ");
		scanf("%d", &mak);							//input nomor untuk menu makanan yang bersesuaian
		printf("\t\tJumlah: ");
		scanf("%d", &jumlahmak);					//input jumlah makanan yang diinginkan
		
		tabelminuman();								//Menampilkan tabel minuman
		printf("\t\tPilih Minuman: ");
		scanf("%d", &min);							//input nomor untuk menu minuman yang bersesuaian
		printf("\t\tJumlah: ");
		scanf("%d", &jumlahmin);					//input jumlah minuman yang diinginkan
		
		printf("\n\tAdditional Service yang dipilih: %s, Jumlah: %d", additionalservice[ad], jumlahad);			//print aditional serv. yang dipilih beserta jumlahnya
		printf("\n\tMakanan: %s (%d) dan Minuman: %s (%d)", makanan[mak], jumlahmak, minuman[min], jumlahmin);	//print makanan, minuman yang dipilih beserta jumlahnya
	}
	
	else if(pilihan == 2){
		ad = 0, mak = 0, min = 0;					//jika tidak memilih additional maka nilai variabel array akan ernilai 0 yang mengindikasikan harganya 0 rupiah
	}
	printf("\n\n=====================================================================================================================\n");
	printf("\tOverview:\n\n");
	printf("\n\t* total hari: %d", jumlahhari);
	printf("\n\t* Kamar Pilihan: %s, jumlah kamar: %d, Pada lantai: %d", tipekamar[i-1], jumlahkamar, lantai);
	printf("\n\t* Additional Services:\n\t  %s\n\t  %s\n\t  %s", makanan[mak], minuman[min], additionalservice[ad]);
	
	kalkulasi_awal(i, lantai, jumlahkamar, ad, jumlahhari, jumlahad);		//fungsi kalkulasi awal (sebelum diterapkan diskon dan pajak)
	printf("\n\n\t	Harga Total: Rp%d", totalawal);								//print kalkulasi awal
	printf("\n\n=====================================================================================================================\n");
		
	printf("\n\tIngin mengaktifkan kupon?\n\t1.	Ya\n\t2.	Tidak\n\n\t\t> Pilihan: ");
	scanf("%d", &pilihan);													//decision untuk mengaktifkan kupon atau tidak
	printf("\n\n=====================================================================================================================\n");
	
	if(pilihan == 1){														//jika pilihan 1 maka kupon diaktifkan dengan nilai 0.1 serta pajak 0.025 dari kalkulasi awal
		kupon = 0.1;														//kupon 10%
		pajak = 0.025;														//pajak 2.5%
		redeemkupon();														//fungsi ini ditunjukkan untuk meredeem kupon dengan memasukkan kode kupon

    printf("\n\n\t=== Receipt ===============================\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Item			type					Qty	Hari	Harga(Rp)|\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Tipe Kamar		%-16s (@Rp%-7d)		%d	%d	%-9d|\n", tipekamar[i-1], hargatipekamar[i-1], jumlahkamar, jumlahhari, (hargatipekamar[i-1]*jumlahkamar)*jumlahhari);
    printf("\t|Lantai			%-16d (x0.5%%xRp%-6d)		%d	%-9.0f|\n", lantai, hargatipekamar[i-1], jumlahhari, ((0.5/100)*lantai*hargatipekamar[i-1])*jumlahkamar*jumlahhari);
    printf("\t|additional		%-16s (@Rp%-7d)		%d		%-9d|\n", additionalservice[ad], hargaadditionalservice[ad], jumlahad, hargaadditionalservice[ad]*jumlahad*jumlahhari);
    printf("\t|Makanan		%-16s (@Rp%-7d)		%d		%-9d|\n", makanan[mak], hargamakanan[mak], jumlahmak, hargamakanan[mak]*jumlahmak);
    printf("\t|Minuman		%-16s (@Rp%-7d)		%d		%-9d|\n", minuman[min], hargaminuman[min], jumlahmin, hargaminuman[min]*jumlahmin);   
    printf("\t------------------------------------------------------------------------------------------\n");
	printf("\t|Total										%-9d|\n", totalawal);
    printf("\t|Diskon (10 %%)									%-9.0f|\n", kupon*totalawal);
    printf("\t|Pajak (2,5 %%)									%-9.0f|\n", pajak*totalawal);
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Total (Setelah diskon)								%-9d|\n", totalakhir);
    printf("\t------------------------------------------------------------------------------------------\n");
	}
	
	else if(pilihan == 2){													//jika tidak mengaktifkan kupon maka
		kupon = 0;															//nilai kupon = 0
		pajak = 0.025;														//nilai pajak = 2.5%
		totalakhir = totalawal - (totalawal*kupon) + (totalawal*pajak);		//kalkulasi total akhir
		printf("\n\t\tHarga Total Final: %d", totalakhir);
		receipt(i, lantai, jumlahkamar, ad, jumlahhari, jumlahad, kupon, mak, min, jumlahmak, jumlahmin, pajak);	//masuk ke fungsi receipt untuk menampilkan tabel
	}
	finalisasi();															//masuk ke fungsi finalisasi
}
		//A. Finalisasi
int finalisasi(){															//Fungsi ini ditunjukkan untuk menanyai apakah ingin mengirim reservasi yang diajukan atau membatalkannya
	printf("\n Finalisasi:\n + (1) Kirim Reservasi\n + (2) Batalkan\n Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){																	//jika ya, maka reservasi dikirim
		system("cls");
		printf("\n Permohonan Reservasi Anda Telah Terkirim.");
		printf("\n        == Terima Kasih :) ==");
		printf("\n\n + (1) Kembali ke Menu Utama\n + (2) Keluar Program\n  Pilihan: ");	//menanyakan apakah ingin kembali ke menu utama atau keluar program
		scanf("%d", &pilihan);
		if(pilihan == 1)
			return main();																//kembali ke fungsi main
		else if(pilihan == 2)
			return keluarprogram();
		else
			pengulanganfinalisasi_error();
	}
	else if(pilihan == 2){																//jika tidak, maka reservasi dibatalkan
		system("cls");
		printf("\n   == Reservasi Anda Telah Dibatalkan ==\n");
		printf("\n\n + (1) Kembali ke Menu Utama\n + (2) Keluar Program\n  Pilihan: ");	//menanyakan apakah ingin kembali ke menu utama atau keluar program
		scanf("%d", &pilihan);
		if(pilihan == 1)
			return main();																//kembali ke fungsi main
		else if(pilihan == 2)
			return keluarprogram();														//masuk ke menu keluarprogram
		else
			pengulanganfinalisasi_error();
	}
}
int pengulanganfinalisasi_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return finalisasi();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganfinalisasi_error();
}
		//B. Kalkulasi Total Hari
int total_hari(int checkin, int checkout, int bulancheckin, int bulancheckout){					//Fungsi total_hari digunakan untuk menghitung total hari inap hotel
	if(bulancheckin == bulancheckout){
		if(checkin < checkout){
			jumlahhari = checkout - checkin;
			return jumlahhari;
		}
		else if(checkin > checkout){
			jumlahhari = (30-checkin) + checkout;
			return jumlahhari;
		}
		else if(checkin == checkout){
			jumlahhari = 1;
			return jumlahhari;
		}	
	}
	else if((bulancheckout - bulancheckin) == 1){
		jumlahhari = (31-checkin) + checkout;
		return jumlahhari;
	}
	else if((bulancheckout - bulancheckin) > 1){
		if(checkin > checkout){
			jumlahhari = (bulancheckout-bulancheckin)*30 + ((31-checkin) + checkout) - 30;
			return jumlahhari;
		}
		else if(checkin < checkout){
			jumlahhari = (bulancheckout-bulancheckin)*30 + ((31-checkin) + checkout) - 30;
			return jumlahhari;			
		}
	}
}
		//C. Kalkulasi Awal
int kalkulasi_awal(int i, int lantai, int jumlahkamar, int ad, int jumlahhari, int jumlahad){	//fungsi kalkulasi awal (sebelum diterapkan diskon dan pajak)
	totalawal = ((hargatipekamar[i-1]+((0.5/100)*lantai*hargatipekamar[i-1]))*jumlahkamar + hargaadditionalservice[ad]*jumlahad)*jumlahhari + hargamakanan[mak]*jumlahmak + hargaminuman[min]*jumlahmin;
	return totalawal;
}
		//D. Redeem Kupon
int redeemkupon(){															//fungsi ini ditunjukkan untuk meredeem kupon dengan memasukkan kode kupon
	printf("\n\tMasukkan Kode Kupon: ");
	scanf("%d", &kodekupon);												//memasukkan kode kupon
	if(kodekupon == 12345){													//jika kode benar, maka masuk ke kalkulasi total akhir
		totalakhir = totalawal - (totalawal*kupon) + (totalawal*pajak);		//total harga setelah diterapkan kupon dan pajak
		printf("\n\tHarga Total Final: %d", totalakhir);
	}
	else if(kodekupon != 12345){
		kuponerror();														//jika kode yang dimasukkan salah maka masuk ke fungsi kodeeror
	}
	else
		pengulanganredeem_error();
}
int pengulanganredeem_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return redeemkupon();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganredeem_error();
}
		//E. Kupon Error
int kuponerror(){															//Fungsi ini berfungsi apabila kode kupon yang diinput tidak sesuai
	system("cls");
	printf("Maaf kode kupon yang Anda masukkan tidak terdaftar.\n");
	printf("Ingin memasukkan kode lagi?\n(1) Ya\n(2) Tidak\n Pilihan: ");
	scanf("%d", &pilihan);			//decision apakah ingin mengulang memasukkan kode atau tidak
	if(pilihan == 1){				//jika ingin mengulang, maka
		redeemkupon();				//kembali ke fungsi redeem kupon
	}
	else if(pilihan == 2){			//jika tidak, maka
		kupon = 0;					//menerapkan nilai kupon = 0 (kupon tidak diterapkan)
		pajak = 0.025;				//pajak 2.5%
		totalakhir = totalawal - (totalawal*kupon) + (totalawal*pajak);												//total biaya setelah dikenai diskon dan pajak
		printf("\nHarga Total Final: %d", totalakhir);																//print total biaya akhir
		receipt(i, lantai, jumlahkamar, ad, jumlahhari, jumlahad, kupon, mak, min, jumlahmak, jumlahmin, pajak);	//masuk ke fungsi receipt untuk menampilkan tabel
		finalisasi();																								//fungsi finalisasi
	}
	else
		pengulangankuponer_error();
}
int pengulangankuponer_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return kuponerror();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulangankuponer_error();
}
		//F. Lantai pilihan
int lantaipilihan(){
	printf("\n\t* Pilih tingkat lantai (Lantai yang dipilih akan dikalikan dengan 0.5 Persen * harga kamar yang dipilih).\n");
	printf("\t Pilihan lantai: 1 - 10\n");
	printf("\n\t\t> Pilih Lantai: ");
	scanf("%d", &lantai);							//input lantai yang diinginkan
	if(lantai<1 || lantai>10){
		pengulanganlantai_error();
	}
	else
		return lantai;
}
int pengulanganlantai_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n  Mohon maaf, lantai tidak tersedia. Silakan pilih lantai dari 1 hingga 10.\n\n  Pilihan: ");
	scanf("%d", &lantai);
	if(lantai<1 || lantai>10){
		pengulanganlantai_error();
	}
	else
		return lantai;
}

//////////	( Menu Fasilitas Hotel )
int additional(){															//Fungsi ini digunakan untuk menampilkan Fasilitas Hotel yang tersedia di Hotel Sayur Asem
	system("cls");
	printf("\n===============================================  Menu Fasilitas Hotel  ===============================================\n");
	printf("\n Menu Fasilitas Hotel:\n");
	printf("\n  (1) Menu Makanan & Minuman\n\n  (2) Additional Services\n\n  (3) Tipe Kamar\n\n   Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){					//jika memilih 1 maka akan menampilkan tabel makanan dan minuman
		tabelmakanan();
		tabelminuman();
		pengulanganadditional();
	}
	else if(pilihan == 2){				//jika memilih 2 maka akan menampilkan tabel additional services
		tabeladditionalservice();
		pengulanganadditional();
	}
	else if(pilihan == 3){				//jika memilih 3 maka akan menampilkan tabel tipe kamar
		tabeltipekamar();
		pengulanganadditional();
	}
}
int pengulanganadd_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return additional();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganadd_error();
}
int pengulanganadditional(){												//Fungsi ini ditunjukkan untuk userfriendly apakah ingin kembali melihat menu/kembali ke menu utama/keluar program
	printf("\n Kembali ke Menu Utama:\n  (1) Ya\n  (2) Kembali ke Menu Fasilitas\n  (3) Keluar Program\n   Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){					//jika memilih 1 maka akan kembali ke menu utama
		printf("\n\n                 ==========                    \n");
		return main();
	}
	else if(pilihan == 2)				//jika memilih 2 maka akan kembali ke menu servis tambahan
		return additional();
	else if(pilihan == 3)
		return keluarprogram();			//jika memilih 3 maka akan beralih ke fungsi keluar program
	else
		return pengulanganpengad_error();
}
int pengulanganpengad_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return pengulanganadditional();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganpengad_error();
}
		//A. Tabel-Tabel
int tabeltipekamar(){														//Tabel tipe kamar
	int i;
    printf("\n\t== Tabel Tipe Kamar Hotel Sayur Asem ==\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Tipe Kamar		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(i=0; i<3; i++){
    	printf("\t|%d	%-25s%-11d|\n",i+1, tipekamar[i], hargatipekamar[i]);
	}
    printf("\t---------------------------------------------\n");
}
int tabelmakanan(){															//Tabel menu makanan
	int mak;
    printf("\n\n\t== Tabel Menu Makanan Hotel Sayur Asem ==\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Makanan			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(mak=1; mak<7; mak++){
    	printf("\t|%d	%-25s%-11d|\n", mak, makanan[mak], hargamakanan[mak]);
	}
	printf("\t---------------------------------------------\n");
}
int tabelminuman(){															//Tabel menu minuman
	int min;
    printf("\n\n\t== Tabel Menu Minuman Hotel Sayur Asem ==\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Minuman			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
	for(min=1; min<8; min++){
		printf("\t|%d	%-25s%-11d|\n", min, minuman[min], hargaminuman[min]);
	}
    printf("\t---------------------------------------------\n");
}
int tabeladditionalservice(){												//Tabel additional services
	int ad;
    printf("\n\n\t= Tabel Additional Services Hotel Sayur Asem =\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Additional		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(ad=1; ad<6; ad++){
    	printf("\t|%d	%-25s%-11d|\n", ad, additionalservice[ad], hargaadditionalservice[ad]);
	}
    printf("\t---------------------------------------------\n");
}
int receipt(int i, int lantai, int jumlahkamar, int ad, int jumlahhari, int jumlahad, int mak, int min, int jumlahmak, int jumlahmin){		//Tabel Receipt
	
    printf("\n\n\t=== Receipt ===============================\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Item			type					Qty	Hari	Harga(Rp)|\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Tipe Kamar		%-16s (@Rp%-7d)		%d	%d	%-9d|\n", tipekamar[i-1], hargatipekamar[i-1], jumlahkamar, jumlahhari, (hargatipekamar[i-1]*jumlahkamar)*jumlahhari);
    printf("\t|Lantai			%-16d (x0.5%%xRp%-6d)		%d	%-9.0f|\n", lantai, hargatipekamar[i-1], jumlahhari, ((0.5/100)*lantai*hargatipekamar[i-1])*jumlahkamar*jumlahhari);
    printf("\t|additional		%-16s (@Rp%-7d)		%d		%-9d|\n", additionalservice[ad], hargaadditionalservice[ad], jumlahad, hargaadditionalservice[ad]*jumlahad*jumlahhari);
    printf("\t|Makanan		%-16s (@Rp%-7d)		%d		%-9d|\n", makanan[mak], hargamakanan[mak], jumlahmak, hargamakanan[mak]*jumlahmak);
    printf("\t|Minuman		%-16s (@Rp%-7d)		%d		%-9d|\n", minuman[min], hargaminuman[min], jumlahmin, hargaminuman[min]*jumlahmin);   
    printf("\t------------------------------------------------------------------------------------------\n");
	printf("\t|Total										%-9d|\n", totalawal);
    printf("\t|Diskon (10 %%)									%-9.0f|\n", kupon*totalawal);
    printf("\t|Pajak (2,5 %%)									%-9.0f|\n", pajak*totalawal);
    printf("\t------------------------------------------------------------------------------------------\n");
    printf("\t|Total (Setelah diskon)								%-9d|\n", totalakhir);
    printf("\t------------------------------------------------------------------------------------------\n");
}


//////////	( Menu Sorting & Searching )
int pilihan_sorting(){
	system("cls");
	printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
	printf(" Selamat Datang di Menu Sorting dan Searching\n\n");
	printf("\n Menu:\n\n  (1) Mengurutkan Harga Kamar\n\n  (2) Mengurutkan Harga Makanan\n\n  (3) Mengurutkan Harga Minuman\n\n  (4) Mengurutkan Harga Additional Services\n\n  (5) Pencarian Item\n\n   Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Mengurutkan Harga Tipe Kamar\n\n");
		printf("  (1) Diurutkan secara Ascending\n\n  (2) Diurutkan secara Descending\n\n   Pilihan: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			hargatipekamar_ascending();
		}
		else if(pilihan == 2){
			hargatipekamar_descending();
		}
	}
	else if(pilihan == 2){
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Mengurutkan Harga Makanan\n\n");
		printf("  (1) Diurutkan secara Ascending\n\n  (2) Diurutkan secara Descending\n\n   Pilihan: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			hargamakanan_ascending();
		}
		else if(pilihan == 2){
			hargamakanan_descending();
		}
	}
	else if(pilihan == 3){
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Mengurutkan Harga Minuman\n\n");
		printf("  (1) Diurutkan secara Ascending\n\n  (2) Diurutkan secara Descending\n\n   Pilihan: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			hargaminuman_ascending();
		}
		else if(pilihan == 2){
			hargaminuman_descending();
		}
	}
	else if(pilihan == 4){
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Mengurutkan Harga Additional Services\n\n");
		printf("  (1) Diurutkan secara Ascending\n\n  (2) Diurutkan secara Descending\n\n   Pilihan: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			hargaadditionalservice_ascending();
		}
		else if(pilihan == 2){
			hargaadditionalservice_descending();
		}
	}
	else if(pilihan == 5){
		pencarian_item();
	}
	else
		pengulanganmenusorting_error();
}
int pengulanganmenusorting_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return pilihan_sorting();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganmenusorting_error();
}
		//A. Sorting Tipe Kamar
int hargatipekamar_ascending(){												//Fungsi mengurutkan harga tipe kamar secara ascending
	for(i=0; i<3; i++){
		for(j=i+1; j<3; j++){
			if(hargatipekamar[i]>hargatipekamar[j]){
				t = hargatipekamar[j];
				hargatipekamar[j] = hargatipekamar[i];
				hargatipekamar[i] = t;	
				strcpy(temp, tipekamar[j]);
				strcpy(tipekamar[j], tipekamar[i]);
				strcpy(tipekamar[i], temp);			
			}
		}
	}
	printf("\n\tTabel Tipe Kamar -> Harga diurutkan secara Ascending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Tipe Kamar		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(i=0; i<3; i++){
    	printf("\t|%d	%-25s%-11d|\n",i+1, tipekamar[i], hargatipekamar[i]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();	
}
int hargatipekamar_descending(){											//Fungsi mengurutkan harga tipe kamar secara descending
	for(i=0; i<3; i++){
		for(j=i+1; j<3; j++){
			if(hargatipekamar[i]<hargatipekamar[j]){
				t = hargatipekamar[j];
				hargatipekamar[j] = hargatipekamar[i];
				hargatipekamar[i] = t;
				strcpy(temp, tipekamar[j]);
				strcpy(tipekamar[j], tipekamar[i]);
				strcpy(tipekamar[i], temp);	
			}
		}
	}
	printf("\n\tTabel Tipe Kamar -> Harga diurutkan secara Descending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Tipe Kamar		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(i=0; i<3; i++){
    	printf("\t|%d	%-25s%-11d|\n",i+1, tipekamar[i], hargatipekamar[i]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();	
}
		//B. Sorting Makanan
int hargamakanan_ascending(){												//Fungsi mengurutkan harga menu makanan secara ascending
	for(mak=1; mak<7; mak++){
		for(j=mak+1; j<7; j++){
			if(hargamakanan[mak]>hargamakanan[j]){
				t = hargamakanan[j];
				hargamakanan[j] = hargamakanan[mak];
				hargamakanan[mak] = t;
				strcpy(temp, makanan[j]);
				strcpy(makanan[j], makanan[mak]);
				strcpy(makanan[mak], temp);	
			}
		}
	}
	printf("\n\tTabel Menu Makanan -> Harga diurutkan secara Ascending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Makanan			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(mak=1; mak<7; mak++){
    	printf("\t|%d	%-25s%-11d|\n", mak, makanan[mak], hargamakanan[mak]);
	}
	printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();	
}
int hargamakanan_descending(){												//Fungsi mengurutkan harga menu makanan secara descending
	for(mak=1; mak<7; mak++){
		for(j=mak+1; j<7; j++){
			if(hargamakanan[mak]<hargamakanan[j]){
				t = hargamakanan[j];
				hargamakanan[j] = hargamakanan[mak];
				hargamakanan[mak] = t;
				strcpy(temp, makanan[j]);
				strcpy(makanan[j], makanan[mak]);
				strcpy(makanan[mak], temp);	
			}
		}
	}
	printf("\n\tTabel Menu Makanan -> Harga diurutkan secara Descending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Makanan			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(mak=1; mak<7; mak++){
    	printf("\t|%d	%-25s%-11d|\n", mak, makanan[mak], hargamakanan[mak]);
	}
	printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();	
}
		//C. Sorting Minuman
int hargaminuman_ascending(){												//Fungsi mengurutkan harga menu minuman secara ascending
	for(min=1; min<8; min++){
		for(j=min+1; j<8; j++){
			if(hargaminuman[min]>hargaminuman[j]){
				t = hargaminuman[j];
				hargaminuman[j] = hargaminuman[min];
				hargaminuman[min] = t;
				strcpy(temp, minuman[j]);
				strcpy(minuman[j], minuman[min]);
				strcpy(minuman[min], temp);	
			}
		}
	}
	printf("\n\tTabel Menu Minuman -> Harga diurutkan secara Ascending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Minuman			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
	for(min=1; min<8; min++){
		printf("\t|%d	%-25s%-11d|\n", min, minuman[min], hargaminuman[min]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();
}
int hargaminuman_descending(){												//Fungsi mengurutkan harga menu minuman secara descending
	for(min=1; min<8; min++){
		for(j=min+1; j<8; j++){
			if(hargaminuman[min]<hargaminuman[j]){
				t = hargaminuman[j];
				hargaminuman[j] = hargaminuman[min];
				hargaminuman[min] = t;
				strcpy(temp, minuman[j]);
				strcpy(minuman[j], minuman[min]);
				strcpy(minuman[min], temp);	
			}
		}
	}
	printf("\n\tTabel Menu Minuman -> Harga diurutkan secara Descending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Minuman			Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
	for(min=1; min<8; min++){
		printf("\t|%d	%-25s%-11d|\n", min, minuman[min], hargaminuman[min]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();
}
		//D. Sorting Additional Service
int hargaadditionalservice_ascending(){										//Fungsi mengurutkan harga additional services secara ascending
	for(ad=1; ad<6; ad++){
		for(j=ad+1; j<6; j++){
			if(hargaadditionalservice[ad]>hargaadditionalservice[j]){
				t = hargaadditionalservice[j];
				hargaadditionalservice[j] = hargaadditionalservice[ad];
				hargaadditionalservice[ad] = t;
				strcpy(temp, additionalservice[j]);
				strcpy(additionalservice[j], additionalservice[ad]);
				strcpy(additionalservice[ad], temp);	
			}
		}
	}
	printf("\n\tTabel Menu Additional Sercices -> Harga diurutkan secara Ascending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Additional		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(ad=1; ad<6; ad++){
    	printf("\t|%d	%-25s%-11d|\n", ad, additionalservice[ad], hargaadditionalservice[ad]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();
}
int hargaadditionalservice_descending(){									//Fungsi mengurutkan harga additional services secara descending
	for(ad=1; ad<6; ad++){
		for(j=ad+1; j<6; j++){
			if(hargaadditionalservice[ad]<hargaadditionalservice[j]){
				t = hargaadditionalservice[j];
				hargaadditionalservice[j] = hargaadditionalservice[ad];
				hargaadditionalservice[ad] = t;
				strcpy(temp, additionalservice[j]);
				strcpy(additionalservice[j], additionalservice[ad]);
				strcpy(additionalservice[ad], temp);
			}
		}
	}
	printf("\n\tTabel Menu Additional Sercices -> Harga diurutkan secara Descending\n");
    printf("\t---------------------------------------------\n");
    printf("\t|No.	Additional		Harga(Rp)   |\n");
    printf("\t---------------------------------------------\n");
    for(ad=1; ad<6; ad++){
    	printf("\t|%d	%-25s%-11d|\n", ad, additionalservice[ad], hargaadditionalservice[ad]);
	}
    printf("\t---------------------------------------------\n");
	return pengulangan_sortsearch();
}
		//E. Searching
int pencarian_item(){														//fungsi ini digunakan untuk mencari item yang ada pada fasilitas Hotel Sayur Asem
	char search_nama[100];
	int ada=0;
	char temp;
	
	system("cls");
	printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
	printf(" Pencarian:\n\n  (1) Tipe Kamar\n\n  (2) Additional Services\n\n  (3) Makanan\n\n  (4) Minuman\n\n   Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){															//jika pilihan 1, mencari item tipe kamar
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Pencarian Tipe Kamar\n\n");
		printf(" *Gunakan huruf awalan kapital pada setiap katanya :)\n\n");
		printf("  Masukkan Tipe Kamar yang Anda ingin cari: ");
		scanf("%c",&temp);
		gets(search_nama);
		int found=0;
		for(j=0; j<3; j++){
			if(strcmp(tipekamar[j],search_nama)==0){
				found=1;
				break;
			}
		}
		if(found==1)
			printf("\n Item %s ada pada daftar Fasilitas kami, Harga: Rp%d\n\n", tipekamar[j], hargatipekamar[j]);
		else
			printf("\n Mohon Maaf, Item yang Anda cari TIDAK ADA pada fasilitas hotel kami..\n\n");
		return pengulangan_sortsearch();
		getch();
	}
	else if(pilihan == 2){														//jika pilihan 2, mencari item additional services
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Pencarian Additional Services\n\n");
		printf(" *Gunakan huruf awalan kapital pada setiap katanya :)\n\n");
		printf("  Masukkan Additional Services yang Anda ingin cari: ");
		scanf("%c",&temp);
		gets(search_nama);
		int found=0;
		for(j=0; j<6; j++){
			if(strcmp(additionalservice[j],search_nama)==0){
				found=1;
				break;
			}
		}
		if(found==1)
			printf("\n Item %s ada pada daftar Fasilitas kami, Harga: Rp%d\n\n", additionalservice[j], hargaadditionalservice[j]);
		else
			printf("\n Mohon Maaf, Item yang Anda cari TIDAK ADA pada fasilitas hotel kami..\n\n");
		return pengulangan_sortsearch();
		getch();		
	}
	else if(pilihan == 3){														//jika pilihan 3, mencari menu makanan
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Pencarian Menu Makanan\n\n");
		printf(" *Gunakan huruf awalan kapital pada setiap katanya :)\n\n");
		printf("  Masukkan Menu Makanan yang Anda ingin cari: ");
		scanf("%c",&temp);
		gets(search_nama);
		int found=0;
		for(j=0; j<7; j++){
			if(strcmp(makanan[j],search_nama)==0){
				found=1;
				break;
			}
		}
		if(found==1)
			printf("\n Item %s ada pada daftar Fasilitas kami, Harga: Rp%d\n\n", makanan[j], hargamakanan[j]);
		else
			printf("\n Mohon Maaf, Item yang Anda cari TIDAK ADA pada fasilitas hotel kami..\n\n");
		return pengulangan_sortsearch();
		getch();		
	}
	else if(pilihan == 4){														//jika pilihan 4, mencari menu minuman
		system("cls");
		printf("\n===============================================  Menu Cari & Urutkan  ================================================\n\n");
		printf(" Pencarian Menu Minuman\n\n");
		printf(" *Gunakan huruf awalan kapital pada setiap katanya :)\n\n");
		printf("  Masukkan Menu Minuman yang Anda ingin cari: ");
		scanf("%c",&temp);
		gets(search_nama);
		int found=0;
		for(j=0; j<8; j++){
			if(strcmp(minuman[j],search_nama)==0){
				found=1;
				break;
			}
		}
		if(found==1)
			printf("\n Item %s ada pada daftar Fasilitas kami, Harga: Rp%d\n", minuman[j], hargaminuman[j]);
		else
			printf("\n Mohon Maaf, Item yang Anda cari TIDAK ADA pada fasilitas hotel kami..\n\n");
		return pengulangan_sortsearch();
		getch();		
	}	
	else
		pengulangansearching_error();
}
int pengulangansearching_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return pencarian_item();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulangansearching_error();
}
		//F. Pengulangan Sorting
int pengulangan_sortsearch(){
	printf("\n Menu:\n  (1) Kembali ke Menu Sorting Searching\n  (2) Menu Utama\n  (3) Keluar Program\n  Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return pilihan_sorting();
	else if(pilihan == 2)
		return main();
	else if(pilihan == 3)
		keluarprogram();
	else
		pengulangansorting_error();
}
int pengulangansorting_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return pengulangan_sortsearch();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulangansorting_error();
}


//////////	( Menu Tukar Kode Diskon )
int tukardiskon(){															//Fungsi ini kan menampilkan kode diskon yang nantinya akan ditukarkan saat reservasi
	system("cls");
	printf("\n===================================================  Kode Diskon  ====================================================\n\n");
	printf("\n\t\t\t\t\t\t  Kode Diskon Anda:\n\n\t\t\t\t\t\t\t12345\n");
	printf("\n *Gunakan Kode tersebut untuk mendapatkan potongan harga 10 %% pada saat pemesanan Hotel.");
	printf("\n\n\n Kembali ke Menu Utama:\n  (1) Ya\n  (2) Keluar Program\n    Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){
		return main();													//kembali ke menu utama
	}
	else if(pilihan == 2)
		return keluarprogram();											//masuk ke menu keluar program
	else
		pengulanganmenudiskon_error();
}
int pengulanganmenudiskon_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return tukardiskon();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganmenudiskon_error();
}


//////////	( Menu Help )
int help(){																	//Menampilkan panduan penggunaan program ini
	system("cls");
	printf("\n=====================================================  Menu Help  ====================================================\n\n");
	printf("\tProgram ini dirancang untuk dapat:\n\t + mereservasi hotel\n\t  + menampilkan fasilitas hotel\n\t   + Melakukan searching dan sorting\n");
	printf("\n\tFitur Program:\n\t + Dapat mengaktifkan voucher diskon\n\t  + User Friendly\n");
	printf("\n=== Menu Reservasi Hotel ======================\n\n");
	printf("\t+ Pada Menu reservasi hotel, masukkan data-data yang kami minta seperti tanggal masuk, tanggal keluar, \n");
	printf("\t  pilihan kamar, lantai, dan seterusnya.\n\n");
	printf("\t+ Pada setiap input pada display tabel, masukkan nomor yang sesuai pada item yang Anda inginkan.\n\n");
	printf("\t+ Kemudian, Anda dapat menggunakan kupon dengan memasukkan Kode Kupon yang telah Anda dapatkan sebelumnya.\n\n");
	printf("\t+ Terakhir, Anda dapat melihat receipt berupa harga total dan rincian harganya dan dapat melakukan \n");
	printf("\t  finalisasi untuk reservasi hotel.\n\n");
	printf("\n=== Menu Fasilitasi Hotel =====================\n\n");
	printf("\t+ Pada menu fasilitas hotel, anda dapat memilih untuk menampilkan fasilitas hotel apa saja yang kami miliki.\n\n");
	printf("\t+ Terdapat pilihan untuk menampilkan Menu Makanan dan Minuman, Additional Services, serta Tipe Kamar yang kami\n\tmiliki.\n\n");
	printf("\n=== Menu Cari dan Urutkan =====================\n\n");
	printf("\t+ Pada menu ini, Anda dapat Mencari item yang Anda inginkan serta dapat Mengurutkan harga dari Fasilitas \n");
	printf("\t  Hotel baik secara Ascanding maupun Descending.\n\n");
	printf("\n=== Menu Kode Diskon ==========================\n\n");
	printf("\t+ Pada menu ini, Anda akan mendapat kode diskon (kupon), yang selanjutnya dapat ditukarkan menjadi potongan\n");
	printf("\t  harga senilai 10 %% terhadap harga total reservasi Hotel.\n");
	printf("\n\n Kembali ke Menu Utama:\n (1) Ya\n (2) Keluar Program\n Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){
		return main();													//kembali ke menu utama
	}
	else if(pilihan == 2)
		return keluarprogram();											//masuk ke menu keluar program
	else
		pengulanganmenuhelp_error();
}
int pengulanganmenuhelp_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH. Ingin menginput ulang?\n\n\t(1) Input Ulang\n\t(2) Keluar Program\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return help();
	else if(pilihan == 2)
		return keluarprogram();
	else
		return pengulanganmenuhelp_error();
}


//////////	( Keluar Program )
int keluarprogram(){														//fungsi ini bertujuan sebagai kata-kata penutup keluar program
	printf("====================================================  ~~~~~~~~~~  ====================================================\n\n");
	printf("\tYakin ingin keluar program?\n\t(1) Ya\n\t(2) Kembali ke Menu Utama\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1){
		printf("\t\t\t\t\t\t   Program Selesai,\n\n\t\t\t\tTerima Kasih atas kunjungan Anda di Hotel Sayur Asem!");
		return 0;
	}
	else if(pilihan == 2)
		return main();
	else
		return pengulanganend_error();
}
int pengulanganend_error(){
	printf("\n=== Error Notice =====================================================================================================");
	printf("\n\n\tPilihan yang Anda masukkan SALAH.\n\n\t(1) Kembali\n\t Pilihan: ");
	scanf("%d", &pilihan);
	if(pilihan == 1)
		return keluarprogram();
	else
		return pengulanganend_error();
}
