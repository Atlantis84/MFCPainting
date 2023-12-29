
// MFCPaintingDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCPainting.h"
#include "MFCPaintingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPaintingDlg 对话框

CMFCPaintingDlg::CMFCPaintingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPAINTING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPaintingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCPaintingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SHOWWINDOW()
	//ON_WM_NCPAINT()
END_MESSAGE_MAP()


// CMFCPaintingDlg 消息处理程序

BOOL CMFCPaintingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//ShowWindow(SW_SHOWMAXIMIZED);
	// TODO: 在此添加额外的初始化代码
	SetWindowPos(NULL, 100, 100, 600, 400, SWP_NOZORDER);
	//SetTimer(1, 50, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
static int value = 0;
void CMFCPaintingDlg::OnPaint()
{
	CPaintDC dc(this);
	Graphics graphics(dc);
	/*value += 5;
	DrawTJGraph(graphics, value);*/
	DrawBasics(graphics);
	CDialogEx::OnPaint();
}

void CMFCPaintingDlg::DrawBasics(Graphics & graphics)
{
	//graphics.SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeHighQuality);
	CRect rt;
	GetClientRect(&rt);
	RectF rtt(rt.left, rt.top, rt.Width(), rt.Height());
	graphics.FillRectangle(&SolidBrush(Color(255, 255, 255)), rtt);
#if 0 //路径叠加
	GraphicsPath pa;
	pa.AddEllipse(0, 0, rt.Width(), rt.Height());
	Region rg(Rect(0, 0, rt.Width(), rt.Height()));
	rg.Exclude(&pa);
	graphics.FillRegion(&SolidBrush(Color(255, 0, 0)), &rg);

	GraphicsPath pa;
	pa.AddRectangle(Rect(0, 0, rt.Width(), rt.Height()));
	pa.AddEllipse(Rect(0, 0, rt.Width(), rt.Height()));
	graphics.FillPath(&SolidBrush(Color(255, 0, 0)), &pa);
	return;
#endif

	//字符串测量
	WCHAR string[] = L"上善若水";
	Gdiplus::Font ft(L"KaiTi", 70);
	RectF layoutRect(10.0f, 10.0f, 200.0f, 330.0f);
	StringFormat strF;
	strF.SetAlignment(StringAlignmentFar);
	RectF boundRect;
	graphics.DrawRectangle(&Pen(Color(255, 0, 0)), layoutRect);
	graphics.MeasureString(string, 4, &ft, layoutRect, &strF, &boundRect);
	graphics.DrawString(string, 4, &ft, boundRect, &strF, &SolidBrush(Color(0, 255, 0)));
	graphics.DrawRectangle(&Pen(Color(0, 0, 255)), boundRect);
	return;

	//画点
	graphics.DrawEllipse(&Pen(Color(255, 0, 0)), 50, 50, 1, 1);
	//单线
	graphics.DrawLine(&Pen(Color(255, 0, 0),2), PointF(0, 10), PointF(rt.Width(), 10));
	//多线
	PointF point1(10.0f, 10.0f),point2(10.0f, 100.0f),point3(200.0f, 50.0f),point4(250.0f, 80.0f);
	PointF points[4] = { point1, point2, point3, point4 };
	PointF* pPoints = points;
	graphics.DrawLines(&Pen(Color(0, 0, 255),2), pPoints, 4);
	//单方框
	Rect rect(250, 80, 100, 100);
	graphics.DrawRectangle(&Pen(Color(255, 0, 0),2), rect);
	//graphics.FillRectangle
	//graphics.DrawRectangles
	//graphics.FillRectangles
	//填充圆
	Rect rect1(350, 180, 100, 100);
	graphics.DrawRectangle(&Pen(Color(0, 255, 0), 2), rect1);
	graphics.FillEllipse(&SolidBrush(Color(255, 255, 0)), rect1);
	graphics.DrawEllipse(&Pen(Color(255, 0, 0)), rect1);
	// 画曲线及封闭曲线
	Pen greenPen(Color::Green, 3);
	PointF point11(450.0f, 130.0f), point12(550.0f, 80.0f),point13(650.0f, 40.0f),point14(750.0f, 130.0f);
	PointF curvePoints[4] = {point11,point12,point13,point14 };
	PointF point21(455.0f, 130.0f),point22(555.0f, 80.0f),point23(655.0f, 40.0f),point24(755.0f, 130.0f);
	PointF curvePoints1[4] = {point21,point22,point23,point24 };
	//graphics.DrawCurve(&greenPen, curvePoints,4,0.9);
	graphics.DrawClosedCurve(&greenPen, curvePoints1, 4, 0.9);
	graphics.FillClosedCurve(&SolidBrush(Color(255, 0, 0)), curvePoints1, 4);
	//画弧线
	Pen redPen(Color::Red, 3);
	RectF ellipseRect(250, 280, 100, 100);
	REAL startAngle = 180.0f;//起始度数  
	REAL sweepAngle = 90.0f;//结尾时的度数  
	graphics.DrawRectangle(&Pen(Color(255, 0, 0), 2), ellipseRect);
	graphics.DrawArc(&redPen, ellipseRect, startAngle, sweepAngle);
	//画扇形
	Pen blackPen(Color(255, 0, 255, 0), 3);
	RectF ellipseRect1(400, 230, 100, 100);
	REAL startAngle1 = 40.0f;
	REAL sweepAngle1 = 100.0f;
	graphics.DrawPie(&blackPen, ellipseRect1, startAngle1, sweepAngle1);
	//graphics.FillPie
	//写字
	//graphics.DrawString
	//贝塞尔曲线
	//graphics.DrawBezier
	//绘制多边形
	//graphics.DrawPolygon
	//绘制路径
	//graphics.DrawPath
}

void CMFCPaintingDlg::DrawTJGraph(Graphics & graphics, int rotateValue)
{
	CRect rect;
	CPoint pt;
	int r=200;
	GetClientRect(&rect);
	graphics.TranslateTransform(rect.Width()/2, rect.Height()/2);
	graphics.RotateTransform(rotateValue);

	graphics.FillPie(&SolidBrush(Color(255, 255, 255)), -r / 2, -r / 2, r, r, 90, 180);
	graphics.FillPie(&SolidBrush(Color(0, 0, 0)), -r / 2, -r / 2, r, r, -90, 180);

	graphics.FillEllipse(&SolidBrush(Color(255, 255, 255)), -r / 4, -r / 2, r / 2, r / 2);
	graphics.FillEllipse(&SolidBrush(Color(0, 0, 0)), -r / 4, 0, r / 2, r / 2);

	graphics.FillEllipse(&SolidBrush(Color(0, 0, 0)), -r / 8, -3 * r / 8, r / 4, r / 4);
	graphics.FillEllipse(&SolidBrush(Color(255, 255, 255)), -r / 8, r / 8, r / 4, r / 4);
}
void CMFCPaintingDlg::DrawTJGraph(CDC & dc, int rotateValue)
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
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCPaintingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPaintingDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//TRACE("test\r\n");
	
	Invalidate();
	CDialogEx::OnTimer(nIDEvent);
}


void CMFCPaintingDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	// TODO: 在此处添加消息处理程序代码
	CDialogEx::OnShowWindow(bShow, nStatus);
}


//void CMFCPaintingDlg::OnNcPaint()
//{
//	 /*TODO: 在此处添加消息处理程序代码
//	 不为绘图消息调用 CDialogEx::OnNcPaint()*/
//	CWindowDC dc(this);
//	TRACE("SSSSSSSSSSSSSS\r\n");
//	Graphics graphics(dc);
//	graphics.DrawEllipse(&Pen(Color(255, 0, 0)), 0, 0, 100, 100);
//}
