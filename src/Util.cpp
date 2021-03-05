//
// Created by loghin on 05.03.2021.
//

#include "Util.h"
#include <fstream>
#include <sstream> // bridge intre string-uri si stream-uri - stringstream

std::string Util::getStyle(const std::string & relativePath) noexcept {
    /**
     * projRoot
     *      * build *   <- exe
     *      resources   <- aici vrem
     *
     *
     *  path : "./../resources/<relativePath>"
     *
     *  . = dosarul curent
     *  .. = dosarul anterior
     */

    std::fstream file;
    std::stringstream bridgedContents;
//    std::string contents;

    file.open(std::string("./../resources/").append(relativePath), std::ios::in );

    bridgedContents << file.rdbuf(); // bagi tot fisierul
//    contents = bridgedContents.str(); // il facem string

    file.close();

//    return contents;
    return bridgedContents.str();
}
