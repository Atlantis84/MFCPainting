// LinearGradientTwoDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "LinearGradientTwoDlg.h"
#include "afxdialogex.h"


// LinearGradientTwoDlg 对话框

IMPLEMENT_DYNAMIC(LinearGradientTwoDlg, CDialogEx)

LinearGradientTwoDlg::LinearGradientTwoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINEARGRADIENTEXTWODLG, pParent)
{

}

LinearGradientTwoDlg::~LinearGradientTwoDlg()
{
}

void LinearGradientTwoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_pGradientMode);
}

BEGIN_MESSAGE_MAP(LinearGradientTwoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO1, &LinearGradientTwoDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

void LinearGradientTwoDlg::OnPaint()
{
	CPaintDC dc(this);
	DrawFunction();
}

BOOL LinearGradientTwoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_pGradientMode.InsertString(0,L"LinearGradientModeHorizontal");
	m_pGradientMode.InsertString(1, L"LinearGradientModeVertical");
	m_pGradientMode.InsertString(2, L"LinearGradientModeForwardDiagonal");
	m_pGradientMode.InsertString(3, L"LinearGradientModeBackwardDiagonal");
	m_pGradientMode.SetCurSel(0);
	m_pLinearGradientMode = LinearGradientModeHorizontal;
	return TRUE;			
}


void LinearGradientTwoDlg::DrawFunction()
{
	CRect rt;
	GetClientRect(&rt);
	pDC = GetDC();
	MemDCIndicator.CreateCompatibleDC(pDC);
	MemBitmapIndicator.CreateCompatibleBitmap(pDC, rt.Width(), rt.Height() * 2/ 3);
	MemDCIndicator.SelectObject(&MemBitmapIndicator);
	MemDCIndicator.FillSolidRect(rt, RGB(100, 100, 100));

	Graphics graphics(MemDCIndicator);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	LinearGradientBrush lbr(Rect(0, 0, rt.Width(), rt.Height() * 2/ 3), Color(255, 0, 0), Color(0, 255, 0), m_pLinearGradientMode);
	graphics.FillRectangle(&lbr, rt.left, rt.top, rt.Width(), rt.Height() * 2/ 3);
	pDC->BitBlt(rt.left, rt.top, rt.Width(), rt.Height() * 2/ 3, &MemDCIndicator, 0, 0, SRCCOPY);
	MemDCIndicator.DeleteDC();
	MemBitmapIndicator.DeleteObject();
	ReleaseDC(pDC);
}
void LinearGradientTwoDlg::OnCbnSelchangeCombo1()
{
	switch (m_pGradientMode.GetCurSel()) {
	case 0:
		m_pLinearGradientMode = LinearGradientModeHorizontal;
		break;
	case 1:
		m_pLinearGradientMode = LinearGradientModeVertical;
		break;
	case 2:
		m_pLinearGradientMode = LinearGradientModeForwardDiagonal;
		break;
	case 3:
		m_pLinearGradientMode = LinearGradientModeBackwardDiagonal;
		break;
	default:
		break;
	}
	Invalidate();
}
