#include<iostream>
using namespace std;
struct node
    {
    int data;
    struct node *next;
    };
int main()
{
    struct node *f1,*f2,*start,*ptr,*ptr1;
    f1=new node;
    cout<<"Enter Data";
    cin>>f1->data;
    f1->next=NULL;
    start=f1;
    int i=0,t=0;
    ptr=start;

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
    ptr=ptr->next;
}
cout<<"\n";
ptr=start;



    while(ptr->next->data!=3)
    {
        ptr=ptr->next;
        t=1;
    }
    ptr1=ptr->next;
    ptr->next=ptr->next->next;
    delete ptr1;

if(t=0)
{

    cout<<"Number not found";
}
else
    {
while(ptr!=NULL)
{
    cout<<ptr->data;
    ptr=ptr->next;
}
    }
return 0;
}
