#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int crossProduct(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Point> convexHull(vector<Point>& points) {
    sort(points.begin(), points.end());
    
    vector<Point> lower, upper;
    
    for (const auto& p : points) {
        while (lower.size() >= 2 && crossProduct(lower[lower.size()-2], lower.back(), p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }
    
    for (int i = points.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 && crossProduct(upper[upper.size()-2], upper.back(), points[i]) <= 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }
    
    lower.pop_back();
    upper.pop_back();
    
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates of point " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    
    cout << "Convex Hull:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    
    return 0;
}
