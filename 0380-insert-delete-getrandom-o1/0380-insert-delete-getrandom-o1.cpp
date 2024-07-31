#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
private:
    std::unordered_map<int, int> map; // Stores value to its index in the array
    std::vector<int> values;          // Stores the values

public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false; // Value already present
        }
        values.push_back(val);        // Add value to the vector
        map[val] = values.size() - 1; // Store the index of the value in the map
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false; // Value not present
        }
        int lastElement = values.back(); // Get the last element in the vector
        int idx = map[val];              // Get the index of the element to be removed

        // Move the last element to the place of the element to be removed
        values[idx] = lastElement;
        map[lastElement] = idx;

        // Remove the last element
        values.pop_back();
        map.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size(); // Generate a random index
        return values[randomIndex];               // Return the value at the random index
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
