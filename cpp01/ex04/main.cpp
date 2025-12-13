#include <iostream>
#include <string>
#include <fstream>

void myReplaceStr(std::string &line, size_t pos, size_t len, const std::string &replacement)
{
  line.erase(pos, len);
  line.insert(pos, replacement);
}

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cerr << "Error! Usage: <filename> <string1> <sting2>" << std::endl;
    return 1;
  }
  // Open file
  std::string fileName = argv[1];
  std::ifstream inputStream(fileName.c_str());
  if (!inputStream)
  {
    std::cerr << "Can't open input file" << std::endl;
    return 1;
  }
  std::string replaceFileName = fileName + ".replace";
  std::ofstream replaceFile(replaceFileName.c_str());
  if (!replaceFile)
  {
    std::cerr << "Could not create file" << std::endl;
    return 1;
  }
  if (inputStream && replaceFile)
  {
    // Read file
    std::string line;
    while(getline (inputStream, line))
    {
      // Replace str1 for str2
      std::string str1 = argv[2];
      std::string str2 = argv[3];
      size_t pos = line.find(str1);
      while (pos != std::string::npos)
      {
        myReplaceStr(line, pos, str1.size(), str2);
        pos = line.find(str1, pos + str2.size());
      }
      replaceFile << line << std::endl;
    }
  }
  inputStream.close();
  replaceFile.close();
  return 0;
}