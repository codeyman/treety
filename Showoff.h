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

class Showoff {
    private:
        int height;
        int width;
        int headLoc;
        char **bmp;

    public:
        Showoff():height(1),width(1),headLoc(0) 
        {
            bmp = new char*[1];
            bmp[0] = new char[1];
        }

        Showoff(int h, int w, int l):height(h),width(w),headLoc(l) 
        {
            bmp = new char*[h];
            for(int i=0; i<h ; ++i)
                bmp[i] = new char[w];
        }

        ~Showoff()
        {
            for(int i=0; i<height ; ++i)
                delete (bmp[i]);
            delete (bmp);
        }

        void clearbmp()
        {
            for(int i=0;i<height ;++i)
                for(int j=0; j<width; ++j)
                    bmp[i][j]='.';
        }

        void print();

        int getHeight() 
        {
            return height;
        }

        int getWidth()
        {
            return width;
        }

        int getHeadLoc()
        {
            return headLoc;
        }


        void setAtOffset(const int &x, const int &y, Showoff *n);
        void setAtOffset(const int &x, const int &y, char c);
        void setAtOffset(const int &x, const int &y, int val);

};

#endif

/* end of Showoff.h */
