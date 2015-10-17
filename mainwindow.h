/*
 * Copyright © 2015 nastys
 *
 * This file is part of Accend.
 * Accend is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Accend is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Accend.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_text_textChanged(const QString &arg1);

    void speak(QString voice);

    void on_voice_RP_clicked();

    void on_voice_USA_clicked();

    void on_voice_WM_clicked();

    void on_voice_NE_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
