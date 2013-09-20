#include <iostream>
#include <stdio.h>
#include <windows.h>

const int count=50000;
int sourse[count]={0};
char in;
int start,end;

int heap_size=sizeof(sourse)/sizeof(int)-1;//待排序堆的大小，以零开始计


/**********以下三个子程序分别用于计算父节点，左子节点和右子节点************/
int parent(int i)
{
	return i%2+1;
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}
/***********************************************************************/


/***************本程序在节点i的左右子节点均为最大堆前提下将i为根的子树排列为最大堆*********************/
void max_heapify(int *A, int i)
{
	int m=left(i);
	int n=right(i);

	int maxnum=0;

	if(m<=heap_size && A[i]<A[m])
	{
		maxnum=m;
	}
	else maxnum=i;

	if(n<=heap_size && A[maxnum]<A[n])
	{
		maxnum=n;
	}

	if(maxnum!=i)
	{
		int medium=0;
		medium=A[i];A[i]=A[maxnum];A[maxnum]=medium;
		max_heapify(A, maxnum);//递归调用此函数
	}
}
/***********************************************************************/


/******************调用max_heapify()将数组A建为最大堆********************/
void bulid_max_heap(int *A)
{
	for(int i=heap_size/2;i>=0;i--)
	{max_heapify(A,i);}
}
/***********************************************************************/



/*********************使用堆排序依次将根节点置换至数组尾部**************/
void heap_sort(int *A)
{
	int medium=0;
	for(int i=heap_size;i>=1;i--)
	{
		medium=A[heap_size];A[heap_size]=A[0];A[0]=medium;
		heap_size-=1;
		max_heapify(A,0);//此时除根节点外的其他子树均为最大堆，只需掉用一次堆排序子程序即可
	}

}
/***********************************************************************/



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
	
		start=GetTickCount();
		/*****************************调用堆排序算法****************************/
		bulid_max_heap(sourse);
		heap_sort(sourse);
		/***********************************************************************/
		//Sleep(100);
		end=GetTickCount();

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

