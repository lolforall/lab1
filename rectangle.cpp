// Директивы препроцессора
#include <iostream>
#include <cmath>
#include <string>

// Задал поле именования
using namespace std;

/*
Реализовать класс для решения прямоугольника. При создании задаются
длина и ширина. Нужно возвращать периметр, площадь и длину диагонали.
*/

// Создал класс прямоугольника и задал методы для вычисления периметра, площади и длины диагонали
class Rectangle {
private:
    double width, length;

public:
    Rectangle(double a, double b) : length(a), width(b) {}

    double perimeter() {
        return (width + length) * 2;
    }

    double area() {
        return width * length;
    }

    double diagonal() {
        return sqrt((length * length) + (width * width));
    }
};

// Вызов
int main() {
    setlocale(LC_ALL, "RUS");
    
    // Переменные для хранения данных от пользователя
    double someLength, someWidth;

    // Запросы и запись данных из консоли
    cout << "Введите длину прямоугольника: ";
    cin >> someLength;

    cout << "Введите ширину прямоугольника: ";
    cin >> someWidth;

    // Создание класса some и вызов методов с данными пользователя
    Rectangle some(someLength, someWidth);

    cout << "Периметр вашего прямоугольника равен: " << some.perimeter() << endl;
    cout << "Площадь вашего прямоугольника равна: " << some.area() << endl;
    cout << "Длина диагонали вашего прямоугольника равна: " << some.diagonal() << endl;

    return 0;
}