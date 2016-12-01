#pragma once
#include <boost/asio.hpp>
#include <thread>
#include <string>
#include <cstdlib>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#include "Factor.h"
#include "Acceptor.h"

using namespace boost::asio;
using namespace std;

class Server : public QObject {
    Q_OBJECT
public:
	Server();
	void Start();
	void Stop();
    Acceptor* get_acc();
    bool switchOn = false;

signals:

private:  
	std::unique_ptr<std::thread> m_thread;
	io_service m_ios;
	std::unique_ptr<Acceptor> acc;
};
