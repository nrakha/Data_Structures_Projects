#include<iostream>
#include<string>
using namespace std;
int a,b,i, top=0;
char str[20], stack[20];

void push(char ch)
{
        stack[top]=ch;
        top=top+1;

}
void pop()
{
if(top == 0)
cout<<"wrong expr";
else
top--;
}

int main()
{
cin>>str;
for(i=0;str[i] != '\0';i++)
{
    if(str[i]=='(')
    {
        push('(');
    }
    else if(str[i]==')')
    {
        pop();
    }
    else
    {
        cout<<"Wrong";
    }
}
if(top > 0)
cout<<"wrong";
return 0;
}

