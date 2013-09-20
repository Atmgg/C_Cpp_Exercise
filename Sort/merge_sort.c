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
        int *zz=&sourse[0];   //��int *zz=source�ȼ�

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
                /**************************�ϲ������㷨***********************************/	

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

        printf("�����������ʱ��%d ����",end-start);
        getchar();
        getchar();

}

/**************************************
  �����ӳ���

  �������ã�
  A������������ָ�����
p:��������������ʼ��ţ���0��ʼ����
q�� �������зֳ������������е���ţ�qΪ��һ�������������һ��Ԫ����ţ�
q+1Ϊ�ڶ����������е�һ��Ԫ����ţ���0��ʼ����
r����������������ֹ��ţ���0��ʼ����

����ǰ�᣺
��q�ֿ��������������Ѿ�����

 **************************************/
void merge(int *A,int p,int q,int r)
{
        int n1=q-p+1;
        int n2=r-q;

        int L[n1+1];
        int R[n2+1];

        /***********��p��q��Ϊ����***************************/
        for(i=0;i<n1;i++)
        {
                L[i]=A[p+i];
        }


        for(i=0;i<n2;i++)
        {
                R[i]=A[q+1+i];
        }

        L[n1]=R[n2]=1000; 	//L��R��������������ڱ�����ں����ѭ�������Ѿ���ס���ܴ������ڱ���ֻҪ��֤����������
        //���е���ֵ���󼴿ɵõ���ȷ���
        /*****************************************************/

        i=0;
        j=0;

        /***********ѡ��С���ư�������***************************/
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
  �ϲ��㷨�ݹ���ó���
  �������ã�
  A������������ָ��
  p����������������ʼ��ţ���0��ʼ����
  r��������������z��ֹ��ţ���0��ʼ����


 **************************************/
void merge_sort(int *A,int p,int r)
{
        int q;
        if(p<r)
        {
                q=(p+r)/2;    //��p+(r-p)/2
                merge_sort(A,p,q);    //��һ�������еݹ���������㷨
                merge_sort(A,q+1,r);  //��һ�������еݹ���������㷨
                merge(A,p,q,r);       //ǰ���εݹ������ʹ�ֳɵ���������������Ȼ�󼴿ɵ��÷����ӳ���
        }


}


