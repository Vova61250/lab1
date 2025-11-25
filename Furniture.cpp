{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Furniture.cpp\
#include "Furniture.h"\
#include <iostream>\
\
Furniture::Furniture()\
        : type("Unknown"), height(0), width(0), depth(0),\
          color("Unknown"), material("Unknown"), price(0) \{\
    std::cout << "Furniture: default constructor\\n";\
\}\
\
Furniture::Furniture(const std::string& type,\
                     double height, double width, double depth,\
                     const std::string& color,\
                     const std::string& material,\
                     double price)\
        : type(type), height(height), width(width), depth(depth),\
          color(color), material(material), price(price) \{\
    std::cout << "Furniture: constructor with parameters\\n";\
\}\
\
Furniture::Furniture(const Furniture& other)\
        : Base(other),\
          type(other.type),\
          height(other.height),\
          width(other.width),\
          depth(other.depth),\
          color(other.color),\
          material(other.material),\
          price(other.price) \{\
    std::cout << "Furniture: copy constructor\\n";\
\}\
\
Furniture::~Furniture() \{\
    std::cout << "Furniture: destructor\\n";\
\}\
\
void Furniture::input() \{\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1090 \u1080 \u1087  \u1084 \u1077 \u1073 \u1077 \u1083 \u1080 : ";\
    std::getline(std::cin, type);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1074 \u1099 \u1089 \u1086 \u1090 \u1091 : ";\
    std::cin >> height;\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1096 \u1080 \u1088 \u1080 \u1085 \u1091 : ";\
    std::cin >> width;\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1075 \u1083 \u1091 \u1073 \u1080 \u1085 \u1091 : ";\
    std::cin >> depth;\
\
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1094 \u1074 \u1077 \u1090 : ";\
    std::getline(std::cin, color);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1084 \u1072 \u1090 \u1077 \u1088 \u1080 \u1072 \u1083 : ";\
    std::getline(std::cin, material);\
\
    std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1089 \u1090 \u1086 \u1080 \u1084 \u1086 \u1089 \u1090 \u1100 : ";\
    std::cin >> price;\
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\}\
\
void Furniture::print() const \{\
    std::cout << "=== \uc0\u1052 \u1077 \u1073 \u1077 \u1083 \u1100  ===\\n";\
    std::cout << "\uc0\u1058 \u1080 \u1087 : " << type << "\\n";\
    std::cout << "\uc0\u1043 \u1072 \u1073 \u1072 \u1088 \u1080 \u1090 \u1099  (\u1042  x \u1064  x \u1043 ): "\
              << height << " x " << width << " x " << depth << "\\n";\
    std::cout << "\uc0\u1062 \u1074 \u1077 \u1090 : " << color << "\\n";\
    std::cout << "\uc0\u1052 \u1072 \u1090 \u1077 \u1088 \u1080 \u1072 \u1083 : " << material << "\\n";\
    std::cout << "\uc0\u1057 \u1090 \u1086 \u1080 \u1084 \u1086 \u1089 \u1090 \u1100 : " << price << "\\n";\
\}\
\
void Furniture::save(std::ostream& out) const \{\
    // \uc0\u1060 \u1086 \u1088 \u1084 \u1072 \u1090 : type height width depth color material price\
    out << type << "\\n"\
        << height << " " << width << " " << depth << "\\n"\
        << color << "\\n"\
        << material << "\\n"\
        << price << "\\n";\
\}\
\
void Furniture::load(std::istream& in) \{\
    std::getline(in, type);\
    in >> height >> width >> depth;\
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
    std::getline(in, color);\
    std::getline(in, material);\
    in >> price;\
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\}\
\
std::string Furniture::getType() const \{\
    return "Furniture";\
\}\
}