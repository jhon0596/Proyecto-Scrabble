//
// Created by gacova on 27/03/19.
//

#ifndef SCRABLESERVER_TRJSON_H
#define SCRABLESERVER_TRJSON_H

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
#include "juego.h"

class TrJSON {
public:
    boost::property_tree::ptree arb;
    void Json2cod(std::string des);
    std::string cod2json(juego &juego);
private:

};


#endif //SCRABLESERVER_TRJSON_H
