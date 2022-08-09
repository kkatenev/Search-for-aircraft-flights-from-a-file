#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct base
{
    string place;
    int num = 0;
    string type;
};

int main() {
    setlocale(0, "ru");
    base base[100];
    string result;
    int num, i = 0, sum = 0;

    string path = "Spravka.dat";
    ifstream fin;
    fin.open(path);
    

    if (fin.fail())
        cout << "\nФайл не открыт\n\n";
    else
    {
        cout << "Введите название пункта назначения:\n";
        cin >> result;
        cout << endl;

        while (!fin.eof())
        {
            fin >> base[i].place;
            fin >> base[i].num;
            fin >> base[i].type;
            if (result == base[i].place)
            {
                cout << base[i].num << endl;
                sum++;
            }
            i++;
        }
        if (sum == 0)
            cout << "Рейсов не найдено\n";
    }
    return 0;
}