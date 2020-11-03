#include <iostream>
#include <string>

char* itoa(int num) {

    char *ret = new char[100];
    int i = 0;

    while(num > 0) {
        num /= 10;
        i++;
    }

    while(num > 0) {
        num

    }
}

int atoi(const std::string& str) {
    int ret = 0;
    auto itr = str.cbegin();
    while(itr != str.cend()) {
        ret *= 10;
        ret += *itr - '0';
        ++itr;
    }

    return ret;
}

int atoi(char* str) {

    if(str == nullptr) {
        return -1;
    }

    int ret = 0;
    while(*str != '\0') {
        ret *= 10;
        ret += *str - '0';
        ++str;
    }

    return ret;
}

bool match(const std::string& w, const std::string& s)
{
    bool result = true;
    int pos = 0;

    while(w.size() > pos && s.size() > pos && (w[pos] == '?' || w[pos] == s[pos])) {
        ++pos;
    }

    if(w.size() == pos) {
        // *가 없는 경우
        return pos == s.size();
    }
    else if(w[pos] == '*') {
        for(int i = 0; pos + i <= s.size(); ++i) {
            result = match(w.substr(pos+1), s.substr(pos+i));
            if (result == true) {
                return true;
            }
        }
    }

    return false;
}

int main() {

//    std::string w = "a****";
//    std::string s = "aalhsaa";
//
//    bool ret = match(w, s);
//    std::cout << (ret ? "true" : "false") << std::endl;

    std::string numstr("1287812");
    std::cout << numstr << ": " << atoi(numstr) << std::endl;

    return 0;
}