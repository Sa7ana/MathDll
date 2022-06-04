<h1 align="center">MATH LIBRARY </h1>

  Эта библиотека создана для работы с матрицами
  
## [Класс Matrix](#Класс-Matrix)
1. [Конструкторы](#Конструкторы)
2. [Функции](#Функции)

### Класс Matrix

### Конструкторы

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
  
# Функции 
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
  

