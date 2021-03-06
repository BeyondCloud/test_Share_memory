#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>

#pragma comment(lib, "user32.lib")

#define BUF_SIZE 0xFFFFF
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");

int main()
{
   HANDLE hMapFile;
   LPCTSTR pBuf;
   bool* bBuf;
   hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   szName);               // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      system("pause");
      return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);
   
   bBuf = (bool*) MapViewOfFile(hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
                        0,
                        0,
                        BUF_SIZE);
   
   if (pBuf == NULL)
   {
      _tprintf(TEXT("a (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);
      return 1;
   }
   for(int i=0 ;i<307200;i++)
   std::cout<<bBuf[i];
  // MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);

   system("pause");

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}

