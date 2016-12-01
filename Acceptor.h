#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>
#include <vector>
#include "Service.h"
#include <QObject>

using namespace boost::asio;
using namespace std;

class Acceptor:public QObject {
    Q_OBJECT
public:
	Acceptor(io_service &ios);
    ip::tcp::endpoint PortNum();
	void onAccept(const boost::system::error_code&ec,
		std::shared_ptr<ip::tcp::socket> sock) ;
    void InitAccept();

signals:
    void PortOK(unsigned short);
    void col_clientchanged(int);
    void rezultready();
    void UpdateProcInWin(float);
public slots:
    void clientexit();
    void alldone();
    void UpdateProc(float);
private:
    int col_client =0;
	io_service& m_ios;
	ip::tcp::acceptor m_acceptor;
	ip::tcp::endpoint m_port;
};
