#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>

//-------------------------- Enums --------------------------
enum class ProductType { GROCERY, ELECTRONICS, CLOTHING };
enum class ShippingSpeed { TWO_HOUR, ONE_DAY, TWO_DAY, STANDARD };

//------------------------ HttpRequest ----------------------

class HttpRequest {
    std::string method;
    std::string url;
    std::unordered_map<std::string, std::string> headers;
    std::unordered_map<std::string, std::string> queryParams;
    std::string body;

    HttpRequest(const std::string& method,
                const std::string& url,
                const std::unordered_map<std::string, std::string>& headers,
                const std::unordered_map<std::string, std::string>& queryParams,
                const std::string& body)
        : method(method), url(url), headers(headers), queryParams(queryParams), body(body) {}

public:
    void send() const {
        // Simulate sending the HTTP Request
        std::cout << "Sending " << method << " request to " << url << "\n";
        if (!queryParams.empty()) {
                std::cout << "Query Params:\n";
                for (const auto& kv : queryParams)
                std::cout << "  " << kv.first << "=" << kv.second << "\n";
        }

        if (!headers.empty()) {
            std::cout << "Headers:\n";
            for (const auto& kv : headers)
                std::cout << "  " << kv.first << ": " << kv.second << "\n";
        }

        if (!body.empty())
            std::cout << "Body: " << body << "\n";
    }
    friend class HttpRequestBuilder;
};


//--------------------- HttpRequestBuilder ------------------


class HttpRequestBuilder {
    std::string method;
    std::string url;
    std::unordered_map<std::string, std::string> headers;
    std::unordered_map<std::string, std::string> queryParams;
    std::string body;
public:
    HttpRequestBuilder& setMethod(const std::string& method) {
        this->method = method;
        return *this;
    }

    HttpRequestBuilder& setUrl(const std::string& url) {
        this->url = url;
        return *this;
    }

    HttpRequestBuilder& addHeader(const std::string& key, const std::string& value) {
        headers[key] = value;
        return *this;
    }

    HttpRequestBuilder& addQueryParam(const std::string& key, const std::string& value) {
        queryParams[key] = value;
        return *this;
    }

    HttpRequestBuilder& setBody(const std::string& body) {
        this->body = body;
        return *this;
    }

    HttpRequest build() const {
        // Here because of friend class, we can access private members of HttpRequest
        return HttpRequest(method, url, headers, queryParams, body);
    }
};