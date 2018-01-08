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
#include <vector>
#include "stl_use.h"
using namespace std;

void stl_use::priority_queue_use(){
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

void stl_use::vector_use(){

    //test emplace

    vector<int> test1;
    vector<int> test2;

    test1.emplace_back(1);//ֱ�ӹ���
    test1.emplace_back(2);
    test1.emplace_back(3);
    test2.emplace_back(4);
    test2.emplace_back(5);
    test2.emplace_back(6);
    vector<int> res;

    //ʹ��insert������Ԫ��
    res.insert(res.end(),test1.begin(),test1.end());
    res.insert(res.end(),test2.begin(),test2.end());

    for(auto e:res){
        cout <<"emplace1 res:" << e << endl ;
    }

    res.clear();
    //emplace������Ԫ�أ�

    for(auto e:test1){
        res.emplace_back(e);
    }
    for(auto e:test2){
        res.emplace_back(e);
    }



    for(auto e:res){
        cout <<"emplace2 res:" << e << endl ;
    }

    cout << endl;







}






