#pragma once
#include <afxwin.h>
#pragma once
class CColorCombo :public CComboBox
{
	DECLARE_DYNAMIC(CColorCombo)

public:
	CColorCombo();
	virtual ~CColorCombo();
protected:
	DECLARE_MESSAGE_MAP();
public:
	int AddItem(LPCTSTR lpszText, COLORREF clrValue);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};
