#include "pch.h"
#include "CGraph.h"
#include "CourseDlg.h"
#include "Course.h"
#include "CCalc.h"
#include <vector>
#include <math.h> // ����������� ����������� ����������

IMPLEMENT_DYNAMIC(CGraph, CStatic)

CGraph::CGraph() // �����������
{
	m_Col = RGB(255, 255, 255); // ��������� ����� - �����
	Coords = false; // �������� ������ ����������� ���������
}

CGraph::~CGraph() // ����������
{
}

BEGIN_MESSAGE_MAP(CGraph, CStatic) // ���������� ���������
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CGraph::OnPaint()
{
	CPaintDC dc(this);  //  �������� ���������
	CPoint Delta;  //  �������� ������
	int X_Up;  //  ������� ������� �������
	int X_Down;  //  ������ ������� �������
	int Scale;  //  �������� ���������������
	CRect rc; // ��������� ������ CRect
	GetClientRect(&rc); // ����� ������� ���������� �������
	CRgn rgn; // ��������� ������ CRgn
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom); // ������� ������������� ������
	dc.SelectClipRgn(&rgn); // ������� ������ �������� ����������
	dc.FillSolidRect(rc, m_Col);//������ �������
	CCourseDlg* pDlg = (CCourseDlg*)AfxGetMainWnd(); // ��������� ������ ����������� ����
	Param_values par; // ��������� ��������� Param_values
	Delta.x = pDlg->m_calc.m_param.x_i; // ������ �������� �� �
	Delta.y = pDlg->m_calc.m_param.y_i; // ������ �������� �� �
	X_Up = pDlg->m_calc.m_param.x_right;//������ ������ ������� ����������
	X_Down = pDlg->m_calc.m_param.x_left;//������ ����� ������� ����������
	Scale = pDlg->m_calc.m_param.Scale; // ������ ����������� ���������������
	if (Coords) { // ������ ������ ����������� ���������
		CPen penCO(PS_SOLID, 1, RGB(128, 128, 128)); // ������� ���� �����
		HGDIOBJ CoordS = dc.SelectObject(penCO); // ������� ����
		int X_i = 1 * Scale;
		for (double i = 199; i <= 398 - static_cast<unsigned __int64>(Delta.x) * Scale; i = i + X_i) // ���� �� ������ �������� ���� ������� (������) �� �
		{
			dc.MoveTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, 0); // ��������� �������� � ��������������� �����
			dc.LineTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, rc.Height());//�������� ����� �� ��������� �����
		}
		for (double i = 199; i >= 0 - static_cast<unsigned __int64>(Delta.x) * Scale; i = i - X_i)//���� �� ������ �������� ���� ������� (�����) �� �
		{
			dc.MoveTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, 0);//��������� �������� � ��������������� �����
			dc.LineTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, rc.Height());//�������� ����� �� ��������� �����
		}
		for (double i = 199; i <= 398 - static_cast<unsigned __int64>(Delta.y) * Scale; i = i + X_i)//���� �� ������ �������� ���� ������� (������) �� �
		{
			dc.MoveTo(0, i + static_cast<unsigned __int64>(Delta.y) * Scale);//��������� �������� � ��������������� �����
			dc.LineTo(rc.Width(), i + static_cast<unsigned __int64>(Delta.y) * Scale);//�������� ����� �� ��������� �����
		}
		for (double i = 199; i >= 0 - static_cast<unsigned __int64>(Delta.y) * Scale; i = i - X_i)//���� �� ������ �������� ���� ������� (�����) �� �
		{
			dc.MoveTo(0, i + static_cast<unsigned __int64>(Delta.y) * Scale);//��������� �������� � ��������������� �����
			dc.LineTo(rc.Width(), i + static_cast<unsigned __int64>(Delta.y) * Scale);//�������� ����� �� ��������� �����
		}
	}
	CPen penWh(PS_SOLID, 2, RGB(0, 0, 0));//������� ���� ������
	CPen penBl(PS_SOLID, 2, RGB(255, 255, 255));//������� ���� �����
	if (m_Col == RGB(255, 255, 255))//���� ����� �����
		HGDIOBJ Coor = dc.SelectObject(penWh);//������� ���� ��� ������
	if (m_Col == RGB(0, 0, 0))//���� ����� ������
		HGDIOBJ Coor = dc.SelectObject(penBl);//������� ���� ��� �������
	dc.MoveTo(199 + Delta.x * Scale, 0);//���������� ���� � ��������� �����
	dc.LineTo(199 + Delta.x * Scale, rc.Height());//�������� ����� �� ��������� �����
	dc.MoveTo(0, 199 + Delta.y * Scale);//���������� ���� � ��������� �����
	dc.LineTo(rc.Width(), 199 + Delta.y * Scale);//�������� ����� �� ��������� �����
	//���� ���������� ������������ ���
	CPen penWB(PS_SOLID, 2, RGB(0, 255, 255));//������� cyan ���� 
	CPen penBG(PS_SOLID, 2, RGB(255, 0, 255));//������� violet ����
	if (m_Col == RGB(255, 255, 255))//���� ����� �����
		HGDIOBJ Meh = dc.SelectObject(penWB);//������� ���� ��� ������
	if (m_Col == RGB(0, 0, 0))//���� ����� ������
		HGDIOBJ Meh = dc.SelectObject(penBG);//������� ���� ��� �������
	std::vector<POINT>* vec = pDlg->m_calc.GetPoints();//������� ����� �� ������ m_vecPt � ������ vec
	if (vec->size())//���� ������ ����� ������
	{
		std::vector<POINT>::iterator it = vec->begin();//������ �������� ����� � ������ ������� �����
		dc.MoveTo(*it);//���������� ���� � ��������� �����
		for (it; it != vec->end(); it++)//���� for
		{
			dc.LineTo(*it);//�������� ����� �� ��������� �����
		}
	}
	if (X_Up >= X_Down)//��� ���������� ������������ ������ �������
	{
		CPen penUP(PS_SOLID, 3, RGB(255, 0, 0));//������� ���� �����
		HGDIOBJ Up = dc.SelectObject(penUP);//������� ����
		dc.MoveTo(199 + (X_Up + Delta.x) * Scale, 0);//���������� ���� � ��������� �����
		dc.LineTo(199 + (X_Up + Delta.x) * Scale, rc.Height());//�������� ����� �� ��������� �����
		//���������� ������ �������
		CPen penDOWN(PS_SOLID, 3, RGB(0, 0, 255));//������� ���� �������
		HGDIOBJ Down = dc.SelectObject(penDOWN);//������� ����
		dc.MoveTo(199 + (X_Down + Delta.x) * Scale, 0);//���������� ���� � ��������� �����
		dc.LineTo(199 + (X_Down + Delta.x) * Scale, rc.Height());//�������� ����� �� ��������� �����
		//���������� ����� �������
	}
	else if (X_Up != 0 && X_Down != 0) MessageBox(_T("�������� ������ ������� ������ �������� �������.\n��������� ������ � ���������."), _T("������!"), MB_OK | MB_ICONERROR);//������ � ��������
}