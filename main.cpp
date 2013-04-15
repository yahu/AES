#include <stdio.h>
#include "AES.h" 

extern const word8 SBOX[];
int main()
{
	
	int i,j,k=0,count;
	static word8 expandedKey[4][(1+NR)*NB];
	word8 cipherKey[16]={0x2b,0x7e,0x15,0x16,
						 0x28,0xae,0xd2,0xa6,
						 0xab,0xf7,0x15,0x88,
						 0x09,0xcf,0x4f,0x3c};

	word8 text[4][4]={{0x32,0x88,0x31,0xe0},
				{0x43,0x5a,0x31,0x37},
				{0xf6,0x30,0x98,0x07},
				{0xa8,0x8d,0xa2,0x34}},text2[16];
	printf("sizeof(text2)=%d\n",sizeof(text2) );
	//void (*funcP)(word8 a[][NB] ,const word8  b[]);
/*	funcP=encript;
	keyExpasion(cipherKey,expandedKey);
	addRoundKey(text,expandedKey,0);
	subBytes(text,1);
	
	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");

/*	(*funcP)(text,cipherKey);
	
	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");

	funcP=invEncript;
	(*funcP)(text,cipherKey);
	
	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");
	
	printf("sizeof(cipherKey)=%d\n",sizeof(cipherKey));
	printf("4*NB=%d\n",4*NB);
	
	printf("encriptFile\n");*/

	//encriptFile("F:\\《32位汇编语言程序设计》上机指导.doc","F:\\上机指导（加密）.doc",cipherKey);
	encriptFile("F:\\上机指导（加密）.doc","F:\\上机指导（解密）.doc",cipherKey,0); 
	


	//printf("%x\n",sTra(0x21));

	return 0;

}





/* 		
	
	int i,j;
	char *name="F:\doc1.doc",temp[100];
	printf("1:%s\n",name);
	adjustFileName(name,temp);
	printf("2:%s\n",temp);


	word8 cipherkey[32]={0x6,0x2,0x6,0x3,0x6,0x3,0x6,0x3,
						 0x6,0x2,0x6,0x3,0x6,0x3,0x6,0x3,
						 0x6,0x2,0x6,0x3,0x6,0x3,0x6,0x3,
						 0x6,0x2,0x6,0x3,0x6,0x3,0x6,0x3};
						

	keyExpasion(cipherkey,expandedKey);

	for(k=0;k<1+NR;k++)
	{
		printf("\nGroup%d:\n",k);
		for(i=0;i<4;i++)
		{
			for (j=0;j<NB;j++)
				printf("%2x  ",expandedKey[i][k*NB+j]);
			printf("\n");
		}
			

	}

	encript(text,cipherkey);
	
	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");

	invEncript(text,cipherkey);
	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");

	
  int	roundCount=0;
	static word8 expandedKey[4][(1+NR)*NB];
	keyExpasion(cipherkey,expandedKey);
	for(k=0;k<1+NR;k++)
	{
		printf("\nGroup%d:\n",k);
		for(i=0;i<4;i++)
		{
			for (j=0;j<NB;j++)
				printf("%2x  ",expandedKey[i][k*NB+j]);
			printf("\n");
		}
			

	}



	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%2x  ",text[i][j]);
	printf("\n");
	*/
	/*
		encript(text,cipherkey);
		printf("\n\n");

	for(j=0;j<NB;j++)
		for(i=0;i<4;i++)
				printf("%x  ",text[i][j]);
	printf("\n");


  //调整文件名中的转义符‘\’,使c的文件操作函数能够正确识别文件名
//adjustFileName()
void adjustFileName(char FileName[],char * temp)
{
	int i,j;
	char sub[2][10]={{'\a','\b','\f','\n','\r','\t','\v'},
					{'a','b','f','n','r','t','v'} };
	for(i=0,j=0;FileName[i]!='\0';i++)
	{
		temp[j++]=FileName[i];
		
		if (FileName[i]==':')
		{	
			if(FileName[i]!=0)
				temp[j++]='\\';
		}
	
	}
	temp[j]=FileName[i];

}
	*/
	