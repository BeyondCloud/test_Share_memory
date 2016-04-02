#include "ShareMem.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>

#define BUF_SIZE 0xFFFFF
using namespace std;
ShareMem::ShareMem()
{

}
void ShareMem::createTable(void *ptr,TCHAR* Name,int size)
{

    HANDLE hMapFile;
    // create a file mapping object with CreateFileMapping first
    hMapFile =   CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD( upper 32 bit unsigned int))
                 BUF_SIZE,                // maximum object size (low 32 bit DWORD)
                 Name);                 // name of mapping object

   if (hMapFile != NULL)
   {

        // create a pointer to the actual data with MapViewOfFile
        void* bBuf;
        bBuf = (PVOID) MapViewOfFile(hMapFile,   // handle to map object
                            FILE_MAP_ALL_ACCESS, // read/write permission
                            0,
                            0,
                            BUF_SIZE);

        if (bBuf != NULL)
        {
             CopyMemory(bBuf, ptr,307200);  //size cannot exceed 4096
        }
        else
            cout<<"Could not map view of file";


   }
   else
            cout<<"Could not open file mapping object";

}

