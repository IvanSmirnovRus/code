#include "matrix.h"

int main(int argc, char const *argv[])
{
	TMatrix<int> m = TMatrix<int>(4, 5);
	m.Print();
	std::cout << m.RowSize() << std::endl;
	std::cout << m[5] << std::endl;
	std::cout << "Сложение с числом" << std::endl;
	TMatrix<int> n = m + 1;
	n.Print();
	std::cout << "Сложение матриц"<< std::endl;
	TMatrix<int> k = n + m;
	k.Print();
	std::cout << "Вычитание числа"<< std::endl;
	TMatrix<int> p = n - 10;
	p.Print();
	std::cout << "Вычитание матриц" << std::endl;
	TMatrix<int> j = p - n;
	j.Print();
	std::cout << "Умножение на число"<< std::endl;
	TMatrix<int> i = n * 2;
	i.Print();
	std::cout << "Умножение на число" << std::endl;
	TMatrix<int> h = n * 3;
	h.Print();
	std::cout <<"Умножение матриц" << std::endl;
	TMatrix<int> q = h * i;


	q.Print();
	std::cout << "Умножение +=" << std::endl;
	q+= 20;
	q.Print();
	return 0;
}