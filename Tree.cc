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

using namespace std;
#define SEP '.'

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

Showoff* Tree::dispTree()
{
    Showoff *ret = NULL , *leftS = NULL, *rightS = NULL;
    int maxh = 1, maxw = 1, leftw = 1;
    int leftHead = 0,rightHead = 0;
    int datapos = 0;
    if(left == NULL && right == NULL) {
        ret = new Showoff;
        ret->clearbmp(SEP);
        ret->setAtOffset(0,0,this->_data); 
        return ret; 
    }

    if(left != NULL) {
        leftS = left->dispTree();
        maxh = leftS->getHeight();
        maxw = leftS->getWidth();
        leftw = maxw;
        leftHead = leftS->getHeadLoc();
    }

    if(right != NULL) {
        rightS = right->dispTree();
        if( maxh < rightS->getHeight())
            maxh = rightS->getHeight();
        maxw += rightS->getWidth();
        rightHead = rightS->getHeadLoc();
    }

    //+1 for connectors and +1 for parent
    maxh +=2;

    //+2 for left and right connectors. +1 for parent.
    maxw +=3;

    ret = new Showoff( maxh, maxw, (maxw)/2);
    ret->clearbmp(SEP);

    if(leftS && rightS)
        datapos = (3+leftHead+rightHead+leftw)/2;
    else if (leftS)
        datapos = leftHead + 2;
    else if (rightS)
        datapos = leftw + rightHead + 1;

    ret->setAtOffset(0,datapos,_data);
    ret->setHeadLoc(datapos);


    if(leftS) {
        ret->setAtOffset(2,0,leftS);
        ret->setAtOffset(1,leftHead+1,'/');
    }

    if(rightS){
        ret->setAtOffset(1,leftw+rightHead+2,'\\');
        ret->setAtOffset(2,leftw+3,rightS);
    }

    return ret;

    
}

Tree::~Tree() 
{
    if(left!=NULL) delete left;
    if(right!=NULL) delete right;
}
#ifdef TEST_TREE
void test(int x[],int num)
{
    Tree *node = new Tree(x,num);
    Showoff *disp = node->dispTree();
    disp->print();
    delete disp;
    delete node;
}
int main(int argc,char *argv[])
{
    int x[][7]={{6,3,5,1,7,8,4}, 
            {1,2,3,4,5,6,7}, 
            {7,6,5,4,3,2,1},
            {6000,3000,5000,1000,7000,8000,4000}, 
            {10,20,30,40,50,60,70}, 
            {700,60,50,4,3,2,1}};
#ifndef DEBUG
    for(int i = 0; i<6 ; ++i)
    {
        for(int j = 1; j<8; ++j)
            test(x[i],j);
    }
#else
    test(x[5],2);
#endif
}
#endif
/* end of Tree.cc */
