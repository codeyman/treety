/*
 * File name:    Tree.cc
 * Date:         2013/11/13 18:46
 * Author:       Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description: 
 * 
 */


#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cassert>
#include "Tree.h"
#include "Showoff.h"

//using namespace std;

/****************************************
 * Constructors & Destructor 
 **************************************/
Tree::Tree():_data(0),left(NULL),right(NULL),parent(NULL) {}

Tree::Tree(int val):_data(val),left(NULL),right(NULL),parent(NULL) {}

Tree::Tree(const std::vector< int > &val, int count)
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
    std::queue<Tree *> tqueue;
    tqueue.push(this);
    while(!tqueue.empty()) {
        Tree *temp = tqueue.front();
        tqueue.pop();
        std::cout<<" "<<temp->_data;
        if(temp->left) tqueue.push(temp->left);
        if(temp->right) tqueue.push(temp->right);
    }
    std::cout<<std::endl;
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
void test1(const std::vector<int> &x,int num)
{
    Tree node(x,num);
    Showoff disp(&node);
    disp.print();
}

void test2(const std::vector< int > &x,const std::vector< int > &y)
{
    Tree node1(x,x.size());
    Tree *node2 = new Tree(y,y.size());

    Showoff disp1(&node1);
    Showoff disp2(node2);

    std::cout<<"Tree 1: \n";
    disp1.print();
    std::cout<<"Tree 2: \n";
    disp2.print();
    (node1.getLeft())->setLeft(node2);

    std::cout<<"Tree merged: \n";

    Showoff disp3(&node1);
    disp3.print();
    

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
    if (tc <= 0 || tc > testcases.size()) {
        for(std::vector< std::vector<int> >::size_type i = 0; i< testcases.size()-1 ; ++i)
        {
            for(std::vector<int>::size_type j = 1; j<testcases[i].size(); ++j)
                test1(testcases[i],j+1);
        }
    }
    else {
        for(std::vector< std::vector<int> >::size_type j = 1; j<testcases[tc -1].size(); ++j)
            test1(testcases[tc - 1],j+1);
    }

    //Test left/right set
    std::cout<<"<------------- TEST SET 2: SETTER  -------->\n";
    test2(testcases[0],testcases[1]);


}
#endif
/* end of Tree.cc */
