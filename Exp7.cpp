#include<iostream>
#include<string.h>
using namespace std;
int i,error;
void S(char* input);
void A(char* input);
void Aprime(char* input);
void Adprime(char* input);
void B(char* input);
void Bprime(char* input);
void C(char* input);
void Cprime(char* input);
int main()
{
    char input[10];
    cout<<"Enter expression: ";
    cin>>input;
    i=0;
    error=0;
    S(input);
    if(strlen(input)==i && error==0)
    {
        cout<<"ACCEPTED";
    }
    else
    {
        cout<<"REJECTED";
    }
}
void S(char *input)
{
    A(input);
    B(input);
    C(input);
}
void A(char *input)
{
    if(input[i]=='a')
    {
        i++;
        Aprime(input);
    }

}
void Aprime(char* input)
{
    if(input[i] =='b')
    {
        i++;
        Adprime(input);
    }
}
void Adprime(char *input)
{
    A(input);
}
void B(char* input)
{
    if(input[i] =='b')
    {
        i++;
        Bprime(input);
    }
}
void Bprime(char* input)
{
    C(input);
}
void C(char* input)
{
    if(input[i] == 'c')
    {
        i++;
        Cprime(input);
    }
}
void Cprime(char* input)
{
    C(input);
}