#pragma once
class CGraph : public CStatic//�����, ������������� �� Cstatic
{
	DECLARE_DYNAMIC(CGraph)
public:// ����������� �������
	CGraph();// �����������
	virtual ~CGraph();// ����������

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();// ����� OnPaint
public:
	COLORREF m_Col;// ���� �����
	bool Coords;// ����������� ���������
};