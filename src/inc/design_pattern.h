/*
 * design_pattern.h
 *
 *  Created on: Mar 10, 2019
 *      Author: wangwei69
 */

#ifndef SRC_INC_DESIGN_PATTERN_H_
#define SRC_INC_DESIGN_PATTERN_H_

#include <iostream>
using namespace std;



//��֤һ�µ�������е����ʵ�



class SingltonMgr{
public:
    SingltonMgr(){}
    ~SingltonMgr(){}
private:
    int num = 0;
};


class Singlton{

private:
    SingltonMgr mgr;
    static int objNum;
    Singlton(){cout << "objNum: " << objNum << endl; objNum++;};
    ~Singlton(){};
    Singlton(const Singlton&) = delete;
    Singlton& operator= (const Singlton&) = delete;

public:

    static void printTest(){
        cout << "class Singlton function: " << objNum<< endl;
    }

    static Singlton& instance(){
        static Singlton sgl;
        return sgl;
        //������Ʒ�ʽ���᲻��ÿ�ε���instance,��������һ��sgl�Ķ���
        // ����:���ᣬÿ�ε���instance����ͬһ����̬�ֲ�����sgl,����������һ������
    }

};









#endif /* SRC_INC_DESIGN_PATTERN_H_ */
