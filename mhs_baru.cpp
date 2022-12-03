#include <iostream> //memanggil modul agar dapat melakukan proses input dan output
#include <algorithm> //memanggil modul ini untuk melakukan sort

using namespace std; //penyingkatan pemanggilan fungsi seperti cin dan cout

int tambah(); //deklarasi fungsi kosong
int hapus();
int lihat();

struct mhs{ //mendeklarasikan struktur dengan nama mahasiswa
    int nomor_nim, semester;
    char kelas ;
    string nama, prodi, fakultas, alamat;
}biodata[10],*mahasiswa; //deklarasi struct biodata secara langsung dan pointer pada struct mahasiswa, tanpa harus menggandakan sruct mahasiswa

int nomor=0, pilihan,b=1; //deklarasi nomor awal yang menandakan kondisi awal belum diisi data, variabel pilihan untuk menyimpan pilihan yang dimasukkan pada menu awal , variabel b digunakan menampilkan urutan data
string konfirmasi; //menyimpan konfirmasi saat data dihapus

bool urutannim(mhs a,mhs b){ //fungsi untuk mengembalikan nilai nim pada struc mahasiswa
    if(a.nomor_nim > b.nomor_nim) //jika nomor nim pada struct a lebih besar dari struct b
        return 1;   //maka mengembalikan nilai 1
    else    //sebaliknya
        return 0; //mengembalikan nilai 0
}

bool urutannama(mhs a, mhs b){
    if(a.nama > b.nama)
        return 1;
    else
        return 0;
}

bool urutansemester(mhs a, mhs b){
    if(a.semester > b.semester)
        return 1;
    else
        return 0;
}

bool urutankelas(mhs a, mhs b){
    if(a.kelas > b.kelas)
        return 1;
    else
        return 0;
}

bool urutanprodi(mhs a, mhs b){
    if(a.prodi > b.prodi)
        return 1;
    else
        return 0;
}

bool urutanfakultas(mhs a, mhs b){
    if(a.fakultas > b.fakultas)
        return 1;
    else 
        return 0;
}

bool urutanalamat(mhs a, mhs b){
    if(a.alamat > b.alamat)
        return 1;
    else
        return 0;
}

int main() //fungsi utama
{
    cout<<"\n======================================================"
    <<"\n \tProgram Pendataan Mahasiswa Baru"
    <<"\n \t\t   Tahun 2022/2023"
    <<"\n======================================================"
    <<"\n \tSilahkan pilih : "
    <<"\n \t1. Tambah Data Data "
    <<"\n \t2. Hapus Data Data "
    <<"\n \t3. Lihat Daftar "
    <<"\n \t4. Keluar Dari Menu"
    <<"\n======================================================"<<endl;

    cout<<"\nMasukkan pilihan = ";
    cin>>pilihan;

    system("cls"); //menghapus tampilan layar
    switch(pilihan)
    {
        case 1 :
            tambah(); //memanggil fungsi tersebut
            break; //menghentikan fungsi tersebut agar tidak dieksekusi oleh case lainnya

        case 2 :
            hapus();
            break;

        case 3 :
            lihat();
            break;

        case 4:
            cout<<"\n\n";
            cout<<"Terimakasih, sudah melakukan Pendataan Mahasiswa"<<endl;
            return 0;
            break;

        default :
            cout<<"Masukkan angka sesuai pilihan di atas!"<<endl;
            system("cls");
            main();
    }
}

int tambah(){
    if(nomor==10) //jika nomor sudah bertambah hingga 10 maka akan menampilkan peringatan tersebut
        {
            system("cls");
            cout<<"Pendataan sudah penuh, silahkan hapus antrian sebelumnya!"<<endl;
        }
    else
    {
        system("cls");
        nomor++;  
		cout<<"\n======================================================"
    	<<"\n \tProgram Pendataan Mahasiswa Baru"
    	<<"\n \t\t   Tahun 2022/2023"
   	    <<"\n======================================================"  <<endl;//nomor ditambahkan diawal karena dimulai pada indeks 1 pada program ini
        
        cout<<"\nSilahkan Masukkan data diri anda"<<endl;

        cout<<"\nMasukkan NIM : ";
        cin>>biodata[nomor].nomor_nim; //mengisi struct biodata dengan indeks nomor dan pada bagian nomor_nim

        cout<<"\nMasukkan Nama : ";
        cin.get(); //mengambil satu karakter agar tidak terjadi error saat pengisian nama
        getline(cin, biodata[nomor].nama); //mengambil satu baris input

        cout<<"\nMasukkan Angka Semester : ";
        cin>>biodata[nomor].semester;

        cout<<"\nMasukkan Kelas : ";
        cin>>biodata[nomor].kelas;

        cout<<"\nMasukkan Prodi : ";
        cin>>biodata[nomor].prodi;

        cout<<"\nMasukkan Fakultas : ";
        cin>>biodata[nomor].fakultas;

        cout<<"\nMasukkan Alamat : ";
        cin.get();
        getline(cin,biodata[nomor].alamat);

        system("cls");
    }
    main();
    return 0;
}

int hapus(){
    if(nomor==0) //jika nomor 0 maka menampilkan peringatan
    {
        cout<<"\n\nData Kosong!"<<endl;
    }
    else
    {
        cout<<"\n\nNIM : "<<biodata[nomor].nomor_nim
        <<"\nNama : "<<biodata[nomor].nama
        <<"\nSemester : "<<biodata[nomor].semester
        <<"\nKelas : "<<biodata[nomor].kelas
        <<"\nProdi : "<<biodata[nomor].prodi
        <<"\nFakultas : "<<biodata[nomor].fakultas
        <<"\nAlamat : "<<biodata[nomor].alamat;

        cout<<"\nApakah yakin akan menghapus data tersebut Y/N ? ";
        cin>>konfirmasi;

        if(konfirmasi=="Y"||konfirmasi=="y")
            {
                nomor--; //nomor berkurang satu agar tak dapat ditampilkan saat melihat data
                cout<<"Hapus data berhasil!";
            }
        else
            cout<<"Hapus data batal!";
    }
    system("cls");
    main();
    return 0;
}

int lihat(){
        mahasiswa = biodata; //melakukan penggandaan nilai pada struct biodata ke struct pointer mahasiswa
        if(nomor==0)
        {
            cout<<"\n\nData masih kosong! ";
        }
        else
        {
            cout<<"\n1. Tampilkan keseluruhan Data tanpa pengurutan "
            <<"\n2. Tampilkan keseluruhan Data dengan pengurutan "
            <<"\n3. Tampilkan hanya salah satu saja "
            <<"\n4. Kembali ke menu awal "

            <<"\nPilih metode menampilkan data : ";
            cin>>pilihan;

                switch(pilihan){
                case 1:
                    system("cls");
                    for(int i=nomor; i>0; i--){ //menampilkan data dimulai pada variabel nomor lalu diakhiri nomor setelah 0 yaitu satu, dan secara terbalik data yang ditampilkan
                    mahasiswa++;
                    cout<<"\n\nData Baris ke-"<<b                               //disinilah variabel b ditampilkan sebagai penghitung baris
                    <<"\n\nNIM : "<<(*mahasiswa).nomor_nim //memanggil pointer pada struct mahasiswa
                    <<"\nNama : "<<(*mahasiswa).nama
                    <<"\nSemester : "<<(*mahasiswa).semester
                    <<"\nKelas : "<<(*mahasiswa).kelas
                    <<"\nProdi : "<<(*mahasiswa).prodi
                    <<"\nFakultas : "<<(*mahasiswa).fakultas
                    <<"\nAlamat : "<<(*mahasiswa).alamat<<endl<<endl;
                    b++;} //penghitung baris bertambah satu
                    break;

                case 2 :
                    system("cls");
                    cout<<"Pilihan pengurutan"
                    <<"\n1. Menurut NIM "
                    <<"\n2. Menurut Nama "
                    <<"\n3. Menurut Semester "
                    <<"\n4. Menurut Kelas "
                    <<"\n5. Menurut Prodi "
                    <<"\n6. Menurut Fakultas "
                    <<"\n7. Menurut Alamat "
                    <<"\n8. Kembali ke menu paling awal "

                    <<"\nMasukkan pilihan pengurutan : ";
                    cin>>pilihan;

                    switch(pilihan){
                    case 1 :
                            system("cls");

                            sort(biodata+1, biodata+1+nomor,urutannim); //mengurutkan dengan dimulai pada biodata indeks ke 1, dan diakhiri pada biodata indeks terakhir biodata, dengan variabel yang diurutkan adalah nomor nim
                            for(int i=nomor;i>0;i--){
                                cout<<"\nNIM : "<<biodata[i].nomor_nim //memanggil nilai pada variabel nomor_nim pada struct biodata sesuai indeks ke i
                                <<"\nNama : "<<biodata[i].nama
                                <<"\nSemester : "<<biodata[i].semester
                                <<"\nKelas : "<<biodata[i].kelas
                                <<"\nProdi : "<<biodata[i].prodi
                                <<"\nFakultas : "<<biodata[i].fakultas
                                <<"\nAlamat : "<<biodata[i].alamat<<endl<<endl;
                            }
                        break;

                    case 2 :
                            system("cls");

                            sort(biodata+1, biodata+1+nomor,urutannama);
                            for(int i=nomor;i>0;i--){
                                cout<<"\nNIM : "<<biodata[i].nomor_nim
                                <<"\nNama : "<<biodata[i].nama
                                <<"\nSemester : "<<biodata[i].semester
                                <<"\nKelas : "<<biodata[i].kelas
                                <<"\nProdi : "<<biodata[i].prodi
                                <<"\nFakultas : "<<biodata[i].fakultas
                                <<"\nAlamat : "<<biodata[i].alamat<<endl<<endl;
                            }
                            break;
                    case 3 :
                            system("cls");

                            sort(biodata+1, biodata+1+nomor,urutansemester);
                            for(int i=nomor;i>0;i--){
                                cout<<"\nNIM : "<<biodata[i].nomor_nim
                                <<"\nNama : "<<biodata[i].nama
                                <<"\nSemester : "<<biodata[i].semester
                                <<"\nKelas : "<<biodata[i].kelas
                                <<"\nProdi : "<<biodata[i].prodi
                                <<"\nFakultas : "<<biodata[i].fakultas
                                <<"\nAlamat : "<<biodata[i].alamat<<endl<<endl;
                            }
                            break;
                    case 4 :
                            system("cls");

                            sort(biodata+1, biodata+1+nomor,urutankelas);
                            for(int i=nomor;i>0;i--){
                                cout<<"\nNIM : "<<biodata[i].nomor_nim
                                <<"\nNama : "<<biodata[i].nama
                                <<"\nSemester : "<<biodata[i].semester
                                <<"\nKelas : "<<biodata[i].kelas
                                <<"\nProdi : "<<biodata[i].prodi
                                <<"\nFakultas : "<<biodata[i].fakultas
                                <<"\nAlamat : "<<biodata[i].alamat<<endl<<endl;
                            }
                            break;
                    case 5 :
                            system("cls");

                            sort(biodata+1, biodata+1+nomor,urutanalamat);
                            for(int i=nomor;i>0;i--){
                                cout<<"\n\nNIM : "<<biodata[i].nomor_nim
                                <<"\nNama : "<<biodata[i].nama
                                <<"\nSemester : "<<biodata[i].semester
                                <<"\nKelas : "<<biodata[i].kelas
                                <<"\nProdi : "<<biodata[i].prodi
                                <<"\nFakultas : "<<biodata[i].fakultas
                                <<"\nAlamat : "<<biodata[i].alamat<<endl<<endl;
                            }
                            break;

                    case 6 :
                        break;

                    }
                    break;

                case 3 :
                    cout<<"\nMenampilkan data yang berisi nim :";
                    break;
        }
    }

    b=1; //mengembalikan nilai b menjadi satu jika akan digunakan perulangan lagi untuk menghitung baris berapa
    main(); //kembali ke menu utama
    return 0; //mengembalikan nilai 0 karena ini merupakan fungsi int bukan fungsi void
}
