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

#ifndef MYAVLTREE_H
#define MYAVLTREE_H
#include <cstdlib>                  //aparaithto include gia xrhsh tou NULL pointer

using namespace std;
class MyAVLTree
{
    private:
        int size;                   //metavlhth pou krataei to megethos tou dedrou

//=========== NODE CLASS =================================================================
        class node                  //ypoklash-komvos tou tree
        {
            public:
                int data;           //periexei pointers left kai right, kai integer data.
                node *left;
                node *right;
        };
        node *root;                 //pada yparxei o arxikos komvos-riza

        node *newnode(int x)        //synarthsh dhmiourgias neou komvou.
        {
            node *neos;
            neos=new node;
            neos->data = x;
            neos->left=NULL;
            neos->right=NULL;
            return(neos);
        }
//========================================================================================

//=========== DESTRUCTOR FUNCTION ========================================================
        void Postorder_delete(node *ptr);   //synarthsh pou xrhsimopoieitai apo ton katastrofea gia diagrafh ths domhs
//========================================================================================

//=========== LEFT|RIGHT-MOST ============================================================
        node *find_left_most(node *ptr)  //entopizei ton teleutaio aristera kombo tou ipodentrou ptr (xrhsimopoieitai sto delete)
        {
                if(ptr==NULL) return NULL;
                while(ptr->left!=NULL)
                {
                    ptr=ptr->left;
                }
            return ptr;
        }

        node *find_right_most(node *ptr)  //entopizei ton teleutaio deksia kombo tou ipodentrou ptr (xrhsimopoieitai sto delete)
        {
            if(ptr==NULL) return NULL;
            while(ptr->right!=NULL)
            {
                ptr=ptr->right;
            }
            return ptr;
        }
//========================================================================================

//=========== IN|PRE|POST-ORDER ==========================================================
        int counter; //xrhsimopoieitai sta 3 order gia gemisma tou pinaka

        void in_order_display(node *ptr,int *result)  //InOrder
        {
            if (ptr==NULL) return;
            in_order_display(ptr->left,result);
            result[counter]=ptr->data;
            counter++;
            in_order_display(ptr->right,result);
        }

        void pre_order_display(node *ptr,int *result)  //PreOrder
        {
            if (ptr==NULL) return;
            result[counter]=ptr->data;
            counter++;
            pre_order_display(ptr->left,result);
            pre_order_display(ptr->right,result);
        }

        void post_order_display(node *ptr,int *result)  //PostOrder
        {
            if (ptr==NULL) return;
            post_order_display(ptr->left,result);
            post_order_display(ptr->right,result);
            result[counter]=ptr->data;
            counter++;
        }
//========================================================================================



//=========== ROTATIONS & INSERT =========================================================
        int GetHeight(node *ptr);               //edopizei se ti ypsos vrisketai o komvos ptr
        void rotateLeftOnce(node*& ptr);        //aristerh peristrofh (monh)
        void rotateLeftTwice(node*& ptr);       //aristerh peristrofh (diplh)
        void rotateRightOnce(node*& ptr);       //deksia peristrofh (monh)
        void rotateRightTwice(node*& ptr);      //deksia peristrofh (diplh)

        node* Insert(node*& ptr, int x){            //anazhta katallhlh thesh kai topothetei to neo komvo. Kaleitai mesw ths allhs insert.
        if(ptr == NULL)                             //An eimaste sto telos tou dedrou, vale th timh.
            ptr = newnode(x);
        else if(x < ptr->data){                     //alliws phgaine aristera an X<data
            Insert(ptr->left, x);
            if(GetHeight(ptr->left) - GetHeight(ptr->right) == 2){
                if(x < ptr->left->data)
                    rotateLeftOnce(ptr);
                else
                    rotateLeftTwice(ptr);
                }
            }
        else if(x > ptr->data){                     //alliws phgaine deksia an X>data
            Insert(ptr->right, x);
            if(GetHeight(ptr->right) - GetHeight(ptr->left) == 2){
                if(x > ptr->right->data)
                    rotateRightOnce(ptr);
                else
                    rotateRightTwice(ptr);
                }
            }
        return ptr;
        }
//========================================================================================

    public:
        MyAVLTree();                     // constructor
        ~MyAVLTree();                    // destructor
        int Insert (int x);              // εισαγωγή του x στο δένδρο
        int Delete (int x);              // διαγραφή του x
        bool Search (int x);             // αναζήτηση αν υπάρχει το x ή όχι
        int GetSize();                   // πλήθος στοιχείων στο δένδρο
        void Inorder (int *result);      // η inorder διάσχιση αποθηκεύεται στο array result
        void Preorder (int *result);     // η preorder διάσχιση αποθηκεύεται στο array result
        void Postorder (int *result);    // η postorder διάσχιση αποθηκεύεται στο array result
};

#endif // MYAVLTREE_H
