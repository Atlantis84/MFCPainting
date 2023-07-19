// TextureBrushDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "TextureBrushDlg.h"
#include "afxdialogex.h"


// TextureBrushDlg 对话框

IMPLEMENT_DYNAMIC(TextureBrushDlg, CDialogEx)

TextureBrushDlg::TextureBrushDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TBDLG, pParent)
{

}

TextureBrushDlg::~TextureBrushDlg()
{
}

void TextureBrushDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TextureBrushDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// TextureBrushDlg 消息处理程序


void TextureBrushDlg::OnPaint()
{
	CPaintDC dc(this);
	Graphics graphics(dc);
	Gdiplus::TextureBrush tba(&Image(L"F://bb.bmp"),WrapMode::WrapModeTileFlipY);
	CRect crt;
	GetClientRect(&crt);
	graphics.FillRectangle(&tba, crt.left, crt.top, crt.Width(), crt.Height());		  
}
