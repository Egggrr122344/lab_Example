

#include <iostream>
#include <memory>

template<typename T>
class Vector {
public:
    Vector();

    Vector(const size_t, const T & = T()); // конструктор, создающий вектор заданного размера и заполняющий его элементами типа T,
    // по умолчанию инициализированными значениями

    Vector(const Vector<T> &); // конструктор копирования

    Vector(const std::initializer_list<T> &); // конструктор, принимающий список инициализации элементов типа T

    Vector<T>(Vector<T> &&oth) noexcept; // конструктор перемещения

    Vector<T> &operator=(const Vector<T> &); // оператор присваивания
    T &operator[](const size_t) const; // оператор доступа к элементу массива по индексу

    void reserve(const size_t); // выделяет память под кол-во элементов

    void resize(const size_t, const T & = T()); // изменяет размер массива на нужное кол-во элементов

    void push_back(const T &); // в конец

    template<typename... Args>
    void emplace_back(const Args &...); // добавляет элемент в конец с использованием конструктура а не копирования

    void pop_back(); // берет с конца

    T &at(const size_t) const; // возвращает ссылку на нужный элемент вектора с проверкой границ

    T &front() const; // ссылка на первый элемент вектора

    T &back() const; // ссылка на последний элемент

    bool empty() const;

    size_t size() const;

    void setSize(int);

    size_t capacity() const; // возвращает емкость

    void shrink_to_fit(); // уменьшает емкость до его размера

    void clear(); // очищает

    T getLastElement() const; 

    bool operator==(const Vector<T> &) const;

    bool operator!=(const Vector<T> &) const;

    ~Vector(); // удаление

private:
    size_t arraySize; // размер
    size_t arrayCapacity; // емкость
    T *Array; // указатель на массив элементов 
};

