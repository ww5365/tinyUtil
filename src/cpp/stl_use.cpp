/*
 * stl_use.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: wangwei69
 *
 *  ��Ҫչ��stl���и���������ʹ�÷���
 *
 */

#include <iostream>
#include <vector>
#include "stl_use.h"
using namespace std;

/*
 * @brief ����ṹ�壬����set�÷�
 */

typedef struct DistrictInfo
{
    uint32_t cid;
    uint32_t level;
    DistrictInfo(uint32_t cid_, uint32_t level_):
        cid(cid_), level(level_){}

    /*
     * Ҫʵ���Զ��Ľṹ����ܲ���set��
     * ֱ�ӽṹ��������: <
     *      �����ϸ������ϵ����סһ�㣺��ȹ�ϵ����false��
     *      �ڲ��ᣬf(x,y) f(y,x) ���ж������С
     *
     * Ҳ���Զ���Ƚ��࣬������() ���㣺
     *
     *   struct cmp{
     *      bool operator()(const T &l, const T &r);
     *    }
     *      ʹ�õ�ʱ�� set<T, cmp>
     *
     */

    bool operator<(const DistrictInfo &right)const{
        if ((this->cid==right.cid)&&(this->level==right.level)){
            return false; //�ñȽϺ�������ͬԪ�ط���false
        }else{
            return true;
        }
    }


}DistrictInfo;

class Compare{
public:
    bool operator()(const int left, const int right){
        return (left <= right) ? true : false; //true ��λ���Ѿ��źã����ý�����(����)��
    }
};

vector<int>::iterator bin_search(vector<int> &vec, int val){

    sort(vec.begin(), vec.end(), Compare());//����������
    vector<int>::iterator start = vec.begin();
    vector<int>::iterator end = vec.end();
    while(start != end){//Ϊ�յ����Ҳ���ǽ����ˣ�
        vector<int>::iterator mid = start + (end - start)/2;//����������
        cout << "mid val: " << *mid << endl;
        if ( *mid == val){
            return mid;
        }else if(*mid > val){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return vec.end();
}

void stl_use::iterator_use(){

    std::vector<int> vec = {1,2,3,4,5,6,7,8};
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it2 = vec.end();
    std::cout << "iterator + n :" << *(it + 3) << " distance: "<< distance(it2,it)<<std::endl; //4
    std::vector<int>::reverse_iterator rit = vec.rbegin();
    std::cout << "next rit: " << *(next(rit)) << endl; //7

    //����������Ӧ��ʵ�������ֲ���

    int val = 2;
    vector<int>::iterator pos = bin_search(vec, val);

    if (pos != vec.end()){

        std::cout << "binary find: " << *pos << std::endl;
     }else{
         std::cout << "binary not find!" << std::endl;
     }


}


void stl_use::list_use(){

    //test splice
    std::list<int> li_t{3,4,5,6,9};
    list<int>::iterator itor = li_t.begin();
    std::advance(itor, 2); //point to 5
    li_t.splice(li_t.end(), li_t, itor); //cut 5 to the end of list
    //itor is valid? yes
    std::cout << "itor is valid?" << *itor << std::endl;


    li_t.push_back(10);
    li_t.push_back(11);

    auto it_last = li_t.end();

    std::map<std::string, std::list<int>::const_iterator> lmap;
    std::string key("wang");
    lmap.insert(std::make_pair(key, --it_last));

    li_t.push_back(12);


    if (lmap.count(key)){
        auto it = lmap[key];
        cout << "lmap key: " << key << " list value: " << *it << endl;
    }

    //�������������еĶ��Ԫ��

    vector<int> other = {1000,1001,1002};

    li_t.insert(li_t.begin(), other.begin(), other.end());




    //������list�Ļ����ϣ���������λ��Ԫ��

    list<int> li_t2 = {3,4,5,6};

    auto itor2 = li_t2.begin();

    std::advance(itor2, 1);

    li_t2.insert(itor2, 10000);
    li_t2.insert(itor2, 100);
    li_t2.insert(itor2, 10);  //itor2û�б䶯��һֱָ��Ԫ��4 ��ʱ����ǣ�3,10000,100,10,4,5,6





    for (auto e: li_t2){

        cout << "list content: " << e << endl;
    }


}

void stl_use::set_use() {

    //����set����ͬ�ṹ�����,���ȥ��struct���͵����ݣ�
    // ���� operater<


    std::set<DistrictInfo> test_set;

    if (true) {
        DistrictInfo test_d1(131, 3);
        DistrictInfo test_d2(131, 3);
        DistrictInfo test_d3(0, 0);
        test_set.insert(test_d1);
        test_set.insert(test_d2);  //�ᱻȥ�ص�
        test_set.insert(test_d3);
        test_set.insert(test_d3);
    }

    cout << "test set size: " << test_set.size() << endl;

    DistrictInfo test_d3(131, 3);

    auto it = test_set.find(test_d3);
    std::size_t elem_count = test_set.count(test_d3);

    cout << "test set element: " << (*it).cid << " elem count: " << elem_count<< endl;

    //multiset ���������󽻼�

    multiset<int> left = {1,2,2,3,4,7,8,9};
    multiset<int> right = {2,4,5,8,9,9};
    multiset<int> result;

    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(result, result.begin()));

    cout << "test set intersection res size: "  << result.size() << endl;


    for(auto it = result.begin(); it != result.end(); ++it){

        auto range = result.equal_range(*it);
        auto first_elem = range.first;

        while (first_elem != range.second){
            cout << "test set intersection elem: " << *first_elem <<  endl;
            ++first_elem;
        }
    }







}



void stl_use::map_use() {

    //pair make_pair map
    pair<int, string> pa(1, "wang"); //ֱ�ӳ�ʼ��
    pair<int, string> pb;
    pb = make_pair(2, "wei");
    pair<int, string> pc;
    pc = make_pair(4, "ni");  //ʹ��make_pair��ʼ��:pair
    pc.first = 3;

    map<int, string> ma;
    ma.insert(pa);
    ma.insert(pb);
    ma.insert(pc);
    ma.insert(make_pair(4, "hao"));

    for (auto e : ma) {
        cout << e.first << ":" << e.second << endl;
    }


    //multimap

    multimap<int, string> mm1;
    mm1.insert(make_pair(1,"test1"));
    mm1.insert(make_pair(1,"test11"));
    mm1.insert(make_pair(2, "test2"));
    mm1.insert(make_pair(2, "test22"));
    mm1.insert(make_pair(2, "test222"));
    mm1.insert(make_pair(3, "test3"));


    auto it = mm1.find(1);

    cout << "key: test1 -> " << it->second << endl;


    for(auto it = mm1.lower_bound(2); it != mm1.upper_bound(2); ++it){

        cout << "key range: test1 -> " << it->second << endl;
    }

    /*
     * multimap�ı���
     *
     * ��һ��ѭ����it->first it->second �ֱ���mapÿһ��Ԫ��:key value
     *
     * �ڶ���ѭ����range: ĳ��key��Ӧ������Ԫ�أ�
     * range.first�ǵ�һ��Ԫ�صĵ�������range.second�����һ��Ԫ�صĵ�������
     *
     * range.first->first ��һ��Ԫ�ص�key
     * range.first->second ��һ��Ԫ�ص�value
     *
     */

    cout << "multi map tranverse ---" << endl;


    list<string> l_in;
    l_in.push_back("wang");
    l_in.push_back("wei");
    l_in.push_back("ni");
    l_in.push_back("a");


    auto l_it = l_in.begin();
    int last_pos = 0;
    int pos = 0;
    int l_len = l_in.size();

    /*
     * key ��Ҫ����list��λ�ã�value��Ҫ�����ֵ
     * Ҫʵ�ֵ��ǣ�����ԭ��list�е�λ��˳��������λ�ò���multimap�е�valueֵ��
     *
     * 1������mutimap�ı���
     * 2������list������λ�ò���
     *
     */


    for (auto it = mm1.begin(); it != mm1.end(); it = mm1.upper_bound(it->first)){

        auto range = mm1.equal_range(it->first);

        if (it->first <= (l_len + 1)) {
            pos = (it->first - 1);
            int diff_pos = pos - last_pos;
            std::advance(l_it, diff_pos);
            cout << "mm1 first: " << it->first << " second: " << it->second << endl;
        } else {
            l_it = l_in.end();
        }

        while (range.first != range.second) {
            cout << "range first: " << range.first->first
                    << " range second: " << range.first->second << endl;
            l_in.insert(l_it, range.first->second);
            ++range.first;
        }

        last_pos = pos;
    }

    for (auto e: l_in){
        cout << "l_in list: "  << e << endl;
    }

}


void stl_use::priority_queue_use(){
    //������ʹ�����ȼ����еĳ�����ʽ��deque�������ǰ��շ�����С��������
    std::priority_queue<Student,std::deque<Student>,CompareFun> qu_test;

    Student s1("wang",60);
    Student s2("wei",60);
    Student s3("song",54);
    Student s4("ni",76);
    Student s5("havy",80);

    qu_test.push(s1);
    qu_test.push(s2);
    qu_test.push(s3);
    qu_test.push(s4);
    qu_test.push(s5);

    std::cout << "score \t name " <<std::endl;

    while(!qu_test.empty()){
        std::cout << qu_test.top().get_score() << "\t"
                <<qu_test.top().get_name() <<std::endl;

        qu_test.pop();
    }
}

void stl_use::vector_use(){

    //test emplace

    vector<int> test1;
    vector<int> test2;

    test1.emplace_back(1);//ֱ�ӹ���
    test1.emplace_back(2);
    test1.emplace_back(3);
    test2.emplace_back(4);
    test2.emplace_back(5);
    test2.emplace_back(6);
    vector<int> res;

    //ʹ��insert������Ԫ��
    res.insert(res.end(),test1.begin(),test1.end());
    res.insert(res.end(),test2.begin(),test2.end());

    for(auto e:res){
        cout <<"emplace1 res:" << e << endl ;
    }

    res.clear();
    //emplace������Ԫ�أ�

    for(auto e:test1){
        res.emplace_back(e);
    }

    for(auto e:test2){
        res.emplace_back(e);
    }

    for(auto e:res){
        cout <<"emplace2 res:" << e << endl ;
    }

    cout << endl;

}






