#include <iostream>
#include <string>

using namespace std;

template <typename Key, typename Value>
ostream& operator<<(ostream& out, pair<Key, Value> pr)
{
    return out << pr.first << ": "s << pr.second;
}

template <typename C>
ostream& Print(ostream& out, C& container)
{
    bool is_first = true;
    for(const auto& elem : container)
    {
        if(is_first)
        {
            out << elem;
            is_first = false;
            continue;
        }

        out << ", "s << elem;
    }

    return out;
}

template <typename E>
ostream& operator<<(ostream& out, vector<E> container)
{
    out << '[';
    Print(out, container);
    out << ']';

    return out;
}

template <typename E>
ostream& operator<<(ostream& out, set<E> container)
{
    out << '{';
    Print(out, container);
    out << '}';

    return out;
}

template <typename Key, typename Value>
ostream& operator<<(ostream& out, map<Key, Value> container)
{
    out << '{';
    Print(out, container);
    out << '}';

    return out;
}

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const string& t_str, const string& u_str, const string& file,
                     const string& func, unsigned line, const string& hint) {
    if (t != u) {
        cout << boolalpha;
        cout << file << "("s << line << "): "s << func << ": "s;
        cout << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        cout << t << " != "s << u << "."s;
        if (!hint.empty()) {
            cout << " Hint: "s << hint;
        }
        cout << endl;
        abort();
    }
}

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_HINT(a, b, hint) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))

void AssertImpl(bool value, const string& expr_str, const string& file, const string& func, unsigned line,
                const string& hint) {
    if (!value) {
        cout << file << "("s << line << "): "s << func << ": "s;
        cout << "ASSERT("s << expr_str << ") failed."s;
        if (!hint.empty()) {
            cout << " Hint: "s << hint;
        }
        cout << endl;
        abort();
    }
}

#define ASSERT(expr) AssertImpl(!!(expr), #expr, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_HINT(expr, hint) AssertImpl(!!(expr), #expr, __FILE__, __FUNCTION__, __LINE__, (hint))