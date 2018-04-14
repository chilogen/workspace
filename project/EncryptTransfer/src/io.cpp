//
// Created by a on 4/12/18.
//

#include <EncryptTransfer.h>

using namespace std;

namespace aaa {
    int32_t check(string &key) {
        int32_t i;
        if (key.length() != codebit / 16)return 0;
        for (i = 0; i < key.length(); i++) {
            if (key[i] >= 0 && key[i] <= 9)continue;
            if (key[i] >= 'A' && key[i] <= 'F')continue;
            if (key[i] >= 'a' && key[i] <= 'f')key[i] = key[i] - 'a' + 'A';
            return 0;
        }
        return 1;
    }

    int32_t readkey(string path, mpz_class &ans) {
        ans = 0;
        int32_t i, j, k;
        ifstream in(path);
        string s;
        in >> s;
        if (check(s)) {
            for (i = 0; i < s.length(); i++) {
                ans = ans << 16;
                if (s[i] >= 0 && s[i] <= 9)j = s[i] - 'a';
                else j = s[i] - 'A' + 10;
                ans = ans ^ j;
            }
            in.close();
        } else return 0;
        return 1;
    }

    int readdata(string path, mpz_class *&data, int64_t &len) {
        ifstream in(path);
        char c;
        while (!in.eof()) {
            in >> c;
        }
        return 1;
    }

    int getkey(int32_t flag, mpz_class &key) {
        if (key == PUBLIC_KEY)return readkey("key/publickey", key);
        else if (key == PRIVATE_KEY)return readkey("key/privatekey", key);
        return 0;
    }
}