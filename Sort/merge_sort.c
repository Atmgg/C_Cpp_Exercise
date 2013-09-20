#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define count 50000

int sourse[count];
int i,j,k;
char in;
int start,end;
int tmp;
void merge(int *A,int p,int q,int r);
void merge_sort(int *A,int p,int r);

void main()
{
        int *zz=&sourse[0];   //与int *zz=source等价

        for(i=0;i<count;i++)
                sourse[i]=1+(int)(99999.0*rand()/RAND_MAX);


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
                /**************************合并排序算法***********************************/	

                merge_sort(zz,0,count-1);

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

/**************************************
  放置子程序

  参数作用：
  A：待排序数组指针变量
p:待排序子数列起始序号，由0开始计数
q： 将子数列分成两个子子数列的序号，q为第一个子子数列最后一个元素序号，
q+1为第二个子子数列第一个元素序号，有0开始计数
r：待排序子序列终止序号，由0开始计数

调用前提：
由q分开的两个子数列已经有序

 **************************************/
void merge(int *A,int p,int q,int r)
{
        int n1=q-p+1;
        int n2=r-q;

        int L[n1+1];
        int R[n2+1];

        /***********按p、q分为两组***************************/
        for(i=0;i<n1;i++)
        {
                L[i]=A[p+i];
        }


        for(i=0;i<n2;i++)
        {
                R[i]=A[q+1+i];
        }

        L[n1]=R[n2]=1000; 	//L与R数组最后两项是哨兵项，由于后面的循环次数已经卡住了总次数，哨兵项只要保证比排序组中
        //所有的数值都大即可得到正确结果
        /*****************************************************/

        i=0;
        j=0;

        /***********选最小的牌摆在上面***************************/
        for(k=p;k<r+1;k++)
        {
                if(L[i]<R[j])
                {
                        A[k]=L[i];
                        i++;
                }
                else
                {
                        A[k]=R[j];
                        j++;
                }
        }

}

/**************************************
  合并算法递归调用程序
  参数作用：
  A：待排序数组指针
  p：待排序子数列起始序号，由0开始计数
  r：待排序子数列z终止序号，由0开始计数


 **************************************/
void merge_sort(int *A,int p,int r)
{
        int q;
        if(p<r)
        {
                q=(p+r)/2;    //即p+(r-p)/2
                merge_sort(A,p,q);    //第一个子数列递归调用排序算法
                merge_sort(A,q+1,r);  //第一个子数列递归调用排序算法
                merge(A,p,q,r);       //前两次递归调用已使分成的两个子数列有序，然后即可调用放置子程序
        }


}


