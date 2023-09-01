#include "pch.h"
#include "CCalc.h"
#include "CourseDlg.h"
#include "Course.h"
#include <math.h> // подключение необходимых заголовочных файлов и библиотек

CCalc::CCalc() // Конструктор
{
	m_param.Scale = 20; // начальное значение масштабирования
}

CCalc::~CCalc() // Деструктор
{
}

bool CCalc::Shift(CPoint& pt) // Метод для смещения начала (центра) координат
{
	pt.Offset(199 + m_param.x_i * m_param.Scale, 199 + m_param.y_i * m_param.Scale); // Сместить начало координат
	return true; // Вернуть true
}

retres CCalc::findSolv(double eps, double A, double B, double C, double D, double E, int xle, int xri) // метод поиска корней
{
	double xn, xk, xs, xt; // доп переменные
	int n = 1;
	xn = xle;
	xk = xri;
	xt = xle; // даем им значения
	if (xle == xri && (abs(f(xle) == 0))) m_vecRes.push_back({ xt, 1, true });
	if (abs(f(xle)) == 0 && abs(f(xri) == 0)) return { 0, 0, false };
	if (abs(f(xle)) < 0.001) m_vecRes.push_back({ xn, 1, true }); // обработка исключений
	while (xri - xt >= 0.01) // основной в цикл, в котором реализуция метод деления отрезка пополам, или метод бисекции
	{
		xk = xn + 0.01; // 0,01 - шаг деления выбранного пользователем отрезка (разбиение одного большого на кучу маленьких
		n = 1;
		xs = (xn + xk) / 2;
		while ((xk - xn) >= 0.001) // цикл непосредственного "деления отрезка пополам"
		{
			xs = (xn + xk) / 2;
			if ((f(xn) / f(xs)) < 0)
				xk = xs;
			else xn = xs;
			n++;
		}
		if (abs(f(xs)) < 0.001) m_vecRes.push_back({ xs, n, true }); // еще одно исключение
		xt += 0.01;
		xn = xt;

	}

	if (abs(f(xri)) < eps) m_vecRes.push_back({ xk, 1, true }); // еще одно исключение
	return{ 0, 0, false }; // возвращаем ничего
}

bool CCalc::cleanSolv(Param_values& par)//Вектор структур ответов
{
	m_param = par; // Передача значений в структуру
	m_vecRes.clear(); // Очистка вектора структур ответов
	findSolv(m_param.Acc, m_param.A, m_param.B, m_param.C, m_param.D, m_param.E, m_param.x_left, m_param.x_right); // нахождение всех корней на отрезке
	if (m_vecRes.size() > 1) // если вектор результатов не пустой
		for (int i = m_vecRes.size() - 2; i >= 0; i--)
		{
			if (abs(abs(m_vecRes[i].result) - abs(m_vecRes[i + 1].result)) <= 0.15) m_vecRes[i].correct = false;
		}
	m_vecResBoof.clear(); // Очищаем буферный вектор
	if (m_vecRes.size() != 0) // Если вектор не пустой
	{
		for (int i = 0; i < m_vecRes.size(); i++) // то цикл, проходящий по всем элементам вектора ответов
		{
			if (m_vecRes[i].correct) m_vecResBoof.push_back(m_vecRes[i]); // если ответ подтвержденный, то пихаем в буферный вектор наши ответы
		}
		m_vecRes.clear();//далее очищаем вектор ответов
		for (int i = 0; i < m_vecResBoof.size(); i++)
		{
			m_vecRes.push_back(m_vecResBoof[i]); // цикл переноса ответов из буфера в основной вектор ответов
		}
	}
	return true; // вернуть true
}

bool CCalc::Calculate()//Метод расчёта точек графика
{
	if (m_param.Num >= 2 && m_param.Num <= 400 && m_param.Scale > 0) // проверка на кол-во точек
	{
		double X_i = (400 / m_param.Num); // переменная для шага по Х
		double x = -200 - X_i - m_param.x_i; // присваивание текущего значения Х
		CPoint pt;
		m_vecPt.clear(); // Очистить вектор точек
		for (double i = 0; i <= 400; i = i + X_i) // Пока не пройдёт всё окно графика
		{
			x += X_i; // Увелечение Х на шаг
			pt.x = x * m_param.Scale; // запись точки Х в точку pt

			pt.y = -1 * (m_param.A * sin(m_param.B * x + m_param.C) - m_param.D * x - m_param.E) * m_param.Scale; // непосредственно наша функция

			if (Shift(pt)) // смещаем наше начало координат, если все ок - идем дальше
			{
				m_vecPt.push_back(POINT(pt)); // добавляем в вектор точек
			}
		}
	}
	return true; // вернуть true
}

bool CCalc::SetParams(Param_values& par) // Метод для передачи в структуру
{
	m_param = par; // Передать значения в структуру
	Calculate(); // Вызов метода расчёта
	return true; // Вернуть true
}

vector<POINT>* CCalc::GetPoints() // Вектор точек для передачи в класс рисования
{
	return &m_vecPt; // Вернуть вектор точек
}

vector<retres>* CCalc::GetResults() // Вектор ответов для передачи в диалог
{
	return &m_vecRes; // Вернуть вектор ответов
}

double* CCalc::GetResult(int k) // Метод выдачи к-того корня
{
	return &m_vecRes[k].result; // Выдать к-тый корень вектора ответов
}

int* CCalc::GetIteration(int k) // Метод выдачи к-того значения итерации
{
	return &m_vecRes[k].iters; // Выдать к-тое значение итераций вектора ответов
}

int* CCalc::GetSize() // Метод выдачи количества корней
{
	int m = m_vecRes.size(); // Вычислить размер вектора ответов
	return &m; // Выдать размер вектора ответов
}

double CCalc::f(double x) // функция нашего уравнения
{
	return (m_param.A * sin(m_param.B * x + m_param.C) - m_param.D * x - m_param.E); // возвращает само наше уравнение
}