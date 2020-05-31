#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <cassert>

#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Canvas.h"
#include "Functions.h"

const size_t COMMAND_MAX_LENGTH = 6; // "saveas" is the longest one - 6 chars

int main() {
	std::string input, command, value, loadedFileName;
	Canvas canvas;
	bool isProgramRunning = true, isInfoLoaded = false;

	while (isProgramRunning) {
		std::getline(std::cin, input, '\n');
		if (input.length() > COMMAND_MAX_LENGTH) {
			size_t i = 0;
			while (input[i] != ' ') { // separating the command and its parameters
				i++;
			}
			command = input.substr(0, i);
			value = input.substr(i + 1);

			if (!command.compare("open")) {
				loadedFileName = value;
				if (!OpenFile(loadedFileName, canvas)) return 0;
				isInfoLoaded = true;
			}
			else if (!command.compare("saveas") && isInfoLoaded) {
				assert(SaveInFile(value, canvas)); // value holds the new file's name
				std::cout << "Successfully saved at " << value << std::endl;
			}
			else if (!command.compare("create") && isInfoLoaded) {
				Shape* newFigure = createFigure(value);
				if (!newFigure)	std::cout << "Wrong input data!\n";
				else canvas.addFigure(newFigure);
			}
			else if (!command.compare("erase") && isInfoLoaded) {
				if (isConvertibleToInt(value)) {
					size_t index = stoi(value);
					canvas.erase(index);
				}
				else {
					std::cout << "<n> must be a non-negative integer!\n";
				}
			}
			else if (!command.compare("translate") && isInfoLoaded) {
				std::vector<std::string> translationData = splitStringByWhitespaces(value);
				double deltaX = stod(translationData[0]), deltaY = stod(translationData[1]);

				if (translationData.size() == 2) {
					canvas.translate(deltaX, deltaY);
				}
				else if (translationData.size() == 3) {
					size_t index = stoi(translationData[2]);
					canvas.translate(deltaX, deltaY, index);
				}
				else {
					std::cout << "Wrong input data!\n";
				}
			}
			else if (!command.compare("within") && isInfoLoaded) {
				std::vector<std::string> regionData = splitStringByWhitespaces(value);
				if (regionData.size() == 5) {
					double x = stod(regionData[1]), y = stod(regionData[2]),
						   width = stod(regionData[3]), height = stod(regionData[4]);
					canvas.within(Rectangle(Point(x, y), "none", width, height));
				}
				else if (regionData.size() == 4) {
					double x = stod(regionData[1]), y = stod(regionData[2]), radius = stod(regionData[3]);
					canvas.within(Circle(Point(x, y), "none", radius));
				}
				else {
					std::cout << "Wrong input data\n";
				}

			}
			else {
				if (!isInfoLoaded) {
					std::cout << "There is no info loaded. Try opening a file.\n";
				}
				else {
					std::cout << "Error: Unsupported command!\n";
				}
			}
		}
		else {
			command = input;
			if (!command.compare("close") && isInfoLoaded) {
				isInfoLoaded = false;
			}
			else if (!command.compare("save") && isInfoLoaded) {
				assert(SaveInFile(loadedFileName, canvas));
				std::cout << "Successfully saved at " << loadedFileName << std::endl;
			}
			else if (!command.compare("print") && isInfoLoaded) {
				canvas.print();
			}
			else if (!command.compare("help")) {
				displaySupportedCommands();
			}
			else if (!command.compare("exit")) {
				isProgramRunning = false;
			}
			else {
				if (!isInfoLoaded) {
					std::cout << "There is no info loaded. Try opening a file.\n";
				}
				else {
					std::cout << "Error: Unsupported command!\n";
				}
			}
		}
	}
}