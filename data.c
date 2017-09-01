#include "data.h"
node *head=NULL;
void addStu(int id,char *name,int age)
{
	node *p=(node *)malloc (sizeof(node));
	p->s.id=id;
	strcpy(p->s.name,name);
	p->s.age=age;
	p->next =NULL;
	if(head==NULL)
	{
		head=p;
		return ;
	}
	node *q=head;
	while(q->next!=NULL)
	
		q=q->next;
		q->next=p;
	return ;
}
void queryStu(int index,char *value)
{
	node *p=head;
	while(p!=NULL)
	{
			switch(index)
			{
				case 1:
					if(p->s.id==atoi(value))
					{
					printf("学号是%d\n",p->s.id);
					printf("姓名是%s\n",p->s.name);
					printf("年龄是%d\n",p->s.age);
					}

					break;
				case 2:
					if(p->s.name==value)
					{
					printf("学号是%d\n",p->s.id);
					printf("姓名是%s\n",p->s.name);
					printf("年龄是%d\n",p->s.age);
					}
					
					break;
				case 3:
					while(p!=NULL)
					{
					printf("学号是%d\n",p->s.id);
					printf("姓名是%s\n",p->s.name);
					printf("年龄是%d\n",p->s.age);
					p=p->next;
					}
					return ;
				
					



			}
			p=p->next;
		}
	return;	
	}
void updateStu(int id,int index,char *value)
{
	node *p = head;
	while(p!=NULL)
	{
		if(p->s.id==id)
			switch(index)
			{
				case 1:
					p->s.id=atoi(value);
					break;
				
				
				case 2:
					
					strcpy(p->s.name,value);
					break;
				case 3:
					p->s.age=atoi(value);
					
					break;
			}
		p=p->next;
	}
	return;
}
/*int search(int a)
{
	int k=1;
	node *p=head;
	while(p!=NULL)
	{
		if(p->s.id==a)
		{		return k;
		printf("%d",k);}
		k=k+1;
		p=p->next;
	}
	return 0;
}
node *searchnode(int a)
{
	int f=1;
	node *p=head;
	while(p!=NULL)
	{
		if(a==f)
		{
			return p;
		}
		p=p->next;
		f++;
	}
	return;
}



node *serchpos(int pow)
{
   int j=1;
	node *p=head;
	while(p!=NULL)
	{
		if(pow==j)
		{	return p;
			printf("%p\n",p);
		}
		j++;
		p=p->next;
		
		}
	return NULL;
}



void deletell(int a)	
{
	int pow=search(a); 
	node *p=serchpos(pow);
	if(p==NULL)
		return;
	node *q=serchpos(pow-1);
	if(NULL==q)
	{
	free(p);
	printf("1234567890\n");
	head=head->next;
	}
	else
		{
			q->next=p->next;
			free(p);
		}
	p=NULL;
	return;
}
*/



int searchpos(int id)
{
	int i=1;
	node *p=head;
	while(p!=NULL)
	{
	if(p->s.id==id)
		return i;
		i=i+1;
		p=p->next;
	}
	return;
}

node *searchnode(int pow)
{
	int i=1;
	node *p=head;
	while(p!=NULL)
	{
		if(i==pow)
			return p;
		i++;
		p=p->next;
	}
	return NULL;
}
	






void deletell(int id)
{
	int pow=searchpos(id);
	node *p=searchnode(pow);
	if(p==NULL)
	{
		free(p);
		
	}
	node *q=searchnode(pow-1);
	if(q==NULL)
	{

		head=head->next;
	}
	else
	{

		q->next=q->next;
	}
	free(p);
	p=NULL;
	return;
}










int writefile()
{
	FILE *p=fopen ("a.txt","wb");
	if(NULL==p)
			return -1;
	node *q=head;
	while(q!=NULL)
	{
		stu n=q->s;
		
		fwrite(&n,sizeof(n),1,p);
		q=q->next;
	}
	fclose(p);

	return 0;
}
int readfile()
{	
	FILE *p=fopen ("a.txt","rb");
	if(NULL==p)
		return -1;
		stu n;
	while(1)
	{
        fread( &n,sizeof(n),1,p);
		if(feof(p)!=0)
		break;
       // fread(&n,sizeof(n),1,p);
		addStu(n.id,n.name,n.age);
    }
	fclose(p);
	return 0;
}
