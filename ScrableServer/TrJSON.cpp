//
// Created by gacova on 27/03/19.
//

#include "TrJSON.h"


void TrJSON::Json2cod(std::string des) {
    boost::property_tree::ptree pt2;
    des.pop_back();
    std::istringstream is (des);
    boost::property_tree::read_json(is,pt2);
    this->arb= pt2;
}

std::string TrJSON::cod2json(juego &juego) {
    boost::property_tree::ptree arb;
    boost::property_tree::ptree matrix_node;
    arb.put("resultado",juego.getResultado());
    for (int i = 0; i < 15; i++)
    {
        boost::property_tree::ptree row;
        for (int j = 0; j < 15; j++)
        {
            // Create an unnamed value
            boost::property_tree::ptree cell;
            cell.put_value(juego.getMatriz(i,j));
            // Add the value to our row
            row.push_back(std::make_pair("", cell));
        }
        // Add the row to our matrix
        matrix_node.push_back(std::make_pair("", row));
    }
// Add the node to the root
    arb.add_child("matrix", matrix_node);



    std::ostringstream buf;
    boost::property_tree::write_json (buf, arb, false);
    std::string json = buf.str();
    return  json;
}
