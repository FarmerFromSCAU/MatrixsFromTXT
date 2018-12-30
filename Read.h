#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_
template<typename T>
void ShowVec(const std::vector<T>& valList);
class Matrixs {
private:
	std::vector<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic>> Matrixs_;
public:
	//Constructor
	Matrixs();
	//Deconstructor
	~Matrixs();
	void Read(char *FP);

};
#endif
