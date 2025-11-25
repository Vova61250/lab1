{\rtf1\ansi\ansicpg1251\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // main.cpp\
#include <iostream>\
#include <limits>\
\
#include "Keeper.h"\
#include "Furniture.h"\
#include "Worker.h"\
#include "Machine.h"\
#include "MyException.h"\
\
int main() \{\
    setlocale(LC_ALL, "Russian");\
\
    Keeper keeper;\
\
    while (true) \{\
        std::cout << "\\n===== \uc0\u1052 \u1045 \u1053 \u1070  \u1060 \u1040 \u1041 \u1056 \u1048 \u1050 \u1048  =====\\n";\
        std::cout << "1. \uc0\u1044 \u1086 \u1073 \u1072 \u1074 \u1080 \u1090 \u1100  \u1084 \u1077 \u1073 \u1077 \u1083 \u1100 \\n";\
        std::cout << "2. \uc0\u1044 \u1086 \u1073 \u1072 \u1074 \u1080 \u1090 \u1100  \u1088 \u1072 \u1073 \u1086 \u1090 \u1085 \u1080 \u1082 \u1072 \\n";\
        std::cout << "3. \uc0\u1044 \u1086 \u1073 \u1072 \u1074 \u1080 \u1090 \u1100  \u1084 \u1072 \u1096 \u1080 \u1085 \u1091 \\n";\
        std::cout << "4. \uc0\u1055 \u1086 \u1082 \u1072 \u1079 \u1072 \u1090 \u1100  \u1074 \u1089 \u1077  \u1086 \u1073 \u1098 \u1077 \u1082 \u1090 \u1099 \\n";\
        std::cout << "5. \uc0\u1059 \u1076 \u1072 \u1083 \u1080 \u1090 \u1100  \u1086 \u1073 \u1098 \u1077 \u1082 \u1090  \u1087 \u1086  \u1080 \u1085 \u1076 \u1077 \u1082 \u1089 \u1091 \\n";\
        std::cout << "6. \uc0\u1057 \u1086 \u1093 \u1088 \u1072 \u1085 \u1080 \u1090 \u1100  \u1074  \u1092 \u1072 \u1081 \u1083 \\n";\
        std::cout << "7. \uc0\u1047 \u1072 \u1075 \u1088 \u1091 \u1079 \u1080 \u1090 \u1100  \u1080 \u1079  \u1092 \u1072 \u1081 \u1083 \u1072 \\n";\
        std::cout << "0. \uc0\u1042 \u1099 \u1093 \u1086 \u1076 \\n";\
        std::cout << "\uc0\u1042 \u1099 \u1073 \u1077 \u1088 \u1080 \u1090 \u1077  \u1087 \u1091 \u1085 \u1082 \u1090 : ";\
\
        int choice;\
        std::cin >> choice;\
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
\
        try \{\
            if (choice == 0) \{\
                std::cout << "\uc0\u1042 \u1099 \u1093 \u1086 \u1076  \u1080 \u1079  \u1087 \u1088 \u1086 \u1075 \u1088 \u1072 \u1084 \u1084 \u1099 ...\\n";\
                break;\
            \} else if (choice == 1) \{\
                Base* obj = new Furniture();\
                obj->input();\
                keeper.add(obj);\
            \} else if (choice == 2) \{\
                Base* obj = new Worker();\
                obj->input();\
                keeper.add(obj);\
            \} else if (choice == 3) \{\
                Base* obj = new Machine();\
                obj->input();\
                keeper.add(obj);\
            \} else if (choice == 4) \{\
                keeper.printAll();\
            \} else if (choice == 5) \{\
                std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1080 \u1085 \u1076 \u1077 \u1082 \u1089  \u1076 \u1083 \u1103  \u1091 \u1076 \u1072 \u1083 \u1077 \u1085 \u1080 \u1103  (0.." << keeper.getSize()-1 << "): ";\
                int idx;\
                std::cin >> idx;\
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\
                keeper.remove(idx);\
            \} else if (choice == 6) \{\
                std::string filename;\
                std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1080 \u1084 \u1103  \u1092 \u1072 \u1081 \u1083 \u1072  \u1076 \u1083 \u1103  \u1089 \u1086 \u1093 \u1088 \u1072 \u1085 \u1077 \u1085 \u1080 \u1103 : ";\
                std::getline(std::cin, filename);\
                keeper.saveToFile(filename);\
            \} else if (choice == 7) \{\
                std::string filename;\
                std::cout << "\uc0\u1042 \u1074 \u1077 \u1076 \u1080 \u1090 \u1077  \u1080 \u1084 \u1103  \u1092 \u1072 \u1081 \u1083 \u1072  \u1076 \u1083 \u1103  \u1079 \u1072 \u1075 \u1088 \u1091 \u1079 \u1082 \u1080 : ";\
                std::getline(std::cin, filename);\
                keeper.loadFromFile(filename);\
            \} else \{\
                std::cout << "\uc0\u1053 \u1077 \u1074 \u1077 \u1088 \u1085 \u1099 \u1081  \u1087 \u1091 \u1085 \u1082 \u1090  \u1084 \u1077 \u1085 \u1102 , \u1087 \u1086 \u1087 \u1088 \u1086 \u1073 \u1091 \u1081 \u1090 \u1077  \u1077 \u1097 \u1105  \u1088 \u1072 \u1079 .\\n";\
            \}\
        \} catch (const MyException& ex) \{\
            std::cout << "\uc0\u1048 \u1089 \u1082 \u1083 \u1102 \u1095 \u1077 \u1085 \u1080 \u1077 : " << ex.what() << "\\n";\
        \} catch (const std::exception& ex) \{\
            std::cout << "\uc0\u1057 \u1090 \u1072 \u1085 \u1076 \u1072 \u1088 \u1090 \u1085 \u1086 \u1077  \u1080 \u1089 \u1082 \u1083 \u1102 \u1095 \u1077 \u1085 \u1080 \u1077 : " << ex.what() << "\\n";\
        \}\
    \}\
\
    return 0;\
\}\
}