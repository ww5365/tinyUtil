/*
 * cpp_read_write.cpp
 *
 *  Created on: 2016年5月18日
 *      Author: wangwei69
 */

#include "com_use.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * 解析字符串，使用分隔符，将字符串解析到vector中
 *
 */

std::vector<std::string> split(std::string str,std::string pattern){

    std::vector<std::string> res;

    std::string::size_type pos;
    //std::string::npos;

    str +=pattern;//处理很有技巧，保证最后一个分割串能被取到

    unsigned int str_size = str.size();

    for(unsigned int i=0;i<str.size();i++){
        pos = str.find(pattern,i);  //从i开始找，找到pattern，返回位置从下标0开始；
        int find_len = 0;
        if(pos < str_size && pos != std::string::npos){  //定位到的位置
            find_len = pos - i;
            if(find_len >0){
                std::string s = str.substr(i,find_len);  //i索引起始位置，从0开始
                res.push_back(s);
            }
            i = pos + pattern.size() - 1;  //下一次搜索开始位置。为什么-1，因为下一次循环i++啦
        }
    }//end for

    return res;
}



void cpp_r_w_demo(){

    std::ifstream in("D:\\workspace\\github\\tinyUtil\\src\\test.txt");  //定义输入流对象时，关联test.txt文件；默认调用open函数；

    if(!in.is_open()){
        std::cout << "file not open !" <<std::endl;
    }

    //C++中还定义了一个在std名字空间的全局函数getline，因为这个函数的参数使用了string字符串，所以声明在了<string>头文件中了。
    std::string str;
    unsigned int line_no = 1;
    while(getline(in,str)){//将文件中的一行读入到字符串str

        std::cout << "line "<<line_no <<": " <<str<<std::endl;

        std::vector<std::string> res = split(str,"\t");

        for(unsigned int i=0;i<res.size();i++){
            std::cout << res[i] <<" ";
        }

        std::cout << std::endl;

    }










}


