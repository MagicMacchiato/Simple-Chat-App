#pragma once

#ifndef LOGGER_HPP

#define LOGGER_HPP

#include<iostream>
#include<sstream>
#include<string>
#include<ctime>

inline const std::string FORMAT_SPECIFIER = "{}";

enum LoggerLevel{
    debug,
    info,
    warn,
    error
};

class Logger{
    public:
        Logger(const std::string& loggerName);

        Logger(const std::string& loggerName, const LoggerLevel loggerLevel);

        template<typename... Args>
        void debug(const std::string& message, const Args&... args){
            std::string buff{message};
            ((buff = buildFormatString(std::forward<std::string>(buff), args)), ...);
            printLog(buff, LoggerLevel::debug);
        }

        template<typename... Args>
        void info(const std::string& message, const Args&... args){
            std::string buff{message};
            ((buff = buildFormatString(std::forward<std::string>(buff), args)), ...);
            printLog(buff, LoggerLevel::info);
        }

        template<typename... Args>
        void warn(const std::string& message, const Args&... args){
            std::string buff{message};
            ((buff = buildFormatString(std::forward<std::string>(buff), args)), ...);
            printLog(buff, LoggerLevel::warn);
        }

        template<typename... Args>
        void error(const std::string& message, const Args&... args){
            std::string buff{message};
            ((buff = buildFormatString(std::forward<std::string>(buff), args)), ...);
            printLog(buff, LoggerLevel::error);
        }

        void setLoggerLevel(const LoggerLevel loggerLevel);

    private:
        std::string loggerName;
        LoggerLevel loggerLevel;

        void printLog(const std::string& message, const LoggerLevel LoggerLevel);

        std::string makeTimeStamp();

        std::string getloggerNameTag();

        std::string getLoggerLevelTag(const LoggerLevel LoggerLevel);

        template<typename T>
        std::string buildFormatString(std::string&& message, const T& arg){
            std::ostringstream builder;
            std::string_view str_ref{message};
            auto specifier_pos = str_ref.find(FORMAT_SPECIFIER);

            if(specifier_pos != std::string::npos){
                builder<<str_ref.substr(0, specifier_pos)<<arg<<str_ref.substr(specifier_pos + 2);
            }


            return builder.str();
        }

        std::string buildFormatString(std::string&& message);

};


#endif