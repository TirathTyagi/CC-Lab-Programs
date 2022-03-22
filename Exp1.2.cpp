#include<iostream>
using namespace std;
int main()
{
    int regex[5][2] ={{0,1},
                      {2,3},
                      {4,0},
                      {1,2},
                      {3,4}};
    string a;
    cin>>a;
    int k = 0;
    int currstat = 0;
    for(int i = 0;i<a.length();i++)
    {
        cout<<"q"<<currstat<<"->";
        char h = a.at(i);
        int bin = h-48;
        currstat = regex[currstat][bin];
    }
    cout<<"q"<<currstat<<endl;
    if(currstat == 0|| a.find('E')!= std::string::npos)
    {
        cout<<"String is accepted";
    }
    else
    {
        cout<<"String is rejected";
    }
}