{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Keeper.h\
#ifndef KEEPER_H\
#define KEEPER_H\
\
#include "Base.h"\
#include "MyException.h"\
#include <string>\
\
class Keeper \{\
private:\
    struct Node \{\
        Base* data;\
        Node* next;\
    \};\
\
    Node* head;\
    int size;\
\
public:\
    Keeper();\
    ~Keeper();\
\
    void add(Base* obj);           // \uc0\u1076 \u1086 \u1073 \u1072 \u1074 \u1080 \u1090 \u1100  \u1086 \u1073 \u1098 \u1077 \u1082 \u1090 \
    void remove(int index);        // \uc0\u1091 \u1076 \u1072 \u1083 \u1080 \u1090 \u1100  \u1087 \u1086  \u1080 \u1085 \u1076 \u1077 \u1082 \u1089 \u1091 \
    void printAll() const;         // \uc0\u1074 \u1099 \u1074 \u1077 \u1089 \u1090 \u1080  \u1074 \u1089 \u1077  \u1086 \u1073 \u1098 \u1077 \u1082 \u1090 \u1099 \
    int getSize() const;           // \uc0\u1088 \u1072 \u1079 \u1084 \u1077 \u1088 \
\
    void clear();                  // \uc0\u1086 \u1095 \u1080 \u1089 \u1090 \u1080 \u1090 \u1100  \u1082 \u1086 \u1085 \u1090 \u1077 \u1081 \u1085 \u1077 \u1088 \
\
    void saveToFile(const std::string& filename) const;\
    void loadFromFile(const std::string& filename);\
\};\
\
#endif // KEEPER_H\
}