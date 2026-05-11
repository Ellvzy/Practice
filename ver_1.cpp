#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct record
{
    int board_number;
    int flight_number;
    char mark[100] = {0};
    int time_h;
    int time_m;
};

void sort(record *List, int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = List[i].board_number;
        int index_min = i;
        for (int j = i; j < len; j++)
        {
            if (List[j].board_number < min)
            {
                min = List[j].board_number;
                index_min = j;
            }
        }
        record temp = List[i];
        List[i] = List[index_min];
        List[index_min] = temp;
    }
};

void printTable(record *List, int len)
{
}

int main()
{
    setlocale(LC_ALL, "rus");

    record List[100];

    FILE *file = fopen("test.txt", "r");
    if (!file)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    char line[100];
    int line_num = 0;

    // Читаем до символа новой строки с помощью %[^\n]
    while (fscanf(file, "%*[^0-9]%d%*[^0-9]%d%s%d:%d\n", &List[line_num].board_number, &List[line_num].flight_number, List[line_num].mark, &List[line_num].time_h, &List[line_num].time_m) == 5)
    {
        // Пропускаем символ новой строки
        line_num++;
    }

    fclose(file);

    for(int i = 0; i < line_num; i++)
    {
        cout << "Б-" << List[i].board_number<<" РЕЙС" << List[i].flight_number<< " "<<List[i].mark<<" "<< List[i].time_h<< ":"<< List[i].time_m<< endl;
    }
    sort(List, line_num);
    cout << endl;
    for(int i = 0; i < line_num; i++)
    {
        cout << "Б-" << List[i].board_number<<" РЕЙС" << List[i].flight_number<< " "<<List[i].mark<<" "<< List[i].time_h<< ":"<< List[i].time_m<< endl;
    }

    return 0;
}