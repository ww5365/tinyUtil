/*
 * study_case.cpp
 *
 *  Created on: 2016��3��23��
 *      Author: wangwei69
 */


#include "macro_study.h"
#include <cmath>
#include <cstdint>
#include <iostream>
using namespace std;
void macro_study(){

    //�ɱ�����ĺ궨��
//    LOG("this is a test macro\n");
    int t = 10 ;

    LOG("this is another test macro:%d\n",t);
    LOG("this is another test macro:%d,%d\n",t, 30)

    FACTORY(te, st);


    uint32_t prefix = (1 << 10);

    if (BIT_TST(prefix, 10) == 1){
        cout << "bit_tst res: " << prefix << " : " << BIT_TST(prefix, 10) << endl;
    }



}


