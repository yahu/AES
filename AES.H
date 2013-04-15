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
/******************文件加密解密*******************/


void encriptFile(char inFile[],char outFile[],const word8 cipherkey[],const bool mode=1);
//密匙长度为16个字节，使用该函数前请检验
//mode==1时加密，mode==0时解密
//inFile为需要加密的文件名（包含路径）
//outFile为加密的后的文件名（包含路径）


/*************************************************/
/******************组加密*************************/

//mode==1正仿射变换，mode==0逆仿射变换

//加密
void encript(word8 state1[][NB],const word8 cipherkey1[]);

//密码扩展
void keyExpasion(const word8 cipherkey[],word8 expandedKey[][(1+NR)*NB]);

//密匙加法
void addRoundKey(word8 state[][NB],word8 expandedKey[][(1+NR)*NB] ,int roundCount);

//轮变换
void round(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount);

//最后一轮轮变换
void finalRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB]);

//使用S盒进行字节变换
void subBytes(word8 state[][NB],bool mode=1);

//行移动
void shiftRows(word8 state[][NB],bool mode=1);

//列变换
void mixColumns(word8 state[][NB],bool moed=1);

//对一个字节进行s盒变换
word8 sTra(word8 a,bool mode=1);

//求域GF(8)中的逆元，取不可约多项式m(x)=0x011b
word8 inverseEle(word8 a);

//进行仿射变换,mode==1正仿射变换，mode==0逆仿射变换
word8 affineTra(word8 a,bool mode=1);


//获得最高non zeros position
int highestNZP(word16 a);

//求域GF(8)中的逆元，取不可约多项式m(x)=0x011b
word8 inverseEle(word8 a);


//交换数据的对称元素,服务shiftRows函数
void exchange(word8 *a,int low,int high);

word8 xtime(word8 a);

//域GF(8)中的乘法运算，取不可约多项式0x011b
word8 mul(word8 a,word8 b);

//域GF(2)上的多项式乘法
word16 polyMul(word16 a,word16 b);

//域GF(2)上的多项式除法
word16 polyDiv(word16 a,word16 b);


/*************************************************/
/******************组解密***************************/

//解密
void invEncript(word8 state[][NK],const word8  cipherkey[]);

//最后一步轮处理的逆操作
void invFinalRound(word8 state[][NK],word8 expandedKey[][(1+NR)*NB]);

//轮处理的逆操作
void invRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount);

/*************************************************/
/*******************生成BOX***********************/


//生成SBOX
void generateSBOX();


#endif