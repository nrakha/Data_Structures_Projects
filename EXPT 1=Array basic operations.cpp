#include<iostream>
#include<stdlib.h>
using namespace std;
class arr
{
  int arr[100],i,n,pos,val,key;
  public:
  void create();
  void ins();
  void del();
  void search();
  void display();
};
void arr::create()
{
  cout<<"Enter the size of array: ";
  cin>>n;
  cout<<"Enter the elements for the array: ";
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
}
void arr::ins()
{
  cout<<"Enter the position of element to be inserted: ";
  cin>>pos;
  cout<<"Enter the element to be inserted: ";
  cin>>val;
  for(i=n-1;i>=pos;i--)
  {
    arr[i+1]=arr[i];
  }
  arr[pos]=val;
  n=n+1;
}
void arr::del()
{
  cout<<"Enter the position of the element to be deleted: ";
  cin>>pos;
  val=arr[pos];
  for(i=pos;i<n-1;i++)
  {
    arr[i]=arr[i+1];
  }
  n=n-1;
  cout<<"The deleted element is = "<<val<<endl;
}
void arr::search()
{
  cout<<"Enter the element to be searched: ";
  cin>>key;
  for(i=0;i<n;i++)
  {
    if(arr[i]==key)
    {
      cout<<"The element is present at position "<<i<<endl;
      break;
    }
  }
  if(i==n)
  {
    cout<<"The element does not exist\n";
  }
}
void arr::display()
{
  cout<<"The array elements are: ";
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  arr a;
  a.create();
  int choice;
  do{
    cout<<"\nEnter your choice:\n";
    cout<<"1=Insert"<<endl;
    cout<<"2=Delete"<<endl;
    cout<<"3=Search"<<endl;
    cout<<"4=Display"<<endl;
    cout<<"5=Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1: a.ins();
              break;
      case 2: a.del();
              break;
      case 3: a.search();
              break;
      case 4: a.display();
              break;
      case 5: exit(0);
              break;
      default: cout<<"Invalid choice";
               break;
    }
  } while(choice!=5);
}
