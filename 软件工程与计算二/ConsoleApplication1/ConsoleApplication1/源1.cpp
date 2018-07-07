#include "stdafx.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

#define max 100

struct Referee {
	string name;
	string sex;
	string contant;
	double score;
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
	double score;
};
typedef struct Student s;

struct user {
	s student[max];
	int last;
};
typedef struct user * Ptr;


void OutputInformation(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "ѧ��������" << L->student[i].name << " ";
		cout << " ѧ���Ա�" << L->student[i].sex << " ";
		cout << " ѧ����ϵ��ʽ��" << L->student[i].contant << " ";
		if (L->student[i].pt.Sing == true) {
			cout << " ��Ŀ���ͣ����� " << " ��Ŀ���ƣ�" << L->student[i].pt.SingName << endl;
		}
		else if (L->student[i].pt.Dance == true) {
			cout << " ��Ŀ���ͣ��赸 " << " ��Ŀ���ƣ�" << L->student[i].pt.DaneceName << endl;
		}
		else if (L->student[i].pt.Recitation == true) {
			cout << " ��Ŀ���ͣ����� " << " ��Ŀ���ƣ�" << L->student[i].pt.RecitationName << endl;
		}
		cout << endl;
	}
	return;
}

void OutputScore(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "ѧ��������" << L->student[i].name;
		cout << "ѧ���ɼ���" << L->student[i].score << endl;
	}
}

void calculation(Ptr L) {
	int pre;
	int cur;
	int RefereeNumber;
	double all;
	double Max;
	double Min;
	
	cout << "��Ϊ����ѡ�ִ��\n";
	for (int i = 0; i <= L->last; i++) {
		all = 0;
		pre = 0;
		cur = 0;
		Max = 0;
		Min = 900000;
		RefereeNumber = 0;
		cout << "��������ί������";
		cin >> RefereeNumber;
		for (int j = 0; j < RefereeNumber; j++) {
			cout << "�����" << i + 1 << "λѧ���Ĳ��гɼ���";
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
		cout << "�Ա�";
		cin >> L->student[w].sex;
		cout << "��ϵ��ʽ��";
		cin >> L->student[w].contant;
		cout << "ѡ���Ŀ���ͣ�1.���衢2.���衢3.���У���";
		cin >> choose;
		switch (choose)
		{
		case 1:
			L->student[w].pt.Sing = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[w].pt.SingName;
			break;
		case 2:
			L->student[w].pt.Dance = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[w].pt.DaneceName;
			break;
		case 3:
			L->student[w].pt.Recitation = true;
			cout << "��Ŀ���ƣ�";
			cin >> L->student[w].pt.RecitationName;
			break;
		}
		L->student[w].score = 0;
	}
}

void read(Ptr L) {
	int i = 0;
	int j = 0;
	double b;
	int num = 0;//��¼�����м�������
	string a[100][6];
	string line, form, s;
	ifstream Tinfile("E:\\��ѧ\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::in);
	if (Tinfile.fail()) {
		cout << "Cannot open file." << endl;
		return;
	}

	while (getline(Tinfile, form)) {
		num++;
	}
	//cout << "csv����" << num - 1 << "������" << endl;
	Tinfile.close();

	ifstream infile("E:\\��ѧ\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::in);

	for (i = 0; i < num; i++) {
		for (j = 0; j < 6; j++) {
			getline(infile, line, ',');
			a[i][j] = line;
		}
	}
	/*for (i = 0; i < num - 1; i++) {
		for (j = 0; j < 6; j++) {
			cout << a[i][j] << "(" << i << "," << j << ")";
		}
		cout << endl;
	}*/
	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < 6; j++) {
			L->student[i].name = a[i][j];
			j++;
			L->student[i].sex = a[i][j];
			j++;
			L->student[i].contant = a[i][j];
			j++;
			if (a[i][j] == "Sing") {
				L->student[i].pt.Sing = true;
				j++;
				L->student[i].pt.SingName = a[i][j];

			}
			if (a[i][j] == "Dance") {
				L->student[i].pt.Dance = true;
				j++;
				L->student[i].pt.DaneceName = a[i][j];

			}
			if (a[i][j] == "Recitation") {
				L->student[i].pt.Recitation = true;
				j++;
				L->student[i].pt.RecitationName = a[i][j];
			}
			j++;
			s = a[i][j];
			b = atof(s.c_str());
			L->student[i].score = b;
		}
	}
	L->last = num - 2;
	cout << endl;
	infile.close();
}

void save(Ptr L) {
	string s;
	ofstream openfile("E:\\��ѧ\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::app);
	for (int i = 0; i <= L->last; i++) {
		openfile << L->student[i].name << "," << L->student[i].sex << "," << L->student[i].contant << ",";
		if (L->student[i].pt.Sing == true)
			openfile << "Sing" << "," << L->student[i].pt.SingName << ",";
		if (L->student[i].pt.Dance == true)
			openfile << "Dance" << "," << L->student[i].pt.DaneceName << ",";
		if (L->student[i].pt.Recitation == true)
			openfile << "Recitation" << "," << L->student[i].pt.RecitationName << ",";
		s = to_string(L->student[i].score);
		openfile << s << "," << "\n";
	}
	openfile.close();
}

void sort(Ptr L) {

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
	printf("          |	  4 --- ��ί���.                |            \n");
	printf("          |	  ----------------------         |            \n");
	printf("          |	  5 --- �������ݵ��ļ�.          |            \n");
	printf("          |	  6 --- ���ļ���ȡ����.          |            \n");
	printf("          |	  7 --- ��������.                |            \n");
	printf("          |	  0 --- �˳�ϵͳ.                |            \n");
	printf("\n");

	while (1) {
		cout << "��ѡ��˵�:\n";
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
			calculation(L);
			break;
		case 5:
			save(L);
			break;
		case 6:
			read(L);
			break;
		case 7:
			sort(L);
			break;
		case 0:
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