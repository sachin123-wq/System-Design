#include "HttpRequest.hpp"
class HttpRequestDirector {
public:
    HttpRequest createAuthGetRequest(const std::string& url, const std::string& token) {
        HttpRequestBuilder builder;
        return builder.setMethod("GET")
                      .setUrl(url)
                      .addHeader("Authorization", "Bearer " + token)
                      .addHeader("Accept", "application/json")
                      .build();
    }

    HttpRequest createJsonPostRequest(const std::string& url, const std::string& jsonBody) {
        HttpRequestBuilder builder;
        return builder.setMethod("POST")
                      .setUrl(url)
                      .addHeader("Content-Type", "application/json")
                      .setBody(jsonBody)
                      .build();
    }
};