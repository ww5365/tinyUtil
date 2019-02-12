/*
 * thread_use_demo.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: wangwei69
 */

#include "com_use.h"
#include <pthread.h>
#include <iostream>

#include <unistd.h>

using namespace std;

void* thread_stub(void *args){

    pthread_detach(pthread_self());//��stub��detach���̣߳��������̲߳�����������ʹ�ٵ�joinҲ������Ч�����̼߳���ִ�У�
    cout << "this is thread num: " << *(int*)args <<endl;
    while(1){

    }
    return nullptr;

}

void* thread_stub2(void* args){


    cout << "this is thread2!!" << endl;

    while(true){

    }
}


/*
 * 1���̼߳�Ļ�����ͬ����
 *    ����Ӧ�ã�˫buffer���ȼ������ݣ�
 *
 */


/*
 * 1�����Դ����߳�
 * 2���̼߳以�����
 */

void thread_use_test(){

    //����10���߳�
    pthread_t *tid;//�߳�id������
    tid = (pthread_t*)malloc(sizeof(pthread_t)*10);//�����߳�id����ռ�
    for(int i = 0;i < 10;i++){
        //pthread_create����ȫ����ָ��
        pthread_create(&tid[i],NULL,thread_stub,(void*)(&i));

        usleep(1000);
    }


    sleep(1);
    cout << "this is main thread111!" << endl;

    //pthread_exit(NULL);

    pthread_t tid2;
    pthread_create(&tid2, NULL, thread_stub2, NULL);

    for (int i = 0; i < 10; i++){
        pthread_join(tid[i],NULL); //��Ϊ�����߳����Ѿ�detach�ˣ��������Ｔʹjoin��Ҳ�������������߳���
    }

    //pthread_join(tid2, NULL); //���������߳�������

    cout << "this is main thread222!" << endl;




}



