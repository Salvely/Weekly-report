// @file      html_writer.h
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#ifndef __HOMEWORK_3_H__
#define __HOMEWORK_3_H__

#include <array>
#include <string>
#include <tuple>
#include <vector>

namespace html_writer {

/**
 * @brief OpenDocument() will print to the standard output the begining of a
 * HTML5 file. This function should be called only once at the begining of your
 * test program.
 */
void OpenDocument();

/**
 * @brief CloseDocument() will close the HTML5 file, this function should be
 * called only once at the end of your test program.
 */
void CloseDocument();

/**
 * @brief To make your application look nicer, you could opt for providing a
 * stylesheet using CSS for your web application.
 *
 * @param stylesheet The path where the CSS file is located, typically
 * "<path>/style.css"
 */
void AddCSSStyle(const std::string& stylesheet);

/**
 * @brief This function adds a Title to your web application
 *
 * @param title The string containing the title, could be as long as you wish.
 */
void AddTitle(const std::string& title);

/**
 * @brief This will open a <body> clause in your web application.
 */
void OpenBody();

/**
 * @brief This will close a </body> clause in your web application.
 */
void CloseBody();

/**
 * @brief This will open a new row division for your application, make sure the
 * class "row" is defined in the CSS file(if any).
 */
void OpenRow();

/**
 * @brief This will close a  row division for your application, make sure you
 * only call this function after a OpenRow() call
 */
void CloseRow();

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
void AddImage(const std::string& img_path, float score, bool highlight = false);

}  // namespace html_writer

namespace image_browser {

/// Some Utility Name Types that will make the code more readable
using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

/**
 * @brief This function is in charge to add a full row in the web application, A
 * row consists always of 3 columns, each one contains one image with a given
 * score.
 *
 * @param row          A set with 3 images plus the score of each one.
 * @param first_row    If it's the very first row, the first image should be
 * highlighted.
 */
void AddFullRow(const ImageRow& row, bool first_row = false);

/**
 * @brief Create a Image Browser application, This function should be completely
 * self containded and should take all the necessary actions to create an image
 * web browser application.
 *
 * @param title      The title of the web application.
 * @param stylesheet The CSS style, if any.
 * @param rows       A set of ImageRow, with all the given images to show.
 */
void CreateImageBrowser(const std::string& title,
                        const std::string& stylesheet,
                        const std::vector<ImageRow>& rows);

}  // namespace image_browser

#endif
