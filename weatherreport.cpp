#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 70;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 52;
        }
    };

    class HighPrecipitationLowWindSensorStub : public IWeatherSensor {
    
        int Humidity() const override {
            return 85;
         }

        int Precipitation() const override {
            return 80; // High precipitation (>60)
        }

        double TemperatureInC() const override {
            return 22;
        }

        int WindSpeedKMPH() const override {
            return 40; // Low wind speed (<50)
        }
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (precipitation >= 60 && precipitation <= 80) // Change this condition
                report = "Cloudy with light rain";
            else if (sensor.WindSpeedKMPH() > 50 && precipitation > 80)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestRainy()
    {
        SensorStub sensor;
        string report = Report(sensor);
        cout << report << endl;
        assert(report.find("rain") != string::npos);
    }

    void TestHighPrecipitation()
    {


        HighPrecipitationLowWindSensorStub sensor; // Use the new sensor with high precipitation and low wind speed

        string report = Report(sensor);
        assert(report.find("rain") != string::npos); // Strengthen the assert to check if the report contains "rain"


    }
}

int main() {
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
    return 0;
}
