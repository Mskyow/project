#include <conio.h>
#include <time.h> 
#include <iomanip>
#include <iostream>
#include <algorithm>  // Библ. для transform()
#include <fstream>  // Библ. для работы с файлами
#include <windows.h>  // Библ. для ввода/вывода в консоль 
#include <string>  // Библ. для работы со строками
#include <ctime>  // Библ. для таймера
#include <map>  // Библ. для словарей
#include <set>  // Библ. для сет
#include <vector>


using namespace std;


void prog_name() {
	cout << "		<=============================================>" << endl << endl;
	cout << "		                 TEXT ANALYZER" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void nav_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			МЕНЮ НАВИГАЦИИ" << endl;
	cout << "		   1. Выбор файла" << endl;
	cout << "		   2. Настройки регистра" << endl;
	cout << "		   3. Настройки нежелательных символов" << endl;
	cout << "		   4. Настройки нежелательных слов" << endl;
	cout << "		   5. Режим сортировки" << endl << endl;
	cout << "		   ? - чтобы узнать инструкцию" << endl << endl;
	cout << "		   ! - чтобы узнать выбранные настройки" << endl << endl;
	cout << "		<=============================================>" << endl;
}

int file_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ ФАЙЛ" << endl;
		cout << "		   1. Песни группы Курара" << endl;
		cout << "		   2. Песни группы Сплин" << endl;
		cout << "		   3. Песни группы ДДТ" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int font_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ПЕРЕВОД РЕГИСТРА" << endl;
		cout << "		   1. Перевести в нижний" << endl;
		cout << "		   2. Не менять регистр" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 50 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int symb_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СИМВОЛОВ" << endl;
		cout << "		   1. Заготовленный набор символов" << endl;
		cout << "		   2. Создать свой набор" << endl;
		cout << "		   3. Не удалять символы" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int word_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СЛОВ" << endl;
		cout << "		   1. Союзы и предлоги" << endl;
		cout << "		   2. Местоимения" << endl;
		cout << "		   3. Все перечисленные" << endl;
		cout << "		   4. Не удалять слова" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 52 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
			word_menu();
		}
	}
}

int sort_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ СОРТИРОВКУ" << endl;
		cout << "		   1. Алфавитный порядок" << endl;
		cout << "		   2. В порядке по убыванию" << endl;
		cout << "		   3. В порядке по возрастанию" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
			sort_menu();
		}
	}
}

void help() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ИНСТРУКЦИЯ" << endl;
	cout << "		   В п.1 Вы должны выбрать открываемый файл." << endl;
	cout << "		   В п.2 Вы выбираете нужно ли переводить" << endl;
	cout << "		  текст в нижний регистр." << endl;
	cout << "		   В п.3 рекомендуется удалить некоторые" << endl;
	cout << "		  символы, во избежении слов со знаками" << endl;
	cout << "		  препинания(например, \"конец.\", \",утро-\")." << endl;
	cout << "		   В п.4 Вы можете выбрать какие слова" << endl;
	cout << "		  будут удалены(например, можно убрать" << endl;
	cout << "		  местоимения и союзы)." << endl;
	cout << "		   В п.5 у Вас есть возможность выбрать" << endl;
	cout << "		  желаемую сортировку." << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

void status(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer) {
	string status_answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБРАННЫЕ НАСТРОЙКИ" << endl;
	switch (file_menu_answer) {
	case 1:
		status_answer = "песни группы Курара";
		break;
	case 2:
		status_answer = "песни группы Сплин";
		break;
	case 3:
		status_answer = "песни группы ДДТ";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Открываемый файл: " << status_answer << endl;
	switch (font_menu_answer) {
	case 1:
		status_answer = "нижний";
		break;
	case 2:
		status_answer = "не изменять";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Регистр: " << status_answer << endl;
	switch (symb_menu_answer) {
	case 1:
		status_answer = "заготовленный набор";
		break;
	case 2:
		status_answer = "свой набор";
		break;
	case 3:
		status_answer = "не удалять символы";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Удаляемые символы: " << status_answer << endl;
	switch (word_menu_answer) {
	case 1:
		status_answer = "союзы и предлоги";
		break;
	case 2:
		status_answer = "местоимения";
		break;
	case 3:
		status_answer = "все перечисленные";
		break;
	case 4:
		status_answer = "не удалять слова";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Удаляемые слова: " << status_answer << endl;
	switch (sort_menu_answer) {
	case 1:
		status_answer = "алфавитный порядок";
		break;
	case 2:
		status_answer = "в порядке убывания";
		break;
	case 3:
		status_answer = "в порядке возрастания";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Вид сортировки: " << status_answer << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

int ready_for_analysis() {
	string answer;
	while (true) {
		cout << "		    <=============================================>" << endl << endl;
		cout << "			   ВСЕ НАСТРОЙКИ ПРОИЗВЕДЕНЫ" << endl;
		cout << "		       1. Начать анализ" << endl;
		cout << "		       2. Поменять настройки" << endl << endl;
		cout << "		    <=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) == 49 && answer.length() == 1) {
			system("cls");
			return 1;
		}
		else if (int(answer[0]) == 50 && answer.length() == 1) {
			system("cls");
			return 0;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

