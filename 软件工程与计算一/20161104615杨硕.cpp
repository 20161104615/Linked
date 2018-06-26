#include "string"
#include"iostream"
using namespace std;
struct student
{
	char name[50];
	char num[12];
	int age;
	struct student *next;
};

int main()
{
	struct student *p,*q,*head;
	string s;
	head=new student;
	q=head;
	p=q;
	cin>>p->name;
	cin>>p->num;
	cin>>p->age;
	while(cout<<"是否新增学生信息？Yes or No:",cin>>s,(s=="Yes")||(s=="y")||(s=="Y")||(s=="yes"))
	{
		p=new student;
		q->next=p;
		q=p;
		cin>>p->name;
		cin>>p->num;
		cin>>p->age;
		p->next=NULL;
	}
	p=head;
	while(p!=NULL)
	{
		cout<<p->num<<" "<<p->name<<" "<<p->age<<endl;
		p=p->next;
	}
	do
	{
		q=p->next;
		delete p;
		p=q;
	}while(q);
	return 0;
}


