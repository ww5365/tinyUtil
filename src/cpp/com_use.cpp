/*
 * array_use.cpp
 *
 *  Created on: Jul 4, 2018
 *      Author: wangwei69
 */

#include "com_use.h"
#include <cstddef>
#include <iterator>

extern int *g_int_ptr; //����ļ�����ģ��ڱ��ļ����������ã�

/*
 * @brief
 * 1.��ͬ�����͵�����Ķ���
 * 2.��ά����Ķ�̬�ڴ����ͻ���
 */

void array_use_test(){
    const size_t LEN = 10;
    int arr1[LEN] = {1,2,3,4,5};
    int *arr2[LEN];    //����ָ�����飺�����е�Ԫ�ض���ָ������ָ�룻
    int (*ptr)[LEN];  //��������ָ�룺ptr��ָ�룻ָ��һ����LEN������Ԫ�ص����飻
    int (&ref)[LEN] = arr1;  //������������ã� ref��һ�����ã���������LEN������Ԫ�ص����飻
    //ref = arr1;
    int *(&ref2)[LEN] = arr2; //������Ҫ��ʼ��
    int *ptr_end = &arr1[LEN];   //β��ָ�룬������̫��ȫ��c++11�ṩ�˺���
    int *ptr_head = std::begin(arr1); //����ͷָ��
    int *ptr_post_tail = std::end(arr1); //����β��ָ��

    ptrdiff_t len = ptr_post_tail - ptr_head; //���ͣ�ptrdiff_t; ����λ�ó��ȣ�


    //��ά������ڴ�Ķ�̬����ͻ���
    constexpr size_t ROW = 3;
    constexpr size_t COL = 4;

    //����
    int **arr3 = nullptr;
    arr3 = new int*[ROW];
    for (size_t i = 0;i < ROW; i++){
        arr3[i] = new int[COL];
    }
    for (size_t i = 0;i < ROW; i++){
        for(size_t j = 0;j < COL; j++){
            arr3[i][j] = i + j;

            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //����
    for (size_t i = 0;i < ROW; i++){
        delete []arr3[i];//ÿ��ָ��Ķ��л���
    }

    delete []arr3; //���ձ���������


    //ȫ�ֱ���

    g_int_ptr = arr1;

    std::cout << "global int ptr: " << std::endl;
    for (size_t i = 0; i < sizeof(arr1)/sizeof(int); i++){

        std::cout << g_int_ptr[i] << " ";
    }

    std::cout << std::endl;



}


/*
 * @brief
 * const constexpr  ����
 * constexpr ʲôʹ�ñȽϺ�?
 * ���鳤�ȣ�ö�ٳ�ʼ��
 */

struct A{
    int x,y;
    constexpr A(int xx, int yy):x(xx),y(xx){}//��ҪΪ�գ�Ҳ���Ǳ����ڳ�ʼ���б��г�ʼ����
};

constexpr A a(1,2); //�������ʽ����

enum Test{
  XX = a.x, //ֱ��ʹ�ó������ʽ
  YY = a.y
};

constexpr int LEN = 32; //������ƣ�const int LEN = 32..

void const_use_test(){

    std::bitset<LEN> bs; //bitset�ĳ����Ǳ����ڼ����Ҫ֪����
    bs.flip(9); //��10bit������ȡ��: bs.set(9,~bs[9]);
    std::cout << "the value of pos 10: " << bs[9] << std::endl;










}




void com_use_test(){


    std::cout << "begin to test com use--const use test !" << std::endl;
    const_use_test();

    std::cout << "begin to test com use--array use test !" << std::endl;

    array_use_test();


}



