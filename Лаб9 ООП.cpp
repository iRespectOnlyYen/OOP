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

void addarrays(float* adres1, float* adres2, float* adres3)
{
    for (int i = 0; i < 4; i++) 
    {
        *(adres3+i) = *(adres1 + i) + *(adres1 + i);
    }
}

void number5()
{
    float mas1[4] = { 2,3,4,5 };
    float mas2[4] = { 2,3,4,5 };
    float mas3[4];
    addarrays(&mas1[0], &mas2[0], &mas3[0]);
    for (int i = 0; i < 4; i++)
        cout <<"mas["<<i<<"] = "<< mas3[i] << endl;
    
}

int compstr(char * s1, char * s2) 
{
    for (int i = 0; i < 9; i++)
    {
        if (*(s1 + i) > *(s2 + i)) return 1;
        if (*(s1 + i) < *(s2 + i)) return -1;
    }
}

void number6()
{
    char s1[9] = "Афанасия";
    char s2[10] = "Анастасия";
    cout << compstr(&s1[0], &s2[0]);
}

class person //class of persons

{
protected:
    string name; //person's name
    float salary;
public:
    void setData() //set the name
    {
        cout << "Enter name: "; cin >> name;
        cout << "Enter salary: "; cin >> salary;
    }
    void printData() //display the name
    {
        cout << endl << "Name: "<< name;
        cout << endl << "Salary: " << salary;
    }
    string getName() //return the name
    {
        return name;
    }
    float getSalary() 
    {
        return salary;
    }
};

////////////////////////////////////////////////////////////////

void number7()
{
    void bsort(person**, int); //prototype
    void salsort(person**, int); //prototype
    person* persPtr[100]; //array of pointers to persons
    int n = 0; //number of persons in array
    char choice; //input char

    do { //put persons in array
        persPtr[n] = new person; //make new object
        persPtr[n]->setData(); //set person's name
        n++; //count new person
        cout << "Enter another (y/n)? "; //enter another
        cin >> choice; // person?
    }
    while (choice == 'y'); //quit on 'n'

    cout << "\nUnsorted list:";
    for (int j = 0; j < n; j++) //print unsorted list
    {
        persPtr[j]->printData();
    }
    salsort(persPtr, n); //sort pointers
    cout << "\n\nSorted list:";
    for (int j = 0; j < n; j++) //print sorted list
    {
        persPtr[j]->printData();
    }
    cout << endl;
}
//--------------------------------------------------------------

void salsort(person** pp, int n) //sort pointers to persons

{

    int j, k; //indexes to array
    for (j = 0; j < n - 1; j++) //outer loop
        for (k = j + 1; k < n; k++) //inner loop starts at outer
        {
            person** pp1 = pp + j;
            person** pp2 = pp + k; //order the pointer contents
            if ((*pp1)->getSalary() > (*pp2)->getSalary())
            {
                person* tempptr = *pp1; //swap the pointers
                *pp1 = *pp2;
                *pp2 = tempptr;
            }
        }
}

//--------------------------------------------------------------

void bsort(person** pp, int n) //sort pointers to persons

{
    void order(person**, person**); //prototype
    int j, k; //indexes to array
    for (j = 0; j < n - 1; j++) //outer loop
        for (k = j + 1; k < n; k++) //inner loop starts at outer
            order(pp + j, pp + k); //order the pointer contents
}

//--------------------------------------------------------------

void order(person** pp1, person** pp2) //orders two pointers

{ //if 1st larger than 2nd,
    if ((*pp1)->getName() > (*pp2)->getName())
    {
        person* tempptr = *pp1; //swap the pointers
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}



struct link //one element of list
{
    int data; //data item
    link* next; //pointer to next link
};

////////////////////////////////////////////////////////////////

class linklist //a list of links
{
private:
    link* first; //pointer to first link
public:
    linklist() //no-argument constructor
    {
        first = NULL;
    } //no first link

    void additem(int d) //add data item
    {
        link* newlink = new link; //make a new link
        newlink->data = d; //give it data
        if (first == NULL)
        {
            first = newlink;
        }
        else 
        {
            link* tmp = first;
            while (tmp->next) 
            {
                tmp = tmp->next;
            }
            tmp->next = newlink;
        }
        newlink -> next = NULL; //now first points to this
    }

    void display() //display all links

    {
        link* current = first; //set ptr to first link
        while (current != NULL) //quit on last link
        {
            cout << current->data << endl; //print data
            current = current->next; //move to next link
        }
    }
};

void number8()
{
    linklist li; //make linked list
    li.additem(25); //add four items to list
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display(); //display entire list
}


void number9()
{
    int a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10], a10[10];
    int* ap[10] = {a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
    
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            ap[i][j] = i * j;
        }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << ap[i][j] << " ";
        }
        cout << endl;
    }
}


void number10()
{
    int* ap[10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            *(ap + j) = new int[10];
        }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            ap[i][j] = i * j;
        }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << ap[i][j] << " ";
        }
        cout << endl;
    }
}

class mas
{
private:
    int* ap[10];
public:
    mas() 
    {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            *(ap + j) = new int[10];
        }
    }

    int& operator[] (int index)
    {
        int i = static_cast <int> (index / 10);
        int j = index % 10;
        return ap[i][j];
    }
};

void number11()
{
    mas arr;
    for (int i = 0; i < 100; i++) arr[i] = i;
    for (int i = 0; i < 100; i++) cout << arr[i] << ' ';
}


float fmemory[100];
int fmem_top = 0;

class Float
{
private:
    int addr;

public:
    Float(float f) 
    {
        fmemory[fmem_top] = f;
        addr = fmem_top++;
    }

    int operator&() {
        return addr;
    }
};

//==============================================================
int pmemory[100];
int pmem_top = 0;

class ptrFloat
{
private:
    int addr;
public:
    ptrFloat(int p) 
    {
        pmemory[pmem_top] = p;
        addr = pmem_top++;
    }
    float& operator*()
    {
        return fmemory[pmemory[addr]];
    }
};

//----------------------------------------------------------

void number12()
{
    Float var1 = 1.234;
    Float var2 = 5.678;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123;
    *ptr2 = 8.456;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
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