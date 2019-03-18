#include <iostream>
#include <boost/asio.hpp>
#import "VerificadorPal.h"
#import "Server.h"


using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;



int main() {
    try
    {
        boost::asio::io_service io_service;
        Server server(io_service);
        io_service.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << endl;
    }

    return 0;
}