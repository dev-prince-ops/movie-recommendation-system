#include "recommender.h"

void Recommender::loadMovies(string file) {
    ifstream fin(file);
    int id;
    while (fin >> id) {
        string feature;
        vector<string> features;
        getline(fin, feature);
        stringstream ss(feature);
        while (ss >> feature)
            features.push_back(feature);
        movieFeatures[id] = features;
    }
}

void Recommender::loadRatings(string file) {
    ifstream fin(file);
    string user;
    int movie, rating;
    while (fin >> user >> movie >> rating) {
        userRatings[user][movie] = rating;
    }
}

vector<int> Recommender::recommend(string user, int K) {
    unordered_map<int, int> score;

    for (auto &[otherUser, ratings] : userRatings) {
        if (otherUser == user) continue;

        int similarity = 0;
        for (auto &[movie, r] : ratings)
            if (userRatings[user].count(movie))
                similarity++;

        for (auto &[movie, r] : ratings) {
            if (!userRatings[user].count(movie))
                score[movie] += similarity * r;
        }
    }

    priority_queue<pair<int,int>> pq;
    for (auto &[movie, sc] : score)
        pq.push({sc, movie});

    vector<int> result;
    while (!pq.empty() && K--) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
