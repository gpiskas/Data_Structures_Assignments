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

#include <iostream>
#include <fstream>
#include <cstring>
#include "mystack.h"
#include "myqueue.h"
using namespace std;

main()
{
	myStack *stack_array[10];        //arxikopoihsh pinakwn se NULL
		stack_array[0]=NULL;
    	stack_array[1]=NULL;
    	stack_array[2]=NULL;
    	stack_array[3]=NULL;
    	stack_array[4]=NULL;
    	stack_array[5]=NULL;
    	stack_array[6]=NULL;
    	stack_array[7]=NULL;
    	stack_array[8]=NULL;
    	stack_array[9]=NULL;
    	
	myQueue *queue_array[10];
		queue_array[0]=NULL;
    	queue_array[1]=NULL;
    	queue_array[2]=NULL;
    	queue_array[3]=NULL;
    	queue_array[4]=NULL;
    	queue_array[5]=NULL;
    	queue_array[6]=NULL;
    	queue_array[7]=NULL;
    	queue_array[8]=NULL;
    	queue_array[9]=NULL;
    	
    	
	ifstream myInput;				//dhmiourgia revmatwn epikoinwnias
	ofstream myOutput; 
	char myBuffer[30];  // ypothetoume oti h ka8e entolh einai mikroterh apo 30 xarakthres
	int element_id,push_value;		// element id onomazoume ton anangwristiko arithmo kathe edolhs px to "4" sthn edolh "STACK_CREATE 4"
									// push value xrhsimopoieitai gia na apothikefsoume ton arithmo pou vazoume me thn push
	myInput.open("input.txt", ios::in);
	myOutput.open("output.txt", ios::out);

	cout<<"Input commands:"<< endl<< endl;			//eksodos sthn othoni gia efkolotero debug. Oles oi edoles kanoun cout gia ton idio logo.
	
	while(myInput.getline(myBuffer,30))				// ekxwrhsh twn edolwn mia mia while to txt den exei teleiwsei
	{
		
		cout<<myBuffer<<endl;							//ektypwsh ths edolhs pou molis diavasthke
		myOutput<<myBuffer<<"                      ";  //keno aplws gia kalyterh anagnwsh tou txt
		
//COMMANDS
	//STACK COMMANDS ================================================================================ 
		if (strncmp(myBuffer,"STACK_CREATE",12)==0) //STACK_CREATE
		{
			element_id=myBuffer[13]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			if (stack_array[element_id]==NULL)									//ama den yparxei hdh stack ekei, ftiakse...
			{
				stack_array[element_id]=new myStack();
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Stack with ID "<<element_id<<" already exists."<< endl;	//alliws error.
        }
        
		else if (strncmp(myBuffer,"STACK_DESTROY",13)==0) //STACK_DESTROY
		{
			element_id=myBuffer[14]-48;
			if (stack_array[element_id]==NULL)myOutput<<"ERROR! - Stack with ID "<<element_id<<" does not exist and can not be deleted."<< endl;
												//error ean to stack den yparxei...
			else 								//alliws to diagrafei.
			{
				delete stack_array[element_id];
				stack_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }
        
        else if (strncmp(myBuffer,"STACK_PUSH",10)==0) //STACK_PUSH
		{
			element_id=myBuffer[11]-48;
			push_value = atoi(myBuffer+13);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 13 ews 29.
			if (stack_array[element_id]!=NULL)								
			{
				if (push_value>=0)											//elegxos gia thetiko arithmo kai push...
				{
				stack_array[element_id]->push(push_value);
				myOutput<<"OK"<< endl;
				}
				else myOutput<<"ERROR! - Push value is not greater than zero."<< endl;		//alliws error.
			}
			else myOutput<<"ERROR! - Stack with ID "<<element_id<<" does not exist and data can not be pushed."<< endl;	//periptwsh pou h stack den exei dhmiourghthei
        }
        
        else if (strncmp(myBuffer,"STACK_POP",9)==0) //STACK_POP
		{
			element_id=myBuffer[10]-48;
			if (stack_array[element_id]==NULL) myOutput<<"ERROR! - Stack with ID "<<element_id<<" does not exist and pop can not be performed."<<endl;		//den exei dhmiourghthei stack, kai apo katw einai adeia
			else if ((stack_array[element_id]!=NULL) && (stack_array[element_id]->getSize()==0)) myOutput<<"ERROR! - Stack with ID "<<element_id<<" exists but is empty and pop can not be performed."<<endl;
			else myOutput<<stack_array[element_id]->pop()<< endl;    //alliws pop it
		}

        else if (strncmp(myBuffer,"STACK_READ",10)==0) //STACK_READ
		{
			element_id=myBuffer[11]-48;
			if (stack_array[element_id]==NULL) myOutput<<"ERROR! - Stack with ID "<<element_id<<" does not exist and read can not be performed."<<endl;    //den exei dhmiourghthei stack, kai apo katw einai adeia
			else if ((stack_array[element_id]!=NULL) && (stack_array[element_id]->getSize()==0)) myOutput<<"ERROR! - Stack with ID "<<element_id<<" exists but is empty and read can not be performed."<<endl;
			else myOutput<<stack_array[element_id]->read()<< endl;	//alliws read it
        }
        
        else if (strncmp(myBuffer,"STACK_GETSIZE",13)==0) //STACK_GETSIZE
		{
			element_id=myBuffer[14]-48;
			if (stack_array[element_id]==NULL) myOutput<<"ERROR! - Stack with ID "<<element_id<<" does not exist and has no size."<<endl;	//periptwsh pou h stack den exei dhmiourghthei
			else myOutput<<stack_array[element_id]->getSize()<< endl;	//alliws getsize
        }
        
	//QUEUE COMMANDS ================================================================================ *H ylopoihsh einai paromoia me tis edoles gia stack, giafto o sxoliasmos einai perittos*
		else if (strncmp(myBuffer,"QUEUE_CREATE",12)==0) //QUEUE_CREATE
		{
			element_id=myBuffer[13]-48;											
			if (queue_array[element_id]==NULL)
			{
				queue_array[element_id]=new myQueue();
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Queue with ID "<<element_id<<" already exists."<< endl;
        }
        
		else if (strncmp(myBuffer,"QUEUE_DESTROY",13)==0) //QUEUE_DESTROY
		{
			element_id=myBuffer[14]-48;											
			if (queue_array[element_id]==NULL) myOutput<<"ERROR! - Queue with ID "<<element_id<<" does not exist and can not be deleted."<< endl;
			else 
			{
				delete queue_array[element_id];
				queue_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }
        
        else if (strncmp(myBuffer,"QUEUE_INSERT",12)==0) //QUEUE_INSERT
		{
			element_id=myBuffer[13]-48;											
			push_value = atoi(myBuffer+15);									
			if (queue_array[element_id]!=NULL)								
			{
				if (push_value>=0)
				{
				queue_array[element_id]->insert(push_value);
				myOutput<<"OK"<< endl;
				}
				else myOutput<<"ERROR! - Insert value is not greater than zero."<< endl;	
				
				
				
			}
			else myOutput<<"ERROR! - Queue with ID "<<element_id<<" does not exist and data can not be inserted."<< endl;
        }
        
        else if (strncmp(myBuffer,"QUEUE_DELETE",12)==0) //QUEUE_DELETE
		{
			element_id=myBuffer[13]-48;											
			if (queue_array[element_id]==NULL) myOutput<<"ERROR! - queue with ID "<<element_id<<" does not exist and delete can not be performed."<<endl;
			else if ((queue_array[element_id]!=NULL) && (queue_array[element_id]->getSize()==0)) myOutput<<"ERROR! - Queue with ID "<<element_id<<" exists but is empty and delete can not be performed."<<endl;
			else
			{
				queue_array[element_id]->del();
				myOutput<<"OK"<< endl;
			}
		}

        else if (strncmp(myBuffer,"QUEUE_READ",10)==0) //QUEUE_READ
		{
			element_id=myBuffer[11]-48;										
			if (queue_array[element_id]==NULL) myOutput<<"ERROR! - Queue with ID "<<element_id<<" does not exist and read can not be performed."<<endl;
			else if ((queue_array[element_id]!=NULL) && (queue_array[element_id]->getSize()==0)) myOutput<<"ERROR! - Queue with ID "<<element_id<<" exists but is empty and read can not be performed."<<endl;
			else myOutput<<queue_array[element_id]->read()<< endl;	
        }
        
        else if (strncmp(myBuffer,"QUEUE_GETSIZE",13)==0) //QUEUE_GETSIZE
		{
			element_id=myBuffer[14]-48;
			if (queue_array[element_id]==NULL) myOutput<<"ERROR! - Queue with ID "<<element_id<<" does not exist and has no size."<<endl;
			else myOutput<<queue_array[element_id]->getSize()<< endl;
        }
        
	//GENERIC COMMANDS ================================================================================ 
        else if (strcmp(myBuffer,"")==0) //KENO
		{
			myOutput<<""<< endl;	
        }
        
        else  //OTIDHPOTE ALLO
		{
			myOutput<<"ERROR! - Invalid Command."<<endl;
        }
	}
//TELOS COMMANDS 

	myInput.close();			//kleisimo twn revmatwn epikoinwnias me ton eksw kosmo
	myOutput.close();
	system("pause");
}
