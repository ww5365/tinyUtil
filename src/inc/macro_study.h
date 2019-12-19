/*
 * macro_study.h
 *
 *  Created on: 2016��3��23��
 *      Author: wangwei69
 */

#ifndef INC_MACRO_STUDY_H_
#define INC_MACRO_STUDY_H_

#include <stdio.h>

/*
 * �ɱ�����ĺ궨��
 * arg...:�ɱ�Ĳ�����=0
 * ##arg������������γɲ����б����ȥ��֮ǰ�Ķ���(����Ϊ��ʱ)
 * ˫���ž�����������
 * �����ž��ǽ�����ĺ�������һ���ַ��������ǽ�����Ĳ�����˫����������
 *
 *
 *
 */


// ## ��ɱ����(ԭֵ)�γɲ����б�

#define LOG(fmt, name, arg...) do \
{\
    printf("[%s] [%d] :" fmt, __FILE__, __LINE__, ##arg); \
} while(0);


//## �����(ԭֵ)������һ��
#define FACTORY(seg1, seg2) do \
{\
   int seg1##seg2 = 10; \
}while(0);


/*
 * �궨�壺ʵ�ֳ��õ�λ����
 */
#define  BIT_MSK(bit)     (1 << (bit))
#define  BIT_SET(x, bit)  ((x) |= BIT_MSK(bit))
#define  BIT_CLR(x, bit)  ((x) &= ~BIT_MSK(bit))
#define  BIT_TST(x, bit)  ((x) >> (bit) & 1)   //�ж�ĳ��bit λ�Ƿ�Ϊ1


void macro_study();







#endif /* INC_MACRO_STUDY_H_ */
