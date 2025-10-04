package NotificationsAndReminders;

import AppointmentScheduling.*;
import DoctorPatientInteraction.*;
import UserManagement.*;

// user will have the choice to have the object of this class to remind them of their appointments and medications
public class ReminderService {
    User user; // can be patient or doctor
    
    // different constructors
    public ReminderService(Patient patient) {
        this.user = patient;
    }
    public ReminderService(Doctor doctor) {
        this.user = doctor;
    }

    // method to remind user of their appointments
    public void remindAppointments() {
        System.out.println("Reminding " + user.getName() + " of their appointments:");
        // checking the appointments of the user either it is patient or doctor
        for (Appointment appointment : AppointmentManager.getAppointments()) {
            if (appointment.getPatient().equals(user) || appointment.getDoctor().equals(user)) {
                // calling toString implicitly
                System.out.println(appointment);
            }
        }
    }
    // method to remind user of their medications
    public void remindMedications() {
        System.out.println("Reminding " + user.getName() + " of their medications:");

        // checking if user is a patient because only patients have medications
        if (user instanceof Patient) {
            // downcastign
            Patient patient = (Patient) user;
            // all  prescriptiosn of a patient
            for (Feedback feedback : patient.getFeedbacks()) {
                for (Prescription prescription : feedback.getPrescriptions()) {
                    System.out.println(prescription);
                }
            }
        } else if (user instanceof Doctor) {
            System.out.println("Doctors do not have medications.");
        } else {
            System.out.println("Invalid user type.");
        }
    }
}
