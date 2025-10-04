package ChatAndVideoConsultation;

import java.time.LocalDateTime;

public class VideoCall {
    // required fields for a video call
    private int sessionId;
    private int doctorId;
    private int patientId;
    private LocalDateTime scheduledTime;
    private String platform; // "Zoom" or "GoogleMeet"
    private String meetingLink;
    private boolean active;
    
    // constructor
    public VideoCall(int sessionId, int doctorId, int patientId, LocalDateTime scheduledTime, String platform) {
        this.sessionId = sessionId;
        this.doctorId = doctorId;
        this.patientId = patientId;
        this.scheduledTime = scheduledTime;
        this.platform = platform;
        this.active = false;    // initially not active
        
        // Generate a simulated meeting link
        generateMeetingLink();
    }
    
    // generating fake sample meeitng links
    private void generateMeetingLink() {
        if ("Zoom".equalsIgnoreCase(platform)) {
            meetingLink = "https://zoom/" + sessionId + "?pwd=meetingpassword";
        } else {
            meetingLink = "https://meet.google.com/" + sessionId;
        }
    }
    
    // starting the call
    public void startCall() {
        // In a real application, we would check if current time is near scheduled time
        active = true;
        System.out.println("Video call started: " + meetingLink);
    }
    
    //ending the call
    public void endCall() {
        if (!active) {
            System.out.println("Call is not active");
            return;
        }
        
        active = false;
        System.out.println("Video call ended");
    }
    
    // getters for the fields
    public String getMeetingLink() {
        return meetingLink;
    }
    public boolean isActive() {
        return active;
    }
    public LocalDateTime getScheduledTime() {
        return scheduledTime;
    }
    
    // setters
    public int getSessionId() {
        return sessionId;
    }
    public int getDoctorId() {
        return doctorId;
    }
    public int getPatientId() {
        return patientId;
    }

    // no need for toString() method as we are not displaying the object directly
}
