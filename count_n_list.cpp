using namespace std;

#include<iostream>

struct node {
	int info;
	node *next;
	
}*save,*front,*rear,*newptr,*ptr;

node *create_node(int);
void front_insert_node(node*);
int display();
void count_n(int);



int main()
{
	int info,disp,value,n;
	char choice;
	front = NULL;
	rear = NULL;
	
	do
	{
		cout<<"\nEnter info: ";
		cin>>info;
		ptr = create_node(info);
		if(ptr==NULL)
		{
			cout<<"\nNode cannot be entered";
			break;
		}
		
		
		front_insert_node(ptr);
		disp = display();
		
		
		cout<<"\nDo you want to insert more nodes (Y/N): ";
		cin>>choice;
	}while(choice=='y');
	
	disp = display();
	if(disp == 0)
		exit(0);
	cout<<"\nElement: ";
	cin>>n;
	count_n(n);
	return 0;
	
}

node *create_node(int data)
{
	newptr = new node;
	newptr -> info = data;
	newptr -> next = NULL;
	return newptr;
}


void front_insert_node(node *ptr)
{
	if(front==NULL)
	{
		front = ptr;
		rear = ptr;
	}
	else
    {
		ptr -> next = front;
		front = ptr;
    }
}

int display()
{
	if(front==NULL)
	{
		cout<<"\nNo node to display";
		return 0;
	}
	else
	{
		ptr = front;
		while(ptr != NULL)
		{
			cout<<ptr->info<<" -> ";
			ptr = ptr->next;
		}
		cout<<"!"<<endl;
		return 1;
	}
}

void count_n(int n)
{
	if(front==NULL)
	{
		cout<<"\nNo node to display";
		exit(0);
	}
	else
	{       int count = 0;
			ptr = front;
			while(ptr != NULL)
			{
				if(ptr -> info == n)
					count++;
				ptr = ptr->next;
			}
			cout<<"\nCount = "<<count<<endl;
	}
}