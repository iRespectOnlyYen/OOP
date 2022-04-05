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


void number7()
{


    enum etype { laborer, secretary, manager, accountant, executive, researcher };

    struct Data
    {
        int mounth;
        int day;
        int years;
    };

    struct Employee
    {
        int number;
        float money;
        Data start_work;
        etype position;
    };

    char slash;

    Employee worker_info1, worker_info2, worker_info3;

    cout << "Введите номер первого сотрудника: ";
    cin >> worker_info1.number;

    cout << "Введите пособие первого сотрудника: ";
    cin >> worker_info1.money;

    cout << "Введите дату устройства на работу первого сотрудника: ";
    cin >> worker_info1.start_work.mounth;
    cin >> slash;
    cin >> worker_info1.start_work.day;
    cin >> slash;
    cin >> worker_info1.start_work.years;



    cout << "Введите первую букву профессии: ";
    char x;
    cin >> x;
    switch (x)
    {
    case 'l':
        worker_info1.position = laborer;
        break;
    case 's':
        worker_info1.position = secretary;
        break;
    case 'm':
        worker_info1.position = manager;
        break;
    case  'a':
        worker_info1.position = accountant;
        break;
    case 'e':
        worker_info1.position = executive;
        break;
    case 'r':
        worker_info1.position = researcher;
        break;
    }



    cout << endl << endl;




    cout << "Введите номер второго сотрудника: ";
    cin >> worker_info2.number;

    cout << "Введите пособие второго сотрудника: ";
    cin >> worker_info2.money;

    cout << "Введите дату устройства на работу второго сотрудника: ";
    cin >> worker_info2.start_work.mounth;
    cin >> slash;
    cin >> worker_info2.start_work.day;
    cin >> slash;
    cin >> worker_info2.start_work.years;


    cout << "Введите второго букву профессии: ";

    cin >> x;
    switch (x)
    {
    case 'l':
        worker_info2.position = laborer;
        break;
    case 's':
        worker_info2.position = secretary;
        break;
    case 'm':
        worker_info2.position = manager;
        break;
    case  'a':
        worker_info2.position = accountant;
        break;
    case 'e':
        worker_info2.position = executive;
        break;
    case 'r':
        worker_info2.position = researcher;
        break;
    }


    cout << endl << endl;


    cout << "Введите номер третьего сотрудника: ";
    cin >> worker_info3.number;

    cout << "Введите пособие третьего сотрудника: ";
    cin >> worker_info3.money;

    cout << "Введите дату устройства на работу третьего сотрудника: ";
    cin >> worker_info3.start_work.mounth;
    cin >> slash;
    cin >> worker_info3.start_work.day;
    cin >> slash;
    cin >> worker_info3.start_work.years;

    cout << "Введите третьего букву профессии: ";

    cin >> x;
    switch (x)
    {
    case 'l':
        worker_info3.position = laborer;
        break;
    case 's':
        worker_info3.position = secretary;
        break;
    case 'm':
        worker_info3.position = manager;
        break;
    case  'a':
        worker_info3.position = accountant;
        break;
    case 'e':
        worker_info3.position = executive;
        break;
    case 'r':
        worker_info3.position = researcher;
        break;
    }

    cout << endl << endl;

    cout << "Первый сотрудник" << endl << "Зарплата: " << worker_info1.money << endl << "Номер: " << worker_info1.number << endl << "Дата устройства: " << worker_info1.start_work.mounth << slash << worker_info1.start_work.day << slash << worker_info1.start_work.years << endl << "Должность: ";
    switch (worker_info1.position)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    }

    cout << endl << endl;

    cout << "Второе сотрудник" << endl << "Зарплата: " << worker_info2.money << endl << "Номер: " << worker_info2.number << endl << "Дата устройства: " << worker_info2.start_work.mounth << slash << worker_info2.start_work.day << slash << worker_info2.start_work.years << endl << "Должность: ";
    switch (worker_info2.position)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    }

    cout << endl << endl;
    cout << "Третий сотрудник" << endl << "Зарплата: " << worker_info3.money << endl << "Номер: " << worker_info3.number << endl << "Дата устройства: " << worker_info3.start_work.mounth << slash << worker_info3.start_work.day << slash << worker_info3.start_work.years << endl << "Должность: ";
    switch (worker_info3.position)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    }

}

void number8()
{
    cout << "Программа складывает дроби находя общий знаминатель" << endl << endl;
    struct fraction
    {
        int chisl;
        int znam;
    };
    fraction drob1, drob2, finale;
    char slash;

    cout << "Введите первую дробь: ";
    cin >> drob1.chisl >> slash >> drob1.znam;

    cout << "Введите вторую дробь: ";
    cin >> drob2.chisl >> slash >> drob2.znam;

    finale.chisl = (drob1.chisl * drob2.znam) + (drob2.chisl * drob1.znam);
    finale.znam = drob1.znam * drob2.znam;

    cout << "\nСумма равна: " << finale.chisl << '/' << finale.znam;

    double a = finale.chisl;
    double b = finale.znam;

    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    if (a > 1) cout << "\nМожно скоратить до: " << finale.chisl / a << '/' << finale.znam / a;
}

void number9()
{
    struct time
    {
        int hour;
        int minutes;
        int seconds;
    };
    time t1;
    char slash;
    cout << "Введите время (например 12:36:56): ";
    cin >> t1.hour >> slash >> t1.minutes >> slash >> t1.seconds;
    long totalsecs = t1.hour * 3600 + t1.minutes * 60 + t1.seconds;
    cout << "totalsecs = " << totalsecs;
}

void number10()
{
    struct sterling
    {
        int pounds;
        int shillings;
        int pence;
    };

    sterling old;
    double funt;

    cout << "Программа конвертирует сумму из новой Британской денежной системы в старую Британскую денежную систему." << endl << endl;
    cout << "Введите количество фунтов: ";
    cin >> funt;

    int int_funt = funt;
    old.shillings = (funt - int_funt) * 20.;
    int int_old_shill = old.shillings;
    old.pence = (old.shillings - int_old_shill) * 12.;

    cout << "В старой Британской денежной системе: ";
    cout << int_funt << '.' << int_old_shill << '.' << (int)old.pence;
}

void number11()
{
    struct time
    {
        int hour;
        int minutes;
        int seconds;
    };
    time t1, t2, t_finale;
    char slash;
    cout << "Введите время1 (например 12:36:56): ";
    cin >> t1.hour >> slash >> t1.minutes >> slash >> t1.seconds;

    cout << "Введите время2 (например 12:36:56): ";
    cin >> t2.hour >> slash >> t2.minutes >> slash >> t2.seconds;

    long totalsecs1 = t1.hour * 3600 + t1.minutes * 60 + t1.seconds;
    long totalsecs2 = t2.hour * 3600 + t2.minutes * 60 + t2.seconds;
    long totalsecs_finale = totalsecs1 + totalsecs2;
    t_finale.seconds = totalsecs_finale % 60;
    totalsecs_finale /= 60;
    t_finale.minutes = totalsecs_finale % 60;
    t_finale.hour = totalsecs_finale / 60;
    cout << "Сумма времени: " << t_finale.hour << slash << t_finale.minutes << slash << t_finale.seconds;
}

void number12()
{
    struct fraction
    {
        int chisl;
        int znam;
    };

    fraction d1, d2, d_totale;

    cout << "Программа выполняет четыре арифемтических действия над дробями\n(Пример: 12/2 + 12/2)" << endl << endl;
    char slash, deistvie, next_or_stop = 'y';

    while (next_or_stop == 'y') {

        cout << "Введите выражение: ";
        cin >> d1.chisl >> slash >> d1.znam >> deistvie >> d2.chisl >> slash >> d2.znam;

        switch (deistvie)

        {
        case '+':  d_totale.chisl = (d1.chisl * d2.znam + d1.znam * d2.chisl); d_totale.znam = (d1.znam * d2.znam);
            break;
        case '-':  d_totale.chisl = (d1.chisl * d2.znam - d1.znam * d2.chisl); d_totale.znam = (d1.znam * d2.znam);
            break;
        case '*':  d_totale.chisl = (d1.chisl * d2.chisl); d_totale.znam = (d1.znam * d2.znam);
            break;
        case '/':  d_totale.chisl = (d1.chisl * d2.znam); d_totale.znam = (d1.znam * d2.chisl);
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