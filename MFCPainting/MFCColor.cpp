// MFCColor.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "MFCColor.h"
#include "afxdialogex.h"


// MFCColor 对话框

IMPLEMENT_DYNAMIC(MFCColor, CDialogEx)

MFCColor::MFCColor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COLOR, pParent)
{

}

MFCColor::~MFCColor()
{
}

void MFCColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCColor, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MFCColor 消息处理程序


void MFCColor::OnPaint()
{
	CPaintDC dc(this);
	Graphics graphics(dc);

	Color clr(255, 0, 0);
	Color clg(0, 255, 0);
	Color clb(0, 0, 255);

	Pen pr(clr, 2.0);
	Pen pg(clg, 2.0);
	Pen pb(clb, 2.0);

	graphics.DrawLine(&pr, 0, 0, 100, 100);
	graphics.DrawLine(&pg, 100, 100, 200, 0);
	graphics.DrawLine(&pb, 200, 0, 300, 100);

	Color clra(100, 255, 0, 0);
	Color clga(100, 0, 255, 0);
	Color clba(100, 0, 0, 255);

	Pen pra(clra, 2.0);
	Pen pga(clga, 2.0);
	Pen pba(clba, 2.0);

	graphics.DrawLine(&pra, 0, 100, 100, 200);
	graphics.DrawLine(&pga, 100, 200, 200, 100);
	graphics.DrawLine(&pba, 200, 100, 300, 200);
}
