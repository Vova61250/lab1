{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Worker.h\
#ifndef WORKER_H\
#define WORKER_H\
\
#include "Base.h"\
\
class Worker : public Base \{\
private:\
    std::string name;      // \uc0\u1060 \u1048 \u1054 \
    std::string position;  // \uc0\u1076 \u1086 \u1083 \u1078 \u1085 \u1086 \u1089 \u1090 \u1100 \
    double salary;         // \uc0\u1079 \u1072 \u1088 \u1087 \u1083 \u1072 \u1090 \u1072 \
    std::string address;   // \uc0\u1072 \u1076 \u1088 \u1077 \u1089  \u1087 \u1088 \u1086 \u1078 \u1080 \u1074 \u1072 \u1085 \u1080 \u1103 \
    std::string phone;     // \uc0\u1090 \u1077 \u1083 \u1077 \u1092 \u1086 \u1085 \
public:\
    Worker();\
    Worker(const std::string& name,\
           const std::string& position,\
           double salary,\
           const std::string& address,\
           const std::string& phone);\
    Worker(const Worker& other);\
    ~Worker() override;\
\
    void input() override;\
    void print() const override;\
    void save(std::ostream& out) const override;\
    void load(std::istream& in) override;\
    std::string getType() const override;\
\};\
\
#endif // WORKER_H\
}