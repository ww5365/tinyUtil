/*
 * thread_use_demo.h
 *
 *  Created on: May 28, 2019
 *      Author: wangwei69
 */

#ifndef SRC_INC_THREAD_USE_DEMO_H_
#define SRC_INC_THREAD_USE_DEMO_H_

#include <stdio.h>
#include <pthread.h>

void print_msg(const char* msg, int error);

/*
 * ��ʵ�ֹ��ܣ���
 *
 * 1���ඨ��Ķ�������Զ��ԣ��ٽ������м�����ͬʱ������������������������Զ������Ĺ��ܣ��Ѽӵ����ͷŵ���
 *
 */

class Lock{

public:
    Lock(){
        int ret = pthread_mutex_init(&mutex, nullptr);
        fprintf(stderr, "init mutex!ret:[%d][%s]\n", ret, strerror(ret));//��������������ظ��Ĵ���

        print_msg("mutxt_lock", pthread_mutex_lock(&mutex));
    }

    virtual ~Lock(){
        print_msg("mutex_unlock", pthread_mutex_unlock(&mutex));

        int ret = pthread_mutex_destroy(&mutex);
        fprintf(stderr, "mutex destory! ret:[%d][%s]\n", ret, strerror(ret));
    }
private:
    pthread_mutex_t mutex;
};








#endif /* SRC_INC_THREAD_USE_DEMO_H_ */
