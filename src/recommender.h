#pragma once
#include <bits/stdc++.h>
using namespace std;

class Recommender {
    unordered_map<int, vector<string>> movieFeatures;
    unordered_map<string, unordered_map<int, int>> userRatings;

public:
    void loadMovies(string file);
    void loadRatings(string file);
    vector<int> recommend(string user, int K);
};
