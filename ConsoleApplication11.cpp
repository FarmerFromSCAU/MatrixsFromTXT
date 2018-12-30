#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Eigen/Dense"
#include "Read.h"
int main()
{
	//读入两个文件中的数值，以矩阵的形式储存在类的成员中
	Matrixs M;
	char *FileName = (char *)malloc(30 * sizeof(char));
	std::cin >> FileName;//输入文件名，带后缀
	M.Read(FileName);
	free(FileName);
	char *FileName2 = (char *)malloc(30 * sizeof(char));
	std::cin >> FileName2;//输入文件名，带后缀
	M.Read(FileName2);
	free(FileName2);

}
