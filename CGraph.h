#pragma once
class CGraph : public CStatic//Класс, наследованный от Cstatic
{
	DECLARE_DYNAMIC(CGraph)
public:// Модификатор доступа
	CGraph();// Конструктор
	virtual ~CGraph();// Деструктор

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();// Метод OnPaint
public:
	COLORREF m_Col;// Цвет стиля
	bool Coords;// Отображение координат
};