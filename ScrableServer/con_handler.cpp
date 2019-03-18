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
    sock.async_read_some(
            boost::asio::buffer(data, max_length),
            boost::bind(&con_handler::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));

    palCheck= VerificadorPal::buscarPal(data);
    if (palCheck){
        message="palabra Encontrada" ;
    } else{message= "palabra NO Encontrada"; }





    sock.async_write_some(
            boost::asio::buffer(message, max_length),
            boost::bind(&con_handler::handle_write,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {
        std::cout << data << std::endl;
        //entra la logica


    } else {
        std::cerr << "error: " << err.message() << std::endl;
        sock.close();
    }
}

void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {
        cout << "Server sent Hello message!"<< endl;
        // entra Json

        if (palCheck){
            message="palabra Encontrada" ;
        } else{message= "palabra NO Encontrada"; }


    } else {
        std::cerr << "error: " << err.message() << endl;
        sock.close();
    }
}
