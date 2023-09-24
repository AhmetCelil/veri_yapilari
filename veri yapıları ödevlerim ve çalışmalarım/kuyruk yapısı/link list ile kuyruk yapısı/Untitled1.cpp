/*
	linked list ile oluþturulan kuyruk yapýsý
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node * next;
};

struct node * temp = NULL;
struct node * front = NULL;
struct node * rear = NULL;

void tekYazdir(struct node *nd){
	cout << "\ndata: " << nd->data;
	cout << "\nadress: " << &(nd->next) <<endl;
}

void enqueue(int x){
	struct node * willbeadded = (struct node * )malloc (sizeof(struct node));
	willbeadded -> data = x;
	
	if(front ==  NULL){  // kuyrukta eleman yoksa
		front = willbeadded;
		front -> next = front;
		rear = willbeadded;
		rear -> next = NULL;
		tekYazdir(willbeadded);
		
	}else if(front -> next == front){
		rear -> next = willbeadded;
		rear = willbeadded;
		rear -> next = rear;
		tekYazdir(willbeadded);
		
	}else{
		rear -> next = willbeadded;
		rear = willbeadded;
		rear -> next = NULL;
		tekYazdir(willbeadded);
	}
}

void dequeue() {
	if(front == NULL){
		cout << "kuyruk bos" << endl;
	}else{
		temp = front -> next;
		free(front);
		front = temp;
	}
}

void printqueue(){
	system("cls");
	if(front == NULL)
		cout << "kuyrukta eleman yok" <<endl;
	else{
		temp = front;
		while(temp->next != NULL){
			cout << temp -> data << " ";
			temp = temp -> next;
		}
		cout << temp->data;
	}
	cout << endl;
}

int main(){
	int sec , sayi;
	while(true){
		cout << "1-kuyruga eleman eklemek icin" <<endl;
		cout << "2-kuyruktan eleman cikarmak icin" << endl;
		cout << "3-elemanlari yazdirmak icin" << endl;
		cout << "secim yapin: ";
		cin >> sec;
		switch(sec){
			case 1:
				cout << "eklenecek sayiyi girin: " << endl;
				cin >> sayi;
				enqueue(sayi);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printqueue();
				break;
		}
	}
}


















