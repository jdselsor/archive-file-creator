#include <iostream>
#include <fstream>
#include <string>

/*std::ofstream writeToBinary (std::ifstream, std::string);
void readFromBinary (std::ifstream);*/

void writeToBinary (std::string, std::ofstream&);

int main ()
{
    std::ofstream data ("data.dat", std::ios::out | std::ios::binary);
    writeToBinary("./files/items.json", data);

    return 0;
}

void writeToBinary (std::string writeFrom, std::ofstream& writeTo)
{
    std::ifstream from;
    std::string line;

    from.open(writeFrom);

    if (from.is_open() || writeTo)
    {
        while (std::getline(from, line))
        {
            std::cout << line << '\n';
            writeTo.write((char*) &line, sizeof(std::string));
        }

        from.close();
        writeTo.close();

        if (!writeTo.good())
        {
            std::cout << "Error occurred at writing time!" << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

// from is the file to write from. This should be plain text.
// from_path is the path to the from file.
/*std::ofstream writeToBinary (std::ifstream from, std::string from_path)
{
    std::ofstream data("game.eaf", std::ios::out | std::ios::binary);
    std::string line;

    from.open(from_path);

    if (from.is_open() || data)
    {
        while (std::getline (from, line))
        {
            std::cout << line << '\n';
            data.write((char*) &line, sizeof(std::string));
        }

        from.close();
        data.close();

        if (!data.good())
        {
            std::cout << "Error occurred at writing time!" << std::endl;
            //return nullptr;
        }
    }
    else
    {
        std::cout<< "Unable to open file" << std::endl;
        //return nullptr;
    }

    return data;
}*/