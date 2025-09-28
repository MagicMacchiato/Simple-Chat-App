#include"logger.hpp"

Logger::Logger(const std::string& loggerName) : Logger(loggerName, LoggerLevel::info){}

Logger::Logger(const std::string& loggerName, const LoggerLevel loggerLevel){
    this->loggerName = loggerName;
    this->loggerLevel = loggerLevel;
}


void Logger::setLoggerLevel(const LoggerLevel loggerLevel){
    this->loggerLevel = loggerLevel;
}


//helper functions

void Logger::printLog(const std::string& message, const LoggerLevel LoggerLevel){
    if(loggerLevel >= this->loggerLevel){
        std::cout<<makeTimeStamp()<<" "<<getloggerNameTag()<<" "<<getLoggerLevelTag(loggerLevel)
        <<" "<<message<<std::endl;
    }
}


std::string Logger::getloggerNameTag(){
    std::ostringstream builder;
    builder<<"["<<this->loggerName<<"]";
    return builder.str();
}


std::string Logger::makeTimeStamp(){
    time_t time_stamp = time(NULL);
    struct tm* local_time = localtime(&time_stamp);
    char buff[70];
    int buff_len = sizeof(buff);

    strftime(buff, buff_len, "[%Y/%m/%d %H:%M:%S]", local_time);

    return buff;
}


std::string Logger::getLoggerLevelTag(const LoggerLevel LoggerLevel){
    switch(loggerLevel){
        case LoggerLevel::debug: return "[DEBUG]";
        case LoggerLevel::info: return "[INFO]";
        case LoggerLevel::warn: return "[WARN]";
        case LoggerLevel::error: return "[ERROR]";
        default: return "";
    }
}


std::string Logger::buildFormatString(std::string&& message){
    return message;
}