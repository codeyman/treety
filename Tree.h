/*
 * File name: Tree.h
 * Date:      2013/11/13 15:47
 * Author:    Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description: Tree node
 *
 */

#ifndef __TREE_H__
#define __TREE_H__
/*
 * Class Operations
 * ================
 *
 * Public Interfaces
 * =================
 * 
 * Maintenance History
 * ==================
 *
 */
#include <vector>
#include <exception>
#include <iostream>

class Tree {
    private:
        int _data;
        Tree *left;
        Tree *right;
        Tree *parent;
    public:
        Tree();
        Tree(int val);
        virtual ~Tree(); 

        /****************************************/
        // Setters and getters  
        void setLeft(const int &val);
        void setRight(const int &val);
        void setLeft(Tree *node);
        void setRight(Tree *node);

        // The derived classes should call use 
        // dynamic_cast to get the correct pointer,
        // else we get a compilation error.
        Tree *getLeft();
        Tree *getRight();
        Tree *getParent();

        int getData();
        /****************************************/
          
        //void printDFS();
        void initTree(const std::vector< int > &val, int count);
        void printBFS();

        //We had to templatize this because we want the caller to 
        //call the constructor for derived class when adding new 
        //nodes
        template<class T>
        T *addBST(int val);

        virtual void insert(int val);
};

template< class T = Tree>
T* Tree::addBST(int val)
{
    T *node = NULL;
    try {
        if(val<=_data) {
            if(left==NULL) {
                node=new T(val);
                node->parent = this;
                left = node;
                return node;
            }
            else 
            {
                return left->addBST<T>(val);
            }
        }
        else {
            if(right==NULL) {
                node=new T(val);
                node->parent = this;
                right = node;
                return node;
            }
            else {
                return right->addBST<T>(val);
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    //Should never come here
    return NULL; 

}

#endif

/* end of Tree.h */
