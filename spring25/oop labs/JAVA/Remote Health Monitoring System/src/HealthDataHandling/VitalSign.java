package HealthDataHandling;

import java.time.LocalDateTime;

public class VitalSign {
    // attributes for vital signs including date for keeping track of when they were recorded
    private String patientID;
    private double heartRate;
    private double oxygenLevel;
    private double bloodPressure;
    private double temperature;
    private LocalDateTime dateTimeRecorded;

    // constructor to initialize the vital sign attributes
    public VitalSign(String patientID, double heartRate, double oxygenLevel, double bloodPressure, double temperature, LocalDateTime dateTimeRecorded) {
        this.patientID = patientID;
        this.heartRate = heartRate;
        this.oxygenLevel = oxygenLevel;
        this.bloodPressure = bloodPressure;
        this.temperature = temperature;
        this.dateTimeRecorded = dateTimeRecorded;
    }

    // getters
    public String getUserId() { return patientID; }
    public double getHeartRate() { return heartRate;}
    public double getOxygenLevel() { return oxygenLevel;}
    public double getBloodPressure() { return bloodPressure;}
    public double getTemperature() { return temperature;}
    public LocalDateTime getDateTimeRecorded() { return dateTimeRecorded;}

    // setters in case modification is required
    public void setHeartRate(double heartRate) { this.heartRate = heartRate; }
    public void setOxygenLevel(double oxygenLevel) { this.oxygenLevel = oxygenLevel; } 
    public void setBloodPressure(double bloodPressure) { this.bloodPressure = bloodPressure; }
    public void setTemperature(double temperature) { this.temperature = temperature; }
    public void setDateRecorded(LocalDateTime dateTimeRecorded) { this.dateTimeRecorded = dateTimeRecorded; }


    // overriden toString method to display the vital sign details
    @Override
    public String toString() {
        return "PatientID: " + patientID +
        "\nHeart Rate: " + heartRate + " bpm"+
        "\nOxygen Level: " + oxygenLevel + "%" +
        "\nBlood Pressure: " + bloodPressure + " mmHg" +
        "\nTemperature: " + temperature + " °C" +
        "\nDate Recorded: " + dateTimeRecorded;
    }
}
