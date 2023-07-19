#pragma once


// MFCColor 对话框

class MFCColor : public CDialogEx
{
	DECLARE_DYNAMIC(MFCColor)

public:
	MFCColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCColor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
