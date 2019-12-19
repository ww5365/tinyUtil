/*
 * design_model.h
 *
 *  Created on: May 28, 2019
 *      Author: wangwei69
 */

#ifndef SRC_INC_DESIGN_MODEL_H_
#define SRC_INC_DESIGN_MODEL_H_

#include "thread_use_demo.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class DataProcess{
private:
    vector<int> data;
public:
    void process();
};

class _Singlton{

private:
    static bool s_create;
    static _Singlton *s_instance;
    string str;
    unique_ptr<DataProcess> dp; //�����������������ݴ������(����ָ��);��ռ��ʽ��

    //copy���캯����˽�еģ����û����ඨ���⣩���ã���ͨ�û�����ʹ���ߣ�������;
    explicit _Singlton(string s = ""):str(s), dp(new DataProcess){
        cout << "constructor: " << str << endl;
    }

    //�����͸�ֵ
    _Singlton(const _Singlton &cp) = delete;
    _Singlton& operator=(const _Singlton &cp) = delete;


public:


    /*
     * ������ʽʵ�ֵ���ģʽ
     */

    //��ʽ1: c++11 ����ʵ�ַ�ʽ��static���̰߳�ȫ��
    static _Singlton& get_instance(){
        static _Singlton obj("_Singlton test"); //���ڲ���˽�й��캯���ɼ�
        return obj;
    }

    //��ʽ2�� ����: ���߳� + double chcek
    static _Singlton& get_instance2(){
        if (!s_create){
            Lock lock; //��֤���̵߳�������̰߳�ȫ
            if (!s_create){
                static _Singlton obj("_Singlton test2");
                s_instance = &obj;
            }
        }

        return *s_instance;
    }

    void data_process(){
        dp->process();
    }

};

//���о�̬��Ա������Ҫ��ʼ��
bool _Singlton::s_create = false;
_Singlton* _Singlton::s_instance = nullptr;

//��дһ��

class Singlton{
private:
    string singlton_name;
    unique_ptr<DataProcess> dp;

public:

    explicit Singlton(string str = ""): singlton_name(str), dp(new DataProcess()){

    }

    static Singlton& get_instance(){
        static Singlton  obj("singlton");
        return obj;
    }


};





#endif /* SRC_INC_DESIGN_MODEL_H_ */
