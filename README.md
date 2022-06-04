<h1 align="center">MATH LIBRARY </h1>

  Эта библиотека создана для работы с матрицами

## Оглавление:
### Класс Matrix
1. [Конструкторы Matrix](#Конструкторы-Matrix)
2. [Функции Matrix](#Функции-Matrix)
### Класс PCA
1. [Конструкторы PCA](#Конструкторы-PCA)
2. [Функции PCA](#Функции-PCA)

## Класс Matrix

### Конструкторы Matrix

```
Matrix x(int n)
```
  Создание квадратной матрицы x размера n на n

```
Matrix x(int n, int m)
```
  Создание матрицы x размера n на m

```
Matrix x(initializer_list<double> list)
```
  Создание квадратной матрицы x, строки которой состоят из list
```
EMatrix x(int n)
```
  Создание единичной матрицыx размера n на n
```
DMatrix x(int n)
``` 
  Создание диагональной матрицы x размера n на n с значениями на диагонали от 1 до n
```
UTatrix x(int n)
```

  Создание верхней треугольной матрицы x размера n на n  
  
```
LTMatrix x(int n)
``` 
  Создание нижней треугольной матрицы x размера n на n
  
```
SMatrix x(int n)
```
  Создание симметричной матрицы x размера n на n
  
### Функции Matrix
+ SetMij
```
SetMij(int i, int j, const double value)
```
Замена перепенной на позиции i j на значение value

+ ReadBin
```
ReadBin(const char* fname)
```
Чтение матрицы из бинарного файла с именем fname
  
+ WriteBin
```
ReadBin(const char* fname)
```  
Запись матрицы в бинарный файл с именем fname

+ Hadamard
```
N1.Hadamard(Matrix N2)
```
Произведение Адамара (N1 * N2)

+ Det
```
Det(Matrix M)
```
Определитель матрицы M

+ Scalar
```
(Matrix x).Scalar(Matrix y)
```
Скалярное произведение векторов x и y

+ Norm
```
(Matrix x).Norm()
```
Норма вектора x

+ NormM
```
(Matrix M).NormM()
```
Норма матрицы M

+ Tr
```
(Matrix M).Tr()
```
След матрицы М

+ Angle
```
(Matrix M1).Angle(Matrix M2)
```
Угол между векторами M1 и M2

+ Rank
```
(Matrix M).Rank()
```
Ранг матрицы M

+ Minor
```
(Matrix M).Minor(int n, int m)
```
Минор элемента на позиции n, m матрицы M

+ Transpose
```
(Matrix M).Transpose()
```
Транспонирование матрицы M

+ Inverse
```
(Matrix M).Inverse()
```
Обратная матрица к матрице M

+ AddColumn
```
(Matrix M).AddColumn(Matrix V)
```
Добавление вектора столбца V к матрице M 

+getElem
```
(Matrix M).getElem(int n, int m)
```
Возвращение элемента на позиции n, m матрицы M


## Класс PCA

### Конструкторы PCA

```
PCA p(Matrix M, int ar);
```
Обработка матрицы M алгоритмом PCA и создание элемента класса PCA с результатом

### Функции PCA

+ Centering
```
Centering(Matrix M1)
```
Центрирование матрицы M1

+ Scaling
```
Scaling(Matrix M1)
```
Шкалирование матрицы M1

+ HV
```
(PCA p).HV()
```
Вычисление размахов и отклонений

+ Dispersion
```
(PCA p).Dispersion()
```
Вычисление дисперсии

+  GetP
```
(PCA p).GetP()
```
Возвращает матрицу весов

+  GetT
```
(PCA p).GetT()
```
Возвращает матрицу счётов

+  GetE
```
(PCA p).GetE()
```
Возвращает матрицу остатков

+  GetH
```
(PCA p).GetH()
```
Возвращает вектор размаха

+  GetV
```
(PCA p).GetV()
```
Возвращает вектор отклонений

+  GetTRV
```
(PCA p).GetTRV()
```
Возвращает вектор полной дисперсии остатков

+  GetERV
```
(PCA p).GetERV()
```
Возвращает вектор объясненной дисперсии остатков
