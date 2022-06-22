
//!!!!! The function save as works if it is written saveas, because otherwise we will not be able to work with large files 
//! and change will not be validated right. Otherwise we can use std::cin.getline and save as will work.

#include "HexViewer.h"

char view_word[5] = { 'v', 'i', 'e', 'w', '\0' };
char change_word[7] = { 'c', 'h', 'a', 'n', 'g', 'e', '\0' };
char remove_word[7] = { 'r', 'e', 'm', 'o', 'v', 'e', '\0' };
char add_word[4] = { 'a', 'd', 'd', '\0' };
char save_word[5] = { 's', 'a', 'v', 'e', '\0' };
char saveas_word[7] = { 's', 'a', 'v', 'e', 'a', 's', '\0' };


int compare(char* array1, char* array2)
{
    int j = 0;
    int response = 0;

    while (array1[j] == array2[j] && response == 0)
    {
        if (array1[j] == '\0' || array2[j] == '\0')
        {
            response = 1;
        }
        j++;
    }

    return response;
}

int main()
{
    char path[1000];
    std::cout << "Please enter a file path.\n";
    std::cin >> path;
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    HexViewer temp;

    if (file.is_open())
    {
        temp.setSize(file);

        std::cout << "File loaded successfully! size: " << temp.getSize() << " bytes\n";
        char option[1000];
        temp.setBuffer(file);
        file.close();
        
        while (true)
        {
            
            std::cin >> option;

            if (compare(view_word, option) == 1)
            {
                temp.view();
            }
            else if (compare(change_word, option) == 1)
            {
                int a = 0;
                char b[3];
                std::cin >> a >> b;
                temp.change(a, b);
                std::cout << "Operation successfully executed!\n";
            }
            else if (compare(remove_word, option) == 1)
            {
                temp.removeByte();
            }
            else if (compare(add_word, option) == 1)
            {
                char b[3];
                std::cin >> b;
                temp.add(b);
            }
            else if (compare(save_word, option) == 1)
            {
                temp.save(path);

                std::cout << "File successfully saved.\n";

                break;
            }
            else if (compare(saveas_word, option) == 1)
            {
                char path1[1000];
                std::cin >> path1;
                temp.saveas(path1);
                std::cout << "File successfully saved.\n";
                break;
            }
            else
            {
                std::cout << "No such operation\n";
                break;
            }
        }

        temp.freeBuffer();
    }
    else
    {
        std::cout << "Open file - error.\n";
    }
}
