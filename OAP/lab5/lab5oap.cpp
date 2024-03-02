#include <iostream>
#include <string>

using namespace std;

// Перечисление для специальностей
enum Specialty {
    COMPUTER_SCIENCE,
    ELECTRICAL_ENGINEERING,
    MECHANICAL_ENGINEERING,
    CHEMICAL_ENGINEERING,
    CIVIL_ENGINEERING
};
// Структура для конкурса
struct Competition {
    unsigned int computer_science : 1;
    unsigned int electrical_engineering : 1;
    unsigned int mechanical_engineering : 1;
    unsigned int chemical_engineering : 1;
    unsigned int civil_engineering : 1;
};
// Структура для университета
struct University {
    string name;
    string address;
    Competition competition;
    float payment;
    Specialty specialties[5];
};

const int MAX_UNIVERSITIES = 100;

int numUniversities = 0;
University universities[MAX_UNIVERSITIES];

// Функция для добавления университета
void addUniversity() {
    if (numUniversities < MAX_UNIVERSITIES) {
        University u;

        cout << "Введите имя университета: ";
        getline(cin, u.name);

        cout << "Введите адрес университета: ";
        getline(cin, u.address);

        for (int i = 0; i < 5; i++) {
            cout << "Введите специальность " << i + 1 << " (0 для окончания): ";
            int s;
            cin >> s;
            cin.ignore();

            if (s == 0) {
                break;
            }

            u.specialties[i] = static_cast<Specialty>(s - 1);
        }

        cout << "Введите конкурс за прошлый год(0 или 1): " << endl;
        cout << "Информатика: ";


        string competitionStr;
        getline(cin, competitionStr);
        u.competition.computer_science = stoi(competitionStr);

        cout << "Электротехника: ";

        string competitioStr;
        getline(cin, competitioStr);
        u.competition.electrical_engineering = stoi(competitioStr);

        cout << "Машиностроение: ";

        string competitiStr;
        getline(cin, competitiStr);
        u.competition.mechanical_engineering = stoi(competitiStr);

        cout << "Химическая инженерия: ";
        string competitStr;
        getline(cin, competitStr);
        u.competition.chemical_engineering = stoi(competitStr);

        cout << "Гражданское строительство: ";
        string competiStr;
        getline(cin, competiStr);
        u.competition.civil_engineering = stoi(competiStr);

        cout << "Введите цену за контрактное обучение: ";
        cin >> u.payment;

        universities[numUniversities++] = u;
        cout << "Университет успешно добавлен!" << endl;
    }
    else {
        cout << "Достигнуто максимальное количество университетов!" << endl;
    }
}
// Функция для отображения информации об университете
void displayUniversity(University u) {
    cout << "Имя: " << u.name << endl;
    cout << "Адрес: " << u.address << endl;
    cout << "Специальности: ";

    for (int i = 0; i < 5; i++) {
        if (u.specialties[i] != static_cast<Specialty>(-1)) {
            cout << u.specialties[i] << ", ";
        }
    }

    cout << endl;
    cout << "Конкурс: " << endl;
    cout << "Информатика: " << u.competition.computer_science << endl;
    cout << "Электротехника: " << u.competition.electrical_engineering << endl;
    cout << "Машиностроение: " << u.competition.mechanical_engineering << endl;
    cout << "Химическая инженерия: " << u.competition.chemical_engineering << endl;
    cout << "Гражданское строительство: " << u.competition.civil_engineering << endl;
    cout << "Цена за контрактное обучение: " << u.payment << endl;
}
// Функция для отображения всех университетов
void displayUniversities() {
    for (int i = 0; i < numUniversities; i++) {
        displayUniversity(universities[i]);
    }
}
// Функция для удаления университета
void deleteUniversity() {
    cout << "Введите имя университета для удаления: ";
    string name;
    getline(cin, name);
    for (int i = 0; i < numUniversities; i++) {
        if (universities[i].name == name) {
            for (int j = i; j < numUniversities - 1; j++) {
                universities[j] = universities[j + 1];
            }

            numUniversities--;
            cout << "Университет удален успешно!" << endl;
            return;
        }
    }

    cout << "Университет не найден!" << endl;
}
// Функция для поиска университета
void searchUniversityBySpecialty() {
    cout << "Введите специальность для поиска (0 - Информатика, 1 - Электротехника, 2 - Машиностроение, 3 - Химическая инженерия, 4 - Гражданское строительство): ";
    int s;
    cin >> s;
    cin.ignore();
    // Преобразование введенного числа в специальность
    Specialty specialty = static_cast<Specialty>(s);

    int count = 0;

    for (int i = 0; i < numUniversities; i++) {
        for (int j = 0; j < 5; j++) {
            if (universities[i].specialties[j] == specialty) {
                displayUniversity(universities[i]);
                count++;
                break;
            }
        }
    }

    if (count == 0) {
        cout << "Не найдено университетов с этой специальностью!" << endl;
    }
}
// Функция для отображения меню
void displayMenu() {
    cout << "Меню:" << endl;
    cout << "1. Добавить университет" << endl;
    cout << "2. Показать университеты" << endl;
    cout << "3. Удалить университет" << endl;
    cout << "4. Искать университет по специальности" << endl;
    cout << "5. Выход" << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        displayMenu();
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:

            addUniversity();
            break;
        case 2:
            displayUniversities();
            break;

        case 3:
            deleteUniversity();
            break;

        case 4:
            searchUniversityBySpecialty();
            break;

        case 5:
            cout << "Пока!" << endl;
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}