#include<stdio.h>

main(int how,char* who[])
{
	char p;
	
	p=*who[1];
	printf("p= %c\n",p);
	
	if(p=='1')
		{
			printf("p= %c\n",p);
		}
	return 0;
}
