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
END_MESSAGE_MAP()


// LinearGradientDlg 消息处理程序


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

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void LinearGradientDlg::OnSelchangeComboForecolor()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pColorRef1 = m_pColor1.GetItemData(m_pColor1.GetCurSel());
	Invalidate();
}


void LinearGradientDlg::OnSelchangeComboBackcolor()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pColorRef2 = m_pColor2.GetItemData(m_pColor2.GetCurSel());
	Invalidate();
}


void LinearGradientDlg::OnPaint()
{
	CPaintDC dc(this);
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	CRect crt;
	GetClientRect(&crt);
	LinearGradientBrush lbr(Point(0, 0), Point(crt.Width() / 2, 0),
		Color(GetRValue(m_pColorRef1), GetGValue(m_pColorRef1), GetBValue(m_pColorRef1)),
		Color(GetRValue(m_pColorRef2), GetGValue(m_pColorRef2), GetBValue(m_pColorRef2)));

	graphics.FillEllipse(&lbr, Rect(0, 0, crt.Width() / 2, crt.Height()/2));
	graphics.FillRectangle(&lbr, Rect(crt.Width() / 2, 0, crt.Width() / 2, crt.Height() / 2));
}


void LinearGradientDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnMouseMove(nFlags, point);
}
