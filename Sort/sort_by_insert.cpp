#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


main()



{
	int sourse[50];
	int i,j,min_now=0;
	char in;
	int start,end;


	for(i=0;i<50;i++)
		
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
		/**************************插入排序算法*******************************/
				for(i=1;i<50;i++)
				{
					min_now=sourse[i];
					for(j=i-1;j>0;j--)
					{	
					if(sourse[j+1]<sourse[j])//插入算法的特点为前面的子列肯定是已经有序了的，所以将会把新数据有序的插入到原组中的正确顺序，就像泡泡一样一个一个的浮上来，所以原组的order是不会乱的				
						{
							sourse[j+1]=sourse[j];
							sourse[j]=min_now;														
						}
					}
				}
	
		/*********************************************************************/
		
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
