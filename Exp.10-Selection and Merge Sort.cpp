#include<iostream>
using namespace std;
class sort
{
  int size,arr[100];
  public:
    void input()
    {
      cout<<"Enter size of array: ";
      cin>>size;
      cout<<"Enter Array Elements : ";
    	for(int i=0;i<size;i++)
    	{
    		cin>>arr[i];
    	}
    }
    void selectionsort()
    {
      int min,loc,temp;
      for(int i=0;i<size;i++)
      {
        min=arr[i];
        loc=i;
        for(int j=i+1;j<size;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                loc=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[loc];
        arr[loc]=temp;
      }
    }
    sort merge(sort s1,sort s2)
    {
      sort s3;
      s3.size=s1.size+s2.size;
      int i=0,j=0,k=0;
      while(i<s1.size && j<s2.size)
      {
        if(s1.arr[i] < s2.arr[j])
          s3.arr[k++] = s1.arr[i++];
        else
          s3.arr[k++] = s2.arr[j++];
      }
      while (i < s1.size)
      {
        s3.arr[k++]=s1.arr[i++];
      }
      while (j < s2.size)
      {
        s3.arr[k++]=s2.arr[j++];
      }
      return s3;
    }
    void display()
    {
      for(int i=0; i<size; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    }
};
int main()
{
  sort s1;
  s1.input();
  sort s2;
  s2.input();
  s1.selectionsort();
  s2.selectionsort();
  cout<<"Array1 after sorting: ";
  s1.display();
  cout<<"\nArray2 after sorting: ";
  s2.display();
  sort s3;
  s3=s3.merge(s1,s2);
  cout<<"\nArray after merging above arrays: ";
  s3.display();
}
