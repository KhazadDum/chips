#ifndef BITMASK_H
#define BITMASK_H

    #define SET_BIT(flag,bit)       ((flag) |= 1 << (bit))
    #define GET_BIT(flag,bit)       ((flag) & (1 << (bit)))
    #define CLEAR_BIT(flag,bit)     ((flag) &= ~(1 << (bit)))

    #define LEAST_MAX(x,y) (x ^ ((x ^ y) & -(x < y)))
    #define LEAST_SWAP(x,y) ((x)^=(y);(y)^=(x);(x)^=(y))
    #define LEAST_ISPOWERTWO(x) (( x &&! (x & (x - 1))))

    typedef unsigned char           FLAGS_8;
    typedef unsigned short int      FLAGS_16;
    typedef unsigned long int       FLAGS_32;
    typedef unsigned long long int  FLAGS_64;

#endif // BITMASK_H
