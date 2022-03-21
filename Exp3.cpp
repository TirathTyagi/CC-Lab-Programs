#include<iostream>
#include <fstream>

using namespace std;
int main()
{
    int num_prods;
    cout<<"Enter number of productions: ";
    cin>>num_prods;
    string prod[num_prods][3];
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
    for(int x = num_prods-1;x>0;x--)
    {
        if(prod[x][0] == prod[x-1][0])
        {
            prod[x-1][2] = prod[x-1][2] +" | "+ prod[x][2];
            for(int l= 0;l<num_prods;l++) {
                for (int y = 0; y < 3; y++)
                {
                    if (l == x) {
                        prod[l][y] = "";
                    }
                }
            }
        }
    }
    fstream file;
    file.open("productions.txt",ios::out);
    if(!file)
    {
        cout<<"ERROR CREATING FILE";
        return 0;
    }
    for (int x = 0; x < num_prods; x++) {
        for (int y = 0; y < 3; y++) {
            if(prod[x][y] =="")
            {
                continue;
            }
            cout << prod[x][y];
            file<<prod[x][y];
        }
        file<<"\n";
        cout << endl;
    }
}