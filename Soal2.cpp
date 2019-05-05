#include<iostream>
#include<string.h>
using namespace std;

const int maxElem=255;

struct Queue{
    string nama [maxElem];
    int nilai[maxElem];
    int head;
    int tail;  
};
void createQueue(Queue& Q){
    Q.head=0;
    Q.tail=-1;
}
void insertQueue(Queue& Q, string nama,int nilai){
    //cout<<"Insert Queue"<<endl;
    if(Q.tail==maxElem-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else{
        Q.tail=Q.tail+1;
        Q.nama[Q.tail]=nama;
        Q.nilai[Q.tail]=nilai;
    }
}
void deleteQueue(Queue& Q,int& elemenHapus){
    cout<<"Delete Queue"<<endl;
    if(Q.head>Q.tail){
        cout<<"Antrian kosong"<<endl;
    }
    else{
        elemenHapus=Q.nilai[Q.head];
        for(int i=0;i<Q.tail;i++){
            Q.nama[i]=Q.nama[i+1];
            Q.nilai[i]=Q.nilai[i+1];
        }
    Q.tail=Q.tail-1;
    }
}
void beasiswa(Queue Q){
    while(Q.head!=Q.tail+1){
        if(Q.nilai[Q.head]>=85){
            cout<<Q.nama[Q.head]<<"\t   ";
            cout<<Q.nilai[Q.head]<<"\t\t";
            
            if(Q.nilai[Q.head]>=95){
                cout<<"Rp 10.000.000"<<endl;
            }
            else if(Q.nilai[Q.head]<95 && Q.nilai[Q.head]>=90){
                cout<<"Rp 7.500.000"<<endl;
            }
            else{
                cout<<"Rp 5.000.000"<<endl;
            }
        }
    Q.head+=1;
    }
}
void cetak(Queue Q){
    while(Q.head!=Q.tail+1){
        cout<<Q.nama[Q.head]<<"\t ";
        cout<<Q.nilai[Q.head]<<endl;
        Q.head+=1;
    }
}
int main(){
    Queue Q,B;
    int nilai,n,elemenhapus;
    int siswa;
    string nama;
    createQueue(Q);
    cout<<"Masukkan banyak siswa : ";cin>>siswa;
    do{
        system("cls");
        cout<<"Nama : "; cin.ignore(); getline(cin,nama);
        cout<<"Nilai: "; cin>>nilai;
        cout<<endl;
        if(nilai<0 || nilai>100){
            cout<<"Nilai salah, silahkan masukkan ulang"<<endl;
            ++siswa;
            system("pause");
        }
        else{
            insertQueue(Q,nama,nilai);
        }
        --siswa;        
    }while(siswa!=0);

    cout<<"--------DAFTAR SISWA--------"<<endl;
    cout<<"Nama\t\t Nilai"<<endl;
    cetak(Q);cout<<endl<<endl;

    cout<<" Daftar Penerima Beasiswa  "<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Nama\t\t Nilai\t\t Beasiswa"<<endl;
    beasiswa(Q);

}