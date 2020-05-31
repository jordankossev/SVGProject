#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>
#include <vector>

#include "Canvas.h"

const double EPSILON = 0.001;

/// <summary>
/// Checks if a char is a digit
/// </summary>
/// <param name="ch">Charachter to be checked</param>
///<returns>
/// \b *true*: if \b ch is a digit\n
/// \b *false*: else
///</returns>
bool isDigit(char);

/// <summary>
/// Checks if a string is convertible to int
/// </summary>
/// <param name="str">String to be checked</param>
///<returns>
/// \b *true*: if \b ch can be an integer value\n
/// \b *false*: else
///</returns>
bool isConvertibleToInt(const std::string&);

/// <summary>
/// Checks if a string is convertible to double
/// </summary>
/// <param name="str">String to be checked</param>
///<returns>
/// \b *true*: if \b ch can be an double value\n
/// \b *false*: else
///</returns>
bool isConvertibleToDouble(const std::string&);

/// <summary>
/// Trims the quotation marks from a string
/// </summary>
/// <param name="str">String to be trimmed</param>
void trimQuotationMarks(std::string& string);

/// \brief Given a tag and a string in SVG format, retrieves the value of the tag
/// <param name="tag">Tag the value of which is being retrieved</param>
/// <param name="str">Line from an SVG file</param>
/// <returns>
/// The value of the tag
/// </returns>
/// \attention The value is expected to be double
size_t retrieveDoubleTagValue(const std::string&, const std::string&);

/// \brief Given a tag and a string in SVG format, retrieves the value of the tag
/// <param name="tag">Tag the value of which is being retrieved</param>
/// <param name="str">Line from an SVG file</param>
/// <returns>
/// The value of the tag
/// </returns>
/// \attention The value is expected to be string
std::string retrieveStringTagValue(const std::string&, const std::string&);

/// \brief Split string into separate words
/// <returns>
/// Container with the words that were divide by spaces in \b str
/// </returns>
std::vector<std::string> splitStringByWhitespaces(const std::string&);

/// \brief Creates a figure based on input from a console command
/// <param name="input">Expected to be string with parameters from the 'create' command</param>
/// <returns>
/// Shape pointer to the new figure
/// </returns>
/// \details In order to determine what figure to create the figure to create the function ckeck the first word of the input.\n It should indicate the type of the figure
Shape* createFigure(const std::string&);

void displaySupportedCommands();

/// \brief Opens and loads info from a file
/// <param name="fileName">The name of the file</param>
/// <param name="canvas">The canvas that will contain the info</param>
/// <returns>
/// \b *true*: if opening and loading were successful\n
/// \b *false*: else
/// </returns>
bool OpenFile(const std::string&, Canvas&);

/// \brief Saves the info from canvas to file
/// <param name="fileName">The name of the file</param>
/// <param name="canvas">The canvas containing the info</param>
/// <returns>
/// \b *true*: if saving was successful\n
/// \b *false*: else
/// </returns>
bool SaveInFile(const std::string&, const Canvas&);

#endif // !_FUNCTIONS_H
