//
// Created by gacova on 16/03/19.
//

#ifndef ABRIRTXT_CON_HANDLER_H
#define ABRIRTXT_CON_HANDLER_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "VerificadorPal.h"
#include "TrJSON.h"
#include "juego.h"
#include "Lista.h"
#include <thread>
#include <mutex>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

class con_handler: public boost::enable_shared_from_this<con_handler> {
public:
    typedef boost::shared_ptr<con_handler> pointer;
    con_handler(boost::asio::io_service& io_service): sock(io_service){}
    static pointer create(boost::asio::io_service& io_service);
    tcp::socket& socket();
    void start();
    void handle_read(const boost::system::error_code& err, size_t bytes_transferred);
    void handle_write(const boost::system::error_code& err, size_t bytes_transferred);
     void operaciones();

private:
    enum { max_length = 1024};
    tcp::socket sock;
    std::string message="no mando ";
    int buscarJuego(std::string codigo);
    bool palCheck;

    std::string data;


};


#endif //ABRIRTXT_CON_HANDLER_H
