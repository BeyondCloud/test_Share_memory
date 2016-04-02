#include "ShareMem.h"
#include "windows.h"  //for TCHAR
#include <iostream>

using namespace std;
TCHAR name[] = TEXT("bitmap");
int main()
{

    bool foo[307200],foo2[3]={0,0,0};
    for(int i=0;i<307200;i++)
    {
        foo[i]=i%2;
    }
    ShareMem sh(name,foo,sizeof(foo));
  //  sh.createTable(foo,sizeof(foo));

	system("pause");
}
