#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct City {
    string name;
    vector<pair<int, int>> neighbors;

    City(const string& cityName) : name(cityName) {}
};

vector<City> createCities() {
    vector<City> cities;

    // Þehirleri oluþturun ve mesafeleri hesaplayýn
    City cityA("A");
    City cityB("B");
    City cityC("C");
    City cityD("D");
    City cityE("E");

    cityA.neighbors.emplace_back(1, 50);  // Þehir A'dan B'ye olan mesafe: 50 km
    cityA.neighbors.emplace_back(2, 100); // Þehir A'dan C'ye olan mesafe: 100 km

    cityB.neighbors.emplace_back(0, 50);  // Þehir B'den A'ya olan mesafe: 50 km
    cityB.neighbors.emplace_back(3, 75);  // Þehir B'den D'ye olan mesafe: 75 km

    cityC.neighbors.emplace_back(0, 100); // Þehir C'den A'ya olan mesafe: 100 km
    cityC.neighbors.emplace_back(4, 120); // Þehir C'den E'ye olan mesafe: 120 km

    cityD.neighbors.emplace_back(1, 75);  // Þehir D'den B'ye olan mesafe: 75 km

    cityE.neighbors.emplace_back(2, 120); // Þehir E'den C'ye olan mesafe: 120 km

    cities.push_back(cityA);
    cities.push_back(cityB);
    cities.push_back(cityC);
    cities.push_back(cityD);
    cities.push_back(cityE);

    return cities;
}

void DFS(const vector<City>& cities, int startCity) {
    int numCities = cities.size();
    vector<bool> visited(numCities, false);
    stack<int> cityStack;

    visited[startCity] = true;
    cityStack.push(startCity);

    cout << "DFS traversal starting from City " << cities[startCity].name << ":" << endl;

    while (!cityStack.empty()) {
        int currentCity = cityStack.top();
        cityStack.pop();

        cout << cities[currentCity].name << " ";

        for (const auto& neighbor : cities[currentCity].neighbors) {
            int neighborIndex = neighbor.first;
            if (!visited[neighborIndex]) {
                visited[neighborIndex] = true;
                cityStack.push(neighborIndex);
            }
        }
    }

    cout << endl;
}

int main() {
    vector<City> cities = createCities();
    int startCity = 2; // Baþlangýç þehri indeksi

    DFS(cities, startCity);

    return 0;
}

