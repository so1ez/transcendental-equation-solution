#include "pch.h"
#include "CCalc.h"
#include "CourseDlg.h"
#include "Course.h"
#include <math.h> // ����������� ����������� ������������ ������ � ���������

CCalc::CCalc() // �����������
{
	m_param.Scale = 20; // ��������� �������� ���������������
}

CCalc::~CCalc() // ����������
{
}

bool CCalc::Shift(CPoint& pt) // ����� ��� �������� ������ (������) ���������
{
	pt.Offset(199 + m_param.x_i * m_param.Scale, 199 + m_param.y_i * m_param.Scale); // �������� ������ ���������
	return true; // ������� true
}

retres CCalc::findSolv(double eps, double A, double B, double C, double D, double E, int xle, int xri) // ����� ������ ������
{
	double xn, xk, xs, xt; // ��� ����������
	int n = 1;
	xn = xle;
	xk = xri;
	xt = xle; // ���� �� ��������
	if (xle == xri && (abs(f(xle) == 0))) m_vecRes.push_back({ xt, 1, true });
	if (abs(f(xle)) == 0 && abs(f(xri) == 0)) return { 0, 0, false };
	if (abs(f(xle)) < 0.001) m_vecRes.push_back({ xn, 1, true }); // ��������� ����������
	while (xri - xt >= 0.01) // �������� � ����, � ������� ���������� ����� ������� ������� �������, ��� ����� ��������
	{
		xk = xn + 0.01; // 0,01 - ��� ������� ���������� ������������� ������� (��������� ������ �������� �� ���� ���������
		n = 1;
		xs = (xn + xk) / 2;
		while ((xk - xn) >= 0.001) // ���� ����������������� "������� ������� �������"
		{
			xs = (xn + xk) / 2;
			if ((f(xn) / f(xs)) < 0)
				xk = xs;
			else xn = xs;
			n++;
		}
		if (abs(f(xs)) < 0.001) m_vecRes.push_back({ xs, n, true }); // ��� ���� ����������
		xt += 0.01;
		xn = xt;

	}

	if (abs(f(xri)) < eps) m_vecRes.push_back({ xk, 1, true }); // ��� ���� ����������
	return{ 0, 0, false }; // ���������� ������
}

bool CCalc::cleanSolv(Param_values& par)//������ �������� �������
{
	m_param = par; // �������� �������� � ���������
	m_vecRes.clear(); // ������� ������� �������� �������
	findSolv(m_param.Acc, m_param.A, m_param.B, m_param.C, m_param.D, m_param.E, m_param.x_left, m_param.x_right); // ���������� ���� ������ �� �������
	if (m_vecRes.size() > 1) // ���� ������ ����������� �� ������
		for (int i = m_vecRes.size() - 2; i >= 0; i--)
		{
			if (abs(abs(m_vecRes[i].result) - abs(m_vecRes[i + 1].result)) <= 0.15) m_vecRes[i].correct = false;
		}
	m_vecResBoof.clear(); // ������� �������� ������
	if (m_vecRes.size() != 0) // ���� ������ �� ������
	{
		for (int i = 0; i < m_vecRes.size(); i++) // �� ����, ���������� �� ���� ��������� ������� �������
		{
			if (m_vecRes[i].correct) m_vecResBoof.push_back(m_vecRes[i]); // ���� ����� ��������������, �� ������ � �������� ������ ���� ������
		}
		m_vecRes.clear();//����� ������� ������ �������
		for (int i = 0; i < m_vecResBoof.size(); i++)
		{
			m_vecRes.push_back(m_vecResBoof[i]); // ���� �������� ������� �� ������ � �������� ������ �������
		}
	}
	return true; // ������� true
}

bool CCalc::Calculate()//����� ������� ����� �������
{
	if (m_param.Num >= 2 && m_param.Num <= 400 && m_param.Scale > 0) // �������� �� ���-�� �����
	{
		double X_i = (400 / m_param.Num); // ���������� ��� ���� �� �
		double x = -200 - X_i - m_param.x_i; // ������������ �������� �������� �
		CPoint pt;
		m_vecPt.clear(); // �������� ������ �����
		for (double i = 0; i <= 400; i = i + X_i) // ���� �� ������ �� ���� �������
		{
			x += X_i; // ���������� � �� ���
			pt.x = x * m_param.Scale; // ������ ����� � � ����� pt

			pt.y = -1 * (m_param.A * sin(m_param.B * x + m_param.C) - m_param.D * x - m_param.E) * m_param.Scale; // ��������������� ���� �������

			if (Shift(pt)) // ������� ���� ������ ���������, ���� ��� �� - ���� ������
			{
				m_vecPt.push_back(POINT(pt)); // ��������� � ������ �����
			}
		}
	}
	return true; // ������� true
}

bool CCalc::SetParams(Param_values& par) // ����� ��� �������� � ���������
{
	m_param = par; // �������� �������� � ���������
	Calculate(); // ����� ������ �������
	return true; // ������� true
}

vector<POINT>* CCalc::GetPoints() // ������ ����� ��� �������� � ����� ���������
{
	return &m_vecPt; // ������� ������ �����
}

vector<retres>* CCalc::GetResults() // ������ ������� ��� �������� � ������
{
	return &m_vecRes; // ������� ������ �������
}

double* CCalc::GetResult(int k) // ����� ������ �-���� �����
{
	return &m_vecRes[k].result; // ������ �-��� ������ ������� �������
}

int* CCalc::GetIteration(int k) // ����� ������ �-���� �������� ��������
{
	return &m_vecRes[k].iters; // ������ �-��� �������� �������� ������� �������
}

int* CCalc::GetSize() // ����� ������ ���������� ������
{
	int m = m_vecRes.size(); // ��������� ������ ������� �������
	return &m; // ������ ������ ������� �������
}

double CCalc::f(double x) // ������� ������ ���������
{
	return (m_param.A * sin(m_param.B * x + m_param.C) - m_param.D * x - m_param.E); // ���������� ���� ���� ���������
}