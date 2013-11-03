/*
*  Data Structures Assignments
*  Copyright (C) 2013  George Piskas
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License along
*  with this program; if not, write to the Free Software Foundation, Inc.,
*  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*  Contact: geopiskas@gmail.com
*/

#include "mystack.h"
#include <iostream>
using namespace std;


myStack::myStack()
{
      list_head=NULL;  
}

myStack::~myStack()
{
	node *temp;
	while(list_head!=NULL)
	{
		temp = list_head->next;
		delete list_head;
		list_head = temp;
	}
}

void myStack::push(int y)
{
    node *neos;
    neos = new node;
    neos->number=y;
    neos->next = list_head;
    list_head = neos;
    
}

int myStack::pop()
{
    node *temp;
    int tempnumber;
    if(list_head==NULL) return 0;
    tempnumber=list_head->number;
    temp = list_head->next;
    delete list_head;
    list_head = temp;
    return (tempnumber);
    
}

int myStack::read()
{
    if(list_head==NULL) return 0;
    return (list_head->number);
}

int myStack::getSize()
{
	int counter=0;
    node *temp;
    temp = list_head;
    while(temp!=NULL)
    {
		counter++;
		temp = temp->next;
	}
	return counter;
}
