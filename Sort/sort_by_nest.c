#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


#define count 50000

void main()



{
	int sourse[count];
	int nest[1000]={0};
	int i,j;
	int start,end;
	char in;


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
		printf("*************************************************************************");
		printf("\n");
		printf("\n");


		start=GetTickCount();
	
		/**************************鸽巢排序算法***********************************/
		for(i=0;i<count;i++)//归巢
			{
				j=sourse[i]-1;
				nest[j]+=1;
			}

		j=0;//sourse数组下标

		for(i=0;i<1000;i++)//排序
			{
				while(nest[i]!=0)
					{
						sourse[j]=i+1;
						nest[i]--;
						j++;
					}
			}
			
		/*********************************************************************/
		//Sleep(500);
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
