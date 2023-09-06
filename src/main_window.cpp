#include "main_window.hpp"
#include "ui_main_window.h"
#include <iostream>

main_window::main_window(QWidget *parent) 
  : QMainWindow(parent),
    ui(new Ui::main_window) {
  ui->setupUi(this);

  connect(ui->button_say_hello, SIGNAL(clicked()), this, SLOT(say_hello_button_clicked()));
  connect(ui->line_edit_first_name, SIGNAL(textChanged(QString)), this, SLOT(first_name_text_changed(QString)));
}

main_window::~main_window() {
  delete ui;
}

void main_window::say_hello_button_clicked() {
  std::cout << "hello button clicked!\n";
}

void main_window::first_name_text_changed(QString s) {
  std::cout << "first name text changed to \"" << s.toStdString() << "\"\n";
}
