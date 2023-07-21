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
	DDX_Control(pDX, IDC_COMBO1, m_pStyle);
}

BEGIN_MESSAGE_MAP(TextureBrushDlg, CDialogEx)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO1, &TextureBrushDlg::OnSelchangeCombo1)
END_MESSAGE_MAP()

void TextureBrushDlg::OnPaint()
{
	CPaintDC dc(this);
	Graphics graphics(dc);
	Rect rt(0, 0, 100, 150);
	Gdiplus::TextureBrush tba(&Image(L".//bb.bmp"), m_pCurrentWrapMode, 15, 15, 50, 50);
	graphics.FillRectangle(&tba, 0, 0, 400, 300);
	//图像原图
	//graphics.DrawImage(&Image(L".//bb.bmp"), 100, 0, 100, 150);
}

BOOL TextureBrushDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowPos(NULL, 500, 500, 420, 410, SWP_NOZORDER);
	m_pStyle.InsertString(0, L"WrapModeTile");
	m_pStyle.InsertString(1, L"WrapModeTileFlipX");
	m_pStyle.InsertString(2, L"WrapModeTileFlipY");
	m_pStyle.InsertString(3, L"WrapModeTileFlipXY");
	m_pStyle.InsertString(4, L"WrapModeClamp");
	m_pStyle.SetCurSel(0);
	m_pCurrentWrapMode = WrapModeClamp;
	return TRUE;
}

void TextureBrushDlg::OnSelchangeCombo1()
{
	switch (m_pStyle.GetCurSel())
	{
	case 0:
		m_pCurrentWrapMode = WrapModeTile;
		break;
	case 1:
		m_pCurrentWrapMode = WrapModeTileFlipX;
		break;
	case 2:
		m_pCurrentWrapMode = WrapModeTileFlipY;
		break;
	case 3:
		m_pCurrentWrapMode = WrapModeTileFlipXY;
		break;
	case 4:
		m_pCurrentWrapMode = WrapModeClamp;
		break;
	default:
		m_pCurrentWrapMode = WrapModeTile;
		break;
	}
	Invalidate();
}
