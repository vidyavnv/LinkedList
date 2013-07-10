using namespace std;

#include<iostream>

struct node {
                int info;
                node *next;

}*save,*front,*rear,*newptr,*ptr;

node *create_node(int);
void front_insert_node(node*);
int display();
node *find_node(int);
void delete_node(node *);


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
  do {
	  cout<<"\nNth value: ";
	  cin>>n;
	  ptr = find_node(n);
	  if(!ptr)
	  {
		  cout<<"\nNode not found";
		  exit(0);
	  }
	  cout<<"\nValue of find is: "<<ptr -> info;
	  delete_node(ptr);
	  cout<<endl;
	  disp = display();
	  if(disp == 0)
		  exit(0);
	  cout<<"\nFind more: ";
	  cin>>choice;
  }while(choice == 'y');
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

node *find_node(int n)
{
	int count = 1;
	node *curr;
	curr = new node;
	curr = front;
	if(curr == NULL)
	{
		cout<<"\nList empty";
		delete curr;
		exit(0);
	}
	else if(!curr -> next && n > 1)
	{
		cout<<"\nList contains only one element and n is greater than 1";
		delete curr;
		exit(0);
	}
	else 
	{
		 while(curr)
		 {
			if(count == n)
				return curr;
			else 
			{
				curr = curr -> next;
				count++;
			}
	     }
		 cout<<"\nNot found";
		exit(0);
	}
}

void delete_node(node *p)
{
	if(!p && !p->next)
		exit(0);
	node *q = p -> next;
	
	p -> info = q -> info;
	p -> next = q -> next;
	}
}
		
