#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
enum GoodType{Food,Book,Medica,Other};
enum GoodSource{Import,Local};

vector<string> FoodKeyArr;
vector<string> BookKeyArr;
vector<string> MedicalKeyArr;
vector<string> ImportKeyWord;

void InitKeyWord()
{
        FoodKeyArr.push_back("chocolate");
        FoodKeyArr.push_back("chocolates");
        BookKeyArr.push_back("book");
        MedicalKeyArr.push_back("pills");
        ImportKeyWord.push_back("imported");
}

GoodType CheckGoodType(string &str)
{
        size_t indexL=0;
        size_t indexR=0;
        string Tmpstr;
        while(true)
        {
                indexR=str.find_first_of(' ',indexR);
                if (indexR == string::npos)
                        break;
                Tmpstr=str.substr(indexL,indexR-indexL);
                indexR=str.find_first_not_of(' ',indexR);
                indexL=indexR;
                
                for(vector<string>::iterator iter=FoodKeyArr.begin();iter!=FoodKeyArr.end();++iter)
                {
                        if(*iter == Tmpstr)
                                return Food;
                }

                for(vector<string>::iterator iter=BookKeyArr.begin();iter!=BookKeyArr.end();++iter)
                {
                        if(*iter == Tmpstr)
                                return Book;
                }

                for(vector<string>::iterator iter=MedicalKeyArr.begin();iter!=MedicalKeyArr.end();++iter)
                {
                        if(*iter == Tmpstr)
                                return Medica;
                }
        }
        return Other;
}

GoodSource CheckGoodSource(string &str)
{
        size_t indexL=0;
        size_t indexR=0;
        string Tmpstr;
        while(true)
        {
                indexR=str.find(' ',indexR);
                if(indexR==string::npos)
                        break;
                Tmpstr=str.substr(indexL,indexR-indexL);
                indexR=str.find_first_not_of(' ',indexR);
                indexL=indexR;
                
                for(vector<string>::iterator iter=ImportKeyWord.begin();iter!=ImportKeyWord.end();++iter)
                {
                        if(*iter == Tmpstr)
                                return Import;
                }
        }
        return Local;
}

double CheckGoodPrice(string &str)
{
        size_t indexL=str.size()-1;
        size_t indexR=str.size()-1;
        string Tmpstr;
        while (str[indexL]==' ')
        {--indexL;--indexR;}

        indexL=str.rfind(' ');
        Tmpstr=str.substr(indexL+1,indexR-indexL);
        
        return atof(Tmpstr.c_str());
}

double RoundTax(double tax)
{
        int IntPart=(int)(tax*10);
        double DealPart=tax*10-IntPart;

        if(DealPart<=0.25)
                return IntPart/10.0f;
        else if(DealPart>0.25 && DealPart<0.75)
                return (IntPart+0.5)/10.0f;
        else
                return (IntPart+1.0)/10.0f;
}

bool OutputRes(vector<string> &Input)
{
        if(Input.empty())
                return false;
        int i=0,RowCount=Input.size();

        GoodType Type;
        GoodSource Source;
        double TaxRate=0.0f;
        double Tax=0.0f;
        double TotalPrice=0.0f;
        double TotalTax=0.0f;
        double Price=0.0f;
        string Tmpstr;
        size_t Index;

        while(RowCount>i)
        {
                Tmpstr=Input.at(i);
                Type=CheckGoodType(Tmpstr);
                Source=CheckGoodSource(Tmpstr);
                Price=CheckGoodPrice(Tmpstr);

                TaxRate=0.0f;
                if (Type==Other)
                        TaxRate+=0.1;
                if (Source==Import)
                        TaxRate+=0.05;

                Tax=RoundTax(Price*TaxRate);
                TotalTax+=Tax;
                Price+=Tax;
                TotalPrice+=Price;

                Index=Tmpstr.rfind("at");
                cout<<setiosflags(ios::fixed)<<setprecision(2)<<Tmpstr.substr(0,Index-1)<<": "<<Price<<endl;
                
                i++;
        }

        cout<<"Sales Taxes:"<<TotalTax<<endl;
        cout<<"Total:"<<TotalPrice<<endl;
        return true;
}



int main()
{
        InitKeyWord();
        vector<string> Input;

        Input.push_back("1 book at 12.49");
        Input.push_back("1 music CD at 14.99");
        Input.push_back("1 chocolate bar at 0.85");

        /*Input.push_back("1 imported box of chocolates at 10.00");
        Input.push_back("1 imported bottle of perfume at 47.50");*/

        /*Input.push_back("1 imported bottle of perfume at 27.99");
        Input.push_back("1 bottle of perfume at 18.99");
        Input.push_back("1 packet of headache pills at 9.75");
        Input.push_back("1 box of imported chocolates at 11.25");*/

        if(!OutputRes(Input))
                cout<<"Invalid Input"<<endl;
        return 0;
}



