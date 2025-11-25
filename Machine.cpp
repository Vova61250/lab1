{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Machine.cpp\
#include "Machine.h"\
#include <iostream>\
#include <limits>\
\
Machine::Machine()\
        : brand("Unknown"), model("Unknown"), plate("Unknown") \{\
    std::cout << "Machine: default constructor\\n";\
\}\
\
Machine::Machine(const std::string& brand,\
                 const std::string& model,\
                 const std::string& plate)\
        : brand(brand), model(model), plate(plate) \{\
    std::cout << "Machine: constructor with parameters\\n";\
\}\
\
Machine::Machine(const Machine& other)\
        : Base(other),\
          brand(other.brand),\
          model(other.model),\
          plate(other.plate) \{\
    std::cout << "Machine: copy constructor\\n";\
\}\
\
Machine::~Machine() \{\
    std::cout << "Machine: destructor\\n";\
\}\
\
void Machine::input() \{\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1084 \u1072 \u1088 \u1082 \u1091 : ";\
    std::getline(std::cin, brand);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1084 \u1086 \u1076 \u1077 \u1083 \u1100 : ";\
    std::getline(std::cin, model);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1075 \u1086 \u1089 . \u1085 \u1086 \u1084 \u1077 \u1088 : ";\
    std::getline(std::cin, plate);\
\}\
\
void Machine::print() const \{\
    std::cout << "=== \uc0\u1052 \u1072 \u1096 \u1080 \u1085 \u1072  ===\\n";\
    std::cout << "\uc0\u1052 \u1072 \u1088 \u1082 \u1072 : " << brand << "\\n";\
    std::cout << "\uc0\u1052 \u1086 \u1076 \u1077 \u1083 \u1100 : " << model << "\\n";\
    std::cout << "\uc0\u1043 \u1086 \u1089 . \u1085 \u1086 \u1084 \u1077 \u1088 : " << plate << "\\n";\
\}\
\
void Machine::save(std::ostream& out) const \{\
    out << brand << "\\n"\
        << model << "\\n"\
        << plate << "\\n";\
\}\
\
void Machine::load(std::istream& in) \{\
    std::getline(in, brand);\
    std::getline(in, model);\
    std::getline(in, plate);\
\}\
\
std::string Machine::getType() const \{\
    return "Machine";\
\}\
}