// Директивы препроцессора
#include <iostream>
#include <cmath>
#include <string>

// Задал поле именования
using namespace std;

/*
Реализовать класс для работы с датой и временем. Два конструктора. Первый
принимает в качестве аргументов год, месяц, день, час, минуту и секунду. Час,
минута и секунда могут быть инициализированы по умолчанию. Второй
конструктор принимает строку в формате ISO [1] «YYYYMMDDThhmmss».
Класс должен реализовывать следующую функциональность: вывод года,
месяца, даты, часа, минуты, секунды, даты в формате «YYYYMMDD», времени
в формате «hhmmss», даты и времени в формате «YYYYMMDDThhmmss»,
operator>(), operator<(), operator+(), operator-(), operator==().

YYYYMMDDThhmmss	20050809T183142
YYYYMMDD	20050809
hhmmss	183142
*/

// Создал класс и описал два конструктора
class setDate {    
    private:
        int year, month, day, hour, minute, second;

        // Понял, что тип данных int "съедает" 0, если число начинается с 0, например 07.
        // Добавил функцию, которая добавляет первый 0 и преобразовывает значение в строку
        string addFirst0(int num) {
            if (num < 10) {
                return "0" + to_string(num);
            } else {
                return to_string(num);
            }
        };
        // Добавил функцию, которая конвертирует значения в секунды и сразу прибавляет какое-то колиичество секунд,
        // затем из суммы выражает количество часов, минут и остаток секунд (для реализации оператора operator+())
        void convertToSeconds(int seconds) {
            int sum = (hour * 3600) + (minute * 60) + second;
            sum += seconds;

            hour = sum / 3600;
            minute = (sum % 3600) / 60;
            second = sum % 60;
        };
    
    public:
        // конструктор 1
        setDate(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) {
            this->year = year;
            this->month = month;
            this->day = day;
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        
        // конструктор 2
        setDate(const std::string& YYYYMMDDThhmmss) {
            string YYYY = YYYYMMDDThhmmss.substr(0, 4);
            string MM = YYYYMMDDThhmmss.substr(4, 2);
            string DD = YYYYMMDDThhmmss.substr(6, 2);
            string hh = YYYYMMDDThhmmss.substr(9, 2);
            string mm = YYYYMMDDThhmmss.substr(11, 2);
            string ss = YYYYMMDDThhmmss.substr(13, 2);

            // После получения нужных значений из строки, воспользовался методом для приведения к целочисленному типу данных int
            this->year = stoi(YYYY);
            this->month = stoi(MM);
            this->day = stoi(DD);
            this->hour = stoi(hh);
            this->minute = stoi(mm);
            this->second = stoi(ss);
        }

        // Описал методы для вывода значений даты и времени
        int getYear() {
            return year;
        }

        string getMonth() {
            return addFirst0(month);
        }

        string getDay() {
            return addFirst0(day);
        }

        string getHour() {
            return addFirst0(hour);
        }

        string getMinute() {
            return addFirst0(minute);
        }

        string getSecond() {
            return addFirst0(second);
        }

        string getDate() {
            return to_string(year) + getMonth() + getDay();
        }

        string getTime() {
            return getHour() + getMinute() + getSecond();
        }

        string getIsoDate() {
           return getDate() + "T" + getTime();
        }

        // Реализация операторов сравнения, равенства, сложения и вычитания
        // operator>()
        bool operator>(const setDate& anotherDate) const {
        if (year > anotherDate.year)
            return true;
        else if (year < anotherDate.year)
            return false;

        if (month > anotherDate.month)
            return true;
        else if (month < anotherDate.month)
            return false;

        if (day > anotherDate.day)
            return true;
        else if (day < anotherDate.day)
            return false;

        if (hour > anotherDate.hour)
            return true;
        else if (hour < anotherDate.hour)
            return false;

        if (minute > anotherDate.minute)
            return true;
        else if (minute < anotherDate.minute)
            return false;

        return second > anotherDate.second;
    }
    // operator<()
    bool operator<(const setDate& anotherDate) const {
        return anotherDate > *this;
    }
    // operator==()
    bool operator==(const setDate& anotherDate) const {
        return year == anotherDate.year && month == anotherDate.month && day == anotherDate.day &&
            hour == anotherDate.hour && minute == anotherDate.minute && second == anotherDate.second;
    }
    // operator+()
    // Вот тут я понял, что потребуется преобразовать дату в секунды и дописал еще одну функцию наверху
    setDate operator+(int seconds) const {
        setDate result(*this);
        result.convertToSeconds(seconds);
        return result;
    }

    // operator-()
    setDate operator-(int seconds) const {
        return *this + (-seconds);
    }
};



// Вызов
int main() {
    setlocale(LC_ALL, "RUS");

    // Переменные для хранения данных от пользователя
    int someYear, someMonth, someDay, someHours, someMinutes, someSeconds, somePlusSeconds, someMinusSeconds;
    string someIsoDate;

    // Запросы и запись данных из консоли
    cout << "Давайте введем произвольную дату.\n\n" << "Начнём с года: ";
    cin >> someYear;

    cout << "Затем месяц: ";
    cin >> someMonth;

    cout << "Теперь день: ";
    cin >> someDay;

    cout << "А еще часы: ";
    cin >> someHours;

    cout << "Разумеется минуты: ";
    cin >> someMinutes;

    cout << "Ну и наконец - секунды, столько, сколько вам нравится: ";
    cin >> someSeconds;

    cout << "А теперь усложним.\nВведите дату в ISO формате (YYYYMMDDThhmmss, например 20050809T183142): ";
    cin >> someIsoDate;

    // Создание классов dateNumber и dateString и вызов методов с данными пользователя
    setDate dateNumber(someYear, someMonth, someDay, someHours, someMinutes, someSeconds);
    setDate dateString(someIsoDate);

    cout << "\nДавайте посмотрим, что получилось: " << endl;
    cout << "\nДата заданная вами в числовом формате " << endl;
    cout << "Год: " << dateNumber.getYear() << endl;
    cout << "Месяц: " << dateNumber.getMonth() << endl;
    cout << "День: " << dateNumber.getDay() << endl;
    cout << "Часы: " << dateNumber.getHour() << endl;
    cout << "Минуты: " << dateNumber.getMinute() << endl;
    cout << "Секунды: " << dateNumber.getSecond() << endl;

    cout << "\nДата заданная вами в ISO формате " << endl;
    cout << "Дата ISO: " << dateString.getDate() << endl;
    cout << "Время ISO: " << dateString.getTime() << endl;
    cout << "Дата и время ISO: " << dateString.getIsoDate() << endl;

    // Чтобы упростить восприятие пользователем, я добавил слов "Верно" и "Не верно", вместо 0 и 1
    cout << "\nПервая дата больше второй? " << ((dateNumber > dateString) ? "Верно" : "Не верно") << endl;
    cout << "Первая дата меньше второй? " << ((dateNumber < dateString) ? "Верно" : "Не верно") << endl;
    cout << "Первая дата равняется второй? " << ((dateNumber == dateString) ? "Верно" : "Не верно") << endl;

    // Еще запрос и запись
    cout << "\nТеперь давайте прибавим к первой дате сколько-то секунд: ";
    cin >> somePlusSeconds;

    // Результат сложения в консоль
    setDate addSomeSeconds = dateNumber + somePlusSeconds;
    cout << "\nМы прибавили " << somePlusSeconds << " секунд и получилось " << addSomeSeconds.getIsoDate() << endl;

    // Еще запрос и запись
    cout << "\n\nТеперь давайте вычтем из первой даты сколько-то секунд: ";
    cin >> someMinusSeconds;

    // Результат вычитания в консоль
    setDate reduceSomeSeconds = dateNumber - someMinusSeconds;
    cout << "\nМы вычли " << someMinusSeconds << " секунд и получилось " << reduceSomeSeconds.getIsoDate() << endl;

    return 0;
}