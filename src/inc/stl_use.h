/*
 * stl_use.h
 *
 *  Created on: Jun 16, 2017
 *      Author: wangwei69
 */

#ifndef SRC_INC_STL_USE_H_
#define SRC_INC_STL_USE_H_

#include <string>
#include <queue>
#include <map>
#include <set>
#include <list>

/*
 * priority_queueʹ�÷���
 * ������5��ͬѧ������ӣ����Ƕ��гɼ����������밴�ճɼ��ӵ͵��߳����У�����ɼ���ȣ�����������ĸ��˳����ӣ�
 */

class Student{
private:
    std::string name;
    short score;
public:
    Student():name(""),score(0){}
    Student(std::string name,short score):name(name),score(score){}
    short get_score() const{
        return score;
    }
    std::string get_name() const{
        return name;
    }


};

class CompareFun{
public:
    bool operator() (const Student &lf,const Student &rg) const {
        if (lf.get_score() == rg.get_score()){
            return lf.get_name() < rg.get_name(); //����1��ʱ��������Ĵ󣬷���1�����е������Ѵ�ĵ�����ǰ��
        }
        return lf.get_score() > rg.get_score();//��ߴ����ұߣ�����1�����ʱ��֮ǰ��ӵ�Ԫ�ش��ں���ӵģ�����1�����е�����
    }
};


class stl_use{
public:


    void priority_queue_use();
    void vector_use();

    static void map_use();

    static void set_use();

    static void list_use();

    static void iterator_use();

};



#endif /* SRC_INC_STL_USE_H_ */
