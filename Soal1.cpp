#include<iostream>
using namespace std;

const int maxElem=255;
struct Queue
{
    int no[maxElem];
    int urg[maxElem];
    int head;
    int tail;
};

void createQueue(Queue& Q)
{
    Q.head=0;
    Q.tail=-1;
}

void enQueue(Queue& Q, int NoAntri, int urg)
{
    if(Q.tail==maxElem-1){
        cout<<"Antrian Penuh!"<<endl;
    }else{
        Q.tail=Q.tail + 1;
		Q.no[Q.tail] = NoAntri;
        Q.urg[Q.tail] = urg;
    }
}

void cetak(Queue Q,int a){
    cout<<"Queue : \n";
    if(Q.tail<0){
        cout<<"Antrian Kosong!\n";
    }else{
        for(int i=Q.head;i<a;i++){
            cout<<"No.Antrian : "<<Q.no[i]<<" - Urgensi : "<<Q.urg[i]<<endl;
        }
    }
}

void sort(Queue& Q){
    for(int i=Q.tail;i>Q.head;i--){
        for(int j=0;j<i;j++){
            if(Q.urg[j]<Q.urg[j+1]){
                swap(Q.no[j],Q.no[j+1]);
                swap(Q.urg[j],Q.urg[j+1]);
            }
        }
    }
}

int main()
{
    Queue Q;
    int a,b;
    int n;
    int k;

    createQueue(Q);
    cout<<"Masukkan banyak data : ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Antrian ke-"<<i+1<<endl;
        cout<<"Urgensi : ";cin>>b;
        enQueue(Q,i+1,b);
    }
    cetak(Q,Q.tail+1);
    sort(Q);
    
    cout<<"\nBanyak batas antrian :";cin>>k;
    cetak(Q,k);
}