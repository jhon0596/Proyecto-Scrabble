//
// Created by gacova on 16/03/19.
//

#ifndef ABRIRTXT_CON_HANDLER_H
#define ABRIRTXT_CON_HANDLER_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#import "VerificadorPal.h"

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

class con_handler: public boost::enable_shared_from_this<con_handler> {
private:
    tcp::socket sock;
    std::string message;
    enum { max_length = 1024 };
    char data[max_length];
    bool palCheck;

public:
    typedef boost::shared_ptr<con_handler> pointer;
    con_handler(boost::asio::io_service& io_service): sock(io_service){}
// creating the pointer
    static pointer create(boost::asio::io_service& io_service);
    tcp::socket& socket();
    void start();
    void handle_read(const boost::system::error_code& err, size_t bytes_transferred);
    void handle_write(const boost::system::error_code& err, size_t bytes_transferred);
};


#endif //ABRIRTXT_CON_HANDLER_H
