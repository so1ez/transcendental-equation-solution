#pragma once
#include <vector>// Подключить библиотеку для исп. дин. массива

using namespace std;// пространство имен

typedef struct// Структура значений
{
	double A;// Параметры для вычисления 
	double B;
	double C;
	double D;
	double E;
	int x_left;
	int x_right;
	double Acc;// Параметр точности
	int Scale;// Параметр масштаба
	int y_i;// Параметры смещения
	int x_i;// Параметры смещения
	int Num;// Параметр плотности точек
} Param_values;

struct retres
{ // Структура ответов
	double result;// Корень
	int iters;// Итерации
	bool correct;// Успех (Ошибка - false)
};

class CCalc // Класс для вычисления вектора точек
{
public:// Модификатор доступа
	CCalc();// Конструктор
	~CCalc();// Деструктор
public:
	Param_values m_param; // Экземпляр структуры
	retres findSolv(double eps, double A, double B, double C, double D, double E, int board1, int board2);// Метод поиска корней
	bool cleanSolv(Param_values& par);// Вычисление всех корней на участке
	vector<retres> m_vecRes;// Вектор структур ответов
	vector<retres> m_vecResBoof;// вектор структур ответов (буфер)	
	bool Calculate();// Метод вычисления точек
	bool SetParams(Param_values& par);// Метод для передачи в структуру измененных значений
	vector<POINT> m_vecPt;// Вектор точек
	bool Shift(CPoint& pt);// Метод для переопределения центра
	vector<POINT>* GetPoints();// Вектор точек для передачи точек в класс рисования
	vector<retres>* GetResults(); // Вектор ответов
	double* GetResult(int k); // Получить i-тый корень из вектора ответов
	int* GetIteration(int k); // Получить i-тое значение интерации из вектора ответов
	int* GetSize(); // Получить размер вектора ответов
	double f(double x); // метод расчета уравнения
};