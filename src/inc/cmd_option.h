/*
 * CmdOption.h
 *
 *  Created on: 2016��2��19��
 *      Author: wangwei69
 */

#ifndef CMDOPTION_INCLUDE_CMDOPTION_H_
#define CMDOPTION_INCLUDE_CMDOPTION_H_

#include<map>
#include<string>

namespace util {
    class CmdOption {
    public:
        CmdOption();
        virtual ~CmdOption();

        int init(int argc, char * const * argv, const char *optstr);

        bool has_option(const char *) const;

        const char* operator[](const char *) const;


    private:
        const static int CHAR_TABLE_SIZE = 256;
        char _ch[CHAR_TABLE_SIZE];

        int set_opt_string(const char *); //ʹ��optstr��ʼ���ַ���

        std::multimap<std::string,std::string> _args;


    };

}

#endif /* CMDOPTION_INCLUDE_CMDOPTION_H_ */
