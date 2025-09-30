#ifndef UNITS_H
#define UNITS_H

#include <QString>
#include <QComboBox>

class Units
{
public:
    Units() = default;

    static double convert(const QString &from, const QString &to, double value);

    static void populateUnits(QComboBox *combo);
};

#endif // UNITS_H
