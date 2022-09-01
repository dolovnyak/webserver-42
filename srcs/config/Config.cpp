#include "Config.h"

#include <utility>

namespace {
/// TODO delete when parse will finish
    std::vector<SharedPtr<ServerConfig> > mock_1_server_config() {
        std::vector<SharedPtr<ServerConfig> > configs;

        ServerConfig config(2222, "Kabun", "examples/aaaa/", std::vector<std::string>(), "index.html", 10, 300);
        configs.push_back(MakeShared(config));
        return configs;
    }

/// TODO delete
    std::vector<SharedPtr<ServerConfig> > mock_2_server_configs() {
        std::vector<SharedPtr<ServerConfig> > configs;

        ServerConfig config1(1337, "HelloWorld", "examples/hello_world/", std::vector<std::string>(), "index.html", 10, 300);
        configs.push_back(MakeShared(config1));

        std::vector<std::string> cgi_extensions;
        cgi_extensions.push_back(".py");
        cgi_extensions.push_back(".php");
        ServerConfig config2(1488, "CgiChecker", "examples/cgi_checker/", cgi_extensions, "index.html", 10, 300);

        configs.push_back(MakeShared(config2));
        return configs;
    }
}


bool Config::Load(const char* path) {
    /// TODO delete
    if (std::string(path) == "1") {
        max_sockets_number = 256;
        servers_configs = mock_1_server_config();
        return true;
    }
    else if (std::string(path) == "2") {
        max_sockets_number = 128;
        servers_configs = mock_2_server_configs();
        return true;
    }
    else {
        /// TODO(Jeka) fill servers_configs from json
    }
    return false;
}

ServerConfig::ServerConfig(int port, const std::string& name, const std::string& root_path,
                           const std::vector<std::string>& cgi_file_extensions,
                           const std::string& default_file_name,
                           int default_keep_alive_timeout,
                           int max_keep_alive_timeout)
        : port(port), name(name), root_path(root_path), cgi_file_extensions(cgi_file_extensions),
          default_file_name(default_file_name), default_keep_alive_timeout(default_keep_alive_timeout),
          max_keep_alive_timeout(max_keep_alive_timeout) {}
