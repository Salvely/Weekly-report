#include "html_writer.hpp"

#include <fmt/core.h>

#include <cstdlib>
#include <experimental/filesystem>
// #include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

namespace html_writer {
/**
 * @brief OpenDocument() will print to the standard output the begining of a
 * HTML5 file. This function should be called only once at the begining of your
 * test program.
 */
void OpenDocument() {
    std::cout << "<!DOCTYPE html>" << std::endl;
    std::cout << "<html>" << std::endl;
}

/**
 * @brief CloseDocument() will close the HTML5 file, this function should be
 * called only once at the end of your test program.
 */
void CloseDocument() { std::cout << "</html>" << std::endl; }

/**
 * @brief To make your application look nicer, you could opt for providing a
 * stylesheet using CSS for your web application.
 *
 * @param stylesheet The path where the CSS file is located, typically
 * "<path>/style.css"
 */
void AddCSSStyle(const std::string& stylesheet) {
    std::cout << " <head>" << std::endl;
    std::cout << R"(  <link rel="stylesheet" type="text/css" href=")"
              << stylesheet << "style.css\" />" << std::endl;
    std::cout << " </head>" << std::endl;
}

/**
 * @brief This function adds a Title to your web application
 *
 * @param title The string containing the title, could be as long as you wish.
 */
void AddTitle(const std::string& title) {
    std::cout << " <title>" << title << "</title>" << std::endl;
}

/**
 * @brief This will open a <body> clause in your web application.
 */
void OpenBody() { std::cout << " <body>" << std::endl; }

/**
 * @brief This will close a </body> clause in your web application.
 */
void CloseBody() { std::cout << " </body>" << std::endl; }

/**
 * @brief This will open a new row division for your application, make sure the
 * class "row" is defined in the CSS file(if any).
 */
void OpenRow() { std::cout << "  <div class = \"row\">" << std::endl; }

/**
 * @brief This will close a  row division for your application, make sure you
 * only call this function after a OpenRow() call
 */
void CloseRow() { std::cout << "  </div>" << std::endl; }

/**
 * @brief This function will add a new image to your web application using the
 * <img src=""> clause. It also prints the score of the image and the name of
 * the image. If it happens to be the very first image you add to your web
 * application, then,  it should be highlighted.
 *
 * @param img_path  The path to the image [png, jpg]
 * @param score     The score of the given image
 * @param highlight In case to be the very first image, this must be true.
 */
void AddImage(const std::string& img_path, float score, bool highlight) {
    /**
     *  <div class="column">
         <h2>000100.png</h2>
        <img src="data/000100.png" />
        <p>score = 0.96</p>
        </div>
    * */

    if (highlight) {
        std::cout
                << R"(   <div class="column" style="border: 5px solid green;">)"
                << std::endl;
    } else {
        std::cout << R"(   <div class="column">)" << std::endl;
    }
    std::experimental::filesystem::v1::path p(img_path);
    if (p.extension() != ".png" && p.extension() != ".jpg") {
        std::cerr << "Image Extension Invalid!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "   <h2>" << p.filename().string() << "<h2>" << std::endl;
    std::cout << "   <img src=\"" << img_path << "\" />" << std::endl;
    std::cout << "   <p>";
    fmt::print("{:.2f}", score);
    std::cout << "</p>" << std::endl;
    std::cout << R"(   </div>)" << std::endl;
}

}  // namespace html_writer
