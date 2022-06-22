#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#pragma warning(disable : 4996)

struct HexViewer
{
private:
    char* buffer;
    int size;
    int HexToDec(char hex[]);
public:
    int getSize();
    void setSize(std::fstream& file);
    void setBuffer(std::fstream& file);
    void view();
    void change(int place, char* different);
    void removeByte();
    void add(char* different);
    void save(char path[1000]);
    void saveas(char path[1000]);
    void freeBuffer();
    

};

