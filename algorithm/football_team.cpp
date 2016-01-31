#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void RandomVector(std::vector<int>* vector, int sid, size_t maxSize, long long int maxElement) {
    srand(sid);
    size_t sequenceSize = rand() % maxSize + 1;
    for (size_t index = 0; index < sequenceSize; ++index) {
        vector->push_back(rand() % maxElement);
    }
}

template <typename ForwardIterator>
void PrintContainer (ForwardIterator begin, ForwardIterator end) {
    if (begin + 1 <= end) {
        std::cout << *begin;
    }
    for (ForwardIterator it = begin + 1; it < end; ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
}

struct TPlayer {
    int Number;
    long long Efficiency;
    bool operator< (const TPlayer& otherPlayer) const{
        return Efficiency < otherPlayer.Efficiency;
    }
};

std::ostream& operator<< (std::ostream& os, const TPlayer& player) {
    os << player.Number << ","<< player.Efficiency;
    return os;
}

struct  TTeam {
    std::vector<TPlayer> players;
    long long Efficiency;
};

void input(std::vector<TPlayer>& players) {
    int playersQuantity;
    std::cin >> playersQuantity;
    players.resize(playersQuantity);
    for (std::vector<TPlayer>::iterator it = players.begin(); it < players.end(); ++it) {
        std::cin >> it->Efficiency;
        it->Number = std::distance(players.begin(), it) + 1;
    }
}

void OptimalTeam(std::vector<TPlayer>::iterator begin, std::vector<TPlayer>::iterator end,
                 TTeam& team) {
    long long int maxEfficiency = 0;
    long long int teamEfficiency = 0;
    int worstPlayer = 0;
    int bestPlayer = 0;
    int previousWorstPlayerEfficiency = 0;
    for (std::vector<TPlayer>::iterator it = begin, jt = begin;; ++it) {
        if (it + 1 == end || jt == end) {
            if (teamEfficiency > maxEfficiency) {
                maxEfficiency = teamEfficiency;
                bestPlayer = std::distance(begin, jt - 1);
                worstPlayer = std::distance(begin, it - 1);
            }
            break;
        }
        teamEfficiency -= previousWorstPlayerEfficiency;
        previousWorstPlayerEfficiency = it->Efficiency;
        for (;jt != end;) {
            if (std::distance(it, jt) < 2) {
                teamEfficiency += jt->Efficiency;
                ++jt;
            } else {
                if (jt->Efficiency <=  (long long int)(it->Efficiency) + (it + 1)->Efficiency) {
                    teamEfficiency +=  jt->Efficiency;
                    ++jt;
                } else {
                    if (teamEfficiency > maxEfficiency) {
                        maxEfficiency = teamEfficiency;
                        bestPlayer = std::distance(begin, jt - 1);
                        worstPlayer = std::distance(begin, it);
                    }
                    break;
                }
            }
        }
    }
    team.players.resize(bestPlayer + 1 - worstPlayer);
    std::copy(begin + worstPlayer, begin + bestPlayer + 1, team.players.begin());
    team.Efficiency = maxEfficiency;
}

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
