package NotificationsAndReminders;

public class EmailNotification implements Notifiable {
    // every email object will have these fields
    private String recipientEmail;
    private String subject;
    private String message;

    // constructor to initialize the fields
    public EmailNotification(String recipientEmail, String subject, String message) {
        this.recipientEmail = recipientEmail;
        this.subject = subject;
        this.message = message;
    }
    // getters and setters
    public String getRecipientEmail() {
        return recipientEmail;
    }
    public void setRecipientEmail(String recipientEmail) {
        this.recipientEmail = recipientEmail;
    }
    public String getSubject() {
        return subject;
    }
    public void setSubject(String subject) {
        this.subject = subject;
    }
    public String getMessage() {
        return message;
    }
    public void setMessage(String message) {
        this.message = message;
    }


    // method to send the email notification
    @Override
    public void sendNotification() {
        System.out.println("Sending email to: " + recipientEmail);
        System.out.println("Subject: " + subject);
        System.out.println("Message: " + message);
    }

    
}
