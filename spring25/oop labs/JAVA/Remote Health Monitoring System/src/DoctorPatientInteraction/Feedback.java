package DoctorPatientInteraction;

import java.util.ArrayList;
import java.time.LocalDateTime;

public class Feedback {
    // datafields
    private String comments;
    private ArrayList<Prescription> prescriptions; // ArrayList to hold prescriptions
    private LocalDateTime datetime;// date of the feedback

    public Feedback(String comments, ArrayList<Prescription> prescriptions, LocalDateTime datetime) {
        this.datetime = datetime;
        this.comments = comments;
        // initializing the arraylist of prescriptions
        this.prescriptions = prescriptions;
    }

    // getters and setters
    public String getComments() { return comments; }
    public LocalDateTime getDate() { return datetime; }
    public ArrayList<Prescription> getPrescriptions() {
        return prescriptions;
    }
    
    // setters
    public void setComments(String comments) { this.comments = comments; }
    public void setDate(LocalDateTime datetime) { this.datetime = datetime; }

    // adding new prescriptions
    public void addPrescriptions(Prescription prescription) {
        this.prescriptions.add(prescription); 
    }

    // overriden tostring to display details
    @Override
    public String toString() {
        return "Comments: " + comments + 
               "\nPrescriptions: " + prescriptions;
    }
}
