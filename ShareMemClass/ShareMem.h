#ifndef ShareMem_H
#define ShareMem_H
#include <tchar.h>
using namespace std;
class ShareMem
{
    public:
        ShareMem(void *ptr,TCHAR*,int);
        void *pointer;
};

#endif
