#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

std::string A(const std::string &B) {
    std::string C;
    for (char D : B) {
        C += std::bitset<8>(D).to_string();
    }
    return C;
}

std::string E(const std::string &F, const std::string &G) {
    std::string H = F;
    for (size_t I = 0; I < F.size(); ++I) {
        H[I] = F[I] ^ G[I % G.size()];
    }
    return H;
}

std::string J(const std::string &K) {
    const std::string L =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::string M;
    int N = 0;
    int O = 0;
    unsigned char P[3];
    unsigned char Q[4];

    for (auto R : K) {
        P[N++] = R;
        if (N == 3) {
            Q[0] = (P[0] & 0xfc) >> 2;
            Q[1] = ((P[0] & 0x03) << 4) + ((P[1] & 0xf0) >> 4);
            Q[2] = ((P[1] & 0x0f) << 2) + ((P[2] & 0xc0) >> 6);
            Q[3] = P[2] & 0x3f;

            for (N = 0; N < 4; N++)
                M += L[Q[N]];

            N = 0;
        }
    }

    if (N) {
        for (O = N; O < 3; O++)
            P[O] = '\0';

        Q[0] = (P[0] & 0xfc) >> 2;
        Q[1] = ((P[0] & 0x03) << 4) + ((P[1] & 0xf0) >> 4);
        Q[2] = ((P[1] & 0x0f) << 2) + ((P[2] & 0xc0) >> 6);
        Q[3] = P[2] & 0x3f;

        for (O = 0; O < N + 1; O++)
            M += L[Q[O]];

        while (N++ < 3)
            M += '=';
    }

    return M;
}

std::string S(const std::string &T) {
    std::string U = T;
    for (char &V : U) {
        if ((V >= 'a' && V <= 'z') || (V >= 'A' && V <= 'Z')) {
            char W = (V >= 'a' && V <= 'z') ? 'a' : 'A';
            V = ((V - W + 13) % 26) + W;
        }
    }
    return U;
}

int main() {
    std::string X;
    std::cout << "Password: ";
    std::getline(std::cin, X);
    std::string Y = A(X);
    std::string Z = "clave";
    std::string AA = E(Y, Z);
    std::string AB = J(AA);
    std::string AC = S(AA);
    std::string AD = "U11RRlVSXFBGVFJdUUZUUlxQR1RTXVFGVVNdUEZVU1xRR1VTXFBGVFNdUEdVU11QRlRTXVFHVVJcUEdVUl1QRlVTXVBGVFNcUUdVU1xRR1RTXVBGVFJcUUZUUlxRRlVSXFBHVFNdUEZVUl1RRlRTXVFHVVNcUUZUU11QRlRSXFFGVFJcUUdUU1xRR1RTXVFGVVJcUUdUUlxRR1RSXFBGVFNdUEZUUlxQRlVSXVFGVFJcUEdUU1xQRlVSXVFHVVNdUUdUU1xRR1RTXFBHVVJcUUZUU11QRlVTXFBGVVJdUEdVUlxQRlVSXFFHVFNdUUZUU11QR1RTXVFGVFJcUUZVUlxQR1VTXVFGVVJdUUZVU11RR1VSXFFHVVNdUEZUUl1QRlRSXVFHVVNcUUdUU1xRR1VTXVBGVVJdUUdUU11RRlRTXFBHVVNcUUZUUlxRR1RTXFBHVFNdUUdVUl1QRlVSXVFHVFNcUUdUU11QRlVTXFBGVFJcUUdVU1xQR1VTXFFH";
    if(AD == AB){
        std::cout << "Gotcha!";
    }else{
        std::cout << "Wrong Password!";
    }
    return 0;
}
