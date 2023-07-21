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

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEARGRADIENTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CColorCombo m_pColor1;
	CColorCombo m_pColor2;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboForecolor();
	afx_msg void OnSelchangeComboBackcolor();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
