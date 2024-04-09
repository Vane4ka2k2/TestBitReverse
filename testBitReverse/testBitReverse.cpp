#include "testBitReverse.h"

using namespace std;

uint8_t bitReverse(uint8_t num)
{
	uint8_t reversedNum = 0;
	const int bits = 4;

	for (size_t i = 0; i < bits; ++i)
	{
		reversedNum |= ((num >> i) & 1) << (bits - 1 - i);
	}

	return reversedNum;
}

uint8_t** oneDimToTwoDim(uint8_t* oneDimArray, int rows, int cols)
{
	uint8_t** twoDimArray = new uint8_t * [rows];

	for (size_t i = 0; i < rows; ++i)
	{
		twoDimArray[i] = new uint8_t[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			twoDimArray[i][j] = oneDimArray[i * cols + j];
		}
	}

	return twoDimArray;
}

void testArray()
{
	size_t rows = 16;
	size_t cols = 16;

	uint8_t* oneDimArray = new uint8_t[rows * cols];
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			oneDimArray[i * cols + j] = i * cols + j;
		}
	}

	uint8_t** twoDimArray = oneDimToTwoDim(oneDimArray, rows, cols);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			cout << static_cast<unsigned>(twoDimArray[i][j]) << "\t";
		}
		cout << endl;
	}
	cout << endl;

	uint8_t** twoDimArrayTwo = new uint8_t * [rows];

	for (size_t i = 0; i < rows; ++i)
	{
		twoDimArrayTwo[i] = new uint8_t[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			twoDimArrayTwo[i][j] = twoDimArray[i][j];
		}
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			twoDimArrayTwo[i][j] = twoDimArray[static_cast<unsigned>(bitReverse(i))][static_cast<unsigned>(bitReverse(j))];
		}
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			cout << static_cast<unsigned>(twoDimArrayTwo[i][j]) << "\t";
		}
		cout << endl;
	}

	// очистка памяти
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] twoDimArray[i];
	}

	delete[] twoDimArray;
	
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] twoDimArrayTwo[i];
	}

	delete[] twoDimArrayTwo;

	delete[] oneDimArray;
}

void testBitReverse()
{
	for (size_t i = 0; i < 16; ++i)
	{
		cout << i << " " << static_cast<unsigned>(bitReverse(i)) << "\n";
	}
}

void simpleTest()
{
	// Создаем исходный массив из 12 чисел
	int* originalArray = new int[12];
	for (int i = 0; i < 12; ++i) {
		originalArray[i] = i + 1;
	}

	// Создаем второй массив, в который будем копировать каждый третий элемент
	int* newArray = new int[4]; // Создаем новый динамический массив

	// Предположим, что у вас есть какие-то значения в newArray, назначим их для примера
	for (int i = 0; i < 4; ++i) {
		newArray[i] = i + 21;
	}

	// Удаляем старый массив
	delete[] originalArray;

	// Создаем новый массив и копируем значения из newArray
	originalArray = new int[4];
	for (int i = 0; i < 4; ++i) {
		originalArray[i] = newArray[i];
	}

	// Выводим обновленный первый массив на экран
	std::cout << "Updated original array:" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << originalArray[i] << " ";
	}
	std::cout << std::endl;

	// Удаляем второй массив
	delete[] newArray;

	// Удаляем новый массив, так как он больше не нужен
	delete[] originalArray;
}

int main()
{
	simpleTest();

	return 0;
}