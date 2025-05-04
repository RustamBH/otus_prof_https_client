#include <gtest/gtest.h>
#include "../src/client.hpp"

using namespace https_client;

TEST(ClientTest, ConnectToServer) {
	net::io_context ioc;
	ssl::context ctx{ ssl::context::tlsv12_client };	
	
        ctx.set_default_verify_paths();
        ctx.set_verify_mode(ssl::verify_none); // verify_peer	

	https_client::HttpsClient client{ ioc, ctx };
	client.request("localhost", "4433", "/");   
	ioc.run();
	std::string response = client.get_response();		
        ASSERT_FALSE(response.empty();
}

TEST(ClientTest, HandleInvalidPath) {
	net::io_context ioc;
	ssl::context ctx{ ssl::context::tlsv12_client };	
        
	ctx.set_default_verify_paths();
        ctx.set_verify_mode(ssl::verify_none); // verify_peer		
	
	   
	https_client::HttpsClient client{ ioc, ctx };
	client.request("localhost", "4433", "/nonexistent");   
	ioc.run();
	std::string response = client.get_response();		
        ASSERT_TRUE(response.find("404 Not Found") != std::string::npos);
}
