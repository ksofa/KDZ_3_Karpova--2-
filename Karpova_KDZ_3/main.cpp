#include <vector>
#include <random>
#include <fstream>
#include "generator.h"
#include "records.h"

// получить случайно сгенерированное число
int rn(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// записать результаты на всех алгоритмах в файл
void record(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        const std::string &name) {

    recordDijkstraPriorityQueue(file, g, start, end, numEdges, name);
    recordDijkstraVector(file, g, start, end, numEdges, name);
    recordFloyd(file, g, start, end, numEdges, name);
    recordFord(file, g, start, end, numEdges, name);

}

int main() {
    // присваиваем имена столбцам в таблице
    std::ofstream file("data.csv", std::ios_base::app);
    file << "info;time;edges;ribs\n";

    // задаём крайние значения и значения шага итерации
    int start = 10;
    int end = 1010;
    int step = 50;

    // полный граф
    for (int n = start; n <= end; n += step) {

        // генерируем полный граф
        std::vector<std::vector<int>> g = generateCompleteGraph(n);
        // задаём начальную и конечную вершины случайным образом
        int a = rn(0, n - 1), b = rn(0, n - 1);
        // используем известное количество ребёр
        int numEdges = (n * (n - 1)) / 2;

        // присваиваем имя первой ячейки в таблице
        std::string name = "complete graph";
        // запускаем запись результатов всех алгоритмов
        record(file, g, a, b, numEdges, name);
    }

    // разреженный граф
    for (int n = start; n <= end; n += step) {

        // количество ребер неизвестно, из-за чего принимаем его первым параметром из генератора
        auto info = generateSparseGraph(n);
        // записываем количество ребер
        int numEdges = info.first;
        // записываем разреженный граф
        auto g = info.second;
        // случайным образом определяем начальную и конечную вершины
        int a = rn(0, n - 1), b = rn(0, n - 1);

        // задаем имя первой ячейке в таблице
        std::string name = "sparse graph";
        record(file, g, a, b, numEdges, name);
    }

    // соединенный граф

    // определяем параметр density
    double density = 0.4;
    for (int n = start; n <= end; n += step) {

        // генерируем соединенный граф и записываем его вместе с количеством ребер в переменную
        auto info = generateConnectedGraph(n, density);
        // записываем количество ребер в переменную
        int numEdges = info.first;
        // записываем соединенный граф
        auto g = info.second;
        // генерируем начальную и конечную вершины графа
        int a = rn(0, n - 1), b = rn(0, n - 1);

        // задаем имя первой ячейки в таблице
        std::string name = "connected graph";
        // запускаем запись данных в таблицу
        record(file, g, a, b, numEdges, name);
        // увеличиваем параметр density
        density += 0.025;
    }

    file.close();

    return 0;
}
