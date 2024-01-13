//
// Created by Clément Desavis on 12/01/2024.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <cstdarg>


class Logger {

public:

    enum TraceLevel {
        DEBUG = 0,
        INFO,
        WARNING,
        ERROR,
    };

    static void Log(TraceLevel level, const char* message, va_list args);
    static void Debug(const char* message);
    static void Info(const char* message);
    static void Warning(const char* message);
    static void Error(const char* message);

};



#endif //LOGGER_H
