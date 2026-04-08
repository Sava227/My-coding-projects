#include<iostream>
#include<utility>
using namespace std;

template <typename T>
class unique_pointer {
private:
    T* ptr;

public:
    //constructor
    explicit unique_pointer(T* p = nullptr) : ptr(p) {}

    //destructor
    ~unique_pointer() {
        delete ptr;
    }

    //no copy
    unique_pointer(const unique_pointer&) = delete;
    unique_pointer& operator=(const unique_pointer&) = delete;

    //moving constructor
    unique_pointer(unique_pointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    //move owning
    unique_pointer& operator=(unique_pointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    //unnaming
    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    //get empty pointer
    T* get() const {
        return ptr;
    }

    //free ownership
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    //erase
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

int main() {
    unique_pointer<int> p1(new int(100));
    cout<<*p1<<endl;

    unique_pointer<int> p2 = move(p1);

    if (!p1.get()) {
        cout<<"p1 is empty"<<endl;
    }
    cout<<*p2<<endl;
    return 0;
}