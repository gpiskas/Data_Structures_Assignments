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

#include "MyHash.h"

MyHash::MyHash(int size)
{
    maxSize=size;
    currSize=0;         //adeios pinakas arxika
    hashTable = new int[maxSize];
    for (int i=0;i<maxSize;i++)
    {
        hashTable[i]=-1;        //arxikopoihsh
    }
    isEmptyTable = new bool[maxSize];
        for (int i=0;i<maxSize;i++)
    {
        isEmptyTable[i]=true;        //arxikopoihsh
    }
}

MyHash::~MyHash()
{
    delete[] hashTable;
    delete[] isEmptyTable;
}

int MyHash::Insert(int x)
{
    int probes=0;
    int b=hashFunction(x,&probes);      //to b tha periexei th thesh pou prepei na bei to x. -1 an pinakas full.

    if(b==-1) return -1;    //pinakas full
    if(isEmptyTable[b])
    {
        isEmptyTable[b]=false;
        hashTable[b]=x;
        currSize++;
        return probes;      //return tis epanalhpseis pou eginan gia na bei to stoixeio
    }
    else if(hashTable[b]==x) return -2; //duplicate
}

int MyHash::hashFunction(int x,int *probes)
{
    int i=x%maxSize;
    int j=i;
    do{
        (*probes)++;    //+ mia akoma epanalhpsh
        if( isEmptyTable[j] || hashTable[j]==x ) return j;
        j=(j+1)%maxSize;
    }while(j!=i);       //oso den exoume oloklhrwsei kyklo.

    return -1; //pinakas full
}

bool MyHash::Search (int x, int *probes)
{
    int b=hashFunction(x,probes);   //edopismos theshs gia to x
    if(isEmptyTable[b] || hashTable[b]!=x) return false;
    else return true;
}

int MyHash::GetSize()
 {
     return currSize;
 }

int MyHash::GetMaxSize()
{
    return maxSize;
}
