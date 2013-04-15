#include "AES.h"


/*************************************************/
/******************生成SBOX***********************/


//生成SBOX
//generateSBOX()
void generateSBOX()
{
	word8 sbox[16][16];
	word8 a;
	int i,j;
	FILE *fp;
	if( !(fp=fopen("SBOX.txt","w") ) )
	{
		printf("文件打开失败！\n");
		exit(0);
	}
	
	printf("SBOX:\n");
	fprintf(fp,"SBOX:\n");
	for(i=0;i<16;i++)
	{
		
		for(j=0;j<16;j++)
		{
			a=(i<<4)+j;
			sbox[i][j]=sTra(a);
			printf("%#4x,",sbox[i][j]);
			fprintf(fp,"%#4x,",sbox[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");

	}

	printf("invSBOX:\n");
	fprintf(fp,"\n\ninvSBOX:\n");
	for(i=0;i<16;i++)
	{
		
		for(j=0;j<16;j++)
		{
			a=(i<<4)+j;
			sbox[i][j]=sTra(a,0);
			printf("%#4x,",sbox[i][j]);
			fprintf(fp,"%#4x,",sbox[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");

	}
	
	fclose(fp);


}

//对一个字节S变换
//word8 sTra(word8 a)
word8 sTra(word8 a,bool mode)
{
	if(mode==1)
	{
		a=inverseEle(a);
		a=affineTra(a,mode);
	}
	else
	{
		a=affineTra(a,mode);
		a=inverseEle(a);
	}
	
	return a;
}


//取既约多项式0x011b，求逆元,规定0的逆元为0
//使用扩展的欧几里得方法
//word8 inverseEle(word8 a)
word8 inverseEle(word8 a)
{
	word16 X1=1,X2=0,X3=0x11B;
	word16 Y1=0,Y2=1,Y3=a;
	word16 T1,T2,T3,BU;
	if(!Y3)
	{
		return 0;
	}
	while(Y3!=1)
	{
		BU=polyDiv(X3,Y3);
		T1=X1^polyMul(BU,Y1);
		T2=X2^polyMul(BU,Y2);
		T3=X3^polyMul(BU,Y3);

		X1=Y1;X2=Y2;X3=Y3;
		Y1=T1;Y2=T2;Y3=T3;

	
	}
	return (word8)Y2;
}

//进行仿射变换,mode==1正仿射变换，mode==0逆仿射变换
//word8 affineTra(word8 a)
word8 affineTra(word8 a,bool mode)
{
	word8 b=0,temp;
	static word8 U[2][8]={ {0xa4,0x49,0x92,0x25,0x4a,0x94,0x29,0x52},
		{0xf1,0xe3,0xc7,0x8f,0x1f,0x3e,0x7c,0xf8} };
	static word8 V[2][1]={{0x5},{0x63}};
	word8 ut,at;
	word8 *u=U[mode],v=V[mode][0];
	
	int i,j;
	for(i=7;i>=0;i--)
	{
		b<<=1;
		
		temp=0;
		at=a;
		ut=u[i];
		for(j=0;j<8;j++)
		{	
			temp^=HIGHESTBIT8(at)*HIGHESTBIT8(ut);;
			at<<=1;
			ut<<=1;
		}

		if( temp>0 )
		{
			b|=0x1;
		}
	}
	return b^v;
}

//域GF(2)上的多项式乘法
//unsigned int polyMul(word16 a,word16 b)
word16 polyMul(word16 a,word16 b)
{
	word16 s=0,t=0,flag;
	int i;

	t^=a;
	for(i=0;i<16;i++)
	{
		flag=b&0x1;
		b>>=1;
		if(flag)
		{	
			s^=t;
		}
		t<<=1;

	}
	return s;

}

//域GF(2)上的多项式除法
//unsigned int polyMul(word16 a,word16 b)
word16 polyDiv(word16 a,word16 b)
{
	if(!b)
	{
		printf("被除数为0\n");
		return 0;
	}

	int k1,k2,t;
	const int wordLength=15;
	word16 temp,bu=0;

	k1=highestNZP(a);
	k2=highestNZP(b);
	while( k1>=k2 )
	{
		t=k1-k2;
		temp=b<<t;
		bu+=(1<<t);
		a^=temp;
		k1=highestNZP(a);
	}
	
	return bu;

}


//int highestNZP(word16 a)
//获得最高non zero position
int highestNZP(word16 a)
{
	const int wordLength=15;
	word16 temp=a;
	for(int i=0;i<16&&!HIGHESTBIT16(temp);i++)
	{
		temp<<=1;
	}
	return wordLength-i;
}

