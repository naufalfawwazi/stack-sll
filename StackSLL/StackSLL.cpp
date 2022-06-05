#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	char nama[30];
	Node *next;
};

Node *head = NULL, *tail = NULL;
int count = 0, maxstack = 5;

void push() {
	if(count == maxstack)
		cout<<"gagal push, stack penuh!\n";
	else {
		char namabuku[30];
		cout<<"Nama Buku : "; cin>>namabuku;
		Node *baru = new Node;
		strcpy(baru->nama, namabuku);
		
		if(head == NULL) {
			baru->next = NULL;
			head = baru;
			tail = baru;
		} else {
			baru->next = NULL;
			tail->next = baru;
			tail = baru;
		} 
		cout<<"berhasil push "<<namabuku<<endl;
		++(count);
	}
}

void pop() {
	if(head == NULL)
		cout<<"gagal pop, stack kosong\n";
	else {
		cout<<"berhasil pop "<<tail->nama<<endl;
		if(head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		} else {
			Node *bantu = head;
			while(bantu->next != tail) {
				bantu = bantu->next;
			}
			bantu->next = NULL;
			delete tail;
			tail = bantu;
		} --(count);
	}
}

void print() {
	Node *bantu = head;
	while(bantu!=NULL) {
		cout<<bantu->nama<<endl;
		bantu = bantu->next;
	}
}

int main() {
	int pilih;
	do {
		cout<<"Operasi - operasi Stack :\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Keluar\n";
		cout<<"4. Print\n";
		cout<<"Pilih operasi : "; cin>>pilih;
		
		if(pilih==1) push();
		if(pilih==2) pop();
		if(pilih==4) print();
	
	} while(pilih!=3);

	return 0;
}
