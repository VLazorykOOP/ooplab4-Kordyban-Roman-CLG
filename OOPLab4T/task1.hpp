//1.5
#include<iostream>
using namespace std;
//----------------------------------------------------------------
template <typename T>
class myVector
{
protected:
    T *data;
    size_t data_size;
    short codeError; // 0=normal | 1=oob | 2=
    void builder(size_t _data_size,T _value)
    {
        codeError=0;
        data_size=_data_size;
        delete[] data;
        data=new T[data_size];
        for(int i=0; i<data_size; ++i) { data[i]=_value; }
    }
public:
    size_t size() const { return data_size; }
    myVector() { builder(1,0); }
    myVector(size_t _data_size) { builder(_data_size,0); }
    myVector(size_t _data_size,T _value) { builder(_data_size,_value); }
    myVector(const myVector &other)
    {
        builder(other.data_size,0);
        for(size_t i=0; i<data_size; ++i) { data[i]=other.data[i]; }
    }
    ~myVector() { delete[] data; }
    T &operator[](size_t index)
    {
        if(index>data_size) { codeError=1; index=0; }
        return data[index];
    }
    myVector &operator++()
    {
        for(size_t i=0; i<data_size; ++i) { ++data[i]; }
        return *this;
    }
    myVector operator++(int) const
    {
        myVector result(*this);
        ++result;
        return result;
    }
    myVector &operator--()
    {
        for(size_t i=0; i<data_size; ++i) { --data[i]; }
        return *this;
    }
    myVector operator--(int) const
    {
        myVector result(*this);
        --result;
        return result;
    }
    myVector &operator=(const myVector &other)
    {
        builder(other.data_size,0);
        for(size_t i=0; i<data_size; ++i) { data[i]=other.data[i]; }
        return *this;
    }
    myVector &operator+(const myVector &other) const
    {
        if(data_size!=other.data_size) { throw; }
        myVector result(*this);
        for(size_t i=0; i<data_size; ++i) { result.data[i]+=other.data[i]; }
        return result;
    }
    myVector &operator-(const myVector &other) const
    {
        if(data_size!=other.data_size) { throw; }
        myVector result(*this);
        for(size_t i=0; i<data_size; ++i) { result.data[i]-=other.data[i]; }
        return result;
    }
    myVector &operator*(const T _value) const
    {
        myVector result(*this);
        for(size_t i=0; i<data_size; ++i) { result.data[i]*=_value; }
        return result;
    }
    myVector &operator/(const T _value) const
    {
        myVector result(*this);
        for(size_t i=0; i<data_size; ++i) { result.data[i]/=_value; }
        return result;
    }
    myVector &operator%(const T _value) const
    {
        myVector result(*this);
        for(size_t i=0; i<data_size; ++i) { result.data[i]%=_value; }
        return result;
    }
    bool operator!() const { return bool(data_size); }
    void print() const { for(int i=0; i<data_size; i++) { cout<<data[i]<<'\t'; } cout<<endl; }
};
//----------------------------------------------------------------
void t1()
{
    myVector<long> a(5,11),b(a),d;
    b.print();
    d=b%5;
    d.print();
}
//----------------------------------------------------------------
/*
Створити тип даних - клас myVectorLong (вектор цілих чисел), який має вказівник на long, число елементів data_size і змінну стану codeError. У класі визначити
~   o конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
~   o конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
~   o конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу) ;
~   o конструктор копіювання;
~   o деструктор звільняє пам'ять;
   o перевантаження операцій (операції перевантажувати через функції класу або дружні функції, якщо не вказано яким чином це робити):
~        унарних префіксних та постфіксних ++ та --: одночасно збільшує (зменшує) значення елементів масиву на 1;
~        унарної логічної ! (заперечення): повертає значення true, якщо елементи якщо data_size не дорівнює – нулю, інакше false;
        унарної побітової ~ (заперечення): повертає побітове заперечення для всіх елементів масиву класу вектор;
        унарний арифметичний - (мінус) : повертає всі елементи масиву класу вектор з протилежним знаком;
~        присвоєння =: копіює вектор(перевантажити через функцію класу);
        присвоєння з (перевантажити через функцію класу)
           o += - додаванням векторів;
           o -= - відніманням векторів;
           o *= - множення, вектора на число;
           o /= - ділення, вектора на число;
           o %= - остача від ділення, вектора на число;
           o |= - побітове додаванням векторів;
           o ^= - побітове додавання за модулем 2 векторів;
           o &= - побітове по-елементне множення векторів;
~        арифметичних бінарні:
~           o + - додавання векторів;
~           o – - віднімання векторів;
~           o * - множення, вектора на число;
~           o / - ділення, вектора на число типу;
~           o % - остача від ділення, вектора на число типу;
        побітові бінарні
           o | - побітове додавання векторів;
           o ^ - побітове додавання за модулем 2 векторів;
           o & - побітове по-елементне множення векторів;
        побітові операції зсувів, як дружні операції введення та виведення вектора у потік (перевантажувати через дружні функції)
           o введення >> (побітовий зсув право) ;
           o введення << (побітовий зсув ліво);
        рівності == та нерівності!= , функція-операція виконує певні дії над кожною парою елементів векторів за індексом;
        операцію індексації [] – функцію, яка звертається до елементу масиву за індексом, якщо індекс невірний функція вказує на останній елемент масиву та встановлює код помилки у змінну codeError;
        розподілу пам’яті new та delete;
        виклику функції ();
        порівняння (функція-операція виконує певні дії над кожною парою елементів векторів за індексом), які повертають true або false:
           o > (більше) для двох векторів;
           o >= (більше рівне) для двох векторів;
           o < (менше) для двох векторів;
           o <=(менше рівне) для двох векторів.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу. Перевірити роботу цього класу.
*/
