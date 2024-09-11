using Coord = std::pair<int, int>;

std::set<Coord> get_affected(const Coord& coord) {
    auto [i, j] = coord;
    return {{i-1, j}, {i, j-1}, {i, j}, {i, j+1}, {i+1, j}};
}

int pluck_matrix(std::set<Coord>& coordinates) {
    int plucks = 0;
    
    while (!coordinates.empty()) {
        auto best_pluck = *std::max_element(coordinates.begin(), coordinates.end(),
            [&](const Coord& a, const Coord& b) {
                auto affected_a = get_affected(a);
                auto affected_b = get_affected(b);
                return std::count_if(affected_a.begin(), affected_a.end(),
                    [&](const Coord& c) { return coordinates.count(c); }) <
                       std::count_if(affected_b.begin(), affected_b.end(),
                    [&](const Coord& c) { return coordinates.count(c); });
            });
        
        auto affected = get_affected(best_pluck);
        for (const auto& coord : affected) {
            coordinates.erase(coord);
        }
        plucks++;
    }
    
    return plucks;
}

int main() {
    std::set<Coord> coordinates = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 2}};
    std::cout << "Minimum plucks required: " << pluck_matrix(coordinates) << std::endl;
    return 0;
}