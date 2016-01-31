#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void input(std::vector<std::vector<int> >& adjacencyList) {
    size_t vertexQuantity;
    std::cin >> vertexQuantity;
    adjacencyList.resize(vertexQuantity);
    for (size_t edgeIndex = 0; edgeIndex + 1 < vertexQuantity; ++edgeIndex) {
        int xx, yy;
        std::cin >> xx;
        std::cin >> yy;
        --xx;
        --yy;
        adjacencyList[xx].push_back(yy);
        adjacencyList[yy].push_back(xx);
    }
}

struct TMySet {
    std::set<int> S;
    int Hash;
    TMySet() : Hash(0) {}
    bool operator<(const TMySet& other) const {
        if (Hash == other.Hash) {
            return S < other.S;
        }
        return Hash < other.Hash;
    }
    void insert(int xx) {
        if (S.find(xx) == S.end()) {
            Hash ^= xx;
        }
        S.insert(xx);
    }
    bool operator==(const TMySet& other) const {
        return S == other.S;
    }
    void swap(TMySet& other) {
        std::swap(Hash, other.Hash);
        S.swap(other.S);
    }
};

void merge(TMySet& first, TMySet& second, std::set<int>& result) {
    for (std::set<int>::iterator it = first.S.begin(); it != first.S.end(); ++it) {
        for (std::set<int>::iterator itt = second.S.begin(); itt != second.S.end(); ++itt) {
            result.insert(*it + *itt);
        }
    }
}

void unique(std::vector<TMySet>& vv) {
    size_t pos = 0;
    for (size_t ii = 0; ii < vv.size();) {
        size_t jj = ii;
        for (; jj < vv.size() && vv[jj] == vv[ii]; ++jj) {
        }
        if (jj - ii == 1) {
            vv[pos].swap(vv[ii]);
            pos++;
        } else {
            vv[pos].swap(vv[ii]);
            pos++;
            vv[pos].swap(vv[ii + 1]);
            pos++;
        }
        ii = jj;
    }
    vv.resize(pos);
}

TMySet dfs(const std::vector<std::vector<int> >& adjacencyList, std::vector<bool>& used,
           int vv, std::set<int>& result) {
    used[vv] = 1;
    std::vector<TMySet> depthes;
    for (std::vector<int>::const_iterator it = adjacencyList[vv].begin();
         it != adjacencyList[vv].end(); ++it) {
        if (used[*it] == 0) {
            depthes.push_back(dfs(adjacencyList, used, *it, result));
        }
    }
    std::sort(depthes.begin(), depthes.end());
    unique(depthes);
    for (size_t it = 0; it < depthes.size(); ++it) {
        for (size_t itt = it + 1; itt < depthes.size(); ++itt) {
            merge(depthes[it], depthes[itt], result);
        }
    }
    if (depthes.empty()) {
        TMySet depth;
        depth.insert(1);
        return depth;
    } else {
        TMySet depth;
        for (std::vector<TMySet >::iterator it = depthes.begin(); it != depthes.end(); ++it) {
            for (std::set<int>::iterator itt = it->S.begin(); itt != it->S.end(); ++itt) {
                depth.insert(*itt + 1);
            }
        }
        return depth;
    }
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::vector<std::vector<int> > adjacencyList;
    input(adjacencyList);
    if (adjacencyList.size() == 2) {
        std::cout << 1 << std::endl << 1 << std::endl;
        return 0;
    }

    std::vector<bool> used;
    used.assign(adjacencyList.size(), false);
    std::set<int> result;
    for (size_t vertexIndex = 0; vertexIndex != adjacencyList.size(); ++vertexIndex) {
        if (adjacencyList[vertexIndex].size() > 1) {
            dfs(adjacencyList, used, vertexIndex, result);
            break;
        }
    }
    std::cout << result.size() << std::endl;
    for (std::set<int>::iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
