/*
 * mem_use.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: wangwei69
 *  @brief ���������ڴ�ʹ�õĹ���
 */

#include "com_use.h"
#include <string>
#include <map>


/*
 * ����ͷ������У�new���������ݣ�
 */

void del_new_data_container(){

    std::map<int, std::string*> map_test;
    std::string *str = new std::string("wang");
    map_test.insert(std::make_pair(1,str));

    //����ͷ�strָ��




}

void mem_use_test(){



}










