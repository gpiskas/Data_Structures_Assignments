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
#include "MyHash.h"
#include "MyGraph.h"
using namespace std;

int main(void)
{
    MyHash *hash_array[10];        //arxikopoihsh pinakwn se NULL
		hash_array[0]=NULL;
    	hash_array[1]=NULL;
    	hash_array[2]=NULL;
    	hash_array[3]=NULL;
    	hash_array[4]=NULL;
    	hash_array[5]=NULL;
    	hash_array[6]=NULL;
    	hash_array[7]=NULL;
    	hash_array[8]=NULL;
    	hash_array[9]=NULL;

    MyGraph *graph_array[10];        //arxikopoihsh pinakwn se NULL
		graph_array[0]=NULL;
    	graph_array[1]=NULL;
    	graph_array[2]=NULL;
    	graph_array[3]=NULL;
    	graph_array[4]=NULL;
    	graph_array[5]=NULL;
    	graph_array[6]=NULL;
    	graph_array[7]=NULL;
    	graph_array[8]=NULL;
    	graph_array[9]=NULL;


	ifstream myInput;			        	//dhmiourgia revmatwn epikoinwnias
	ofstream myOutput;

	char myBuffer[30];                      // ypothetoume oti h ka8e entolh einai mikroterh apo 30 xarakthres
	int element_id,insert_value;	    	// element id onomazoume ton anangwristiko arithmo kathe edolhs px to "4" sthn edolh "STACK_CREATE 4"
                                            // insert value xrhsimopoieitai gia na kataxwrisoume times analogws me thn edolh(insert px).
	myInput.open("input.txt", ios::in);
	myOutput.open("output.txt", ios::out);

	cout<<"Input commands:"<< endl<< endl;			//eksodos sthn othoni gia efkolotero debug. Oles oi edoles kanoun cout gia ton idio logo.

	while(myInput.getline(myBuffer,30))				// ekxwrhsh twn edolwn mia mia while to txt den exei teleiwsei
	{
		cout<<myBuffer<<endl;							//ektypwsh ths edolhs pou molis diavasthke
		myOutput<<myBuffer<<"                      ";  //keno aplws gia kalyterh anagnwsh tou txt

//COMMANDS
	//HASH COMMANDS ================================================================================
		if (strncmp(myBuffer,"HASH_CREATE",11)==0) // HASH_CREATE
		{
			element_id=myBuffer[12]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			insert_value = atoi(myBuffer+14);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 14 ews 29. Megethos tou hash map
			if (hash_array[element_id]==NULL)									//ama den yparxei hdh hash ekei, ftiakse...
			{
				hash_array[element_id]=new MyHash(insert_value);
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Hash with ID "<<element_id<<" already exists."<< endl;	//alliws error.
        }

		else if (strncmp(myBuffer,"HASH_DESTROY",12)==0) //HASH_DESTROY
		{
			element_id=myBuffer[13]-48;
			if (hash_array[element_id]==NULL)myOutput<<"ERROR! - Hash with ID "<<element_id<<" does not exist and can not be deleted."<< endl; //error ean to hash den yparxei...
			else 								//alliws to diagrafei.
			{
				delete hash_array[element_id];
				hash_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }

        else if (strncmp(myBuffer,"HASH_INSERT",11)==0) //HASH_INSERT
		{
			element_id=myBuffer[12]-48;
			insert_value = atoi(myBuffer+14);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 14 ews 29.
			if (hash_array[element_id]!=NULL)
			{
			    int rtrnVal=hash_array[element_id]->Insert(insert_value);
			    if(rtrnVal==-2) myOutput<<"ERROR! - Duplicate element detected."<< endl;
			    else if(rtrnVal==-1) myOutput<<"ERROR! - Hash table is full."<< endl;
			    else myOutput<<"OK - probes: "<<rtrnVal<< endl;
			}
			else myOutput<<"ERROR! - Hash with ID "<<element_id<<" does not exist."<< endl;	//periptwsh pou h hash den exei dhmiourghthei
        }

        else if (strncmp(myBuffer,"HASH_SEARCH",11)==0) //HASH_SEARCH
		{
			element_id=myBuffer[12]-48;
			insert_value = atoi(myBuffer+14);									//string to int me xrhsh ths atoi(). Olo to string ap th thesh 14 ews 29.
			if (hash_array[element_id]!=NULL)
			{
			    int probes=0;
			    bool rtrnVal=hash_array[element_id]->Search(insert_value, &probes);
			    if(!rtrnVal) myOutput<<"ERROR! - Element "<<insert_value<<" not found."<< endl;
			    else myOutput<<"OK - probes: "<<probes<< endl;
			}
			else myOutput<<"ERROR! - Hash with ID "<<element_id<<" does not exist."<< endl;	//periptwsh pou h hash den exei dhmiourghthei
        }

        else if (strncmp(myBuffer,"HASH_GETSIZE",12)==0) //HASH_GETSIZE
		{
			element_id=myBuffer[13]-48;
			if (hash_array[element_id]==NULL) myOutput<<"ERROR! - Hash with ID "<<element_id<<" does not exist and has no size."<<endl;	//periptwsh pou to hash den exei dhmiourghthei
			else myOutput<<hash_array[element_id]->GetSize()<< endl;	//alliws getsize
        }

        else if (strncmp(myBuffer,"HASH_GETMAXSIZE",15)==0) //HASH_GETMAXSIZE
		{
			element_id=myBuffer[16]-48;
			if (hash_array[element_id]==NULL) myOutput<<"ERROR! - Hash with ID "<<element_id<<" does not exist and has no size."<<endl;	//periptwsh pou to hash den exei dhmiourghthei
			else myOutput<<hash_array[element_id]->GetMaxSize()<< endl;	//alliws getsize
        }

	//GRAPH COMMANDS ================================================================================
        else if (strncmp(myBuffer,"GRAPH_CREATE",12)==0) // GRAPH_CREATE
		{
			element_id=myBuffer[13]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			insert_value = atoi(myBuffer+15);
			if (graph_array[element_id]==NULL)									//ama den yparxei hdh graph ekei, ftiakse...
			{
				graph_array[element_id]=new MyGraph(insert_value);
				myOutput<<"OK"<< endl;
			}
			else myOutput<<"ERROR! - Graph with ID "<<element_id<<" already exists."<< endl;	//alliws error.
        }

		else if (strncmp(myBuffer,"GRAPH_DESTROY",13)==0) //GRAPH_DESTROY
		{
			element_id=myBuffer[14]-48;
			if (graph_array[element_id]==NULL)myOutput<<"ERROR! - Graph with ID "<<element_id<<" does not exist and can not be deleted."<< endl; //error ean to graph den yparxei...
			else 								//alliws to diagrafei.
			{
				delete graph_array[element_id];
				graph_array[element_id]=NULL;
				myOutput<<"OK"<< endl;
			}
        }

        else if (strncmp(myBuffer,"GRAPH_INSERTEDGE",16)==0) //GRAPH_INSERTEDGE
		{
			element_id=myBuffer[17]-48;
			int v,u,w;
			int komma1=strchr(myBuffer,',')-myBuffer;
			int komma2=strchr(myBuffer+komma1+1,',')-myBuffer;
			int komma3=strchr(myBuffer+komma2+1,',')-myBuffer;
			char tempBufferV[30];
			strncpy(tempBufferV,myBuffer+komma1+1,komma2-komma1);
            v=atoi(tempBufferV);

            char tempBufferU[30];
            strncpy(tempBufferU,myBuffer+komma2+1,komma3-komma2);
            u=atoi(tempBufferU);

            char tempBufferW[30];
            strcpy(tempBufferW,myBuffer+komma3+1);
            w=atoi(tempBufferW);

            int maxNodeNum=graph_array[element_id]->GetNumNodes();
			if (graph_array[element_id]!=NULL)
			{
			    if(v<maxNodeNum && u<maxNodeNum)
			    {
			        graph_array[element_id]->InsertEdge(v,u,w);
                    myOutput<<"OK"<< endl;
			    }
				else myOutput<<"ERROR! - Index out of bounds."<< endl;
			}
			else myOutput<<"ERROR! - Graph with ID "<<element_id<<" does not exist."<< endl;	//periptwsh pou to graph den exei dhmiourghthei/full
        }

        else if (strncmp(myBuffer,"GRAPH_MINSPANTREE",17)==0) //GRAPH_MINSPANTREE
		{
			element_id=myBuffer[18]-48;
			if (graph_array[element_id]==NULL) myOutput<<"ERROR! - Graph with ID "<<element_id<<" does not exist and minSpanTree can not be performed."<<endl;		//den exei dhmiourghthei graph
			else
			{
			    int graphSize=graph_array[element_id]->GetNumNodes();
			    int contents[graphSize*2];
                int cost=graph_array[element_id]->MinSpanTree(contents);
                myOutput<<"OK: Cost = "<<cost<<". ";

                for(int i=0;i<graphSize;i++)
                {
                    if(contents[i]==-1) continue;
                    myOutput<<"<"<<i<<","<<contents[i]<<","<<contents[graphSize+i]<<">, ";
                }
                myOutput<<endl;
			}
		}

        else if (strncmp(myBuffer,"GRAPH_SHORTESTPATHS",19)==0) // GRAPH_SHORTESTPATHS
		{
			element_id=myBuffer[20]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			insert_value = atoi(myBuffer+22);
			if (graph_array[element_id]==NULL) myOutput<<"ERROR! - Graph with ID "<<element_id<<" does not exist and shortestPaths can not be performed."<<endl;		//den exei dhmiourghthei graph
			else
			{
			    int graphSize=graph_array[element_id]->GetNumNodes();
			    int contents[graphSize];
                graph_array[element_id]->ShortestPaths(insert_value,contents);
                myOutput<<"OK: ";

                for(int i=0;i<graphSize;i++)
                {
                    if(contents[i]==-1) continue;
                    myOutput<<"<"<<i<<","<<contents[i]<<">, ";
                }
                myOutput<<endl;
			}
        }

        else if (strncmp(myBuffer,"GRAPH_DFS",9)==0) // GRAPH_DFS
		{
			element_id=myBuffer[10]-48;											//-48 (logw ascii) gia na metatrepsoume to char se int.
			insert_value = atoi(myBuffer+12);
			if (graph_array[element_id]==NULL) myOutput<<"ERROR! - Graph with ID "<<element_id<<" does not exist and DFS can not be performed."<<endl;		//den exei dhmiourghthei graph
			else
			{
			    int graphSize=graph_array[element_id]->GetNumNodes();
			    int contents[graphSize];
			    int treeCounter=1;
                graph_array[element_id]->DFS(insert_value,contents);
                myOutput<<"OK: (see below)";
                for(int i=0;i<graphSize;i++)
                {
                    if(contents[i]<0)
                    {
                        if(contents[i]==-100)
                        {
                           myOutput<<endl<<"                                   TREE "<<treeCounter<<": "<<0<<", ";  //gia na vgei katw apo to OK. - an exoume -100 shmainei node=0
                        }
                        else
                        {
                            myOutput<<endl<<"                                   TREE "<<treeCounter<<": "<<-contents[i]<<", ";  //gia na vgei katw apo to OK.
                        }
                        treeCounter++;
                    }
                    else
                    {
                        myOutput<<contents[i]<<", ";
                    }

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
