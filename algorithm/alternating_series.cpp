#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

/*
void GetMaxAlternatingSeries(const std::vector<int>& series, std::vector<int>* alternatingSeries) {
    if(!series.size()) {
        return;
    }
    if(series.size() == 1) {
        *alternatingSeries = series;
    }
    bool positive;
    std::vector<int> groupBegins;
    std::vector<int>::const_iterator itSeries;

    for (itSeries = series.begin(); itSeries != std::prev(series.end()); ++itSeries) {
        if (*itSeries - *std::next(itSeries) > 0) {
            mask.push_back(1);
        } else {
            if (*itSeries - *std::next(itSeries) < 0) {
                mask.push_back(0);  
            }
            else {
                mask.push_back(mask.back());
            }
        }
    } 
    std::copy(mask.begin(), mask.end(), std::ostream_iterator<int>(std::cout, " "));

    alternatingSeries->push_back(series[0]);
    int in = mask[0];
    for(std::vector<int>::const_iterator itSeries = series.begin(), itSeries != series.end(), ++itSeries) {
        if() {}
    } */

void ReadSeries(std::vector<int>* series) {
    size_t size;
    std::cin >> size;
    series->resize(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> (*series)[i]; 
    }
}

void GetBegins(const std::vector<int>& series, std::vector<int>* begins) {
    int elemCounter = 0;
    while (series[elemCounter] == series[0] && elemCounter != series.size()) {
        ++elemCounter;
    }
    if (elemCounter == series.size()) {
        return;
    }
    begins->push_back(elemCounter); 
    bool isPositive = (series[0] > series[elemCounter]); 
    ++elemCounter;
    for (;elemCounter != series.size(); ++elemCounter) {
        if (series[elemCounter] == series[elemCounter - 1]) {
            continue;
        }
        if ((series[elemCounter] < series[elemCounter  - 1]) != isPositive) {
            begins->push_back(elemCounter);
            isPositive = !isPositive;
        }
    }
}

void GetMaxAlternatingSeries(const std::vector<int>& series, const std::vector<int>& begins,
    std::vector<int>* alternatingSeries) {
    if (series.size() < 2) {
        *alternatingSeries = series;
        return;
    }
    bool isPositive = series[0] > series[begins[0]];
    alternatingSeries->push_back(series[0]);
    int elemCounter = begins[0];
    int nextElemCounter;
    int nextEndCounter;
    bool stop = false;
    for (int beginsCounter = 0; beginsCounter + 1 < begins.size(); ++beginsCounter) {
        nextElemCounter = begins[beginsCounter + 1];
        if (beginsCounter + 2 == begins.size()) {
            nextEndCounter = series.size() - 1; 
        } else {
            nextEndCounter = begins[beginsCounter + 2] - 1;
        }
        while (nextEndCounter  + 1> begins[beginsCounter + 1] && !stop) {
            if (isPositive) {
                while (series[elemCounter] < series[nextEndCounter]) {
                    nextElemCounter = nextEndCounter;
                    --nextEndCounter;
                    stop = true;
                }
            } else {
                while (series[elemCounter] > series[nextEndCounter]) {
                    nextElemCounter = nextEndCounter;
                    --nextEndCounter;
                    stop = true;
                }
            }
            ++elemCounter;
        }
        stop = false;
        isPositive = !isPositive;
        alternatingSeries->push_back(series[elemCounter - 1]);
        elemCounter = nextElemCounter;
    }
    alternatingSeries->push_back(series[elemCounter ]);
}

int main(int argc, char const *argv[])
{   
    std::vector<int> series, begins, alternatingSeries;
    ReadSeries(&series); 
    GetBegins(series, &begins);
    GetMaxAlternatingSeries(series, begins, &alternatingSeries);
    std::copy(alternatingSeries.begin(), alternatingSeries.end(),
    std::ostream_iterator<int> (std::cout, " ")); 
    std::cout << std::endl;
    return 0;
}
