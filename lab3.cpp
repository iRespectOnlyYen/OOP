#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <ctype.h>


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

double power1(double n, int p = 2)
{
    return pow(n, p);
}
void number2()
{
    double number, answer;
    int pow;
    char yeserno;
    cout << "\nВведите число:"; // get number
    cin >> number;
    cout << "Будете вводить степень (y/n)?";
    cin >> yeserno;
    if (yeserno == 'y')// пользователю нужен не квадрат числа?
    {
        cout << "Введите степень:";
        cin >> pow;
        answer = power1(number, pow); // возвести число в степень
    }
    else
        answer = power1(number); // квадрат числа
    cout << "Ответ " << answer << endl;
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
    struct Employee
    {
        int number;
        float money;
    };

    Employee worker1, worker2, worker3;

    cout << "Введите данные о сотруднике 1:";
    cin >> worker1.number;
    cin >> worker1.money;

    cout << "Введите данные о сотруднике 2:";
    cin >> worker2.number;
    cin >> worker2.money;

    cout << "Введите данные о сотруднике 3:";
    cin >> worker3.number;
    cin >> worker3.money;


}


int hms_to_secs(int hours, int minutes, int seconds) {
    int32_t all_seconds = seconds + minutes * 60 + hours * 60 * 60;
    return all_seconds;
}
void number5()
{
    int x = 0;
    while (x == 0) {

        int hours;
        int minutes;
        int seconds;
        char separator_character;

        cout << "Введите часы, минуты и секунды (например 20:08:30): ";
        cin >> hours >> separator_character >> minutes >> separator_character >> seconds;

        cout << "Время в секундах: " << hms_to_secs(hours, minutes, seconds) << endl;

        cout << "Желаете продолжить? (y/n): ";
        char continue_programm;
        cin >> continue_programm;
        if (continue_programm == 'y') {}
        else if (continue_programm == 'n') { break; }
        else cout << "Неверный символ";
        cout << endl;
    }
}

struct time1
{
    int hour;
    int minutes;
    int seconds;
};
int time_to_secs(int hours, int minutes, int seconds) {
    int32_t all_seconds = seconds + minutes * 60 + hours * 60 * 60;
    return all_seconds;
}
time1 secs_to_time(int seconds) {



    time1 t;

    t.seconds = seconds % 60;
    seconds /= 60;
    t.minutes = seconds % 60;
    t.hour = seconds / 60;
    return (t);
}
void number6()
{

    time1 t1, t2, t_finale;
    char slash;
    cout << "Введите время1 (например 12:36:56): ";
    cin >> t1.hour >> slash >> t1.minutes >> slash >> t1.seconds;

    cout << "Введите время2 (например 12:36:56): ";
    cin >> t2.hour >> slash >> t2.minutes >> slash >> t2.seconds;

    int64_t all_seconds = time_to_secs(t1.hour, t1.minutes, t1.seconds) + time_to_secs(t2.hour, t2.minutes, t2.seconds);
    t_finale = secs_to_time(all_seconds);
    cout << "Сумма времени: " << t_finale.hour << slash << t_finale.minutes << slash << t_finale.seconds;

}

double power1(int n, int p = 2)
{
    return pow(n, p);
}
double power1(long n, int p = 2)
{
    return pow(n, p);
}
double power1(float n, int p = 2)
{
    return pow(n, p);
}
double power1(char n, int p = 2)
{
    return pow(n, p);
}
void number7()
{
    cout << "Введите аргументы типов: double, int, long, float, char." << endl;
    double a;
    int b;
    long c;
    float d;
    char e;
    cin >> a >> b >> c >> d >> e;
    cout << power1(a)<<endl;
    cout << power1(b)<< endl;
    cout << power1(c) << endl;
    cout << power1(d) << endl;
    cout << power1(e) << endl;
}


void swap1(int& a, int& b) 
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void number8()
{
    cout << "Введите значения переменных A и B, программа поменяет их значения местами. " << endl;
    int a, b;
    cin >> a >> b;
    swap1(a, b);
    cout << a <<' '<< b;
}


void swap_time(time1& a, time1& b) 
{
    time1 temp;
    temp = a;
    a = b;
    b = temp;
}
void number9()
{
    cout << "Введите значения переменных A и B, программа поменяет их значения местами. " << endl;
    time1 a, b;
    char slash;
    cin >> a.hour >> slash >> a.minutes >> slash >> a.seconds;
    cin >> b.hour >> slash >> b.minutes >> slash >> b.seconds;
    swap_time(a,b);
    cout << endl<< a.hour << slash << a.minutes << slash << a.seconds;
    cout << endl<<b.hour << slash << b.minutes << slash << b.seconds;
}

int count_test = 0;
void func_global() 
{
    count_test++;
    cout <<"Функция была вызванна "<<count_test<<" раз(а)"<<endl;
}
void func_static()
{
    static int counter_static = 0;
    counter_static++;
    cout << "Функция была вызванна " << counter_static << " раз(а)" << endl;
}
void number10()
{
    
    for (int i = 0;i < 10; i++) 
    {
        func_global();
    }
    cout << endl;

    for (int i = 0;i < 10; i++)
    {
        func_static();
    }
}


struct sterling
{
    int pounds;
    int shillings;
    int pence;
};
void print_sterling(sterling sterling) 
{
    cout << "Сумма стерлингов: ";
    cout << sterling.pounds <<'.'<< sterling.shillings << '.' << sterling.pence;
}
sterling sum_sterling(sterling value1, sterling value2) 
{
    sterling sum_sterling;
    sum_sterling.pounds = value1.pounds + value2.pounds;
    sum_sterling.shillings = value1.shillings + value2.shillings;
    sum_sterling.pence = value1.pence + value2.pence;
    sum_sterling.shillings = sum_sterling.pence / 12 + sum_sterling.shillings;
    sum_sterling.pence = sum_sterling.pence % 12;
    sum_sterling.pounds = sum_sterling.pounds + sum_sterling.shillings / 20;
    sum_sterling.shillings = sum_sterling.shillings % 20;
    return sum_sterling;

}
sterling get_sterling(sterling& value) {
    cout << "Введите кол-во стерлингов (пример: 1.1.1)"<<endl;
    char slash;
    cin >> value.pounds >>slash>> value.shillings >>slash>> value.pence;
    return value;
}
void number11()
{
    sterling value1, value2;
    get_sterling(value1);
    get_sterling(value2);
    print_sterling(sum_sterling(value1, value2));

}


struct fraction
{
    int chisl;
    int znam;
};
fraction f_addition(fraction d1, fraction d2)
{
    fraction d_totale;
    d_totale.chisl = (d1.chisl * d2.znam + d1.znam * d2.chisl);
    d_totale.znam = (d1.znam * d2.znam);
    return d_totale;
}
fraction f_subtraction(fraction d1, fraction d2)
{
    fraction d_totale;
    d_totale.chisl = (d1.chisl * d2.znam - d1.znam * d2.chisl);
    d_totale.znam = (d1.znam * d2.znam);
    return d_totale;
}
fraction f_multiplication(fraction d1, fraction d2)
{
    fraction d_totale;
    d_totale.chisl = (d1.chisl * d2.chisl); 
    d_totale.znam = (d1.znam * d2.znam);
    return d_totale;
}
fraction f_division(fraction d1, fraction d2)
{
    fraction d_totale;
    d_totale.chisl = (d1.chisl * d2.znam); 
    d_totale.znam = (d1.znam * d2.chisl);
    return d_totale;
}
void number12()
{
    fraction d1, d2, d_totale;

    cout << "Программа выполняет четыре арифемтических действия над дробями\n(Пример: 12/2 + 12/2)" << endl << endl;
    char slash, deistvie, next_or_stop = 'y';

    while (next_or_stop == 'y') {

        cout << "Введите выражение: ";
        cin >> d1.chisl >> slash >> d1.znam >> deistvie >> d2.chisl >> slash >> d2.znam;

        switch (deistvie)

        {
        case '+':  d_totale = f_addition(d1, d2);
            break;
        case '-':  d_totale = f_subtraction(d1, d2);
            break;
        case '*':  d_totale = f_multiplication(d1, d2);
            break;
        case '/':  d_totale = f_division(d1, d2);
            break;

        }
        cout << "\nОтвет: " << d_totale.chisl << '/' << d_totale.znam;

        double A = d_totale.chisl;
        double B = d_totale.znam;

        if (A != 0)
            while (A != B) {
                if (A > B) A -= B;
                else B -= A;
            }
        if (A > 1) {
            if (d_totale.znam / A == 1) cout << "\nМожно скоратить до: " << d_totale.chisl / A;
            else cout << "\nМожно скоратить до: " << d_totale.chisl / A << '/' << d_totale.znam / A;
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
