//
//#include <iostream>
//#include <Windows.h>
//#include <string>
//#include <sstream>
//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//const int templates[4][8] = {
//    {1, 2, 3, 4, 1, 2, 3, 4},
//    {2, 3, 4, 1, 2, 3, 4, 1},
//    {3, 4, 1, 2, 3, 4, 1, 2},
//    {4, 1, 2, 3, 4, 1, 2, 3}
//};
//
//int access_matrix[4][8];
//int object_secret_level[8] = { 1,1,1,1,2,2,2,2 };
//int user_secret_level[1][8];
//
//
//string name_1class = "user1";
//string name_2class = "user2";
//string name_3class = "user3";
//string name_4class = "user4";
//
//
//void save_access_matrix() 
//{
//    ofstream file("access_matrix.txt");
//    if (file.is_open()) {
//        for (int i = 0; i < 4; ++i) 
//        {
//            for (int j = 0; j < 8; ++j) 
//            {
//                file << access_matrix[i][j] << " ";
//            }
//            file << "\n";
//        }
//        file.close();
//    }
//}
//
//void save_security_levels() 
//{
//    ofstream file("security_levels.txt");
//    if (file.is_open()) 
//    {
//        for (int j = 0; j < 8; ++j) file << object_secret_level[j] << " ";
//        file << "\n";
//        for (int i = 0; i < 4; ++i) 
//        {
//            for (int j = 0; j < 8; ++j) 
//            {
//                file << user_secret_level[i][j] << " ";
//            }
//            file << "\n";
//        }
//        file.close();
//    }
//}
//
//void load_access_matrix() 
//{
//    ifstream file("access_matrix.txt");
//    if (file.is_open()) {
//        for (int i = 0; i < 4; ++i)
//        {
//            for (int j = 0; j < 8; ++j)
//            {
//                file >> access_matrix[i][j];
//            }
//        }
//        file.close();
//    }
//    else
//    {
//        for (int i = 0; i < 4; ++i)
//            for (int j = 0; j < 8; ++j)
//                access_matrix[i][j] = templates[i][j];
//
//        ofstream new_file("access_matrix.txt");
//        if (new_file.is_open()) 
//        {
//            for (int i = 0; i < 4; ++i)
//            {
//                for (int j = 0; j < 8; ++j)
//                {
//                    new_file << access_matrix[i][j] << " ";
//                }
//                new_file << "\n";
//            }
//            new_file.close();
//        }
//    }
//}
//
//void load_security_levels()
//{
//    ifstream file("security_levels.txt");
//    if (file.is_open()) {
//        for (int j = 0; j < 8; ++j) file >> object_secret_level[j];
//        for (int i = 0; i < 4; ++i)
//            for (int j = 0; j < 8; ++j)
//                file >> user_secret_level[i][j];
//        file.close();
//    }
//    else {
//        save_security_levels();
//    }
//}
//
//
//
//int check_user_class(const string& name) 
//{
//    string temp;
//    istringstream iss1(name_1class);
//    while (iss1 >> temp) if (temp == name) return 0;
//    istringstream iss2(name_2class);
//    while (iss2 >> temp) if (temp == name) return 1;
//    istringstream iss3(name_3class);
//    while (iss3 >> temp) if (temp == name) return 2;
//    istringstream iss4(name_4class);
//    while (iss4 >> temp) if (temp == name) return 3;
//    return -1;
//}
//
//void main_choise(int choice) 
//{
//    switch (choice)
//    {
//    case 1: cout << "Чтение\n"; break;
//    case 2: cout << "Чтение и запись\n"; break;
//    case 3: cout << "Чтение, запись, редактирование\n"; break;
//    case 4: cout << "Полные права\n"; break;
//    default: cout << "Нет прав\n";
//    }
//}
//
//void show_actions(int rights) 
//{
//    cout << "Доступные действия:\n";
//    switch (rights) {
//    case 1: cout << "1. Просмотр\n"; break;
//    case 2: cout << "1. Просмотр\n2. Запись\n"; break;
//    case 3: cout << "1. Просмотр\n2. Запись\n3. Редактирование\n4. Передача прав\n"; break;
//    case 4: cout << "1. Просмотр\n2. Запись\n3. Редактирование\n4. Удаление\n5. Передача прав\n"; break;
//    default: cout << "Действия недоступны\n";
//    }
//}
//
//void perform_action(int action, int rights) 
//{
//    if (action < 1 || action > rights) 
//    {
//        cout << "Недопустимое действие!\n";
//        return;
//    }
//    switch (action) 
//    {
//    case 1: cout << "Выполняется просмотр... Успешно!\n"; break;
//    case 2: if (rights >= 2) cout << "Выполняется запись... Успешно!\n"; break;
//    case 3: if (rights >= 3) cout << "Выполняется редактирование... Успешно!\n"; break;
//    case 4: if (rights >= 4) cout << "Выполняется удаление... Успешно!\n"; break;
//    default: cout << "Действие не реализовано\n";
//    }
//}
//
//void print_matrix()
//{
//    cout << "\n[Матрица прав доступа]\n     Объекты 0-7\n";
//    for (int j = 0; j < 8; ++j) cout << setw(3) << j;
//    cout << "\n     -------------------------\n";
//    for (int i = 0; i < 4; ++i)
//    {
//        cout << "id." << i << " |";
//        for (int j = 0; j < 8; ++j) cout << setw(3) << access_matrix[i][j];
//        cout << "\n";
//    }
//
//    cout << "\n[Уровни секретности объектов]\nОбъекты: ";
//    for (int j = 0; j < 8; ++j) cout << setw(3) << j;
//    cout << "\nУровни:  ";
//    for (int j = 0; j < 8; ++j) cout << setw(3) << object_secret_level[j];
//    cout << "\n";
//
//    cout << "\n[Уровни доступа пользователей]\nПользователь | Объекты 0-7\n";
//    cout << "-------------+-------------------------\n";
//    for (int i = 0; i < 4; ++i) {
//        cout << "   " << setw(2) << i << "        | ";
//        for (int j = 0; j < 8; ++j) {
//            cout << setw(3) << user_secret_level[i][j];
//        }
//        cout << "\n";
//    }
//
//    cout << "Права доступа: 1-чтение, 2-запись, 3-редактирование, 4-полные права\n";
//    cout << "Уровни секретности: 0-открытый, 1-секретный, 2-совершенно секретный\n";
//    cout << "Уровень пользователя должен быть >= уровня объекта для доступа\n\n";
//}
//
//void admin_mode() 
//{
//    cout << "Режим администратора\n";
//    print_matrix();
//
//    while (true) {
//        cout << "1 - Изменить права доступа\n2 - Показать матрицу\n"
//            "3 - Изменить уровень секретности объекта\n"
//            "4 - Изменить уровень доступа пользователя\n5 - Выход\nВыберите: ";
//        int choice;
//        cin >> choice;
//
//        if (choice == 5) break;
//
//        switch (choice) 
//        {
//        case 1: 
//        {
//            int row, tpl;
//            cout << "Введите номер строки (0-3) и номер шаблона (0-3): ";
//            cin >> row >> tpl;
//            if (row >= 0 && row < 4 && tpl >= 0 && tpl < 4) {
//                for (int j = 0; j < 8; ++j) access_matrix[row][j] = templates[tpl][j];
//                save_access_matrix();
//                cout << "Права обновлены!\n";
//                print_matrix();
//            }
//            else cout << "Ошибка ввода!\n";
//            break;
//        }
//        case 2: print_matrix(); break;
//        case 3: 
//        {
//            int obj, level;
//            cout << "Введите номер объекта (0-7) и новый уровень (0-2): ";
//            cin >> obj >> level;
//            if (obj >= 0 && obj < 8 && level >= 0 && level <= 2)
//            {
//                object_secret_level[obj] = level;
//                save_security_levels();
//                cout << "Уровень секретности обновлен!\n";
//            }
//            else cout << "Ошибка ввода!\n";
//            break;
//        }
//        case 4: 
//        {
//            int user, obj, level;
//            cout << "Введите ID пользователя (0-3), объект (0-7) и уровень (0-2): ";
//            cin >> user >> obj >> level;
//            if (user >= 0 && user < 4 && obj >= 0 && obj < 8 && level >= 0 && level <= 2) 
//            {
//                if (level < object_secret_level[obj]) 
//                {
//                    cout << " [ВНИМАНИЕ] Уровень пользователя (" << level
//                        << ") ниже уровня объекта (" << object_secret_level[obj] << ")!\n";
//                }
//                user_secret_level[user][obj] = level;
//                save_security_levels();
//                cout << "Уровень доступа пользователя обновлен!\n";
//            }
//            else cout << "Ошибка ввода!\n";
//            break;
//        }
//        default: cout << "Неверный выбор!\n";
//        }
//    }
//}
//
//int main()
//{
//    SetConsoleOutputCP(1251);
//    load_access_matrix();
//    load_security_levels();
//
//    while (true)
//    {
//        cout << "\nВведите имя пользователя (или 'exit' для выхода): ";
//        string name;
//        cin >> name;
//
//        if (name == "exit") break;
//        if (name == "admin") { admin_mode(); continue; }
//
//        int user_class = check_user_class(name);
//        if (user_class == -1) { cout << "Пользователь не найден!\n"; continue; }
//
//        while (true) {
//            cout << "\nВыберите объект (0-7) или -1 для возврата: ";
//            int obj; cin >> obj;
//            if (obj == -1) break;
//            if (obj < 0 || obj > 7) { cout << "Неверный объект!\n"; continue; }
//
//            int user_level = user_secret_level[user_class][obj];
//            int obj_level = object_secret_level[obj];
//
//            cout << "Уровень доступа: пользователь " << user_level
//                << " | объект " << obj_level << " -> ";
//            if (user_level < obj_level)
//            {
//                cout << "Доступ запрещен!\n";
//                continue;
//            }
//            cout << "Доступ разрешен\n";
//
//            int rights = access_matrix[user_class][obj];
//            cout << "Ваши права: "; main_choise(rights);
//            show_actions(rights);
//
//            int action;
//            cout << "Выберите действие (0-отмена): ";
//            cin >> action;
//            if (action == 0) continue;
//
//            if ((rights >= 3 && action == 4) || (rights >= 4 && action == 5)) 
//            {
//                cout << "Введите имя пользователя для передачи прав: ";
//                string targetName;
//                cin >> targetName;
//                int targetClass = check_user_class(targetName);
//                if (targetClass == -1) {
//                    cout << "Пользователь не найден!\n";
//                    continue;
//                }
//
//                if (user_secret_level[targetClass][obj] < object_secret_level[obj])
//                {
//                    cout << " У получателя уровень доступа "
//                        << user_secret_level[targetClass][obj]
//                        << " < уровня объекта (" << object_secret_level[obj] << ")\n";
//                    continue;
//                }
//
//                int current_rights = access_matrix[user_class][obj];
//                int transfer_right;
//                cout << "1 - Чтение\n2 - Запись\n3 - Редактирование\n4 - Полные права\n";
//                cout << "Введите уровень прав: ";
//                cin >> transfer_right;
//
//                if (transfer_right < 1 || transfer_right > 4)
//                {
//                    cout << "Неверный уровень прав!\n";
//                }
//                else if (transfer_right > current_rights)
//                {
//                    cout << "Нельзя передать права выше своих!\n";
//                }
//                else
//                {
//                    access_matrix[targetClass][obj] = transfer_right;
//                    save_access_matrix();
//                    cout << "Права успешно переданы!\n";
//                }
//            }
//            else 
//            {
//                perform_action(action, rights);
//            }
//        }
//    }
//    return 0;
//}



#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

const int templates[4][8] = {
    {1, 2, 3, 4, 1, 2, 3, 4},
    {2, 3, 4, 1, 2, 3, 4, 1},
    {3, 4, 1, 2, 3, 4, 1, 2},
    {4, 1, 2, 3, 4, 1, 2, 3}
};

int access_matrix[4][8];
int object_secret_level[8] = { 1, 1, 1, 1, 2, 2, 2, 2 };
int user_secret_level[4] = { 1, 1, 1, 1 }; 

string user_names[4] = { "user1", "user2", "user3", "user4" };

void save_access_matrix() {
    ofstream file("access_matrix.txt");
    if (file.is_open()) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                file << access_matrix[i][j] << " ";
            }
            file << "\n";
        }
        file.close();
    }
}

void save_security_levels() {
    ofstream file("security_levels.txt");
    if (file.is_open()) {
        // Сохраняем уровни объектов
        for (int j = 0; j < 8; ++j)
            file << object_secret_level[j] << " ";
        file << "\n";

        // Сохраняем уровни пользователей
        for (int i = 0; i < 4; ++i)
            file << user_secret_level[i] << " ";
        file << "\n";
        file.close();
    }
}

void load_access_matrix() {
    ifstream file("access_matrix.txt");
    if (file.is_open()) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                file >> access_matrix[i][j];
            }
        }
        file.close();
    }
    else {
        // Инициализация шаблоном при первом запуске
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 8; ++j)
                access_matrix[i][j] = templates[i][j];
        save_access_matrix();
    }
}

void load_security_levels() {
    ifstream file("security_levels.txt");
    if (file.is_open()) {
        // Загрузка уровней объектов
        for (int j = 0; j < 8; ++j)
            file >> object_secret_level[j];

        // Загрузка уровней пользователей
        for (int i = 0; i < 4; ++i)
            file >> user_secret_level[i];
        file.close();
    }
    else {
        // Инициализация по умолчанию
        for (int i = 0; i < 4; ++i) user_secret_level[i] = 1;
        save_security_levels();
    }
}

int check_user_class(const string& name) {
    for (int i = 0; i < 4; ++i) {
        if (name == user_names[i]) return i;
    }
    return -1;
}

void main_choice(int choice) {
    switch (choice) {
    case 1: cout << "Чтение\n"; break;
    case 2: cout << "Чтение и запись\n"; break;
    case 3: cout << "Чтение, запись, редактирование\n"; break;
    case 4: cout << "Полные права\n"; break;
    default: cout << "Нет прав\n";
    }
}

void show_actions(int rights) {
    cout << "Доступные действия:\n";
    switch (rights) {
    case 1: cout << "1. Просмотр\n"; break;
    case 2: cout << "1. Просмотр\n2. Запись\n"; break;
    case 3: cout << "1. Просмотр\n2. Запись\n3. Редактирование\n4. Передача прав\n"; break;
    case 4: cout << "1. Просмотр\n2. Запись\n3. Редактирование\n4. Удаление\n5. Передача прав\n"; break;
    default: cout << "Действия недоступны\n";
    }
}

void perform_action(int action, int rights) {
    if (action < 1 || action > rights) {
        cout << "Недопустимое действие!\n";
        return;
    }
    switch (action) {
    case 1: cout << "Выполняется просмотр... Успешно!\n"; break;
    case 2: if (rights >= 2) cout << "Выполняется запись... Успешно!\n"; break;
    case 3: if (rights >= 3) cout << "Выполняется редактирование... Успешно!\n"; break;
    case 4: if (rights >= 4) cout << "Выполняется удаление... Успешно!\n"; break;
    default: cout << "Действие не реализовано\n";
    }
}

void print_matrix() {
    cout << "\n[Матрица прав доступа]\n     Объекты 0-7\n";
    for (int j = 0; j < 8; ++j) cout << setw(3) << j;
    cout << "\n     -------------------------\n";
    for (int i = 0; i < 4; ++i) {
        cout << "id." << i << " |";
        for (int j = 0; j < 8; ++j) cout << setw(3) << access_matrix[i][j];
        cout << "\n";
    }

    cout << "\n[Уровни секретности объектов]\nОбъекты: ";
    for (int j = 0; j < 8; ++j) cout << setw(3) << j;
    cout << "\nУровни:  ";
    for (int j = 0; j < 8; ++j) cout << setw(3) << object_secret_level[j];
    cout << "\n";

    cout << "\n[Уровни доступа пользователей]\n";
    cout << "Пользователь | Уровень\n";
    cout << "-------------+---------\n";
    for (int i = 0; i < 4; ++i) {
        cout << " " << setw(10) << user_names[i] << " | " << user_secret_level[i] << "\n";
    }
}

void admin_mode() {
    cout << "Режим администратора\n";
    print_matrix();

    while (true) {
        cout << "\n1 - Изменить права доступа\n2 - Показать матрицу\n"
            "3 - Изменить уровень секретности объекта\n"
            "4 - Изменить уровень доступа пользователя\n5 - Выход\nВыберите: ";
        int choice;
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
        case 1: {
            int row, tpl;
            cout << "Введите номер строки (0-3) и номер шаблона (0-3): ";
            cin >> row >> tpl;
            if (row >= 0 && row < 4 && tpl >= 0 && tpl < 4) {
                for (int j = 0; j < 8; ++j)
                    access_matrix[row][j] = templates[tpl][j];
                save_access_matrix();
                cout << "Права обновлены!\n";
            }
            else cout << "Ошибка ввода!\n";
            break;
        }
        case 2:
            print_matrix();
            break;
        case 3: {
            int obj, level;
            cout << "Введите номер объекта (0-7) и новый уровень (0-2): ";
            cin >> obj >> level;
            if (obj >= 0 && obj < 8 && level >= 0 && level <= 2) {
                object_secret_level[obj] = level;
                save_security_levels();
                cout << "Уровень секретности обновлен!\n";
            }
            else cout << "Ошибка ввода!\n";
            break;
        }
        case 4: {
            int user, level;
            cout << "Введите ID пользователя (0-3) и новый уровень (0-2): ";
            cin >> user >> level;
            if (user >= 0 && user < 4 && level >= 0 && level <= 2) {
                user_secret_level[user] = level;
                save_security_levels();
                cout << "Уровень доступа пользователя обновлен!\n";
            }
            else cout << "Ошибка ввода!\n";
            break;
        }
        default:
            cout << "Неверный выбор!\n";
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    load_access_matrix();
    load_security_levels();

    while (true) {
        cout << "\nВведите имя пользователя (или 'exit' для выхода): ";
        string name;
        cin >> name;

        if (name == "exit") break;
        if (name == "admin") { admin_mode(); continue; }

        int user_class = check_user_class(name);
        if (user_class == -1) { cout << "Пользователь не найден!\n"; continue; }

        while (true) {
            cout << "\nВыберите объект (0-7) или -1 для возврата: ";
            int obj;
            cin >> obj;
            if (obj == -1) break;
            if (obj < 0 || obj > 7) { cout << "Неверный объект!\n"; continue; }

            int user_level = user_secret_level[user_class];
            int obj_level = object_secret_level[obj];

            cout << "Уровень доступа: пользователь " << user_level
                << " | объект " << obj_level << " -> ";
            if (user_level < obj_level) {
                cout << "Доступ запрещен!\n";
                continue;
            }
            cout << "Доступ разрешен\n";

            int rights = access_matrix[user_class][obj];
            cout << "Ваши права: ";
            main_choice(rights);
            show_actions(rights);

            int action;
            cout << "Выберите действие (0-отмена): ";
            cin >> action;
            if (action == 0) continue;

            if ((rights >= 3 && action == 4) || (rights >= 4 && action == 5)) {
                cout << "Введите имя пользователя для передачи прав: ";
                string targetName;
                cin >> targetName;
                int targetClass = check_user_class(targetName);
                if (targetClass == -1) {
                    cout << "Пользователь не найден!\n";
                    continue;
                }

                if (user_secret_level[targetClass] < object_secret_level[obj]) {
                    cout << " У получателя уровень доступа "
                        << user_secret_level[targetClass]
                        << " < уровня объекта (" << object_secret_level[obj] << ")\n";
                    continue;
                }

                int current_rights = access_matrix[user_class][obj];
                int transfer_right;
                cout << "1 - Чтение\n2 - Запись\n3 - Редактирование\n4 - Полные права\n";
                cout << "Введите уровень прав: ";
                cin >> transfer_right;

                if (transfer_right < 1 || transfer_right > 4) {
                    cout << "Неверный уровень прав!\n";
                }
                else if (transfer_right > current_rights) {
                    cout << "Нельзя передать права выше своих!\n";
                }
                else {
                    access_matrix[targetClass][obj] = transfer_right;
                    save_access_matrix();
                    cout << "Права успешно переданы!\n";
                }
            }
            else {
                perform_action(action, rights);
            }
        }
    }
    return 0;
}