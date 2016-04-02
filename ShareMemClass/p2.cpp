#include <iostream>
#include "ShareMem.h"
#include <tchar.h>
#include "windows.h"

TCHAR szName[]=TEXT("bitmap");
using namespace std;
int main()
{
	ShareMem sh(szName);
	bool* ptr = (bool *)sh.readMem();
	bool test[307200];
	if(ptr != NULL)
    {
       	for(int i=0;i<sh.getBufferSize();i++)
            test[i] = *(ptr + i);
        for(int i=0;i<100;i++)
            cout<<test[i];
    }
    else
        cout << "ptr = NULL";
    system ("pause");

	return 0;
}
