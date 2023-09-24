#include<iostream>
#include<stdlib.h>
using namespace std;

void addToFoot(int);
void addHead(int);
void addBetween(int,int);
void print();
void deleteNode(int);


struct node{                 // dugum uret
	int data;                //dugumdeki data
	struct node * pointer;    // dugum pointeri
};

struct node* head = NULL;     // head dugum
struct node* temp = NULL;      // gecici dugum


int main(){

	int sayi, count=0,select,hangi;
	while(true){
		
	
		cout << "basa dugum olusturmak icin 1, araya node eklemek icin 2, sona node eklmek icin3, node silmek için 4:" <<endl;
		cin >> select;
		switch(select){
		case 1:
			cout << "eklemek istediginiz sayiyi giriniz: ";
			cin >> sayi;
			addHead(sayi);
			print();
			break;
		case 2:
			cout << "hangi dugumden once: ";
			cin >> hangi; 
			cout << "\n araya eklenecek deger: ";
			cin >> sayi;
			addBetween(hangi, sayi);
			print();
			break;
		case 3:
			cout << "eklmek istediginiz sayiyi girin: "<<endl;
			cin >>sayi;
			addToFoot(sayi);
			print();
			break;
		case 4:
			cout << "silmek istediginiz node u seçin"<<endl;
			cin>>sayi;
			deleteNode(sayi);
			print();
			break;
		}
	}
	return 0;
}

void addHead(int deger){
	struct node * willbeadded= (struct node *)malloc(sizeof( node)); // listenin basina eklenecek dugum
	
	willbeadded -> data = deger; // eklenecek data kismi
	willbeadded -> pointer = head; // eklenecek pointer kismi
	head = willbeadded; // liste basina eklenecegi icin yeni node	
}


//araya node ekleme
void addBetween(int hangi, int deger){
	struct node * willbeadded = (struct node *) malloc (sizeof(node));
	willbeadded -> data =deger; 
	temp = head;
	
	while(temp -> pointer -> data != hangi){
		temp = temp -> pointer;
	}
	
	struct node * temp2 = (struct node *) malloc (sizeof(node));
	temp2 = temp-> pointer;
	temp -> pointer = willbeadded;
	willbeadded -> pointer = temp2;
}


//sona node ekleme
void addToFoot(int deger){
	struct node * willbeadded = (struct node *) malloc (sizeof(struct node));
	willbeadded -> data = deger;
//	willbeadded -> pointer = ;

	
	if(head == NULL){   // henüz listede düðüm yoksa 
		head = willbeadded;
		willbeadded -> pointer = head; 
	}else{
		temp = head;
		
		while(temp->pointer != head){
			temp = temp ->pointer;
		}
		temp ->pointer = willbeadded;
		willbeadded->pointer = head;

	}
}

//node silme
void deleteNode(int deger) {
    temp = head;
    struct node* prev = NULL;
    // Dugum bulunana kadar ya da listenin sonuna gelene kadar ilerlenir
    while(temp != NULL && temp->data != deger) {
        prev = temp;
        temp = temp->pointer;
    }
    // Eger dugum bulunamazsa fonksiyondan cikilir
    if(temp == NULL) {
        cout << "Dugum bulunamadi." << endl;
        return;
    }
    // Dugumun listenin basinda olmasi durumu
    if(temp == head) {
        head = temp->pointer;
    } 
    // Dugum listenin ortasinda ya da sonunda ise
    else {
        prev->pointer = temp->pointer;
    }
    // Bellekten silinir
    free(temp);
}

//listedeki nodelarý yazdýrma
void print(){
	temp = head;
	while(temp -> pointer != NULL){
		cout << temp->data << " ";
		//cout << temp->pointer << " ";
		temp = temp->pointer;
	}
	cout << temp->data << endl;
}

