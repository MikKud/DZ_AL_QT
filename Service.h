#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <string>
#include <cstdlib>
#include <vector>
#include "Factor.h"
#include <QObject>

using namespace boost::asio;
using namespace std;
extern vector<int> control;
extern vector<mpz_class> rezult;

class Service:public QObject {
    Q_OBJECT
public:
    Service();
    Service(std::shared_ptr<ip::tcp::socket> _sock);

    void InitHandling();
    void OnSend(const boost::system::error_code& , size_t ,int);

    void StartRecieving(int) ;

    void OnRecieved(const boost::system::error_code&, size_t,
        std::shared_ptr<boost::asio::streambuf>,int);

    void stopHandling() ;
signals:
    void acceptError();
    void serverend();
    void ProcChanged(float);
private:
    std::shared_ptr <ip::tcp::socket> m_sock;
};
