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

#ifndef MYHEAP_H
#define MYHEAP_H


class MyHeap
{
    private:
        int size, sizeHS;             //sizeHS xrhsimopoieitai sth HeapSort san temp
        bool heap_type;               //true shmainei swros megistwn.
        int *heap;
        int position;                 //current position

        //extra
        void makeMaxHeap(int i);      //Dhmiourgei max heap. (xrhsimopoieitai sth heapsort)

    public:
        MyHeap(int size,bool heap_type);     // constructor
        ~MyHeap();                           // destructor
        int Insert (int x);                  // εισαγωγή του x
        int DeleteTop ();                    // διαγραφή της κορυφής
        int ReadTop ();                      // ανάγνωση της κορυφής
        int GetSize();                       // πλήθος στοιχείων στο σωρό
        int Sort();                          // ταξινόμηση
        int GetContents(int *h);             // αντιγράφει τα περιεχόμενα του σωρού στο array h
};

#endif // MYHEAP_H
