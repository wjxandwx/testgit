#ifndef _DATA_H
#define _DATA_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stu
{
	int id;
	char name[64];
	int age;
}stu;

typedef struct _node
{
	stu s;
	struct _node *next;
}node;

void addStu(int id,char *name,int age);
void updataStu(int id,int index,char *value);
void queryStu(int index,char *value);
void deletell(int a);
node *serchpos(int pow);
int search(int a);
int writefile();
int readfile();

