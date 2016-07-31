/*
 * curl_mapbox.h
 *
 *  Created on: 2016��5��16��
 *      Author: wangwei69
 */


#ifndef INC_CURL_MAPBOX_H_
#define INC_CURL_MAPBOX_H_
#include <string>

class CHttpClient
{
public:
    CHttpClient(void);
    virtual ~CHttpClient(void);

public:
    /**
    * @brief HTTP POST����
    * @param strUrl �������,�����Url��ַ,��:http://www.baidu.com
    * @param strPost �������,ʹ�����¸�ʽpara1=val1?2=val2&��
    * @param strResponse �������,���ص�����
    * @return �����Ƿ�Post�ɹ�
    */
    int post_http(const std::string & strUrl, const std::string & strPost, std::string & strResponse);

    /**
    * @brief HTTP GET����
    * @param strUrl �������,�����Url��ַ,��:http://www.baidu.com
    * @param strResponse �������,���ص�����
    * @return �����Ƿ�Post�ɹ�
    */
    int get_http(const std::string & strUrl, std::string & strResponse);

    /**
    * @brief HTTPS POST����,��֤��汾
    * @param strUrl �������,�����Url��ַ,��:https://www.alipay.com
    * @param strPost �������,ʹ�����¸�ʽpara1=val1?2=val2&��
    * @param strResponse �������,���ص�����
    * @param pCaPath �������,ΪCA֤���·��.�������ΪNULL,����֤��������֤�����Ч��.
    * @return �����Ƿ�Post�ɹ�
    */
    int post_https(const std::string & strUrl, const std::string & strPost, std::string & strResponse, const char * pCaPath = NULL);

    /**
    * @brief HTTPS GET����,��֤��汾
    * @param strUrl �������,�����Url��ַ,��:https://www.alipay.com
    * @param strResponse �������,���ص�����
    * @param pCaPath �������,ΪCA֤���·��.�������ΪNULL,����֤��������֤�����Ч��.
    * @return �����Ƿ�Post�ɹ�
    */
    int get_https(const std::string & strUrl, std::string & strResponse, const char * pCaPath = NULL);



public:
    void set_debug(bool bDebug);

private:
    bool _m_bDebug;
};


#endif /* INC_CURL_MAPBOX_H_ */
