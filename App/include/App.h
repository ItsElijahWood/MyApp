#pragma once

#include <windows.h>

#include "resource.h"

// Global Variables
extern HINSTANCE hInst;
extern WCHAR szTitle[];
extern WCHAR szWindowClass[];

// Function Declarations
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
