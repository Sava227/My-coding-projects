#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_unique(vector<int> data) {
    //sort container
    sort(data.begin(), data.end());
    //remove copies
    auto last = unique(data.begin(), data.end());
    //cut the vector
    data.erase(last, data.end());

    return data;
}

int main() {
    vector<int> numbers = {4, 2, 5, 2, 3, 4, 1, 5};

    vector<int> unique_numbers = get_unique(numbers);

    for (int n : unique_numbers) {
        cout<<n<<" "<<endl;
    }
    return 0;
}