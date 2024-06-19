#include <stdio.h>

#include <Windows.h>

#define MAX_X 50

#define MAX_Y 20

int CUR_X, CUR_Y;

#define mainMenuStartX 10

#define subMenuStartX 15

enum MainMenuOrder { MainMenu_Oper = 1 };

enum SubMenuOrder{SubMenu_Add=3, SubMenu_Sub=5, SubMenu_Mul =7, SubMenu_Div =9};

void TurnCursor(BOOL bTurn)
{
    CONSOLE_CURSOR_INFO cci;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    cci.bVisible = bTurn;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void gotoxy(int x, int y)
{
    COORD Pos;

    Pos.X = x;

    Pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

double Add(double a, double b)
{

    return a + b;

}

/// 함수 추가 <<---

double OperationFunc(double (*func)(double, double))

{

    double num1, num2;

    gotoxy(0, SubMenu_Div + 5); // 마지막 서브메뉴 항목보다 충분히 아래 좌표에서 입/출력

    TurnCursor(1); // 커서 보이게

    printf("Input two nums: ");

    scanf_s("%lf %lf", &num1, &num2);

    TurnCursor(0); // 커서 안보이게

    return ; /// <<--- return 문 적절히 완성
}

void OnSubMenuClicked(int subMenuID)

{

    double result = 0.;

    switch (subMenuID)
    {
        case SubMenu_Add:
            result = OperationFunc(Add);
            break;
    /// <<--- switch-case 문 적절히 완성
    }
    gotoxy(0, SubMenu_Div + 5 + 1); // 마지막 서브메뉴 항목보다 충분히 아래 좌표에서 입/출력 5 + 1

    printf("Result: %.2lf \n", result);
}

void DrawMenu()
{
    // Main menu

    gotoxy(mainMenuStartX, MainMenu_Oper - 1);

    printf("┌─────────────────┐\n");

    gotoxy(mainMenuStartX, MainMenu_Oper);

    printf("│ Operations │\n");

    gotoxy(mainMenuStartX, MainMenu_Oper + 1);

    printf("└─────────────────┘\n");

    // Sub menus

    gotoxy(subMenuStartX, SubMenu_Add -1);

    printf("┌─────────────────┐\n");

    gotoxy(subMenuStartX, SubMenu_Add);

    printf("│ Addition │\n");

    gotoxy(subMenuStartX, SubMenu_Sub -1);

    printf("├─────────────────┤\n");

    gotoxy(subMenuStartX, SubMenu_Sub - 1);

    printf("├─────────────────┤\n");

    gotoxy(subMenuStartX, SubMenu_Sub);

    printf("│ Subtraction │\n");

    gotoxy(subMenuStartX, SubMenu_Mul -1);

    printf("├─────────────────┤\n");

    gotoxy(subMenuStartX, SubMenu_Mul);

    printf("│ Multiflication │\n");

    gotoxy(subMenuStartX, SubMenu_Div -1);

    printf("├─────────────────┤\n");

    gotoxy(subMenuStartX, SubMenu_Div);

    printf("│ Division │\n");

    gotoxy(subMenuStartX, SubMenu_Div + 1);

    printf("└─────────────────┘\n");

    gotoxy(mainMenuStartX, MainMenu_Oper - 1);
}

int main()
{

    char formatStr[50] = { 0, };

    sprintf_s(formatStr, sizeof(formatStr), "mode con: cols=%d lines=%d", MAX_X, MAX_Y); // "mode con: cols=MAX_X lines=MAX_Y"

    system(formatStr); //creates a window

    TurnCursor(0); // 커서 안보이게

    int key;

    DrawMenu(); // draw menu

    gotoxy(CUR_X= mainMenuStartX, CUR_Y= MainMenu_Oper);

    printf("▶");

    while (1)
    {

        key = _getch(); // read low 1 byes

        switch (key)
        {
        case 224: // 0xE0, arrow key starts

        gotoxy(CUR_X, CUR_Y);

        key = _getch(); // read high 1 byes

        switch (key)
        {

    case 72: // Up

    if (CUR_Y > SubMenu_Add)

    CUR_Y -= 2;

    break;

    case 80: // Down

    CUR_X = subMenuStartX;

    if (CUR_Y < SubMenu_Div)

    CUR_Y += 2;

    break;

    case 75: // Left

    case 77: // Right --> we don't use these horizontal keys.

    default:

    break;

    }

    break;

    case 13:

    if(CUR_Y != MainMenu_Oper)

    {

    system("cls");

    //////////////////////////////////////

    OnSubMenuClicked(CUR_Y);

    //////////////////////////////////////

    }

    break;

    case 27:

    system("cls");

    printf("Bye... \n");

    exit(0);

    break; //

    default:

    break;

    }

    DrawMenu();

    gotoxy(CUR_X, CUR_Y);

    printf("▶");

    }

}