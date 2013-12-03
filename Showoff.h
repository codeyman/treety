/*
 * File name: Showoff.h
 * Date:      2013/11/14 17:55
 * Author:    Sridhar V Iyer (sridhiye@cisco.com)
 * Description: 
 *
 */

#ifndef __SHOWOFF_H__
#define __SHOWOFF_H__
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

        Showoff(Tree *node);
        ~Showoff();
        void print();
};

#endif

/* end of Showoff.h */
