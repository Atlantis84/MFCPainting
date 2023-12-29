#pragma once


// LinearGradientTwoDlg 对话框

class LinearGradientTwoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LinearGradientTwoDlg)

public:
	LinearGradientTwoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LinearGradientTwoDlg();

	void DrawFunction();
	CDC MemDCIndicator;
	CBitmap MemBitmapIndicator;
	CDC *pDC;
	CComboBox m_pGradientMode;

	LinearGradientMode m_pLinearGradientMode;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEARGRADIENTEXTWODLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
};
