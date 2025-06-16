
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

const int templates[4][8] = 
{
    {1, 2, 3, 4, 1, 2, 3, 4},
    {2, 3, 4, 1, 2, 3, 4, 1},
    {3, 4, 1, 2, 3, 4, 1, 2},
    {4, 1, 2, 3, 4, 1, 2, 3}
};

int access_matrix[4][8] =
{
    {1, 2, 3, 4, 1, 2, 3, 4},
    {2, 3, 4, 1, 2, 3, 4, 1},
    {3, 4, 1, 2, 3, 4, 1, 2},
    {4, 1, 2, 3, 4, 1, 2, 3}
};

string name_1class = "user1";
string name_2class = "user2";
string name_3class = "user3";
string name_4class = "user4";

void load_matrix() 
{
    ifstream file("matrix.txt");
    if (file.is_open()) {
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 8; ++j) 
            {
                file >> access_matrix[i][j];
            }
        }
        file.close();
    }
}

void save_matrix()
{
    ofstream file("matrix.txt");
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

int check_user_class(const string& name) 
{
    string temp;
    istringstream iss1(name_1class);
    while (iss1 >> temp) if (temp == name) return 0;
    istringstream iss2(name_2class);
    while (iss2 >> temp) if (temp == name) return 1;
    istringstream iss3(name_3class);
    while (iss3 >> temp) if (temp == name) return 2;
    istringstream iss4(name_4class);
    while (iss4 >> temp) if (temp == name) return 3;
    return -1;
}

void main_choise(int choice)
{
    switch (choice)
    {
    case 1: cout << "Чтение\n"; break;
    case 2: cout << "Чтение и запись\n"; break;
    case 3: cout << "Чтение, запись, редактирование\n"; break;
    case 4: cout << "Полные права\n"; break;
    default: cout << "Нет прав\n";
    }
}

void show_actions(int rights) 
{
    cout << "Доступные действия:\n";
    switch (rights) {
    case 1:
        cout << "1. Просмотр\n";
        break;
    case 2:
        cout << "1. Просмотр\n2. Запись\n";
        break;
    case 3:
        cout << "1. Просмотр\n2. Запись\n3. Редактирование\n";
        break;
    case 4:
        cout << "1. Просмотр\n2. Запись\n3. Редактирование\n4. Удаление\n";
        break;
    default:
        cout << "Действия недоступны\n";
    }
}

void perform_action(int action, int rights) 
{
    if (action < 1 || action > rights) {
        cout << "Недопустимое действие!\n";
        return;
    }

    switch (action) 
    {
    case 1:
        cout << "Выполняется просмотр... Успешно!\n";
        break;
    case 2:
        if (rights >= 2)
            cout << "Выполняется запись... Успешно!\n";
        break;
    case 3:
        if (rights >= 3)
            cout << "Выполняется редактирование... Успешно!\n";
        break;
    case 4:
        if (rights >= 4)
            cout << "Выполняется удаление... Успешно!\n";
        break;
    default:
        cout << "Действие не реализовано\n";
    }
}

void print_matrix() 
{
    cout << "\nТекущая матрица прав доступа:\n";
    cout << "     Объекты 0-7\n";
    cout << "     ";
    for (int j = 0; j < 8; ++j) cout << setw(3) << j;
    cout << "\n";
    cout << "     -------------------------\n";

    for (int i = 0; i < 4; ++i) 
    {
        cout << "id." << i << " |";
        for (int j = 0; j < 8; ++j) 
        {
            cout << setw(3) << access_matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\nКлюч прав: 1-чтение, 2-запись, 3-редакт., 4-полные\n\n";
}

void admin_mode() 
{
    cout << "Режим администратора\n";
    print_matrix();

    while (true) 
    {
        cout << "1 - Изменить права\n2 - Показать матрицу\n3 - Выход\nВыберите: ";
        int choice; cin >> choice;

        if (choice == 3) break;

        if (choice == 1) 
        {
            int row, tpl;
            cout << "Введите номер строки (0-3) и номер шаблона (0-3): ";
            cin >> row >> tpl;

            if (row >= 0 && row < 4 && tpl >= 0 && tpl < 4) 
            {
                for (int j = 0; j < 8; ++j) {
                    access_matrix[row][j] = templates[tpl][j];
                }
                save_matrix();
                cout << "Права обновлены!\n";
                print_matrix();
            }
            else {
                cout << "Ошибка ввода!\n";
            }
        }
        else if (choice == 2) 
        {
            print_matrix();
        }
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    load_matrix();

    while (true) 
    {
        cout << "\nВведите имя пользователя (или 'exit' для выхода): ";
        string name;
        cin >> name;

        if (name == "exit") break;

        if (name == "admin") 
        {
            admin_mode();
            continue;
        }

        int user_class = check_user_class(name);
        if (user_class == -1) 
        {
            cout << "Пользователь не найден!\n";
            continue;
        }

        while (true) 
        {
            cout << "\nВыберите объект (0-7) или -1 для возврата в меню: ";
            int obj; cin >> obj;
            if (obj == -1) break;
            if (obj < 0 || obj > 7) 
            {
                cout << "Неверный объект!\n";
                continue;
            }

            int rights = access_matrix[user_class][obj];
            
            cout << "1 - чтение"<<endl;
            cout << "2 - запись"<<endl;
            cout << "3 - редактирование"<<endl;
            cout << "-------'\n";
            cout << "Ваши права: ";
            main_choise(rights);

            show_actions(rights);
            if (rights > 0) 
            {
                cout << "Выберите действие (0-отмена): ";
                int action;
                cin >> action;
                if (action != 0) 
                {
                    perform_action(action, rights);
                }
            }
        }
    }
    return 0;
}