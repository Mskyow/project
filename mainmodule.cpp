#include <windows.h> 
#include <stdio.h> 
#include <iostream> 
#include <stdlib.h> 
#include <conio.h> 

using namespace std;

void PrintglMenu(int&);
int funk(int, int&);

int main()
{
    system("chcp 1251 > nul");
    //////////////////////////////////////////////////////////////////////// 
    int n = 7;// индекс последнего пункта меню 
    int c;
    c = funk(n, c);
    //PrintglMenu(c); 
    while (TRUE)
    {
        //funk (nLast,c); 
        //c = funk (nLast,c); 
        switch (c)
        {
        case 1:
            cout << "   Выбран первый пункт меню.\n";
            break;
        case 2:
            cout << "   Выбран второй пункт меню.\n";
            break;
        case 3:
            cout << "   Выбран третий пункт меню.\n";
            break;
        case 4:
            cout << "    Выбран четвертый пункт меню.\n";
            break;
        case 5:
            cout << "    Выбран пятый пункт меню.\n";
            break;
        case 6:
            cout << "    Выбран шестой пункт меню.\n";
            break;
        case 7:
            cout << "    Выбран седьмой пункт меню.\n";
            break;

        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////// 
    //getch(); 
    return 0;
}
int funk(int nMenu, int& input)
{
    input = 1;//устанавливаем на первый пункт меню 
    PrintglMenu(input);
    while (TRUE)//бесконечный цикл 
    {
        if (GetAsyncKeyState(VK_UP))
        {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку 
            0 < input - 1 ? input = input - 1 : input = nMenu;
            PrintglMenu(input);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку 
            input < nMenu ? input = input + 1 : input = 1;
            PrintglMenu(input);

        }
        if (GetAsyncKeyState(VK_RETURN)) //VK_RETURN = 13; 
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку 
            Sleep(200);//иначе не работает с вложенными меню 
            PrintglMenu(input);
            //Sleep(200); 
            //cout <<input; 
            return input;
        }
    }
    //return input; 
}
void PrintglMenu(int& b)
{
    system("cls");
    cout << " Просто двигайте стрелку по пунктам меню и на выбранном жмите Enter.Удачи! " << "\n";
    cout << "\t\t\t Ваш выбор:   " << "\n\n";
    printf("\t%s 1 пункт меню. \n", b == 1 ? "->" : " ");
    printf("\t%s 2 пункт меню. \n", b == 2 ? "->" : " ");
    printf("\t%s 3 пункт меню. \n", b == 3 ? "->" : " ");
    printf("\t%s 4 пункт меню.     \n", b == 4 ? "->" : " ");
    printf("\t%s 5 пункт меню. \n", b == 5 ? "->" : " ");
    printf("\t%s 6 пункт меню. \n", b == 6 ? "->" : " ");
    printf("\t%s 7 пункт меню. \n", b == 7 ? "->" : " ");

}
