{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Keeper.cpp\
#include "Keeper.h"\
#include "Furniture.h"\
#include "Worker.h"\
#include "Machine.h"\
\
#include <fstream>\
#include <iostream>\
#include <limits>\
\
Keeper::Keeper() : head(nullptr), size(0) \{\
    std::cout << "Keeper: constructor\\n";\
\}\
\
Keeper::~Keeper() \{\
    std::cout << "Keeper: destructor\\n";\
    clear();\
\}\
\
void Keeper::add(Base* obj) \{\
    Node* node = new Node;\
    node->data = obj;\
    node->next = head;\
    head = node;\
    ++size;\
\}\
\
void Keeper::remove(int index) \{\
    if (index < 0 || index >= size) \{\
        throw MyException("\uc0\u1054 \u1096 \u1080 \u1073 \u1082 \u1072 : \u1085 \u1077 \u1074 \u1077 \u1088 \u1085 \u1099 \u1081  \u1080 \u1085 \u1076 \u1077 \u1082 \u1089  \u1087 \u1088 \u1080  \u1091 \u1076 \u1072 \u1083 \u1077 \u1085 \u1080 \u1080 ");\
    \}\
\
    Node* current = head;\
    Node* prev = nullptr;\
\
    for (int i = 0; i < index; ++i) \{\
        prev = current;\
        current = current->next;\
    \}\
\
    if (prev == nullptr) \{\
        head = current->next;\
    \} else \{\
        prev->next = current->next;\
    \}\
\
    delete current->data;\
    delete current;\
    --size;\
\}\
\
void Keeper::printAll() const \{\
    if (size == 0) \{\
        std::cout << "\uc0\u1050 \u1086 \u1085 \u1090 \u1077 \u1081 \u1085 \u1077 \u1088  \u1087 \u1091 \u1089 \u1090 .\\n";\
        return;\
    \}\
\
    Node* current = head;\
    int index = 0;\
    while (current != nullptr) \{\
        std::cout << "\\n[\uc0\u1048 \u1085 \u1076 \u1077 \u1082 \u1089  " << index << "] \u1058 \u1080 \u1087 : "\
                  << current->data->getType() << "\\n";\
        current->data->print();\
        current = current->next;\
        ++index;\
    \}\
\}\
\
int Keeper::getSize() const \{\
    return size;\
\}\
\
void Keeper::clear() \{\
    Node* current = head;\
    while (current != nullptr) \{\
        Node* next = current->next;\
        delete current->data;\
        delete current;\
        current = next;\
    \}\
    head = nullptr;\
    size = 0;\
\}\
\
void Keeper::saveToFile(const std::string& filename) const \{\
    std::ofstream out(filename);\
    if (!out.is_open()) \{\
        throw MyException("\uc0\u1053 \u1077  \u1091 \u1076 \u1072 \u1083 \u1086 \u1089 \u1100  \u1086 \u1090 \u1082 \u1088 \u1099 \u1090 \u1100  \u1092 \u1072 \u1081 \u1083  \u1076 \u1083 \u1103  \u1079 \u1072 \u1087 \u1080 \u1089 \u1080 ");\
    \}\
\
    out << size << "\\n";\
\
    Node* current = head;\
    while (current != nullptr) \{\
        out << current->data->getType() << "\\n";\
        current->data->save(out);\
        current = current->next;\
    \}\
\
    std::cout << "\uc0\u1044 \u1072 \u1085 \u1085 \u1099 \u1077  \u1089 \u1086 \u1093 \u1088 \u1072 \u1085 \u1077 \u1085 \u1099  \u1074  \u1092 \u1072 \u1081 \u1083 : " << filename << "\\n";\
\}\
\
void Keeper::loadFromFile(const std::string& filename) \{\
    std::ifstream in(filename);\
    if (!in.is_open()) \{\
        throw MyException("\uc0\u1053 \u1077  \u1091 \u1076 \u1072 \u1083 \u1086 \u1089 \u1100  \u1086 \u1090 \u1082 \u1088 \u1099 \u1090 \u1100  \u1092 \u1072 \u1081 \u1083  \u1076 \u1083 \u1103  \u1095 \u1090 \u1077 \u1085 \u1080 \u1103 ");\
    \}\
\
    clear();\
\
    int count = 0;\
    in >> count;\
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\
    for (int i = 0; i < count; ++i) \{\
        std::string type;\
        std::getline(in, type);\
\
        Base* obj = nullptr;\
\
        if (type == "Furniture") \{\
            obj = new Furniture();\
        \} else if (type == "Worker") \{\
            obj = new Worker();\
        \} else if (type == "Machine") \{\
            obj = new Machine();\
        \} else \{\
            throw MyException("\uc0\u1053 \u1077 \u1080 \u1079 \u1074 \u1077 \u1089 \u1090 \u1085 \u1099 \u1081  \u1090 \u1080 \u1087  \u1087 \u1088 \u1080  \u1079 \u1072 \u1075 \u1088 \u1091 \u1079 \u1082 \u1077 : " + type);\
        \}\
\
        obj->load(in);\
        add(obj);\
    \}\
\
    std::cout << "\uc0\u1044 \u1072 \u1085 \u1085 \u1099 \u1077  \u1079 \u1072 \u1075 \u1088 \u1091 \u1078 \u1077 \u1085 \u1099  \u1080 \u1079  \u1092 \u1072 \u1081 \u1083 \u1072 : " << filename << "\\n";\
\}\
}