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

#ifndef MYHASH_H
#define MYHASH_H
class MyHash
{
    private:
        int *hashTable;
        bool *isEmptyTable;
        int maxSize;
        int currSize;
        int hashFunction(int x,int *probes);

    public:
        MyHash(int size);
        ~MyHash();
        int Insert(int x);
        bool Search(int x, int *probes);
        int GetSize();
        int GetMaxSize();

};
#endif // MYHASH_H
