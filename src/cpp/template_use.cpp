/*
 * template_use.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: wangwei69
 */

#include "com_use.h"

#include <string>
#include <iostream>

using namespace std;

/*
 * 1����ͨ���࣬���Ա�����Ƿ����Ϊģ�庯����ok
 *
 */
class Frame{

public:
    Frame():str(""){
    }
    //ģ���Ա����
    template<typename Type>
    void get_type_len(){
        Type test;
        cout << "sizeof Type: " << sizeof(test) << endl;
    }
private:
    string str;
};


void template_use_test(){

    Frame fr;

    //����ģ���Ա����
    fr.get_type_len<int>();

}



