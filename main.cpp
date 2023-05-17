#include <iostream>

using namespace std;

template <typename T>
class Container {
    T* container = NULL;
    T* new_container = NULL;

    uint64_t base_Size = 1;
    uint64_t global_Index = 0;

public:
    Container(const uint64_t& enter_Size, const T& enter_Value) {
        container = new T[enter_Size];

        for (uint64_t i = 0; i != enter_Size; ++i) {
            container[i] = enter_Value;
        }

        base_Size = enter_Size;
    }
    Container(const uint64_t& enter_Size) {
        container = new T[enter_Size];
        base_Size = enter_Size;
    }
    Container(void) {
        container = new T[base_Size];
    }
    ~Container(void) {
        delete [] container;
        container = NULL;
    }

    void Push_Back(const T& your_Value) {
        if (global_Index == base_Size) {
            new_container = new T[base_Size * 2];

            for (uint64_t i = 0; i != base_Size; ++i) {
                new_container[i] = container[i];
            }

            base_Size *= 2;
            delete [] container;
            container = new_container;
        }

        container[global_Index] = your_Value;

        ++global_Index;
    }
    void Pop_Back(void) {
        if (base_Size) {
                container[global_Index].~T();
        }
        --global_Index;
        --base_Size;
    }
    uint64_t Size(void) {
        return base_Size;
    }

    T& operator[](const uint64_t& index) {
        if (index >= base_Size) {
            return container[base_Size -1];
        } else {
            return container[index];
        }
    }
};

int main(void) {
    return 0;
}
