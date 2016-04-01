#include "ShareMem.h"
#include "windows.h"  //for TCHAR
using namespace std;
TCHAR name[] = TEXT("Global\\MyFileMappingObject");
int main()
{
    bool foo[3]={1,0,1},foo2[3]={0,0,0};

    ShareMem sh(foo,name,sizeof(foo));


	foo2[0]=(*(bool *)sh.pointer);

	system("pause");
}
