#include <conio.h>
#include "Autocompletion.h"
#include <iostream>


int main()
{
    //Поддержка русского языка.
	setlocale(LC_ALL, "Russian");

    //Инициализирует базовый словарь.
    std::string word[] = { "durt", "durk", "drift", "dog", "dos", "dote", "zebra", "zuko", "area", "world", "work" };
    int n = sizeof(word) / sizeof(word[0]);

	bool _true = true;
	std::string str;
	while (_true)
	{
		Trie t;
		t.insertion(word, n);
		std::cout << "Выберите действие:    1 - автодополнение          2 - выход \n";

		char choose;
		std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
		switch (choose)
		{

		case '1':
			std::cout << "введите слово:  ";
			getline(std::cin, str);
			t.findAllPrefix(str);

			std::cout << std::endl;
			break;
		case '2':
			_true = false;
			break;
		default:
			break;
		}

	}


    return 0;
}