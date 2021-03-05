//
// Created by loghin on 05.03.2021.
//

#ifndef TETRIS_UTIL_H
#define TETRIS_UTIL_H

#include <string>

class Util {
public:
    // Nu facem Util u; u.getStyle <- non static
    // facem Util::getStyle        <- static

    /**
     * @param primeste o cale relativa din resources
     *
     * resources
     *      button_styles
     *          button_type_1
     *              style.css
     *          button_type_2
     *
     *
     * getStyle("button_styles/button_type_1/style.css");
     *
     * @return
     */
    static std::string getStyle(std::string const &) noexcept;
};


#endif //TETRIS_UTIL_H
