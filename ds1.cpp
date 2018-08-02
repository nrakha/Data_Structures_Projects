#include<iostream>
using namespace std;
int main()
{

int i,n,insert,position,ch;
cout<<"Enter no. of elements";
cin>>n;
int a[30];
cout<<"Enter numbers";
for(i=1;i<=n;i++)
{
cin>>a[i];
}
cout<<"Enter 1 to insert \n Enter 2 to search \n Enter 3 to Delete \n Enter 4 to display data";
cin>>ch;
if(ch==1)
{
cout<<"Enter number to insert";
cin>>insert;
cout<<"Enter the position , where to insert";
cin>>position;

i=n+1;
while(i!=position)
{
a[i]=a[i-1];
i--;

}
a[position]=insert;
for(i=1;i<=n+1;i++)
{
    cout<<a[i]<<endl;
}
}
else if(ch==2)
{
    int search,k;
    cout<<"Enter a number to search";
    cin>>search;
    for(i=1;i<=n;i++)
    {
        if (a[i]==search)
        {
      cout<<"position is"<<i;
      k=1;
      break;
        }
    }
    if(k=0)
    {
       cout<<"Element not Found";
    }
}



else if(ch==3)
{
    int del,temp;
    cout<<"Enter position of element to delete";
    cin>>del;
   i=n-1;
   while(i!=del)
   {
    temp=a[i];
    a[i]=a[i-1];
    a[i-1]=temp;
   }
    for(i=0;i<n-1;i++)
    {
      cout<<a[i]<<endl;
    }

}
return 0;
}
