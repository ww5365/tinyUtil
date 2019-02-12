/*
 * new_feature_c11_use.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: wangwei69
 */

#include "com_use.h"
#include <vector>

#include <iostream>


/*
 * ��ֵ���ã�
 * T &&
 * ���ã������c++Ч�����⡣�������������ʱ������
 */

struct A{
    char *x;
    int len;
    A(char *str, int b): len(b){
        x = new char[len];
        snprintf(x, 10, "%s", str);
        std::cout << "constructor!" << std::endl;
    }

    A(const A &other){
        if(this != &other){
            len = other.len;
            this->x = new char[len];
            snprintf(x, 10, "%s", other.x);
        }

        std::cout << "copy constructor!" << std::endl;
    }

    A(A &&o){
        this->x = o.x;
        len = o.len;

        std::cout << "move copy constructor"  << std::endl;

        //delete []o.x;
        //o.x = nullptr;
        //o.len = 0;
    }

};

void rvalue_referenct_use(){

    A a("wangwei", 30);

    std::vector<A> vec;
    vec.reserve(10);//Ԥ�ȷ�����ʴ�С��vector��Ҳ�����Ч�ʣ�
    vec.push_back(a);
    std::cout << "-----" << std::endl;
    vec.push_back(a);

    std::cout << "-----" << std::endl;
    vec.push_back(a);

    std::cout << "-----" << std::endl;
    vec.emplace_back(a);//a������ֵ���������Ч����push_back����

    std::cout << "a.x: " << a.x << " size: " << vec.size()<<std::endl;

    std::cout << "-----" << std::endl;
    vec.emplace_back(std::move(a));

    std::cout << "a.x: " << a.x << " size: " << vec.size() << std::endl;

    std::cout << "-----" << std::endl;


}




void new_feature_c11_use_test(){
    rvalue_referenct_use();

}
