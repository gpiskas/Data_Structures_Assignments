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
#include <cstdlib>
#include "MyHeap.h"
#include "MyAVLTree.h"
using namespace std;

int main(void)
{

    MyAVLTree *avl_array[10];        //arxikopoihsh pinakwn se NULL
		avl_array[0]=NULL;
    	avl_array[1]=NULL;
    	avl_array[2]=NULL;
    	avl_array[3]=NULL;
    	avl_array[4]=NULL;
    	avl_array[5]=NULL;
    	avl_array[6]=NULL;
    	avl_array[7]=NULL;
    	avl_array[8]=NULL;
    	avl_array[9]=NULL;

    MyHeap *heap_array[10];        //arxikopoihsh pinakwn se NULL
		heap_array[0]=NULL;
    	heap_array[1]=NULL;
    	heap_array[2]=NULL;
    	heap_array[3]=NULL;
    	heap_array[4]=NULL;
    	heap_array[5]=NULL;
    	heap_array[6]=NULL;
    	heap_array[7]=NULL;
    	heap_array[8]=NULL;
    	heap_array[9]=NULL;



	ifstream myInput;				//dhmiourgia revmatwn epikoinwnias
	ofstream myOutput;

	char myBuffer[30];  // ypothetoume oti h ka8e entolh einai mikroterh apo 30 xarakthres
	int element_id,insert_value, size;		// element id onomazoume ton anangwristiko arithmo kathe edolhs px to "4" sthn edolh "STACK_CREATE 4"
	bool isMaxHeap;                         // isMaxHeap true h false.
									// insert value xrhsimopoieitai gia na kataxwrisoume times analogws me thn edolh(insert px)
	myInput.open("input.txt", ios::in);
	myOutput.open("output.txt", ios::out);

	cout<<"Input commands:"<< endl<< endl;			//eksodos sthn othoni gia efkolotero debug. Oles oi edoles kanoun cout gia ton idio logo.

	while(myInput.getline(myBuffer,30))				// ekxwrhsh twn edolwn mia mia while to txt den exei teleiwsei
	{

		cout<<myBuffer<<endl;							//ektypwsh ths edolhs pou molis diavasthke
		myOutput<<myBuffer<<"                      ";  //keno aplws gia kalyterh anagnwsh tou txt

//COMMANDS
	//HEAP COMMANDS ================================================================================
		if (strncmp(myBuffer,"HEAP_CREATE",11)==0) // HEAP_CREATE
		{
			element_id=myBuffer[12]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.

			int n=((strrchr(myBuffer,',')-(strchr(myBuffer,','))));         //n o arithmos twn noumerwn pou theloume na diavasoume ap to buffer anamesa sta kommata.
			char tempBuffer[30];                                            //proswrinh apo8hkefsh tou Buffer.
			(strncpy(tempBuffer,(strchr(myBuffer,',')+1),n));		        //strncpy(string,shmeioPrwtouKomma,n)
			size=atoi(tempBuffer);                                          //teliko size.

			isMaxHeap=atoi(strrchr(myBuffer,',')+1);						//Telefteo komma kai meta

			if (heap_array[element_id]==NULL)									//ama den yparxei hdh heap ekei, ftiakse...
			{
				heap_array[element_id]=new MyHeap(size,isMaxHeap);
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Heap with ID "<<element_id<<" already exists."<< endl;	//alliws error.
        }

		else if (strncmp(myBuffer,"HEAP_DESTROY",12)==0) //HEAP_DESTROY
		{
			element_id=myBuffer[13]-48;
			if (heap_array[element_id]==NULL)myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and can not be deleted."<< endl; //error ean to heap den yparxei...
			else 								//alliws to diagrafei.
			{
				delete heap_array[element_id];
				heap_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }

        else if (strncmp(myBuffer,"HEAP_INSERT",11)==0) //HEAP_INSERT
		{
			element_id=myBuffer[12]-48;
			insert_value = atoi(myBuffer+14);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 14 ews 29.
			if (heap_array[element_id]!=NULL && heap_array[element_id]->Insert(insert_value)!=-1)
			{
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist or full."<< endl;	//periptwsh pou h heap den exei dhmiourghthei/full
        }

        else if (strncmp(myBuffer,"HEAP_DELETETOP",14)==0) //HEAP_DELETETOP
		{
			element_id=myBuffer[15]-48;
			if (heap_array[element_id]==NULL) myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and deleteTop can not be performed."<<endl;		//den exei dhmiourghthei heap, kai apo katw einai adeio
			else if ((heap_array[element_id]!=NULL) && (heap_array[element_id]->GetSize()==0)) myOutput<<"ERROR! - Heap with ID "<<element_id<<" exists but is empty and deleteTop can not be performed."<<endl;
			else{
			    heap_array[element_id]->DeleteTop();    //alliws delete it
			    myOutput<<"OK"<< endl;
			}
		}

        else if (strncmp(myBuffer,"HEAP_READTOP",12)==0) //HEAP_READTOP
		{
			element_id=myBuffer[13]-48;
			if (heap_array[element_id]==NULL) myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and read can not be performed."<<endl;    //den exei dhmiourghthei heap, kai apo katw einai adeio
			else if ((heap_array[element_id]!=NULL) && (heap_array[element_id]->GetSize()==0)) myOutput<<"ERROR! - Heap with ID "<<element_id<<" exists but is empty and read can not be performed."<<endl;
			else myOutput<<heap_array[element_id]->ReadTop()<< endl;	//alliws read it
        }

        else if (strncmp(myBuffer,"HEAP_GETSIZE",12)==0) //HEAP_GETSIZE
		{
			element_id=myBuffer[13]-48;
			if (heap_array[element_id]==NULL) myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and has no size."<<endl;	//periptwsh pou to heap den exei dhmiourghthei
			else myOutput<<heap_array[element_id]->GetSize()<< endl;	//alliws getsize
        }

        else if (strncmp(myBuffer,"HEAP_PRINT",10)==0) //HEAP_PRINT
		{
			element_id=myBuffer[11]-48;
			if (heap_array[element_id]==NULL) myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and is not printable."<<endl;	//den exei dhmiourghthei heap, kai apo katw einai adeio
			else if ((heap_array[element_id]!=NULL) && (heap_array[element_id]->GetSize()==0)) myOutput<<"ERROR! - Heap with ID "<<element_id<<" exists but is empty and print can not be performed."<<endl;
			else{
			    int j=heap_array[element_id]->GetSize()+1, i=0;           //orizw ena pinaka megethous idiou me to max size tou heap mas
			    int contents[j];
			    heap_array[element_id]->GetContents(contents);          //kalw th get contents me orisma ton pinaka, wste na ton gemisoume me ta stoixeia tou heap
			    for(i=0;i<j;i++){
			        if(contents[i]==LONG_MIN || contents[i]==LONG_MAX) continue; //ama vrei tis times ths arxikopoihshs, tis agnooume k den typwnodai
			        myOutput<<contents[i]<<" ";
			    }
			    myOutput<<endl;
			}
        }

        else if (strncmp(myBuffer,"HEAP_SORT",9)==0) //HEAP_SORT
		{
			element_id=myBuffer[10]-48;
			if (heap_array[element_id]==NULL) myOutput<<"ERROR! - Heap with ID "<<element_id<<" does not exist and sort cannot be performed."<<endl;	//den exei dhmiourghthei heap, kai apo katw einai adeio
			else if ((heap_array[element_id]!=NULL) && (heap_array[element_id]->GetSize()==0)) myOutput<<"ERROR! - Heap with ID "<<element_id<<" exists but is empty and sort cannot be performed."<<endl;
			else{
			    heap_array[element_id]->Sort(); //alliws sort it
			    myOutput<<"OK"<< endl;
			}
        }

	//MYAVLTREE COMMANDS ================================================================================
        else if (strncmp(myBuffer,"AVLTREE_CREATE",14)==0) // AVLTREE_CREATE
		{
			element_id=myBuffer[15]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			if (avl_array[element_id]==NULL)									//ama den yparxei hdh avl ekei, ftiakse...
			{
				avl_array[element_id]=new MyAVLTree();
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Avl with ID "<<element_id<<" already exists."<< endl;	//alliws error.
        }

		else if (strncmp(myBuffer,"AVLTREE_DESTROY",15)==0) //AVLTREE_DESTROY
		{
			element_id=myBuffer[16]-48;
			if (avl_array[element_id]==NULL)myOutput<<"ERROR! - Avl with ID "<<element_id<<" does not exist and can not be deleted."<< endl; //error ean to avl den yparxei...
			else 								//alliws to diagrafei.
			{
				delete avl_array[element_id];
				avl_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }

        else if (strncmp(myBuffer,"AVLTREE_INSERT",14)==0) //AVLTREE_INSERT
		{
			element_id=myBuffer[15]-48;
			insert_value = atoi(myBuffer+17);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 17 ews 29.
			if (avl_array[element_id]!=NULL)
			{
				avl_array[element_id]->Insert(insert_value);
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Avl with ID "<<element_id<<" does not exist or full."<< endl;	//periptwsh pou to avl den exei dhmiourghthei/full
        }

        else if (strncmp(myBuffer,"AVLTREE_DELETE",14)==0) //AVLTREE_DELETE
		{
			element_id=myBuffer[15]-48;
			insert_value = atoi(myBuffer+17);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 17 ews 29.
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Avl with ID "<<element_id<<" does not exist and delete can not be performed."<<endl;		//den exei dhmiourghthei avl, kai apo katw einai adeio
			else if ((heap_array[element_id]!=NULL) && (heap_array[element_id]->GetSize()==0)) myOutput<<"ERROR! - Avl with ID "<<element_id<<" exists but is empty and delete can not be performed."<<endl;
			else{
			    if(avl_array[element_id]->Search(insert_value))     //yparxei h timh pou pame na diagrapsoume?
			    {
                    avl_array[element_id]->Delete(insert_value);    //delete it
                    myOutput<<"OK"<< endl;
			    }
			    else myOutput<<"ERROR! - Value "<<insert_value<<" does not exist in the tree with ID "<<element_id<<"."<< endl; //error otan h timh den yparxei
			}
		}

        else if (strncmp(myBuffer,"AVLTREE_SEARCH",14)==0) //AVLTREE_SEARCH
		{
			element_id=myBuffer[15]-48;
			insert_value = atoi(myBuffer+17);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 17 ews 29.
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Avl with ID "<<element_id<<" does not exist and search can not be performed."<<endl;		//den exei dhmiourghthei avl
			else{
			    if(avl_array[element_id]->Search(insert_value)) myOutput<<"OK - True"<< endl;
			    else myOutput<<"OK - False"<< endl;                                      //alliws return true/false
			}
		}

        else if (strncmp(myBuffer,"AVLTREE_GETSIZE",15)==0) //AVLTREE_GETSIZE
		{
			element_id=myBuffer[16]-48;
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Avl with ID "<<element_id<<" does not exist and has no size."<<endl;	//periptwsh pou to avl den exei dhmiourghthei
			else myOutput<<avl_array[element_id]->GetSize()<< endl;	//alliws getsize
        }

        else if (strncmp(myBuffer,"AVLTREE_INORDER",15)==0) //AVLTREE_INORDER
		{
			element_id=myBuffer[16]-48;
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Tree with ID "<<element_id<<" does not exist."<<endl;	//periptwsh pou to tree den exei dhmiourghthei
			else{
			    int j=avl_array[element_id]->GetSize(), i=0;
                int result[j];                                  //dhmiourgw pinaka result megethous iso me to megethos tou avl, kai ton gemizw kalwdas th synarthsh
			    avl_array[element_id]->Inorder(result);
			    for(i=0;i<j;i++){
			        myOutput<<result[i]<<" ";                   //sth synexeia ektypwnetai sto output.txt
			    }
			    myOutput<<endl;
			}
        }

        else if (strncmp(myBuffer,"AVLTREE_PREORDER",16)==0) //AVLTREE_PREORDER
		{
			element_id=myBuffer[17]-48;
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Tree with ID "<<element_id<<" does not exist."<<endl;	//periptwsh pou to tree den exei dhmiourghthei
			else{
			    int j=avl_array[element_id]->GetSize(), i=0;
                int result[j];                                  //dhmiourgw pinaka result megethous iso me to megethos tou avl, kai ton gemizw kalwdas th synarthsh
			    avl_array[element_id]->Preorder(result);
			    for(i=0;i<j;i++){
			        myOutput<<result[i]<<" ";                   //sth synexeia ektypwnetai sto output.txt
			    }
			    myOutput<<endl;
			}
        }

        else if (strncmp(myBuffer,"AVLTREE_POSTORDER",17)==0) //AVLTREE_INORDER
		{
			element_id=myBuffer[18]-48;
			if (avl_array[element_id]==NULL) myOutput<<"ERROR! - Tree with ID "<<element_id<<" does not exist."<<endl;	//periptwsh pou to tree den exei dhmiourghthei
			else{
			    int j=avl_array[element_id]->GetSize(), i=0;
                int result[j];                                  //dhmiourgw pinaka result megethous iso me to megethos tou avl, kai ton gemizw kalwdas th synarthsh
			    avl_array[element_id]->Postorder(result);
			    for(i=0;i<j;i++){
			        myOutput<<result[i]<<" ";                   //sth synexeia ektypwnetai sto output.txt
			    }
			    myOutput<<endl;
			}
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
