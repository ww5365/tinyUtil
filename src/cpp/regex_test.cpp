/*
 * regex_test.cpp
 *
 *  Created on: 2019��12��18��
 *      Author: wangwei69
 */

#include "com_use.h"

#include <regex>
#include <string>
#include <vector>

using namespace std;



/*
 * @�ַ�����ģʽƥ��
 * std::regex  pattern("ģʽ�Ӵ���", std::regex_constraints::icase);  //ģʽ�����Ժ��Դ�Сд
 *
 * std::regex_match(str, pattern);  //str�Ƿ����ģʽƥ�� pattern������ true/false;
 *
 */

void string_match_way(){

    std::vector<string> test;
    test.push_back("bei hai1");
    test.push_back("beijing university");
    test.push_back("beijing����");
    std::regex pattern("beijing.*");//.ƥ�������ַ���*ƥ��֮ǰ���ֵ�>=0���ַ�
    std::regex pattern2("[A-Za-z0-9 ]+");//��ĸ�����֣��ո�
    for (auto it = test.begin();it != test.end(); it++){

        if (std::regex_match(*it, pattern)){//����1��Ҫƥ����ַ��� ����2��ͨ��ģʽ
            std::cout << "match pattern: " << *it << std::endl;
        }
        if (std::regex_match(*it, pattern2)){
            std::cout << "match pattern2: " << *it << std::endl;
        }
        //ģʽƥ��ɹ�����ƥ��ɹ����ַ���ȫ���滻��replace���������´�;δ�ɹ���ֱ�ӷ��ش�ƥ����ַ�����
        std::string replace_str = "good person";
        string new_str = std::regex_replace( *it, pattern, replace_str);
        std::cout << "repalce: " << new_str << std::endl;
    }//end for


    //ƥ�䣺�������� �� ATM

    std::string str("��������ATM(�Ϻ�����360�㳡���ȳǵ�)");

    string substr("��������");
    string::size_type idx = str.find(substr);

    if (idx != string::npos){
        cout << "self bank match str: " << str << " substr: " <<  substr << endl;
        cout << "self bank match: " << str.substr(0, idx) << endl;
    }else {
        cout << "self bank not match! " << str << " : " <<  substr << endl;
    }

    string  pat_str = ".*��������.*|.*ATM.*";
    std::regex pat(pat_str, std::regex_constants::icase);

    bool res = std::regex_match(str, pat);

    if (res){
        cout << "self bank regex match" << endl;
    } else {
        cout << "self bank regex not match" << endl;
    }

    const char *str_ch = "��������atm(�Ϻ�)";

    res = std::regex_match(str_ch, pat);

    if (res){
        cout << "self bank regex match2" << endl;
    } else {
        cout << "self bank regex not match2" << endl;
    }
}



void regex_test(){

    string_match_way();


}


