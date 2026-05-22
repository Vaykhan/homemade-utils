/**
 * yes(1) - Repeatedly output a string until killed.
 *          Modern extended C++ implementation.
 *
 * Author: Vugar Ahadli
 * Date:   2026
 */


#include <iostream>
#include <string>
#include <unistd.h>
#include <getopt.h>

/* Colours */

/* Regular */
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

/* Bright */
#define BRIGHT_BLACK "\x1b[90m"
#define BRIGHT_RED "\x1b[91m"
#define BRIGHT_GREEN "\x1b[92m"
#define BRIGHT_YELLOW "\x1b[93m"
#define BRIGHT_BLUE "\x1b[94m"
#define BRIGHT_MAGENTA "\x1b[95m"
#define BRIGHT_CYAN "\x1b[96m"
#define BRIGHT_WHITE "\x1b[97m"

#define RESET "\x1b[0m"

std::string getColour(const std::string& c)
{
    if (c == "black")
    {
        return BLACK;
    }
    
    if (c == "red")
    {
        return RED;
    }
    
    if (c == "green")
    {
        return GREEN;
    }
    
    if (c == "yellow")
    {
        return YELLOW;
    } 
    
    if (c == "blue")
    {
        return BLUE;
    } 
    
    if (c == "magenta")
    {
        return MAGENTA;
    }
    
    if (c == "cyan")
    { 
        return CYAN;
    }
    
    if (c == "white")
    { 
        return WHITE;
    }
    
    if (c == "bright_black")
    {
        return BRIGHT_BLACK;
    }
    
    if (c == "bright_red")
    {
        return BRIGHT_RED;
    } 
    
    if (c == "bright_green")
    {
        return BRIGHT_GREEN;
    } 
    
    if (c == "bright_yellow")
    { 
        return BRIGHT_YELLOW;
        
    }
    
    if (c == "bright_blue")
    {
        return BRIGHT_BLUE;
    }
    
    if (c == "bright_magenta")
    {
        return BRIGHT_MAGENTA;
    }
    
    if (c == "bright_cyan")
    {
        return BRIGHT_CYAN;
    }
    
    if (c == "bright_white")
    {
        return BRIGHT_WHITE;
    } 
    

    return RESET;
}




void printUsage()
{
    std::cout << "yes++\n\n"
              << "Repeatedly output a string until killed.\n"
              << "Modern implementation of yes tool\n"
              << "Usage:\n"
              << "  yes [--color <color>] [text...]\n"
              << "Options:\n"
              << "  -h,  --help          show this message \n"
              << "  -c,  --color         specify output color\n";
}


int main(int argc, char* argv[])
{
    static struct option options[] = {
        {"color", required_argument, 0, 'c'},
        {"help",  no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };

    int opt;
    std::string colour = RESET;
    std::string output;
    
    while ((opt = getopt_long(argc, argv, "c:h", options, nullptr)) != -1)
    {
        switch (opt)
        {
            case 'c':
                colour = getColour(optarg);
                break;
            case 'h':
                printUsage();
                return 0;
            default:
                printUsage();
                return 1;
        }
    }


    for (int i = optind; i < argc; i++)
    {
        if (!output.empty()) output += " ";
        output += argv[i];
    }
    
    if (output.empty()) output = "y";

    std::string msg = colour + output + RESET + "\n";

    std::string buf;
    buf.reserve(4096);
    while (buf.size() <= 4096 - msg.size())
        buf += msg;

    for (;;)
        if (write(STDOUT_FILENO, buf.data(), buf.size()) == -1)
            return 1;
}
