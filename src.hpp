#include <vector>

template <typename T>
class Validator {
private:
    T value;
    bool valid;
    bool negate;

public:
    Validator(const T& val) : value(val), valid(true), negate(false) {}

    // Comparison methods - using only < and == operators
    Validator<T>& ge(const T& other) {
        if (valid) {
            // a >= b is equivalent to !(a < b)
            bool result = !(value < other);
            if (negate) {
                result = !result;
            }
            valid = valid && result;
        }
        return *this;
    }

    Validator<T>& le(const T& other) {
        if (valid) {
            // a <= b is equivalent to (a < b || a == b)
            bool result = (value < other) || (value == other);
            if (negate) {
                result = !result;
            }
            valid = valid && result;
        }
        return *this;
    }

    Validator<T>& gt(const T& other) {
        if (valid) {
            // a > b is equivalent to !(a < b || a == b)
            bool result = !((value < other) || (value == other));
            if (negate) {
                result = !result;
            }
            valid = valid && result;
        }
        return *this;
    }

    Validator<T>& lt(const T& other) {
        if (valid) {
            bool result = (value < other);
            if (negate) {
                result = !result;
            }
            valid = valid && result;
        }
        return *this;
    }

    Validator<T>& toBe(const T& other) {
        if (valid) {
            bool result = (value == other);
            if (negate) {
                result = !result;
            }
            valid = valid && result;
        }
        return *this;
    }

    Validator<T>& toBeOneOf(const std::vector<T>& options) {
        if (valid) {
            bool found = false;
            for (typename std::vector<T>::const_iterator it = options.begin();
                 it != options.end(); ++it) {
                if (value == *it) {
                    found = true;
                    break;
                }
            }
            if (negate) {
                found = !found;
            }
            valid = valid && found;
        }
        return *this;
    }

    Validator<T>& Not() {
        negate = true;
        return *this;
    }

    // Boolean conversion operator
    operator bool() const {
        return valid;
    }
};

template <typename T>
Validator<T> expect(const T& value) {
    return Validator<T>(value);
}
