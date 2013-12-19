/*
 * File name: Showoff.h
 * Date:      2013/11/14 17:55
 * Author:    Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description: 
 *
 */

#ifndef __SHOWOFF_H__
#define __SHOWOFF_H__
/*
 * Class Operations
 * ================
 * setWidth: frees the internal char **bmp, and allocates a new for the width.
 * init: initialize the internal data structure. Could be called from constructor.
 * clearbmp: clears up everything in the internal 2d array.
 * setAtOffset: updates the internal 2d array with data. There is scope of templatization here. 
 * getHeight/getWidth/getHeadLoc/getHeadWidth/setHeadLoc: getters and setters.
 * 
 * Public Interfaces
 * =================
 * print: the sole purpose of this class is to print tree. Everything else is private.
 *
 */

#include "Tree.h"

class Showoff {
    private:
        int height;
        int width;
        int headLoc;
        int headwidth;
        char **bmp;

    protected:
        Showoff();
        Showoff(int h, int w, int l);
        void setWidth(int w);
        void init(int h,int w, int headL, int headW);
        void clearbmp( char c);
        void setAtOffset(const int &x, const int &y, const Showoff *n);
        void setAtOffset(const int &x, const int &y, const char& c);
        void setAtOffset(const int &x, const int &y, const int& val);
        int getHeight() ;
        int getWidth();
        int getHeadLoc();
        int getHeadWidth();
        void setHeadLoc(const int &h);

    public:

        Showoff(TreeNode *node);
        ~Showoff();
        void print();
};

#endif

/* end of Showoff.h */
