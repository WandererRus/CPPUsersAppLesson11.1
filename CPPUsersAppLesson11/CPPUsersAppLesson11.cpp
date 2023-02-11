// CPPUsersAppLesson11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define __CRT_SECURE_NO_WARNINGS
union code {
    int number;
    char letter;
};
#include <iostream>
#include <io.h>

int CountWord(std::string text)
{
    int length = text.length();
    char* pmystr = new char[length];
    int wordsCount = 0;
    bool letterExist = false;
    for (int i = 0; i < length; i++)
    {
        *(pmystr + i) = text[i];
    }
    for (int i = 0; i < length; i++)
    {
        *(pmystr + i) = text[i];
    }
    for (int i = 0; i < length; i++)
    {
        if (!letterExist && int(*(pmystr + i)) >= 65 && int(*(pmystr + i)) <= 90 || !letterExist && int(*(pmystr + i)) >= 97 && int(*(pmystr + i)) <= 122)
        {
            letterExist = true;
            wordsCount++;
        }
        else if (int(*(pmystr + i)) < 65 || int(*(pmystr + i)) > 90 && int(*(pmystr + i)) < 97 || int(*(pmystr + i)) > 122)
        {
            letterExist = false;
        }

    }

    return wordsCount;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    
    int length = 0;
    int counter = 0;
    int word = 0;
    int letter = 0;
    bool passWord = false;
    std::string text = "";
    FILE* myfile;
    fopen_s(&myfile,"D:\\test.txt", "r");
    code cod;


    while (!feof(myfile))
    {
        cod.number = fgetc(myfile);
        if (cod.number >=0 )
        { 
            text.push_back(cod.letter);
        }
        
    }
    fclose(myfile);

    length = text.length();
    int massiveWordsLength = CountWord(text);
    char** massiveWords = new char* [massiveWordsLength];
    for (int i = 0; i < massiveWordsLength; i++)
    {
        massiveWords[i] = new char[length];
    }
    for (int i = 0; i < massiveWordsLength; i++)
    {
        for (int j = 0; j < length; j++)
        {
            massiveWords[i][j] = '1';
        }        
    }
    bool letterExist = false;
    int massiveWordsIndex = 0;
    int massiveWordsCharIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (int(text[i]) >= 65 && int(text[i]) <= 90 || int(text[i]) >= 97 && int(text[i]) <= 122)
        {
            massiveWords[massiveWordsIndex][massiveWordsCharIndex] = text[i];
            massiveWordsCharIndex++;
        }
        else if (int(text[i]) == 32)
        {
            massiveWordsCharIndex = 0;
            massiveWordsIndex++;
        }
        

    }
    massiveWordsIndex = 0;
    massiveWordsCharIndex = 0;
    for (int i = 0; i < massiveWordsLength; i++)
    {
        for (int j = 0; j < length; j++)
        {
            massiveWordsCharIndex++;
            if (massiveWords[i][j] == '1')
            {
                if (massiveWordsCharIndex >= 7)
                {
                    massiveWordsIndex++;                                        
                }
                massiveWordsCharIndex = 0;
                break;
            }

        }
    }

    std::cout << massiveWordsIndex;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
