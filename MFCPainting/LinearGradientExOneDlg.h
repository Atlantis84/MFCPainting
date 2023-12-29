#pragma once


// LinearGradientExOneDlg 对话框

class LinearGradientExOneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LinearGradientExOneDlg)

public:
	LinearGradientExOneDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LinearGradientExOneDlg();

	CDC MemDCIndicator;
	CBitmap MemBitmapIndicator;
	CDC *pDC;

	REAL m_pRealValue;
	CSliderCtrl m_pSlider;

	void DrawFunction();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LinearGradientExOneDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
};
