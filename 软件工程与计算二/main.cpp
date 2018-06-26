//
//  main.cpp
//  Text
//
//  Created by 20161104615 on 2018/6/25.
//  Copyright © 2018年 20161104615. All rights reserved.
//

#include <iostream>
#define    MAXSIZE  100
//节目类型和名称
struct PT{
    std::string Sing;//歌唱
    std::string Dance;//舞蹈
    std::string Recitation;//朗诵
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

bool add(Ptr L){
    int StuNum;//添加学生数量
    int w;
    int Program;
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
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.Sing;
                        break;
                    case 2:
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.Dance;
                        break;
                    case 3:
                        std::cout<<"请输入节目名称：";
                        std::cin>>L->student[i].pt.Recitation;
                        break;
                }
            }
        }
    }
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Ptr L = (body*)malloc(sizeof(body));
    L->last = -1;
    return 0;
}
