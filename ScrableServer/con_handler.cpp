//
// Created by gacova on 16/03/19.
//

#include "con_handler.h"


con_handler::pointer con_handler::create(boost::asio::io_service &io_service) {
    return pointer(new con_handler(io_service));
}

tcp::socket &con_handler::socket() {
    return sock;
}

void con_handler::start() {
    char dato[max_length];
    char dato[max_length];
    //cout << dato<<endl;
    sock.async_read_some(
            boost::asio::buffer(dato, max_length),
            boost::bind(&con_handler::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));




    operaciones(dato);


    sock.async_write_some(
            boost::asio::buffer(this->message, max_length),
            boost::bind(&con_handler::handle_write,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {

    } else {
        std::cerr << "error: " << err.message() << std::endl;
        //sock.close();
    }
}

void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {

    } else {
        std::cerr << "error: " << err.message() << endl;
       // sock.close();
    }
}

void con_handler::operaciones(char *dato) {

TrJSON tr;
    tr.Json2cod(dato);
    boost::property_tree::ptree pt2=tr.arb;

    std::string g = pt2.get<std::string>("codigo");

    if(lobby.getSize() == 0 ){
        std::cout << "creo un nuevo juego";
        juego j= juego(pt2.get<std::string>("palabra"),pt2.get<std::string>("codigo"));
        lobby.add(&j);
        this->message = tr.cod2json(j);
    }else{
        std::cout << "busca el juego";
        //search(g)
    }






}

