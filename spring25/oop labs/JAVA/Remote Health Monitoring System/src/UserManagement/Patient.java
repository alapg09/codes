package UserManagement;


// required imports
import AppointmentScheduling.Appointment;
import AppointmentScheduling.AppointmentManager;
import DoctorPatientInteraction.Feedback;
import EmergencyAlertSystem.*;
import HealthDataHandling.VitalSign;
import HealthDataHandling.VitalsDatabase;
import java.util.ArrayList;

public class Patient extends User {
    // attributes specific to the Patient class
    private VitalsDatabase vitalsDatabase;  // to store the vital signs of the patient
    private ArrayList<Feedback> feedbacks;  // to store previous feedbacks given by doctors
    private ArrayList<String> emergencyContacts; // to store emergency contact numbers of the patient 
    private Doctor physician = null; ;   // this is the general physician of the patient who tracks the vitals etc but the patient can havae multiple doctors for different specializations


    // constructor to initialize the Patient object
    public Patient(String id, String name, String phoneNumber, String email, ArrayList<String> emergencyContacts) {
        super(id, name, phoneNumber, email);
        // new vitals database objject for each patient4
        this.vitalsDatabase = new VitalsDatabase();
        // new arraylist for feedbacks for each patient
        this.feedbacks = new ArrayList<>();
        // new arraylist for emergency contacts for each patient
        this.emergencyContacts = emergencyContacts;
        // setting the physician for the patient
        // physician is not added becaise it is not necessarry for patient to always have a physician. can be added later
    }

    // getter for vitalsdatabase of each patient
    public VitalsDatabase getVitals() {
        return vitalsDatabase;
    }

    // getter for feedback
    public ArrayList<Feedback> getFeedbacks() {
        return feedbacks;
    }
    // getter for emergency contacts
    public ArrayList<String> getEmergencyContacts() {
        return emergencyContacts;
    }
    // setter for emergency contacts
    public void setEmergencyContacts(ArrayList<String> emergencyContacts) {
        this.emergencyContacts = emergencyContacts;
    }
    // getter for physician
    public Doctor getPhysician() {
        return physician;
    }
    // setter for physician
    public void setPhysician(Doctor physician) {
        this.physician = physician;
    }
    //adding and removing emergency contacts
    public void addEmergencyContact(String contact) {
        emergencyContacts.add(contact);
        System.out.println("Emergency contact added for patient: " + getName());
    }
    public void removeEmergencyContact(String contact) {
        emergencyContacts.remove(String.valueOf(contact));
        System.out.println("Emergency contact removed for patient: " + getName());
    }

    // no setters for vitalsdatabase and feedbacks because doesnt make sense to change vitasldatabase and feedbacks after the patient has been created

    
    // for uploading a new vital sign 
    public void uploadVitalSign(VitalSign vital) {
        vitalsDatabase.addVital(vital);
        System.out.println("Vital sign added for patient: " + getName());

        // vitals will be checked here to ensure that the patient is not in critical condition
        EmergencyAlert.checkVitalSigns(this, vital);
    }

    //
    public void panicButton(String message) {
        PanicButton.pressPanicButton(message ,this);
    }

    // requesting a new appointment
    public void requestAppointment(Appointment appointment) {
        AppointmentManager.requestAppointment(appointment);
        System.out.println("Appointment requested for: " + getName());
    }
    // adding a new feedback
    public void addFeedback(Feedback feedback) {
        feedbacks.add(feedback);
        System.out.println("Feedback added for patient: " + getName());
    }
    // removing a feedback
    public void removeFeedback(Feedback feedback) {
        feedbacks.remove(feedback);
        System.out.println("Feedback removed for patient: " + getName());
    }

    // removing a vital sign
    public void removeVital(VitalSign vitalSign){
        vitalsDatabase.removeVital(vitalSign);
    }

    // viewing previous feedbacks
    public void viewPreviousFeedbacks() {
        System.out.println("Feedbacks for " + getName() + ":");
        for (Feedback f : feedbacks) {
            System.out.println(f.getComments());
        }
    }
    // viewing previous feedbacks
    public void viewPreviousVitals(){
        System.out.println("Vital Signs for " + getName() + ":");
        vitalsDatabase.displayVitals();
    }

    // 


    // no toString bcs user's can be used. no need to didplay vitals and feedbacks in this 
}
