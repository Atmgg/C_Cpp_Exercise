#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define count 50000

int sourse[count];
int i,j;
char in;
int start,end;
int tmp;
int flag;    //flag�Ǵ���־��ð�������־


void main()
{

	for(i=0;i<count;i++)
		sourse[i]=1+(int)(999.0*rand()/RAND_MAX);

	
	for(i=0;i<50;i+=5)
		{
			printf("%d		",sourse[i]);
			printf("%d		",sourse[i+1]);
			printf("%d		",sourse[i+2]);
			printf("%d		",sourse[i+3]);
			printf("%d		",sourse[i+4]);
			printf("\n");
		}
	printf("Start sorting now?(y/n)");
	in=getchar();
	if(in=='y')
	{
	printf("********************************************************************");
	printf("\n");
	
	start=GetTickCount();
	/**************************ð�������㷨***********************************/	
	for(i=0;i<count;i++)
		{
			flag=1;     //ÿ�ο�ʼʱ����־��Ϊ��

			for(j=count-1;j>=i+1;j--)
			{
				if(sourse[j]<sourse[j-1])
					{
						tmp=sourse[j-1];
						sourse[j-1]=sourse[j];
						sourse[j]=tmp;
						flag=0;//���н�����������˵��ʣ�µ���������Դ���������
					}
			}

			if(flag==1) 		//û�з���һ�ν�����˵��ʣ�µ���������Ѿ���ȫ����
			{
				break;
			}
			
		}
	/*************************************************************************/
	end=GetTickCount();

	for(i=0;i<50;i+=5)
		{
			printf("%d		",sourse[i]);
			printf("%d		",sourse[i+1]);
			printf("%d		",sourse[i+2]);
			printf("%d		",sourse[i+3]);
			printf("%d		",sourse[i+4]);
			printf("\n");
		}

	}
	printf("�����������ʱ��%d ����",end-start);
		getchar();
		getchar();

}

