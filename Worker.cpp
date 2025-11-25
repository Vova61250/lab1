{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Worker.cpp\
#include "Worker.h"\
#include <iostream>\
#include <limits>\
\
Worker::Worker()\
        : name("Unknown"), position("Unknown"), salary(0),\
          address("Unknown"), phone("Unknown") \{\
    std::cout << "Worker: default constructor\\n";\
\}\
\
Worker::Worker(const std::string& name,\
               const std::string& position,\
               double salary,\
               const std::string& address,\
               const std::string& phone)\
        : name(name), position(position), salary(salary),\
          address(address), phone(phone) \{\
    std::cout << "Worker: constructor with parameters\\n";\
\}\
\
Worker::Worker(const Worker& other)\
        : Base(other),\
          name(other.name),\
          position(other.position),\
          salary(other.salary),\
          address(other.address),\
          phone(other.phone) \{\
    std::cout << "Worker: copy constructor\\n";\
\}\
\
Worker::~Worker() \{\
    std::cout << "Worker: destructor\\n";\
\}\
\
void Worker::input() \{\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1060 \u1048 \u1054 : ";\
    std::getline(std::cin, name);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1076 \u1086 \u1083 \u1078 \u1085 \u1086 \u1089 \u1090 \u1100 : ";\
    std::getline(std::cin, position);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1079 \u1072 \u1088 \u1072 \u1073 \u1086 \u1090 \u1085 \u1091 \u1102  \u1087 \u1083 \u1072 \u1090 \u1091 : ";\
    std::cin >> salary;\
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1072 \u1076 \u1088 \u1077 \u1089  \u1087 \u1088 \u1086 \u1078 \u1080 \u1074 \u1072 \u1085 \u1080 \u1103 : ";\
    std::getline(std::cin, address);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1090 \u1077 \u1083 \u1077 \u1092 \u1086 \u1085 : ";\
    std::getline(std::cin, phone);\
\}\
\
void Worker::print() const \{\
    std::cout << "=== \uc0\u1056 \u1072 \u1073 \u1086 \u1090 \u1085 \u1080 \u1082  ===\\n";\
    std::cout << "\uc0\u1060 \u1048 \u1054 : " << name << "\\n";\
    std::cout << "\uc0\u1044 \u1086 \u1083 \u1078 \u1085 \u1086 \u1089 \u1090 \u1100 : " << position << "\\n";\
    std::cout << "\uc0\u1047 \u1072 \u1088 \u1087 \u1083 \u1072 \u1090 \u1072 : " << salary << "\\n";\
    std::cout << "\uc0\u1040 \u1076 \u1088 \u1077 \u1089 : " << address << "\\n";\
    std::cout << "\uc0\u1058 \u1077 \u1083 \u1077 \u1092 \u1086 \u1085 : " << phone << "\\n";\
\}\
\
void Worker::save(std::ostream& out) const \{\
    out << name << "\\n"\
        << position << "\\n"\
        << salary << "\\n"\
        << address << "\\n"\
        << phone << "\\n";\
\}\
\
void Worker::load(std::istream& in) \{\
    std::getline(in, name);\
    std::getline(in, position);\
    in >> salary;\
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
    std::getline(in, address);\
    std::getline(in, phone);\
\}\
\
std::string Worker::getType() const \{\
    return "Worker";\
\}\
}