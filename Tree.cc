/*
 * File name:    Tree.cc
 * Date:         2013/11/13 18:46
 * Author:       Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description:  Tree implementation and test for Showoff and  Tree classes. 
 * 
 */


#include <iostream>
#include <vector>
#include "Tree.h"
#include "Showoff.h"


/****************************************
 * Constructors & Destructor 
 **************************************/
TreeNode::TreeNode():_data(0),left(NULL),right(NULL),parent(NULL) {}

TreeNode::TreeNode(int val):_data(val),left(NULL),right(NULL),parent(NULL) {}


TreeNode::~TreeNode() 
{
    if(left!=NULL) delete left;
    if(right!=NULL) delete right;
}

/****************************************/
  
//Getters & Setters

TreeNode *TreeNode::getLeft()
{
    return left;
}

TreeNode *TreeNode::getRight()
{
    return right;
}

TreeNode *TreeNode::getParent()
{
    return parent;
}

int TreeNode::getData()
{
    return _data;
}

void TreeNode::setLeft(TreeNode *node)
{
    left = node;
    if(left)
        left->parent = this;
}

void TreeNode::setParent(TreeNode *node)
{
    this->parent = node;
}

void TreeNode::setRight(TreeNode *node)
{
    right = node;
    if(right)
        right->parent = this;
}

/****************************************/
  


#ifdef TEST_TREE
void test1(const std::vector<int> &x,int num)
{
    Tree<> mytree;
    mytree.initTree(x,num);
    Showoff disp(mytree.getRoot());
    disp.print();
}

void test2(const std::vector<int> &x, int search)
{
    Tree<> mytree;
    mytree.initTree(x,x.size());
    TreeNode *node = mytree.find(search);
    if(node) std::cout<<"Found "<<search<<std::endl;
    else std::cout<<"Not Found "<<search<<std::endl;
}

void test3(const std::vector<int> &x,int num)
{
    Tree<> mytree;
    mytree.initTree(x,num);
    Showoff disp(mytree.getRoot());
    disp.print();

    mytree.remove(6);
    Showoff disp1(mytree.getRoot());
    disp1.print();

    mytree.remove(3);
    Showoff disp2(mytree.getRoot());
    disp2.print();

    mytree.remove(4);
    Showoff disp3(mytree.getRoot());
    disp3.print();

    mytree.remove(5);
    Showoff disp4(mytree.getRoot());
    disp4.print();

    mytree.remove(1);
    Showoff disp5(mytree.getRoot());
    disp5.print();

    mytree.remove(9);
    Showoff disp6(mytree.getRoot());
    disp6.print();


    mytree.remove(7);
    Showoff disp7(mytree.getRoot());
    disp7.print();


    mytree.remove(8);
    Showoff disp8(mytree.getRoot());
    disp8.print();
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
            for(std::vector<int>::size_type j = 1; j<= testcases[i].size(); ++j)
                test1(testcases[i],j);
        }
    }
    else {
        for(std::vector< std::vector<int> >::size_type j = 1; j<testcases[tc -1].size(); ++j)
            test1(testcases[tc - 1],j+1);
    }
    test3(testcases[0],7);
    test2(testcases[0],6);
    test2(testcases[0],5);
    test2(testcases[0],1);
    test2(testcases[0],2);
    test2(testcases[0],2);
    test2(testcases[0],8);
    test2(testcases[0],4);
    test2(testcases[0],0);

}
#endif
/* end of Tree.cc */
