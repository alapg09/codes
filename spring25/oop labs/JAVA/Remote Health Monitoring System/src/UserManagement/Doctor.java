package UserManagement;

// required imports
import AppointmentScheduling.Appointment;
import AppointmentScheduling.AppointmentManager;
import DoctorPatientInteraction.Feedback;
import java.util.ArrayList;

public class Doctor extends User {
    // arraylists of patients that are assigned to a Doctor
    private ArrayList<Patient> patients;
    
    // constructor
    public Doctor(String id, String name,String phoneNumber, String email) {
        super(id, name, email, phoneNumber); 
        this.patients = new ArrayList<>();  // iniitializing the new arraylist of patients for each doctor
    }
    // gettern for patients
    public ArrayList<Patient> getPatients() {
        return patients;
    }

    // no setter for patients bcs doesnt make sense

    
    // adding a new patient
    public void addPatient(Patient patient) {
        patients.add(patient);
        System.out.println("Patient " + patient.getName() + " added to Dr. " + getName() + "'s list.");
    }

    // giving feedback to a patient
    public void provideFeedback(Patient patient, Feedback feedback) {
        patient.addFeedback(feedback);
    }

    // viewing appointments for doctors
    public void viewAppointments() {
        System.out.println("Appointments for Dr. " + getName() + ":");
        for (Appointment a : AppointmentManager.getAppointments()) {
            if (a.getDoctor().equals(this)) {
                System.out.println(a.getDateTime() + " - " + a.getStatus());
            }
        }
    }

    // viewing patients
    public void viewPatients() {
        System.out.println("Patients for Dr. " + getName() + ":");
        for (Patient p : patients) {
            System.out.println(p.getName());
        }
    }

    // viewing patient feedbacks
    public void viewPatientFeedbacks(Patient patient) {
        System.out.println("Feedbacks for " + patient.getName() + ":");
        for (Feedback f : patient.getFeedbacks()) {
            System.out.println(f);
        }
    }

    // viewing patient vitals
    public void viewPatientVitals(Patient patient) {
        System.out.println("Vitals for " + patient.getName() + ":");
        System.out.println(patient.getVitals());
    }

    // approving appointments
    public void approveAppointment(Appointment appointment) {
       AppointmentManager.approveAppointment(appointment);
       System.out.println("Appointment approved for: " + appointment.getPatient().getName());
    }

    // cancellign appointments
    public void cancelAppointment(Appointment appointment) {
        AppointmentManager.cancelAppointment(appointment);
        System.out.println("Appointment cancelled for: " + appointment.getPatient().getName());
    }
}
