/*
 * File name:    Tree.cc
 * Date:         2013/11/13 18:46
 * Author:       Sridhar V Iyer (sridhiye@cisco.com)
 * Description: 
 * 
 */


#include <iostream>
#include <queue>
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
    _data = val[0];
    for(;i<count;++i) {
        cout<<"Adding "<<val[i]<<endl;
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

#ifdef TEST_TREE
int main(int argc,char *argv[])
{
    int x[]={6,3,5,1,7};
    Tree *node = new Tree(x,5);
    node->printBFS();
    delete node;
}
#endif
/* end of Tree.cc */
