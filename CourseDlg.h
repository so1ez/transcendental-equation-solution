#pragma once

#include "CCalc.h"
#include "CGraph.h"
#include "afxcmn.h"
//���������� ������������ �����
//���������� ���� CCourseDlg
class CCourseDlg : public CDialogEx
{
public:
	CCourseDlg(CWnd* pParent = NULL);

	// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);// ��������� DDX/DDV


	//����������
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:// ����������� �������
	CEdit m_Edit_A;
	CEdit m_Edit_B;
	CEdit m_Edit_C;
	CEdit m_Edit_D;
	CEdit m_Edit_E;
	CEdit m_Edit_x_left;
	CEdit m_Edit_x_right;
	CEdit m_Edit_Acc;
	CEdit m_Edit_Num;
	CEdit m_Edit_Scale;
	CCalc m_calc;
	CGraph m_graph;
	CString m_A;
	CString m_B;
	CString m_C;
	CString m_D;
	CString m_E;
	CString m_x_left;
	CString m_x_right;
	CString m_Acc;
	CString m_Num;
	CString m_Scale;
	CComboBox m_ComboStyle;

	// ���� ����������, ����������� ��� ������ ���������
	afx_msg void OnEnChangeEditA();//����� ��������� ���� �����
	afx_msg void OnEnChangeEditB();//����� � ����� ��� ���������
	afx_msg void OnEnChangeEditC();
	afx_msg void OnEnChangeEditD();
	afx_msg void OnEnChangeEditE();
	afx_msg void OnEnChangeEditCur();
	afx_msg void OnBnClickedButtonCalc();
	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonCenter();
	afx_msg void OnBnClickedButtonDown();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnEnChangeEditScale();//����� ��������� ���� �����
	afx_msg void OnEnChangeEditNum();
	afx_msg void OnEnChangeEditxdown();
	afx_msg void OnEnChangeEditxup();
	afx_msg void OnBnClickedButtonClean();
	afx_msg void OnBnClickedButtonsave();
	afx_msg void OnCbnSelchangeCombostyle();//����� ��������� ComboBox
	afx_msg void OnBnClickedCheckcoord();//����� ��������� CheckBox
};