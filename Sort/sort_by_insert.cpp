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
		/**************************���������㷨*******************************/
				for(i=1;i<50;i++)
				{
					min_now=sourse[i];
					for(j=i-1;j>0;j--)
					{	
					if(sourse[j+1]<sourse[j])//�����㷨���ص�Ϊǰ������п϶����Ѿ������˵ģ����Խ��������������Ĳ��뵽ԭ���е���ȷ˳�򣬾�������һ��һ��һ���ĸ�����������ԭ���order�ǲ����ҵ�				
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
		
		printf("�����������ʱ��%d ����",end-start);
		getchar();
		getchar();

}
