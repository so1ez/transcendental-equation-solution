#include "pch.h"
#include "CGraph.h"
#include "CourseDlg.h"
#include "Course.h"
#include "CCalc.h"
#include <vector>
#include <math.h> // подключение необходимых заголовков

IMPLEMENT_DYNAMIC(CGraph, CStatic)

CGraph::CGraph() // Конструктор
{
	m_Col = RGB(255, 255, 255); // Начальный стиль - белый
	Coords = false; // Значение флажка отображения координат
}

CGraph::~CGraph() // Деструктор
{
}

BEGIN_MESSAGE_MAP(CGraph, CStatic) // Обработчик сообщений
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CGraph::OnPaint()
{
	CPaintDC dc(this);  //  Контекст рисования
	CPoint Delta;  //  Смещение центра
	int X_Up;  //  Верхняя граница отрезка
	int X_Down;  //  Нижняя граница отрезка
	int Scale;  //  Значение масштабирования
	CRect rc; // Экземпляр класса CRect
	GetClientRect(&rc); // Взять размеры клиентской области
	CRgn rgn; // Экземпляр класса CRgn
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom); // Создать прямоугольный регион
	dc.SelectClipRgn(&rgn); // Выбрать регион контекст устройства
	dc.FillSolidRect(rc, m_Col);//Залить область
	CCourseDlg* pDlg = (CCourseDlg*)AfxGetMainWnd(); // Экземпляр класса диалогового окна
	Param_values par; // Экземпляр структуры Param_values
	Delta.x = pDlg->m_calc.m_param.x_i; // Задать смещение по Х
	Delta.y = pDlg->m_calc.m_param.y_i; // Задать смещение по У
	X_Up = pDlg->m_calc.m_param.x_right;//Задать правую границу промежутка
	X_Down = pDlg->m_calc.m_param.x_left;//Задать левую границу промежутка
	Scale = pDlg->m_calc.m_param.Scale; // Задать коэффициент масштабирования
	if (Coords) { // Нажата кнопка отображения координат
		CPen penCO(PS_SOLID, 1, RGB(128, 128, 128)); // Создать перо серое
		HGDIOBJ CoordS = dc.SelectObject(penCO); // Выбрать перо
		int X_i = 1 * Scale;
		for (double i = 199; i <= 398 - static_cast<unsigned __int64>(Delta.x) * Scale; i = i + X_i) // Пока не пройдёт половину окна графика (справа) по Х
		{
			dc.MoveTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, 0); // Поставить кисточку в соответствующую точку
			dc.LineTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, rc.Height());//Провести линию до указанной точки
		}
		for (double i = 199; i >= 0 - static_cast<unsigned __int64>(Delta.x) * Scale; i = i - X_i)//Пока не пройдёт половину окна графика (слева) по Х
		{
			dc.MoveTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, 0);//Поставить кисточку в соответствующую точку
			dc.LineTo(i + static_cast<unsigned __int64>(Delta.x) * Scale, rc.Height());//Провести линию до указанной точки
		}
		for (double i = 199; i <= 398 - static_cast<unsigned __int64>(Delta.y) * Scale; i = i + X_i)//Пока не пройдёт половину окна графика (вверху) по У
		{
			dc.MoveTo(0, i + static_cast<unsigned __int64>(Delta.y) * Scale);//Поставить кисточку в соответствующую точку
			dc.LineTo(rc.Width(), i + static_cast<unsigned __int64>(Delta.y) * Scale);//Провести линию до указанной точки
		}
		for (double i = 199; i >= 0 - static_cast<unsigned __int64>(Delta.y) * Scale; i = i - X_i)//Пока не пройдёт половину окна графика (Внизу) по У
		{
			dc.MoveTo(0, i + static_cast<unsigned __int64>(Delta.y) * Scale);//Поставить кисточку в соответствующую точку
			dc.LineTo(rc.Width(), i + static_cast<unsigned __int64>(Delta.y) * Scale);//Провести линию до указанной точки
		}
	}
	CPen penWh(PS_SOLID, 2, RGB(0, 0, 0));//Создать перо черное
	CPen penBl(PS_SOLID, 2, RGB(255, 255, 255));//Создать перо белое
	if (m_Col == RGB(255, 255, 255))//Если стиль белый
		HGDIOBJ Coor = dc.SelectObject(penWh);//Выбрать перо для белого
	if (m_Col == RGB(0, 0, 0))//Если стиль черный
		HGDIOBJ Coor = dc.SelectObject(penBl);//Выбрать перо для черного
	dc.MoveTo(199 + Delta.x * Scale, 0);//установить перо в указанной точке
	dc.LineTo(199 + Delta.x * Scale, rc.Height());//провести линию до указанной точки
	dc.MoveTo(0, 199 + Delta.y * Scale);//установить перо в указанной точке
	dc.LineTo(rc.Width(), 199 + Delta.y * Scale);//провести линию до указанной точки
	//Были отрисованы координатные оси
	CPen penWB(PS_SOLID, 2, RGB(0, 255, 255));//Создать cyan перо 
	CPen penBG(PS_SOLID, 2, RGB(255, 0, 255));//Создать violet перо
	if (m_Col == RGB(255, 255, 255))//Если стиль белый
		HGDIOBJ Meh = dc.SelectObject(penWB);//Выбрать перо для белого
	if (m_Col == RGB(0, 0, 0))//Если стиль чёрный
		HGDIOBJ Meh = dc.SelectObject(penBG);//Выбрать перо для чёрного
	std::vector<POINT>* vec = pDlg->m_calc.GetPoints();//Забрать точки из ветора m_vecPt в вектор vec
	if (vec->size())//Если вектор имеет данные
	{
		std::vector<POINT>::iterator it = vec->begin();//Начать итерацию цикла с начала вектора точек
		dc.MoveTo(*it);//Установить перо в указанной точке
		for (it; it != vec->end(); it++)//Цикл for
		{
			dc.LineTo(*it);//Провести линию до указанной точки
		}
	}
	if (X_Up >= X_Down)//При правильном расположении границ отрезка
	{
		CPen penUP(PS_SOLID, 3, RGB(255, 0, 0));//Создать перо синее
		HGDIOBJ Up = dc.SelectObject(penUP);//Выбрать перо
		dc.MoveTo(199 + (X_Up + Delta.x) * Scale, 0);//установить перо в указанной точке
		dc.LineTo(199 + (X_Up + Delta.x) * Scale, rc.Height());//провести линию до указанной точки
		//Отрисовали правую границу
		CPen penDOWN(PS_SOLID, 3, RGB(0, 0, 255));//Создать перо красное
		HGDIOBJ Down = dc.SelectObject(penDOWN);//Выбрать перо
		dc.MoveTo(199 + (X_Down + Delta.x) * Scale, 0);//установить перо в указанной точке
		dc.LineTo(199 + (X_Down + Delta.x) * Scale, rc.Height());//провести линию до указанной точки
		//Отрисовали левую границу
	}
	else if (X_Up != 0 && X_Down != 0) MessageBox(_T("Значение левого предела меньше значения правого.\nИсправьте ошибку и повторите."), _T("Ошибка!"), MB_OK | MB_ICONERROR);//Ошибка в границах
}