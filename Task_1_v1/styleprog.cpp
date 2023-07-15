#include "styleprog.h"

QString StyleProg::getStyleButton()
{
    return "QPushButton {"
               "color : #0d0;"
               "background-color: rgb(100, 100, 100);"
               "}"
               "QPushButton::hover {"
               "background-color: rgb(60, 60, 60);"
               "}";
}
