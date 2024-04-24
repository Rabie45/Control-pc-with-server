#include "command.hpp"

std::string CMD::openCalc(){
    std::string result;
    FILE* fp = popen("gnome-calculator","r");
    if(!fp){
        return "faild";

    }
    char buffer[128];
    while ((fgets(buffer,sizeof(buffer),fp)) != nullptr){
        result += buffer;
        /* code */
    }
    pclose(fp);
    return result;
}

std::string CMD::openVScode(){
    std::string result;
    FILE* fp = popen("code","r");
    if(!fp){
        return "faild";

    }
    char buffer[128];
    while ((fgets(buffer,sizeof(buffer),fp)) != nullptr){
        result += buffer;
        /* code */
    }
    pclose(fp);
    return result;
}
std::string CMD::openBrowser(){
    std::string result;
    FILE* fp = popen("thorium-browser","r");
    if(!fp){
        return "faild";

    }
    char buffer[128];
    while ((fgets(buffer,sizeof(buffer),fp)) != nullptr){
        result += buffer;
        /* code */
    }
    pclose(fp);
    return result;
}