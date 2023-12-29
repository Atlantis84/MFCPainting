// LinearGradientExOneDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "LinearGradientExOneDlg.h"
#include "afxdialogex.h"


// LinearGradientExOneDlg 对话框

IMPLEMENT_DYNAMIC(LinearGradientExOneDlg, CDialogEx)

LinearGradientExOneDlg::LinearGradientExOneDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LinearGradientExOneDlg, pParent)
{

}

LinearGradientExOneDlg::~LinearGradientExOneDlg()
{
}

void LinearGradientExOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER2, m_pSlider);
}


BEGIN_MESSAGE_MAP(LinearGradientExOneDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

void LinearGradientExOneDlg::DrawFunction()
{
	CRect rt;
	GetClientRect(&rt);
	pDC = GetDC();
	MemDCIndicator.CreateCompatibleDC(pDC);
	MemBitmapIndicator.CreateCompatibleBitmap(pDC, 200, 200);
	MemDCIndicator.SelectObject(&MemBitmapIndicator);
	MemDCIndicator.FillSolidRect(rt, RGB(100, 100, 100));

	Graphics graphics(MemDCIndicator);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	LinearGradientBrush lbr(Rect(0,0, 200, 200),Color(255,0,0),Color(0,255,0),m_pRealValue,TRUE);
	graphics.FillRectangle(&lbr, rt.left, rt.top, 200, 200);
	pDC->BitBlt(rt.left, rt.top, 200, 200, &MemDCIndicator, 0, 0, SRCCOPY);
	MemDCIndicator.DeleteDC();
	MemBitmapIndicator.DeleteObject();
	ReleaseDC(pDC);
}

void LinearGradientExOneDlg::OnPaint()
{
	CPaintDC dc(this);		  
	DrawFunction();
}

void LinearGradientExOneDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar * pScrollBar)
{
	int ctrID = pScrollBar->GetDlgCtrlID();
	switch (ctrID)
	{
	case IDC_SLIDER2:
		m_pRealValue = m_pSlider.GetPos()*3;
		TRACE(L"%d\r\n", m_pSlider.GetPos());
		DrawFunction();
		break;
	}
}

BOOL LinearGradientExOneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowPos(NULL, 100, 100, 200, 300, SWP_NOZORDER);
	m_pRealValue = 0;
	return TRUE;	
}
