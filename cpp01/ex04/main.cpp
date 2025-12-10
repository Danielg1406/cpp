#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t found;

    if (s1.empty())
        return content;

    while (pos < content.length())
    {
        found = content.find(s1, pos);
        if (found == std::string::npos)
        {
            result.append(content, pos, content.length() - pos);
            break;
        }
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    // Open input file
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    // Read entire file content
    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += '\n';
    }
    infile.close();

    // Replace all occurrences
    std::string result = replaceAll(content, s1, s2);

    // Write to output file
    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file " << outfilename << std::endl;
        return 1;
    }

    outfile << result;
    outfile.close();

    std::cout << "File processed successfully: " << outfilename << std::endl;
    return 0;
}