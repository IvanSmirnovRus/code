#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <ctime>

using std::set;
using std::map;
using std::vector;
using std::pair;
using std::make_pair;

static const int NN = 200005;
using TBitSet = std::bitset<NN>;

void input(std::vector<std::vector<int> >& adjacencyList) {
    int vertexQuantity;
    scanf("%d", &vertexQuantity);
    adjacencyList.resize(vertexQuantity);
    for (size_t edgeIndex = 0; edgeIndex + 1 < vertexQuantity; ++edgeIndex) {
        int xx, yy;
        scanf("%d %d", &xx, &yy);
        --xx;
        --yy;
        adjacencyList[xx].push_back(yy);
        adjacencyList[yy].push_back(xx);
    }
}

void Merge(const vector<int>& ss, map<int, int>& res, map<int, int>& good) {
    for (int x : ss) {
        ++res[x];
    }
    for (int i = 0; i < ss.size(); ++i) {
        for (int j = i; j < ss.size(); ++j) {
            --good[ss[i] + ss[j]];
        }
    }
}

vector<int> Dfs(const std::vector<std::vector<int> >& adjacencyList, 
                std::vector<bool>& used, int vv, TBitSet& result) {
    used[vv] = true;

    map<int, int> res, good;
    for (int to : adjacencyList[vv]) {
        if (!used[to]) {
            Merge(Dfs(adjacencyList, used, to, result), res, good);
        }
    }

    for (auto it = res.begin(); it != res.end(); ++it) {
        for (auto itt = it; itt != res.end(); ++itt) {
            if (it == itt) {
                good[it->first + itt->first] += it->second + (it->second > 1);
            } else {
                good[it->first + itt->first] += it->second * itt->second;
            }
        }
    }
    for (const auto& it : good) {
        if (it.second > 0) {
            result.set(it.first);
        }
    }

    if (res.empty()) {
        return std::vector<int> (1, 1);
    }
    vector<int> ret;
    for (auto it = res.begin(); it != res.end(); ++it) {
        ret.push_back(it->first + 1);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int> > adjacencyList;
    input(adjacencyList);

    if (adjacencyList.size() == 2) {
        std::cout << 1 << std::endl << 1 << std::endl;
        return 0;
    }

    std::vector<bool> used;
    used.assign(adjacencyList.size(), false);
    TBitSet result;
    for (size_t vertexIndex = 0; vertexIndex != adjacencyList.size(); ++vertexIndex) {
        if (adjacencyList[vertexIndex].size() > 1) {
            Dfs(adjacencyList, used, vertexIndex, result);
            break;
        }
    }

    printf("%d\n", result.count());
    for (int i = 0; i < result.size(); ++i) {
        if (result.test(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
