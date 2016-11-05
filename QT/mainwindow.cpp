#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

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

/**
 * @brief MainWindow::on_comboBox_TeamInfo_currentIndexChanged
 * @param index
 */
void MainWindow::on_comboBox_TeamInfo_currentIndexChanged(int index)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    switch(index)
    {
        /* index == 0 -> List of all Teams */
    case 0:
        model->setQuery("SELECT TEAM_NAME AS \'Team Name\' FROM STADIUM ORDER BY TEAM_NAME;", *Database::getInstance());
        break;

        /* index == 1 -> List of all Stadiums */
    case 1:
        model->setQuery("SELECT STADIUM_NAME AS \'Stadium\', TEAM_NAME AS \'Team Name\' FROM STADIUM ORDER BY TEAM_NAME;", *Database::getInstance());
        break;

        /* index == 2 -> List of AFC Teams */
    case 2:
        model->setQuery("SELECT TEAM_NAME AS \'Team Name\' FROM STADIUM WHERE CONFERENCE = 'AFC' ORDER BY TEAM_NAME;", *Database::getInstance());
        break;

        /* index == 3 -> List of all NFC Teams */
    case 3:
        model->setQuery("SELECT TEAM_NAME AS \'Team Name\' FROM STADIUM WHERE CONFERENCE = 'NFC' ORDER BY TEAM_NAME;", *Database::getInstance());
        break;

        /* index == 4 -> List of all Open Roof Stadiums */
    case 4:
        model->setQuery("SELECT STADIUM_NAME AS \'Stadium\', TEAM_NAME AS \'Team Name\' FROM STADIUM WHERE ROOF_TYPE = 'O';", *Database::getInstance());
        break;

        /* index == 5 -> List of all Star Players */
    case 5:
        model->setQuery("SELECT STAR_PLAYER AS \'Star Player\', TEAM_NAME AS \'Team Name\' FROM STADIUM ORDER BY TEAM_NAME;", *Database::getInstance());
        break;

        /* index == 6 -> List of Teams by Seating Capacity */
    case 6:
        model->setQuery("SELECT TEAM_NAME AS \'Team Name\', STADIUM_NAME AS \'Stadium\', SEATING_CAP AS \'Seating Capacity\', LOCATION AS \'Location\' FROM STADIUM ORDER BY SEATING_CAP;", *Database::getInstance());
        break;

        /* index == 7 -> List of Teams by Surface Type */
    case 7:
        model->setQuery("SELECT TEAM_NAME AS \'Team Name\', STADIUM_NAME AS \'Stadium\', SURFACE AS \'Surface Type\', LOCATION AS \'Location\' FROM STADIUM ORDER BY SEATING_CAP;", *Database::getInstance());
        break;
    }
    ui->Information_Table->setModel(model);
    ui->Information_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
