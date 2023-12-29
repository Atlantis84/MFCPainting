// LinearGradientDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "LinearGradientDlg.h"
#include "afxdialogex.h"

// LinearGradientDlg 对话框

IMPLEMENT_DYNAMIC(LinearGradientDlg, CDialogEx)

LinearGradientDlg::LinearGradientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINEARGRADIENTDLG, pParent)
{

}

LinearGradientDlg::~LinearGradientDlg()
{
}

void LinearGradientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FORECOLOR, m_pColor1);
	DDX_Control(pDX, IDC_COMBO_BACKCOLOR, m_pColor2);
}

BEGIN_MESSAGE_MAP(LinearGradientDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_FORECOLOR, &LinearGradientDlg::OnSelchangeComboForecolor)
	ON_CBN_SELCHANGE(IDC_COMBO_BACKCOLOR, &LinearGradientDlg::OnSelchangeComboBackcolor)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

BOOL LinearGradientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_pColor1.AddItem(_T("紫色"), RGB(128, 0, 128));
	m_pColor1.AddItem(_T("青色"), RGB(0, 255, 255));
	m_pColor1.AddItem(_T("红色"), RGB(255, 0, 0));
	m_pColor1.AddItem(_T("蓝色"), RGB(0, 0, 255));
	m_pColor1.AddItem(_T("绿色"), RGB(0, 255, 0));
	m_pColor1.AddItem(_T("黄色"), RGB(255, 255, 0));
	m_pColor1.AddItem(_T("粉色"), RGB(255, 0, 255));
	m_pColor1.AddItem(_T("棕色"), RGB(255, 128, 64));
	m_pColor1.SetCurSel(0);

	m_pColor2.AddItem(_T("紫色"), RGB(128, 0, 128));
	m_pColor2.AddItem(_T("青色"), RGB(0, 255, 255));
	m_pColor2.AddItem(_T("红色"), RGB(255, 0, 0));
	m_pColor2.AddItem(_T("蓝色"), RGB(0, 0, 255));
	m_pColor2.AddItem(_T("绿色"), RGB(0, 255, 0));
	m_pColor2.AddItem(_T("黄色"), RGB(255, 255, 0));
	m_pColor2.AddItem(_T("粉色"), RGB(255, 0, 255));
	m_pColor2.AddItem(_T("棕色"), RGB(255, 128, 64));
	m_pColor2.SetCurSel(0);

	m_pColorRef1 = RGB(255, 0, 0);
	m_pColorRef2 = RGB(0, 0, 255);

	m_pLBDown = false;
	m_pRBDown = false;

	CRect crt;
	GetClientRect(&crt);
	m_pPoint1 = Point(0,0);
	m_pPoint2 = Point(crt.Width() / 2, 0);
	m_pPath1.AddRectangle(Rect(-5, -5, 10, 10));
	m_pPath2.AddRectangle(Rect(crt.Width() / 2 - 5, -5, 10, 10));

	return TRUE;
}

void LinearGradientDlg::OnSelchangeComboForecolor()
{
	m_pColorRef1 = m_pColor1.GetItemData(m_pColor1.GetCurSel());
	Invalidate();
}

void LinearGradientDlg::OnSelchangeComboBackcolor()
{
	m_pColorRef2 = m_pColor2.GetItemData(m_pColor2.GetCurSel());
	Invalidate();
}

void LinearGradientDlg::OnPaint()
{
	CPaintDC dc(this);
	DrawFunction();
}

void LinearGradientDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_pLBDown)
	{
		m_pPoint1.X = point.x;
		m_pPoint1.Y = point.y;
		DrawFunction();
	}

	if (m_pRBDown)
	{
		m_pPoint2.X = point.x;
		m_pPoint2.Y = point.y;
		DrawFunction();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void LinearGradientDlg::DrawFunction()
{
	CRect rt;
	GetClientRect(&rt);
	pDC = GetDC();
	MemDCIndicator.CreateCompatibleDC(pDC);
	MemBitmapIndicator.CreateCompatibleBitmap(pDC, rt.Width(), rt.Height() / 2);
	MemDCIndicator.SelectObject(&MemBitmapIndicator);
	MemDCIndicator.FillSolidRect(rt, RGB(100, 100, 100));

	Graphics graphics(MemDCIndicator);
	graphics.SetSmoothingMode(SmoothingModeAntiAlias);
	LinearGradientBrush lbr(m_pPoint1, m_pPoint2,
		Color(GetRValue(m_pColorRef1), GetGValue(m_pColorRef1), GetBValue(m_pColorRef1)),
		Color(GetRValue(m_pColorRef2), GetGValue(m_pColorRef2), GetBValue(m_pColorRef2)));

	graphics.FillRectangle(&SolidBrush(Color(100, 100, 100)), Rect(0, 0, rt.Width() / 2, rt.Height() / 2));
	graphics.FillEllipse(&lbr, Rect(0, 0, rt.Width() / 2, rt.Height() / 2));
	graphics.FillRectangle(&lbr, Rect(rt.Width() / 2, 0, rt.Width() / 2, rt.Height() / 2));

	graphics.DrawRectangle(&Pen(Color(255, 255, 0), 2.0), Rect(m_pPoint1.X - 5, m_pPoint1.Y - 5, 10, 10));
	graphics.DrawRectangle(&Pen(Color(255, 255, 0), 2.0), Rect(m_pPoint2.X - 5, m_pPoint2.Y - 5, 10, 10));

	pDC->BitBlt(rt.left, rt.top, rt.Width(), rt.Height() / 2, &MemDCIndicator, 0, 0, SRCCOPY);
	MemDCIndicator.DeleteDC();
	MemBitmapIndicator.DeleteObject();
	ReleaseDC(pDC);
}

void LinearGradientDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_pLBDown = !m_pLBDown;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void LinearGradientDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pLBDown = !m_pLBDown;
	CDialogEx::OnLButtonUp(nFlags, point);
}



void LinearGradientDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_pRBDown = !m_pRBDown;
	CDialogEx::OnRButtonDown(nFlags, point);
}


void LinearGradientDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	m_pRBDown = !m_pRBDown;
	CDialogEx::OnRButtonUp(nFlags, point);
}