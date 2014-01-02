/*
 * File name:    AVLTree.cc
 * Date:         2013/12/06 16:17
 * Author:       Sridhar V Iyer (iyer@sridharv.net)
 * Description: 
 * 
 */


#include "AVLTree.h"
#include "Showoff.h"
#include <vector>
#include <iostream>
#include <algorithm>


void AVLTree::insert(int val)
{
    AVLTreeNode *node;
    std::cout<<"Calling child insert: "<<val<<std::endl;
    node = addBST(val);
    node->setHeight(0);
//#if DEBUG 
#if 1 
    AVLTreeNode *temp = node;
    std::cout<<"Parent links: ";
    while(temp!=NULL) {
        temp->adjustHeight();
        std::cout<<" "<<temp->getData()<<":"<<temp->getHeight();
        temp = temp->getParent();
    }
    std::cout<<std::endl;
#endif
}

void AVLTree::rotateRight(AVLTreeNode *node)
{
   int oldH = 0;
   if(!node) return;
   AVLTreeNode *temp,*tparent;
   temp = node->getLeft();
   tparent = node->getParent();
   if(temp) {
       oldH = temp->getLeft()->getHeight();
       node->setLeft(temp->getRight());
       temp->setRight(node); 
       temp->setParent(tparent);
       if( node == getRoot() ) setRoot(temp);
       else {
           if((tparent->getLeft())==node) tparent->setLeft(temp);
           else tparent->setRight(temp);
       }
       node->setHeight(oldH);
   }
}

void AVLTree::rotateLeft(AVLTreeNode *node)
{
   int oldH = 0;
   if(!node) return;
   AVLTreeNode *temp,*tparent;
   temp = node->getRight();
   tparent = node->getParent();
   if(temp) {
       oldH = temp->getRight()->getHeight();
       node->setRight(temp->getLeft());
       temp->setLeft(node); 
       temp->setParent(tparent);
       if( node == getRoot() ) setRoot(temp);
       else {
           if(tparent->getRight()==node) tparent->setRight(temp);
           else tparent->setLeft(temp);
       }

       node->setHeight(oldH);

   }
}

void AVLTree::printBFS()
{
    std::queue<AVLTreeNode *> tqueue;
    tqueue.push(getRoot());
    while(!tqueue.empty()) {
        AVLTreeNode *temp = tqueue.front();
        tqueue.pop();
        std::cout<<" "<<temp->getData()<<":"<<temp->getHeight();
        if(temp->getLeft()) tqueue.push(temp->getLeft());
        if(temp->getRight()) tqueue.push(temp->getRight());
    }
    std::cout<<std::endl;
}
AVLTreeNode::AVLTreeNode():TreeNode(),height(0){}
AVLTreeNode::AVLTreeNode(int val):TreeNode(val),height(0){}

void AVLTreeNode::setHeight(int h) 
{
    height = h;
}

//assumes that the children have their heights adjusted.
void AVLTreeNode::adjustHeight() 
{
    int lh = (getLeft())?(getLeft()->getHeight()):-1;
    int rh = (getRight())?(getRight()->getHeight()):-1;

    height = std::max(lh,rh) + 1;
}
int AVLTreeNode::getHeight()
{
    return height;
}


AVLTreeNode *AVLTreeNode::getLeft()
{
    return static_cast<AVLTreeNode *>(left);
}

AVLTreeNode *AVLTreeNode::getRight()
{
    return static_cast<AVLTreeNode *>(right);
}

AVLTreeNode *AVLTreeNode::getParent()
{
    return static_cast<AVLTreeNode *>(parent);
}

#ifdef TEST_AVLTREE
void test1(const std::vector<int> &x,int num)
{
    AVLTree avtree;
    avtree.initTree(x,num);

    Showoff disp(avtree.getRoot());
    disp.print();
    avtree.printBFS();

    avtree.rotateLeft(avtree.getRoot()->getRight());
    //avtree.rotateLeft(avtree.getRoot());

    Showoff disp2(avtree.getRoot());
    disp2.print();
    avtree.printBFS();

}
void test2(const std::vector<int> &x,int num)
{
    AVLTree avtree;
    avtree.initTree(x,num);

    Showoff disp(avtree.getRoot());
    disp.print();
    avtree.printBFS();


    avtree.rotateRight(avtree.getRoot());

    Showoff disp2(avtree.getRoot());
    disp2.print();
    avtree.printBFS();

}
int main(int argc,char *argv[])
{
    unsigned int tc = 0;
    if (argc > 1) {
        tc = std::stoul(argv[1]); //C++11 specific addition
    }

    //C++11 allows this initialization.
    std::vector< std::vector<int> > testcases = {{6,3,5,1,7,8,4}, 
            {1,2,3,4,5,6,7}, 
            {7,6,5,4,3,2,1},
            {6000,3000,5000,1000,7000,8000,4000}, 
            {10,20,30,40,50,60,70}, 
            {700,60,50,4,3,2,1}};

    //Test tree creation: checks getters
    std::cout<<"<------------- TEST SET 1: GETTER+SHOWOFF -------->\n";
    /*
    if (tc <= 0 || tc > testcases.size()) {
        for(std::vector< std::vector<int> >::size_type i = 0; i< testcases.size()-1 ; ++i)
        {
            for(std::vector<int>::size_type j = 1; j<=testcases[i].size(); ++j)
                test1(testcases[i],j);
        }
    }
    else test1(testcases[tc-1], testcases[tc-1].size());
    */
    test1(testcases[1], 4);
    test2(testcases[2], 3);
}
#endif
/* end of AVLTree.cc */
