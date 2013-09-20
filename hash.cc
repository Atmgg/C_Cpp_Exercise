#include <ext/hash_map>
#include <iostream>
using namespace __gnu_cxx;
using namespace std;

int main()
{
        hash_map<const char*,int> HashMap;
        HashMap.insert(std::make_pair("str1",321));
        cout<<HashMap.size()<<endl;
        if(HashMap.end()!=HashMap.find("str1"))
        {
                cout<<"value of \"123\" is:"<<HashMap["str1"]<<endl;
        }
        return 0;
}
