#include<iostream>
using namespace std;
int main()
{
    cout<<"PLEASE NOTE '&' HERE MEANS NULL";
    cout<<endl;
    cout<<endl;
    int num_prods;
    cout<<"Enter number of productions: ";
    cin>>num_prods;
    string prod[num_prods+6][3];
    int i = 0;
    while(i<num_prods)
    {
        string lhs,rhs;
        cout<<"Enter LHS Non Terminal:"<<endl;
        cin>>lhs;
        cout<<"Enter RHS:"<<endl;
        cin>>rhs;
        prod[i][0] = lhs;
        prod[i][1] = "-->";
        prod[i][2] = rhs;
        i++;
        cout<<endl;
    }
    cout<<endl;
    cout<<"--------------REGULAR GRAMMAR----------------";
    cout<<endl;
    for (int x = 0; x < num_prods; x++) {
        for (int y = 0; y < 3; y++) {
            cout << prod[x][y];
        }
        cout << endl;
    }
    int extra_prods = 0;
    for(int x = 0;x<(num_prods+6);x++)
    {
        string a = prod[x][2];
        string b = prod[x][0];
        if(b[0] == a[0])
        {
            int s = a.find('|');
            if(s!=-1)
            {
                string beta = a.substr(s + 1);
                string alpha = a.substr(1, s-1);
                prod[num_prods+extra_prods][0] = b+"'";
                prod[num_prods+extra_prods][1] = "-->";
                prod[num_prods+extra_prods][2] = alpha+prod[num_prods+extra_prods][0]+"|&";
                prod[x][2] = beta+prod[num_prods+extra_prods][0];
                extra_prods++;
            }
        }
    }
    cout<<endl;
    cout<<"---------------------ELIMINATING LEFT RECURSION---------------------";
    cout<<endl;
    for (int x = 0; x < (num_prods+extra_prods); x++) {
        for (int y = 0; y < 3; y++) {
            cout << prod[x][y];
        }
        cout << endl;
    }
}