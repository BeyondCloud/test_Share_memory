#include "ShareMem.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#define BUF_SIZE 256
ShareMem::ShareMem()
{

}
void ShareMem::createTable(void *ptr,TCHAR* Name,int size)
{

    HANDLE hMapFile;
    hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 Name);                 // name of mapping object

   if (hMapFile != NULL)
   {

        void* bBuf;
        bBuf = (PVOID) MapViewOfFile(hMapFile,   // handle to map object
                            FILE_MAP_ALL_ACCESS, // read/write permission
                            0,
                            0,
                            BUF_SIZE);

        if (bBuf != NULL && size <=4096 )
            CopyMemory(bBuf, ptr,size);  //size cannot exceed 4096
        else if(size>4096)
            cout<<"size exceed 4096";
        else
            cout<<"Could not map view of file";


   }
        else
            cout<<"Could not open file mapping object";

}

