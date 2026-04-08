#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;

mutex mtx;
vector<int> primes;

//function to check if a number is prime
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
//each thread runs this function
void find_primes(int start, int end) {
    vector<int> local_primes;   //local storage

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            local_primes.push_back(i);
        }
    }

    lock_guard<mutex> lock(mtx);
    primes.insert(primes.end(), local_primes.begin(), local_primes.end());
}

int main() {
    int L = 1;
    int R = 100;
    int num_threads = 4;

    vector<thread> threads;

    int chunk = (R - L + 1) / num_threads;

    for (int i = 0; i < num_threads; i++) {
        int start = L + i * chunk;
        int end = (i == num_threads - 1) ? R : start + chunk - 1;
        threads.emplace_back(find_primes, start, end);
    }

    //ending of streams
    for (auto& t : threads) {
        t.join();
    }

    //sorting result
    sort(primes.begin(), primes.end());

    cout<<"Prime numbers:"<<endl;
    for (int p : primes) {
        cout<<p<<" "<<endl;
    }
    return 0;
}