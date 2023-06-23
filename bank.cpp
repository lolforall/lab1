// Директивы препроцессора
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>

// Задал поле именования
using namespace std;


/*
Банковские операции. Клиент банка имеет имя, фамилию, дату рождения и
уникальный идентификатор. Банк хранит информацию о клиентах в списке.
Необходимо реализовать следующий функционал. Вкладные операции. Банк
предлагает определенный процент и срок размещения вклада. Реализовать
калькулятор вкладов: какой доход может получить клиент и когда. Кредитные
операции. Банк устанавливает определенный процент и срок. Реализовать
кредитный калькулятор: выводить график платежей, сумму процентов.
Выводить информацию о клиенте, его вкладах и кредитах. Для работы с датой и
временем использовать класс, реализованный в п.2
*/

// Создал класс клиент
class Client {    
    private:
        string firstName, lastName, bornDate;
        double salary;
        int clientID;
        bool haveCredit, haveDeposit;
    public:
        Client (string firstName, string lastName, string bornDate, double salary, int clientID, bool haveCredit = false, bool haveDeposit = false)
            : firstName(firstName), lastName(lastName), bornDate(bornDate), salary(salary), clientID(clientID), haveCredit(haveCredit), haveDeposit(haveDeposit)
        {}
    string clientInfo() {
        cout << "Имя клиента: " << firstName << endl;
        cout << "Фамилия клиента: " << lastName << endl;
        cout << "Дата рождения клиента: " << bornDate << endl;
        cout << "Доход клиента: " << salary << endl;
        cout << "Уникальный номер клиента: " << clientID << endl;
        if (haveCredit) {
            cout << "Клиент: " << clientID << " имеет действующий кредит." << endl;
        } else {
            cout << "Клиент: " << clientID << " не имеет действующих кредитов." << endl;
        }
        if (haveDeposit) {
            cout << "Клиент: " << clientID << " имеет действующий вклад." << endl;
        } else {
            cout << "Клиент: " << clientID << " не имеет действующих вкладов." << endl;
        }
    }
    // string showClientInfo() {
    //     clientInfo();
    // }
};




// Вызов
int main() {
    setlocale(LC_ALL, "RUS");
    // Переменные для хранения данных от оператора банка
    string someFirstName, someLastName, someBornDate, doesHaveCr, doesHaveDep;
    double someSalary;
    int someClientID;
    bool doesHaveCredit, doesHaveDeposit;

    // Запросы и запись данных из консоли
    cout << "Регистрация нового клиента.\n\n" << "Введите имя клиента: ";
    cin >> someFirstName;

    cout << "Введите фамилию клиента: ";
    cin >> someLastName;

    cout << "Введите дату рождения клиента: ";
    cin >> someBornDate;

    cout << "Присвойте клиенту идентификатор (число от 0 до 1000): ";
    cin >> someClientID;

    cout << "Каков доход клиента (в рублях)? : ";
    cin >> someSalary;

    cout << "Имеет ли клиент действующие кредиты? (введите да или нет): ";
    cin >> doesHaveCr;
    if (doesHaveCr == "да") {
        doesHaveCredit = true;
    } else {
        doesHaveCredit = false;
    }

    cout << "Имеет ли клиент действующие вклады? (введите да или нет): ";
    cin >> doesHaveDep;
    if (doesHaveDep == "да") {
        doesHaveDeposit = true;
    } else {
        doesHaveDeposit = false;
    }

    // Создание класса newClient и вызов методов с данными пользователя
    Client newClient(someFirstName, someLastName, someBornDate, someSalary, someClientID, doesHaveCredit, doesHaveDeposit);
    cout << "\nУ нас новый клиент!\n\n" << newClient.clientInfo() << endl;

    return 0;
    
}