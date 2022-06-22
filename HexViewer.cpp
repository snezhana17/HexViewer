#pragma once
#include "HexViewer.h"

int HexViewer::getSize() {
    return size;
}

void HexViewer::setSize(std::fstream& file)
{
    file.seekg(0, std::ios::end);
    //tells where the end of the file is
    size = file.tellg();

    //puts the reading of the file at the beginning again
    file.seekg(0);
}

void HexViewer::setBuffer(std::fstream& file)
{

    buffer = new char[size + 1];

    char byte;

    for (int i = 0; i < size; i++)
    {
        file.get(byte);
        buffer[i] = byte;
    }

    buffer[size] = '\0';
}

void HexViewer::freeBuffer()
{
    delete[] buffer;
    size = 0;
}
void HexViewer::view()
{

    for (int i = 0; i < size; i++)
    {

        printf("%02X", buffer[i]);

        std::cout << " ";
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        char byte = buffer[i];
        if ((byte >= 65 && byte <= 90) || (byte >= 97 && byte <= 122))
        {
            std::cout << byte;
        }
        else
        {
            std::cout << '.';
        }
        std::cout << " ";
    }
    std::cout << "\n";
}

void HexViewer::change(int place, char* different)
{
    if (place > size)
    {
        std::cout << "No value in this place.\n";
    }

    int b = HexToDec(different);
    buffer[place] = b;
}

void HexViewer::removeByte()
{
    char* temp = new char[size];

    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = buffer[i];
    }

    temp[size - 1] = '\0';

    delete[] buffer;

    size = size - 1;

    buffer = temp;
}

void HexViewer::add(char* different)
{
    char a = HexToDec(different);

    char* temp = new char[size + 2];

    for (int i = 0; i < size; i++)
    {
        temp[i] = buffer[i];
    }

    temp[size] = a;
    temp[size + 1] = '\0';

    delete[] buffer;
    buffer = nullptr;

    ++size;
    buffer = temp;
}

void HexViewer::save(char path[1000])
{

    std::ofstream file(path, std::ios::in | std::ios::binary | std::ios::trunc);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << buffer[i];
        }
        file.close();
    }
}

void HexViewer::saveas(char path[1000])
{
    std::ofstream file(path, std::ios::in | std::ios::binary | std::ios::trunc);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << buffer[i];
        }
        file.close();
    }
}

int HexViewer::HexToDec(char hex[])
{
    char* hexnumber;
    int length = 0;
    const int base = 16;
    int decimal = 0;
    int i;
    for (hexnumber = hex; *hexnumber != '\0'; hexnumber++)
    {
        length++;
    }
    hexnumber = hex;
    for (i = 0; *hexnumber != '\0' && i < length; i++, hexnumber++)
    {
        if (*hexnumber >= 48 && *hexnumber <= 57)
        {
            decimal += (((int)(*hexnumber)) - 48) * pow(base, length - i - 1);
        }
        else if ((*hexnumber >= 65 && *hexnumber <= 70))
        {
            decimal += (((int)(*hexnumber)) - 55) * pow(base, length - i - 1);
        }
        else if (*hexnumber >= 97 && *hexnumber <= 102)
        {
            decimal += (((int)(*hexnumber)) - 87) * pow(base, length - i - 1);
        }
        else
        {
            std::cout << " The given hexadecimal number is invalid. \n";
        }
    }
    return decimal;
}
