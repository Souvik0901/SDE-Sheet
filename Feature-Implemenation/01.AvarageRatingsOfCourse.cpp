#include <bits/stdc++.h>
using namespace std;

class CourseRatingSystem {
    unordered_map<string, pair<int,int>> courseRatings; // courseId -> {sum, count}
    unordered_map<string, int> userRatings;             // "userId#courseId" -> rating

    string makeKey(const string &userId, const string &courseId) {
        return userId + "#" + courseId;
    }

public:
    void addRating(const string &userId, const string &courseId, int rating) {
        string key = makeKey(userId, courseId);

        if(courseRatings.find(courseId) == courseRatings.end()) {
            courseRatings[courseId] = {0, 0};
        }

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

    vector<pair<string,double>> getTopK(int k) {
        using P = pair<double,string>; // {avg, courseId}

        priority_queue<P, vector<P>, greater<P>> minHeap;

        for (auto &p : courseRatings) {
            if (p.second.second == 0) continue;
            double avg = (double)p.second.first / p.second.second;
            minHeap.push({avg, p.first});
            if ((int)minHeap.size() > k) {
                minHeap.pop(); // keep only top K
            }
        }

        vector<pair<string,double>> result;
        while(!minHeap.empty()) {
            result.push_back({minHeap.top().second, minHeap.top().first});
            minHeap.pop();
        }

        reverse(result.begin(), result.end()); // highest first
        return result;
    }
};

int main() {
    CourseRatingSystem rs;

    // Add ratings
    rs.addRating("User1", "Course1", 3);
    rs.addRating("User2", "Course1", 5);
    rs.addRating("User2", "Course2", 3);
    rs.addRating("User1", "Course2", 4);
    rs.addRating("User1", "Course3", 5);
    rs.addRating("User2", "Course3", 1);
    rs.addRating("User3", "Course4", 5);
    rs.addRating("User4", "Course4", 4);
    rs.addRating("User5", "Course5", 2);
    rs.addRating("User6", "Course5", 1);

    cout << fixed << setprecision(2);

    cout << "Average ratings:\n";
    cout << "Course1: " << rs.getAverage("Course1") << endl;
    cout << "Course2: " << rs.getAverage("Course2") << endl;
    cout << "Course3: " << rs.getAverage("Course3") << endl;
    cout << "Course4: " << rs.getAverage("Course4") << endl;
    cout << "Course5: " << rs.getAverage("Course5") << endl;

    cout << "\nTop 10 Courses:\n";
    auto top = rs.getTopK(10);
    for (auto &p : top) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}

