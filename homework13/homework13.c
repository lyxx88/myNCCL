//��дһ������ͳ�Ƹ������֣��հ��ַ������������ַ����ֵĴ������Լ�������
//����һ����ʽ����ӡ����У���ӡ����%d���ַ�%c���ַ���%s����ַ%p 
//���Գ��ֵĴ�����

#include <stdio.h>

void countstr(char ch)
{
	int a[37];
}

int main(void)
{
	int i;
	char str[100];

	printf("input a string");
	scanf("%s",str);
	
	i=0;
	while (str[i]!='\0')
	{
		countstr(str[i]);
	}

	return 0;
}
