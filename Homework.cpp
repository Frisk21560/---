// Homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

// клас Дріб тут зберігаються числа для дробу
class Drob {
private:
    int zminna1; // чисельник
    int zminna2; // знаменник

public:
    // функція щоб ввести наші числа в дріб
    void vvedyZminni() {
        cout << "Введи чисельник: ";
        cin >> zminna1; // тут вводимо що зверху
        cout << "Введи знаменник: ";
        cin >> zminna2; // тут що знизу
        if (zminna2 == 0) {
            cout << "Знаменник не може бути 0. Ставимо 1.\n";
            zminna2 = 1;
        }
    }

    // ця функція просто показує наш дріб
    void pokazhiDrob() {
        cout << zminna1 << "/" << zminna2 << '\n';
    }

    // це для додавання дробів
    Drob dodaty(Drob insha) {
        Drob novii;
        // перехрестно множимо
        novii.zminna1 = zminna1 * insha.zminna2 + insha.zminna1 * zminna2;
        novii.zminna2 = zminna2 * insha.zminna2;
        return novii;
    }

    // віднімання
    Drob vidnyaty(Drob insha) {
        Drob novii;
        // те саме що і додавання, тільки мінус між чисельникамии
        novii.zminna1 = zminna1 * insha.zminna2 - insha.zminna1 * zminna2;
        novii.zminna2 = zminna2 * insha.zminna2;
        return novii;
    }

    // множення дробів
    Drob mnozhyty(Drob insha) {
        Drob novii;
        // просто перемножаємо чисельники і знаменники
        novii.zminna1 = zminna1 * insha.zminna1;
        novii.zminna2 = zminna2 * insha.zminna2;
        return novii;
    }

    // ділення
    Drob dilyty(Drob insha) {
        Drob novii;
        // тут перевірка
        if (insha.zminna1 == 0) {
            cout << "Ділення на нуль! Повертаємо 0/1\n";
            novii.zminna1 = 0;
            novii.zminna2 = 1;
            return novii;
        }
        novii.zminna1 = zminna1 * insha.zminna2;
        novii.zminna2 = zminna2 * insha.zminna1;
        return novii;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Drob chislo1, chislo2, rezultat; // створюю три дроби, два для вводу, один для результату

    cout << "Введи перший дріб:\n";
    chislo1.vvedyZminni(); // тут користувач вводить перший дріб

    cout << "Введи другий дріб:\n";
    chislo2.vvedyZminni(); // тут другий

    cout << "Перший дріб: ";
    chislo1.pokazhiDrob(); // показує перший

    cout << "Другий дріб: ";
    chislo2.pokazhiDrob(); // показує другий

    // тепер роблю різні операції

    rezultat = chislo1.dodaty(chislo2); // додаю
    cout << "Сума: ";
    rezultat.pokazhiDrob();

    rezultat = chislo1.vidnyaty(chislo2); // віднімаю
    cout << "Різниця: ";
    rezultat.pokazhiDrob();

    rezultat = chislo1.mnozhyty(chislo2); // множу
    cout << "Добуток: ";
    rezultat.pokazhiDrob();

    rezultat = chislo1.dilyty(chislo2); // ділю
    cout << "Частка: ";
    rezultat.pokazhiDrob();

    return 0;
}