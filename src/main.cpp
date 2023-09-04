#include <iostream>
#include <QApplication>
#include "main_window.hpp"

int main(int argc, char** argv ) {
    QApplication qapp(argc, argv);

    main_window window;
    window.show();

    return qapp.exec();
}