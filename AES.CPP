#include "AES.h"


extern const word8 SBOX[256]={
0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30, 0x1,0x67,0x2b,0xfe,0xd7,0xab,0x76,
0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
 0x4,0xc7,0x23,0xc3,0x18,0x96, 0x5,0x9a, 0x7,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
 0x9,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
0x53,0xd1,   0,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9, 0x2,0x7f,0x50,0x3c,0x9f,0xa8,
0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
0xcd, 0xc,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e, 0xb,0xdb,
0xe0,0x32,0x3a, 0xa,0x49, 0x6,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae, 0x8,
0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
0x70,0x3e,0xb5,0x66,0x48, 0x3,0xf6, 0xe,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
0x8c,0xa1,0x89, 0xd,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d, 0xf,0xb0,0x54,0xbb,0x16
};

const word8 invSBOX[256]={
0x52, 0x9,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb,
0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb,
0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95, 0xb,0x42,0xfa,0xc3,0x4e,
 0x8,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25,
0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92,
0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84,
0x90,0xd8,0xab,   0,0x8c,0xbc,0xd3, 0xa,0xf7,0xe4,0x58, 0x5,0xb8,0xb3,0x45, 0x6,
0xd0,0x2c,0x1e,0x8f,0xca,0x3f, 0xf, 0x2,0xc1,0xaf,0xbd, 0x3, 0x1,0x13,0x8a,0x6b,
0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73,
0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e,
0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62, 0xe,0xaa,0x18,0xbe,0x1b,
0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4,
0x1f,0xdd,0xa8,0x33,0x88, 0x7,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f,
0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a, 0xd,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef,
0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61,
0x17,0x2b, 0x4,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21, 0xc,0x7d
};
/*************************************************/
/******************文件加密解密*******************/

//文件加密
//encriptFile()
void encriptFile(char inFile[],char outFile[],const word8 cipherkey[],const bool mode)
//密匙长度为16个字节，使用该函数前请检验
//mode==1时加密，mode==0时解密
//inFile为需要加密的文件名（包含路径）
//outFile为加密的后的文件名（包含路径）
{
	
	FILE *fp1,*fp2;
	word8 temp[4][NB],text[4*NB];
	int count,i,j;
	void (*funcP)(word8 a[][NB] ,const word8  b[]);
	
	if(mode==1)
		funcP=encript;
	else
		funcP=invEncript;

	if( ( fp1=fopen(inFile,"rb") )==0 ) 
	{
		printf("can not open %s\n",inFile);
		exit(0);
	}

	if( ( fp2=fopen(outFile,"wb") )==0 ) 
	{
		printf("can not open %s\n",outFile);
		exit(0);
	}
	
	
	while( ( count=fread(text,1,4*NB,fp1)) == 4*NB)
	{
		for(j=0;j<NB;j++)
			for(i=0;i<4;i++)
				temp[i][j]=text[4*j+i];
	
		(*funcP)(temp,cipherkey);
		
		for(j=0;j<NB;j++)
			for(i=0;i<4;i++)
				text[4*j+i]=temp[i][j];

		if(( count=fwrite(text,1,16,fp2) )<16)
			printf("写入错误!\n");

	}

	fwrite(text,1,count,fp2);
	fclose(fp1);
	fclose(fp2);
}
/*************************************************/
/********************组加密***********************/

//加密
//void encripnt(word8 state1[],word8 cipherKey1[])
void encript(word8 state[][NB],const word8 cipherKey[])
{
	int roundCount=0;
	static word8 expandedKey[4][(1+NR)*NB];
	roundCount=0;

	keyExpasion(cipherKey,expandedKey);
	addRoundKey(state,expandedKey,roundCount);
	for(roundCount=1;roundCount<NR;roundCount++)
		round(state,expandedKey,roundCount);
	finalRound(state,expandedKey);
}
//密码扩展,密匙的长度不超度192位，NK取6
//keyExpasion()
void keyExpasion(const word8 cipherKey[],word8 expandedKey[][(1+NR)*NB])
{
	word8 CR;
	int i,j;
	for(j=0;j<NK;j++)
		for(i=0;i<4;i++)
			expandedKey[i][j]=cipherKey[4*j+i];

	CR=1;

	for(;j<(1+NR)*NB;j++)
	{
		if(j%NK==0)
		{
			
			expandedKey[0][j]=expandedKey[0][j-NK]^sTra(expandedKey[1][j-1])^CR;
			for(i=1;i<4;i++)
			{
				expandedKey[i][j]=expandedKey[i][j-NK]^sTra(expandedKey[(i+1)%4][j-1]);
			}

			if( HIGHESTBIT8(CR))
				CR=(CR<<1)^0x1b;
			else 
				CR<<=1; 

		}
		else
		{
			for(i=0;i<4;i++)
				expandedKey[i][j]=expandedKey[i][j-NK]^expandedKey[i][j-1];
		}		
	}

}
//密匙加法
//void addRoundKey(word8 state[][NB],word8 expandedKey[][(1+NR)*NB] )
void addRoundKey(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount)
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<NB;j++)
			state[i][j]^=expandedKey[i][roundCount*NB+j];

	
}
//轮变换
//void round(word8 state[][NB],word8 expandedKey[][(1+NR)*NB])
void round(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount)
{	
	subBytes(state);
	shiftRows(state);
	mixColumns(state);
	addRoundKey(state,expandedKey,roundCount);

}
//最后一轮轮变换
//void finalRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB])
void finalRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB])
{
	subBytes(state);
	shiftRows(state);
	addRoundKey(state,expandedKey,NR);
}
//使用S盒进行字节变换
//void subBytes(word8 state[][NB])
void subBytes(word8 state[][NB],bool mode)
{	
	int i,j;
	word8 rNr,cNr;

	if(mode)
		for(i=0;i<4;i++)
			for(j=0;j<NB;j++)
			{
				cNr=state[i][j]&0xf;
				rNr=(state[i][j]>>4)&0xf;
				state[i][j]=SBOX[rNr*16+cNr];
			}
	else
		for(i=0;i<4;i++)
			for(j=0;j<NB;j++)
			{
				cNr=state[i][j]&0xf;
				rNr=(state[i][j]>>4)&0xf;
				state[i][j]=invSBOX[rNr*16+cNr];
			}
}
//行移动,使用一个有趣的算法
//void shiftRows(word8 state[][NB])
void shiftRows(word8 state[][NB],bool mode)
{
	int offset[4]={0,1,2,3},i;
	for(i=0;i<4;i++)
		if(offset[i]>0)
		{
			exchange(state[i],0,NB-1);
			if(mode==1)
			{
				exchange(state[i],0,NB-1-offset[i]);
				exchange(state[i],NB-offset[i],NB-1);
			}
			else
			{
				exchange(state[i],0,offset[i]-1);
				exchange(state[i],offset[i],NB-1);

			}
			
		}			
}

//交换数据的对称元素,服务shiftRows函数
//void exchange(word8 *a,int low,int high)
void exchange(word8 *a,int low,int high)
{
	int i,mid=(low+high)/2;
	int l=low+high;
	word8 temp;
	for(i=low;i<=mid;i++)
	{
		temp=a[i];
		a[i]=a[l-i];
		a[l-i]=temp;
	}
}

//列变换
//void mixColumns(word8 state[][NB])
void mixColumns(word8 state[][NB],bool mode)
{
	static word8 c[2][4][4]=//static
	{
		{
		{0x0e,0x0b,0x0d,0x09},
		{0x09,0x0e,0x0b,0x0d},
		{0x0d,0x09,0x0e,0x0b},
		{0x0b,0x0d,0x09,0x0e} 
		},
		{
		{0x02,0x03,0x01,0x01},
		{0x01,0x02,0x03,0x01},
		{0x01,0x01,0x02,0x03},
		{0x03,0x01,0x01,0x02} 
		}
	};


	word8 s[4],temp;
	int i,j,k;
	for(i=0;i<NB;i++)//对每一列进行变换
	{
		for(j=0;j<4;j++)
			s[j]=state[j][i];

		for(j=0;j<4;j++)
		{	
			state[j][i]=0;
			for(k=0;k<4;k++)
			{
				temp=mul( c[mode][j][k], s[k] ) ;
				state[j][i]^=temp;
			}
		}
	}
}

/*************************************************/
/******************解密部分***********************/


//解密
//void invEncript(word8 state[][NK],word8 cipherKey[])
void invEncript(word8 state[][NK],const word8 cipherKey[])
{	
	int roundCount;
	static word8 expandedKey[4][(1+NR)*NB];

	keyExpasion(cipherKey,expandedKey);
	invFinalRound(state,expandedKey);

	for(roundCount=NR-1;roundCount>0;roundCount--)
		invRound(state,expandedKey,roundCount);
	addRoundKey(state,expandedKey,0);
	
}


//最后一步轮处理的逆操作
//void invFinalRound(word8 state[][NK],word8 expandedKey[][(1+NR)*NB])
void invFinalRound(word8 state[][NK],word8 expandedKey[][(1+NR)*NB])
{
	addRoundKey(state,expandedKey,NR);
	shiftRows(state,0);
	subBytes(state,0);
}

//轮处理的逆操作
//void invRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount)
void invRound(word8 state[][NB],word8 expandedKey[][(1+NR)*NB],int roundCount)
{
	addRoundKey(state,expandedKey,roundCount);
	mixColumns(state,0);
	shiftRows(state,0);
	subBytes(state,0);
}

/*************************************************/
/********************域运算***********************/
//word8 xtime( word8 a)
word8 xtime( word8 a)
{
	word8 m=0x1B;
	word8 b=a & 0x80;//取得a的最高位
	a<<=1;
	if(b>0)
		a^=0x1b;
	return a;
}

//域GF(8)中的乘法运算，取不可约多项式0x011b
//word8 mul(word8 a, word8 b)
word8 mul(word8 a, word8 b)

{
	word8 s=0,temp,flag;
	int i,j;
	for(i =0;i<8;i++)
	{
		flag=b&0x1;
		b>>=1;
		if(flag)
		{	
			temp=a;
			for(j=0;j<i;j++)
				temp=xtime(temp);
			s^=temp;
		}
		
	}

	return s;
}