#include <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node* link;
};

struct node* root=NULL;
int len;
//root=(struct node*)malloc(sizeof(struct node));

//--------------------------------------------------------
void append() //function to append a element at the end of linked list
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter node data:");
 scanf("%d", &temp->data);
 temp->link=NULL;
  if (root == NULL)
  {
   root=temp;   //for the first element in linked list.
  }
  else
  {
   struct node* p;
   p= root;
   while (p->link!=NULL)//to insert at the end of linked list.
   {
    p=p->link;
   }
   p->link=temp;
  }
}
//----------------------------------------------------------
int length() // counting the number of elements in the list
{
 int count=0;
 struct node* temp;
 temp=root;
  while(temp!=NULL)
  {
   temp = temp->link;
   count++;
  }
 return count;
}
//----------------------------------------------------------
void addatbegin()
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter the node data:");
 scanf("%d",&temp->data);
 temp->link=NULL;
   if(root==NULL)
   {
     root=temp;
   }
   else
   {
     temp->link= root;//right side connection first for replacing the address
     root=temp;//left side connection second for entering the data..if you do this first you loose the whole data in linked list
   }
}
//----------------------------------------------------------
void delete()
{
 struct node* temp;
 int loc;
 printf("Enter location to delete:\n");
 scanf("%d",&loc);
  if(loc>length())
  {
   printf("INVALID LOCATION \n \n");
  }
  else if (loc==1)
  {
   temp=root;
   root=temp->link; //assigning the nodes link into the node which we want to enter
   temp->link=NULL;
   free(temp);
  }
  else
  {
   struct node* p=root,*q;
   int i=1;
   while(i<loc-1)
   {
     p=p->link;
     i++;
   }
   q=p->link;
   p->link=q->link;
   q->link=NULL;
   free(q);
  }
}
//----------------------------------------------------------
void display()//for printing the final Linklist
{
    struct node *temp;
    temp=root;
    if (temp == NULL)
    {
     printf("List is empty \n \n");
    }
    while(temp!=NULL)
    {
    printf("%d -->",temp->data);
    temp=temp->link;
    }
    printf("\n\n");
}
//----------------------------------------------------------
void addatPosition()
{
 struct node* temp,*p;
 int loc,len,locat,i=1;
 temp=(struct node*)malloc(sizeof(struct node));
     printf("enter node data:");
     scanf("%d", &temp->data);
     temp->link=NULL;
 printf("Enter location:");
 scanf("%d",&locat);
 loc=locat-1;
 len=length();
  if(loc>len)
    {
     printf("Invalid location \n");
    }
  else
    {
     p=root;
     while(i<loc)
     {
      p=p->link;
      i++;
     }
     temp->link = p->link;//right connection to connect the link to next element
     p->link=temp;//left connecetion to connect the data to pervious element
    }
}
//----------------------------------------------------------
int main()
{
 int a,b,i,c,d;
 printf("\n||_____Welcome to Linked List_____||\n\n");
 printf("How many elements you wish to enter: \n");
 scanf("%d",&b);  //taking elements for the linked list
  for(i=1;i<=b;i++)//reads data for the limit entered
   {
     append();  //entering the elements at the end of list
     display();
   }
 printf("\n-------Operations on Linked List-------\n\n"); 
 while(1)
 {
  printf("1.INSERT more elements \n");
  printf("2.DELETE elements \n");
  printf("3.SORT elements \n");
  printf("4.DISPLAY the Linked List \n");
  printf("5.EXIT\n");
  scanf("%d",&a);
   switch(a)
    {
    case 1: printf("Where would you like to enter the element in the Linked List: \n");
            printf("1.At the Begining \n");
            printf("2.At the End \n");
            printf("3.At the specific Position \n");
            scanf("%d",&c);
            switch(c)
             {
               case 1: addatbegin();
                       display();
                       break;
               case 2: append();
                       display();
                       break;
               case 3: addatPosition();
                       display();
                       break;
             }
            break;
    case 2: printf("Delected List:\n");
            delete();
            break;
   // case 3:
    case 4: printf("Linked list: \n\n");
            display();
            break;
    case 5: printf("Thank you for using LINKED LIST\n");
            printf("Confirm you wanna EXIT?\n yes(1)/no(0)");
            scanf("%d",&d);
            if(d==1)
            {
             exit(0);
            }
            break;
    }
 }
  
}

 
