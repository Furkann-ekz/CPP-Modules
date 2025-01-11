#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const string &target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target) {  }

ShrubberyCreationForm::~ShrubberyCreationForm() {  }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	string str = target + "_shrubbery";
	ofstream outputFile(str.c_str());

	if (outputFile)
	{
		outputFile << "                      ___" << endl;
		outputFile << "                _,-'\"\"   \"\"\"\"`--." << endl;
		outputFile << "             ,-'          __,,-- \\" << endl;
		outputFile << "           ,\'    __,--\"\"\"\"dF      )" << endl;
		outputFile << "          /   .-\"Hb_,--\"\"dF      /" << endl;
		outputFile << "        ,\'       _Hb ___dF\"-._,-'" << endl;
		outputFile << "      ,'      _,-\"\"\"\"   \"\"--..__" << endl;
		outputFile << "     (     ,-'                  `." << endl;
		outputFile << "      `._,'     _   _             ;" << endl;
		outputFile << "       ,'     ,' `-'Hb-.___..._,-'" << endl;
		outputFile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << endl;
		outputFile << "        `--\'   \"Hb  HH  dF\"" << endl;
		outputFile << "                \"Hb HH dF" << endl;
		outputFile << "                 \"HbHHdF" << endl;
		outputFile << "                  |HHHF" << endl;
		outputFile << "                  |HHH|" << endl;
		outputFile << "                  |HHH|" << endl;
		outputFile << "                  |HHH|" << endl;
		outputFile << "                  |HHH|" << endl;
		outputFile << "                  dHHHb" << endl;
		outputFile << "                .dFd|bHb.               o" << endl;
		outputFile << "      o       .dHFdH|HbTHb.          o /" << endl;
		outputFile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << endl;
		outputFile << "##########################################" << endl;
	}
	else
	{
		throw runtime_error("Failed to create shrubbery file for " + target + ".");
	}
	outputFile.close();
}
