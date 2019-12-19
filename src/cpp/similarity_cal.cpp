/*
 * similarity_cal.cpp
 *
 *  Created on: 2019��10��30��
 *      Author: wangwei69
 */
#include "com_use.h"
#include <list>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
 * �����������ϣ�jaccrd ����
 *
 * dist(A,B) = 1 - (|A �� B|/|A �� B|)
 *
 */

double jaccrd_distance(const set<string> &s1, const set<string> &s2){

    vector<string> res;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(res));

    cout << "set_intersection size: " << res.size() << endl;

    size_t intersection_size = res.size();

    res.clear();

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(res));

    size_t union_size = res.size();
    cout << "set_union size: " << res.size() << endl;

    double jaccrd_dis = 1;
    if (union_size > 0)
        jaccrd_dis = 1- (double) intersection_size/union_size;
    return jaccrd_dis;

}






void similarity_test(){


    set<string> s1;
    s1.insert("��ΰ");
    s1.insert("��");
    s1.insert("��");
    s1.insert("test");

    set<string> s2;
    s2.insert("��");
    s2.insert("��");
    s2.insert("��");
    s2.insert("��");



    double res = jaccrd_distance(s1, s2);

    cout << "jaccard_distance: " << res << endl;


}



