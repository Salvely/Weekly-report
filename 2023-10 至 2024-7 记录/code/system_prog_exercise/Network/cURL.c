#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;   // use to send HTTP request
    CURLcode res; // used to store the result of HTTP request

    // init curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    // init curl handle
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "www.example.com");
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}