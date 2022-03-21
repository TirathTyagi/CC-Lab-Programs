#include<iostream>
#include<string.h>
using namespace std;
int i,error;
void E(char *input);
void Eprime(char *input);
void T(char *input);
void Tprime(char *input);
void F(char *input);
int main()
{
    char input[10];
    i=0;
    error = 0;
    cout<<"Enter an expression: ";
    cin>>input;
    E(input);
    if(strlen(input) == i && error == 0)
    {
        cout<<"ACCEPTED";
    }
    else
    {
        cout<<"REJECTED";
    }
}
void E(char *input)
{
    T(input);
    Eprime(input);
}
void Eprime(char *input)
{
    if(input[i] == '+')
    {
        i++;
        T(input);
        Eprime(input);
    }
}
void T(char *input)
{
    F(input);
    Tprime(input);
}
void Tprime(char *input)
{
    if(input[i] == '*')
    {
        i++;
        F(input);
        Tprime(input);
    }
}
void F(char *input)
{
    if(isalnum(input[i]))
    {
        i++;
    }
    else if(input[i] == '(')
    {
        i++;
        E(input);
        if(input[i] == ')')
        {
            i++;
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