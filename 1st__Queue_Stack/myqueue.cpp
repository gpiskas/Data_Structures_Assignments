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

#include "myqueue.h" 
#include <iostream>


myQueue::myQueue()
{
	list_head = NULL;
	list_tail = list_head;
}

myQueue::~myQueue()
{
	node *temp;
	while(list_head!=NULL)
	{
		temp = list_head->next;
		delete list_head;
		list_head = temp;
	}
}

void myQueue::insert(int y)
{
	node *neos;
    neos = new node;
    neos->number=y;
    if(list_tail!=NULL)
    {
    	list_tail->next = neos;
    	neos->next = NULL;
    	list_tail = neos;
    }    
	else if(list_head==NULL)
	{
		list_head = list_tail = neos;
		neos->next = NULL;
	}
}

void myQueue::del()
{
	node *temp;
	if(list_head==NULL) return; 
	temp = list_head->next;
	delete list_head;
	list_head = temp;
	return;
}

int myQueue::read()
{
	if(list_head==NULL) return 0; 
	return list_head->number;
}

int myQueue::getSize()
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
