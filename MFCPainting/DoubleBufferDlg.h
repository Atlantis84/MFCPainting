#pragma once


// DoubleBufferDlg 对话框

class DoubleBufferDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DoubleBufferDlg)

public:
	DoubleBufferDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DoubleBufferDlg();

	void DrawTJGraph(CDC & graphics, int rotateValue);

	CDC MemDCIndicator;
	CBitmap MemBitmapIndicator;
	CDC *pDC;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOUBLEBUFFER
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
};
