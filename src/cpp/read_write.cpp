/*
 * read_write.cpp
 *
 *  Created on: 2016��3��23��
 *      Author: wangwei69
 */

#include<stdio.h>
#include "com_use.h"
void read_write_demo(){

    //sscanf�����ʽ���������ַ�����������
    const char *geo = "(123.22,456.33;234.11,567.22)";
    double x1=0,y1=0,x2=0,y2=0;
    sscanf(geo,"(%lf,%lf;%lf,%lf)",&x1,&y1,&x2,&y2);  //�������磺(1,2;1,2)  �����������ַ�����������
    printf("geo str: %s\n",geo);
    printf("the res is: %f,%f,%f,%f \n",x1,y1,x2,y2);

}



