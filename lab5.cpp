#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctype.h>
#include <cmath>

using namespace std;


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
class Date_custom
{
public:
    int month;
    int day;
    int year;

    void get_date()
    {
        cout << "Введите дату (пример: 01/01/2021): ";
        char slash;
        cin >> month >> slash >> day >> slash >> year;
    }

    void show_date()
    {
        cout << "Дата: " << month << '/' << day << '/' << year;
    }
};
enum etype { laborer, secretary, manager, accountant, executive, researcher };

class Employee
{
private:
    Date_custom date1;
    etype dolzh;
    int number;
    float sallary;
    bool true_indicate = 1;
public:

    void getemploy() {
        char ch1;
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите зарплату сотрудника: ";
        cin >> sallary;
        date1.get_date();
        cout << "Введите первую букву должности: ";
        cin >> ch1;
        cout << endl;
        switch (ch1) {
        case 'l': {
            dolzh = laborer;
            break;
        }
        case 's': {
            dolzh = secretary;
            break;
        }
        case 'm': {
            dolzh = manager;
            break;
        }
        case 'a': {
            dolzh = accountant;
            break;
        }
        case 'e': {
            dolzh = executive;
            break;
        }
        case 'r': {
            dolzh = researcher;
            break;
        }
        default: {
            cout << "Такой должности нет" << endl;
            true_indicate = 0;
            break;
        }
        }
    }
    void putemploy() {
        cout << "Номер сотрудника: " << number << endl;
        cout << "Зарплата сотрудника " << sallary << endl;
        date1.show_date();
        cout << endl;
        if (true_indicate != 0) {
            switch (dolzh) {
            case laborer: {
                cout << "Полное название должности: laborer" << endl;
                break;
            }
            case secretary: {
                cout << "Полное название должности: secretary" << endl;
                break;
            }
            case manager: {
                cout << "Полное название должности: manager" << endl;
                break;
            }
            case accountant: {
                cout << "Полное название должности: accountant" << endl;
                break;
            }
            case executive: {
                cout << "Полное название должности: executive" << endl;
                break;
            }
            case researcher: {
                cout << "Полное название должности: researcher" << endl;
                break;
            }
            
            }
        }
        cout << endl;

    }
};

void number4()
{
    Employee worker1, worker2, worker3;
    worker1.getemploy();
    worker2.getemploy();
    worker3.getemploy();

    worker1.putemploy();
    worker2.putemploy();
    worker3.putemploy();
}




void number5()
{
    Date_custom today;
    today.get_date();
    today.show_date();

}



void number6()
{

    Employee n1, n2, n3;
    n1.getemploy();
    n2.getemploy();
    n3.getemploy();
    n1.putemploy();
    n2.putemploy();
    n3.putemploy();

}

class angle {
private:
    int deg;
    float min;
    char napr;
public:
    angle(int grad, float minuti, char naprav) : deg(grad), min(minuti), napr(naprav) {}
    void vvod() {
        cout << "Введите градусы: ";
        cin >> deg;
        cout << "Введите минуты: ";
        cin >> min;
        cout << "Введите направление: ";
        cin >> napr;
        if (min > 60) {
            deg = deg + (min / 60);
            while (min > 60) {
                min = min - 60;
            }
        }
    }
    void show() {
        cout << "Координаты: " << deg << "°" << min << "' " << napr << endl;
    }
};
void number7()
{
    angle n1(0, 0, 0);
    n1.vvod();
    n1.show();
    char ch2;
    angle n2(5, 23, 's');
    n2.show();
    do {
        cout << "Ввести новые координаты?(n - для выхода)" << endl;
        cin >> ch2;
        if (ch2 != 'n') {
            n2.vvod();
            n2.show();
        }
    } while (ch2 != 'n');
}


class numbers {
private:
    int n;
    static int countall;
public:
    numbers() {
        countall++;
        n = countall;
    }
    void show() {
        cout << "Мой порядковый номер: " << n << endl;
    }
    void getnum() {
        cout << n;
    }
};
int numbers::countall = 0;
void number8()
{
    numbers n1, n2, n3;
    n1.show();
    n2.show();
    n3.show();
}


class fraction {
private:
    int ch;
    int zn;
    char dr;
public:
    void vvod_zn() {
        cout << "Введите знаменатель: ";
        cin >> zn;
    }
    void set_zn(int zn1) {
        zn = zn1;
    }
    int get_zn() {
        return zn;
    }
    void vvod_ch(int num) {
        ch = num;
    }
    void show() {
        cout << ch << "/" << zn;
    }
    void add() {
        cin >> ch >> dr >> zn;
    }
    void showresoper() {
        lowterms();
        cout << ch << "/" << zn;
    }
    void addfr(fraction dr1, fraction dr2) {
        ch = dr1.ch * dr2.zn + dr2.ch * dr1.zn;
        zn = dr1.zn * dr2.zn;
    }
    void fsub(fraction dr1, fraction dr2) {
        ch = dr1.ch * dr2.zn - dr2.ch * dr1.zn;
        zn = dr1.zn * dr2.zn;
    }
    void fmul(fraction dr1, fraction dr2) {
        ch = dr1.ch * dr2.ch;
        zn = dr1.zn * dr2.zn;
    }
    void fdiv(fraction dr1, fraction dr2) {
        ch = dr1.ch * dr2.zn;
        zn = dr1.zn * dr2.ch;
    }
    void lowterms() {
        long tnum, tden, temp, gcd;
        tnum = labs(ch); 
        tden = labs(zn);                  
        if (tden == 0) { 
            cout << "Недопустимый знаменатель";
            exit(1);
        }
        else if (tnum == 0) {
            ch = 0;
            zn = 1;
            return;
        }

        while (tnum != 0) {
            if (tnum < tden) { 
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        ch = ch / gcd;
        zn = zn / gcd;
    }
};
void number9()
{
    fraction dr1, dr2, sumdr;
    char continue_prog;
    while (true) {
        cout << "Введите первую дробь: ";
        dr1.add();
        cout << "Введите вторую дробь: ";
        dr2.add();
        sumdr.addfr(dr1, dr2);
        sumdr.showresoper();
        cout << endl;
        cout << "Продолжить? (y/n)";
        cin >> continue_prog;
        cout << endl;
        if (continue_prog == 'n') break;
    }
}
class ship {
private:
    numbers num;
    angle an1{ 0, 0, 's' };
    angle an2{ 0, 0, 's' };
public:
    void addshipinfo() {
        cout << "Корабль №";
        num.getnum();
        cout << "\n";
        an1.vvod();
        an2.vvod();
        cout << endl;
    }
    void showinfo() {
        cout << "Корабль №";
        num.getnum();
        cout << "\n";
        an1.show();
        an2.show();
        cout << endl;
    }
};
void number10()
{
    ship n1, n2, n3;
    n1.addshipinfo();
    n2.addshipinfo();
    n3.addshipinfo();
    n1.showinfo();
    n2.showinfo();
    n3.showinfo();
}

void number11()
{
    fraction dr1, dr2, sumdr;
    char oper, ch1;
    do {
        cout << "Введите выражение (например 23/3+12/2): ";
        dr1.add();
        cin >> oper;
        dr2.add();

        switch (oper) {
        case '+': {
            sumdr.addfr(dr1, dr2);
            sumdr.showresoper();
            break;
        }
        case '-': {
            sumdr.fsub(dr1, dr2);
            sumdr.showresoper();
            break;
        }
        case '*': {
            sumdr.fmul(dr1, dr2);
            sumdr.showresoper();
            break;
        }
        case '/': {
            sumdr.fdiv(dr1, dr2);
            sumdr.showresoper();
            break;
        }
        default: {
            cout << "Такой операции не существует";
            break;
        }
        }
        cout << "\nПродолжить? (y/n)" << endl;
        cin >> ch1;
        } while (ch1 != 'n');
}


void number12()
{
    fraction n1, n2, sumn;
    n1.vvod_zn();
    for (int i = 1; i < n1.get_zn(); i++) {
        n1.vvod_ch(i);
        cout << setw(12);
        n1.show();
    }
    cout << endl << endl;
    n2.set_zn(n1.get_zn());
    for (int j = 1; j < n1.get_zn(); j++) {
        n2.vvod_ch(j);
        n2.show();
        cout << setw(9);
        for (int k = 1; k < n1.get_zn(); k++) {
            n1.vvod_ch(k);
            sumn.fmul(n1, n2);
            sumn.showresoper();
            if (k != n1.get_zn() - 1) {
                if (sumn.get_zn() > 9) {
                    cout << setw(11);
                }
                else {
                    cout << setw(12);
                }
            }

        }
        cout << endl;
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