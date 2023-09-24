/*
		AHMET CEL�L YALMAN
		22181616702
		
		VER� YAPILARI VE ALGOR�TMALAR �DEV-6
		
		   --DO�.DR. ADEM TEKEREK--
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node { // A�A�TA KULLANILACAK D���M YAPISI
    int data;
    Node* left;
    Node* right;
};
/*------------------------------------*/
// �devde istenen i�lemleri yapan fonksiyonlar
int dugumSayisiBul(Node*);    //D���M SAYISI
int agacYuksekligiBul(Node*); //A�A� Y�KSEKL���
int kokDegeriBul(Node*);      //K�K DE�ERi
void yaprakDugumleriniAl(Node*, vector<int>&);//YAPRAK D���MLER�
Node* ataBul(Node*, Node*);  //ATA D���M
void kardesBul(Node*, Node* ); //KARDE� DE�ERLER
int derinlikBul(Node*, Node*, int);//DER�NL�K DE�ER�
/*------------------------------------*/

//MA�N FONKS�YONU
int main() {
    // ilgili a�a� veri yap�s� olu�turulur 
    Node* kok = new Node{8, NULL, NULL};
    kok->left = new Node{4, NULL, NULL};
    kok->right = new Node{12, NULL, NULL};
    kok->left->left = new Node{2, NULL, NULL};
    kok->left->right = new Node{5, NULL, NULL};
    kok->left->right->right = new Node{7, NULL, NULL};
    kok->left->left->right = new Node{3, NULL, NULL};
    kok->right->left = new Node{9, NULL, NULL};
    kok->right->right = new Node{14, NULL, NULL};
    kok->right->left->right = new Node{10, NULL, NULL};
 	// ilgili a�ac�n sonu
    
    cout << "Agacin dugum sayisi: " << dugumSayisiBul(kok) << endl; // a�a�taki d���m say�s�n� bulan fonksiyon

    cout << "Agacin yuksekligi: " << agacYuksekligiBul(kok) << endl; // a�ac�n y�ksekli�ini bulan fonksiyon

    cout << "Agacin kok degeri: " << kokDegeriBul(kok) << endl; // k�k de�erini bulan fonksiyon

    vector<int> yaprakDegerleri; //d���meler vekt�re atan�r
    yaprakDugumleriniAl(kok, yaprakDegerleri); // fonsiyona kok de�erleri ve vekt�r parametre olarak aktar�l�r

    cout << "Yaprak dugumlerin degeri: ";
    for (int i = 0; i < yaprakDegerleri.size(); i++) {
        cout << yaprakDegerleri[i] << "  ";    // son node a kadar gelmi� node de�erlerini bast�r�r(yapraklar)
    }
	cout << endl;
	cout << endl;
    
    Node* hedef = kok->right->left->right;
	Node* ata = ataBul(kok, hedef);   // 10 numaral� sayin�n bulundu�u nodun atas�n�n nodunu d�nd�ren fonksiyon 
	if (ata != nullptr) {
	    cout << hedef->data << " nin atasi:  " << ata->data << endl;
	} else {
	    cout << hedef->data << " nin atasi yok:  " << endl;
	}
	
	Node* node = kok->left->right;   //  5 say�s�n�n bulundu�u nodun karde�ini bulan fonksiyon
	kardesBul(kok, node);   
	
	Node* hedef2 = kok->right->left;   // 9 say�s�n�n derinli�i 
	int derinlik = derinlikBul(kok, hedef2, 0);
	cout  << hedef2->data << " nin derinligi:  " << kok->left->right->data - derinlik << endl; //derinli�i bulur
}





//D���M SAYISI
int dugumSayisiBul(Node* kok) { // node laron sa� ve solundaki �ocuklara gider ve varsa her d���m i�in 1 ekler
    if (kok == NULL) {
        return 0;
    }
    return 1 + dugumSayisiBul(kok->left) + dugumSayisiBul(kok->right); //eklenme i�lemi i�in recursive func.
}
//A�A� Y�KSEKL���
int agacYuksekligiBul(Node* kok) {
    if (kok == NULL) {
        return -1; // bo� a�ac�n y�ksekli�i -1'dir
    }
    int sagYukseklik = agacYuksekligiBul(kok->right);
    int solYukseklik = agacYuksekligiBul(kok->left);

    return 1 + max(solYukseklik, sagYukseklik); // en  y�ksek kol hangisi ise y�ksekli�i max(param,param)iel bulunur
}
//K�K DE�ERi
int kokDegeriBul(Node* kok) {
    if (kok == NULL) {
        return -1; // a�a� bo� ise ge�ersiz de�er (-1) d�nd�r�r�z
    }
    return kok->data; // kok de�erini d�nd�r�yor
}
//YAPRAK D���MLER�
void yaprakDugumleriniAl(Node* kok, vector<int>& yaprakDegerleri) {
    if (kok == NULL) {
        return;
    }
    if (kok->left == NULL && kok->right == NULL) {
        yaprakDegerleri.push_back(kok->data);   // son node a geldi�inde durur
        return;
    }
    yaprakDugumleriniAl(kok->left, yaprakDegerleri); // soldaki node son node a kadar ilerletir
    yaprakDugumleriniAl(kok->right, yaprakDegerleri); // sa� i�in
}

//ATA D���M
Node* ataBul(Node* root, Node* node) {
    if (root == nullptr || root == node) {
        return nullptr;
    }
    Node* ancestor = nullptr;
    while (root != nullptr) { // k�k fonksiyon var iken(a�a� var)
        if (node->data < root->data) { 
            ancestor = root;
            root = root->left;
        } else if (node->data > root->data) {
            ancestor = root;
            root = root->right;
        } else {
            break;
        }
    }
    return ancestor; // atay� d�nd�r
}

//KARDE� DE�ERLER
void kardesBul(Node* root, Node* node) {
    if (root == nullptr || node == nullptr) {
        return;
    }
    Node* parent = nullptr;
    Node* bro = nullptr;
    if (root == node) {
        return;
    }
    while (root != nullptr) {
        if (node->data < root->data) {
            parent = root;
            root = root->left;
        } else if (node->data > root->data) {
            parent = root;
            root = root->right;
        } else {
            break;
        }
    }
    if (parent == nullptr) {
        cout << "kok kardese sahip degil" << endl;
        return;
    }
    if (parent->left == node) {
        bro = parent->right;
    } else {
        bro = parent->left;
    }
    if (bro == nullptr) {
        cout << "node " << node->data << " kardese sahip degil" << endl;
    } else {
        cout << node->data << " nin kardesi:  " << bro->data << endl;
    }
}
//DER�NL�K DE�ER�
int derinlikBul(Node* root, Node* node, int depth = 0) {
    if (root == nullptr || node == nullptr) {
        return -1;
    }
    if (root == node) {
        return depth;
    }
    int solDerinlik = derinlikBul(root->left, node, depth + 1);
    if (solDerinlik != -1) {
        return solDerinlik;
    }
    int sagDerinlik = derinlikBul(root->right, node, depth + 1);
    if (sagDerinlik != -1) {
        return sagDerinlik;
    }
    return -1;
}



