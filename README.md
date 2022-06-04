<h1 align="center">MATH LIBRARY </h1>

  Эта библиотека создана для работы с матрицами
  
## [Класс Matrix](#Класс-Matrix)
1. [Конструкторы](#Конструкторы)

    1.[Matrix(int n)](#Matrix(int-n))

    2.[Matrix(int n, int m)](#Matrix(int-n,-int-m))
3. [SetMij](#SetMij)
4. [ReadBin](#ReadBin)
5. [WriteBin](#WriteBin)
6. [Hadamard](#Hadamard)
7. [Det](#Det)

## Класс Matrix

### Конструкторы

#### Matrix(int n)
Создание квадратной матрицы размера n на n

#### Matrix(int n, int m)
  Создание матрицы размера n на m

+ Matrix(initializer_list<double> list)

Создание квадратной матрицы, строки которой состоят из list
  
+ EMatrix (int n)
  
Создание единичной матрицы размера n на n

+ DMatrix(int n)
  
Создание диагональной матрицы размера n на n с значениями на диагонали от 1 до n
  
+ UTatrix (int n)
  
Создание верхней треугольной матрицы размера n на n  
  
+ LTMatrix (int n)
  
Создание нижней треугольной матрицы размера n на n
  
+ SMatrix (int n)
  
Создание симметричной матрицы размера n на n
  
# SetMij
  + SetMij(int i, int j, const double value)

Замена перепенной на позиции i j на значение value

# ReadBin
  + ReadBin(const char* fname)
  
Чтение матрицы из бинарного файла с именем fname
  
# WriteBin
  + ReadBin(const char* fname)
  
Запись матрицы в бинарный файл с именем fname

# Hadamard
  + N1.Hadamard(Matrix N2)
Произведение Адамара (N1 * N2)

# Det
  + Det(Matrix M)
Определитель матрицы M
  

