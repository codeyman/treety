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

AVLTree::AVLTree():Tree(),balanceFactor(0){}


void AVLTree::insert(int val)
{
    std::cout<<"Calling child insert: "<<val<<std::endl;
    addBST(val);
}
#ifdef TEST_AVLTREE
void test1(const std::vector<int> &x,int num)
{
    AVLTree node;
    node.initTree(x,num);
    Showoff disp(&node);
    disp.print();
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
}
#endif
/* end of AVLTree.cc */
