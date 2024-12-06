#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QScrollArea>
#include <QPixmap>
#include <cmath>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget* createRangeTable(int numChairs, int numTables);
    QWidget* createImageWidget(const QString &imagePath, int width, int height);
    void insertPng(const std::string &pngPath, QWidget *parent, int ax, int ay, int aw, int ah);
};

#endif // MAINWINDOW_H
