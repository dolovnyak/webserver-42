#pragma once

#include "Request.h"
#include "Response.h"

namespace Http {

struct HandleResult {
    std::shared_ptr<Request> handled_request;
    std::shared_ptr<Response> response;
};

class RequestHandler {
private:
    std::shared_ptr<Request> _request;

    std::shared_ptr<Location> _matched_location;

    std::string _content_type;

    bool _keep_alive;

public:
    RequestHandler(const std::shared_ptr<Request>& request);

    HandleResult Handle();

private:
    void HandleContentTypeHeader();

    void HandleContentLengthHeader();

    void HandleConnectionHeader();

    void HandleKeepAliveHeader();

    void HandleAcceptHeader();

    void HandleAcceptEncodingHeader();

    void HandleCookiesHeader();

    void HandleRouteLocation();

    void HandleAuthorizationHeader();

    void HandleHttpMethod();

    std::shared_ptr<Response> ProcessRequest();
};

}