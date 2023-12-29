#pragma once

#include "CColorCombo.h"
// LinearGradientDlg 对话框

class LinearGradientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LinearGradientDlg)

public:
	LinearGradientDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LinearGradientDlg();

	COLORREF m_pColorRef1;
	COLORREF m_pColorRef2;
	Point m_pPoint1;
	Point m_pPoint2;
	GraphicsPath m_pPath1;
	GraphicsPath m_pPath2;

	bool m_pLBDown;
	bool m_pRBDown;

	CDC MemDCIndicator;
	CBitmap MemBitmapIndicator;
	CDC *pDC;

	CColorCombo m_pColor1;
	CColorCombo m_pColor2;

	void DrawFunction();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEARGRADIENTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboForecolor();
	afx_msg void OnSelchangeComboBackcolor();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};
