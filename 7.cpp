#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctype.h>
#include <cmath>
#include <sstream>
#include <string> 
#include <process.h>

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

int maxint(int* array, int len_mas)
{
    int max_array = array[0];
    int max_element_index = 0;
    for (int i = 0; i < len_mas; i++)
    {
        if (array[i] > max_array)
        {
            max_array = array[i];
            max_element_index = i;
        }
    }
    return max_element_index;
}

void number4()
{
    cout << "Сколько цифр вы хотите ввести? ";
    int len_mas;
    cin >> len_mas;
    int* mas = new int[len_mas];
    for (int i = 0; i < len_mas; i++)
    {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
    cout << maxint(mas, len_mas);
}


class Time
{
private:
    int hrs, mins, secs;
public:
    Time() : hrs(0), mins(0), secs(0) //no-arg constructor          
    {  }

    Time(int h, int m, int s) : hrs(h), mins(m), secs(s) //3-arg constructor   
    {
        mins += secs / 60;
        secs = secs % 60;
        hrs += mins / 60;
        mins = mins % 60;
    }

    void display()                    //format 11:59:59          
    {
        cout << hrs << ":" << mins << ":" << secs << endl;
    }
    Time operator + (Time t2)         //add two times 
    {
        int s = secs + t2.secs;        //add seconds          
        int m = mins + t2.mins;       //add minutes          
        int h = hrs + t2.hrs;        //add hours    

        m += s / 60;
        s = s % 60;
        h += m / 60;
        m = m % 60;

        return Time(h, m, s);          //return temp value 
    }

    Time operator - (Time t2)         //add two times 
    {
        int s = secs - t2.secs;        //add seconds          
        int m = mins - t2.mins;       //add minutes          
        int h = hrs - t2.hrs;          //add hours          
        if (t2.secs > secs)
        {
            s += 60;
            m--;
        }
        if (t2.mins > mins)
        {
            m += 60;
            h--;
        }

        return Time(h, m, s);          //return temp value 
    }

    Time operator * (float t2)         //add two times 
    {
        int s = secs * t2;        //add seconds          
        int m = mins * t2;       //add minutes          
        int h = hrs * t2;
        if (s > 59) {
            m += s / 60;
            s = s % 60;
        }
        if (m > 59) {
            h += m / 60;
            m = m % 60;
        }

        return Time(h, m, s);          //return temp value 
    }

    Time operator ++ (int)
    {
        int s = secs;
        int m = mins;
        int h = hrs;

        if (s == 59)
        {
            secs =  0;
            ++mins;
            if (mins == 60) 
            {
                mins = 0;
                ++hrs;
                return Time(h, m, s);
            }
            return Time(h, m, s);
        }
        else
        {
            ++secs;
            return Time(h, m, s);
        }
    }

    Time operator ++ ()
    {
        if (secs == 59)
        {
            secs = 0;
            ++mins;
            if (mins == 60)
            {
                ++hrs;
                mins = 0;
            }
            return Time(hrs, mins, secs);
        }
        else return Time(hrs, mins, ++secs);
    }
};

void number5()
{
    Time time1(5, 40, 40);               //create and initialze    
    Time time2(4, 30, 30);               //   two times    
    Time time3;                          //create another time      
    time3 = time1 + time2;       //add two times    

    cout << "\ntime3 = ";
    time3.display(); //display result  

    cout << endl;
    (++time1).display();
    time1++.display();
    time1.display();
}


void number6()
{
    Time time1(1, 46, 0);
    Time time2(0, 16, 0);
    Time time3;
    time3 = time1 - time2;
    cout << "\ntime3 = ";
    time3.display(); //display result  

    time3 = time3 * 2;

    cout << "\ntime3 = ";
    time3.display(); //display result  
}

class fraction {
private:
    int ch;
    int zn;
    char dr;
public:
    fraction() : ch(0), dr('/'), zn(0) //no-arg constructor          
    {  }

    fraction(int ch, int dr, int zn) : ch(ch), dr('/'), zn(zn)
    {  }

    void add() {
        cout << "Введите дробь (например 1/2): ";
        cin >> ch >> dr >> zn;
    }
    void showresoper() {
        lowterms();
        if (zn == 1) cout << ch << endl;
        else cout << ch << "/" << zn << endl;
    }
    fraction operator + (fraction dr2) {
        long ch_f = ch * dr2.zn + dr2.ch * zn;
        long zn_f = zn * dr2.zn;
        return fraction(ch_f, dr, zn_f);
    }
    fraction operator - (fraction dr2) {
        long ch_f = ch * dr2.zn - dr2.ch * zn;
        long zn_f = zn * dr2.zn;
        return fraction(ch_f, dr, zn_f);
    }
    fraction operator * (fraction dr2) {
        long ch_f = ch * dr2.ch;
        long zn_f = zn * dr2.zn;
        return fraction(ch_f, dr, zn_f);
    }
    fraction operator / (fraction dr2) {
        long ch_f = ch * dr2.zn;
        long zn_f = zn * dr2.ch;
        return fraction(ch_f, dr, zn_f);
    }

    bool operator == (fraction dr2) {
        dr2.lowterms();
        lowterms();
        if ((ch == dr2.ch) and (zn == dr2.zn))
            return true;
        return false;
    }

    bool operator != (fraction dr2) {
        dr2.lowterms();
        lowterms();
        if ((ch == dr2.ch) and (zn == dr2.zn))
            return false;
        return true;
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

class sterling;
class Money {
private:
    long double d;
public:
    Money() : d(0) 
    {}
    Money(string original_string) 
    {
        mstold(original_string);
    }
    Money(long double d) : d(d)
    {}

    long double mstold(string original_string)
    {
        string new_string = "";
        for (int i = 0; i < original_string.length(); i++)
        {
            if ((original_string[i] == '0') or (original_string[i] == '1') or (original_string[i] == '2') or (original_string[i] == '3') or (original_string[i] == '4') or (original_string[i] == '5') or (original_string[i] == '6') or (original_string[i] == '7') or (original_string[i] == '8') or (original_string[i] == '9') or (original_string[i] == '.'))
            {
                new_string += original_string[i];
            }
        }
        d = stold(new_string);  // ХЕЛП!!!
        return d;
    }
    string ldtoms()
    {
        if (d > 9999999999999990)
        {
            cout << "Введённое число слишком большое!";
            exit(0);
        }
        stringstream myString;
        string money_str;
        myString << setprecision(2) << fixed << d;
        myString >> money_str;
        string temp_string = "", final_string = "$";
        int count = 0;
        for (int i = money_str.length() - 4; i >= 0; i--)
        {
            temp_string += money_str[i];
            count += 1;
            if ((count % 3 == 0) and (i != 0)) temp_string += ",";
        }
        for (int i = temp_string.length() - 1; i >= 0; i--)
        {
            final_string += temp_string[i];
        }
        final_string += money_str[(money_str.length() - 3)];
        final_string += money_str[(money_str.length() - 2)];
        final_string += money_str[(money_str.length() - 1)];

        return final_string;
    }

    void print_money()
    {
        cout << ldtoms();
    }
    void set_money()
    {
        cout << "Введите денежное значение (например $100): ";
        string money_str;
        cin >> money_str;
        d = mstold(money_str);
    }

    Money operator + (Money m2)
    {
        long double new_summ = d + m2.d;
        return Money(new_summ);
    }
    Money operator - (Money m2)
    {
        long double new_summ = d - m2.d;
        return Money(new_summ);
    }
    Money operator / (Money m2)
    {
        long double new_summ = d / m2.d;
        return Money(new_summ);
    }
    Money operator * (long double m2)
    {
        long double new_summ = d * m2;
        return Money(new_summ);
    }
    Money operator / (long double m2)
    {
        long double new_summ = d / m2;
        return Money(new_summ);
    }

    operator sterling();
};
void number7()
{
    fraction d1, d2, d3;
    d1.add();
    d2.add();
    cout << "d1 + d2 = ";
    d3 = d1 + d2;
    d3.showresoper();

    cout << "d1 - d2 = ";
    d3 = d1 - d2;
    d3.showresoper();

    cout << "d1 * d2 = ";
    d3 = d1 * d2;
    d3.showresoper();

    cout << "d1 / d2 = ";
    d3 = d1 / d2;
    d3.showresoper();

    cout << "d1 == d2 = ";
    bool jes = d1 == d2;
    cout << jes << endl;

    cout << "d1 != d2 = ";
    jes = d1 != d2;
    cout << jes << endl;



}



void number8()
{
    Money m1, m2, m3;
    while (true) 
    {
        m1.set_money();
        m2.set_money();

        cout << "m1 + m2 = ";
        m3 = m1 + m2;
        cout << m3.ldtoms()<<endl;

        cout << "m1 - m2 = ";
        m3 = m1 - m2;
        cout << m3.ldtoms() << endl;

        cout << "m1 / m2 = ";
        m3 = m1 / m2;
        cout << m3.ldtoms() << endl;

        long double long_q;
        cout << "Введите число типа long double: ";
        cin >> long_q;
        cout << "m1 * long_double = ";
        m3 = m1 * long_q;
        cout << m3.ldtoms() << endl;

        cout << "m1 / long_double = ";
        m3 = m1 / long_q;
        cout << m3.ldtoms() << endl;

        cout << "\nContinue? (y/n) ";
        char boolka;
        cin >> boolka;
        if (boolka == 'n') break;
    }
}

const int LIMIT = 100; // размер массива
class safearray
{
private:
    int arr[LIMIT];
    int down_edge;
    int up_edge;
public:


    safearray(int up_edge, int down_edge) : up_edge(up_edge), down_edge(down_edge)
    {  }
    int& operator[](int n)
    {
        if ((n - down_edge < 0) or (n - down_edge >= LIMIT))
        {
            cout << "\nОшибочный индекс!"; exit(1);
        }
        return arr[n - down_edge];
    }
};

void number9()
{

    cout << "Введите границы масива (максималный размер массива - 100). " << endl;
    int up_edge, down_edge;
    cout << "Введите верхнюю границу массива: ";
    cin >> up_edge;
    cout << "Введите нижнюю границу массива: ";
    cin >> down_edge;
    safearray sa1(up_edge, down_edge);

    cout << "\nЭлемент с каким индексом вы хотите ввести? ";
    int element_index, element;
    cin >> element_index;
    cout << "Введите элемент: ";
    cin >> element;
    sa1[element_index] = element;

    cout << "\nЭлемент с каким индексом вы хотите ввести? ";
    cin >> element_index;
    cout << "Введите элемент: ";
    cin >> element;
    sa1[element_index] = element;
}

class Polar
{
private:

public:
    long double angle, radius;
    Polar() : angle(0), radius(0) {}
    Polar(long double a, long double r) : angle(a), radius(r) {}

    long double x = radius * cos(angle);
    long double y = radius * sin(angle);

    Polar operator + (Polar v2)
    {
        long double x_new = x + v2.x;
        long double y_new = y + v2.y;
        long double new_radius = sqrt(pow(x_new, 2) + pow(y_new, 2));
        long double new_angle = acos(x_new / (sqrt(pow(x_new, 2) + pow(y_new, 2))));
        return Polar(new_angle, new_radius);
    }
};

void number10()
{
    Polar value1(1.1, 0.1);
    Polar value2(1.1, 0.4);
    Polar value3;

    value3 = value1 + value2;
    cout << value3.angle << " " << value3.radius;

}

class sterling
{
private:
    long double new_sterling = 0;
public:
    sterling() : new_sterling(0) 
    {}
    sterling(int pounds, int shillings, int pence)  
    {
        new_sterling = pounds + (shillings + pence * (1. / 12.)) * (1. / 20.);
    }
    sterling(long double new_sterling) : new_sterling(new_sterling) 
    {}

    long double old_to_new(int pounds, int shillings, int pence)
    {
        return pounds + (shillings + pence * (1. / 12.)) * (1. / 20.);
    }

    void get_old_sterling()
    {
        int pounds;
        int shillings;
        int pence;
        cout << "Введите кол-во стерлингов (пример: 1.1.1)" << endl;
        char slash;
        cin >> pounds >> slash >> shillings >> slash >> pence;
        new_sterling = old_to_new(pounds, shillings, pence);
    }

    void print_old_sterling()
    {
        int pounds = new_sterling / 1;
        int shillings = (new_sterling - (double)pounds) * 20.;
        int pence = (((new_sterling - (double)pounds) * 20) - (double)shillings) * 12;;

        cout << "Кол-во стерлингов: ";
        cout << pounds << '.' << shillings << '.' << pence << endl;
    }

    long double modern_money_value() const 
    {
        return new_sterling;
    }

    sterling operator + (sterling v2) // сложение двух денег)
    {
        return sterling(modern_money_value() + v2.modern_money_value());
    }

    sterling operator - (sterling v2) // сложение двух денег)
    {
        return sterling(modern_money_value() - v2.modern_money_value());
    }

    sterling operator * (double v2) // умножение денег на число
    {
        return sterling(modern_money_value() * v2);
    }

    sterling operator / (sterling v2)
    {
        return sterling(modern_money_value() / v2.modern_money_value());
    }

    sterling operator / (double v2) 
    {
        return sterling(modern_money_value() / v2);
    }

    operator double() // 
    {
        return modern_money_value();
    }

    operator Money()
    {
        Money money(50 * new_sterling);
        return money;
    }


};
Money::operator sterling()
{
    return sterling(d / 50.);
}

void number11()
{
    sterling value1(5, 2, 8);
    sterling value2(0, 0, 8);
    sterling value3;

    value3 = value1 + value2;
    value3.print_old_sterling();

    cout << endl << (double)value3;

}


void number12()
{
    sterling v1(100);
    Money v2;
    v2 = v1;
    v2.print_money();

    cout << endl<<endl;

    v1 = v2;
    v1.print_old_sterling();

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