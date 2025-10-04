
// required imports
import UserManagement.Patient;
import UserManagement.Doctor;
import AppointmentScheduling.Appointment;
import AppointmentScheduling.AppointmentManager;
import DoctorPatientInteraction.Feedback;
import DoctorPatientInteraction.Prescription;
import HealthDataHandling.VitalSign;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Creating a Patient
        Patient patient1 = new Patient("P001", "Alap Gohar", "+92316-5666994", "alapgohar@gmail.com", new ArrayList<>());
        System.out.println("Patient Created: " + patient1);

        // Creating a Doctor
        Doctor doctor1 = new Doctor("D001", "Dr. Khan", "+92315-5656974", "drsmith@gmail.com");
        System.out.println("Doctor Created: " + doctor1);

        LocalDateTime currentDateTime = LocalDateTime.now();

        // Adding a Vital Sign
        VitalSign vital1 = new VitalSign("P1001", 72.5, 98.6, 120.0, 98.0, currentDateTime);
        // adding the vitalsign to database for patient
        patient1.uploadVitalSign(vital1);
        System.out.println("Vital Sign Added: " + vital1);

        // Scheduling an Appointment
        Appointment appointment = new Appointment(currentDateTime, doctor1, patient1);
        // scheduling the appointment using the appointment manager
        AppointmentManager.requestAppointment(appointment);
        System.out.println("Appointment Scheduled: " + appointment);

        // comments for prescription
        String comments = "Mild Flu";
        // prescription
        ArrayList<Prescription> prescriptions = new ArrayList<Prescription>();
        prescriptions.add(new Prescription("Azomax 250mg", "1+1", "15 days"));
        prescriptions.add(new Prescription("Panadol", "1+1", "5 days"));

        // Doctor Providing Feedback
        Feedback feedback = new Feedback(comments, prescriptions, currentDateTime);
        System.out.println("Doctor Feedback: " + feedback);
    }
}
