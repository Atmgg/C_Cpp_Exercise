#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define count 50000

	int sourse[count];
	int i,j,min_now=0,flag=0;
	char in;
	int start,end;



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
	/**************************选择排序算法***********************************/
	
	for(i=0;i<count;i++)
		{
			flag=i;

			for(j=i+1;j<count;j++)
			{
				if(sourse[j]<min_now)
					{
						min_now=sourse[j];
						flag=j;
					}
			}
			
			min_now=sourse[i];
			sourse[flag]=sourse[i];
			sourse[i]=min_now;
			
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
	printf("程序运行需耗时：%d 毫秒",end-start);
		getchar();
		getchar();

}
