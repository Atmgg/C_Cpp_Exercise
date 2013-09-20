#include <iostream>
#include <stdio.h>
#include <windows.h>

const int count=50000;
int sourse[count]={0};
char in;
int start,end;

int heap_size=sizeof(sourse)/sizeof(int)-1;//������ѵĴ�С�����㿪ʼ��


/**********���������ӳ���ֱ����ڼ��㸸�ڵ㣬���ӽڵ�����ӽڵ�************/
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


/***************�������ڽڵ�i�������ӽڵ��Ϊ����ǰ���½�iΪ������������Ϊ����*********************/
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
		max_heapify(A, maxnum);//�ݹ���ô˺���
	}
}
/***********************************************************************/


/******************����max_heapify()������A��Ϊ����********************/
void bulid_max_heap(int *A)
{
	for(int i=heap_size/2;i>=0;i--)
	{max_heapify(A,i);}
}
/***********************************************************************/



/*********************ʹ�ö��������ν����ڵ��û�������β��**************/
void heap_sort(int *A)
{
	int medium=0;
	for(int i=heap_size;i>=1;i--)
	{
		medium=A[heap_size];A[heap_size]=A[0];A[0]=medium;
		heap_size-=1;
		max_heapify(A,0);//��ʱ�����ڵ��������������Ϊ���ѣ�ֻ�����һ�ζ������ӳ��򼴿�
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
		/*****************************���ö������㷨****************************/
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
		std::cout<<"�����������ʱ��"<<end-start<<"����"<<std::endl;
	}
	std::cin>>i;

	return 0;

}

