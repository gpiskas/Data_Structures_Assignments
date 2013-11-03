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

#include <cstdlib>                  //aparaithto include gia xrhsh tou NULL pointer
#include <climits>                  //aparaithto include gia xrhsh tou INT_MAX;
#include "MyGraph.h"

MyGraph::MyGraph(int n)
{
    maxNodes=n;
    currentEdges=0;
    DFScounter=0;

    graph = new node*[maxNodes];
    for (int i=0;i<maxNodes;i++)
    {
      graph[i]=NULL;        //arxikopoihsh
    }
}

MyGraph::~MyGraph()
{
    for (int i=0;i<maxNodes;i++)    //gia kathe stoixeio node tou graph
    {
      node* temp;
      node* tempNext;
      if(graph[i]!=NULL)
      {
          temp=graph[i];
          tempNext=graph[i];
          while(temp!=NULL)         //diegrapse OLH thn alysida ksekinwdas ap thn arxh ews na peseis se NULL.
          {
             tempNext=temp;
             delete tempNext;
             temp=temp->next;
          }
      }
    }
    delete[] graph;                 //diegrapse kai ton arxiko pinaka
}

void MyGraph::InsertEdge(int x,int y,int w)
{

    int allowInsert=1;      //xrhsimopoieitai parakatw se elegxo

    if(graph[x]==NULL && graph[y]==NULL)    //periptwsh pou kai oi 2 akmes xrhsimopoioudai gia prwth fora
    {
        graph[x]=newnode(y,w);
        graph[y]=newnode(x,w);
        currentEdges++;     //+1 edge!
    }
    else
    {
        allowInsert=searchEdge(x,y);        //elegxei ama yparxei hdh to edge gia na mh to ksanavalei
    }
    if(allowInsert==0)
    {
        if(graph[x]==NULL && graph[y]!=NULL) //periptwsh pou mia mono akmh xrhsimopoioudai gia prwth fora (x)
        {
            graph[x]=newnode(y,w);
            getLastNode(graph[y])->next=newnode(x,w);
        }
        else if(graph[x]!=NULL && graph[y]==NULL) //periptwsh pou mia mono akmh xrhsimopoioudai gia prwth fora (y)
        {
            graph[y]=newnode(x,w);
            getLastNode(graph[x])->next=newnode(y,w);
        }
        else                                     //periptwsh pou kai oi 2 akmes periexoun hdh alysida. vazoume to stoixeio sto telos ths alysidas kai twn 2
        {
            getLastNode(graph[y])->next=newnode(x,w);
            getLastNode(graph[x])->next=newnode(y,w);
        }
        currentEdges++;     //+1 edge!
    }
}

int MyGraph::GetNumNodes()
{
    return maxNodes;
}

int MyGraph::GetNumEdges()
{
    return currentEdges;
}

int MyGraph::searchEdge(int x,int y)
{
        node* temp=graph[x];
        while(temp!=NULL)       //oso den exoume pesei se NULL proxwra vathytera sthn alysida twn nodes.
        {
            if(temp->connectedTo==y) return 1; //found
            temp=temp->next;
        }
    return 0;   //not found
}


void MyGraph::DFS(int x,int *contents)
{
    int doneCounter=0;                  //otan oloi ginoun visited, prepei =maxNodes
    int root=x;                         //starting point
    int Q[maxNodes];                    //kwdikos node: 0 not visited, 1 in progress, 2 visited
    for(int i=0;i<maxNodes;i++)
    {
        Q[i]=0;     // 0 not visited se ola
    }

    while(doneCounter<=maxNodes)
    {
        doDFS(root,contents,Q);    //dfs gia to dothen root.

        //kanw arnhtiko to prwto stoixeio gia na kserw poio einai to root sth main.
        //an einai node=0, to kanw -100.
        contents[doneCounter]=-contents[doneCounter];
        if(contents[doneCounter]==0) contents[doneCounter]=-100;

        for(int i=0;i<maxNodes;i++) //orise posa nodes einai done gia na deis ama teleiwses
        {
            if(Q[i]==2)
            {
                Q[i]=3;
                doneCounter++;
            }
        }
        for(int i=0;i<maxNodes;i++) //orise to neo root
        {
            if(Q[i]==0)
            {
                root=i;
                break;
            }
        }
    }

    DFScounter=0;   //ksana 0 bas kai ksanaxreiastei DFS.
}

void MyGraph::doDFS(int x,int *contents,int *Q)
{
    Q[x]=1; //x in progress
    contents[DFScounter]=x; //prospelasthke kai bainei sthn epomenh thesh tou contents
    DFScounter++;   //afksanetai h thesh
    for(int i=0;i<maxNodes;i++)
    {
        if(searchEdge(x,i) && Q[i]==0)  //yparxei edge kai den einai visited
        {
            doDFS(i,contents,Q);    //anadromh me to edge pou ikanopoiei to parapanw
        }
    }
    Q[x]=2; //x done
}

int MyGraph::MinSpanTree(int *contents) //o contents sto telos tha periexei to parent node tou kathe i. stis theseis 2*i periexetai to varos anamesa se parent kai i.
{
    int dist[maxNodes];                 //apostash
    int NodeCounter=0;                  //sto telos prepei =maxNodes, xrhsimopoieitai sto while parakatw
    int Q[maxNodes];                    //kwdikos node gia enable/disable
    int parent[maxNodes];               //deixnei ton parent

    //algorithmos Prim.
    int u;
    int minDist;
    for(int i=0;i<maxNodes;i++)         //arxikopoihseis
    {
        parent[i]=-1;
        dist[i]=INT_MAX; //INT_MAX adi gia apeiro.
        Q[i]=1;
    }
    for(int i=0;i<maxNodes;i++)         //pairnw to prwto node pou tha vrw sth tyxh gia arxh
    {
        if(graph[i]!=NULL)
        {
            dist[i]=0;
            u=i;
            minDist=dist[i];
            break;
        }
    }
    while(NodeCounter!=maxNodes)
    {
        for(int i=0;i<maxNodes;i++)
        {
            if(Q[i]!=0)
            {
                if(dist[i]<minDist)
                {
                    u=i;
                    minDist=dist[i];
                }
            }
        }
        if(minDist==INT_MAX)
        {
            break;
        }
        Q[u]=0;
        NodeCounter++;
        node* temp=graph[u];
        while(temp!=NULL)
        {
            if(Q[temp->connectedTo]==1 && temp->weight<dist[temp->connectedTo])
            {
                parent[temp->connectedTo]=u;
                dist[temp->connectedTo]=temp->weight;
            }
            temp=temp->next;
        }
        minDist=INT_MAX;
    }
    int totalDist=0;

    //gemizw ton contents me ta periexomena tou dist.
    for(int i=0;i<maxNodes;i++)
    {
        contents[i]=parent[i];
        if(dist[i]==INT_MAX)
        {
            contents[maxNodes+i]=-1;
        }
        else
        {
            contents[maxNodes+i]=dist[i];
            totalDist=totalDist+dist[i];
        }
    }
    return totalDist;   //total dist athroisma synoliko pou epistrefetai
}

void MyGraph::ShortestPaths(int x, int *contents) //o contents sto telos tha periexei to distance tou komvou i apo to root x.
{
    int dist[maxNodes];         //apostash
    int NodeCounter=0;          //sto telos prepei =maxNodes, xrhsimopoieitai sto while parakatw
    int Q[maxNodes];            //kwdikos node gia enable/disable

    //algorithmos Dijkstra
    for(int i=0;i<maxNodes;i++)
    {
        dist[i]=INT_MAX; //INT_MAX adi gia apeiro.
        Q[i]=1;
    }
    dist[x]=0;
    int u=x;
    int minDist=dist[x];
    while(NodeCounter!=maxNodes)
    {
        for(int i=0;i<maxNodes;i++)
        {
            if(Q[i]!=0)
            {
                if(dist[i]<minDist)
                {
                    u=i;
                    minDist=dist[i];
                }
            }
        }
        if(minDist==INT_MAX)
        {
            break;
        }
        Q[u]=0;
        NodeCounter++;
        node* temp=graph[u];
        while(temp!=NULL)
        {
            int tempDist = dist[u]+temp->weight;
            if(tempDist<dist[temp->connectedTo])
            {
                dist[temp->connectedTo]=tempDist;
            }
            temp=temp->next;
        }
        minDist=INT_MAX;
    }
    //gemizw ton contents me ta periexomena tou dist.
    for(int i=0;i<maxNodes;i++)
    {
        if(dist[i]!=INT_MAX)
        {
            contents[i]=dist[i];
        }
        else contents[i]=-1;
    }
}
