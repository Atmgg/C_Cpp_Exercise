#include <iostream>
#include <memory.h>
#include <cstring>
#include <limits.h>
#include <stdexcept>
#include <assert.h>

using namespace std;

// дһ������,����ԭ���� int continumax(char *outputstr,char *intputstr)
// ����:
// ���ַ������ҳ�����������ִ�,����������ĳ��ȷ���,
// �����������ִ���������һ���������� outputstr ��ָ�ڴ档
//

int continumax(char *outputstr,char *intputstr)
{
        if (!intputstr)
                return 0;
        size_t StrLen=strlen(intputstr);

        unsigned int i=0;
        char *pChar=NULL;
        int TmpNumStrLen=0;
        int MaxNumStrLen=INT_MIN;
        while(i<StrLen)
        {
                if(intputstr[i]>'9' || intputstr[i]<'0')
                {
                        i++;
                        continue;
                }
                TmpNumStrLen=0;
                pChar=&intputstr[i];
                while(intputstr[i]<='9' && intputstr[i]>='0')
                {
                        TmpNumStrLen++;
                        i++;
                }

                if(TmpNumStrLen>MaxNumStrLen)
                {
                        MaxNumStrLen=TmpNumStrLen;
                        memcpy(outputstr,pChar,MaxNumStrLen);
                        outputstr[MaxNumStrLen]='\0';
                }
        }

        return MaxNumStrLen;
}


// ����ʵ���ַ�����ȫ�����㷨
void StrArrange(char *Str,char* pBegin)
{
        if (pBegin[0] == '\0')
        {
                cout<<Str<<endl;
                return;
        }

        char Tmp=0;
        for(int i=0;Str[i]!='\0';++i)
        {
                Tmp=Str[0];Str[0]=Str[i];Str[i]=Tmp;
                StrArrange(Str,pBegin+1);
                Tmp=Str[0];Str[0]=Str[i];Str[i]=Tmp;
        }
}

// ��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b
//
char FindFirstOneChar(const char *str)
{
        size_t str_len=strlen(str);
        if(!str_len)
                return '\0';
        int hash_table[256];
        memset(hash_table,0,sizeof(hash_table));

        for(size_t i=0;i<str_len;++i)
        {
                hash_table[str[i]]++;
        }

        for(size_t i=0;i<str_len;++i)
        {
                if(hash_table[str[i]]==1)
                        return str[i];
        }
        return '\0';
}

// ���ִ�A�ʹ�B�е�������Ӵ�
void FindMaxSubString(char* strA,char *strB,char **SubStr)
{
    unsigned int lenA=strlen(strA);
    unsigned int lenB=strlen(strB);
    char *p = strA;
    char *q = strB;
    int j=0;
    int k=0;
    int maxlen = lenA<lenB?lenB:lenA;
    int MaxSubLen=0;
    char *Tmp = (char*)malloc((maxlen+1)*sizeof(char));
    if(*SubStr==NULL)
    {
        *SubStr = (char*)malloc((maxlen+1)*sizeof(char));
    }
    while(*p != '\0')
    {
        j=0;
        while(*p != *(q+j) && *(q+j)!='\0')
        {
            j++;
        }
            
        k=0;
        while((*(p+k) == *(q+j+k))&&(*(q+j+k)!='\0')&&(*(p+k)!='\0') )
        {
            Tmp[k++]= *(p+k);
        }
        Tmp[k]='\0';
        if(k>MaxSubLen)
        {
            MaxSubLen=k;
            strcpy(*SubStr,Tmp);
        }
        p++;
         
    } 
    
    free(Tmp);
    
}


// ���������ַ����������е��ַ��͸�������ͬ���Ǿͽ��������ַ���ƥ�䣬���磺abcda��adabc,
// ���ڳ��ֵ��ַ�����������ͬ��ֻ��˳��ͬ�������������ַ�����ƥ���
bool isStrMatch(const char* str1,const char* str2)
{
        if(!str1 && !str2) return true;
        else
        {
                size_t len_str1=strlen(str1);
                size_t len_str2=strlen(str2);
                if(len_str1!=len_str2)
                        return false;
                map<char,int> char_map;
                map<char,int>::iterator iter=char_map.end();
                for(int i=0;i!=len_str1;++i)
                {
                        iter=char_map.find(str1[i]); // ע�⣺i�����ĸ�ֵ���ܷ���i������У�����ᱨ��
                        if(iter != char_map.end())
                                iter->second+=1;
                        else
                                char_map.insert(make_pair(str1[i],1));
                }
                
                for(int i=0;i!=len_str2;++i)
                {
                        iter=char_map.find(str2[i]);
                        if( iter == char_map.end()) 
                                return false;
                        else
                        {
                                if(iter->second==1)
                                        char_map.erase(iter);
                                else
                                        iter->second-=1;
                        }

                }

                return char_map.empty()?true:false;
        }

}

// �ַ�����ת
const char* Rotate(char *start,char *end)
{
        const char *pStart=start;
        char tmp=0;
        while(start<end)
        {
                tmp=*start;
                *start=*end;
                *end=tmp;
                start++,end--;
        }
        return pStart;
}

/********�˺���������һ���ַ������ƣͣ����ӣ����λ*******/
const char* LeftMove(char *Str,size_t len,unsigned int MoveStep)
{
        if(len!=strlen(Str))
                throw("Error:length parameter is wrong!");
        Rotate(Str,Str+MoveStep-1);
        Rotate(Str+MoveStep,Str+len-1);
        Rotate(Str,Str+len-1);
        return Str;
}

// ������һ���ַ���ת��Ϊ������ֵ
int Str2Num(const char* str)
{
        if (!str)
                throw runtime_error("Error:string is empty");
        size_t i=0;
        int num=0;
        int prefix=1;
        while(str[i]==' '|| str[i]=='\t')i++;
        if(str[i]=='-')
                prefix=-1;
        else if(str[i]=='+')
                prefix=1;
        else if(str[i]>='0' && str[i] <='9')
        {
                prefix=1;
                num+=str[i]-'0';
        }
        else 
                throw runtime_error("Error:ilegal string");
        i++;

        while(str[i]>='0' && str[i] <='9')
        {
                num*=10;
                num+=str[i++]-'0';

                assert(num>=0); // �����ж��Ƿ����
        }
        num*=prefix;

        return num;
}

const char* strcpy_own(char *dest,const char *src)
{
        assert(dest && src);

        size_t i=0;
        size_t j=0;
        while( (dest[i++]=src[j++]) != '\0');

        return dest;
}

// �˺����������str2�Ƿ���str2�е�������ĸ
bool isStr1HasAllAlphaOfStr2(const char *str1,const char *str2)
{
        bool VecStr[128];
        size_t num=0;
        memset(VecStr,0,sizeof(VecStr));
        size_t len_str1=strlen(str1);
        size_t len_str2=strlen(str2);
        for(size_t i=0;i<len_str2;++i) // �ö̵��ַ�����Ϊ��������������ݿ�ʹƽ��ʱ�临�ӶȽ���һЩ
        {
                if (!VecStr[str1[i]])
                {
                        VecStr[str1[i]]=true;
                        num++;
                }
        }

        for(size_t i=0;i<len_str1;++i)
        {
                if (VecStr[str2[i]])
                {
                        num--;
                        VecStr[str2[i]]=false;
                }
                if(!num)
                        return true;
        }
        return !num?true:false; // ��str1����str2��������ĸʱ��num����Ϊ0
}

bool strstr_own(const char* str,const char* substr)
{
        size_t str_len=strlen(str);
        size_t sub_str_len=strlen(substr);
        if(str_len<sub_str_len)
                return false;
        for(size_t i=0;i<str_len-sub_str_len+1;++i) // ע��i�����һ��λ��
        {
                for(size_t j=0;j<sub_str_len;++j)
                {
                        if(str[i+j]!=substr[j])
                                break;
                        if(j==sub_str_len-1)
                                return true;
                }
        }
        return false;
}


int main()
{
        // char A[]="abcd12345ed125ss123456789";
        // char B[30];
        // cout<<continumax(B,A)<<'\t'<<B<<endl;
       
        // char Str[]="abcde";
        // StrArrange(Str,Str);

        // char str[30];
        // while(cout<<"input str:" && cin>>str)
                // cout<<"this first one char is:"<<FindFirstOneChar(str)<<endl;

        /********************************
        char str1[30];
        char str2[30];
        char *substr=NULL;
        while(cout<<"str1:"<<endl && cin>>str1)
        {
                cout<<"str2:";
                cin>>str2;
                FindMaxSubString(str1,str2,&substr);
                cout<<boolalpha<<substr<<endl;
                free(substr);substr=NULL;
        }
        *********************************/


        /********************************
        char str1[20];
        char str2[20];
        while(cout<<"input str1:"&& cin>>str1)
        {
                cout<<"input str2:";
                cin>>str2;
                cout<<boolalpha<<isStrMatch(str1,str2)<<endl;
        }
        **********************************/

        /*********************************
        char str[20];
        unsigned int step=0;
        memset(str,0,sizeof(str));
        while(cin>>str)
        {
                cout<<"input step:"<<endl;
                cin>>step;
                LeftMove(str,strlen(str),step);
                cout<<str<<endl;
        }
        **********************************/

        /*********************************
        string str1("");
        string str2("");
        while(cout<<"str1:"<<endl && cin>>str1)
        {
                cout<<"str2:"<<endl;
                cin>>str2;
                cout<<boolalpha<<isStr1HasAllAlphaOfStr2(str1.c_str(),str2.c_str())<<endl;
        }
        cin.clear();
        **********************************/

        /*********************************
        char str[30];
        char substr[30];
        while(cout<<"input str:" && cin>>str)
        {
                cout<<"input substr:";
                cin>>substr;
                cout<<boolalpha<<strstr_own(str,substr)<<endl;
        }
        **********************************/

        return 0;
}
