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
    /**
     *@brief  convierte el serial del json recibido por el server y crea el ptree
     * @param serl json serializacdo
     * */
    void Json2cod(std::string serl);
    /**
     *@brief  convierte el ptree a json y luego serializa el json
     * @param serl json serializacdo
     * @return el json serializado para enviralo al cliente
     * */
    std::string cod2json(juego &juego);
private:

};


#endif //SCRABLESERVER_TRJSON_H
