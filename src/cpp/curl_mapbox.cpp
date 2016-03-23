/*
 * curl_mapbox.cpp
 *
 *  Created on: 2016��3��10��
 *      Author: wangwei69
 *  ˵����ʹ��libcurl��ȡmapbox��geocoding���񷵻ص����ݣ����������ص�json���ݴ�
 *
 *  ���ʣ�
 *  curl https://api.mapbox.com/geocoding/v5/mapbox.places/-73.989,40.733.json?access_token=sk.eyJ1Ijoid3c1MzY1IiwiYSI6ImNpbGx5aGhqdDY0czd1dW1jaTA1eWVrdGUifQ.L66B41d7fz0x6iKjb93tjQ
 *  ���أ�json ���ݴ�
 *
 */

/*
 * libcurl���ʹ��;
 * ����mapbox����

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <stdio.h>
#include <string.h>


int curl_mapbox() {
    //char buff[102400];
    //memset(buff,0,102400);

    const char *get_url = "https://api.mapbox.com/geocoding/v5/mapbox.places/-73.989,40.733.json?access_token=sk.eyJ1Ijoid3c1MzY1IiwiYSI6ImNpbGx5aGhqdDY0czd1dW1jaTA1eWVrdGUifQ.L66B41d7fz0x6iKjb93tjQ";
    CURL *curl;
    CURLcode res;
    FILE *fp;
    if((fp = fopen("res.txt","w")) == NULL){
        printf("open file failed!\n");
        return -1;
    }
    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, get_url);// ����server��URL
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //��ʹ��SA��֤
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); //���ص��������������fp��ָ����ļ�
       // curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp); //���ص�ͷ�����������fp��ָ����ļ�

        res = curl_easy_perform(curl); //ִ��
        printf("get curl res: %d \n",res);
        curl_easy_cleanup(curl);

    }
    //printf("\nbuff : %s\n", buff);
    fclose(fp);
    return 0;
}

*/
