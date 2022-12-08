// Arrays.cpp 

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
int menu();
void FillRand(int mas[], int n, int a, int b);
void Prit(int mas[], int n);
int Sum(int mas[], int n);
int Avg(int Sum, int n);
int minValueln(int mas[], int n);
int maxValueln(int mas[], int n);
void Sort(int mas[], int n);
void UniqueRand(int mas[], int n, int a, int b);
void Search(int mas[], int n);
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	const int n = 10;
	int mas[n];
	int a = 0, b = 6;



	int poz = 0;
	int key;
	do
	{
		system("cls");
		poz = menu();
		system("cls");
		switch (poz)
		{
		case 1:
		{



			const int n = 10;
			int mas[n];
			int size = 0;
			for (int i = 0; i < 10; i++)
			{

				mas[i] = i + 1;
				cout << mas[i] << "\t";
			}

			do {
				system("cls");

				for (int i = 0; i < 10; i++)
				{


					cout << mas[i] << "\t";
				}

				cout << endl;
				cout << "Нажмите Enter для выхода";



				key = _getch();
				switch (key)
				{
				case Left:
				{
					size--;
					break;
				}
				case Right:
				{
					size++;
					break;
				}
				case Enter:
				{
					break;
				}

				}
				if (size < 0)
				{
					size = 9;
				}
				if (size > 9 && key == Right)
				{
					size = 0;
				}
				size = n - size;
				for (int i = 0; i < size; i++)
				{
					int d = mas[0];
					for (int i = 0; i < n; i++)
					{

						mas[i] = mas[i + 1];

					}
					mas[n - 1] = d;
				}


			} while (key != Enter);
			break;
		}

		case 0:
		{
			do {
				system("cls");
				cout << "Введите диапазон от "; cin >> a; cout << " до "; cin >> b;
				system("cls");
				FillRand(mas, n, a, b);
				Prit(mas, n);
				cout << endl << Sum(mas, n);
				cout << endl << Avg(Sum(mas, n), n);
				cout << endl << minValueln(mas, n);
				cout << endl << maxValueln(mas, n);
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;

		}

		case 2:
		{
			do {
				system("cls");
				Prit(mas, n);
				cout << endl;
				Sort(mas, n);
				Prit(mas, n);
				cout << endl;
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;
		}

		case 3:
		{
			do {
				system("cls");
				cout << "Введите диапазон от "; cin >> a; cout << "до "; cin >> b;
				system("cls");

				UniqueRand(mas, n, a, b);
				Prit(mas, n);
				cout << endl;
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;
		}
		case 4:
		{
			do
			{
				system("cls");
				FillRand(mas, n, a, b);
				Prit(mas, n);
				Search(mas, n);
				cout << endl;
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);

		}
		case 5:
		{
			break;
		}

		}

	} while (poz != 5);
}

void FillRand(int mas[], int n, int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = a + rand() % (b - a);

	}

}

void Prit(int mas[], int n)
{
	for (int i = -0; i < n; i++)
	{
		cout << mas[i] << "\t";

	}

}

int Sum(int mas[], int n)
{
	int Sum = 0;

	for (int i = 0; i < n; i++)
	{
		Sum = Sum + mas[i];

	}



	return Sum;
}

int Avg(int Sum, int n)
{
	int Avg = 0;
	Avg = Sum / n;

	return Avg;
}

int minValueln(int mas[], int n)
{
	int Min = mas[0];

	for (int i = 1; i < n; i++)
	{
		if (mas[i] < Min)
		{
			Min = mas[i];
		}


	}


	return Min;
}

int maxValueln(int mas[], int n)
{

	int Max = mas[0];

	for (int i = 1; i < n; i++)
	{
		if (mas[i] > Max)
		{
			Max = mas[i];
		}


	}


	return Max;


}

void Sort(int mas[], int n)
{
	int boof = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++) {
			if (mas[j] > mas[j + 1])
			{
				boof = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = boof;
			}
		}
	}
}

void UniqueRand(int mas[], int n, int a, int b)
{
	FillRand(mas, n, a, b);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == mas[i] && i != j)
			{
				mas[i] = a + rand() % (b - a);
				j = 0;
			}
		}

	}


}

void Search(int mas[], int n)
{
	int arr[10]{};
	cout << endl;
	int coll = 0, cikl = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i] == mas[j])
			{
				coll++;
			}
		}

		if (coll > 0)
		{

			for (int g = 0; g < n; g++)
			{
				if (mas[i] == arr[g])
				{
					cikl++;
				}

			}

			if (cikl == 0)
			{
				arr[i] = mas[i];
				cout << mas[i] << "|" << coll;
			}
			cikl = 0;


		}
		coll = 0;
		cout << "\t";
	}

}

int menu()
{
	char menu[6][50] = { "Вывод массива и работа с ним","Движение массива","Сортировка массива","Заполнение массива уник числами","Нахожденеи повторений","Выход" };//Пункты меню
	int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

	for (int i = 0; i < 6; i++)//Рисовка меню
	{
		SetCursor(15, 10 + i);
		cout << menu[i];

	}
	do {
		for (int i = 0; i < 6; i++)//изменения цвета выбронного пункта
		{
			SetCursor(15, 10 + i);

			if (i == poz)
			{
				SetColor(Yellow, Black);
			}
			else
			{
				SetColor(White, Black);
			}

			cout << menu[i];

		}

		key = _getch();
		switch (key)
		{
		case Up:
		{	poz--;
		if (poz < 0)
		{
			poz = 5;
		}
		break;
		}
		case Down:
		{
			poz++;
			if (poz > 5)
			{
				poz = 0;
			}
			break;
		}
		case Enter:
		{
			SetColor(White, Black);
			return(poz);//возвращение выбронного пункта меню
		}


		}

	} while (true);
}