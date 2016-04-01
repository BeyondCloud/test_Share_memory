#include "ShareMem.h"
#include "windows.h"  //for TCHAR
#include <iostream>

using namespace std;
TCHAR name[] = TEXT("Global\\MyFileMappingObject");
int main()
{
    bool foo[4096],foo2[3]={0,0,0};
    memset(foo,2,sizeof(foo));
    ShareMem sh;

    cout<< sizeof(foo);
    sh.createTable(foo,name,sizeof(foo));

	system("pause");
}
