#include "pch.h"
#include "MathLib.h"

#define PI 3.14159265   

void Matrix::WriteBin(const char* fname) {
	ofstream file(fname, ios::binary);
	if (!file) throw Exception1("Error: file open error");
	else {
		int n = M.size();
		int m = M[0].size();
		file.write((char*)&n, sizeof(int));
		file.write((char*)&m, sizeof(int));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				file.write((char*)&M[i][j], sizeof(double));
	}
	file.close();
}

void Matrix::ReadBin(const char* fname) {
	ifstream file(fname, ios::binary);
	if (!file) throw Exception1("Error: file open error");
	else {
		int n = 0;
		int m = 0;

		file.read((char*)&n, sizeof(int));
		file.read((char*)&m, sizeof(int));
		Matrix T1(n, m);
		M = T1.M;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				file.read((char*)&M[i][j], sizeof(double));
	}
	file.close();
}


ofstream& operator << (ofstream& out, Matrix& M1) {
	for (int i = 0; i < M1.M.size(); i++) {
		for (int j = 0; j < M1.M[0].size(); j++) {
			out << M1.M[i][j];
			if (j != M1.M[0].size() - 1)
				out << "	";
			else
				if (i != M1.M.size() - 1)
					out << '\n';
		}
	}

	return out;
}

ifstream& operator>>(ifstream& input, Matrix& M1) {

	int count = 0;
	vector<double> vec;

	while (!input.eof())
	{
		double temp;
		input >> temp;
		count++;
		vec.push_back(temp);
	}

	input.seekg(0, ios::beg);
	input.clear();

	int count_space = 0;
	char str;
	while (!input.eof())
	{
		input.get(str);
		if (str == '	') count_space++;
		if (str == '\n') break;
	}
	int k = 0;
	int n = count / (count_space + 1);
	int m = count_space + 1;
	//cout << count << "  " << count_space << endl;;
	Matrix M2(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			M2.M[i][j] = vec[k];
			k++;
		}
	M1 = M2;
	return input;
}

Matrix::Matrix(int n) {
	vector<double> x;
	for (int i = 0; i < n; i++)
		x.push_back(0);
	for (int i = 0; i < n; i++)
		M.push_back(x);
}

Matrix::Matrix(initializer_list<double> list) {
	vector<double> x;
	for (auto m : list)
		x.push_back(m);
	for (int i = 0; i < list.size(); i++)
		M.push_back(x);
}

Matrix::Matrix(int m, int n) {
	vector<double> x;
	for (int i = 0; i < n; i++)
		x.push_back(0);
	for (int i = 0; i < m; i++)
		M.push_back(x);
}

ostream& operator<< (ostream& out, const Matrix& M)
{
	cout << endl;
	for (int i = 0; i < M.M.size(); i++) {
		for (int j = 0; j < M.M[0].size(); j++) {
			if (abs(M.M[i][j]) > 10E-7)
				cout << M.M[i][j] << "\t";
			else
				cout << 0 << "\t";
		}
		cout << endl;
	}
	return out;
}

void  Matrix::SetMij(int i, int j, const double value) {

	if (i > M.size() || j > M[0].size()) {
		throw Exception1("Error: There is no element in the matrix with such indexes");
	}
	else
		M[i - 1][j - 1] = value;
	vector<vector<double>> Mat;
}


Matrix Matrix::operator + (const Matrix N)const {
	Matrix S(N.M.size(), N.M[0].size());
	if (M.size() == N.M.size() && M[0].size() == N.M[0].size()) {
		for (int i = 0; i < N.M.size(); i++) {
			for (int j = 0; j < N.M[0].size(); j++) {
				S.M[i][j] = M[i][j] + N.M[i][j];
			}
		}
	}
	else
		throw Exception1("Error:  not equal size ");
	return S;
}

Matrix Matrix::operator-(Matrix N)const {
	Matrix S(N.M.size(), N.M[0].size());
	if (M.size() == N.M.size() && M[0].size() == N.M[0].size()) {
		for (int i = 0; i < N.M.size(); i++) {
			for (int j = 0; j < N.M[0].size(); j++) {
				S.M[i][j] = M[i][j] - N.M[i][j];
			}
		}
	}
	else
		throw Exception1("Error:  not equal size ");
	return S;
};


Matrix Matrix::operator*(double x)const {
	Matrix S(M.size(), M[0].size());
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[0].size(); j++) {
			S.M[i][j] = M[i][j] * x;
		}
	}
	return S;
};

Matrix Matrix::operator*(Matrix N)const {
	Matrix S(M.size(), N.M[0].size());
	if (M[0].size() == N.M.size()) {
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < N.M[0].size(); j++) {
				for (int k = 0; k < M[0].size(); k++)
					S.M[i][j] += M[i][k] * N.M[k][j];
			}
		}
	}
	else
		throw Exception1("Error: objects have incompatible shapes");
	return S;
};


Matrix Matrix::Hadamard(Matrix N2) {
	Matrix S(M.size(), M[0].size());
	if (M.size() == N2.M.size() && M[0].size() == N2.M[0].size()) {
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[0].size(); j++) {
				S.M[i][j] = M[i][j] * N2.M[i][j];
			}
		}
	}
	else
		throw Exception1("Error:  not equal size");
	return S;
}

double Matrix::Det() {

	Matrix Mat;
	Mat.M = M;
	double D = 1;
	if (M.size() == M[0].size() && M.size() != 0) {
		for (int j = 0; j < Mat.M.size(); j++) {
			int k = j;
			for (int i = j + 1; i < Mat.M.size(); i++)
				if (abs(Mat.M[i][j]) > abs(Mat.M[k][j]))
					k = i;

			if (abs(Mat.M[k][j]) < 1E-9) {
				D = 0;
				break;
			}

			swap(Mat.M[j], Mat.M[k]);
			if (j != k)
				D = -D;
			D = D * Mat.M[j][j];

			for (int i = j + 1; i < Mat.M.size(); i++)
				Mat.M[j][i] /= Mat.M[j][j];
			for (int i = 0; i < Mat.M.size(); i++)
				if (i != j && abs(Mat.M[i][j]) > 1E-9)
					for (int k = j + 1; k < Mat.M.size(); ++k)
						Mat.M[i][k] -= Mat.M[j][k] * Mat.M[i][j];

		}
	}
	else
		throw Exception1("Error:  Matrix must be square");
	return D;
}

double Matrix::Rank() {
	Matrix Mat(M.size(), M[0].size());
	Mat.M = M;
	int r = 0;
	for (int j = 0; j < Mat.M.size(); j++) {
		int k = j;
		for (int i = j + 1; i < Mat.M.size(); i++)
			if (abs(Mat.M[i][j]) > abs(Mat.M[k][j]))
				k = i;

		swap(Mat.M[j], Mat.M[k]);

		for (int i = j + 1; i < Mat.M.size(); i++)
			Mat.M[j][i] /= Mat.M[j][j];
		for (int i = 0; i < Mat.M.size(); i++)
			if (i != j && abs(Mat.M[i][j]) > 1E-9)
				for (int k = j + 1; k < Mat.M.size(); ++k)
					Mat.M[i][k] -= Mat.M[j][k] * Mat.M[i][j];
	}
	for (int i = 0; i < Mat.M.size(); i++) {
		if (Mat.M[i][i] > 1E-9)
			r++;
	}
	return r;
}

Matrix Matrix::Minor(int n, int m) {
	Matrix Mat(M.size(), M[0].size());
	Mat.M = M;
	if (n <= Mat.M.size() && m <= Mat.M[0].size()) {
		Mat.M.erase(Mat.M.begin() + n - 1);
		for (int i = 0; i < Mat.M.size(); i++) {
			Mat.M[i].erase(Mat.M[i].begin() + m - 1);
		}
	}
	else
		throw Exception1("Error: There is no element in the matrix with such indexes");
	return Mat;
}

Matrix Matrix::Transpose() {
	Matrix Mat(M[0].size(), M.size());
	for (int i = 0; i < Mat.M.size(); i++) {
		for (int j = 0; j < Mat.M[0].size(); j++) {
			Mat.M[i][j] = M[j][i];

		}
	}
	return Mat;
}

Matrix Matrix::Inverse() {
	Matrix Mat(M.size(), M[0].size());
	Mat.M = M;
	Matrix Inv(Mat.M.size());
	if (Mat.Det() != 0 && Mat.M.size() == Mat.M[0].size() && Mat.M.size() != 0) {
		for (int i = 0; i < Mat.M.size(); i++) {
			for (int j = 0; j < Mat.M.size(); j++) {
				Inv.M[i][j] = (Mat.Minor(i + 1, j + 1)).Det() * pow(-1, i + j + 2);
			}
		}
		Inv = Inv * (1 / Mat.Det());
	}
	else
		throw Exception1("Error: There is no inverse matrix for this matrix");
	return Inv.Transpose();
}


double Matrix::Scalar(Matrix M2) {
	double scal = 0;
	if (M.size() == 1 && M2.M.size() == 1) {
		if (M2.M[0].size() == M[0].size() && M2.M[0].size() != 0) {
			for (int j = 0; j < M[0].size(); j++)
				scal = scal + M[0][j] * M2.M[0][j];
		}
		else
			throw Exception1("Error:  not equal size ");
	}
	else {
		if (M[0].size() == 1 && M2.M[0].size() == 1) {
			if (M2.M.size() == M.size() && M2.M.size() != 0) {
				for (int j = 0; j < M.size(); j++)
					scal = scal + M[j][0] * M2.M[j][0];
			}
			else
				throw Exception1("Error:  not equal size ");
		}
		else
			throw Exception1("Error: Objects must be vectors");

	}
	return scal;
}

double Matrix::Norm() {
	Matrix M1(M.size(), M[0].size());
	M1.M = M;
	return sqrt(M1.Scalar(M1));
}

double Matrix::Tr() {
	double tr = 0;
	if (M.size() == M[0].size() && M.size() != 0)
		for (int i = 0; i < M[0].size(); i++)
			tr = tr + M[i][i];
	else
		throw Exception1("Error: Matrix must be square");
	return tr;
}

double Matrix::Max() {
	if (M.size() == 1 && M[0].size() != 0) {
		double max = M[0][0];
		for (int i = 1; i < M[0].size(); i++)
			if (M[0][i] > max)
				max = M[0][i];
		return max;
	}
	else {
		if (M[0].size() == 1 && M.size() != 0) {
			double max = M[0][0];
			for (int i = 1; i < M.size(); i++)
				if (M[i][0] > max)
					max = M[i][0];
			return max;
		}
		else
			throw Exception1("Error: Objects must be vectors");
		return 0;
	}
}


double Matrix::NormM() {
	double norm = 0;
	if (M.size() != 0 && M[0].size() != 0) {
		for (int i = 0; i < M.size(); i++) {
			Matrix a(1);
			a.M[0] = M[i];
			norm = norm + a.Scalar(a);
		}
	}
	else
		throw Exception1("Error: zero-size matrix ");
	return sqrt(norm);
}

double Matrix::Angle(Matrix M2) {
	Matrix M1(M.size(), M[0].size());
	M1.M = M;
	double ang = acos(M1.Scalar(M2) / M1.Norm() / M2.Norm()) * 180.0 / PI;
	if (ang > 90)
		ang = 180 - ang;
	return ang;
}

EMatrix::EMatrix(int n) {
	for (int i = 0; i < n; i++) {
		vector<double> x;
		for (int j = 0; j < n; j++)
			if (j == i)
				x.push_back(1);
			else
				x.push_back(0);
		M.push_back(x);
	}
}


DMatrix::DMatrix(int n) {
	for (int i = 0; i < n; i++) {
		vector<double> x;
		for (int j = 0; j < n; j++)
			if (j == i)
				x.push_back(i + 1);
			else
				x.push_back(0);
		M.push_back(x);
	}
}


UTMatrix::UTMatrix(int n) {
	for (int i = 0; i < n; i++) {
		vector<double> x;
		for (int j = 0; j < n; j++)
			if (j >= i)
				x.push_back(i + 1 + j);
			else
				x.push_back(0);
		M.push_back(x);
	}
}



LTMatrix::LTMatrix(int n) {
	for (int i = 0; i < n; i++) {
		vector<double> x;
		for (int j = 0; j < n; j++)
			if (j <= i)
				x.push_back(i + 1 + j);
			else
				x.push_back(0);
		M.push_back(x);
	}
}

SMatrix::SMatrix(int n) {
	for (int i = 0; i < n; i++) {
		vector<double> x;
		for (int j = 0; j < n; j++) {
			if (j <= i)
				x.push_back(i + 1 + j);
			else {
				if (j > i)
					x.push_back(i + 1 + j);
				else
					x.push_back(0);
			}
		}
		M.push_back(x);
	}
}

vector<int> Matrix::Size() {
	vector<int> s;
	s.push_back(M.size());
	s.push_back(M[0].size());
	return s;
}

double Matrix::getElem(int n, int m) {
	return M[n][m];
}

Matrix PCA::Centering(Matrix M1) {
	Matrix M2(M1.Size()[0], M1.Size()[1]);
	double summ = 0;
	for (int i = 0; i < M1.Size()[1]; i++, summ = 0) {
		for (int j = 0; j < M1.Size()[0]; j++)
			summ += M1.getElem(j, i);
		for (int j = 0; j < M1.Size()[0]; j++)
			M2.SetMij(j + 1, i + 1, summ / M1.Size()[0]);
	}


	return M1 - M2;
}

Matrix PCA::Scaling(Matrix M1) {
	Matrix M2(M1.Size()[0], M1.Size()[1]);
	double summ = 0, sj = 0;
	for (int i = 0; i < M1.Size()[1]; i++, summ = 0) {
		for (int j = 0; j < M1.Size()[0]; j++)
			summ += M1.getElem(j, i);
		for (int j = 0; j < M1.Size()[0]; j++, sj = 0) {
			for (int k = 0; k < M1.Size()[0]; k++) {
				sj += pow((M1.getElem(k, i) - summ), 2);
			}
			M2.SetMij(j + 1, i + 1, (M1.getElem(j, i) - summ) / sqrt(sj / (M1.Size()[0] - 1)));
		}
	}
	return M2;
}

Matrix Matrix::AddColumn(Matrix V) {
	if (M.size() == 0)
		return V;

	else {
		if (M.size() == V.M.size()) {
			Matrix New(M.size(), M[0].size() + 1);
			for (int i = 0; i < M.size(); i++) {
				for (int j = 0; j < M[0].size(); j++)
					New.M[i][j] = M[i][j];
				New.M[i][M[0].size()] = V.M[i][0];
			}
			return New;
		}
		else
			throw Exception1("Error: objects have incompatible shapes ");
	}
}


PCA::PCA(Matrix M, int ar) {
	if (ar >= M.Size()[0] || ar >= M.Size()[1])
		throw Exception1("Error: out of range");
	Matrix D;
	D = Centering(M);
	D = Scaling(D);

	E = D;
	//int min = ((E.Size()[0]) < (E.Size()[1]) ? (E.Size()[0]) : (E.Size()[1]));

	for (int h = 0; h < ar; h++) {
		Matrix t(E.Size()[0], 1);
		for (int i = 0; i < E.Size()[0]; i++)
			t.SetMij(i + 1, 1, E.getElem(i, h));

		Matrix d;
		Matrix p;
		do {

			p = (t.Transpose() * E) * (1 / (t.Transpose() * t).getElem(0, 0));
			p = p * (1 / p.Norm());

			Matrix t_old;
			t_old = t;
			t = (E * p.Transpose()) * (1 / (p * p.Transpose()).getElem(0, 0));
			d = t_old - t;
		} while (d.Norm() > 1e-8);

		E = E - (t * p);
		P = P.AddColumn(p.Transpose());
		T = T.AddColumn(t);

	}

}

void PCA::Dispersion() {

	vector<double> a;
	for (int i = 0; i < T.Size()[1]; i++) {
		a.push_back(0);
		for (int j = 0; j < T.Size()[0]; j++)
			a[i] += pow(T.getElem(j, i), 2);
	}


	double sa = 0;
	for (auto v : a)
		sa += v;


	for (int i = 0; i < a.size() + 1; i++) {
		double s = 0;
		for (int k = 0; k < TRV.size(); k++)
			s += a[k];
		TRV.push_back((sa - s) / (T.Size()[0] * T.Size()[1]));
	}

	for (auto x : TRV)
		ERV.push_back(1 - x / TRV[0]);
}

void PCA::HV() {
	//H

	vector<double> a;
	for (int i = 0; i < T.Size()[1]; i++) {
		a.push_back(0);
		for (int j = 0; j < T.Size()[0]; j++)
			a[i] += pow(T.getElem(j, i), 2);
	}

	for (int i = 0; i < T.Size()[0]; i++) {
		double summ = 0;
		for (int k = 0; k < T.Size()[1]; k++)
			summ += pow(T.getElem(i, k), 2) / a[k];
		H.push_back(summ);
	}


	//V
	for (int i = 0; i < E.Size()[0]; i++) {
		double summ = 0;
		for (int j = 0; j < E.Size()[1]; j++)
			summ += pow(E.getElem(i, j), 2);
		V.push_back(summ);
	}
}

Matrix PCA::GetP() { return P; }
Matrix PCA::GetT() { return T; }
Matrix PCA::GetE() { return E; }
vector<double> PCA::GetH() { return H; }
vector<double> PCA::GetV() { return V; }
vector<double> PCA::GetTRV() { return TRV; }
vector<double> PCA::GetERV() { return ERV; }