/*
 * cmdOption.cpp
 *
 *  Created on: 2016��2��19��
 *      Author: wangwei69
 */

#include "cmd_option.h"
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

namespace util{

    CmdOption::CmdOption(){
    }

    CmdOption::~CmdOption(){
    }

    int CmdOption::set_opt_string(const char *optstr){

        int ret = 0;
        const char *pre = NULL;
        memset(_ch,0,sizeof(_ch));
        const char *p=optstr;

        while (*p!='\0'){
            if (*p == ':'){  //֮ǰ���ַ�ѡ��ض���һ������
                if (_ch[(unsigned int)(*pre)]==0 || _ch[(unsigned char)(*pre)]==3){
                    std::cout<< "option error" << std::endl;
                    ret = -1;
                    break;
                }
                _ch[(unsigned int)(*pre)]++;  //��һ������ֵ��2 û�в���ֵ��1
            }else{
                if(_ch[(unsigned int)(*p)] == 1){
                    ret = -1;
                    break;
                }
                _ch[(unsigned int)(*p)] =1;
            }
            pre = p;
            p++;
        }
        return ret;
    }


    int CmdOption::init(int argc, char * const *argv, const char *optstr){
        if (argv==NULL || optstr==NULL){
            cout << "argv or optstring null" << endl;
            return -1;
        }

        if (set_opt_string(optstr) != 0){
            cout <<"optstr set error" <<endl;
            return -1;
        }

        stack<char *> st;

        for (int i=argc-1;i>0;i--){
            char *p= argv[i];
            string key,value;

            if (*p == '-'){
                if (*(p+1) == '-'){  //��ѡ��ģʽ --c=./conf  --h
                    string tmp(p+2);
                    cout << "tmp string: " <<tmp<<endl;
                    key = tmp.substr(0,1);
                    unsigned int pos = tmp.find("=");
                    if(_ch[(unsigned int)(*(p+2))] == 1){//ѡ��û�в���
                        value =  "true";
                    }else if (_ch[(unsigned int)(*(p+2))] == 2){ //ѡ����Ҫ�в���
                        if(pos == string::npos || pos == (tmp.length()-1)){
                            cout <<"args error:" <<p <<endl;
                            continue;
                        }
                        value = tmp.substr(pos+1);
                        cout<<"key:value: " <<key <<"\t"<< value <<endl;
                    }else{  //optstr û�д�ѡ����������
                        cout <<"option error:" <<key <<endl;
                        continue;
                    }
                    _args.insert(pair<string,string>(key,value));
                }else{              //ģʽ�� -c ./conf/
                    key = *(p+1); //�ַ�����string
                    if (_ch[(unsigned int)(*(p+1))] == 2){//ѡ���в�����

                        if(st.empty()){ //ջ��û�в����ʹ�ѡ��ƥ��
                            cout <<"option's args not exist :" <<key <<endl;
                            continue;
                        }
                        value = st.top(); //�ַ�������string
                        st.pop();
                    }else if (_ch[(unsigned int)(*(p+1))] == 1){
                        value = "true";
                    }else {
                        cout <<"option error:" <<key <<endl;
                        continue;
                    }
                    cout<<"key2:value: " <<key <<"\t"<< value <<endl;
                    _args.insert(pair<string,string>(key,value));
                }

            }else{
                st.push(p);
            }
        }
        return 0;
    }

    bool CmdOption::has_option(const char *option) const{
        string key = option;
        return(_args.find(key) != _args.end());
    }

    const char* CmdOption::operator[](const char *key) const{
        std::multimap<std::string,std::string>::const_iterator it = this->_args.find(key);
        if (it != this->_args.end())
            return (it->second).c_str();
        return NULL;
    }


}


