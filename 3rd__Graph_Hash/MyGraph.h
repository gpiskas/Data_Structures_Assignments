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

#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <cstdlib>                  //aparaithto include gia xrhsh tou NULL pointer

class MyGraph
{
    private:

    //=========== NODE CLASS =================================================================
        class node                  //ypoklash-komvos tou graph
        {
            public:
                int connectedTo;           //periexei pointer next,integer weight kai integer connectedTo.
                int weight;
                node *next;

                node()  //new default node
                {
                    this->connectedTo=-1;
                    this->weight=-1;
                    this->next=NULL;
                }
        };
    //=========================================================================================
        node *newnode(int x,int w)        //synarthsh dhmiourgias neou komvou me to dothen input
        {
            node *neos;
            neos=new node;
            neos->connectedTo = x;
            neos->weight = w;
            neos->next=NULL;
            return(neos);
        }

        node **graph;           //o pinakas deiktwn me ola ta nodes
        int maxNodes;
        int currentEdges;
        int DFScounter;         //xrhsimopoieitai sto while tou DFS gia na kathorisei posoi komvoi einai akoma not visited

        node *getLastNode(node *firstNode)  //epistrefei to telefteo stoixeio ths alysidas ksekinwdas apo to input
        {
            node* temp=firstNode;
            while(temp->next!=NULL) //mexri na pesei se NULL...
            {
                temp=temp->next;
            }
            return(temp);
        }

        void doDFS(int x,int *contents,int *Q); //anadromikh diadikasia tou DFS
        int searchEdge(int x,int y);    //anazhta an yparxei kombos metaksy x - y

    public:
        MyGraph(int n);
        ~MyGraph();
        void InsertEdge(int x,int y,int w);
        int GetNumNodes();
        int GetNumEdges();
        void DFS(int x,int *contents);
        int MinSpanTree(int *contents);
        void ShortestPaths(int x, int *contents);

};

#endif // MYGRAPH_H
