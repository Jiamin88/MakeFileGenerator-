#include <fstream>
#include <string>
#include <assert.h>
#include <iostream>
#include <ctype.h>

std::string filename("makefile.txt");
std::ofstream file_out;

void Output_Makefile_Details(std::string ss)
{
    file_out
        << "GCC = g++ -std=c++17 -pedantic-errors -Wall -Wextra" << std::endl
        << "FILE = " << ss << ".cpp" << std::endl
        << "OBJ = " << ss << ".o" << std::endl
        << "EXEC = " << ss << std::endl
        << std::endl
        << std::endl
        << "$(EXEC) : $(OBJ)"
        << std::endl
        << "\t"
        << "$(GCC) $(OBJ) -o $(EXEC)"
        << std::endl
        << std::endl
        << "$(OBJ) : $(FILE)"
        << std::endl
        << "\t"
        << "clear"
        << std::endl
        << "\t"
        << "$(GCC) -c $(FILE) -o $(OBJ)"
        << std::endl
        << std::endl
        << "#to clean files , type make clean"
        << std::endl
        << "clean :"
        << std::endl
        << "\t"
        << "rm -f $(OBJ) $(EXEC)"
        << std::endl;
}

void Output_File(std::string ss)
{

    file_out.open(filename, std::ofstream::out);
    assert(!file_out.fail());

    if (file_out.is_open())
    {
        Output_Makefile_Details(ss);
    }
    std::cout << "fresh makefile in the making ! " << std::endl;
    exit(1);
}

int main()
{
    std ::string File_Name = "";
    std ::string Name_Checked = "";
    std ::cout << "Enter .cpp file name:";
    std ::cin >> File_Name;

    for (char Check_Name : File_Name)
    {
        if (!isalpha(Check_Name) && !isdigit(Check_Name) && Check_Name != '_' && Check_Name != '-' && Check_Name != ' ' && Check_Name != '.')
        {
            std ::cout << "Your file name sucks man!";
            break;
        }
        else
        {
            if (Check_Name == '.')
            {
                break;
            }
            Name_Checked += Check_Name;
        }
    }

    Output_File(Name_Checked);
}