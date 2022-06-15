#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctype.h>
#include <cmath>
#include <sstream>
#include <string> 
#include <process.h>

using namespace std;


class publication
{
private:
    string title;
    int price;
public:
    void getdata()
    {
        cout << "\nВведите название книги: ";
        cin >> title;
        cout << "Введите цену книги: ";
        cin >> price;
    }
    void putdata()
    {
        cout << "\nНазвание книги: " << title << endl;
        cout << "Цена книги: " << price << endl;
    }
};

class sales
{
private:
    float sale_for_three_month[3];
public:
    void getdata()
    {
        cout << "Введите продажи за 3 месяца через пробел (например: 20 30 40): ";
        cin >> sale_for_three_month[0] >> sale_for_three_month[1] >> sale_for_three_month[2];
    }
    void putdata()
    {
        cout << "Продажи за 3 месяца: \n1:" << sale_for_three_month[0] << "\n2:" << sale_for_three_month[1] << "\n3:" << sale_for_three_month[2] << endl;
    }
};

class book : private publication, sales
{
private:
    int quantity;
public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout << "Введите количество страниц: ";
        cin >> quantity;
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout << "Количество страниц: " << quantity;
    }
};

class type : publication, sales
{
private:
    float lenght;
public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout << "Введите длину записи: ";
        cin >> lenght;
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout << "Длина записи: " << lenght;
    }
};



void number1()
{
    book book1; // определить публикации
    type type1;
    book1.getdata(); // получить данные о них
    type1.getdata();
    cout << endl;
    book1.putdata(); // вывести данные о них
    cout << endl;
    type1.putdata();
    cout << endl;
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
    book book1; // определить публикации
    type type1;
    book1.getdata(); // получить данные о них
    type1.getdata();
    cout << endl;
    book1.putdata(); // вывести данные о них
    cout << endl;
    type1.putdata();
    cout << endl;
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
        cout << "Дата: " << month << '/' << day << '/' << year << endl;
    }
};



class disk : private publication
{
private:
    enum type_disk { CD, DVD };
    type_disk diisk;
public:
    void getdata()
    {
        publication::getdata();
        cout << "Введите ""d"" если тип диска DVD или ""c"" если тип диска CD: ";
        char input_disk;
        cin >> input_disk;
        switch (input_disk) {
        case 'c': {
            diisk = CD;
            break;
        }
        case 'd': {
            diisk = DVD;
            break;
        }
        }
    }

    void putdata()
    {
        publication::putdata();
        switch (diisk) {
        case CD: {
            cout << "Тип диска: CD";
            break;
        }
        case DVD: {
            cout << "Тип диска: DVD";
            break;
        }
        }
    }
};

void number4()
{
    disk d1;
    d1.getdata();
    d1.putdata();
}

const int LEN = 80;
class employee // некий сотрудник
{
private:
    char name[LEN]; // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: "; cin >> number;
    }
    void putdata() const
    {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};

class employee2 : private employee
{
private:
    double compensation;
    enum period { почасовая, понедельная, помесячная };
    period p1;
public:
    void getdata()
    {
        employee::getdata();
        cout << "Введите h если оплата почасовая, w если оплата понедельная, m если оплата помесячная: ";

        char first_char;
        cin >> first_char;
        switch (first_char) {
        case 'h': {
            p1 = почасовая;
            break;
        }
        case 'w': {
            p1 = понедельная;
            break;
        }
        case 'm': {
            p1 = помесячная;
            break;
        }
        }

    }
    void putdata()
    {
        employee::putdata();
        switch (p1) {
        case почасовая: {
            cout << "\n Тип оплаты: почасовая";
            break;
        }
        case понедельная: {
            cout << "\n Тип оплаты: понедельная";
            break;
        }
        case помесячная: {
            cout << "\n Тип оплаты: помесячная";
            break;
        }
        }
    }
};

void number5()
{
    employee2 man;
    man.getdata();
    man.putdata();
}

const int LIMIT = 100;
class safearay {
private:
    int arr[LIMIT];
public:
    int& operator [](int n)  //note: return by reference  
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds"; exit(1);
        }
        return arr[n];
    }
};

class safearay2 : private safearay
{
private:
    int up_edge;
    int down_edge;
public:
    safearay2()
    {
        cout << "Введите верхнюю границу массива:";
        cin >> up_edge;
        cout << "Введите нижнюю границу массива:";
        cin >> down_edge;
    }

    int& operator [](int n)  //note: return by reference  
    {
        if ((up_edge - down_edge) >= 100)
        {
            cout << "Массив с предложенными границами больше допустимого размера. \nМаксимальный допустимый размер массива - 100.\n";
            exit(-1);
        };

        if (n > up_edge)
            return safearay::operator[] (LIMIT);
        else
            return safearay::operator[] (n - down_edge);
    }
};

void number6()
{
    safearay2 mas;

    cout << "Введите индекс элемента: ";
    int index_mas;
    cin >> index_mas;

    cout << "Введите значение элемента: ";
    int value_mas;
    cin >> value_mas;

    mas[index_mas] = value_mas;

}


class Money {
public:
    string original_string;
    long double d;

    Money() :original_string(""), d(0) {}
    Money(string original_string, long double d) : original_string(original_string), d(d) {}


    long double mstold()
    {
        cout << "Введите денежное значение (например $230.5): ";
        cin >> original_string;
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
    void ldtoms()
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

        cout << final_string << endl;
    }

    Money operator + (Money m2)
    {
        long double new_summ = d + m2.d;
        return Money(original_string, new_summ);
    }
    Money operator - (Money m2)
    {
        long double new_summ = d - m2.d;
        return Money(original_string, new_summ);
    }
    Money operator / (Money m2)
    {
        long double new_summ = d / m2.d;
        return Money(original_string, new_summ);
    }
    Money operator * (long double m2)
    {
        long double new_summ = d * m2;
        return Money(original_string, new_summ);
    }
    Money operator / (long double m2)
    {
        long double new_summ = d / m2;
        return Money(original_string, new_summ);
    }

};


class Counter {

protected:                            //NOTE: not private      
    unsigned int count;                //count    
public:
    Counter() : count(0)               //constructor, no args          
    {  }
    Counter(int c) : count(c)          //constructor, one arg 
    {  }
    unsigned int get_count() const     //return count  
    {
        return count;
    }
    Counter operator ++ ()             //incr count (prefix)  
    {
        return Counter(++count);
    }
    Counter operator ++ (int)             //incr count (prefix)  
    {
        return Counter(count++);
    }

};
//////////////////////////////////////////////////////////////// 
class CountDn : public Counter
{
public:
    CountDn() : Counter()              //constructor, no args          
    { }
    CountDn(int c) : Counter(c)        //constructor, 1 arg          
    { }
    CountDn operator -- ()             //decr count (prefix)  
    {
        return CountDn(--count);
    }
    CountDn operator -- (int)             //decr count (prefix)  
    {
        return CountDn(count--);
    }

};
void number7()
{
    CountDn c1;                           //class CountDn     
    CountDn c2(100);

    cout << "\nc1=" << c1.get_count();//display    
    cout << "\nc2=" << c2.get_count();//display  
    ++c1; c1++; c1++;                     //increment c1    
    cout << "\nc1=" << c1.get_count();    //display it  
    --c2; c2--;                           //decrement c2    
    cout << "\nc2=" << c2.get_count();    //display it  
    CountDn c3 = --c2;                    //create c3 from c2    
    cout << "\nc3=" << c3.get_count();    //display c3    
    cout << endl;
}


class NormString
{

private:
    string s;
    int n;
public:
    NormString(string s) : s(s) {}
    NormString() {}

    NormString operator = (string s2)
    {
        s = s2;
        return NormString(s);
    }


    string left(NormString s_tmp, int n)
    {
        string final_s, new_s;
        new_s = s_tmp.s;
        for (int i = 0; i < new_s.length(); i++)
        {
            if (i < n) final_s += new_s[i];
        }
        return final_s;
    }

    string right(NormString s_tmp, int n)
    {
        string final_s, new_s;
        new_s = s_tmp.s;
        for (int i = new_s.length() - n; i < new_s.length(); i++)
        {
            final_s += new_s[i];
        }
        return final_s;
    }

    string mid(NormString s_tmp, int number_first_sym, int n)
    {
        string final_s, new_s;
        new_s = s_tmp.s;
        number_first_sym--;
        for (int i = number_first_sym; i < number_first_sym + n; i++)
        {
            final_s += new_s[i];
        }
        return final_s;
    }

};

void number8()
{
    NormString s1, s2;
    s1 = "Абрикос";

    cout << "s2.left(s1, 2) = " << s2.left(s1, 2) << endl;
    cout << "s2.mid(s1, 2, 2) = " << s2.mid(s1, 3, 3) << endl;
    cout << "s2.right(s1, 2) = " << s2.right(s1, 2) << endl;
}

class publication2 : private publication, private Date_custom
{
public:
    void getdata()
    {
        publication::getdata();
        get_date();
    }

    void putdata()
    {
        publication::putdata();
        show_date();
    }

};

class book2 : private publication2, sales
{
private:
    int quantity;
public:
    void getdata()
    {
        publication2::getdata();
        sales::getdata();
        cout << "Введите количество страниц: ";
        cin >> quantity;
    }
    void putdata()
    {
        publication2::putdata();
        sales::putdata();
        cout << "Количество страниц: " << quantity;
    }
};

class type2 : publication2, sales
{
private:
    float lenght;
public:
    void getdata()
    {
        publication2::getdata();
        sales::getdata();
        cout << "Введите длину записи: ";
        cin >> lenght;
    }
    void putdata()
    {
        publication2::putdata();
        sales::putdata();
        cout << "Длина записи: " << lenght << endl;
    }
};



void number9()
{
    type2 audio1;
    audio1.getdata();
    audio1.putdata();

    book2 book1;
    book1.getdata();
    book1.putdata();

}



class student                 //educational background  

{
private:
    char school[LEN];       //name of school or university       
    char degree[LEN];       //highest degree earned    
public:
    void getedu()
    {
        cout << "   Enter name of school or university: ";
        cin >> school;
        cout << "   Enter highest degree earned \n";
        cout << "   (Highschool, Bachelor's, Master's, PhD): ";
        cin >> degree;
    }

    void putedu() const
    {
        cout << "\n   School or university: " << school;
        cout << "\n   Highest degree earned: " << degree;
    }
};

//////////////////////////////////////////////////////////////// 
class employee_10_number
{
private:
    char name[LEN];         //employee name       
    unsigned long number;   //employee number    
public:
    void getdata()
    {
        cout << "\n   Enter last name: ";
        cin >> name;
        cout << "   Enter number: ";
        cin >> number;
    }

    void putdata() const
    {
        cout << "\n   Name: " << name;
        cout << "\n   Number: " << number;
    }
};

//////////////////////////////////////////////////////////////// 
class manager : private employee_10_number, private student  //management  
{
private:
    char title[LEN];        //"vice-president" etc.  
    double dues;            //golf club dues   
public:
    void getdata()
    {
        employee_10_number::getdata();
        cout << "   Enter title: ";
        cin >> title;
        cout << "   Enter golf club dues: ";
        cin >> dues;
        student::getedu();
    }

    void putdata() const
    {
        employee_10_number::putdata();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues;
        student::putedu();

    }
};

class executive : private manager
{
private:
    int annual_bonus;
    int quantity_of_company_shares;
public:
    void getdata()
    {
        manager::getdata();
        cout << "   Enter annual bonus: ";
        cin >> annual_bonus;
        cout << "   Enter quantity_of_company_shares: ";
        cin >> quantity_of_company_shares;
    }

    void putdata() const
    {
        manager::putdata();
        cout << "\n   Annual bonus: " << annual_bonus;
        cout << "\n   Quantity of company shares: " << quantity_of_company_shares;
    }
};

void number10()
{
    executive pety2a;
    pety2a.getdata();
    pety2a.putdata();
}

class Stack
{
public:
    Stack(int alocated) : alocated(alocated) {} //конструктор размера стека
private:
    int top;
    int alocated;
    int* mas = new int[alocated];
public:

    void push(int value)
    {
        if (top == alocated)
        {
            cout << "\nstack overflow!" << endl;
        }
        else
        {
            mas[top++] = value;
        }
    }

    int pop()
    {
        if (top == 0)
        {
            cout << "\nstack void! ";
            return -1;
        }
        else
        {
            return mas[--top];
        }
    }
};
struct Custom_pair
{
    int x;
    int y;
};
class PairStack : private Stack
{
protected:
    Custom_pair para;
public:
    PairStack(int x) : Stack(2 * x) {}

    void push(Custom_pair para)
    {
        Stack::push(para.x);
        Stack::push(para.y);
    };

    void pop()
    {
        cout << "x = " << Stack::pop() << endl;
        cout << "y = " << Stack::pop() << endl << endl;
    };
};

void number11()
{
    Custom_pair para1{ 11, 11 }, para2{ 22,22 };
    PairStack s1(2);
    s1.push(para1);
    s1.push(para2);
    s1.pop();
    s1.pop();
}

class sterling
{
public:
    int pounds;
    int shillings;
    int pence;
    long double new_sterling = 0;

    sterling() : pounds(0), shillings(0), pence(0) {}
    sterling(int pounds, int shillings, int pence) : pounds(pounds), shillings(shillings), pence(pence) {}
    sterling(long double new_sterling) : new_sterling(new_sterling) {}

    void get_old_sterling()
    {
        cout << "Введите кол-во стерлингов: " << endl;
        char slash;
        cin >> pounds >> slash >> shillings >> slash >> pence;
    }

    void print_old_sterling()
    {
        cout << "Кол-во стерлингов: ";
        cout << pounds << '.' << shillings << '.' << pence;
    }

    long double old_to_new()
    {
        new_sterling = pounds + (shillings + pence * (1. / 12.)) * (1. / 20.);
        return new_sterling;
    }

    void new_to_old()
    {
        pounds = new_sterling / 1;
        shillings = (new_sterling - (double)pounds) * 20.;
        pence = (((new_sterling - (double)pounds) * 20) - (double)shillings) * 12;;
    }

    sterling operator + (sterling v2) // сложение двух денег)
    {
        long double a = old_to_new();
        long double b = v2.old_to_new();
        sterling summ_sterling(a + b);
        summ_sterling.new_to_old();
        return sterling(summ_sterling);
    }

    sterling operator - (sterling v2) // вычитание двух денег
    {
        long double a = old_to_new();
        long double b = v2.old_to_new();
        sterling summ_sterling(a - b);
        summ_sterling.new_to_old();
        return sterling(summ_sterling);
    }

    sterling operator * (double v2) // умножение денег на число
    {
        long double a = old_to_new();
        sterling summ_sterling(a * v2);
        summ_sterling.new_to_old();
        return sterling(summ_sterling);
    }

    sterling operator / (sterling v2) // вычитание двух денег
    {
        long double a = old_to_new();
        long double b = v2.old_to_new();
        sterling summ_sterling(a / b);
        summ_sterling.new_to_old();
        return sterling(summ_sterling);
    }

    sterling operator / (double v2) // вычитание двух денег
    {
        long double a = old_to_new();
        sterling summ_sterling(a / v2);
        summ_sterling.new_to_old();
        return sterling(summ_sterling);
    }

    operator double() const // 
    {
        return (pounds + shillings / 20.0 + pence / 240.0);
    }

    operator Money()
    {
        long double a = old_to_new();
        Money value_money;
        value_money.d = 50 * a;
        return value_money;
    }

};

class sterfrac : public sterling
{
private:
    int eighths;
    long double eighths_in_new_standart;
public:
    sterfrac() {}
    sterfrac(double other_funt)
    {
        pounds = other_funt;
        shillings = (other_funt - pounds) * 20;
        pence = ((other_funt - pounds) * 20 - shillings) * 12;
        eighths_in_new_standart = static_cast<int>(round((((other_funt - pounds) * 20 - shillings) * 12 - pence) * 8));
    }
    void get_old_sterling()
    {
        char _;
        int quisquiliae;
        sterling::get_old_sterling();
        cin >> _ >> eighths >> _ >> quisquiliae;
        eighths_in_new_standart = (eighths / 8.) / 240.;

    }

    void print_old_sterling()
    {
        sterling::print_old_sterling();
        cout << "-" << eighths_in_new_standart << "/8";
    }

    operator double() const
    {
        return (sterling::operator double() + eighths_in_new_standart);
    }

    sterfrac operator+(sterfrac value2)
    {
        return sterfrac((double)*this + (double)value2);
    }

    sterfrac operator-(sterfrac value2)
    {
        return sterfrac((double)*this - (double)value2);
    }

    sterfrac operator*(double value2)
    {
        return sterfrac((double)*this * value2);
    }

    double operator/(sterfrac value2)
    {
        return sterfrac((double)*this / (double)value2);
    }

    sterfrac operator/(double value2)
    {
        return sterfrac((double)*this / value2);
    }
};

void number12()
{
    sterfrac value3, value1, value2;
    double a = 2;

    value1.get_old_sterling();
    value2.get_old_sterling();

    cout << endl;

    value3 = value1 - value2;
    value3.print_old_sterling();
    cout <<"   (Вычитание)\n";

    value3 = value1 + value2;
    value3.print_old_sterling();
    cout << "   (Сложение)\n";
    
    value3 = value1 * a;
    value3.print_old_sterling();
    cout << "   (Умножение на "<<a<<")\n";
    
    value3 = value1 / value2;
    value3.print_old_sterling();
    cout << "   (Деление)\n";

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