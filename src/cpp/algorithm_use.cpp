/*
 * algorithm_use.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: wangwei69
 */

#include <vector>
#include <algorithm>

#include <map>

#include <iostream>
using namespace std;


/*
 * @biref ����ӿڵ�ʹ�ã�sort��stable_sort
 *
 *
 */

/*
 * �ȽϺ�����ע������ǣ�const ���͵�����
 * �ȽϺ�����������Ƴ�
 */

template <class Type>
bool cmp_fun(const Type&t1,const Type &t2){
    return (t1.size() < t2.size());
}



void sort_algorithm_use(){

    //�����ַ����ĳ���,��С��������
    vector<std::string> test;

    test.push_back("wang");
    test.push_back("wei");
    test.push_back("test");
    test.push_back("ni");
    test.push_back("hao");
    test.push_back("hello");

    //�ȶ����򣺳�����ͬ���ַ���������ԭ����λ�ò���
    std::stable_sort(test.begin(),test.end(),cmp_fun<string>);
    vector<string>::iterator it = test.begin();
    for (;it != test.end();it++){
        std::cout << *it << "  ";
    }

    std::cout << std::endl;
    /*
     * Ԥ�ڽ����ni  wei  hao  wang  test  hello
     */


    test.clear();
    test.push_back("wang");
    test.push_back("niooo");
    test.push_back("weii");
    test.push_back("test");
    test.push_back("haoo");
    test.push_back("hello");

    //���ȶ����򣺳�����ͬ���ַ�����λ�ÿ��ܱ�
    std::sort(test.begin(),test.end(),cmp_fun<string>);
    it = test.begin();
    for (;it != test.end();it++){
        std::cout << *it << "  ";
    }

    std::cout << std::endl;
}


/*
 * @brief ����ַ����е�ĳ���ַ����滻����һ���ַ���
 * ͷ�ļ���
 * #include <algorithm>
 * ԭ�ͣ�
 * template <class ForwardIterator, class T>
 * void replace (ForwardIterator first, ForwardIterator last,
                const T& old_value, const T& new_value);

 *�ο���http://www.cplusplus.com/reference/algorithm/replace/?kw=replace
 */


void replace_str_use() {

    //�滻�ַ��������еĶ���-��$
    string test_replace_str = "��ΰ,test,n";
    std::replace(test_replace_str.begin(), test_replace_str.end(), ',', '$');
    cout << "test replace str: " << test_replace_str << endl;

}

/*
 * �������������� ����㷨ʹ��
 *
 */
void test_container_algorithm_use(){

    //��vector���ַ�����β��ķ���������map��Ӧ��ĳ��key��
    std::map<uint32_t, std::vector<std::string>> test_map;
    std::vector<std::string> vec = {"wang", "wei", "ni", "hao"};

    std::copy(vec.begin(), vec.end(), std::back_inserter(test_map[1]));

    std::cout << "copy back_inserter: " << test_map[1].size() << std::endl;




}

void algorithm_use(){

    sort_algorithm_use();
    replace_str_use();

    test_container_algorithm_use();
}
