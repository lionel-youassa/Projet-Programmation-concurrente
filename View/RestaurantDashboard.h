#ifndef RESTAURANTDASHBOARD_H
#define RESTAURANTDASHBOARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMap>

class RestaurantDashboard : public QWidget {
    Q_OBJECT

public:
    explicit RestaurantDashboard(QWidget *parent = nullptr);

    // Méthode pour mettre à jour l’état des tables
    void updateTableState(int tableIndex, const QString &state);

    // Méthode pour mettre à jour l’état du personnel
    void updateStaffState(const QString &role, bool isActive);

    // Méthode pour mettre à jour l’état des machines
    void updateMachineState(const QString &machineName, bool isActive);

    // Méthode pour mettre à jour les statistiques
    void updateStatistics(int cleanDishes, int dirtyDishes, int pendingOrders);

private:
    // Widgets et données pour chaque section
    QMap<int, QPushButton *> tableButtons; // Boutons pour les tables
    QMap<QString, QPushButton *> staffButtons; // Boutons pour le personnel
    QMap<QString, QPushButton *> machineButtons; // Boutons pour les machines
    QLabel *cleanDishesLabel;
    QLabel *dirtyDishesLabel;
    QLabel *pendingOrdersLabel;

    // Méthodes privées pour créer les sections
    QWidget *createTableSection(int numTables);
    QWidget *createStaffSection();
    QWidget *createMachineSection();
    QWidget *createStatisticsSection();
};

#endif // RESTAURANTDASHBOARD_H
