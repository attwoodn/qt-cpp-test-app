#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
  class main_window; 
}

class main_window : public QMainWindow {
  Q_OBJECT

  public:
    explicit main_window(QWidget *parent = nullptr);
    ~main_window() override;

  public slots:
    void say_hello_button_clicked();
    void first_name_text_changed(QString);
    void last_name_text_changed(QString);
    void favorite_fruit_selection_changed(int);

    void process_ui_state_change();

  private:
    Ui::main_window *ui;
};

#endif // MAIN_WINDOW_H
