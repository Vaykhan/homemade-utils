/**
 * cat(1) - Output from specified source to STDOUT.
 *          Modern extended C++ implementation.
 *
 * Author: Vugar Ahadli
 * Date:   2026
 */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    auto printStream = [](std::istream &inputSource)
    {
        std::string line;
        while (getline(inputSource,line))
        {
            std::cout << line << "\n";
        }
    };

    if (argc == 1)
    {
        printStream(std::cin);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        std::ifstream file(argv[i]);

        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << argv[i] << '\n';
            return 1;
        }

        printStream(file);
    }

    return 0;
}
