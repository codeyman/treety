/*
 * File name: AVLTree.h
 * Date:      2013/12/06 15:05
 * Author:    Sridhar V Iyer (iyer@sridharv.net)
 * Description: Augument Tree with info needed for avl.
 *
 */

#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include "Tree.h"
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

class AVLTreeNode:public TreeNode {
    private:
        int height;
    public:
        //int height;
        AVLTreeNode();
        explicit AVLTreeNode(int val);
        AVLTreeNode *getLeft();
        AVLTreeNode *getRight();
        AVLTreeNode *getParent();

        void setHeight(int h);
        int getHeight();
        void adjustHeight();
        int balanceFactor();

        template <class N>
        friend void swapNodeData( N* node1,  N* node2);

};

class AVLTree:public Tree<AVLTreeNode> {
    private:
        void rotateRight(AVLTreeNode *node);
        void rotateLeft(AVLTreeNode *node);
        void rebalanceAncestors(AVLTreeNode *node);
        int height_i(AVLTreeNode *node);

    public:
        using Tree::Tree;
        virtual void insert(int val);
        virtual void remove(int val);

        void show();
        void verifyHeight(); //only for debugging
        void printBFS();
};

#endif

/* end of AVLTree.h */
