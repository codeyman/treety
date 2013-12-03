/*
 * File name:    Tree.cc
 * Date:         2013/11/13 18:46
 * Author:       Sridhar V Iyer (sridhiye@cisco.com)
 * Description: 
 * 
 */


#include <iostream>
#include <queue>
#include <string>
#include <cassert>
#include "Tree.h"
#include "Showoff.h"

using namespace std;

/****************************************
 * Constructors & Destructor 
 **************************************/
Tree::Tree():_data(0),left(NULL),right(NULL),parent(NULL) {}

Tree::Tree(int val):_data(val),left(NULL),right(NULL),parent(NULL) {}

Tree::Tree(int val[], int count)
{
    int i=1;
    assert(count >= 1);
    _data = val[0];
    left = right = parent = NULL;
    for(;i<count;++i) {
        addBST(val[i]);
    }
}

Tree::~Tree() 
{
    if(left!=NULL) delete left;
    if(right!=NULL) delete right;
}

/****************************************/
  
//Getters & Setters

Tree *Tree::getLeft()
{
    return left;
}

Tree *Tree::getRight()
{
    return right;
}

Tree *Tree::getParent()
{
    return right;
}

int Tree::getData()
{
    return _data;
}
void Tree::setLeft(const int &val)
{
    if(left!=NULL){
        delete left;
        left = NULL;
    }

    left = new Tree(val);
    left->parent = this;
}

void Tree::setLeft(Tree *node)
{
    if(left!=NULL){
        delete left;
        left = NULL;
    }

    left = node;
    left->parent = this;

}

void Tree::setRight(const int &val)
{
    if(right!=NULL){
        delete right;
        right = NULL;
    }

    right = new Tree(val);
    right->parent = this;
}

void Tree::setRight(Tree *node)
{
    if(right!=NULL){
        delete right;
        right = NULL;
    }

    right = node;
    right->parent = this;
}

/****************************************/
  
void Tree::printBFS()
{
    queue<Tree *> tqueue;
    tqueue.push(this);
    while(!tqueue.empty()) {
        Tree *temp = tqueue.front();
        tqueue.pop();
        cout<<" "<<temp->_data;
        if(temp->left) tqueue.push(temp->left);
        if(temp->right) tqueue.push(temp->right);
    }
    cout<<endl;
}


void Tree::addBST(int val)
{
    if(val<=_data) {
        if(left==NULL) left=new Tree(val);
        else left->addBST(val);
    }
    else {
        if(right==NULL) right=new Tree(val);
        else right->addBST(val);
    }

}

#ifdef TEST_TREE
void test(int x[],int num)
{
    Tree node(x,num);
    Showoff disp(&node);
    disp.print();
}
int main(int argc,char *argv[])
{
    int testcase = 0;
    if (argc > 1) {
        testcase = atoi(argv[1]);
    }
    int x[][7]={{6,3,5,1,7,8,4}, 
            {1,2,3,4,5,6,7}, 
            {7,6,5,4,3,2,1},
            {6000,3000,5000,1000,7000,8000,4000}, 
            {10,20,30,40,50,60,70}, 
            {700,60,50,4,3,2,1}};
#ifndef DEBUG
    if (testcase <= 0 || testcase >6) {
        for(int i = 0; i<6 ; ++i)
        {
            for(int j = 1; j<8; ++j)
                test(x[i],j);
        }
    }
    else {
        for(int j = 1; j<8; ++j)
            test(x[testcase - 1],j);
    }

#else
    test(x[5],2);
#endif
}
#endif
/* end of Tree.cc */
