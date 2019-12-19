/*
 * thread_use_demo.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: wangwei69
 */

#include "com_use.h"
#include "thread_use_demo.h"
#include <pthread.h>
#include <iostream>

#include <unistd.h>
#include <utility>
#include <functional>


using namespace std;


void print_msg(const char* msg, int error){

    fprintf(stderr, "error msg: [%d][%s][%s]\n", error, strerror(error), msg);
}

void* thread_stub(void *args){

    pthread_detach(pthread_self());//��stub��detach���̣߳��������̲߳�����������ʹ�ٵ�joinҲ������Ч�����̼߳���ִ�У�
    //cout << "this is thread num: " << *(int*)args <<endl;

    int pa = *(int*)args;
    while(1){
        //cout << "thread num: " << *(int*)args << endl; //�����⣬����ƽ�Ⱥ����ȫ��Ϊ��thread num : 2 ?����Ϊʲô����Ϊ �������в���i��Ϊ2��*(int*)args�൱�����÷�ʽʹ�ð���
        cout << "this is thread num: " << pa << endl;
        usleep(1000000);
    }
    return nullptr;
}

void* thread_stub2(void* args){
    cout << "this is thread2!!" << endl;
    while(true){
    }
}

class CallBackHandle{
public:
    //typedef int(*CallBackFun)(string &name);

    typedef function <int(string)> CallBackFun;  //�ص�����������ָ������

    CallBackHandle(CallBackFun f, string name):_fun(f), _name(name){}
    ~CallBackHandle(){}

    bool run(){

        cout << "call back handle invoke function!" << endl;
        _fun(_name);
        return true;
    }

private:
    CallBackFun _fun;
    string _name;
};


class Process{
private:
    string _name;
    int _id;

public:
    Process(string name = " ", int id  = 0):_name(name), _id(id){}

    int handle(string name, int seqid){
        cout << "invoke function name: " << name << " seqid: " << seqid << endl;
        return _id;
    }

};


static void* stub3(void* args){

    CallBackHandle* handle = reinterpret_cast<CallBackHandle*>(args);

    handle->run();

    return (void*)nullptr;

}


/*
 * �̳߳صļ���ƺ�ʵ�֣���
 *
 * �ο���sudata ������SimpleThreadPool��ƺ�ʵ�֡���
 *
 *
 *
 */









/*
 * 1���Ȳ�����β������߳�������
 *
 */

void thread_use_test(){

    //��֤�Զ�������������

    {
        Lock lock_obj;
    }

    //ֻ������������
    return ;

    /*
     * ��֤�����̴߳����߳���detach��������ʹjoin��Ҳ�����������̵߳����У�
     */

    //����2���߳�
    static const int THREAD_NUM = 2;
    pthread_t *tid;//�߳�id������
    tid = (pthread_t*)malloc(sizeof(pthread_t) * THREAD_NUM);//�����߳�id����ռ�
    for(int i = 0;i < THREAD_NUM;i++){
        //pthread_create����ȫ����ָ��
        pthread_create(&tid[i],NULL,thread_stub,(void*)(&i));
        usleep(1000);
    }
    sleep(1);
    cout << "this is main thread, over create stub1!" << endl;

    //pthread_exit(NULL);
    pthread_t tid2;
    pthread_create(&tid2, NULL, thread_stub2, NULL);

    for (int i = 0; i < THREAD_NUM; i++){
        pthread_join(tid[i],NULL); //��Ϊ�����߳����Ѿ�detach�ˣ��������Ｔʹjoin��Ҳ�������������߳���
    }

    //pthread_join(tid2, NULL); //���������߳���; ������ﲻ���������̻߳����ִ�У���������
    cout << "this is main thread222!" << endl;


    /*
     * ��֤����Ʒ�ʽ�� callbackhandle����ָ����Ϊ���������ݸ�׮����,ʵ��ʹ�ö����ж���ĺ���run��
     *               ͬʱ�ڣ����߳���ʵ�ֶ�callbackhandle�����á�
     *               ��Ҫ��Ŀ���ǣ�ͨ�������ص����ƣ���ʹ���Զ���ĺ���;
     *
     */


    int seqid = 1;
    Process pro("test", seqid);
    CallBackHandle::CallBackFun fun = std::bind(&Process::handle, &pro,std::placeholders::_1, seqid); //fun(str) <=> pro.handle(str,seqid)

    //ʹ���Զ���Ļص���������������
    CallBackHandle cbh(fun, "Process::handle"); //ͨ��handler���������˻ص�������Ҳ���ǰѻص�������װ��һ������������
    pthread_t tid3;
    pthread_create(&tid3, nullptr, stub3, &cbh); //��cbh��Ϊ����������׮�����У�׮����ͨ��cbh�����ûص�������




}



