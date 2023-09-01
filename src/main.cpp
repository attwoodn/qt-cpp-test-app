#include <iostream>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char** argv ) {
    QApplication qapp(argc, argv);

    QMainWindow main_window;
    main_window.setWindowTitle(QString("Qt Test App"));
    main_window.setMinimumSize(200, 200);
    main_window.show();

    return qapp.exec();
}