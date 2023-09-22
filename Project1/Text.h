#pragma once

#include<string>

class Text
{
private:

	std::string text;

	char** fillingMatrix(char** matrix, int sizeMatr);

	char** rearranging—olumnsForEncryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey);
	char** rearrangingStringsForEncryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey);

	char** rearranging—olumnsForDecryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey);
	char** rearrangingStringsForDecryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey);

public:

	Text(std::string _text = "");
	~Text();

	void setText(std::string _text);
	std::string getText();

	std::string getEncryptedText(std::string key1, std::string key2);
	std::string getDecryptedText(std::string key1, std::string key2);
};

Text::Text(std::string _text)
{
	text = _text;
}

Text::~Text()
{
	text = "";
}

void  Text::setText(std::string _text)
{
	text = _text;
}

std::string Text::getText()
{
	return text;
}

char** Text::fillingMatrix(char** matrix, int sizeMatr)
{
	int textInd = 0;
	for (int i = 0; i < sizeMatr; i++)
		for (int j = 0; j < sizeMatr; j++)
		{
			matrix[i][j] = text[textInd];
			textInd++;
		}

	return matrix;
}

char** Text::rearranging—olumnsForEncryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey)
{
	char** newMatrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		newMatrix[i] = new char[sizeMatr];

	int columnInd = 0;
	for (int i = 0; i < sizeKey; i++)
	{
		for (int j = 0; j < sizeMatr; j++)
			newMatrix[j][columnInd] = origMatrix[j][(key[i] - '0') - 1];
		columnInd++;
	}

	return newMatrix;

}

char** Text::rearrangingStringsForEncryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey)
{
	char** newMatrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		newMatrix[i] = new char[sizeMatr];

	int stringInd = 0;
	for (int i = 0; i < sizeKey; i++)
	{
		for (int j = 0; j < sizeMatr; j++)
			newMatrix[stringInd][j] = origMatrix[(key[i] - '0') - 1][j];
		stringInd++;
	}

	return newMatrix;
}

char** Text::rearranging—olumnsForDecryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey)
{
	char** newMatrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		newMatrix[i] = new char[sizeMatr];

	int columnInd = 0;
	for (int i = 0; i < sizeKey; i++)
	{
		for (int j = 0; j < sizeMatr; j++)
			newMatrix[j][(key[i] - '0') - 1] = origMatrix[j][columnInd];
		columnInd++;
	}

	return newMatrix;
}

char** Text::rearrangingStringsForDecryption(char** origMatrix, int sizeMatr, std::string key, int sizeKey)
{
	char** newMatrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		newMatrix[i] = new char[sizeMatr];

	int stringInd = 0;
	for (int i = 0; i < sizeKey; i++)
	{
		for (int j = 0; j < sizeMatr; j++)
			newMatrix[(key[i] - '0') - 1][j] = origMatrix[stringInd][j];
		stringInd++;
	}

	return newMatrix;
}

std::string Text::getEncryptedText(std::string key1, std::string key2)
{
	int sizeKey1 = key1.length(), sizeKey2 = key2.length();
	if (sizeKey1 == 0 || sizeKey2 == 0 || sizeKey1 != sizeKey2)
		return "";

	int sizeMatr = sizeKey1;

	char** matrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		matrix[i] = new char[sizeMatr];

	matrix = fillingMatrix(matrix, sizeMatr);
	matrix = rearranging—olumnsForEncryption(matrix, sizeMatr, key1, sizeKey1);
	matrix = rearrangingStringsForEncryption(matrix, sizeMatr, key2, sizeKey2);

	text = "";
	for (int i = 0; i < sizeMatr; i++)
		for (int j = 0; j < sizeMatr; j++)
			text += matrix[j][i];

	for (int i = 0; i < sizeMatr; i++)
		delete[]matrix[i];
	delete[]matrix;

	return text;
}

std::string Text::getDecryptedText(std::string key1, std::string key2)
{
	int sizeKey1 = key1.length(), sizeKey2 = key2.length();
	if (sizeKey1 == 0 || sizeKey2 == 0 || sizeKey1 != sizeKey2)
		return "";

	int sizeMatr = sizeKey1;

	char** matrix = new char* [sizeMatr];
	for (int i = 0; i < sizeMatr; i++)
		matrix[i] = new char[sizeMatr];

	matrix = fillingMatrix(matrix, sizeMatr);
	matrix = rearranging—olumnsForDecryption(matrix, sizeMatr, key2, sizeKey1);
	matrix = rearrangingStringsForDecryption(matrix, sizeMatr, key1, sizeKey2);

	text = "";
	for (int i = 0; i < sizeMatr; i++)
		for (int j = 0; j < sizeMatr; j++)
			text += matrix[j][i];

	for (int i = 0; i < sizeMatr; i++)
		delete[]matrix[i];
	delete[]matrix;

	return text;
}
