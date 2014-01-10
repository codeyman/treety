/*
 * File name:    Showoff.cc
 * Date:         2013/11/22 01:26
 * Author:       Sridhar V Iyer (sridhar.v.iyer@gmail.com)
 * Description:  Implementation of Showoff
 * 
 */


#include "Showoff.h"
#include <iostream>
#include <string>
#include <cassert>

#define SEP '.'

Showoff::Showoff():height(1),width(1),headLoc(0),headwidth(1)
{
    bmp = new char*[1];
    bmp[0] = new char[1];
}

Showoff::Showoff(int h, int w, int l):height(h),width(w),headLoc(l),headwidth(1)
{
    bmp = new char*[h];
    for(int i=0; i<h ; ++i)
        bmp[i] = new char[w];
}

Showoff::Showoff(TreeNode *node)
{
    Showoff *leftS = NULL, *rightS = NULL;
    int maxh = 1, maxw = 1, leftw = 1;
    int leftHead = 0,rightHead = 0;
    int datapos = 0;
    if(!node) {
        init(0,0,0,0);
        return;
    }
    TreeNode *nodeL = node->getLeft();
    TreeNode *nodeR = node->getRight();


    if(nodeL == NULL && nodeR == NULL) {
        //Initialize internal variables
        init(1,1,0,1);

        clearbmp(SEP);
        setAtOffset(0,0,node->getData()); 
    }
    else {
        if(nodeL != NULL) {
            leftS = new Showoff(nodeL);
            maxh = leftS->getHeight();
            maxw = leftS->getWidth();
            leftw = maxw;
            leftHead = leftS->getHeadLoc();
        }

        if(nodeR != NULL) {
            rightS = new Showoff(nodeR);
            if( maxh < rightS->getHeight())
                maxh = rightS->getHeight();
            maxw += rightS->getWidth();
            rightHead = rightS->getHeadLoc();
        }

        //+1 for connectors and +1 for parent
        maxh +=2;

        //+2 for left and right connectors. +1 for parent.
        maxw +=3;

        init(maxh,maxw,(maxw/2),1);

        clearbmp(SEP);

        if(leftS && rightS)
            datapos = (3+leftHead+rightHead+leftw)/2;
        else if (leftS)
            datapos = leftHead + 2;
        else if (rightS)
            datapos = leftw + rightHead + 1;

        setAtOffset(0,datapos,node->getData());
        setHeadLoc(datapos);


        if(leftS) {
            setAtOffset(2,0,leftS);
            setAtOffset(1,leftHead+1,'/');
            delete leftS;
        }

        if(rightS){
            setAtOffset(1,leftw+rightHead+2,'\\');
            setAtOffset(2,leftw+3,rightS);
            delete rightS; 
        }

    }

    
}

Showoff::~Showoff()
{
    for(int i=0; i<height ; ++i)
        delete (bmp[i]);
    delete (bmp);
}

void Showoff::setWidth(int w)
{
    char **bmpT = new char*[height];
    for(int i=0; i<height ; ++i){
        bmpT[i] = new char[w];
        for(int j=0; j<width ;++j)
            bmpT[i][j] = bmp[i][j];
    }
    for(int i=0; i<height ; ++i)
        delete (bmp[i]);
    delete (bmp);
    width = w;

    bmp = bmpT;
}

void Showoff::clearbmp( char c)
{
    for(int i=0;i<height ;++i)
        for(int j=0; j<width; ++j)
            bmp[i][j]=c;
}

void Showoff::init(int h,int w, int headL, int headW)
{
    height = h;
    width = w;
    headLoc = headL;
    headwidth = headW;
    bmp = new char*[height];
    for(int i=0; i<height ; ++i)
        bmp[i] = new char[width];

}
void Showoff::setAtOffset(const int &x, const int &y, const char &c)
{
    assert(x <= height);
    assert(y <= width );
    bmp[x][y] = c;
#if DEBUG
    print();
#endif
}

void Showoff::setAtOffset(const int &x, const int &y, const Showoff *n)
{

    assert( (x + n->height) <= height );
    assert( (y + n->width) <= width );
    for(int i = 0; i < n->height; ++i)
        for(int j = 0; j < n->width; ++j){
            bmp[x+i][y+j]= n->bmp[i][j];
        }
#if DEBUG
    print();
#endif
}
void Showoff::setAtOffset(const int &x, const int &y, const int &val)
{
    assert(x <= height);
    assert(y <= width );
    std::string s = std::to_string(val);
    int temp = 0;
    headwidth = s.length();
    if (y + headwidth  > width){
        temp = y + headwidth ;
        if (temp < headwidth) 
            temp = headwidth;
        if (temp != width){
            width = temp;
            setWidth(width);
        }
    }
    for (std::string::size_type i=0; i<s.length(); ++i)
        bmp[x][y+i] = s.at(i);

#if DEBUG
    print();
#endif
}

/****************************************
 * 2013/12/02: Getters & Setters  
 **************************************/
int Showoff::getHeight() 
{
    return height;
}

int Showoff::getWidth()
{
    return width;
}


int Showoff::getHeadLoc()
{
    return headLoc;
}

int Showoff::getHeadWidth()
{
    return headwidth;
}

void Showoff::setHeadLoc(const int &h)
{
    headLoc = h;
}
/****************************************/
  
void Showoff::print()
{
#if DEBUG
    std::cout<<"h:"<<height<<" w:"<<width<<" head:"<<headLoc<<std::endl;
#endif
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j)
            std::cout<<bmp[i][j];
        std::cout<<std::endl;
    }

}

#ifdef TEST_SHOWOFF
int main(int argc,char *argv[])
{
}
#endif
/* end of Showoff.cc */
