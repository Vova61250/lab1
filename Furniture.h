{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Furniture.h\
#ifndef FURNITURE_H\
#define FURNITURE_H\
\
#include "Base.h"\
\
class Furniture : public Base \{\
private:\
    std::string type;      // \uc0\u1090 \u1080 \u1087  \u1084 \u1077 \u1073 \u1077 \u1083 \u1080 \
    double height;         // \uc0\u1074 \u1099 \u1089 \u1086 \u1090 \u1072 \
    double width;          // \uc0\u1096 \u1080 \u1088 \u1080 \u1085 \u1072 \
    double depth;          // \uc0\u1075 \u1083 \u1091 \u1073 \u1080 \u1085 \u1072 \
    std::string color;     // \uc0\u1094 \u1074 \u1077 \u1090 \
    std::string material;  // \uc0\u1084 \u1072 \u1090 \u1077 \u1088 \u1080 \u1072 \u1083 \
    double price;          // \uc0\u1089 \u1090 \u1086 \u1080 \u1084 \u1086 \u1089 \u1090 \u1100 \
public:\
    Furniture();\
    Furniture(const std::string& type,\
              double height, double width, double depth,\
              const std::string& color,\
              const std::string& material,\
              double price);\
    Furniture(const Furniture& other);\
    ~Furniture() override;\
\
    void input() override;\
    void print() const override;\
    void save(std::ostream& out) const override;\
    void load(std::istream& in) override;\
    std::string getType() const override;\
\
    // \uc0\u1087 \u1088 \u1086 \u1089 \u1090 \u1099 \u1077  get/set \u1087 \u1088 \u1080  \u1078 \u1077 \u1083 \u1072 \u1085 \u1080 \u1080  \u1084 \u1086 \u1078 \u1085 \u1086  \u1076 \u1086 \u1073 \u1072 \u1074 \u1080 \u1090 \u1100 \
\};\
\
#endif // FURNITURE_H\
}