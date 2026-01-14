#include "recommender.h"

int main() {
    Recommender r;
    r.loadMovies("data/movies.txt");
    r.loadRatings("data/ratings.txt");

    auto recs = r.recommend("user1", 3);
    cout << "Recommended movies:\n";
    for (int m : recs)
        cout << "Movie ID: " << m << "\n";
}
