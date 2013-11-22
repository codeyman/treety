/*
 * File name:    Showoff.cc
 * Date:         2013/11/22 01:26
 * Author:       Sridhar V Iyer (sridhiye@cisco.com)
 * Description: 
 * 
 */


#include "Showoff.h"
#include <iostream>
#include <string>
#include <cassert>

void Showoff::setAtOffset(const int &x, const int &y, char c)
{
    assert(x <= height);
    assert(y <= width );
    bmp[x][y] = c;
    print();

}

void Showoff::setAtOffset(const int &x, const int &y, Showoff *n)
{

    assert( (x + n->height) <= height );
    assert( (y + n->width) <= width );
    for(int i = 0; i < n->height; ++i)
        for(int j = 0; j < n->width; ++j){
            bmp[x+i][y+j]= n->bmp[i][j];
        }
    print();
}
void Showoff::setAtOffset(const int &x, const int &y, int val)
{
    assert(x <= height);
    assert(y <= width );
    std::string s = std::to_string(val);
    char c = s.at(0);
    bmp[x][y] = c;
    print();
}

void Showoff::print()
{
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
