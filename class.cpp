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
		std::cout << "��" << iter - valList.cbegin() + 1 << "������:" << std::endl;
		std::cout << (*iter) << std::endl;
	}
}
void Matrixs::Read(char *FP) {
	//ͨ���������һ�е�Ԫ�ظ�������þ������������Ԫ���������������õ��������ٰѴ�����vector�������Ԫ��ӳ�䵽����
	int flag = 0, Cols = 0, CountNumber = 0;//flag�����ж��Ƿ��������Ŀո�ColsΪ������RowsΪ������CountNumberΪԪ������
	float number = 0;//float���͵�Ԫ��
	std::vector<float> numbers;//���ڴ�������Ԫ��
	std::ifstream InFile;
	InFile.open(FP, std::ios::in);//���ļ���ֻ��
	if (!InFile.is_open()) {
		std::cout << "Open file failure" << std::endl;
		exit(1);
	}
	while (!InFile.eof())
	{
		InFile >> number;//���뵽number��
		numbers.push_back(number);
		CountNumber++;//��ȡԪ������
	}
	InFile.close();
	FILE *fp;
	fopen_s(&fp, FP, "r");
	char str = 'F';
	while (1) {
		str = fgetc(fp);
		if (str == '\n')//ֻ����һ�У��������س�������
			break;
		if (str == ' ' && flag == 0) {
			flag = 1;
			continue;
		}
		if (str != ' '&& flag == 1)
		{
			flag = 0;
			Cols += 1;//�õ���һ��������һ
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