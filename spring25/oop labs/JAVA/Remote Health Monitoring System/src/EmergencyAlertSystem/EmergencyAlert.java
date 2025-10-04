package EmergencyAlertSystem;

import HealthDataHandling.VitalSign;
import UserManagement.Patient;

public class EmergencyAlert {

    // static method so that it can be called without creating an object of the class
    public static void checkVitalSigns(Patient patient, VitalSign vital){
        // check if the vital signs are within normal range, send alerts if not
        if (vital.getHeartRate() < 60 || vital.getHeartRate() > 100) {
            NotificationService.sendAlert("Alert: Abnormal heart rate detected for Patient: "+ patient.getName() + " with ID: " + patient.getId(), patient);
        }
        if (vital.getOxygenLevel() < 90) {
            NotificationService.sendAlert("Alert: Abnormal Oxygen Level detected for Patient: "+ patient.getName() + " with ID: " + patient.getId(), patient);
        }

        if (vital.getBloodPressure() < 90 || vital.getBloodPressure() > 120) {
            NotificationService.sendAlert("Alert: Abnormal Blood Pressure detected for Patient: "+ patient.getName() + " with ID: " + patient.getId(), patient);
        }
        if (vital.getTemperature() < 36.1 || vital.getTemperature() > 37.2) {
            NotificationService.sendAlert("Alert: Abnormal Temperature detected for Patient: "+ patient.getName() + " with ID: " + patient.getId(), patient);
        }
    }
}
