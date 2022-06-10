#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctype.h>
#include <cmath>
#include <sstream>
using namespace std;
void number1()
{
    unsigned long n; //number
    cout << "\nEnter a number: ";
    cin >> n; //get number
    for (int j = 1; j <= 200; j++) //loop from 1 to 200
    {
        cout << setw(5) << j * n << " "; //print multiple of n
        if (j % 10 == 0) //every 10 numbers,
            cout <<
            endl; //start new line
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
        total = total * 10 + ch - '0'; //add digit to total*10
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
class fraction {
public:
    int ch;
    int zn;
    char dr;
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
void number5()
{
    cout << "Сколько цифр вы хотите ввести? ";
    int len_mas;
    cin >> len_mas;
    fraction* mas = new fraction[len_mas];
    for (int i = 0; i < len_mas; i++)
    {
        mas[i].add();
    }
    double summa = 0;
    for (int i = 0; i < len_mas; i++)
    {
        summa += double(mas[i].ch) / double(mas[i].zn);
    }
    cout << "Ср. знач: " << summa / len_mas;
}
// cardaray.cpp
// класс игральных карт
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card
{
private:
    int number;
    Suit suit;
public:
    card() // конструктор
    { }
    void set(int n, Suit s) // установка значения
    {
        suit = s; number = n;
    }
    void display(); // показ карты
};
/////////////////////////////////////////////////////////////
void card::display()
{
    if (number >= 2 && number <= 10)
        cout << number;
    else
    {
        switch (number)
        {
        case jack: cout << 'J'; break;
        case queen: cout << 'Q'; break;
        case king: cout << 'K'; break;
        case ace: cout << 'A'; break;
        }
    }
    switch (suit)
    {
    case clubs: cout << static_cast<char>(5); break;
    case diamonds: cout << static_cast<char>(4); break;
    case hearts: cout << static_cast<char>(3); break;
    case spades: cout << static_cast<char>(6); break;
    }
}
/////////////////////////////////////////////////////////////
void number6()
{
    card deck[52];
    int j;
    cout << endl;
    for (j = 0; j < 52; j++) // создаем упорядоченную колоду карт
    {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    // показываем исходную колоду
    cout << "Исходная колода:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            cout << endl;
    }
    srand(time(NULL)); // инициализируем генератор случайных чисел
    for (j = 0; j < 52; j++)
    {
        int k = rand() % 52; // выбираем случайную карту
        card temp = deck[j]; // и меняем ее с текущей
        deck[j] = deck[k];
        deck[k] = temp;
    }
    // показываем перемешанную колоду
    cout << "\nПеремешанная колода:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            cout << endl;
    }
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
class Money {
public:
    long double mstold(string original_string)
    {
        string new_string = "";
        for (int i = 0; i < original_string.length(); i++)
        {
            if ((original_string[i] == '0') or (original_string[i] == '1') or
                (original_string[i] == '2') or (original_string[i] == '3') or (original_string[i] == '4') or
                (original_string[i] == '5') or (original_string[i] == '6') or (original_string[i] == '7') or
                (original_string[i] == '8') or (original_string[i] == '9') or (original_string[i] == '.'))
            {
                new_string += original_string[i];
            }
        }
        long double d = atof(new_string.c_str());
        return d;
    }
    string ldtoms(long double money_value)
    {
        if (money_value > 9999999999999990)
        {
            cout << "Введённое числе слишком большое!";
            exit(0);
        }
        stringstream myString;
        string money_str;
        myString << setprecision(2) << fixed << money_value;
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
};
void number7()
{
    Money american_value;
    cout << "Введите строку:";
    string original_string;
    cin >> original_string;
    cout << american_value.mstold(original_string);
}
class SafeArray
{
public:
    int LIMIT[10];
    void putel(int index_mas, int value_mas)
    {
        if ((index_mas >= 10) or (index_mas < 0))
        {
            cout << "Выход за границу масива";
            exit(0);
        }
        LIMIT[index_mas] = value_mas;
    }
    int getel(int index_mas)
    {
        if ((index_mas >= 10) or (index_mas < 0))
        {
            cout << "Выход за границу масива!!!\n";
            exit(0);
        }
        return LIMIT[index_mas];
    }
};
void number8()
{
    SafeArray mas;
    mas.putel(9, 15);
    cout << mas.getel(9);
}
class Stack
{
private:
    enum { MAX = 10 }; // немного нестандартный синтаксис
    int st[MAX]; // стек в виде массива
    int head; // начало очереди
    int tail; // конец очереди
public:
    Stack() // конструктор
    {
        head = 0;
        tail = -1;
    }
    void put(int var) // поместить в очередь
    {
        if (tail == MAX - 1)
            tail = -1;
        st[++tail] = var;
    }
    int get() // взять из очереди
    {
        if (head == MAX - 1)
            head = -1;
        return st[head++];
    }
};
void number9()
{
    Stack s1;
    s1.put(11);
    s1.put(22);
    cout << "1: " << s1.get() << endl;
    cout << "2: " << s1.get() << endl;
    s1.put(33);
    s1.put(44);
    s1.put(55);
    s1.put(66);
    cout << "3: " << s1.get() << endl;
    cout << "4: " << s1.get() << endl;
    cout << "5: " << s1.get() << endl;
    cout << "6: " << s1.get() << endl;
}
class Matrix
{
public:
    int x_edge;
    int y_edge;
    Matrix(int size_matrix_x, int size_matrix_y)
    {
        x_edge = size_matrix_x;
        y_edge = size_matrix_y;
    }
    int mas[10][10];
    void putel(int x, int y, int temp)
    {
        if (((x >= 0) and (x <= x_edge)) and ((y >= 0) and (y <= y_edge)))
            mas[x][y] = temp;
        else cout << "Элемент за границей массива!";
    }
    int getel(int x, int y)
    {
        if (((x >= 0) and (x < x_edge)) and ((y >= 0) and (y < y_edge)))
            return mas[x][y];
    }
};
void number10()
{
    Matrix m1(3, 4); // описываем матрицу
    int temp = 12345; // описываем целое
    m1.putel(7, 4, temp); // помещаем значение temp в матрицу
    temp = m1.getel(7, 4); // получаем значение из матрицы
}
void number11()
{
    cout << "Введите число: ";
    long double user_value;
    cin >> user_value;
    cout << "\n Строка: ";
    Money m1;
    cout << m1.ldtoms(user_value);
}
class bMoney
{
    Money m1;
    long double value;
    string string_value;
    
public:
    void getdata() 
    {
        cout << "Введите кол-во денег (Например: $100): ";
        cin >> string_value;
        value = m1.mstold(string_value);
    }

    void print_data()
    {
        cout << string_value;
    }
    void madd(bMoney s1, bMoney s2)
    {
        value = (s1.value + s2.value);
        string_value = m1.ldtoms(s1.value + s2.value);
    }
};
void number12()
{
   
    bMoney m1,m2,m3;
    m1.getdata();
    m2.getdata();
    m3.madd(m1, m2);
    m3.print_data();
}
int main()
{
    setlocale(LC_ALL, "rus");
    int x, number_max = 12, number_work = 2;
    for (int i = 0; 1; i) {
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
            for (int j = 0; 1; j) {
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
                cout << "\n\nДля того чтобы перейти к следющему номеру нажмите стрелку вверхна клавиатуре, для того \nчтобы вернуться к предыдущему - стрелку вниз, что бы запустить номер ещё раз - пробел." << endl;
                    cout << "Что бы вернуться к выбору номера нажмите любую другую кнопку.";
                int key = _getch();
                if (((key == 119) or (key == 230) or (key == 87) or (key == 150)) and (x <
                    number_max)) x++;
                else if (((key == 115) or (key == 235)) and (x > 1)) x--;
                else if ((key == 114) or (key == 170)) x;
                else break;
            }
        }
    }
}