#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

//g++ example.cpp -o example -lcurl  -ljsoncpp
/**
 * sudo apt install libcurl3 libcurl-openssl1.0-dev
 *
 *
 * :~$ sudo apt-get install libcurl-dev
:~$ sudo apt-get install libcurl4-openssl-dev
:~$ sudo apt-get install libcurl4-gnutls-dev
:~$ sudo apt-get install libjson-c-dev
:~$ sudo apt-get install libjsoncpp-dev
 */

void print_error()
{
    std::cerr << "ERRO! Número de parâmetros inválido, entre com 1 ou nenhum parâmetro" << std::endl;
}


static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string download_json()
{
    CURL *curl;
    CURLcode res;
    std::string read_buffer;
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return read_buffer;
}


void print_formatted_users()
{
    std::string json = download_json();
    std::istringstream iss(json);

    Json::Value root;
    iss >> root;

    for (auto node : root)
    {
        std::cout << "Id: " << node["id"] << std::endl;
        std::cout << "Name: " << node["name"] << std::endl;
        std::cout << "User name: " << node["username"] << std::endl;
        std::cout << "Email: " << node["email"] << std::endl;;

        Json::Value addr_node = node["address"];
        std::cout << "City: " << addr_node["city"] << std::endl;
        std::cout << "Street: " << addr_node["street"] << std::endl;
        std::cout << "Suite: " << addr_node["suite"] << std::endl;
        std::cout << "Zipcode: " << addr_node["zipcode"] << std::endl;

        Json::Value location = addr_node["geo"];
        std::cout << "Latitude: " << location["lat"] << std::endl;
        std::cout << "Longitude: " << location["lng"] << std::endl;

        std::cout << "Phone: " << node["phone"] << std::endl;
        std::cout << "Website: " << node["website"] << std::endl;

        Json::Value company_node = node["company"];
        std::cout << "Company name: " << company_node["name"] << std::endl;
        std::cout << "Catchphrase: " << company_node["catchPhrase"] << std::endl;
        std::cout << "BS: " << company_node["bs"] << std::endl;
        std::cout << std::endl;
    }
}


void print_formatted_posts(char *user_id)
{
    std::string json = download_json();
    std::istringstream iss(json);

    Json::Value root;
    iss >> root;

    

}


int main(int argc, char *argv[])
{
    switch (argc)
    {
        case 1:
        {
            try
            {
                print_formatted_users();
            }
            catch (std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }

            break;
        }
        case 2:
        {
            print_formatted_posts(argv[1]);
            break;
        }
        default:
        {
            print_error();
            return -1;
        }
    }

    return 0;
}
