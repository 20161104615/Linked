//
//  main.cpp
//  Text
//
//  Created by 20161104615 on 2018/6/25.
//  Copyright © 2018年 20161104615. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define    MAXSIZE  100
//节目类型和名称
struct PT{
    std::string Sing;//歌唱
    std::string SingName;
    std::string Dance;//舞蹈
    std::string DanceName;
    std::string Recitation;//朗诵
    std::string RecitationName;
};

//裁判
struct Referee{
    std::string name;//裁判姓名
    std::string sex;//裁判性别
    std::string contant;//裁判联系方式
};

//学生
struct Student{
    std::string name;//学生姓名
    std::string sex;//学生性别
    std::string contant;//学生联系方式
    PT pt;//节目类型
    Referee referee[MAXSIZE];//裁判
};

//实现体
typedef struct body * Ptr;//指向实现体结构体的指针
struct body{
    Student student[MAXSIZE];
    int last;//指向最后一个学生
};
typedef Ptr position;


void save(Ptr L){
    FILE *fp;
    fp = fopen("//Users//a20161104615//Desktop//Test//Text//Text.txt", "w+");
    if (fp == NULL){
        printf("Error");
    }
    for (int i=0; i<L->last;i++){
        fprintf(fp,"%s",L->student[i].name.c_str());
        fprintf(fp,"%s",L->student[i].sex.c_str());
        fprintf(fp,"%s",L->student[i].contant.c_str());
        if (L->student[i].pt.Sing != ""){
            fprintf(fp,"Sing:%s\n",L->student[i].pt.SingName.c_str());
        } else if (L->student[i].pt.Dance != ""){
            fprintf(fp,"Dance:%s\n",L->student[i].pt.DanceName.c_str());
        } else if (L->student[i].pt.Recitation != ""){
            fprintf(fp,"Recitation:%s\n",L->student[i].pt.RecitationName.c_str());
        }
    }
    fclose(fp);
}


bool add(Ptr L){
    int StuNum;//添加学生数量
    int w;
    int Program;
    int choose;
    if (MAXSIZE <= L->last){
        std::cout<<"以达到报名人数限制！";
        return false;
    } else{
        std::cout<<"请输入报名人数：";
        std::cin>>StuNum;
        if ((L->last+StuNum)<MAXSIZE){
            std::cout<<"请输入报名信息：\n";
            for (int i=0;i<StuNum;i++){
                L->last++;
                w = L->last;
                std::cout<<"请输入学生姓名：";
                std::cin>>L->student[i].name;
                std::cout<<"请输入学生性别：";
                std::cin>>L->student[i].sex;
                std::cout<<"请输入学生联系方式：";
                std::cin>>L->student[i].contant;
                std::cout<<"请输入学生报名节目类型(1：歌唱、2：舞蹈、3：朗诵)：";
                std::cin>>Program;
                switch (Program) {
                    case 1:
                        L->student[i].pt.Sing = "yes";
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.SingName;
                        break;
                    case 2:
                        L->student[i].pt.Dance = "yes";
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.DanceName;
                        break;
                    case 3:
                        L->student[i].pt.Recitation = "yes";
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.RecitationName;
                        break;
                }
            }
            
            for (int j=0;j<StuNum;j++){
                std::cout<<"学生姓名："<<L->student[j].name.c_str()<<std::endl;
                std::cout<<"学生性别："<<L->student[j].sex.c_str()<<std::endl;
                std::cout<<"学生联系方式："<<L->student[j].contant.c_str()<<std::endl;
                if (L->student[j].pt.Sing != ""){
                    std::cout<<"节目类型：唱歌"<<std::endl;
                    std::cout<<"学生节目名称："<<L->student[j].pt.SingName.c_str()<<std::endl;
                } else if (L->student[j].pt.Dance != ""){
                    std::cout<<"节目类型：舞蹈"<<std::endl;
                    std::cout<<"学生节目名称："<<L->student[j].pt.DanceName.c_str()<<std::endl;
                } else if (L->student[j].pt.Recitation != ""){
                    std::cout<<"节目类型：朗诵"<<std::endl;
                    std::cout<<"学生节目名称："<<L->student[j].pt.RecitationName.c_str()<<std::endl;
                }
            }
            std::cout<<"是否要保存记录：(1：保存、2:不保存)";
            std::cin>>choose;
            switch (choose) {
                case 1:
                    save(L);
                    break;
                case 2:
                    break;
            }
        }
        return true;
    }
}

void read(Ptr L){
    FILE *f,*p,*q;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Ptr L = (body*)malloc(sizeof(body));
    L->last = -1;
    add(L);
    return 0;
}
