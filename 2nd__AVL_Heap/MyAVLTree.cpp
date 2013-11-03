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

#include "MyAVLTree.h"

MyAVLTree::MyAVLTree(){
    root=NULL;                      //arxikopoihseis...
    size=0;
}

MyAVLTree::~MyAVLTree(){
    Postorder_delete(root);         //kaleitai h postrder delete h opoia diagrafei tous komvous enan enan
    root=NULL;                      //xrhsimopoiwdas prosvash postorder.
}

int MyAVLTree::Insert(int x){
    if(root==NULL){             //an to tree einai adeio, these ton neo komvo sto root
        node *ptr;
        ptr=newnode(x);
        root=ptr;
        size++;
        return 1;//SUCCESS
    }
    else                        //diaforetika kalese thn private Insert (me ta 2 orismata)
    {
        Insert(root, x);        //bainei "mesa" sto dedro kai topothetei to x sth swsth thesh.
        size++;
        return 1;
    }
}

int MyAVLTree::Delete(int x){
    node *current,*parent;
    int isleftchild =1;
    current=parent=root;                    //arxikopoihsh anazhthshs
    if(root==NULL) return 0;                //periptwsh pou to tree einai adeio
    while(current->data!=x){                //arxika anazhtoume to x.
        parent = current;
        if(x<current->data){
            isleftchild=1;
            current=current->left;
        }
        else{
            isleftchild=0;
            current = current->right;
        }
        if(current == NULL){
            return -1;                      //den vrethike
        }
    }

    //ama h while perasei, vrikame ton komvo pou krataei to x. O komvos aftos einai o current,
    //kai o gonikos tou komvos einai o parent.
    //An o komvos den exei allous thygatrikous:
    if(current->left==NULL && current->right==NULL){
        if(current==root)                   //ama to stoixeio einai to root
            root=NULL;                      //tote to dedro einai keno
        else if(isleftchild)                //ama einai aristero paidi
            parent->left=NULL;              //to aposyndeoume
        else
            parent->right=NULL;             //omoia ama einai deksio paidi
    }
    //An den yparxe deksios thygatrikos komvos:
    else if(current->right==NULL){
        if(current == root)                   //ama to stoixeio einai to root
            root=current->left;               //tote anevase panw ton komvo aristera.
        else if(isleftchild)                  //ama einai aristero paidi
            parent->left = current->left;     //omoiws
        else
            parent->right = current->left;    //omoia ama einai deksio paidi
    }
    //An den yparxe aristeros thygatrikos komvos:
    else if(current->left==NULL){
        if(current == root)                   //omoios sxoliasmos me to parapanw
            root = current->right;            //h diadikasia einai panomoiotyph
        else if(isleftchild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    //an yparxei kai aristeros kai deksios thygatrikos komvos:
    else{
        node *successor,*temp;
        if(current==root){                              //an vriskomaste sto root me 2 paidia
            temp=root->left;                            //pare olo to aristero ypodedro
            successor = find_left_most(root->right);    //these ws neo root to deksi ypodedro
            root = root->right;                         //kai sto aristerotero paidi tou neou root
            successor->left = temp;                     //vale to prwhn aristero ypodedro
        }
        else if(isleftchild)
        {
            successor=find_left_most(current->right);   //omoia
            successor->left=current->left;
            parent->left=current->right;
        }
        else
        {
            successor=find_right_most(current->left);   //omoia
            successor->right=current->right;
            parent->right=current->left;
        }
    }
    delete current; //diagrafoume th mnhmh pou katalamvanei o komvos
    size--;         //afairesame ena komvo
    return 1;       //Great success!11
}

bool MyAVLTree::Search(int x){
    node *current;                  //anazhthsh tou komvou me th timh x.
    current=root;                   //ksekinwdas apo th riza
    while(current->data != x){      //sygrinoume to x me tis current times tou data
        if(x<current->data)         //kai kinoumaste analogws, deksia h aristera...
            current = current->left;
        else
            current = current->right;
        if(current==NULL)           //ama den to vroume, return false
            return false;           //NOT FOUND
    }
    return true;                    //FOUND
}

int MyAVLTree::GetSize(){
    return size;        //epistrefoume to megethos tou tree
}

void MyAVLTree::Inorder(int *result){
    counter=0;                          //xrhsimopoieitai voh8htika sth parakatw
    in_order_display(root,result);      //kaloume thn adistoixh private synarthsh
}

void MyAVLTree::Preorder(int *result){
    counter=0;                           //xrhsimopoieitai voh8htika sth parakatw
    pre_order_display(root,result);      //kaloume thn adistoixh private synarthsh
}

void MyAVLTree::Postorder(int *result){
    counter=0;                            //xrhsimopoieitai voh8htika sth parakatw
    post_order_display(root,result);      //kaloume thn adistoixh private synarthsh
}

//extras

void MyAVLTree::Postorder_delete(node *ptr){
    if (ptr==NULL) return;              //h synarthsh afth xrhsimopoieitai apo ton katastrofea
    Postorder_delete(ptr->left);        //kai diagrafei olous tous komvous me th xrhsh ths postorder
    Postorder_delete(ptr->right);       //apodesmevodas enan enan to xwro kathe keliou
    delete ptr;
}

void MyAVLTree::rotateLeftOnce(node*& ptr){
     node *otherNode;
     otherNode = ptr->left;
     ptr->left = otherNode->right;
     otherNode->right = ptr;
     ptr = otherNode;                       //aristerh peristrofh (monh)
}

void MyAVLTree::rotateLeftTwice(node*& ptr){
     rotateRightOnce(ptr->left);
     rotateLeftOnce(ptr);                   //aristerh peristrofh (diplh)
}

void MyAVLTree::rotateRightOnce(node*& ptr){
     node *otherNode;
     otherNode = ptr->right;
     ptr->right = otherNode->left;
     otherNode->left = ptr;
     ptr = otherNode;                       //deksia peristrofh (monh)
}

void MyAVLTree::rotateRightTwice(node*& ptr){
     rotateLeftOnce(ptr->right);
     rotateRightOnce(ptr);                  //deksia peristrofh (diplh)
}

int MyAVLTree::GetHeight(node *ptr){
     int left, right;
     if(ptr==NULL)                      //edopizei se ti ypsos vrisketai o komvos ptr
         return 0;                      //xrhsimopoieitai apo thn insert
     left = GetHeight(ptr->left);       //gia ton edopismo ths katallhlhs theshs
     right = GetHeight(ptr->right);     //wste to tree na einai isokatanemhmeno
  if(left > right)
            return left+1;
         else
            return right+1;
}
