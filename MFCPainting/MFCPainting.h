
// MFCPainting.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号

/**********************GDI预定义****************************/
#ifndef ULONG_PTR
#define ULONG_PTR unsigned long
#endif
#include "GdiPlus.h"
using namespace Gdiplus;
#pragma comment(lib,"GdiPlus.lib")
/***********************************************************/
// CMFCPaintingApp:
// 有关此类的实现，请参阅 MFCPainting.cpp
//

class CMFCPaintingApp : public CWinApp
{
public:
	CMFCPaintingApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCPaintingApp theApp;
