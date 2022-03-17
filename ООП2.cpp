#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <ctype.h>

int oleg = -401238478;

void number1()
{
    unsigned long n;                    //number 

    cout << "\nEnter a number: ";
    cin >> n;                           //get number     
    for (int j = 1; j <= 200; j++)           //loop from 1 to 200 
    {

        cout << setw(5) << j * n << "  ";  //print multiple of n        
        if (j % 10 == 0)                  //every 10 numbers,          
            cout <<
            endl;                 //start new line 

    }
}
void number2()
{
    int response;
    double temper;



    cout << "\nType 1 to convert fahrenheit to celsius," << "\n2 to convert celsius to fahrenheit : ";    cin >> response;

    if (response == 1)

    {

        cout << "Enter temperature in fahrenheit: ";
        cin >> temper;
        cout << "In celsius that's " << 5.0 / 9.0 * (temper - 32.0);

    }
    else

    {

        cout << "Enter temperature in celsius: ";
        cin >> temper;
        cout << "In fahrenheit that's " << 9.0 / 5.0 * temper + 32.0;

    }

    cout << endl;

}

void number3()
{


    char ch;
    unsigned long total = 0; //this holds the number 


    cout << "\nEnter a number: ";
    while ((ch = _getche()) != '\r') //quit on Enter       
        total = total * 10 + ch - '0';     //add digit to total*10    
    cout << "\nNumber is: " << total << endl;


}

void number4()
{

    {

        double n1, n2, ans;
        char oper, ch;


        do {
            cout << "\nEnter first number, operator, second number: ";
            cin >> n1 >> oper >> n2;
            switch (oper)

            {
            case '+':  ans = n1 + n2;
                break;
            case '-':  ans = n1 - n2;
                break;
            case '*':  ans = n1 * n2;
                break;
            case '/':  ans = n1 / n2;
                break;

            default:   ans = 0;

            }

            cout << "Answer = " << ans;
            cout << "\nDo another (Enter 'y' or 'n')? ";
            cin >> ch;
        } while (ch != 'n');

    }

}
void number5()
{
    int x = 20;
    for (int i = 0; i < x; i++)
    {
        for (int j = x; j > i; j--)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << 'X';
        cout << endl;
    }
}

void number6()
{

    unsigned int numb = 1;

    while (numb != 0) {
        unsigned long fact = 1; //long for larger numbers  
        cout << "Enter a number: ";
        cin >> numb; //get number  
        if (numb == 0) break;


        for (int j = numb; j > 0; j--)         //multiply 1 by       
            fact *= j;                     //numb, numb-1, ..., 2, 1    
        cout << "Factorial is " << fact << endl;
    }

}

void number7()
{

    cout << "Программа рассчитает сумму денег, которую вы получите при вложении начальной суммы \nс фиксированной процентной ставкой дохода через определенное количество лет.\n\n";
    cout << "Введите начальный вклад: ";
    double money_value;
    cin >> money_value;
    cout << "Введите кол-во лет: ";
    int years;
    cin >> years;
    cout << "Введите процентную ставку: ";
    double persent;
    cin >> persent;
    if (persent <= 0) cout << "Введённый процент отрицательный или равен нулю";
    else {
        for (int i = 1; i <= years;i++) {
            money_value *= 1 + (persent / 100.);
        }

        cout << "\nРасчётный размер вклада спустя время: " << money_value;
    }
}

void number8()
{
    char char1 = 'y';
    int v11, v12, v13, v21, v22, v23, vs1, vs2, vs3;
    while (char1 == 'y') {
        cout << "Введите первую сумму:";
        cin >> v11 >> v12 >> v13;
        cout << "Введите вторую сумму:";
        cin >> v21 >> v22 >> v23;

        vs3 = (v23 + v13) % 12;
        vs2 = (v22 + v12 + ((v23 + v13) / 12)) % 20;
        vs1 = ((v22 + v12 + ((v23 + v13) / 12)) / 20) + v11 + v21;

        cout << "Всего: " << vs1 << ' ' << vs2 << ' ' << vs3 << endl << endl << "Продолжить (y/n)?\n";
        cin >> char1;
    }

}

void number9()
{
    cout << "Введите количество стульев: ";
    int taburetka;
    cin >> taburetka;
    cout << "Введите количество гостей: ";
    int guest, total = 1;
    cin >> guest;
    for (0; taburetka; taburetka -= 1) {
        total = total * guest;
        guest -= 1;

    }
    cout << "\nКол-во комбинация для размещения гостей: " << total;

}

void number10()
{
    cout << "Программа расчитывает количество лет для достижения заданной суммы вклада.\n\n";
    cout << "Введите начальный вклад: ";
    double money_value;
    int count_years = 0;
    cin >> money_value;
    cout << "Введите процентную ставку: ";
    double persent;
    cin >> persent;
    cout << "Введите желаемый размер вклада: ";
    double target;
    cin >> target;
    if (persent <= 0) cout << "Введённый процент отрицательный или равен нулю";
    else {
        while (money_value < target) {
            money_value *= (1 + (persent / 100.));
            count_years += 1;
        }


        cout << "\nКоличество лет необходимых для достижения цели: " << count_years;
    }
}

void number11()
{
    double v11, v12, v13, v21, v22, v23, vs1, vs2, vs3;
    double old_funt, old_shill, old_pens;
    cout << "Введите выражение (примеры: 1 1 1 + 2 2 2, 3 2 1 * 2): ";
    char char1;
    cin >> v11 >> v12 >> v13 >> char1 >> v21;
    v22 = 1; v23 = 1;
    if ((char1 == '+') or (char1 == '-')) cin >> v22 >> v23;
    old_funt = v11; old_shill = v12; old_pens = v13;
    double n1 = old_funt + old_shill / 20. + old_pens / 240.;
    old_funt = v21; old_shill = v22; old_pens = v23;
    double n2 = old_funt + old_shill / 20. + old_pens / 240.;

    double ans;
    switch (char1)

    {
    case '+':  ans = n1 + n2;
        break;
    case '-':  ans = n1 - n2;
        break;
    case '*':  ans = n1 * v21;
        break;
    case '/':  ans = n1 / v21;
        break;

    default:   ans = 0;

    }
    double old_funt1, old_shill1, old_pens1;
    int int_funt1 = ans;
    old_shill1 = (ans - int_funt1) * 20.;
    int int_old_shill1 = old_shill1;
    old_pens1 = (old_shill1 - int_old_shill1) * 12.;
    cout << "Результат: ";
    cout << int_funt1 << ' ' << int_old_shill1 << ' ' << (int)old_pens1;
}

void number12()
{
    cout << "Программа выполняет четыре арифемтических действия над дробями\n(Пример: 12/2 + 12/2)" << endl << endl;
    double a, b, c, d, znam, chisl;
    char slash, deistvie, next_or_stop = 'y';

    while (next_or_stop == 'y') {

        cout << "Введите выражение: ";
        cin >> a >> slash >> b >> deistvie >> c >> slash >> d;

        switch (deistvie)

        {
        case '+':  chisl = (a * d + b * c); znam = (b * d);
            break;
        case '-':  chisl = (a * d - b * c); znam = (b * d);
            break;
        case '*':  chisl = (a * c); znam = (b * d);
            break;
        case '/':  chisl = (a * d); znam = (b * c);
            break;

        }
        cout << "\nОтвет: " << chisl << '/' << znam;

        double A = chisl;
        double B = znam;

        if (A != 0)
        while (A != B) {
            if (A > B) A -= B;
            else B -= A;
        }
        if (A > 1) {
            if (znam / A == 1) cout << "\nМожно скоратить до: " << chisl / A;
            else cout << "\nМожно скоратить до: " << chisl / A << '/' << znam / A;
        }

        cout << "\nЖелаете продолжить (y/n)?\n";
        cin >> next_or_stop;
        cout << endl << endl;
    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    int x, number_max = 12, number_work = 2;
    for (int i = 0;1;i) {
        system("cls");
        cout << "Лабораторная работа №1" << endl;
        cout << "Введите номер задания: ";
        cin >> x;
        cout << "Задание " << x << endl << endl;
        if ((x > number_max) or (x < 1)) {
            cout << "Задания с таким номером не существует\nДля продолжения нажмите любую кнопку";
            int nothing = _getch();
        }
        else {
            for (int j = 0;1;j) {
                system("cls");
                cout << "Лабораторная работа №1" << endl;
                cout << "Задание " << x << endl << endl;
                switch (x) {
                case 1:
                    number1();
                    break;
                case 2:
                    number2();
                    break;
                case 3:
                    number3();
                    break;
                case 4:
                    number4();
                    break;
                case 5:
                    number5();
                    break;
                case 6:
                    number6();
                    break;
                case 7:
                    number7();
                    break;
                case 8:
                    number8();
                    break;
                case 9:
                    number9();
                    break;
                case 10:
                    number10();
                    break;
                case 11:
                    number11();
                    break;
                case 12:
                    number12();
                    break;


                }
                cout << "\n\nДля того чтобы перейти к следющему номеру нажмите стрелку вверх на клавиатуре, для того \nчтобы вернуться к предыдущему - стрелку вниз, что бы запустить номер ещё раз - пробел." << endl;
                cout << "Что бы вернуться к выбору номера нажмите любую другую кнопку.";
                int key = _getch();
                if (((key == 119) or (key == 230) or (key == 87) or (key == 150)) and (x < number_max)) x++;
                else if (((key == 115) or (key == 235)) and (x > 1)) x--;
                else if ((key == 114) or (key == 170)) x;
                else break;
            }
        }
    }
}