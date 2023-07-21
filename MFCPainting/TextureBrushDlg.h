#pragma once


// TextureBrushDlg 对话框

class TextureBrushDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TextureBrushDlg)

public:
	TextureBrushDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TextureBrushDlg();
	WrapMode m_pCurrentWrapMode;
	CComboBox m_pStyle;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TBDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
};
