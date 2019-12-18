#include <stdio.h>

struct qr {
    unsigned int q;
    unsigned int r;
};

typedef struct qr QR;

QR divmod(unsigned int a, unsigned int b) {
    QR result = {
        a/b,
        a%b
    };
    return result;
}

void printqr(QR *qr) {
    printf("%u %u\n", qr->q, qr->r);
}

int main() {
    int x = 10;
    int y = 3;
    QR qr = divmod(x, y);
    printf("%u %u\n", qr.q, qr.r);
    printqr(&qr);
}

/* What does this program print... and why?
 * Why does printqr use ->  ?
 * Why does main use . ?
 * Can you rewrite line 19 to use . instead of -> ?
 */


