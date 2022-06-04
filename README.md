<h1 align="center">MATH LIBRARY </h1>

  Эта библиотека создана для работы с матрицами
  
  ## Функции
  1. [Matrix](#Matrix)
  2. [SetMij](#SetMij)
  3. [ReadBin](#ReadBin)


## Разделительная черта


## Matrix
+ Matrix(int n, int m) 

  Создание матрицы размера n на m
+ Matrix(int n)

Создание квадратной матрицы размера n на n

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
  
Чтение матрицы из бинарного файла
