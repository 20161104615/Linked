#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

#define max 100

struct Referee {
	string name;
	string sex;
	string contant;
	int score;
};
typedef struct Referee r;

struct PT {
	bool Sing;
	string SingName;
	bool Dance;
	string DaneceName;
	bool Recitation;
	string RecitationName;
};
typedef struct PT p;

struct Student {
	string name;
	string sex;
	string contant;
	p pt;
	r re[max];
	int score;
};
typedef struct Student s;

struct user {
	s student[max];
	int last;
};
typedef struct user * Ptr;


void OutputInformation(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "ѧ��������" << L->student[i].name;
		cout << "ѧ���Ա�" << L->student[i].sex;
		cout << "ѧ����ϵ��ʽ��" << L->student[i].contant;
		if (L->student[i].pt.Sing == true)
			cout << "��Ŀ���ͣ�����" << "��Ŀ���ƣ�" << L->student[i].pt.SingName << endl;
		if (L->student[i].pt.Dance == true)
			cout << "��Ŀ���ͣ��赸" << "��Ŀ���ƣ�" << L->student[i].pt.DaneceName << endl;
		if (L->student[i].pt.Recitation == true)
			cout << "��Ŀ���ͣ�����" << "��Ŀ���ƣ�" << L->student[i].pt.RecitationName << endl;
	}
}

void OutputScore(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "ѧ��������" << L->student[i].name;
		cout << "ѧ���ɼ���" << L->student[i].score << endl;
	}
}


void calculation(Ptr L, int RefereeNumber) {
	int pre;
	int cur;
	int all;
	int Max;
	int Min;
	for (int i = 0; i <= L->last; i++) {
		all = 0;
		pre = 0;
		cur = 0;
		Max = 0;
		Min = 900000;
		for (int j = 0; j < RefereeNumber; j++) {
			cout << "�����" << i << "λѧ���Ĳ��гɼ���";
			cin >> L->student[i].re[j].score;
			Max = (Max > L->student[i].re[j].score) ? Max : L->student[i].re[j].score;
			Min = (Min < L->student[i].re[j].score) ? Min : L->student[i].re[j].score;
		}
		for (int z = 0; z < RefereeNumber; z++) {
			cout << z << "���гɼ���" << L->student[i].re[z].score << endl;
		}
		cout << "���ֵ��" << Max << "��Сֵ��" << Min << endl;
		for (int k = 0; k < RefereeNumber; k++) {
			all += L->student[i].re[k].score;
		}
		all = (all - Max - Min) / (RefereeNumber - 2);
		L->student[i].score = all;
	}
}

void add(Ptr L) {
	int StudentNumber;
	int RefereeNumber;
	int w;//��ӵ�λ��
	int choose;
	string name;
	string sex;
	string contant;
	cout << "�����뱨��������";
	cin >> StudentNumber;
	for (int i = 0; i < StudentNumber; i++) {
		L->last++;
		w = L->last;
		cout << "�����뱨��ѧ����Ϣ" << endl;
		cout << "������";
		cin >> L->student[w].name;
		cout << endl;
		cout << "�Ա�";
		cin >> L->student[w].sex;
		cout << endl;
		cout << "��ϵ��ʽ��";
		cin >> L->student[w].contant;
		cout << "ѡ���Ŀ���ͣ�1.���衢2.���衢3.���У���";
		cin >> choose;
		switch (choose)
		{
		case 1:
			L->student[i].pt.Sing = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[i].pt.SingName;
			break;
		case 2:
			L->student[i].pt.Dance = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[i].pt.DaneceName;
			break;
		case 3:
			L->student[i].pt.Recitation = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[i].pt.RecitationName;
			break;
		}
	}
	OutputInformation(L);
	cout << "������и�����";
	cin >> RefereeNumber;
	calculation(L, RefereeNumber);
	OutputScore(L);
}



void read(Ptr L) {

}

void save(Ptr L) {

}

void menu(Ptr L) {
	int n;
	printf("          |***********ѧ���ɼ�����ϵͳ***********|            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |               ���˵���               |            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |	  1 --- ������Ϣ.                |            \n");
	printf("          |	  2 --- ��ʾ��Ϣ.                |            \n");
	printf("          |	  3 --- ��ʾ�ɼ�.                |            \n");
	printf("          |	  4 --- �޸�����.                |            \n");
	printf("          |	  5 --- ɾ������.                |            \n");
	printf("          |	  ----------------------         |            \n");
	printf("          |	  6 --- �������ݵ��ļ�.          |            \n");
	printf("          |	  7 --- ���ļ���ȡ����.          |            \n");
	printf("          |	  8 --- ��������.                |            \n");
	printf("          |	  9 --- �˳�ϵͳ.                |            \n");
	printf("\n");

	while (1) {
		cout << "��ѡ��˵�";
		cin >> n;
		switch (n) {
		case 1:
			add(L);
			break;
		case 2:
			OutputInformation(L);
			break;
		case 3:
			OutputScore(L);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			save(L);
			break;
		case 7:
			read(L);
			break;
		case 8:

			break;
		case 9:
			return;
			break;
		}
	}
}


int main() {
	Ptr L = new user;
	L->last = -1;
	menu(L);
	delete L;
	return 0;
}