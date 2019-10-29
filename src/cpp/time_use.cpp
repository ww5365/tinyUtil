/*
 * time_use.cpp
 *
 *  Created on: May 25, 2018
 *      Author: wangwei69
 *
 * @ ����ʱ�䣬������ص�c/c++ �ӿ�
 */

#include "com_use.h"
#include "time_cal.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <sys/time.h>
#include <unistd.h>

using std::cout;

int get_current_idx(int, int);
time_t get_next_time();
void utc_to_localtime();

void accurate_time();

void time_use_test(){

    //
    get_current_idx(4, 20);
    //get_current_idx(4, 120);
    //get_next_time();
    utc_to_localtime();

    accurate_time();

    Timer timer;

    sleep(1);

    cout << "the program run time: " << timer.elapse() << " us "<<std::endl;

}


time_t get_next_time(){
    int period  = 1;
    int delay = 50;
    int sec_interval = 60 * period;
    //time_t now = time(NULL);

    unsigned int now = 51;
    unsigned int next_time = 1;
    while (now < 1000){
        cout << "---------------" << std::endl;
        cout << "next_time now: " << now << std::endl;
        time_t next_time = (now / sec_interval + 1) * sec_interval + delay;
        cout << "next_time1: " << next_time << std::endl;
        if (next_time - now > sec_interval) {
            next_time -= sec_interval;
        }

        cout << "next_time: " << next_time << std::endl;
        now++;
    }

    return next_time;
}

int get_current_idx(int period, int delay){


    time_t now = time(NULL);//��1970������������long int

    cout << "now: " << now << std::endl;
    struct tm ptm;
    /*
     * �ṹ�壺struct tm
     int tm_sec;   �� �C ȡֵ����Ϊ[0,59]
     int tm_min;        �� - ȡֵ����Ϊ[0,59]
     int tm_hour;       ʱ - ȡֵ����Ϊ[0,23]
     int tm_mday;      һ�����е����� - ȡֵ����Ϊ[1,31]
     int tm_mon;       �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11]
     int tm_year;       ��ݣ���ֵ����ʵ����ݼ�ȥ1900
     int tm_wday;      ���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ�����
     int tm_yday;      ��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ�����
     int tm_isdst;      ����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ������ʱΪ0�����˽����ʱ��tm_isdst()Ϊ����
     *
     */
    localtime_r(&now, &ptm);//��ȡ��ǰʱ��now�����ڣ�

    cout << "sec: " << ptm.tm_sec << " "
         << "min: " << ptm.tm_min << " "
         << "hour: " << ptm.tm_hour << " "
         << "year:" << 1900+ptm.tm_year << " "
         << "month: " << ptm.tm_mon + 1 << " "
         << "day: " << ptm.tm_mday << " "
         << "days from yuandan:" << ptm.tm_yday << " "
         << "xialing: " << ptm.tm_isdst << std::endl;


    now = ptm.tm_hour * 3600 + ptm.tm_min * 60 + ptm.tm_sec;
    int sec = now - delay;
    if (sec < 0) {
        sec += 3600 * 24;
    }
    int idx = sec / (period * 60) + 1;

    cout << "indx: " << idx << std::endl;
    return idx;
}

/*
 * @brief ��iso8601ʱ�䣺2018-06-04T07:13:31Z ת���ɱ���ʱ��
 *
 * ISO8601��ʱ�䣬��ʵ����UTCʱ��ı�ʾ��ʽ��
 *
 */

//���diff_tm������ʲô��˼������tm����������

long long diff_tm(struct tm *a, struct tm *b) {
 return a->tm_sec - b->tm_sec
      + 60LL * (a->tm_min - b->tm_min)
      + 3600LL * (a->tm_hour - b->tm_hour)
      + 86400LL * (a->tm_yday - b->tm_yday)
      + (a->tm_year - 70) * 31536000LL
      - (a->tm_year - 69) / 4 * 86400LL
      + (a->tm_year - 1) / 100 * 86400LL
      - (a->tm_year + 299) / 400 * 86400LL
      - (b->tm_year - 70) * 31536000LL
      + (b->tm_year - 69) / 4 * 86400LL
      - (b->tm_year - 1) / 100 * 86400LL
      + (b->tm_year + 299) /400 * 86400LL;
}

void utc_to_localtime(){

    std::string iso_time = "2018-06-04T07:13:31Z"; //iso8601��׼��utcʱ���ʾ
    struct tm tm_v;
    //std::istringstream is(iso_time);
    //is >> std::get_time(&tm_v,"%Y-%m-%dT%H:%M:%SZ"); //c++11֧�֣�����utc�ض���ʽ��ʱ�䵽tm�У���������������

    int year,month,day;
    int hour,min,second;
    sscanf(iso_time.c_str(), "%d-%d-%dT%d:%d:%d", &year, &month, &day, &hour, &min, &second);

    tm_v.tm_year = year-1900;
    tm_v.tm_mon = month -1;
    tm_v.tm_mday = day;
    tm_v.tm_hour = hour;
    tm_v.tm_min = min;
    tm_v.tm_sec = second;
    tm_v.tm_isdst = -1;

    cout << "sec: " << tm_v.tm_sec << " "
         << "min: " << tm_v.tm_min << " "
         << "hour: " << tm_v.tm_hour << " "
         << "year:" << 1900+tm_v.tm_year << " "
         << "month: " << tm_v.tm_mon + 1 << " "
         << "day: " << tm_v.tm_mday << " "
         << "days from yuandan:" << tm_v.tm_yday << " "
         << "xialing: " << tm_v.tm_isdst << std::endl;

    //��ȡtm�ṹ���ݣ���Ӧ��utc��ʱ�����time_t
    time_t utc = std::mktime(&tm_v);

    struct tm tm_tmp0 = { .tm_year = tm_v.tm_year,
                     .tm_mday = tm_v.tm_mday,
                     .tm_mon = tm_v.tm_mon,
                     .tm_hour = tm_v.tm_hour,
                     .tm_isdst = -1 }; //sec �� min ���������ݶ���0

    cout << "sec: " << tm_tmp0.tm_sec << " "
         << "min: " << tm_tmp0.tm_min << " "
         << "hour: " << tm_tmp0.tm_hour << " "
         << "year:" << 1900+tm_tmp0.tm_year << " "
         << "month: " << tm_tmp0.tm_mon + 1 << " "
         << "day: " << tm_tmp0.tm_mday << " "
         << "days from yuandan:" << tm_tmp0.tm_yday << " "
         << "xialing: " << tm_tmp0.tm_isdst << std::endl;


    //��ȡ����ʱ�����
    time_t pseudo = mktime(&tm_tmp0);

    //��ȡutcʱ����tm�ṹ
    struct tm tm_tmp1 = *gmtime(&pseudo);

    tm_tmp0.tm_sec += utc - diff_tm(&tm_tmp1, &tm_tmp0);
    time_t local = tm_tmp0.tm_sec;
    struct tm tm_local = *localtime(&local); //ͨ��time_t��ȡ����ʱ��
    char local_time[32];
    strftime(local_time, sizeof(local_time), "%Y-%m-%d %H:%M:%S", &tm_local);

    cout << "time res:"  << local_time << std::endl;

}

/*
 * @brief ��ȷ��ʱ�䴦����ȷ������
 */


void accurate_time(){

    /* �������ݽṹ��

     //ʱ���
    struct  timeval{
        long  tv_sec;  //��
        long  tv_usec; //΢��
    };

    //ʱ��
    struct  timezone{
        int tz_minuteswest;  //��greenwich ʱ����˶��ٷ���
        int tz_dsttime; //type of DST correction
    };

    */

    struct timeval tv;
    struct timezone tz;

    //��ȡ��ǰϵͳ��ʱ���(��1970��ʼ)��ʱ��
    gettimeofday(&tv,&tz);

    cout << "timeval: " << tv.tv_sec << " : " << tv.tv_usec << std::endl;

    cout << "timezone: " << tz.tz_dsttime << " : " << tz.tz_minuteswest << std::endl;

    //��1970������Ϊֹ�ĺ�����

    uint64_t m_seconds = (uint64_t)tv.tv_sec* 1000 + tv.tv_usec/1000;

    cout << "mill seconds form 1970: " << m_seconds << std::endl;

}

