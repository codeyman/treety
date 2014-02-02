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

void AVLTree::verifyHeight()
{
    std::queue<AVLTreeNode *> tqueue;
    if(getRoot() == NULL) {
        return;
    }
    tqueue.push(getRoot());
    while(!tqueue.empty()) {
        AVLTreeNode *temp = tqueue.front();
        tqueue.pop();
        int h=height_i(temp);
        if(temp->getHeight() != h){
            std::cout<<"issue is "<<temp->getData()<<" sheight:"<<temp->getHeight()<<" rh:"<<h<<std::endl;
            show();
        }
        assert(temp->getHeight() == h);
        assert(temp->balanceFactor() >= -1 || temp->balanceFactor() <=1 );
        if(temp->getLeft()) tqueue.push(temp->getLeft());
        if(temp->getRight()) tqueue.push(temp->getRight());
    }
}


int AVLTree::height_i(AVLTreeNode *node){
    int lh,rh;
    if(!node) return -1;
    lh = height_i(node->getLeft());
    rh = height_i(node->getRight());
    return std::max(lh,rh)+1;
}
void AVLTree::rebalanceAncestors(AVLTreeNode *a_node)
{
    AVLTreeNode *temp = a_node;
    int lth, rth;
    bool rebalanced = false;

    while(temp!=NULL && !rebalanced) {
        temp->adjustHeight();

        int bf = temp->balanceFactor();

        if(bf == 2) {
            lth = (temp->getLeft()->getLeft())?temp->getLeft()->getLeft()->getHeight():-1;
            rth = (temp->getLeft()->getRight())?temp->getLeft()->getRight()->getHeight():-1;
            if(rth > lth) {
                rotateLeft(temp->getLeft());
            }
            rotateRight(temp);
//            rebalanced = true;
                
        } else if (bf == -2) {
            lth = (temp->getRight()->getLeft())?temp->getRight()->getLeft()->getHeight():-1;
            rth = (temp->getRight()->getRight())?temp->getRight()->getRight()->getHeight():-1;
            if(lth > rth) {
                rotateRight(temp->getRight());
            }
            rotateLeft(temp);
//            rebalanced = true;
            
        }
        temp->adjustHeight();
        temp = temp->getParent();
        
    }
}
void AVLTree::remove(int val)
{
    AVLTreeNode *par;

#if DEBUG
    std::cout<<"Calling child del: "<<val<<std::endl;
#endif 
    par = delBST(val);
    if(!par) return;

    rebalanceAncestors(par);
}

void AVLTree::show()
{
    Showoff disp(getRoot());
    disp.print();
    printBFS();
}
void AVLTree::insert(int val)
{
    AVLTreeNode *node;

#if DEBUG 
    std::cout<<"Calling child insert: "<<val<<std::endl;
#endif

    node = addBST(val);
    if(!node) return; //Entry was already present.
    node->setHeight(0);

    rebalanceAncestors(node);
#if DEBUG 
    verifyHeight();
#endif
}

void AVLTree::rotateRight(AVLTreeNode *node)
{
   int oldLH = 0;
   int oldRH = 0;
   int maxold;
   if(!node) return;
   AVLTreeNode *temp,*tparent;
   temp = node->getLeft();
   tparent = node->getParent();
   if(temp) {
       oldLH = (temp->getLeft())?temp->getLeft()->getHeight():0;
       oldRH = (node->getRight())?node->getRight()->getHeight():-1;
       node->setLeft(temp->getRight());
       temp->setRight(node); 
       temp->setParent(tparent);
       if( node == getRoot() ) setRoot(temp);
       else {
           if((tparent->getLeft())==node) tparent->setLeft(temp);
           else tparent->setRight(temp);
       }
       maxold = std::max(oldLH,oldRH+1);

       node->setHeight(maxold);
       temp->setHeight(maxold+1);
   }
}

void AVLTree::rotateLeft(AVLTreeNode *node)
{
   int oldLH = 0;
   int oldRH = 0;
   int maxold;
   if(!node) return;
   AVLTreeNode *temp,*tparent;
   temp = node->getRight();
   tparent = node->getParent();
   if(temp) {
       oldLH = (node->getLeft())?node->getLeft()->getHeight():-1;
       oldRH = (temp->getRight())?temp->getRight()->getHeight():0;
       node->setRight(temp->getLeft());
       temp->setLeft(node); 
       temp->setParent(tparent);
       if( node == getRoot() ) setRoot(temp);
       else {
           if(tparent->getRight()==node) tparent->setRight(temp);
           else tparent->setLeft(temp);
       }
       maxold = std::max(oldLH+1,oldRH);

       node->setHeight(maxold);
       temp->setHeight(maxold+1);

   }
}

void AVLTree::printBFS()
{
    std::queue<AVLTreeNode *> tqueue;
    if(getRoot() == NULL) {
        std::cout<<"Empty Tree"<<std::endl;
        return;
    }
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

int AVLTreeNode::balanceFactor()
{
    int lh = (getLeft())?(getLeft()->getHeight()):-1;
    int rh = (getRight())?(getRight()->getHeight()):-1;
    
    return (lh - rh);
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

    avtree.show();


}
void test3(const std::vector<int> &x,int num)
{
    AVLTree mytree;
    mytree.initTree(x,num);
    mytree.show();

    mytree.remove(5);
    mytree.show();

    mytree.remove(3);
    mytree.show();

    mytree.remove(4);
    mytree.show();

    mytree.remove(1);
    mytree.show();

    mytree.remove(6);
    mytree.show();

    mytree.remove(9);
    mytree.show();


    mytree.remove(7);
    mytree.show();


    mytree.remove(8);
    mytree.show();
}

int myrandom (int i) { return std::rand()%i;}

void longTest_helper(std::vector<int>& vec)
{
    AVLTree mytree;
    //create a random tree
    mytree.initTree(vec,vec.size());
    mytree.verifyHeight();


    //delete random number of elements in random order
    int numdel = std::rand()%(vec.size());
    std::random_shuffle(vec.begin(), vec.end(),myrandom);
    for(int i=0; i<numdel; ++i){
        mytree.remove(vec[i]);
    }

    mytree.verifyHeight();

}
void longTest()
{
    std::vector<int> x;
    for(int i=1;i<=1000;++i)
        x.push_back(myrandom(i));

    std::cout<<" Failure will cause a crash here \n";
    for(int i=0; i<10000; ++i){
        std::random_shuffle(x.begin(), x.end(),myrandom);
        longTest_helper(x);
    }
    std::cout<<" Test passed \n";
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
            {7,6,5,6,7,5,4,6,1,8,9,10},
            {7,7,7,7,7,7,7},
            {6000,3000,5000,1000,7000,8000,4000}, 
            {10,20,30,40,50,60,70}, 
            {700,60,50,4,3,2,1}};

    //Test tree creation: checks getters
    std::cout<<"<------------- TEST 1: INSERT -------->\n";
    if (tc <= 0 || tc > testcases.size()) {
        for(std::vector< std::vector<int> >::size_type i = 0; i< testcases.size()-1 ; ++i)
        {
            for(std::vector<int>::size_type j = 1; j<=testcases[i].size(); ++j)
                test1(testcases[i],j);
        }
    }
    else test1(testcases[tc-1], testcases[tc-1].size());

    std::cout<<"<------------- TEST 2: DELETES -------->\n";
    test3(testcases[0], 7);
    std::cout<<"<------------- TEST 3: LONG TEST -------->\n";
    longTest();
}
#endif
/* end of AVLTree.cc */
