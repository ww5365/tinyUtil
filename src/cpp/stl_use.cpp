/*
 * stl_use.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: wangwei69
 *
 *  ��Ҫչ��stl���и���������ʹ�÷���
 *
 */

#include <iostream>
#include "stl_use.h"

void stl_use(){

    priority_queue_use();
}



void priority_queue_use(){
    //������ʹ�����ȼ����еĳ�����ʽ
    std::priority_queue<Student,std::deque<Student>,CompareFun> qu_test;

    Student s1("wang",60);
    Student s2("wei",60);
    Student s3("song",54);
    Student s4("ni",76);
    Student s5("havy",80);

    qu_test.push(s1);
    qu_test.push(s2);
    qu_test.push(s3);
    qu_test.push(s4);
    qu_test.push(s5);

    std::cout << "score \t name " <<std::endl;

    while(!qu_test.empty()){
        std::cout << qu_test.top().get_score() << "\t"
                <<qu_test.top().get_name() <<std::endl;

        qu_test.pop();
    }

    /*
     * Ԥ�ڽ����
     *
     *
     */
}




