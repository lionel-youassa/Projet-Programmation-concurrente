//
// Created by Emma on 12/12/2024.
//
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "TaskManager.h"
// class TaskManager : public QObject {
//     Q_OBJECT
//
// public:
//     explicit TaskManager(QObject* parent = nullptr) : QObject(parent) {}
//
//     void start() {
//         // Commencer par la première tâche
//         executeTask1();
//     }
//
//     signals:
//         void task1Finished();
//     void task2Finished();
//     void task3Finished();
//
//     public slots:
//         void executeTask1() {
//         qDebug() << "Tâche 1 commence";
//         QTimer::singleShot(2000, this, [this]() {
//             qDebug() << "Tâche 1 terminée";
//             emit task1Finished(); // Signal que la tâche 1 est terminée
//         });
//     }
//
//     void executeTask2() {
//         qDebug() << "Tâche 2 commence";
//         QTimer::singleShot(3000, this, [this]() {
//             qDebug() << "Tâche 2 terminée";
//             emit task2Finished(); // Signal que la tâche 2 est terminée
//         });
//     }
//
//     void executeTask3() {
//         qDebug() << "Tâche 3 commence";
//         QTimer::singleShot(1000, this, [this]() {
//             qDebug() << "Tâche 3 terminée";
//             emit task3Finished(); // Signal que la tâche 3 est terminée
//         });
//     }
// };
