// rsa.h

#ifndef RSA_H
#define RSA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

extern long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
extern char msg[100];

int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

#endif
