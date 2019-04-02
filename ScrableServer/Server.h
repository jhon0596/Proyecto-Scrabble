//
// Created by gacova on 16/03/19.
//

#ifndef ABRIRTXT_SERVER_H
#define ABRIRTXT_SERVER_H
#include <boost/asio.hpp>
#include "con_handler.h"

using namespace boost::asio;
using ip::tcp;


class Server {
private:
    tcp::acceptor acceptor_;
    void start_accept();
public:
//constructor for accepting connection from client
    Server(boost::asio::io_service& io_service): acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234)){
        start_accept();
};
    void handle_accept(con_handler::pointer connection, const boost::system::error_code& err);
};


#endif //ABRIRTXT_SERVER_H
