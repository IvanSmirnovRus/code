#include <iostream>
#include <vector>
#include <algorithm>


// Выводит в стандартный поток вывода любой контейнер
template <typename ForwardIterator>
void PrintContainer (ForwardIterator begin, ForwardIterator end);

// Хранит информацию об игроке
struct TPlayer {
    int Number;
    long long Efficiency;
    bool operator< (const TPlayer& otherPlayer) const;
};

std::ostream& operator<< (std::ostream& os, const TPlayer& player);


// Хранит информацию о команде
struct  TTeam {
    std::vector<TPlayer> players;
    long long Efficiency;
};

//Читает входные данные
void input(std::vector<TPlayer>& players);

//Находит лучшую команду
void OptimalTeam(std::vector<TPlayer>::iterator begin, std::vector<TPlayer>::iterator end,
                 TTeam& team);

int main(int argc, char const *argv[]) {
    std::vector<TPlayer> players;
    input(players);
    std::sort(players.begin(), players.end());
    TTeam team;
    OptimalTeam(players.begin(), players.end(), team);
    std::vector<int> result(team.players.size());
    for (std::vector<TPlayer>::iterator it = team.players.begin(); it != team.players.end(); ++it) {
        result[it - team.players.begin()] = it->Number;
    }
    std::sort(result.begin(), result.end());
    std::cout << team.Efficiency << std::endl;
    PrintContainer(result.begin(), result.end());
    return 0;
}