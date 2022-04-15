/*
В заданной квадратной матрице размера (2n+1)×(2n+1) найти элементы с наибольшим и наименьшим значениями.
Если хотя бы один из них находится в области левее главной и побочной 
диагоналей найти сумму значений элементов, лежащих ниже главной диагонали.
В противном случае поменять найденные значения местами.*/
#include<iostream>
#include<locale.h>
using namespace std;
const int RAZ = 10;			//максимальный размер квадратной матрицы
typedef int telem;			//определение типа значений элементов массива
typedef telem tmatr[RAZ][RAZ];
void input_matr(tmatr a, int&);
void output_matr(tmatr a, int);
void  obnul_up(tmatr a, int,int&,int&);
void  obnul_down(tmatr a, int, int&, int&);
void summa(tmatr a, int, telem&);
void per(tmatr a,int,int,int);
//main_beg________________________________________________________________
int main()
{
    tmatr a;					//двумерный массив
    int n,max_1,max_2,min_1,min_2,k=0;
    telem sum_gl,tpm;
    setlocale(LC_ALL, "Russian");
    input_matr(a, n);
    cout << " исходная матрица :" << endl;
    output_matr(a, n);
    obnul_up(a, n, max_1, max_2);
    obnul_down(a, n, min_1, min_2);
    cout << "fkgkhg" << endl;
    //max= obnul_up(a, n, max_1, max_2);
   // min = obnul_down(a, n, min_1, min_2);
            if (( (max_1 > max_2) && (max_1 < 2 * n - max_2 + 2)) || ( (min_1 > min_2) && (min_1 <2 * n - min_2 + 2)))
            { 
                cout << "464545" << endl;
               summa(a, n, sum_gl);
               cout << "сумма элементов ниже главной диагонали:  " << endl;
               cout << sum_gl << endl;
            }
            else
            { 
                tpm = a[max_1][max_2];
                a[max_1][max_2] = a[min_1][min_2];
                a[min_1][min_2] = tpm;
            cout << "Матрица после преобразования:" << endl;
            output_matr(a, n);
            } 
}
//Ввод исходных данных
void input_matr(tmatr a, int& n)
{
    cout << "Введите n < " << endl;
    cin >> n;
    cout << "Введите построчно через пробел элементы" << endl;
    cout << "матрицы размера " << 2 * n + 1 << "x" << 2 * n + 1 << endl;
    cout << "После ввода строки нажимайте <Enter>" << endl;
    for (int i = 0; i < 2 * n + 1; i++)
        for (int j = 0; j < 2 * n + 1; j++)
            cin >> a[i][j];
}
//Вывод матрицы
void output_matr(tmatr a, int n)
{
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cout.width(3);
            cout << a[i][j];
        }
        cout << endl;
    }
    return;
}
///Поиск суммы значений элементов, лежащих ниже главной диагонали
void summa(tmatr a, int n, telem& sum_gl)
{
    sum_gl = 0;
    for (int i = 0; i < 2 * n + 1; ++i)
        for (int j = 0; j < 2 * n + 1; ++j)
        { 
            if (i > j)
            {
                sum_gl += a[i][j];
            }
        }
    return ;
}
//поиск максимального элемента
void  obnul_up(tmatr a, int n,int&max_1, int&max_2)
{
    telem max= a[0][0];
    for (int i = 0; i < 2 * n + 1; i++)
        for (int j = 0; j < 2 * n + 1; j++)
            if (max < a[i][j])
            {
                max = a[i][j];
                max_1 = i;
                max_2 = j;
            }
    return ;
}
//поиск минимального элемента
void  obnul_down (tmatr a, int n,int& min_1, int& min_2)
{
    telem min=a[0][0];
    for (int i = 0; i < 2 * n+1; i++)
        for (int j = 0 ; j <2 * n+1; j++)
            if (min> a[i][j])
            {
                min = a[i][j];
                min_1 = i;
                min_2 = j;
            }
    return ;
}
//перестановка минимального и максимального
void per(tmatr a, int n, int max,int min)
{
    int tpm;
    int min_1=0, min_2=0, max_1=0, max_2=0;
     for (int i = 0; i < 2 * n + 1; i++)
        for (int j = 0; j < 2 * n + 1; j++)
        { 
           if (min == a[i][j])
           {
              min_1 = i;
              min_2 = j;
           }
          if (max == a[i][j])
          {
               max_1 = i;
               max_2 = j;
          }
       }
    tpm = a[max_1][max_2];
    a[max_1][max_2] = a[min_1][min_2];
    a[min_1][min_2]=tpm;
}
