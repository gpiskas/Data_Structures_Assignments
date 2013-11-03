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

#include "MyHeap.h"
#include <limits.h>
MyHeap::MyHeap(int sz, bool type){
    size=sz+1;                                          //size+1 giati den xrhsimopoioume to 1o stoixeio tou pinaka mas
    heap_type=type;                                     //otan o xrhsths dwsei  true, exoume megistwn. ama dwsei false elaxistwn
    position=1;                                         //Trexousa thesh tou pinaka, times apo 1 ews size+1
    heap = new int[size];                               //desmefsh tou xwrou pou tha xreiastoume
    if(type) for(int i=0;i<=size;i++) heap[i]=LONG_MIN;   //arxikopoihsh | den xrhsimopoioume th thesh 0.
    else for(int i=0;i<=size;i++) heap[i]=LONG_MAX;        //arxikopoihsh
}

MyHeap::~MyHeap(){
    delete[] heap;                          //katastrofeas
}

int MyHeap::Insert (int x){
    if (position==size) return -1;            //pinakas gematos

    int i=position;
    if(heap_type){                          //an einai swros megistwn
        while(i!=1 && x>heap[i/2]){         //vriskoume se poio i einai h katallhlh thesh gia na eisagoume to stoixeio mas
        heap[i]=heap[i/2];                  //metakinish stoixeiou
        i=i/2;                              //metakinish ston parent
        }
    }
    else{                                   //an einai swros elaxistwn
        while(i!=1 && x<heap[i/2]){         //vriskoume se poio i einai h katallhlh thesh gia na eisagoume to stoixeio mas
        heap[i]=heap[i/2];                  //metakinish stoixeiou
        i=i/2;                              //metakinish ston parent
        }
    }
    position++;                             //efoson prostethike stoixeio, afksanoume to position kata 1
    heap[i]=x;                              //eisagoume to stoixeio
    return 0;                               //egine insert ok
}

int MyHeap::DeleteTop (){
    if (position==1) return -1;           //pinakas adeios
    int telefteo=heap[position-1];            //apothikevoume to telefteo mas stoixeio
    int i=1;
    int ci=2;

    //ektelesh twn aparaithtwn adimetathesewn wste na epanakataskevastei to heap
    if(heap_type){                          //an einai swros megistwn
        while(ci <=position){
            if(ci<position && heap[ci] < heap[ci+1]) ci++;
            if(telefteo>= heap[ci]) break;
            heap[i]=heap[ci];
            i=ci;
            ci=ci*2;
        }
    }
    else{                                   //an einai swros elaxistwn
        while(ci <=position){
            if(ci<position && heap[ci] > heap[ci+1]) ci++;
            if(telefteo<= heap[ci]) break;
            heap[i]=heap[ci];
            i=ci;
            ci=ci*2;
        }
    }
    heap[i]=telefteo;                       //anathesh ths neas timhs tou heap[i] ish me to telefteo stoixeio, afou kathorisame pou tha bei.
    if(heap_type) heap[position-1]=LONG_MIN;    //to telefteo stoixeio diagrafetai k h timh tou "arxikopoieitai"
    else heap[position-1]=LONG_MAX;
    position--;                             //-1 position, afairesame 1 stoixeio
    return 0;                               //egine delete ok
}

int MyHeap::ReadTop (){
    if (position==1) return -1;           //pinakas adeios
    return heap[1];                         //epistrofh kefalhs
}

int MyHeap::GetSize(){
    return (position-1);                    //to position deixnei 1 thesh brosta apo to telefteo stoixeio tou heap, giafto -1.
}

int MyHeap::GetContents(int *h){
    if (position==1) return -1;           //pinakas adeios
    int *start = h;                         //apothikevoume thn arxikh thesh mnhmhs tou pinaka gia na mh th xasoume
    for(int i=0;i<position;i++)
    {
        h[i]=heap[i];                       //o pinakas gemizei me ta stoixeia tou heap
    }
    return  *start;                         //epistrefetai h thesh mnhmhs tou 1ou stoixeiou tou pinaka
}

int MyHeap::Sort(){
    sizeHS=position;                                     //to sizeHS einai ousiastika ena temp tou size giati prepei na to metavaloume
    for (int i=(sizeHS-1)/2;i>=1;i--) makeMaxHeap(i);    //dhmiourgia sorou megistwnh kanodas makeMaxHeap
    for (int i = sizeHS; i > 1; i--)                     //heapsort
    {
        int temp = heap[1];                              //diadikasia ths heapsort
        heap[1] = heap[sizeHS-1];
        heap[sizeHS-1] = temp;
        sizeHS=sizeHS-1;
        makeMaxHeap(1);
    }
    return 1;
}

void MyHeap::makeMaxHeap(int i) {
    int left = 2*i, max;                                //ftiaxnoume maxHeap wste na kanoume extract
    int right = 2*i+1;                                  //to megalytero stoixeio sth heapSort.
    if ( (heap[left] > heap[i]) && (left < sizeHS)) {
        max = left;
    }
    else {
        max = i;
    }
    if ( (heap[right] > heap[max]) && (right < sizeHS)) {
        max = right;
    }
    if (max != i) {
        int temp = heap[i];
        heap[i] = heap[max];
        heap[max] = temp;
        makeMaxHeap(max);
    }
}
