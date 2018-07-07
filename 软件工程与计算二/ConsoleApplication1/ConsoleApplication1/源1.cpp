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
		cout << "学生姓名：" << L->student[i].name << " ";
		cout << " 学生性别：" << L->student[i].sex << " ";
		cout << " 学生联系方式：" << L->student[i].contant << " ";
		if (L->student[i].pt.Sing == true) {
			cout << " 节目类型：唱歌 " << " 节目名称：" << L->student[i].pt.SingName << endl;
		}
		else if (L->student[i].pt.Dance == true) {
			cout << " 节目类型：舞蹈 " << " 节目名称：" << L->student[i].pt.DaneceName << endl;
		}
		else if (L->student[i].pt.Recitation == true) {
			cout << " 节目类型：朗诵 " << " 节目名称：" << L->student[i].pt.RecitationName << endl;
		}
		cout << endl;
	}
	return;
}

void OutputScore(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "学生姓名：" << L->student[i].name;
		cout << "学生成绩：" << L->student[i].score << endl;
	}
}

void calculation(Ptr L) {
	int pre;
	int cur;
	int RefereeNumber;
	double all;
	double Max;
	double Min;
	
	cout << "请为所有选手打分\n";
	for (int i = 0; i <= L->last; i++) {
		all = 0;
		pre = 0;
		cur = 0;
		Max = 0;
		Min = 900000;
		RefereeNumber = 0;
		cout << "请输入评委个数：";
		cin >> RefereeNumber;
		for (int j = 0; j < RefereeNumber; j++) {
			cout << "输入第" << i + 1 << "位学生的裁判成绩：";
			cin >> L->student[i].re[j].score;
			Max = (Max > L->student[i].re[j].score) ? Max : L->student[i].re[j].score;
			Min = (Min < L->student[i].re[j].score) ? Min : L->student[i].re[j].score;
		}
		for (int z = 0; z < RefereeNumber; z++) {
			cout << z << "裁判成绩：" << L->student[i].re[z].score << endl;
		}
		cout << "最大值：" << Max << "最小值：" << Min << endl;
		for (int k = 0; k < RefereeNumber; k++) {
			all += L->student[i].re[k].score;
		}
		all = (all - Max - Min) / (RefereeNumber - 2);
		L->student[i].score = all;
	}
}

void add(Ptr L) {
	int StudentNumber;
	int w;//添加的位置
	int choose;
	string name;
	string sex;
	string contant;
	cout << "请输入报名人数：";
	cin >> StudentNumber;
	for (int i = 0; i < StudentNumber; i++) {
		L->last++;
		w = L->last;
		cout << "请输入报名学生信息" << endl;
		cout << "姓名：";
		cin >> L->student[w].name;
		cout << "性别：";
		cin >> L->student[w].sex;
		cout << "联系方式：";
		cin >> L->student[w].contant;
		cout << "选择节目类型（1.唱歌、2.跳舞、3.朗诵）：";
		cin >> choose;
		switch (choose)
		{
		case 1:
			L->student[w].pt.Sing = true;
			cout << "节目名称：";
			cin >> L->student[w].pt.SingName;
			break;
		case 2:
			L->student[w].pt.Dance = true;
			cout << "节目名称：";
			cin >> L->student[w].pt.DaneceName;
			break;
		case 3:
			L->student[w].pt.Recitation = true;
			cout << "节目名称：";
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
	int num = 0;//记录表中有几行数据
	string a[100][6];
	string line, form, s;
	ifstream Tinfile("E:\\大学\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::in);
	if (Tinfile.fail()) {
		cout << "Cannot open file." << endl;
		return;
	}

	while (getline(Tinfile, form)) {
		num++;
	}
	//cout << "csv中有" << num - 1 << "行数据" << endl;
	Tinfile.close();

	ifstream infile("E:\\大学\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::in);

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
	ofstream openfile("E:\\大学\\visualstudio_c++\\ConsoleApplication1\\Test.csv", ios::app);
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
	printf("          |***********学生成绩管理系统***********|            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |               主菜单项               |            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |	  1 --- 输入信息.                |            \n");
	printf("          |	  2 --- 显示信息.                |            \n");
	printf("          |	  3 --- 显示成绩.                |            \n");
	printf("          |	  4 --- 评委打分.                |            \n");
	printf("          |	  ----------------------         |            \n");
	printf("          |	  5 --- 保存数据到文件.          |            \n");
	printf("          |	  6 --- 从文件读取数据.          |            \n");
	printf("          |	  7 --- 排序数据.                |            \n");
	printf("          |	  0 --- 退出系统.                |            \n");
	printf("\n");

	while (1) {
		cout << "请选择菜单:\n";
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