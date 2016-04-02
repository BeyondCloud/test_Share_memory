#ifndef ShareMem_H
#define ShareMem_H
#include <tchar.h>
using namespace std;
class ShareMem
{
    public:
        ShareMem();
        void createTable(void *ptr,TCHAR*,int);
        void* accessTable(TCHAR*,int);


};

#endif
