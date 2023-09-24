/*
	dizi mantýðý ile oluþturulmuþtur
	first in first out
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define boyut 6

// function
void ekleme(int); 			 // ekleme
void cikarma();				 // çýkarma iþlemi
void yazdir();				 // degerleri yazdirmak icin

int dizi [boyut];
int front =-1 , rear = -1;
int count = 0;

int main(){
	int sec , sayi;
	
	while(true){
		cout << "1 eleman ekler" << endl;
		cout << "2 eleman cýkarýr" << endl;
		cout << "3 elemanlarý yazdýrýr" << endl;
		cout << "4 eleman sayýsýný gosteriri" << endl;
		cout << "Istenilen durum icin secim yapin" << endl;
		cin >> sec;
		switch(sec){
			case 1:
				cout << "sayi degeri girin: ";
				cin >> sayi;
				ekleme(sayi);
			break;
			case 2:
				cikarma();	
			break;
			case 3:
				yazdir();
			break;
			case 4:
				cout << "eleman sayisi: " << count << endl;
			break;
		}
	}
} 

void ekleme(int n){         // ekleme için kullanýlan fonksiyon
	if(rear == boyut-1){       // rear == 5 ise
		cout << "kuyruk dolu!!!"<<endl;
	}else{
		if(front == -1){
			front = 0;
		}
		count++;
		rear++;
		dizi[rear] = n;
	}
}
void cikarma(){
	if(front == -1 || front > rear){
		cout << "kuyruk bos!!! " << endl;
		front = -1;
		rear = -1;
	}else{
		front = front+1;
		count--;
	}
}

void yazdir(){
	system("cls");
	if(front == -1){
		cout << "kuyruk bos!!!" << endl;
	}else{
		for( int i=front; i<=rear ; i++ ){
			cout << dizi[i] << "  ";
		}
	}
}


