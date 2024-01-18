#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
struct node
{
	struct node* prev;
    struct node* next;
	int emp_id;
	double phno;
	float sal;
	char name[20], 
	dept[10],
    desg[20];

}*header,*temp,*temp1,*temp2,*temp3;
void create()
{
	int emp_id;
	double phno;
	float sal;
	char name[20], dept[10], desg[20];
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\n enter");
	printf("\n Emp_id : ");
	scanf("%d",&emp_id);
	printf("\n Name : ");
	scanf("%s",name);
	printf("\n Dept : ");
	scanf("%s",dept);
	printf("\n Desg : ");
	scanf("%s",desg);
	printf("\n Salary : ");
	scanf("%f",&sal);
	printf("\n Phone no. : ");
	scanf("%lf",&phno);
	temp->emp_id=emp_id;
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	strcpy(temp->desg,desg);
	temp->sal=sal;
	temp->phno=phno;
	count++;
}
void insertbeg()
{
	
	if(header==NULL)
	{
		create();
		header=temp;
		temp1=header;
	}

	else
	{
		create();
		temp->next=header;
		header->prev=temp;
		header=temp;
	}
}

void insertend()
{

	if(header==NULL)
	{
		create();
		header=temp;
		temp1=header;
	}

	else
	{
		create();
		temp1->next=temp;
		temp->prev=temp1;
		temp1=temp;
	}
}

void displaybeg()
{
	temp2=header;
	if(temp2==NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	else
	{
		printf("empid \tName \tDept \tDesg \tSalary \tPhone no.\n");
	while(temp2!=NULL)
	{
		printf("\n%d \t%s \t%s \t%s \t%.0f \t%.0lf \n",temp2->emp_id,temp2->name,temp2->dept, temp2->desg,temp2->sal, temp2->phno);
		temp2=temp2->next;
	}
	}
	
	printf("number of employees = %d",count);
}

int deleteend()
{
	temp3=header;
	if(temp3==NULL)
	{
		printf("list is empty\n");
		return 0;
	}
	if(temp3->next==NULL)
	{
		printf("\ndeleted successfully");
		free(temp3);
		header=NULL;
	}
	else
	{
		temp3=temp1;
		temp2=temp1->prev;
		temp2->next=NULL;
		printf("\ndeleted successfully");
		free(temp3);
		temp1=temp2;
	}
	count--;
	return 0;
}

int deletebeg()
{
	temp3=header;
	if(temp3==NULL)
	{
		printf("list is empty\n");
		return 0;
	}
	if(temp3->next==NULL)
	{
		printf("\ndeleted");
		free(temp3);
		header=NULL;
	}
	else
	{
		header=header->next;
		header->prev=NULL;
		printf("\ndeleted successfully");
		free(temp3);
	}
	count--;
	return 0;
}

void employerDetails()
{
	int ch,n,i;
	header=NULL;
	temp=temp1=NULL;
	while(1)
	{
		
	printf("\n                    --------Menu------------\n");
	printf("\n                     1.Enter no. of Emp");
	printf("\n                     2.Display details");
	printf("\n                     3.Insert at beginning");
	printf("\n                     4.Insert at end");
	printf("\n                     5.Delete at beginning");
	printf("\n                     6.Delete at end");
	printf("\n                     7.exit\n");
	printf("                    ----------------------\n");
		printf("\n enter choice : ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				printf("\n enter number of employees:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				insertend();
				break;
			case 2:
				displaybeg();
				break;
			case 3:
                insertbeg();
				break;
			case 4:
		        insertend();
				break;
			case 5:
				deletebeg();
				break;
			case 6:
				deleteend();
				break;
			case 7:
				exit(0);
			default:
				printf("wrong choice\n");
		}
	}
}
int main()
{
	employerDetails();
	return 0;
}
