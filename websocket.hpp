#include <boost/beast/websocket.hpp>
#include <boost/beast/core.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
//#if defined(BOOST_ASIO_HAS_CO_AWAIT)

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


using stream = websocket::stream<
        typename beast::tcp_stream::rebind_executor<
            typename net::use_awaitable_t<>::executor_with_default<net::any_io_executor>>::other>;

void handleWebSocketConnection(beast::websocket::stream<tcp::socket> ws);