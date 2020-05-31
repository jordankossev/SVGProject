#include <iostream>
#include <math.h>
#include <cassert>
#include <iomanip>

#include "Functions.h"

bool isDigit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	return false;
}

bool isConvertibleToInt(const std::string& str) {
	size_t length = str.length(), i = 0;

	if (str[0] == '-' || str[0] == '+') {
		i = 1;
	}

	for (i; i < length; i++) {
		if (!isDigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isConvertibleToDouble(const std::string& str) {
	size_t length = str.length(), pointsCount = 0, i = 0;

	if (str[0] == '-' || str[0] == '+') {
		i = 1;
	}

	for (i; i < length; i++) {
		if (!isDigit(str[i])) {
			if (str[i] == '.') {
				pointsCount++;
			}
			else {
				return false;
			}
		}
	}

	if (pointsCount > 1) {
		return false;
	}
	return true;
}

void trimQuotationMarks(std::string& string) {
	string.erase(0, 1); // initial quotes
	string.erase(string.length() - 1, 1); // endind quotes
}

size_t retrieveDoubleTagValue(const std::string& tag, const std::string& str) {
	std::string tagValue;
	size_t i = str.find(tag + "=\"") + tag.length() + 2;

	while (str[i] != '\"') {
		tagValue.push_back(str[i]);
		i++;
	}

	bool isConvertible = isConvertibleToDouble(tagValue);
	if (!isConvertible) {
		std::cout << "Incorrect "<< tag << " value!\n";
		assert(isConvertible);
	}
	return stod(tagValue);
}

std::string retrieveStringTagValue(const std::string& tag, const std::string& str) {
	std::string tagValue;
	size_t i = str.find(tag + "=\"") + tag.length() + 2;

	while (str[i] != '\"') {
		tagValue.push_back(str[i]);
		i++;
	}

	return tagValue;
}

std::vector<std::string> splitStringByWhitespaces(const std::string& str) {
	size_t i = 0, strLength = str.length();
	std::vector<std::string> decomposedStr;
	std::string token;

	while (i < strLength) {
		if (str[i] == ' ') {
			decomposedStr.push_back(token);
			token = "";
		}
		else {
			token.push_back(str[i]);
		}
		i++;
	}
	decomposedStr.push_back(token);

	return decomposedStr;
}

Shape* createFigure(const std::string& input) {
	std::vector<std::string> figureData = splitStringByWhitespaces(input);
	std::string figureName = figureData[0];
	bool areParametersDouble;

	if (!figureName.compare("rectangle") && figureData.size() == 6) {
		areParametersDouble = isConvertibleToDouble(figureData[1]) && isConvertibleToDouble(figureData[2])
						   && isConvertibleToDouble(figureData[3]) && isConvertibleToDouble(figureData[4]);
		if (!areParametersDouble) {
			return nullptr;
		}

		Point topLeft = Point(stod(figureData[1]), stod(figureData[2]));
		double width = stod(figureData[3]);
		double height = stod(figureData[4]);
		std::string fill = figureData[5];

		return new Rectangle(topLeft, fill, width, height);
	}

	if (!figureName.compare("circle") && figureData.size() == 5) {
		areParametersDouble = isConvertibleToDouble(figureData[1]) && isConvertibleToDouble(figureData[2])
						   && isConvertibleToDouble(figureData[3]);
		if (!areParametersDouble) {
			return nullptr;
		}

		Point center = Point(stod(figureData[1]), stod(figureData[2]));
		double radius = stod(figureData[3]);
		std::string fill = figureData[4];

		return new Circle(center, fill, radius);
	}

	if (!figureName.compare("line") && figureData.size() == 5) {
		areParametersDouble = isConvertibleToDouble(figureData[1]) && isConvertibleToDouble(figureData[2])
						   && isConvertibleToDouble(figureData[3]) && isConvertibleToDouble(figureData[4]);
		if (!areParametersDouble) {
			return nullptr;
		}

		Point start = Point(stod(figureData[1]), stod(figureData[2]));
		Point end = Point(stod(figureData[3]), stod(figureData[4]));

		return new Line(start, end);
	}

	return nullptr;
}

void displaySupportedCommands() {
	std::cout << "The app supports the following commands:\n";
	std::cout << std::setw(30) << std::left << "open <file>" << "open <file>\n";
	std::cout << std::setw(30) << std::left << "close" << "close the currently opened file\n";
	std::cout << std::setw(30) << std::left << "save" << "save changes to the currently opened file\n";
	std::cout << std::setw(30) << std::left << "saveas <file>" << "saves changes to <file>\n";
	std::cout << std::setw(30) << std::left << "print" << "print all figures\n";
	std::cout << std::setw(30) << std::left << "create" << "create new figure\n";
	std::cout << std::setw(30) << std::left << "erase <n>" << "erase figure <n>\n";
	std::cout << std::setw(30) << std::left << "translate <x> <y> <n>" << "perform translation with vector (x, y) on figure <n>\n";
	std::cout << std::setw(30) << std::left << "" << "translate all figures if <n> not specified\n";
	std::cout << std::setw(30) << std::left << "within <option>" << "print all figures within <option>\n";
	std::cout << std::setw(30) << std::left << "" << "<option> can be a circle or a rectangle\n";
	std::cout << std::setw(30) << std::left << "exit" << "exit the program\n";
}

bool OpenFile(const std::string& fileName, Canvas& canvas) {
	std::ifstream file(fileName, std::ios::in | std::ios::beg);
	if (!file) {
		std::ofstream outFile(fileName, std::ios::out);
		outFile.close();
		file.open(fileName, std::ios::in | std::ios::beg);
	}
	assert(file);
	if (!canvas.loadFromFile(file)) {
		file.close();
		return false;
	}
	file.close();
	return true;
}

bool SaveInFile(const std::string& fileName, const Canvas& canvas) {
	std::ofstream file(fileName, std::ios::out | std::ios::beg);
	assert(file);
	if (!canvas.saveChangesInFile(file)) {
		file.close();
		return false;
	}
	file.close();
	return true;
}