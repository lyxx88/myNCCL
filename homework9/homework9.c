//�û���������һ���ַ�����
//�ж�����ַ����Ƿ�Ϊ�����ġ�(���ļ�������˳�����һ��)��
//���� ��abcba�� ���ǻ��ġ�
#include <stdio.h>

int main()
{
	char str[];
	int i,j,len;
	
	printf("input a string: ");
	scanf("%s",str);
	
	i=0;
	while(str[i]!='\0')
	{
		i++;
  }
	
	len=i-1;
	j=0;
	//len=sizeof(str);
	//j=len;
	for (i=0 ;i<len/2 ;i++ )
	{
		if (str[i]!=str[len])
		{
			printf("not palindromic number \n");
			j=1;
			break;
		}
		j--;
	}

	if(j==0)
	printf("palindromic number \n");
	
	return 0;
}


//ʹ���ַ�����ʵ�ֻ��������ַ����ļӼ�����
//����"123" + "45" = "168" , "456"-"13"="443"��


#include <stdio.h>
//���ַ����ķ�ת
void reverser(char sum[],int i)
{
		int len;
		len = i;
    for (i = 0; i < len/2; i++)
    {
        char tmp;
        tmp = sum[i];
        sum[i] = sum[len-i-1];
        sum[len-i-1] = tmp;
    }

    return;
}

//��2�����ļ���
void subtraction(char big[],int i,char small[],int j)
{
        char sub[100];
        int k=0,m;
			//printf("%s\n,%s",big,small);
        while (i>0)
        {if(j>0)
           {
        //      if(small[j-1]>'0' && small[j-1]<'9')
                   m=big[i-1]-'0'-(small[j-1]-'0');
        //      else
        //         m=big[i-1]-'0';
                if (m<0 && i-1>=0)
                {
                        big[i-1]=big[i-1]-1;
                        m=small[j-1]-'0'-(big[i-1]-'0');
                }

                sub[k++]=m+'0';
                i--;
                j--;
            }
         else
            {
                m=big[i-1]-'0';
                sub[k++]=m+'0';
                i--;
            }
        }
        sub[k]='\0';

        reverser(sub,k);
        printf("two string number subtraction = %s\n", sub);
}



//��2�����ļӷ�

void add(char numone[],int i,char numtwo[],int j)
{
        int n,k,m;
        char sum[100];
        k=0;
        while (i>0 || j>0)
        {
        	if (i<=0)
             {i=1;
              numone[i-1]='0';//�����﷢���˱仯
             }
          if(j<=0)
				     {j=1;
					    numtwo[j-1]='0';
				     }
          m=numone[i-1]-'0'+numtwo[j-1]-'0';
          if (m>9)
                {
                        n=1;
                        m=m%10;
                }
                else
                        n=0;

                sum[k]=m+n+'0';
                k=k+1;
                i--;
                j--;
        }
        sum[k]='\0';

        reverser(sum,k);
        printf("two string number add = %s\n", sum);
}



int main()
{
        char a[100],b[100];
        int i=0, j=0,ai,bj;

        printf("input two number ");

        scanf("%s",a);
        while(a[i]!='\0')
        {
                i++;
        }
        scanf("%s",b);
        while(b[j]!='\0')
        {
                j++;
        }
    //    printf("input number is over i j %d,%d\n",i,j);

	if (i>j)
        {
                subtraction(a,i,b,j);
        }
        else if (i<j)
        {
                subtraction(b,j,a,i);
        }
        else if (i=j)
        {ai=i;
         bj=j;
                while (i>=0)
                {
                        if (a[i]-'0'>b[j]-'0')
                        {
                                subtraction(a,ai,b,bj);
                                break;
                        }
                        else
                        {
                                subtraction(b,bj,a,ai);
                          break;
                        }
                        i--;
                        j--;
                }
        }
        
	add(a,i,b,j);//��add���������b����������ݱ���ˡ�
	

        return 0;
}

/*
input two number
 1234
234
two string number subtraction = 1000
two string number add = 1468
[root@localhost nccl]# ./a.out
input two number
 34567
234
two string number subtraction = 34333
two string number add = 34792
*/

//��дһ��ȥ�ַ�������ո�ĵĳ��򣬽���
//���Ķ���ո���һ���ո���档��������"abc___ab_a__c"�����"abc ab a c"��

#include <stdio.h>

int main()
{
	char str[40];
	int i,j;
	scanf("%s",str);
	
	printf("%s",str);
	
	
	for (i=0,j=0 ;str[i]!='\0' ;i++ )
	{
		if (str[i]==' ')
		{
			j=i;
			while (str[j]==' ')
			{
				j++;
			}

			while (str[i+j+1]!='\0')
			{
				str[i+1]=str[i+j+1];
				i++;
				j++;
			}
			str[i]='\0';

		}

	}

	printf("%s",str);

	return 0;
}