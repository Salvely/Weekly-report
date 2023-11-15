#include "image_browser.hpp"

#include <experimental/filesystem>

#include "html_writer.hpp"

using namespace html_writer;

namespace image_browser {
void AddFullRow(const ImageRow& row, bool first_row) {
    OpenRow();

    AddImage(std::get<0>(row[0]), std::get<1>(row[0]), first_row);
    AddImage(std::get<0>(row[1]), std::get<1>(row[1]));
    AddImage(std::get<0>(row[2]), std::get<1>(row[2]));

    CloseRow();
}

void CreateImageBrowser(const std::string& title,
                        const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
    OpenDocument();
    AddTitle("Image Browser");
    AddCSSStyle("");
    OpenBody();

    int i = 1;
    for (auto row : rows) {
        if (i == 1) {
            AddFullRow(row, true);
        } else {
            AddFullRow(row, false);
        }
        i += 1;
    }

    CloseBody();
    CloseDocument();
}
}  // namespace image_browser