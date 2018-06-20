/*
 * data_type_covert.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: wangwei69
 */

#include <cstdio>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

void get_left_bottomXY(std::string map_id, float &x, float &y);
void string_to_number();
void number_to_string();
void add_flag_bit(uint64_t val);

void data_type_convert_test(){

    std::string mesh_code = "33740742";

    float x = 0,y = 0;
    get_left_bottomXY(mesh_code.c_str(), x, y);

    string_to_number();

    uint64_t val = 123456;
    add_flag_bit(val);

}

/*
 * �޷��ŵ������������0��1��eg��123 -�� 1230 12341
 *
 */

void add_flag_bit(uint64_t val){
    uint64_t v_tmp = val * 10;

    if (v_tmp <= std::numeric_limits<unsigned long>::max()){
        std::cout << "add_flag_bit:" << v_tmp << std::endl;
    }

}


/*
 * @brief string��number֮��ת��
 */

void string_to_number(){

    /*
     * @brief stringת����number;��������λС����
     *
     * IO ��ʽʵ�֣�c++ c
     *
     * eg:   str1     -> value
     *     "12.3456"  -> 12.35
     */

    std::string str1 = "12.3456";
    float value = 0;

    //C++ IO: sstream
    std::stringstream ss;
    ss << str1; //��str������ֵ���ý��ַ����������У�
    ss >> value; //����ַ���ת����float��

    // ����С����ľ���
    //ss.str("");
    ss.clear();
    ss.precision(2);
    ss.setf(std::ios::fixed); //�̶�С����ʾ��2λС���������õĻ�����2����Ч���֣�
    ss << value;  //value��float���ͣ����԰������õľ��ȶ��룻
    ss >> value;   //�ѱ�����λС�����ַ������������float����

    std::cout << "str to float: " << value << std::endl;

    //C IO: snprintf sscanf   ***�Ƽ�***
    value = 0;
    sscanf(str1.c_str(), "%f", &value); //��str��ʽ���������value = 12.3456
    char *buff = new char[str1.size() + 1];
    snprintf (buff, sizeof(buff), "%.2f", value); //��������ʽ������buff
    sscanf(buff, "%f", &value); //�ٴζ��뵽value=12.35
    printf("str to float: %f\n", value);
    delete []buff;
    buff = nullptr;


    /*
     * @brief ʹ�ÿ⺯���ķ�ʽʵ��
     *
     * C++ 11: <string>
     *
     * float stof(const string &str, size_t *idx=0); //��strת��float����һ�����Ϸ��ַ�����һ��λ��idx���أ�ͬʱ����float��
     * stoi
     * stol
     * stod
     * stoll
     *
     *
     * C : <stdlib.h>
     *
     * atoi��atol, atof,atod,atoll;
     *
     * long strtol(const char*, char** end, int base); //base�ǽ���10,16,8�� end���ص�һ�����Ϸ��ַ���һ��λ�ã�
     * strtod
     * strtoll
     *
     */

    value = std::stof(str1); //����ʹ��c++;��c++11��֧��
    std::cout << "c++ string stof: " << value << std::endl;

    value = std::atof(str1.c_str()); //c
    std::cout << "c string atof: " << value << std::endl;


    /*
     * ���ۣ�
     * ֧��c++11�������1����ʹ��stof�õ�floatֵ��2����ʹ��sstringstream�����þ��ȶ��룬д����
     * ��֧��C++11�� ʹ��Cģʽ
    */

}


void number_to_string(){
    float value = 12.3456;
    std::string str2;
    //C++ IO ��ʽ
    std::stringstream ss;
    ss << value;
    str2 = ss.str(); //���ַ����е�string��ֵ��str2��
    std::cout << "number to str C++ IO: " << str2 << std::endl;
    str2.clear();

    //C IO��ʽ
    char buff[32];
    memset(buff, 0 , 32);//֧���ת�����31λ
    snprintf(buff, sizeof(buff), "%f", value);
    str2 = buff;
    std::cout << "number to str C IO: " << str2 << std::endl;
    str2.clear();

    //C++�⺯��: to_string(),���԰Ѹ�������ת����string
    str2 = std::to_string(value);
    std::cout << "number to str C++ lib: " << str2 << std::endl;
    str2.clear();

    //C�⺯����itoa ������ʹ����

    /*
     * tips:
     * 1��֧�֣�c++11  to_str() һ�������㶨
     * 2����֧�ֵĻ���ʹ��C/C++��IO��ʽ
     */

}



/*
 * @brief
 * meshcodeͼ����ת��mbr�����½����ꣻ
 * wgs84���ꣻ
 *
 */


void get_left_bottomXY(const std::string map_id, float &lb_x, float &lb_y)
{

    lb_x = std::stof(map_id.substr(0, 4));
    lb_y = std::stof(map_id.substr(4, 4));

    //��������ֵ
    lb_x /= 12.0;
    lb_y /= 8.0;
    lb_x = (lb_x - 180.0);
    lb_y = (lb_y - 90.0);

    //����4λС��
    std::stringstream ss;
    ss.precision(4);
    ss.setf(std::ios::fixed);
    if(ss << lb_x){
        ss >> lb_x;
    }
    ss.clear();
    if(ss << lb_y){
        ss >> lb_y;
    }

    std::cout << "x:y " << lb_x << "," << lb_y << std::endl;
}
