#include<iostream>
using namespace std;
struct node
    {
    int data;
    struct node *next;
    };
int main()
{
    struct node *f1,*f2,*start,*ptr,*ptr1,new1;
    f1=new node;
    cout<<"Enter Data";
    cin>>f1->data;
    f1->next=NULL;
    start=f1;
    int i=0,t=0;
    ptr=start;
    int flag=0;

while(i<5)
{
    f1=new node;
    cin>>f1->data;
    f1->next=NULL;
    ptr->next=f1;
    ptr=ptr->next;
    i++;
}
cout<<"\n";
ptr=start;

while(ptr!=NULL)
{
    cout<<ptr->data;
    if((ptr->data)==1)
    {
        flag=flag+1;
    }
    ptr=ptr->next;

}
cout<<"\n \n";

cout<<flag;
return 0;
}
