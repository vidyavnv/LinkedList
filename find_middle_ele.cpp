using namespace std;

#include<iostream>

struct node {
	int info;
	node *next;
	
}*save,*front,*rear,*newptr,*ptr;

node *create_node(int);
void front_insert_node(node*);
int display();
void find_middle();



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
	find_middle();
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

void find_middle()
{
	if(front == NULL)
	{
		cout<<"\nList empty";
		exit(0);
	}
	else 
	{
		node *slow = front;
		node *fast = front;
	    while(fast -> next)
		{
			slow = slow -> next;
			fast = fast -> next -> next;
	    }
		cout<<"\nMiddle element is: "<<slow -> info<<endl;
    }
}
