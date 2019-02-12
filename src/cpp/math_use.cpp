/*
 * math_use.cpp
 *
 *  Created on: Aug 10, 2018
 *      Author: wangwei69
 *  @breif
 *  ��ѧ������صĺ���ʵ��
 *
 */

#include "com_use.h"
#include <vector>
#include <iostream>

using namespace std;

float sum_square(vector<float> &);

void math_use_test(){

    //ƽ����
    cout << "begin to cal square of vec " << endl;
    vector<float> vec = {-0.68, -0.54, -0.33, 0.16, 0.56, 0.81, -0.01, -0.21, 0.09, 0.14};
    cout << "square of vec: " << sum_square(vec) << endl;


    vector<float> vec1 = {-0.16, -0.02,0.19,-0.06,0.34,0.59,-0.23,-0.43,-0.13,-0.08};
    cout << "square of vec1: " << sum_square(vec1) << endl;


}



/*
 * ������������Ԫ�ص�ƽ���ͣ�vec ={x1��x2,...}
 *
 * sum = x1^2 + x2^2 + ...
 *
 */


float sum_square(vector<float> &vec){

    float res = 0;

    for(auto e : vec){
        res += e * e;
    }
    return res;
}



