#ifndef BOLA
#define BOLA

#include <iostream>
#include <string>

using namespace std;

class Bola
{
private:
    /* data */
public:
    Bola(int id, string cor);
    ~Bola();

    int id;
    string cor;
};

#endif