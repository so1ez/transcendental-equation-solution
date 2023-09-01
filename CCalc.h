#pragma once
#include <vector>// ���������� ���������� ��� ���. ���. �������

using namespace std;// ������������ ����

typedef struct// ��������� ��������
{
	double A;// ��������� ��� ���������� 
	double B;
	double C;
	double D;
	double E;
	int x_left;
	int x_right;
	double Acc;// �������� ��������
	int Scale;// �������� ��������
	int y_i;// ��������� ��������
	int x_i;// ��������� ��������
	int Num;// �������� ��������� �����
} Param_values;

struct retres
{ // ��������� �������
	double result;// ������
	int iters;// ��������
	bool correct;// ����� (������ - false)
};

class CCalc // ����� ��� ���������� ������� �����
{
public:// ����������� �������
	CCalc();// �����������
	~CCalc();// ����������
public:
	Param_values m_param; // ��������� ���������
	retres findSolv(double eps, double A, double B, double C, double D, double E, int board1, int board2);// ����� ������ ������
	bool cleanSolv(Param_values& par);// ���������� ���� ������ �� �������
	vector<retres> m_vecRes;// ������ �������� �������
	vector<retres> m_vecResBoof;// ������ �������� ������� (�����)	
	bool Calculate();// ����� ���������� �����
	bool SetParams(Param_values& par);// ����� ��� �������� � ��������� ���������� ��������
	vector<POINT> m_vecPt;// ������ �����
	bool Shift(CPoint& pt);// ����� ��� ��������������� ������
	vector<POINT>* GetPoints();// ������ ����� ��� �������� ����� � ����� ���������
	vector<retres>* GetResults(); // ������ �������
	double* GetResult(int k); // �������� i-��� ������ �� ������� �������
	int* GetIteration(int k); // �������� i-��� �������� ��������� �� ������� �������
	int* GetSize(); // �������� ������ ������� �������
	double f(double x); // ����� ������� ���������
};