#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
struct book {  string bookname; };
struct student { string studentname; };
static int bookamount = 0;
static int studentamount = 0;
string input;

struct book list[999];
struct student studentcar[999];
////////////////������д 
void checkout() {
	int flag = 1;
	cout << "�������鱾����: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
		if (list[i].bookname == input) { 
		 cout << "�ҵ����顣\n"; 
		 flag = 0;
		 }
	if (flag == 1) cout << "���鲻���ڡ�\n"; 
}  
void giveback() {
	int flag = 1;
	struct student temp;
cout << "�������鱾����: ";
cin >> input;
bookamount++;
list[bookamount].bookname = input;
cout << "�����뻹���˵�����: ";
cin >> input;
for (int i = 1; i <= studentamount; i++) 
if (studentcar[i].studentname == input) {
	temp = studentcar[i];
	studentcar[i] = studentcar[studentamount];
	studentcar[studentamount] = temp;
	studentcar[studentamount].studentname = "";
	flag = 0;
	studentamount--;
}
if (flag == 0) cout << "���ѹ黹���顣\n";
}
int borrow() {
	int flag = 1;
	struct book temp;
	if (bookamount == 0) { cout << "����Ŀ�ɽ裡\n"; return 0;}
	cout << "�������鱾����: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
     	if (list[i].bookname == input) {
			temp = list[i];
			list[i] = list[bookamount];
			list[bookamount] = temp;
			list[bookamount].bookname = "";
			flag = 0;
			studentamount++;
			cout << "����������˵�����: ";
			cin >> input;
			studentcar[studentamount].studentname = input;
		}
		if (flag == 0) cout << "����ɹ���\n";
		else cout << "�Ҳ������顣\n";
}
void add() {
		bookamount++;
	cout << "�������鱾����: ";
	cin >> list[bookamount].bookname;
	cout << "�����鱾�ɹ���\n";
}
int cancel() { 
	struct book temp;
	int flag = 1;
	if (bookamount == 0) { cout << "����Ŀ��ɾ��\n"; return 0;}
	cout << "�������鱾����: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
		if ( list[i].bookname == input) {
			temp = list[i];
			list[i] = list[bookamount];
			list[bookamount] = temp;
			list[bookamount].bookname = "";
			flag = 0;
		}
		if (flag == 0) cout << "������ɾ����\n";
		else cout << "�Ҳ������顣\n";
	bookamount--;
	return 0;
}
////////////////������д 
int main() {
	cout << "��ӭʹ��ͼ�����ϵͳ.\n";
	int a = 0; 
while(1) {
	cout << "�����鱾�밴1��ɾ���밴2�������밴3���黹�밴4�� �����밴5�� �˳��밴6��" << endl;
	cin >> a;
	if (6 == a) break;
	if (5 == a) checkout();
	if (a == 4) giveback();
    if (a == 3) borrow();
    if (a == 2) cancel();
    if (a == 1) add();
}
cout << "��л����ʹ�ã��ټ���";
	return 0;
}
