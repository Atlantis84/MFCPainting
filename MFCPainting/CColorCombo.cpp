#include "pch.h"
#include "CColorCombo.h"

IMPLEMENT_DYNAMIC(CColorCombo, CComboBox)
CColorCombo::CColorCombo()
{
}

CColorCombo::~CColorCombo()
{
}

int CColorCombo::AddItem(LPCTSTR lpszText, COLORREF clrValue)
{
	int nIndex = AddString(lpszText);
	SetItemData(nIndex, clrValue);
	return nIndex;

}

void CColorCombo::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	ASSERT(lpDrawItemStruct->CtlType = ODT_COMBOBOX);

	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect itemRC(lpDrawItemStruct->rcItem);
	CRect clrRC = itemRC;
	//�����ı�����
	CRect textRC = itemRC;
	//��ȡϵͳ�ı���ɫ
	COLORREF clrText = GetSysColor(COLOR_WINDOWTEXT);
	//��ʱ���ı���ɫ
	COLORREF clrSelected = GetSysColor(COLOR_HIGHLIGHT);
	//��ȡ���ڱ�����ɫ
	COLORREF clrNormal = GetSysColor(COLOR_WINDOW);
	//��ȡ��ǰ��Ŀ����
	int nIndex = lpDrawItemStruct->itemID;
	//�ж���Ŀ״̬
	int nState = lpDrawItemStruct->itemState;
	if (nState & ODS_SELECTED) // ������״̬
	{
		dc.SetTextColor((0x00FFFFFF & ~(clrText))); // �ı���ɫȡ��
		dc.SetBkColor(clrSelected); // �����ı�������ɫ
		dc.FillSolidRect(&clrRC, clrSelected); // �����Ŀ����Ϊ����Ч��
	}
	else
	{
		dc.SetTextColor(clrText);// �����������ı���ɫ
		dc.SetBkColor(clrNormal);//�����������ı�������ɫ
		dc.FillSolidRect(&clrRC, clrNormal);


	}
	if (nState & ODS_FOCUS) // �����Ŀ��ȡ���㣬���ƽ�������
	{
		dc.DrawFocusRect(&itemRC);
	}
	//�����ı�����
	int nclrWidth = itemRC.Width() / 4;
	textRC.left = nclrWidth + 55;
	//������ɫ��ʾ����
	clrRC.DeflateRect(2, 2);
	clrRC.right = nclrWidth + 50;
	//������ɫ�ı����������ɫ����
	if (nIndex != -1) // ��Ŀ��Ϊ��
	{
		//��ȡ��Ŀ��ɫ
		COLORREF clrltem = lpDrawItemStruct->itemData;//GetItemData(nIndex);
		dc.SetBkMode(TRANSPARENT);
		//��ȡ�ı�
		CString sZText;
		GetLBText(nIndex, sZText);
		//����ı�
		dc.DrawText(sZText, textRC, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		dc.FillSolidRect(&clrRC, clrltem);
		//�����ɫ
		dc.FrameRect(&clrRC, &CBrush(RGB(0, 0, 0)));

	}
	dc.Detach();
	return;
}
BEGIN_MESSAGE_MAP(CColorCombo, CComboBox)
END_MESSAGE_MAP()
