#include "mainwindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "units.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    setFixedSize(500, 400);
    setWindowTitle("Unit Converter");

    // Initialise UI Elements
    cmbUnitFrom     = new QComboBox(this);
    cmbUnitTo       = new QComboBox(this);

    lnEdtInput      = new QLineEdit(this);
    lnEdtInput->setFixedSize(145,30);
    lnEdtInput->setPlaceholderText("Enter value to convert");

    lblOutputResult = new QLabel("Result: ", this);
    lblFrom         = new QLabel("Convert From: ", this);
    lblTo           = new QLabel("To: ", this);

    btnSubmit = new QPushButton("Submit", this);
    btnSubmit->setFixedSize(135,45);
    btnSubmit->setStyleSheet("background-color: #0078D7; color: black; padding: 3px; font-size:16px; font-weight: bold");

    // Header
    lblHeader = new QLabel("Unit Converter", this);
    lblHeader->setStyleSheet("font-size: 24px; font-weight: bold; padding: 10px;");

    // Populate combo boxes
    cmbUnitFrom->addItems({"Meters", "Kilometers", "Kilograms", "Celsius"});
    cmbUnitTo->addItems({"Feet", "Miles", "Pounds", "Fahrenheit"});

    // Create Top Layout (form area)
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(lblHeader, 0, 0, 1, 2, Qt::AlignCenter);  // header spans two columns
    topLayout->addWidget(lblFrom, 1, 0);
    topLayout->addWidget(cmbUnitFrom, 1, 1);
    topLayout->addWidget(lblTo, 2, 0);
    topLayout->addWidget(cmbUnitTo, 2, 1);
    topLayout->setSpacing(10);
    topLayout->setContentsMargins(15, 15, 15, 15);

    // Input Layout
    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->addWidget(lnEdtInput,0,Qt::AlignHCenter);
    inputLayout->addWidget(btnSubmit,0,Qt::AlignHCenter);

    // Output Layout
    QVBoxLayout *outputLayout = new QVBoxLayout;
    outputLayout->addWidget(lblOutputResult);

    // Combine all layouts into a main vertical layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(outputLayout);

    // Set layout to central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Default suggestion for conversions
    fromUnit = "Meters";
    toUnit = "Feet";
    cmbUnitFrom->setCurrentText(fromUnit);
    cmbUnitTo->setCurrentText(toUnit);

    // Connect button click to slot
    connect(btnSubmit, &QPushButton::clicked, this, &MainWindow::convertUnits);
}

void MainWindow::convertUnits()
{
    bool ok;
    double inputValue = lnEdtInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Invalid Input","Please enter a valid number");
        return;
    }

    QString from = cmbUnitFrom->currentText();
    QString to = cmbUnitTo->currentText();

    double result = Units::convert(from, to, inputValue);

    lblOutputResult->setText("Result: " + QString::number(result));
}

MainWindow::~MainWindow()
{
    delete ui;
}
