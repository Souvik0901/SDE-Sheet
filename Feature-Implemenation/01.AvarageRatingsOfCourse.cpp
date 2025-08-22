#include <bits/stdc++.h>
using namespace std;

class CourseRatingSystem {
    unordered_map<string, pair<int,int>> courseRatings;  // courseId -> {sum, count}
    unordered_map<string, int> userRatings;             // "userId#courseId" -> rating

    string makeKey(const string &userId, const string &courseId) {
        return userId + "#" + courseId;
    }

public:
    void addRating(const string &userId, const string &courseId, int rating) {
        string key = makeKey(userId, courseId);

        // Ensure courseId entry exists
        if(courseRatings.find(courseId) == courseRatings.end()) {
            courseRatings[courseId] = {0, 0};
        }

        // If user already rated → adjust old rating
        if(userRatings.find(key) != userRatings.end()) {
            int oldRating = userRatings[key];
            courseRatings[courseId].first -= oldRating;
            courseRatings[courseId].first += rating;
        } else {
            courseRatings[courseId].first += rating;
            courseRatings[courseId].second += 1;
        }

        userRatings[key] = rating;
    }

    double getAverage(const string &courseId) {
        if(courseRatings.find(courseId) == courseRatings.end() || courseRatings[courseId].second == 0) {
            return 0.0;
        }
        auto [sum, count] = courseRatings[courseId];
        return (double)sum / count;
    }
};

int main() {
    CourseRatingSystem rs;

    // Example input
    rs.addRating("User1", "Course1", 3);
    rs.addRating("User2", "Course1", 5);
    rs.addRating("User2", "Course2", 3);
    rs.addRating("User1", "Course2", 4);
    rs.addRating("User1", "Course3", 5);
    rs.addRating("User2", "Course3", 1);

    cout << fixed << setprecision(2);
    cout << "Course1 Average: " << rs.getAverage("Course1") << endl; // 4.00
    cout << "Course2 Average: " << rs.getAverage("Course2") << endl; // 3.50
    cout << "Course3 Average: " << rs.getAverage("Course3") << endl; // 3.00

    // Test update (User1 changes rating for Course1 from 3 → 1)
    rs.addRating("User1", "Course1", 1);
    cout << "Course1 Average after update: " << rs.getAverage("Course1") << endl; // (1+5)/2 = 3.00

    return 0;
}
