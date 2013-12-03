/*
 * File name: Tree.h
 * Date:      2013/11/13 15:47
 * Author:    Sridhar V Iyer (sridhiye@cisco.com)
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

class Tree {
    private:
        int _data;
        Tree *left;
        Tree *right;
        Tree *parent;
    public:
        Tree();
        Tree(int val);
        Tree(int val[], int count);
        ~Tree(); 

        /****************************************/
        // Setters and getters  
        void setLeft(const int &val);
        void setRight(const int &val);
        void setLeft(Tree *node);
        void setRight(Tree *node);

        Tree *getLeft();
        Tree *getRight();
        Tree *getParent();
        int getData();
        /****************************************/
          
        //void printDFS();
        void printBFS();
        void addBST(int val);
};

#endif

/* end of Tree.h */
