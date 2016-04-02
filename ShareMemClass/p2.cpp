#include <iostream>
#include "ShareMem.h"
#include <tchar.h>
#include "windows.h"

TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
using namespace std;
int main()
{
	ShareMem sh;
	bool* ptr = (bool *)sh.accessTable(szName,307200);
	bool test[307200];
	if(ptr != NULL)
    {
       	for(int i=0;i<307200;i++)
            test[i] = *(ptr + i);
        for(int i=0;i<100;i++)
            cout<<test[i];
    }
    else
        cout << "ptr = NULL";
    system ("pause");

	return 0;
}
