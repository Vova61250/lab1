{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Base.h\
#ifndef BASE_H\
#define BASE_H\
\
#include <iostream>\
#include <string>\
\
class Base \{\
public:\
    Base();\
    Base(const Base& other);\
    virtual ~Base();\
\
    // \uc0\u1042 \u1074 \u1086 \u1076  \u1076 \u1072 \u1085 \u1085 \u1099 \u1093  \u1089  \u1082 \u1083 \u1072 \u1074 \u1080 \u1072 \u1090 \u1091 \u1088 \u1099 \
    virtual void input() = 0;\
\
    // \uc0\u1042 \u1099 \u1074 \u1086 \u1076  \u1076 \u1072 \u1085 \u1085 \u1099 \u1093  \u1085 \u1072  \u1101 \u1082 \u1088 \u1072 \u1085 \
    virtual void print() const = 0;\
\
    // \uc0\u1057 \u1086 \u1093 \u1088 \u1072 \u1085 \u1077 \u1085 \u1080 \u1077  \u1074  \u1087 \u1086 \u1090 \u1086 \u1082  (\u1092 \u1072 \u1081 \u1083 )\
    virtual void save(std::ostream& out) const = 0;\
\
    // \uc0\u1047 \u1072 \u1075 \u1088 \u1091 \u1079 \u1082 \u1072  \u1080 \u1079  \u1087 \u1086 \u1090 \u1086 \u1082 \u1072 \
    virtual void load(std::istream& in) = 0;\
\
    // \uc0\u1057 \u1090 \u1088 \u1086 \u1082 \u1072 -\u1090 \u1080 \u1087  \u1086 \u1073 \u1098 \u1077 \u1082 \u1090 \u1072  (Furniture, Worker, Machine)\
    virtual std::string getType() const = 0;\
\};\
\
#endif // BASE_H\
}