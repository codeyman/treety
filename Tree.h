/*
 * File name: TreeNode.h
 * Date:      2013/11/13 15:47
 * Author:    Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description: TreeNode node
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
#include <iostream>
#include <queue>
#include <cassert>

class TreeNode {
    private:
        int _data;
    protected:
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
    public:
        TreeNode();
        explicit TreeNode(int val);
        virtual ~TreeNode(); 

        /****************************************/
        // Setters and getters  
        void setLeft(const int &val);
        void setRight(const int &val);
        void setLeft(TreeNode *node);
        void setRight(TreeNode *node);
        void setParent(TreeNode *node);

        // The derived classes should call use 
        // dynamic_cast to get the correct pointer,
        // else we get a compilation error.
        TreeNode *getLeft();
        TreeNode *getRight();
        TreeNode *getParent();

        int getData();
        /****************************************/
          
};

template <class T = TreeNode> class Tree;

template <class T>
class Tree {
    private:
        T *root;
    public:
        Tree();
        virtual ~Tree() { if(root) delete root; }
        void initTree(const std::vector< int > &val, int count);
        void printBFS();

        //We had to templatize this because we want the caller to 
        //call the constructor for derived class when adding new 
        //nodes
        T *addBST(int val);
        T *getRoot() { return root;}
        void setRoot(T *node) { root = node;}

        virtual void insert(int val);


};

template <class T>
Tree<T>::Tree():root(NULL){}


template< class T >
void Tree<T>::initTree(const std::vector< int > &val, int count)
{
    int i=1;
    assert(count >= 1);
    if(!root) root = new T(val[0]);
    for(;i<count;++i) {
        insert(val[i]);
    }
}

template< class T >
void Tree<T>::insert(int val)
{
    addBST(val);
}

template< class T >
void Tree<T>::printBFS()
{
    std::queue<T *> tqueue;
    tqueue.push(this);
    while(!tqueue.empty()) {
        T *temp = tqueue.front();
        tqueue.pop();
        std::cout<<" "<<temp->_data;
        if(temp->left) tqueue.push(temp->left);
        if(temp->right) tqueue.push(temp->right);
    }
    std::cout<<std::endl;
}
template< class T >
T* Tree<T>::addBST(int val)
{
    T *node = NULL;
    T *tmp = NULL;
    node = root;
    while(node!= NULL) {
        if(val<=node->getData()) {
            if(node->getLeft() == NULL) {
                tmp = new T(val);
                node->setLeft(tmp);
                return tmp;
            }
            else 
            {
                node = node->getLeft();
            }
        }
        else {
            if(node->getRight() == NULL) {
                tmp = new T(val);
                node->setRight(tmp);
                return tmp;
            }
            else {
                node = node->getRight();
            }
        }
    }

    //Should never come here
    return NULL; 

}

#endif

/* end of Tree.h */
