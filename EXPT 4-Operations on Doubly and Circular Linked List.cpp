#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
node *head;
struct node1
{
    int info;
    node1 *next1;
};
node1 *last;
void create_node()
{

    int value;
    cout<<"Enter value you want to insert:"<<endl;
    cin>>value;
	node *temp=new node;
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insert_node2()
{
    int value;
    cout<<"Enter value you want to insert:"<<endl;
    cin>>value;
	node *temp=new node;
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;
	node *temp2=head;
	if(head==NULL)
    {
        head=temp;
        return;
    }
	while(temp2->next!= NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	temp->prev=temp2;

}

void insert_node3()
{
    int value;
    int position;
    int count1=1;
    cout<<"Enter position where you want to insert:"<<endl;
    cin>>position;
    if(position==1)
    {
        create_node();
        return;
    }
    if(position!=1 && head==NULL)
    {
        create_node();
        return;
    }
    cout<<"enter value you want to insert"<<endl;
    cin>>value;
	node *temp=new node;
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;
	node *temp2=head;
	while(temp2->next!=NULL && count1<position-1)
    {
        count1++;
        temp2=temp2->next;
    }
    if(count1==position-1)
    {
        if(temp2->next!=NULL)
        {
        temp->next=temp2->next;
        temp2->next->prev=temp;
        temp2->next=temp;
        temp->prev=temp2;
        }
        else
        {
             temp2->next=temp;
             temp->prev=temp2;
        }
    }
    else if(temp2->next==NULL && count1<position)
    {

       temp2->next=temp;
       temp->prev=temp2;
    }

}


void search()
{
    cout<<"enter the value of element to search in the linked list"<<endl;
    int n;
    cin>>n;
    int count=0;
    int c=0;
    node *temp1=head;
    while(temp1!= NULL)
	{
	    c++;
	    if(temp1->data==n)
        {
            count++;
            cout<<"element found at"<<c<<endl;
            break;
        }
		temp1=temp1->next;
	}
	if(count==0)
    {

        cout<<"no such element present"<<endl;
    }
}

void display()
{
	node *temp=head;
	while(temp!= NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


void del()
{
	 cout<<"enter the value of element to delete from the linked list"<<endl;
    int n;
    cin>>n;
    int count=0;
    node *temp1=head;
    if(head->data==n)
    {

        head=head->next;
        head->prev=NULL;
        delete(temp1);
        return;

    }
    while(temp1->next!= NULL)
	{
	    if(temp1->data==n)
        {
            count++;
            node *temp2=temp1->next;
           temp2->prev=temp1->prev;
           temp1->prev->next=temp2;
           delete(temp1);
            break;
        }
		temp1=temp1->next;
	}
	if(temp1->next==NULL && temp1->data==n)
    {
        temp1->prev->next=NULL;
        temp1->prev=NULL;
        delete(temp1);
    }
	if(count==0)
    {

        cout<<"no such element present"<<endl;
    }
}



class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        void sort();
        circular_llist()
        {
            last = NULL;
        }
};


void circular_llist::create_node(int value)
{
    node1 *temp=new node1;
    temp->info = value;
    if (last== NULL)
    {
        last = temp;
        temp->next1= last;
    }
    else
    {
        temp->next1 = last->next1;
        last->next1= temp;
        last = temp;
    }
}

void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node1 *temp= new node1;
    temp->info = value;
    temp->next1 = last->next1;
    last->next1= temp;
}

void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node1 *temp, *s;
    s = last->next1;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next1;
        if (s == last->next1)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new(struct node1);
    temp->next1 = s->next1;
    temp->info = value;
    s->next1= temp;
    if (s == last)
    {
        last=temp;
    }
}


void circular_llist::delete_element(int value)
{
    struct node1 *temp, *s;
    s = last->next1;
    if (last->next1== last && last->info == value)
    {
        temp = last;
        last = NULL;
        delete(temp);
        return;
    }
    if (s->info == value)
    {
        temp = s;
        last->next1 = s->next1;
        delete(temp);
        return;
    }
    while (s->next1!= last)
    {
        if (s->next1->info == value)
        {
            temp = s->next1;
            s->next1 = temp->next1;
            delete(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next1;
    }

    if (s->next1->info == value)
    {
        temp = s->next1;
        s->next1= last->next1;
        delete(temp);
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

void circular_llist::search_element(int value)
{
    struct node1 *s;
    int counter = 0;
    s = last->next1;
    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            cout<<"Element "<<value;
            cout<<" found at position "<<counter<<endl;
            return;
        }
        s = s->next1;
    }
    if (s->info == value)
    {
        counter++;
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

void circular_llist::display_list()
{
    node1 *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next1;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->info<<" ";
        s = s->next1;
    }
    cout<<s->info<<endl;
}

int main()
{
  cout<<"Enter 1 to do operations on doubly linked list:"<<endl;
  cout<<"Enter 2 to do operations on circular linked list:"<<endl;
  int c;
  cin>>c;
  if(c==1)
  {
	head=NULL;
	int choice;
    cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
    {
        case 1:create_node();
                break;
        case 2:insert_node2();
                break;
        case 3:insert_node3();
                break;
        case 4:del();
                break;
        case 5:search();
                break;
        case 6:display();
                break;
    }
    cout<<endl<<endl;
     cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    }
  }
  else if(c==2)
  {
      int choice, element, position;
    circular_llist cl;
	cout<<"Enter 1 to create node of circular linked list"<<endl;
     cout<<"Enter 2 to insert an element in beginning"<<endl;
    cout<<"Enter 3 to insert an element after the list"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
    {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.create_node(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            cl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            if (last == NULL)
            {
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            cout<<"Enter the element to be searched: ";
            cin>>element;
            cl.search_element(element);
            cout<<endl;
            break;
        case 6:
            cl.display_list();
            break;
        default:
            cout<<"Wrong choice"<<endl;
    }
   cout<<"Enter 1 to create node of circular linked list"<<endl;
     cout<<"Enter 2 to insert an element in beginning"<<endl;
    cout<<"Enter 3 to insert an element after the list"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    }

  }
}
