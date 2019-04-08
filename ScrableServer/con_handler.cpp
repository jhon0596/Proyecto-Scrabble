//
// Created by gacova on 16/03/19.
//

#include "con_handler.h"

Lista<juego > lobby;
con_handler::pointer con_handler::create(boost::asio::io_service &io_service) {
    return pointer(new con_handler(io_service));
}

tcp::socket &con_handler::socket() {
    return sock;
}

void con_handler::start() {
    char dato[max_length];


    sock.async_read_some(
            boost::asio::buffer(dato, max_length),
            boost::bind(&con_handler::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));


    std::cout << dato<< std::endl;
    this->data =dato;
    operaciones();



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

void con_handler::operaciones() {


    TrJSON tr;
    tr.Json2cod(this->data);
    boost::property_tree::ptree pt2=tr.arb;
    int x[2];
    int y[2];
    int pos =0;

    for (auto i : as_vector<std::string>(pt2, "pos X")){  x[pos]=std::stoi(i); pos++;};
    pos=0;
    for (auto i : as_vector<std::string>(pt2, "pos Y")){  y[pos]=std::stoi(i); pos++;};


    if(lobby.getSize() == 0 ){

        juego j= juego(pt2.get<std::string>("codigo"));
        j.meterpalabra(x,y,pt2.get<std::string>("palabra"));

        lobby.add(j);

        this->message = tr.cod2json(j);

    }else{
        std::cout << "busca el juego"<<endl;

        juego j  = lobby[buscarJuego(pt2.get<std::string>("codigo"))];

         this->message = tr.cod2json(j);

    }





}

int con_handler::buscarJuego(std::string codigo) {
    int i = 0;
    while(i<lobby.getSize()){
        if(lobby[i].getCodigoEntrada()== codigo ){

            break;
        } else{i++;

            continue;}
    }


    return i;
}

template<typename T>
std::vector<T> con_handler::as_vector(boost::property_tree::ptree const &pt, const boost::property_tree::ptree::key_type &key) {
    std::vector<T> r;
    for (auto& item : pt.get_child(key))
        r.push_back(item.second.get_value<T>());
    return r;
}



