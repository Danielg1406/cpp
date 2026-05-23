#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) return;
    ofs << "            / / /\n";
    ofs << "          /        /  /     //    /\n";
    ofs << "       /                 /         /  /\n";
    ofs << "                       /\n";
    ofs << "                      /                //\n";
    ofs << "      /          /            /              /\n";
    ofs << "      /            '/,        /               /\n";
    ofs << "      /              'b      *\n";
    ofs << "       /              '$    //                //\n";
    ofs << "      /    /           $:   /:               /\n";
    ofs << "    //      /  //      */  @):        /   / /\n";
    ofs << "                 /     :@,@):   ,/**:'   /\n";
    ofs << "     /      /,         :@@*: //**'      /   /\n";
    ofs << "              '/o/    /:(@'/@*\"'  /\n";
    ofs << "      /  /       'bq,//:,@@*'   ,*      /  /\n";
    ofs << "                 ,p$q8,:@)'  /p*'      /\n";
    ofs << "          /     '  / '@@Pp@@*'    /  /\n";
    ofs << "           /  / //    Y7'.'     /  /\n";
    ofs << "                     :@):.\n";
    ofs << "                    .:@:' .\n";
    ofs << "                  .::(@:.      -Sam Blumenstein-\n";
    ofs.close();
}