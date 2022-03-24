#include<iostream>
#include<string.h>
/*
 S->cAd
 A->ab|a
 */
using namespace std;
int num_prods;
string prods[100][100];
char nt[100];
int s=0,error=0;
void S(char *input);
void A(char *input);
void getProperGrammar()
{
    for(int x = num_prods-1;x>0;x--)
    {
        if(prods[x][0] == prods[x-1][0])
        {
            prods[x-1][2] = prods[x-1][2] +" | "+ prods[x][2];
            for(int l= 0;l<num_prods;l++) {
                for (int y = 0; y < 3; y++)
                {
                    if (l == x) {
                        prods[l][y] = "";
                    }
                }
            }
        }
    }
}
int main()
{
    cout<<endl;
    cout<<"------------DO NOT ENTER MULTIPLE PRODUCTIONS AT ONCE-----------";
    cout<<endl;
    cout<<"Enter the number of productions: "<<endl;
    cin>>num_prods;
    int i = 0;
    while(i<num_prods)
    {
        string lhs,rhs;
        cout<<"Enter the LHS of production: "<<endl;
        cin>>lhs;
        nt[i] = lhs.at(0);
        cout<<"Enter the RHS of production: "<<endl;
        cin>>rhs;
        if(lhs.at(0) == rhs.at(0)|| rhs.at(0) == 'e')
        {
            cout<<endl;
            cout<<"ERROR: The grammar is either left recursive or contains a null production: "<<endl;
            cout<<endl;
            return 0;
        }
        prods[i][0] = lhs;
        prods[i][1] = "-->";
        prods[i][2] = rhs;
        i++;
    }
    getProperGrammar();
    char input[10];
    cout<<"Enter the string:"<<endl;
    cin>>input;
    S(input);
    if(strlen(input) == s && error == 0)
    {
        cout<<"ACCEPTED";
    }
    else
    {
        cout<<"REJECTED";
    }
}
void S(char* input)
{
    if(input[s] == 'c')
    {
        s++;
        A(input);
        if(input[s] == 'd')
        {
            s++;
        }
        else
        {
            error = 1;
        }
    }
    else
    {
        error = 1;
    }
}
void A(char* input)
{
    if(input[s] == 'a')
    {
        s++;
        if(input[s] =='b')
        {
            s++;
        }
        else
        {
            error = 1;
        }
    }
    else if(input[s] == 'a')
    {
        s++;
    }
    else
    {
        error = 1;
    }
}