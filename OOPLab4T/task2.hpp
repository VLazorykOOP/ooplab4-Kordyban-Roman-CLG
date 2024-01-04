//2.10
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class c_book
{
    friend class c_library;
private:
    string name,genre,author;
public:
    c_book() { name=genre=author=""; }
    c_book(string _name,string _genre,string _author)
    {
        name=_name; genre=_genre; author=_author;
    }
    void print() const
    {
        cout<<name<<"\t"<<genre<<"\t"<<author<<endl;
    }
};
class c_library
{
private:
    vector<int> codes;
    vector<c_book> books;
    int codeError=0;
public:
    c_library() {}
    c_library(vector<c_book> _books)
    {
        books.clear();
        codes.clear();
        for(c_book i:_books)
        {
            books.emplace_back();
            books[books.size()-1]={i.name,i.genre,i.author};
            int code;
            for(;check_code(code);code=rand()) {}
            codes.push_back(code);
        }
    }
    size_t size() const { return codes.size(); }
    bool check_code(int code)const
    {
        for(int i:codes) { if(i==code) { return 1; } }
        return 0;
    }
    void push_back(int code,c_book book)
    {
        if(check_code(code)) { cerr<<"Book with this code already exists"<<endl; codeError=2; }
        else
        {
            codes.push_back(code);
            books.push_back(book);
        }
    }
    void pop_back()
    {
        codes.pop_back();
        books.pop_back();
    }
    c_book operator[](int code)
    {
        for(int index=0; index<codes.size(); index++)
        {
            if(codes[index]==code) { return books[index]; }
        }
        cerr<<"Book with this code does not exist"<<endl;
        codeError=1;
        return books[0];
    }
    int getError()
    {
        int i=codeError;
        codeError=0;
        return i;
    }
};
void t2()
{
    c_book book1{"name1", "genre1", "author1"},book2{"name2", "genre2", "author2"},book3{"name3", "genre3", "author3"};
    vector<c_book> books{book1, book2, book3};
    c_library library;
    for(int i=0; i<books.size(); i++)
    {
        library.push_back(i*11,books[i]);
    }
    for(int i=0; i<books.size(); i++)
    {
        cout<<i*11<<'\t';
        library[i*11].print();
    }
}

/*
Побудувати асоційований клас збереженнядвох сутностей.
В завданні створити клас, який представляє собою асоціативний масив між двома сутностями.
Написати функцію створення набору асоціативних сутностей.
Перевантажити операцію індексації []–функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс, повертає асоціативну сутність, якщо відповідної сутності немає в встановлюєкод помилки у змінну CodeError, альтернативні звернення через перевантаження операції виклику функції();
Перевантажити дружні операції введення та виведення.
Задача 2.10. Інвентарний номер книги в бібліотеці та назва.
*/