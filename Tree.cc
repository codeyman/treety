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
    //cout<<"Adding "<<val[0]<<endl;
    for(;i<count;++i) {
      //  cout<<"Adding "<<val[i]<<endl;
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
        ret->clearbmp();
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

    maxh +=2;
    maxw +=3;

    ret = new Showoff( maxh, maxw, (maxw)/2);
    ret->clearbmp();
    if(leftS) {
        ret->setAtOffset(2,0,leftS);
        ret->setAtOffset(1,leftHead+1,'/');
    }

    if(rightS){
        ret->setAtOffset(1,leftw+rightHead+2,'\\');
        ret->setAtOffset(2,leftw+3,rightS);
    }
    if(leftS && rightS)
        datapos = (3+leftHead+rightHead+leftw)/2;
    else if (leftS)
        datapos = leftHead + 2;
    else if (rightS)
        datapos = leftw + rightHead + 1;

    ret->setAtOffset(0,datapos,_data);
    ret->setHeadLoc(datapos);
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
    //node->printBFS();
    Showoff *disp = node->dispTree();
    disp->print();
    delete disp;
    delete node;
}
int main(int argc,char *argv[])
{
    int x[]={6,3,5,1,7,8,4}; 
    for (int i=1;i<8;++i)
        test(x,i);
    int y[]={1,2,3,4,5,6,7}; 
    for (int i=1;i<8;++i)
        test(y,i);
    int z[]={7,6,5,4,3,2,1}; 
    for (int i=1;i<8;++i)
        test(z,i);
}
#endif
/* end of Tree.cc */
