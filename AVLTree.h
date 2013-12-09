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
#include <vector>
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

class AVLTree:public Tree {
    private:
        int balanceFactor;
    public:
        AVLTree();
        virtual void insert(int val);
};

#endif

/* end of AVLTree.h */
