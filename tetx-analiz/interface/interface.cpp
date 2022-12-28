#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


// Интерфейс меню
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
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void file_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ ФАЙЛ" << endl;
	cout << "		   1. Песни ГрОба" << endl;
	cout << "		   2. Какие-то книги" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void font_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ РЕГИСТР" << endl;
	cout << "		   1. Нижний" << endl;
	cout << "		   2. Верхний" << endl;
	cout << "		   3. Не менять регистр" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void symb_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СИМВОЛОВ" << endl;
	cout << "		   1. Заготовленный набор символов" << endl;
	cout << "		   2. Создать свой набор" << endl;
	cout << "		   3. Не удалять символы" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void word_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СЛОВ" << endl;
	cout << "		   1. Заготовленный набор слов" << endl;
	cout << "		   2. Создать свой набор" << endl;
	cout << "		   3. Не удалять слова" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void sort_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ СОРТИРОВКУ" << endl;
	cout << "		   1. Алфавитный порядок" << endl;
	cout << "		   2. В порядке по убыванию" << endl;
	cout << "		   3. В порядке по возрастанию" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void help() { // памагити
	cout << "		<=============================================>" << endl << endl;
	cout << "			СПИСОК КОМАНД" << endl << endl;
	cout << "			Команды для вызова меню" << endl;
	cout << "		   !navmenu - меню навигации по настройкам" << endl;
	cout << "		   !filemenu - меню настроки рабочего файла" << endl;
	cout << "		   !fontmenu - меню настроки регистра" << endl;
	cout << "		   !symbmenu - меню настроки удаляемых символов" << endl;
	cout << "		   !wordmenu - меню настроки удаляемых слов" << endl;
	cout << "		   !sortmenu - меню настроки сортировки" << endl << endl;
	cout << "			Прочие команды" << endl;
	cout << "		   !exit - выход из программы" << endl;
	cout << "		   !start - запуск анализатора" << endl;
	cout << "		   !findword - поиск по слову" << endl;
	cout << "		   !settings - узнать выбранные " << endl << endl;
	cout << "		<=============================================>" << endl;
}

void main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int answer;
	cin >> answer;
	cout << answer;

	prog_name();
	cout << endl << endl;
	_getch();
	system("cls");

	nav_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	file_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	font_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	symb_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	word_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	sort_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	help();
	cout << endl << endl;
	_getch();
	system("cls");
}