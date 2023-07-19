// DoubleBufferDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "DoubleBufferDlg.h"
#include "afxdialogex.h"


// DoubleBufferDlg 对话框

IMPLEMENT_DYNAMIC(DoubleBufferDlg, CDialogEx)

DoubleBufferDlg::DoubleBufferDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DOUBLEBUFFER, pParent)
{
	
}

DoubleBufferDlg::~DoubleBufferDlg()
{
}

void DoubleBufferDlg::DrawTJGraph(CDC & dc, int rotateValue)
{
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	CRect rect;
	int r = 200;
	GetClientRect(&rect);
	graphics.TranslateTransform(rect.Width() / 2, rect.Height() / 2);
	graphics.RotateTransform(rotateValue);

	graphics.FillPie(&SolidBrush(Color(255, 255, 255)), -r / 2, -r / 2, r, r, 90, 180);
	graphics.FillPie(&SolidBrush(Color(0, 0, 0)), -r / 2, -r / 2, r, r, -90, 180);

	graphics.FillEllipse(&SolidBrush(Color(255, 255, 255)), -r / 4, -r / 2, r / 2, r / 2);
	graphics.FillEllipse(&SolidBrush(Color(0, 0, 0)), -r / 4, 0, r / 2, r / 2);

	graphics.FillEllipse(&SolidBrush(Color(0, 0, 0)), -r / 8, -3 * r / 8, r / 4, r / 4);
	graphics.FillEllipse(&SolidBrush(Color(255, 255, 255)), -r / 8, r / 8, r / 4, r / 4);
}

void DoubleBufferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DoubleBufferDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// DoubleBufferDlg 消息处理程序
void DoubleBufferDlg::OnPaint()
{
	CPaintDC dc(this); 
}

static int value = 0;
void DoubleBufferDlg::OnTimer(UINT_PTR nIDEvent)
{
	value += 5;
	CRect rt;
	GetClientRect(&rt);
	pDC = GetDC();
	//创建内存中的显示设备
	MemDCIndicator.CreateCompatibleDC(pDC);
	//创建内存中的图像
	MemBitmapIndicator.CreateCompatibleBitmap(pDC, rt.Width(), rt.Height());
	//指定内存显示设备在内存图像上画图
	MemDCIndicator.SelectObject(&MemBitmapIndicator);
	//初始化绘图背景
	MemDCIndicator.FillSolidRect(rt, RGB(100, 100, 100));
	//功能函数
	DrawTJGraph(MemDCIndicator, value);
	//将内存中图像呈现
	pDC->BitBlt(rt.left, rt.top, rt.Width(), rt.Height(), &MemDCIndicator, 0, 0, SRCCOPY);
	//释放资源
	MemDCIndicator.DeleteDC();
	MemBitmapIndicator.DeleteObject();
	ReleaseDC(pDC);
	CDialogEx::OnTimer(nIDEvent);
}


BOOL DoubleBufferDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 50, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
