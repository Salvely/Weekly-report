#include <iostream>

#include "html_writer.hpp"
#include "image_browser.hpp"

using namespace html_writer;
using namespace image_browser;

int main() {
    // OpenDocument();
    // AddTitle("Image Browser");
    // AddCSSStyle("");
    // OpenBody();

    // OpenRow();
    // html_writer::AddImage("../web_app/data/000000.png", 0.98, true);
    // CloseRow();

    // OpenRow();
    // CloseRow();

    // OpenRow();
    // CloseRow();

    // OpenRow();
    // CloseRow();
    // CloseBody();
    // CloseDocument();
    ImageRow row;
    row[0] = {"./data/000000.png", 0.98};
    row[1] = {"./data/000100.png", 0.96};
    row[2] = {"./data/000200.png", 0.88};
    std::vector<ImageRow> rows = {row};
    CreateImageBrowser("Image Browser", "../web_app/", rows);
    return 0;
}