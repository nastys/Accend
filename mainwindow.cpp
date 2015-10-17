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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_text_textChanged(const QString &arg1)
{
    if(arg1=="")
    {
        ui->RP->setText("");
        ui->USA->setText("");
        ui->WM->setText("");
        ui->NE->setText("");
    }
    else
    {
        QProcess p1, p2, p3, p4;

        // Start the process
        p1.start("espeak -q --ipa -v en-uk-rp \""+arg1+"\"");
        p2.start("espeak -q --ipa -v en-us \""+arg1+"\"");
        p3.start("espeak -q --ipa -v en-wm \""+arg1+"\"");
        p4.start("espeak -q --ipa -v en-uk-north \""+arg1+"\"");

        // Wait for it to start
        if(!p1.waitForStarted())
            return;

        // Wait for it to start
        if(!p2.waitForStarted())
            return;

        // Wait for it to start
        if(!p3.waitForStarted())
            return;

        // Wait for it to start
        if(!p4.waitForStarted())
            return;

        // Continue reading the data until EOF reached
        QByteArray data1, data2, data3, data4;

        while(p1.waitForReadyRead())
            data1.append(p1.readAll());

        while(p2.waitForReadyRead())
            data2.append(p2.readAll());

        while(p3.waitForReadyRead())
            data3.append(p3.readAll());

        while(p4.waitForReadyRead())
            data4.append(p4.readAll());

        ui->RP->setText(data1);
        ui->USA->setText(data2);
        ui->WM->setText(data3);
        ui->NE->setText(data4);
    }
}

void MainWindow::speak(QString voice)
{
    QProcess p;

    // Start the process
    p.startDetached("espeak -v \""+voice+"\" \""+ui->text->text()+"\"");
}

void MainWindow::on_voice_RP_clicked()
{
    speak("en-uk-rp");
}

void MainWindow::on_voice_USA_clicked()
{
    speak("en-us");
}

void MainWindow::on_voice_WM_clicked()
{
    speak("en-wm");
}

void MainWindow::on_voice_NE_clicked()
{
    speak("en-uk-north");
}
