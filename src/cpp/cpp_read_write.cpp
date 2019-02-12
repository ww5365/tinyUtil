/*
 * cpp_read_write.cpp
 *
 *  Created on: 2016��5��18��
 *      Author: wangwei69
 */

#include "com_use.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * �����ַ�����ʹ�÷ָ��������ַ���������vector��
 *
 */

std::vector<std::string> split(std::string str,std::string pattern){

    std::vector<std::string> res;

    std::string::size_type pos;
    //std::string::npos;

    str +=pattern;//������м��ɣ���֤���һ���ָ�ܱ�ȡ��

    unsigned int str_size = str.size();

    for(unsigned int i=0;i<str.size();i++){
        pos = str.find(pattern,i);  //��i��ʼ�ң��ҵ�pattern������λ�ô��±�0��ʼ��
        int find_len = 0;
        if(pos < str_size && pos != std::string::npos){  //��λ����λ��
            find_len = pos - i;
            if(find_len >0){
                std::string s = str.substr(i,find_len);  //i������ʼλ�ã���0��ʼ
                res.push_back(s);
            }
            i = pos + pattern.size() - 1;  //��һ��������ʼλ�á�Ϊʲô-1����Ϊ��һ��ѭ��i++��
        }
    }//end for

    return res;   //����һ���ֲ������� ���ԣ������ǻᷢ�������������Ƿ��и���Ч�ʵ���ƣ�
}


/*
 * ���ļ��ж�ȡ����,�ŵ��ڴ�(����)
 */
void read_file() {
    std::ifstream in;  //��������������ʱ������test.txt�ļ���Ĭ�ϵ���open������

    in.open("/Users/wangwei69/workspace/github/tiny_util/test.txt");
    if (!in.good()) {
        std::cout << "stream's state flags are set (badbit, eofbit or failbit)."
                << std::endl;
    }

    uint32_t linkid;
    std::string ebc;
    std::string tableid;
    std::string direction;
    std::string pc;
    while (true) {
        if (!in.good()) {
            //�������״̬λ���������bad��eof��fail���쳣������false��
            std::cout << "bad or end!" << std::endl;
            break;
        } else {
            std::cout << "file is good!" << std::endl;
        }

        //�������룬�Կհ׷�(tab���ո�)�ָֱ�ӽ�����������ת����
        in >> linkid >> ebc >> tableid >> direction >> pc;

        std::cout << linkid << ":" << sizeof(linkid) << ":" << ebc << ":"
                << tableid << std::endl;
    }

    if (!in.is_open()) {
        std::cout << "file not open !" << std::endl;
    }

    //C++�л�������һ����std���ֿռ��ȫ�ֺ���getline����Ϊ��������Ĳ���ʹ����string�ַ�����������������<string>ͷ�ļ����ˡ�
    std::string str;
    unsigned int line_no = 1;
    while (getline(in, str)) {  //���ļ��е�һ�ж��뵽�ַ���str
        std::cout << "line " << line_no << ": " << str << std::endl;
        std::vector<std::string> res = split(str, "\t");
        for (unsigned int i = 0; i < res.size(); i++) {
            std::cout << res[i] << " ";
        }
        std::cout << std::endl;
    }
}



/*
 * ���ڴ�(����)�����ݣ�д�뵽�ļ���
 *
 */

void write_file(){

    //���ļ���д�����ݣ������ļ������ڣ�

    std::ofstream ofs;
    ofs.open("./output.txt", std::ios::out|std::ios::app);
    std::string str1 = "wangwei test111!";

    if (ofs.good()){
        ofs << str1 <<std::endl;
        ofs.close();
    }

    ofs.open("./output.txt", std::ios::out|std::ios::app);
    std::string str2 = "wangwei test222!";

    if (ofs.good()){
        ofs << str2 <<std::endl;
        ofs.close();
    }

    std::cout << "this is write file test!" << std::endl;


}


void cpp_r_w_demo(){

    write_file();//�ļ�д�����

}


