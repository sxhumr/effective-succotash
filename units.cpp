#include "units.h"

double Units::convert(const QString &from, const QString &to, double value)
{
    // Length
    if (from == "Meters" && to == "Feet") return value * 3.28084;
    if (from == "Kilometers" && to == "Miles") return value * 0.621371;

    // Weight
    if (from == "Kilograms" && to == "Pounds") return value * 2.20462;

    // Temperature
    if (from == "Celsius" && to == "Fahrenheit") return (value * 9.0/5.0) + 32;
    if (from == "Fahrenheit" && to == "Celsius") return (value - 32) * 5.0/9.0;

    // No valid conversion
    return value;
}

void Units::populateUnits(QComboBox *combo)
{
    if (!combo) return;
    combo->clear();
    combo->addItems({"Meters", "Kilometers", "Kilograms", "Celsius"});
}
