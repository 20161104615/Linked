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
		cout << "学生姓名：" << L->student[i].name;
		cout << "学生性别：" << L->student[i].sex;
		cout << "学生联系方式：" << L->student[i].contant;
		if (L->student[i].pt.Sing == true)
			cout << "节目类型：唱歌" << "节目名称：" << L->student[i].pt.SingName << endl;
		if (L->student[i].pt.Dance == true)
			cout << "节目类型：舞蹈" << "节目名称：" << L->student[i].pt.DaneceName << endl;
		if (L->student[i].pt.Recitation == true)
			cout << "节目类型：朗诵" << "节目名称：" << L->student[i].pt.RecitationName << endl;
	}
}

void OutputScore(Ptr L) {
	for (int i = 0; i <= L->last; i++) {
		cout << "学生姓名：" << L->student[i].name;
		cout << "学生成绩：" << L->student[i].score << endl;
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
			cout << "输入第" << i << "位学生的裁判成绩：";
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
	int RefereeNumber;
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
		cout << endl;
		cout << "性别：";
		cin >> L->student[w].sex;
		cout << endl;
		cout << "联系方式：";
		cin >> L->student[w].contant;
		cout << "选择节目类型（1.唱歌、2.跳舞、3.朗诵）：";
		cin >> choose;
		switch (choose)
		{
		case 1:
			L->student[i].pt.Sing = true;
			cout << "节目名称：";
			cin >> L->student[i].pt.SingName;
			break;
		case 2:
			L->student[i].pt.Dance = true;
			cout << "节目名称：";
			cin >> L->student[i].pt.DaneceName;
			break;
		case 3:
			L->student[i].pt.Recitation = true;
			cout << "节目名称：";
			cin >> L->student[i].pt.RecitationName;
			break;
		}
	}
	OutputInformation(L);
	cout << "输入裁判个数：";
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
	printf("          |***********学生成绩管理系统***********|            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |               主菜单项               |            \n");
	printf("          | ------------------------------------ |            \n");
	printf("          |	  1 --- 输入信息.                |            \n");
	printf("          |	  2 --- 显示信息.                |            \n");
	printf("          |	  3 --- 显示成绩.                |            \n");
	printf("          |	  4 --- 修改数据.                |            \n");
	printf("          |	  5 --- 删除数据.                |            \n");
	printf("          |	  ----------------------         |            \n");
	printf("          |	  6 --- 保存数据到文件.          |            \n");
	printf("          |	  7 --- 从文件读取数据.          |            \n");
	printf("          |	  8 --- 排序数据.                |            \n");
	printf("          |	  9 --- 退出系统.                |            \n");
	printf("\n");

	while (1) {
		cout << "请选择菜单";
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