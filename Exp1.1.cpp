#include<iostream>
using namespace std;
int main()
{
    int regex[5][2] ={{1,2},
                      {1,2},
                      {3,2},
                      {4,4},
                      {4,4}};
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
    if(currstat == 1||currstat == 2||currstat == 3)
    {
        cout<<"String is accepted";
    }
    else
    {
        cout<<"String is rejected";
    }
}