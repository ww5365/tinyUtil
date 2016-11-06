//============================================================================
// Name        : tinyUtil.cpp
// Author      : wangwei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include "cmd_option.h"
#include "com_use.h"
#include "macro_study.h"

#include <cstdlib>
#include <ctime>


using namespace std;

typedef struct test_struct{
    int a;
    char *str;
}test_struct;


#define MAMA(x)  x

#define FUN MAMA
#define QT_LEN 2

#define IP_SIZE 2

int main(int argc, char* argv[]) {

    //c������ʹ��ʱ����������

    std::cout << time(NULL)<<std::endl;

    srand((unsigned int)time(NULL));

    int ran = rand();
    int index = ran%IP_SIZE;

    std::cout << "ran: index: " <<ran <<":"<<index <<std::endl;


    //��ά�ַ������鳤��
    char *test_str[QT_LEN]={
            "qt=s",
            "qt=nb"
    };

    int qt_num = QT_LEN;

    std::cout << "test_str len: " <<qt_num <<std::endl;


    //����Ƕ�׵ĺ궨��

    std::cout << FUN("wangwei macro") <<std::endl;  //ͨ��MAMA���������滻


    //������C���Խṹ��ĸ�ֵ

    test_struct cv[]={
            {2,NULL},
            {3,NULL}
    };//ʹ�ô����Ÿ���ֵ

    std::cout << cv[0].a << std::endl;
    std::cout << cv[1].a << std::endl;


    //����

    std::string qt = "\"qt\":\"s\"";
    const char *bound = "(123,323.2211111;2121,33.33)";

    std::stringstream ss;
    ss<<"\""<<"b"<<"\""<<":"<<"\""<<bound<<"\"";

    std::string query;
    ss>>query;

    cout <<"query res: " <<query <<std::endl;


    float x1,x2,y1,y2;

    sscanf(bound,"(%f,%f;%f,%f)",&x1,&y1,&x2,&y2);

    char buf[256];
    buf[0] = '\0';

    double xx = (x1 + x2)/2;
    double yy = (y1 + y2)/2;

    snprintf(buf,256,"(%.2f,%.2f;%.2f,%.2f)",xx,yy,xx,yy);

    printf("res: %f , %f ,%f ,%f  bound:%s \n",x1,y1,x2,y2,buf);


    //cpp read write file demo

    cpp_r_w_demo();

    //test macro
    macro_study();

    //c read_write_demo
    read_write_demo();

    cout << "!!!Hello World!!!" << endl;
    cout << "args num :" << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "args:" << i << " value:" << argv[i] << endl;
    }
    cout << "finished!" << endl;
    char *p = argv[argc-1];
    cout << "argv:" << *p <<endl;

    util::CmdOption opt;

    opt.init(argc,argv,"d:c:h");

    if (opt.has_option("d")){
        cout << "d option exist" <<endl;
        cout <<"d option is: " <<opt["d"] <<endl;

    }else{
        cout << "d option not exist" <<endl;
    }

    if (opt.has_option("f")){
        cout << "f option exist" <<endl;
        cout <<"f option is: " <<opt["f"] <<endl;

    }else{
        cout << "f option not exist" <<endl;
    }



    return 0;
}
