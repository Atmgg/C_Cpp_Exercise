#include <iostream>
#include <limits.h>
#include <math.h>
#include <memory.h>

using namespace std;

// 一个数组，含有重复元素，给出两个数num1和num2，求这两个数字在数组中出现的位置的最小距离
// 要求O(n)时间复杂度，O(1)空间复杂度
//
int MinDist(int *Arr,int len,int num1, int num2)
{
        if(!Arr || len<=0)
                return -1;

        int TmpDis =0;
        int MinDis =INT_MAX;
        int LastNum=-1;
        for(int i=0;i<=len;++i)
        {
                if(Arr[i]!=num1 && Arr[i]!=num2)
                        continue;
                if(LastNum ==-1 )
                        LastNum=i;
                if(Arr[LastNum] != Arr[i])
                {
                        TmpDis=i-LastNum;
                        if(TmpDis < MinDis)
                                MinDis = TmpDis;
                }
                LastNum=i;
        }

        return MinDis;
}

// 给定一个数组a[N],我们希望构造数组b[N]，其中b[i]=a[0]*a[1]*...*a[N-1]/a[i]
void ConstructMutiArr(int *a,int len_a,int *b)
{
        if(!a || !b || len_a<=0)
                return;
        b[0]=1;
        for(int i=1;i<len_a;++i)
        {
                b[i] = b[i-1]*a[i-1];
        }
        for(int i=len_a-1;i>=1;--i)
        {
                
                b[i] = b[i]*b[0];
                b[0] = b[0]*a[i];
        }
}

// 一个整型数组里除了1个数字只出现一次之外，其他的数字都出现了两次。请写出程序找出这个只出现1次的数字
// 要求时间复杂度是O(n)，空间复杂度是O(1)
int FindUniqNum(int *A,int Len)
{
        if(!A || Len<=0)
                return -1;
        int Ret=0;
        for(int i=0;i<Len;++i)
        {
                Ret ^= A[i];
        }
        return Ret;
}

// 一个整型数组里除了2个数字只出现一次之外，其他的数字都出现了两次。请写出程序找出这个只出现2次的数字
// 要求时间复杂度是O(n)，空间复杂度是O(1)
pair<int,int> FindTwoUniqNum(int *Arr,int Len)
{
        if(!Arr || Len<=0)
                return make_pair(-1,-1);
        int AorB = 0;
        for(int i=0;i<Len;++i)
        {
                AorB^=Arr[i];
        }
        int i=0;
        while(true)
        {
                if(AorB & 0x01<<i)
                        break;
                else
                        ++i;
        }

        int A=AorB,B=0;
        for(int j=0;j<Len;++j)
        {
                if(Arr[j] & 0x01<<i)
                        A^=Arr[j];
        }

        B=AorB^A;

        return make_pair(A,B);
}

// 一个整型数组里除了3个数字只出现一次之外，其他的数字都出现了两次。请写出程序找出这个只出现3次的数字
// 要求时间复杂度是O(n)，空间复杂度是O(1)
void FindOnlyThreeNum(int *Arr,int len,int *a,int *b,int *c)
{
        if (!Arr || len<=0)
                return;

        int Xor1[32];
        int Xor2[32];
        int Count1[32];
        int AxorBxorC=0;
        memset(Xor1,0,sizeof(Xor1));
        memset(Xor2,0,sizeof(Xor1));
        memset(Count1,0,sizeof(Xor1));
        for(int i=0;i<len;++i)
        {
                for(int j=0;j<32;j++)
                {
                        if(Arr[i] & (0x01<<j))
                        {
                                Xor1[j]^=Arr[i]; // Xor1数组中存储的为第j位是1的数的异或
                                Count1[j]++;
                        }
                        else
                                Xor2[j]^=Arr[i];// Xor2中存储的是第j位是0的数的异或
                }
                AxorBxorC^=Arr[i];
            
        }

        // 若有三个数不想等，则这三个数总有两个二进制位不全部相等
        int j=0;
        while(!(Xor1[j] && Xor2[j])) j++; // ｊ为三个书不完全相等的第一个数位
        if (Count1[j]%2) // 第j位是1的数有奇数个，说明此异或结果为一个不同的数
                *a=Xor1[j];
        else // 说明那个不同的数在Xor2中
                *a=Xor2[j];

        j++;
        // 同上
        while(!(Xor1[j] && Xor2[j])) j++;
        if (Count1[j]%2)
                *b=Xor1[j];
        else
                *b=Xor2[j];

        *c=AxorBxorC^(*a)^(*b);
}

// 正整数序列Q中的每个元素都至少能被正整数a和b中的一个整除，现给定a和b，需要计算出Q中的前几项，
// 例如，当a=3，b=5，N=6时，序列为3，5，6，9，10，12
void PrintQ(int a,int b,int N)
{
        int cnt=0;
        int MutipleA=a;
        int MutipleB=b;

        while(cnt<N)
        {
                if(MutipleA <MutipleB)
                {
                        cout<<MutipleA<<'\t';
                        MutipleA+=a;
                }
                else if(MutipleA > MutipleB)
                {
                        cout<<MutipleB<<'\t';
                        MutipleB+=b;
                }
                else
                {
                        cout<<MutipleA<<'\t';
                        MutipleA+=a;
                        MutipleB+=b;
                }
                cnt++;

        }
}

//题目：输入一个正数n，输出所有和为n连续正数序列。
//例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
void PrintCntiousSeq(int N)
{
        if(N<=0)
                return;
        int BeginNum=1,EndNum=2;
        int Sum=BeginNum+EndNum;
        while(BeginNum<=N/2)
        {
                if(Sum<N)
                        Sum += ++EndNum;
                else if(Sum>N)
                        Sum -= BeginNum++;
                else
                {
                        cout<<BeginNum<<'~'<<EndNum<<endl;
                        Sum -= BeginNum++;
                        Sum += ++EndNum;
                }
        }
}

int main()
{
        //int Arr[]={1,2,3,4,55,5,2,5,5,5,4,6,6,2,5,0};
        // cout<<"The Min Dist is:"<<MinDist(Arr,sizeof(Arr)/sizeof(int),2,4)<<endl;

        // int Arr[10]={1,2,3,4,5,6,7,8,9,10};
        // int Arr2[10];
        // cout<<"find Sum of Arr"<<endl;
        // ConstructMutiArr(Arr,10,Arr2);
        // for(int i=0;i<10;++i)
                // cout<<Arr2[i]<<"\t"<<flush;

        // int Arr[] = {1,2,3,3,2,1,4,5,5,6,6,7,7};
        // cout<<"The unique number is:"<<FindUniqNum(Arr,sizeof(Arr)/sizeof(int))<<endl;

        // int Arr[]={1,1,2,2,3,4,4,5,5,6,7,7,9,9};
        // pair<int,int> Res=FindTwoUniqNum(Arr,sizeof(Arr)/sizeof(int));
        // cout<<"The Two Different Num is:"<<Res.first<<" and "<<Res.second<<endl;
        //
        //PrintQ(3,5,6);
        //
        //PrintCntiousSeq(15);
        //
        int Arr[]={1,1,2,3,3,4,4,5,6,6,8,9,9};
        int a=0,b=0,c=0;
        FindOnlyThreeNum(Arr,sizeof(Arr)/sizeof(int),&a,&b,&c);
        cout<<"The Three num is :"<<a<<'\t'<<b<<'\t'<<c<<endl;

        return 0;
}
