//
// Created by a on 4/14/18.
//


#include <encrypttransfer.h>
namespace enp {
    uint8_t ServerNoReady = 0;
    uint8_t ServerReady = 1;
    const uint16_t ENDFLAG = 0xffff;
    const uint16_t DATALEN = 128;
    uint32_t serverport = htons(6666);
    uint32_t serverlistenaddr = htonl(INADDR_ANY);
    pthread_t pid[10000];
    queue<uint32_t> freepid;
    bool freepidlock = false;
    string k1024="key/1024.rsa";
    string k2048="key/2048.rsa";
    string k4096="key/4096.rsa";

    pair<unsigned char *, uint16_t> g2x(mpz_class mp) {
        uint16_t len = 0, i, j, k;
        mpz_class tmp = mp;
        while (tmp != 0) {
            len++;
            tmp /= 16;
        }
        unsigned char *data = new unsigned char(len);
        for (i = 0; i < len; i++) {
            for (j = 0, k = 0; j < 4; j++, k++) {
                k = k << 1;
                if (mp % 2 == 1) k ^= 1;
                mp /= 2;
            }
            if (k >= 0 && k <= 9) data[i] = '0' + k;
            else data[i] = 'A' + k;
        }
        return make_pair(data, len);
    }

    mpz_class x2g(unsigned char *data, uint16_t len) {
        uint32_t i, j, k;
        mpz_class ans = 0;
        for (i = 0; i < len; i++) {
            if (data[i] >= '0' && data[i] <= '9')k = data[i] - '0';
            else k = data[i] - 'A';
            for (j = 0; j < 4; i++) {
                ans *= 2;
                if (k & 1)ans += 1;
                k = k >> 1;
            }
        }
        return ans;
    }

    void Header::set(uint8_t a, unsigned char *b, mpz_class c, mpz_class d) {
        this->encodemethod = a;
        memcpy(this->filename, b, sizeof(unsigned char) * (4096 / 8));
        char buf[4096 / 8];
        pair<unsigned char *, uint16_t> p;
        p = g2x(c);
        memcpy(this->keyn, p.first, sizeof(char) * (4096 / 8));
        p = g2x(d);
        memcpy(this->keyd, p.first, sizeof(char) * (4096 / 8));
    }

    void Dataheader::set(uint16_t a, uint8_t b, uint8_t c) {
        this->ciphertextlen = a;
        this->plaintextlen = b;
        this->end = c;
    }

    funtionparm::funtionparm(uint32_t a, uint32_t b) {
        this->pidind = a;
        this->fd = b;
    }
}

void enp::clear() {
#ifdef LINUX
    system("clear");
#endif
#ifdef WINDOWS
    system("clc");
#endif
}