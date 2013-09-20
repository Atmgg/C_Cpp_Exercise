#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

const int count=50000;
int sourse[count]={0};
char in;
int start,end;

void quick_sort(int *A,int p,int r);
int partition(int *A,int left,int right);

int main()
{
	int i;
	for(i=0;i<count;i++)
	{sourse[i]=1+(int)(99999.0*rand()/RAND_MAX);}	

	for(i=0;i<50;i+=5)
		{
			std::cout<<sourse[i]<<" 		";
			std::cout<<sourse[i+1]<<" 		";
			std::cout<<sourse[i+2]<<" 		";
			std::cout<<sourse[i+3]<<" 		";
			std::cout<<sourse[i+4]<<" 		";
			std::cout<<std::endl;
		}

	std::cout<<"Start sorting now?(y/n)";
	
	in=getchar();
	if(in=='y')	
	{
		std::cout<<"*************************************************************************";
		std::cout<<std::endl<<std::endl;
	
		// start=GetTickCount();
		/*****************************调用快速排序算法****************************/
			quick_sort(sourse,0,sizeof(sourse)/sizeof(int)-1);
		/***********************************************************************/
		//Sleep(100);
		// end=GetTickCount();

		for(i=0;i<50;i+=5)
		{
			std::cout<<sourse[i]<<" 		";
			std::cout<<sourse[i+1]<<" 		";
			std::cout<<sourse[i+2]<<" 		";
			std::cout<<sourse[i+3]<<" 		";
			std::cout<<sourse[i+4]<<" 		";
			std::cout<<std::endl;
		}
		std::cout<<"程序运行需耗时："<<end-start<<"毫秒"<<std::endl;
	}
	std::cin>>i;

	return 0;

}

void quick_sort(int *A,int p,int r)//快速排序算法递归调用程序
{

	if(p<r)
	{
		int q=0;
		q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}

int partition(int *A,int left,int right)//数组划分子程序
{
	/*for(int j=p;j<=r-1;j++)
	{
		if(A[j]<=cmp)
		{
			i+=1;
			medium=A[i];A[i]=A[j];A[j]=medium;
		}
	}*/
        int cmp=A[left];
        while(left<right)
        {
                while(A[right]>=cmp && left<right)right--;
                    A[left]=A[right];
                while(A[left]<=cmp && left<right)left++;
                    A[right]=A[left];
        }// end while
        A[left]=cmp;

	return left;
}
