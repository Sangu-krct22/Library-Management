#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void admin();
void viewbook();
void stu();
void reportbook();

struct books
{
	char bname[100];
	int bid,bkflag;
}book[100];

struct student
{
	char sname[100],spass[100];
	int sid,rbook;
	
}student[100];

int bcount=1,bookid=101,scount=1,sid=1001;

void viewbook()
{
	printf("\n");
	for(int i=1;i<bcount;i++)
	{
	    printf("Book name: %s\t",book[i].bname);
		printf("Book Id : %-10d\t",book[i].bid);
		if(book[i].bkflag==1)
		{
			printf("Available\n");
		}
		else
		{
		    printf("Not Available\n");
		}
	}	
	printf("\n"); 
}
void admin()
{
	int n,m,f;
	char a[100],b[100];
	printf("Enter user name :");
	scanf("%s",a);
	printf("Enter password :");
	scanf("%s",b);
	if(strcmp(a,"Library")==0&&strcmp(b,"Mylibrary")==0)
	{
		while(1)
		{
			printf("\n----------> ADMIN <------------\n\n");
			printf("1.Add Book\n2.View Book\n3.reportbook \n4.Logout\n\nEnter your choice : ");
			scanf("%d",&n);
			if(n==1)
			{
				printf("\nHow many Books add :");
				scanf("%d",&m);
				for(int i=1;i<=m;i++)
				{
					printf("\nEnter Book name :");
					scanf("%s",book[bcount].bname);
					book[bcount].bkflag=1;
					book[bcount].bid=bookid++;
					printf("Your Book id is : %d\n",book[bcount++].bid);			
				}
			}
			else if(n==2)
			{
				viewbook();
			}
			else if(n==3)
			{
				reportbook();
			}
			else if(n==4)
			{
				break;
			}
			else
			{
				printf("\nInvalid choice...\n");
			}
		}
	}
	else
	{
		printf("\nUser name or password is wrong...\n\n");
	}
}
void stu()
{
	int n,a,m,c,e;
	char b[100],d[100];
	while(1)
	{
		printf("\n-------------> STUDENT LOGIN <--------------\n\n");
		printf("1.Sign In\n2.Sign Up\n3.Exit\n\nEnter your choice : ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\nEnter user id: ");
			scanf("%d",&a);
			printf("Enter password: ");
			scanf("\n%s",b);
			if(student[a-1000].sid==a&&strcmp(b,student[a-1000].spass)==0)
			{
				while(1)
				{
					printf("1.View Book\n2.Lend Book\n3.Return Book\n4.Log out\n\nEnter your choice : ");
					scanf("%d",&m);
					if(m==1)
					{
						viewbook();
					}
					else if(m==2)
					{
						printf("Enter Book name: ");
						scanf("%s",d);
						printf("Enter Book id : ");
						scanf("%d",&c);
						if(student[a-1000].rbook==0&&book[c-100].bkflag==1)
						{
							student[a-1000].rbook=book[c-100].bid;
							book[c-100].bkflag=0;
							printf("%s Lend Successfully...\n",book[c-100].bname);
						}
						else if(student[a-200].rbook!=0)
						{
						 	printf("Already you are Lend...\n");
						}
						else
						{
							printf("Book Not Available...\n");
					    }
					}
					else if(m==3)
					{
						e=student[a-1000].rbook;
						if(student[a-1000].rbook!=0&&book[e-100].bkflag==0)
						{
							printf("Book name : %8s\n",book[e-100].bname);
							book[e-100].bkflag=1;
							student[a-1000].rbook=0;
							printf("Return Successfully..\n");
						}
						else
						{
							printf("Your not get Book...\n");
						}
					}
					else if(m==4)
					{
						break;
					}
					else
					{
						printf("Invalid choice...\n");
					}
				}
			}
			else
			{
				printf("\nUser id or password is wrong...\n\n");
			}
		}
		
		else if(n==2)
		{
			printf("\nEnter Member name :");
			scanf("%s",student[scount].sname);
			printf("Enter Password :");
			scanf("%s",student[scount].spass);
			student[scount].sid=sid++;
			printf("Your Membership id is : %d\n",student[scount].sid);
			student[scount++].rbook=0;
		}
		else if(n==3)
		{
			break;
		}
		else
		{
			printf("\nInvalid choice...\n");
		}
	}
}
void reportbook()
{
	FILE *fp1;
	fp1=fopen("out.txt","w");
	for(int i=1;i<bcount;i++)
	{
	    fprintf(fp1,"Book name: %s\t",book[i].bname);
		fprintf(fp1,"Book Id : %-10d\t",book[i].bid);
		if(book[i].bkflag==1)
		{
			fprintf(fp1,"Available\n");
		}
		else
		{
		    fprintf(fp1,"Not Available\n");
		}
		printf("report done");
		printf("\n");
	}	
//	fclose(fp1);
}

int main()
{   
    
	int n;
	while(1)
	{
		printf("\n1.Admin\n2.Student\n3.Exit\n\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
		{
	
			admin();
			break;
		}
		case 2:
		{
			stu();
			break;
			
		}
		case 3:
		{
		    break;
			break;
		}
		default:
		{
			printf("\nInvalid choice");
		}
		}
		printf("\n         Thank you        ");
	}
}	