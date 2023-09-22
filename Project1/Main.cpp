#include<iostream>
#include"Text.h"

int main()
{
	setlocale(0, "rus");

	Text text;
	text.setText("ШИФРОВАНИЕ_ПЕРЕСТАНОВКОЙ_");

	std::cout << "Незашифрованное сообщение \n";
	std::cout << text.getText() << "\n\n";

	std::cout << "Зашифрованное сообщение \n";
	std::cout << text.getEncryptedText("15432", "14532") << "\n\n";

	std::cout << "Расшифрованное сообщение \n";
	std::cout << text.getDecryptedText("15432", "14532") << "\n\n";
	return 0;
}