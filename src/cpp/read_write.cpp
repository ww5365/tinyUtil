/*
 * read_write.cpp
 *
 *  Created on: 2016��3��23��
 *      Author: wangwei69
 */

#include<stdio.h>
#include "com_use.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

void read_write_demo(){

    //sscanf�����ʽ���������ַ�����������
    const char *geo = "(123.22,456.33;234.11,567.22)";
    double x1=0,y1=0,x2=0,y2=0;
    sscanf(geo,"(%lf,%lf;%lf,%lf)",&x1,&y1,&x2,&y2);  //�������磺(1,2;1,2)  �����������ַ�����������
    printf("geo str: %s\n",geo);
    printf("the res is: %f,%f,%f,%f \n",x1,y1,x2,y2);

}


/*
 * ʹ�� STL ��copyʵ�������������
 * �������� ���Ӷ�����������
 *
 * �ϰ��㣺 ��ͬ�� iterator ����
 *
 */

int copy_read_write_demo()
{
     typedef vector<int> IntVector;
     typedef istream_iterator<int> IstreamItr;
     typedef ostream_iterator<int> OstreamItr;
     typedef back_insert_iterator< IntVector > BackInsItr;

     IntVector myvector;

     // �ӱ�׼�����豸��������
     // ֱ��������Ƿ���������Ϊֹ �������������У�����������ּ����س���������
     cout << "Please input element��" << endl;
     copy(IstreamItr(cin), IstreamItr(), BackInsItr(myvector));

     //��������������Ԫ�أ�Ԫ��֮���ÿո����
     cout << "Output : " << endl;
     copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));
     cout << endl;

    return 0;
}


/*
 * ʹ�� c �ļ������ж������ļ��Ķ�д
 *
 * fopen fclose
 * fwrite
 * fread
 * ftell fseek
 *
 */

class PbIO{
public:
    // Constructor
    explicit PbIO(const char* filepath);
    // Destructor
    ~PbIO(){
        if (fp){
            fclose(fp);
        }
        fp = NULL;
    }

    void Rewind() {
        fseek(fp, 0, SEEK_END); //����ڵ�3��������ƫ���� SEEK_SET, SEEK_CUR
        m_file_left_byte = ftell(fp);  //���ص�ǰ�ļ�ָ���λ��
        rewind(fp);  //�ָ��ļ�ָ���λ�õ���ʼ
    }

    //����������ļ�
    int WriteMessage(){



    }

    //����������ļ�
    int ReadMessag(){

        // Check End of File
        if (m_file_left_byte <= sizeof(int) + 1) {
            //ul_writelog(UL_LOG_NOTICE, "[suggestion][End of pb file!]");
            return 0;
        }
       //message->Clear();

        int siz = 0;
        int ret = fread(&siz, sizeof(int), 1, fp);
        if (ret != 1) {
            //ul_writelog(UL_LOG_FATAL, "[suggestion][Failed to read message size]");
            return -1;
        }
        m_file_left_byte -= sizeof(int);

        // Pay attention to buff size.
        char buff[8192];
        ret = fread(buff, sizeof(char), siz, fp);
        if (ret != siz) {
            //ul_writelog(UL_LOG_FATAL, "[suggestion][Failed to read message]");
            return -1;
        }
        m_file_left_byte -= siz;
        //message->ParseFromArray(buff, siz);
        return 1;
}

private:
    //Disallow
    PbIO() {}

private:
    FILE* fp;
    int64_t m_file_left_byte;
};


