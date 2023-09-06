#include "main_window.hpp"
#include "ui_main_window.h"
#include <iostream>

main_window::main_window(QWidget *parent) 
  : QMainWindow(parent),
    ui(new Ui::main_window) {
  ui->setupUi(this);

  connect(ui->button_say_hello, SIGNAL(clicked()), this, SLOT(say_hello_button_clicked()));

  // print out UI actions
  connect(ui->line_edit_first_name, SIGNAL(textChanged(QString)), this, SLOT(first_name_text_changed(QString)));
  connect(ui->line_edit_last_name, SIGNAL(textChanged(QString)), this, SLOT(last_name_text_changed(QString)));
  connect(ui->combo_box_favorite_fruit, SIGNAL(currentIndexChanged(int)), this, SLOT(favorite_fruit_selection_changed(int)));

  // UI state changes that effect other UI elements
  connect(ui->line_edit_first_name, SIGNAL(textChanged(QString)), this, SLOT(process_ui_state_change()));
  connect(ui->line_edit_last_name, SIGNAL(textChanged(QString)), this, SLOT(process_ui_state_change()));
  connect(ui->combo_box_favorite_fruit, SIGNAL(currentIndexChanged(int)), this, SLOT(process_ui_state_change()));
}

main_window::~main_window() {
  delete ui;
}

void main_window::process_ui_state_change() {
  bool first_name_invalid = ui->line_edit_first_name->text().isEmpty();
  bool last_name_invalid = ui->line_edit_last_name->text().isEmpty();
  bool selected_fruit_invalid = ui->combo_box_favorite_fruit->currentIndex() == 0;

  ui->button_say_hello->setDisabled(first_name_invalid || last_name_invalid || selected_fruit_invalid);
}

void main_window::say_hello_button_clicked() {
  std::cout << "hello button clicked!\n";

  std::string full_name = ui->line_edit_first_name->text().toStdString() + " " + ui->line_edit_last_name->text().toStdString();
  std::string favorite_fruit = ui->combo_box_favorite_fruit->currentText().toLower().toStdString();

  std::string msg = "Hello, " + full_name + "! Your favorite fruit are " + favorite_fruit + ", huh? Good choice!";
  ui->text_browser_output->setText(QString::fromStdString(msg));
}

void main_window::first_name_text_changed(QString s) {
  std::cout << "first name text changed to \"" << s.toStdString() << "\"\n";
}

void main_window::last_name_text_changed(QString s) {
  std::cout << "last name text changed to \"" << s.toStdString() << "\"\n";
}

void main_window::favorite_fruit_selection_changed(int index) {
  std::cout << "favorite fruit changed to index " << index << "\n";
}
