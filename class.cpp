#include "pch.h"
#include <iostream>
#include <fstream>
#include "Eigen/Dense"
#include <vector>
#include "Read.h"
template<typename T>
void ShowVec(const std::vector<T>& valList) {
	using std::vector;
	for (auto iter = valList.cbegin(); iter != valList.cend(); iter++) {
		std::cout << "第" << iter - valList.cbegin() + 1 << "个矩阵:" << std::endl;
		std::cout << (*iter) << std::endl;
	}
}
void Matrixs::Read(char *FP) {
	//通过检测矩阵第一行的元素个数来获得矩阵的列数，把元素总数除以列数得到行数，再把储存在vector里的所有元素映射到矩阵
	int flag = 0, Cols = 0, CountNumber = 0;//flag用于判断是否有连续的空格，Cols为列数，Rows为行数，CountNumber为元素总数
	float number = 0;//float类型的元素
	std::vector<float> numbers;//用于储存所有元素
	std::ifstream InFile;
	InFile.open(FP, std::ios::in);//打开文件，只读
	if (!InFile.is_open()) {
		std::cout << "Open file failure" << std::endl;
		exit(1);
	}
	while (!InFile.eof())
	{
		InFile >> number;//输入到number中
		numbers.push_back(number);
		CountNumber++;//获取元素总数
	}
	InFile.close();
	FILE *fp;
	fopen_s(&fp, FP, "r");
	char str = 'F';
	while (1) {
		str = fgetc(fp);
		if (str == '\n')//只检测第一行，故遇到回车就跳出
			break;
		if (str == ' ' && flag == 0) {
			flag = 1;
			continue;
		}
		if (str != ' '&& flag == 1)
		{
			flag = 0;
			Cols += 1;//得到第一行列数减一
		}
	}
	fclose(fp);
	fp = NULL;
	free(fp);
	Cols += 1;
	int Rows = CountNumber / Cols;
	Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> M(numbers.data(), Rows, Cols);
	Matrixs_.push_back(M);
	ShowVec(Matrixs_);
}
Matrixs::Matrixs() {
	std::cout << "Construct" << std::endl;
}
Matrixs::~Matrixs() {
	std::cout << "Destruct" << std::endl;
}