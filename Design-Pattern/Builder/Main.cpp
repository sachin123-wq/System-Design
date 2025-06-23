#include "HttpRequestDirector.hpp"

int main(){
    HttpRequestDirector director;
    HttpRequest getRequest = director.createAuthGetRequest("https://api.example.com/data", "abc123token");
    getRequest.send();

    HttpRequest postRequest = director.createJsonPostRequest(
        "https://api.example.com/users",
        R"({"name":"sachin","email":"sachin@example.com"})"
    );
    postRequest.send();
    return 0;
}