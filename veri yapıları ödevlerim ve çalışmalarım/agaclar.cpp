/*
		AHMET CELÝL YALMAN
		22181616702
		
		VERÝ YAPILARI VE ALGORÝTMALAR ÖDEV-6
		
		   --DOÇ.DR. ADEM TEKEREK--
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node { // AÐAÇTA KULLANILACAK DÜÐÜM YAPISI
    int data;
    Node* left;
    Node* right;
};
/*------------------------------------*/
// ödevde istenen iþlemleri yapan fonksiyonlar
int dugumSayisiBul(Node*);    //DÜÐÜM SAYISI
int agacYuksekligiBul(Node*); //AÐAÇ YÜKSEKLÝÐÝ
int kokDegeriBul(Node*);      //KÖK DEÐERi
void yaprakDugumleriniAl(Node*, vector<int>&);//YAPRAK DÜÐÜMLERÝ
Node* ataBul(Node*, Node*);  //ATA DÜÐÜM
void kardesBul(Node*, Node* ); //KARDEÞ DEÐERLER
int derinlikBul(Node*, Node*, int);//DERÝNLÝK DEÐERÝ
/*------------------------------------*/

//MAÝN FONKSÝYONU
int main() {
    // ilgili aðaç veri yapýsý oluþturulur 
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
 	// ilgili aðacýn sonu
    
    cout << "Agacin dugum sayisi: " << dugumSayisiBul(kok) << endl; // aðaçtaki düðüm sayýsýný bulan fonksiyon

    cout << "Agacin yuksekligi: " << agacYuksekligiBul(kok) << endl; // aðacýn yüksekliðini bulan fonksiyon

    cout << "Agacin kok degeri: " << kokDegeriBul(kok) << endl; // kök deðerini bulan fonksiyon

    vector<int> yaprakDegerleri; //düðümeler vektöre atanýr
    yaprakDugumleriniAl(kok, yaprakDegerleri); // fonsiyona kok deðerleri ve vektör parametre olarak aktarýlýr

    cout << "Yaprak dugumlerin degeri: ";
    for (int i = 0; i < yaprakDegerleri.size(); i++) {
        cout << yaprakDegerleri[i] << "  ";    // son node a kadar gelmiþ node deðerlerini bastýrýr(yapraklar)
    }
	cout << endl;
	cout << endl;
    
    Node* hedef = kok->right->left->right;
	Node* ata = ataBul(kok, hedef);   // 10 numaralý sayinýn bulunduðu nodun atasýnýn nodunu döndüren fonksiyon 
	if (ata != nullptr) {
	    cout << hedef->data << " nin atasi:  " << ata->data << endl;
	} else {
	    cout << hedef->data << " nin atasi yok:  " << endl;
	}
	
	Node* node = kok->left->right;   //  5 sayýsýnýn bulunduðu nodun kardeþini bulan fonksiyon
	kardesBul(kok, node);   
	
	Node* hedef2 = kok->right->left;   // 9 sayýsýnýn derinliði 
	int derinlik = derinlikBul(kok, hedef2, 0);
	cout  << hedef2->data << " nin derinligi:  " << kok->left->right->data - derinlik << endl; //derinliði bulur
}





//DÜÐÜM SAYISI
int dugumSayisiBul(Node* kok) { // node laron sað ve solundaki çocuklara gider ve varsa her düðüm için 1 ekler
    if (kok == NULL) {
        return 0;
    }
    return 1 + dugumSayisiBul(kok->left) + dugumSayisiBul(kok->right); //eklenme iþlemi için recursive func.
}
//AÐAÇ YÜKSEKLÝÐÝ
int agacYuksekligiBul(Node* kok) {
    if (kok == NULL) {
        return -1; // boþ aðacýn yüksekliði -1'dir
    }
    int sagYukseklik = agacYuksekligiBul(kok->right);
    int solYukseklik = agacYuksekligiBul(kok->left);

    return 1 + max(solYukseklik, sagYukseklik); // en  yüksek kol hangisi ise yüksekliði max(param,param)iel bulunur
}
//KÖK DEÐERi
int kokDegeriBul(Node* kok) {
    if (kok == NULL) {
        return -1; // aðaç boþ ise geçersiz deðer (-1) döndürürüz
    }
    return kok->data; // kok deðerini döndürüyor
}
//YAPRAK DÜÐÜMLERÝ
void yaprakDugumleriniAl(Node* kok, vector<int>& yaprakDegerleri) {
    if (kok == NULL) {
        return;
    }
    if (kok->left == NULL && kok->right == NULL) {
        yaprakDegerleri.push_back(kok->data);   // son node a geldiðinde durur
        return;
    }
    yaprakDugumleriniAl(kok->left, yaprakDegerleri); // soldaki node son node a kadar ilerletir
    yaprakDugumleriniAl(kok->right, yaprakDegerleri); // sað için
}

//ATA DÜÐÜM
Node* ataBul(Node* root, Node* node) {
    if (root == nullptr || root == node) {
        return nullptr;
    }
    Node* ancestor = nullptr;
    while (root != nullptr) { // kök fonksiyon var iken(aðaç var)
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
    return ancestor; // atayý döndür
}

//KARDEÞ DEÐERLER
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
//DERÝNLÝK DEÐERÝ
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



