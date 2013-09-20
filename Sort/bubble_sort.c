#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define count 50000

int sourse[count];
int i,j;
char in;
int start,end;
int tmp;
int flag;    //flag是带标志的冒泡排序标志


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
	/**************************冒泡排序算法***********************************/	
	for(i=0;i<count;i++)
		{
			flag=1;     //每次开始时将标志设为真

			for(j=count-1;j>=i+1;j--)
			{
				if(sourse[j]<sourse[j-1])
					{
						tmp=sourse[j-1];
						sourse[j-1]=sourse[j];
						sourse[j]=tmp;
						flag=0;//若有交换发生，则说明剩下的排序堆中仍存在无序性
					}
			}

			if(flag==1) 		//没有发生一次交换，说明剩下的排序堆中已经完全有序
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
	printf("程序运行需耗时：%d 毫秒",end-start);
		getchar();
		getchar();

}

