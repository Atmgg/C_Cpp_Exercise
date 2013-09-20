#include <iostream>

using namespace std;

int FindOneCount(int x)
{
        int count=0;
        while(x)
        {
                count++;
                x &= (x-1);
        }
        return count;
}

int main()
{
        cout<<"please input the num"<<endl;
        int number=0;
        cin>>number;
        cout<<"the number is:"<<hex<<number<<endl;
        cout<<"the count of one in that number is:"<<FindOneCount(number)<<endl;

        return 0;

}
