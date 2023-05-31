#include <stdexcept>

using namespace std;

class SetException : public exception {
public:
    const char* what() const noexcept override {
        return "Множество пустое";
    }
};
