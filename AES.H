#ifndef _AES
#define _AES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB 4
#define NK 4
#define NR 10

typedef  unsigned char word8;
typedef  unsigned int word16;

#define  HIGHESTBIT16(x)( (x&0X8000)>0 ? 1:0 )
#define  HIGHESTBIT8(x) ( (x&0X80)>0 ? 1:0 )


/*************************************************/
/******************�ļ����ܽ���*******************/


void encriptFile(char inFile[],char outFile[],const word8 cipherkey[],const bool mode=1);
//�ܳ׳���Ϊ16���ֽڣ�ʹ�øú���ǰ�����
//mode==1ʱ���ܣ�mode==0ʱ����
//inFileΪ��Ҫ���ܵ��ļ���������·����
//outFileΪ���ܵĺ���ļ���������·����


/*************************************************/
/******************�����*************************/

//mode==1������任��mode==0�����任

//����
void encript(word8 state1[][NB],const word8 cipherkey1[]);

//������չ
void keyExpasion(const word8 cipherkey[],word8 expandedKey[][(1+NR)*NB]);

//�ܳ׼ӷ�
void addRoundKey(word8 state[][NB],word8 expandedKey[][(1+NR)*NB] ,int roundCount);

//�ֱ任
void round(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount);

//���һ���ֱ任
void finalRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB]);

//ʹ��S�н����ֽڱ任
void subBytes(word8 state[][NB],bool mode=1);

//���ƶ�
void shiftRows(word8 state[][NB],bool mode=1);

//�б任
void mixColumns(word8 state[][NB],bool moed=1);

//��һ���ֽڽ���s�б任
word8 sTra(word8 a,bool mode=1);

//����GF(8)�е���Ԫ��ȡ����Լ����ʽm(x)=0x011b
word8 inverseEle(word8 a);

//���з���任,mode==1������任��mode==0�����任
word8 affineTra(word8 a,bool mode=1);


//������non zeros position
int highestNZP(word16 a);

//����GF(8)�е���Ԫ��ȡ����Լ����ʽm(x)=0x011b
word8 inverseEle(word8 a);


//�������ݵĶԳ�Ԫ��,����shiftRows����
void exchange(word8 *a,int low,int high);

word8 xtime(word8 a);

//��GF(8)�еĳ˷����㣬ȡ����Լ����ʽ0x011b
word8 mul(word8 a,word8 b);

//��GF(2)�ϵĶ���ʽ�˷�
word16 polyMul(word16 a,word16 b);

//��GF(2)�ϵĶ���ʽ����
word16 polyDiv(word16 a,word16 b);


/*************************************************/
/******************�����***************************/

//����
void invEncript(word8 state[][NK],const word8  cipherkey[]);

//���һ���ִ����������
void invFinalRound(word8 state[][NK],word8 expandedKey[][(1+NR)*NB]);

//�ִ����������
void invRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount);

/*************************************************/
/*******************����BOX***********************/


//����SBOX
void generateSBOX();


#endif