
// MFCPaintingDlg.h: 头文件
//

#pragma once


// CMFCPaintingDlg 对话框
class CMFCPaintingDlg : public CDialogEx
{
// 构造
public:
	CMFCPaintingDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void DrawBasics(Graphics& graphics);
	void DrawTJGraph(Graphics & graphics, int rotateValue);
	void DrawTJGraph(CDC & graphics, int rotateValue);

	CDC MemDCIndicator;
	CBitmap MemBitmapIndicator;
	CDC *pDC;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPAINTING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//afx_msg void OnNcPaint();
};
