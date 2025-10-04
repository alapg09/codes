import java.util.ArrayList;
import java.util.Date;
import java.util.Calendar;


class Hospital{
    // data fields
    private String hname;
    private String address;
    private ArrayList<Patient> patients;
    private ArrayList<Department> departments;

    // constructor with arraylists
    public Hospital(String hname, String address, ArrayList<Patient> patients, ArrayList<Department> departments) {
        this.hname = hname;
        this.address = address;
        this.patients = patients;
        this.departments = departments;
    }
    // constructor without arraylists
    public Hospital(String hname, String address) {
        this.hname = hname;
        this.address = address;
        this.patients = new ArrayList<>();
        this.departments = new ArrayList<>();
    }
    // no created any no-arg constructor because it does not make sense to create a hospital without any name or address. similaryl, for other classes as well
    // getters and setters
    public String gethname() { return hname; }
    public String getAddress() { return address; }
    public ArrayList<Patient> getPatients() { return patients; }
    public ArrayList<Department> getDepartments() { return departments; }

    public void sethname(String hname) { this.hname = hname; }
    public void setAddress(String address) { this.address = address; }
    public void setPatients(ArrayList<Patient> patients) { this.patients = patients; }
    public void setDepartments(ArrayList<Department> departments) { this.departments = departments; }  

    // required methods for adding and removing patients
    public void addPatient(Patient patient) {
        patients.add(patient);
    }
    public void removePatient(Patient patient) {
        patients.remove(patient);
    }
    // adding and removing departments
    public void addDepartment(Department department) {
        departments.add(department);
    }
    public void removeDepartment(Department department) {
        departments.remove(department);
    }


    // there is no need to display the patients and departments in the hospital class's toString method because that is unnecessary detail
    @Override
    public String toString() {
        return "Hospital{" +
                "hname='" + hname + '\'' +
                ", address='" + address + '\'' +
                '}';
    }

}


class Department{
    // data fields
    private String dname;
    private ArrayList<TeamMember> teamMembers;

    //2 different constructors
    // one with arraylist and one without
    public Department(String dname, ArrayList<TeamMember> teamMembers) {
        this.dname = dname;
        this.teamMembers = teamMembers;
    }
    public Department(String dname) {
        this.dname = dname;
        this.teamMembers = new ArrayList<>();
    }

    // getters and setters
    public String getDname() { return dname; }
    public ArrayList<TeamMember> getTeamMembers() { return teamMembers; }

    public void setDname(String dname) { this.dname = dname; }
    public void setTeamMembers(ArrayList<TeamMember> teamMembers) { this.teamMembers = teamMembers; }

    // required methods for adding and removing team members
    public void addTeamMember(TeamMember teamMember) {
        teamMembers.add(teamMember);
    }
    public void removeTeamMember(TeamMember teamMember) {
        teamMembers.remove(teamMember);
    }
    // there is no need to display the team members in the department class's toString method because that is unnecessary detail
    @Override
    public String toString() {
        return "Department{" +
                "dname='" + dname + '\'' +
                '}';
    }


}

abstract class TeamMember{
    // data fields
    protected String tname;
    protected String tID;
    protected String gender;
    protected Date dateJoined;
    protected final int MAX_HOURS = 12;


    // constructor for subclasses to use
    public TeamMember(String tname, String tID, String gender, Date dateJoined ){
        this.tname = tname;
        this.tID = tID;
        this.gender = gender;
        this.dateJoined = dateJoined;
    }

    // getters and setters for subclasses to use
    public String getTname() { return tname; }
    public String getTID() { return tID; }
    public String getGender() { return gender; }
    public Date getDateJoined() { return dateJoined; }
    public int getMAX_HOURS() { return MAX_HOURS; }


    public void setTname(String tname) { this.tname = tname; }
    public void setTID(String tID) { this.tID = tID; }
    public void setGender(String gender) { this.gender = gender; }
    public void setDateJoined(Date dateJoined) { this.dateJoined = dateJoined; }
    // no setter for max hours because it is a constant value

    // no abstract methods were specified for the team member class, so no need to implement any methods here

    // toString method for subclasses to use
    @Override   
    public String toString(){
        return "Name: "+ tname +
        "ID: " + tID +
        "Gender: " + gender +
        "Date Joined: " + dateJoined +
        "Max Working Hours: " + MAX_HOURS;
    }
    
    
}

class Nurse extends TeamMember {
    // no attributes and methods were specified for the nusre class
    public Nurse(String name, String id, String gender, Date dateJoined) {
        super(name, id, gender, dateJoined);
    }
}


abstract class Doctor extends TeamMember{
    protected String speciality;

// i have not created any no-arg constructors to maintain data integrity

    public Doctor(String name, String id, String gender, Date dateJoined, String speciality){
        super(name, id, gender, dateJoined);
        this.speciality = speciality;
    }

    // getters and setters for the speciality attribute
    public String getSpeciality() { return speciality; }
    public void setSpeciality(String speciality) { this.speciality = speciality; }

    public void checkPatientReport(Patient patient) {
        System.out.println("Doctor " + getTname() + " is checking the report of patient " + patient.getName());
        System.out.println(patient.getReport());
    }


    protected abstract void treatPatient(Patient patient);
    // this method is abstract because each type of doctor will have a different way of treating a patient

    @Override
    public String toString(){
        return super.toString() + 
        "Speciality: " + speciality;
    }


}


class Intern extends Doctor{
    Doctor supervisor;

    // constructor
    public Intern(String name, String id, String gender, Date dateJoined, String speciality, Doctor supervisor){
        super(name, id, gender, dateJoined, speciality);
        this.supervisor = supervisor;
    }

    //getters and setters for the supervisor attribute
    public Doctor getSupervisor() { return supervisor; }
    public void setSupervisor(Doctor supervisor) { this.supervisor = supervisor; }

    // method to treat a patient
    @Override
    public void treatPatient(Patient patient) {
        // we can only use a String for treatment because we are not given any specific details about the treatment process
        System.out.println("Intern " + getTname() + " is treating patient " + patient.getName() + " under the supervision of Dr. " + supervisor.getTname());
    }

    // addign and removong patients
    public void addPatient(Patient patient) {
        System.out.println("Intern " + getTname() + " is adding patient " + patient.getName() + " under the supervision of Dr. " + supervisor.getTname());
    }
    public void removePatient(Patient patient) {
        System.out.println("Intern " + getTname() + " is removing patient " + patient.getName() + " under the supervision of Dr. " + supervisor.getTname());
    }

    @Override
    public String toString(){
        return super.toString() + 
        "Supervisor: " + supervisor.getTname();
    }

    
}

class SeniorDoctor extends Doctor{
    ArrayList<Patient> patientsOfDoctor;
    // 2 diff constructor
    public SeniorDoctor(String name, String id, String gender, Date dateJoined, String speciality, ArrayList<Patient> patients){
        super(name, id, gender, dateJoined, speciality);
        this.patientsOfDoctor = patients;
    }
    public SeniorDoctor(String name, String id, String gender, Date dateJoined, String speciality){
        super(name, id, gender, dateJoined, speciality);
        this.patientsOfDoctor = new ArrayList<>();
    }

    // getters and setters for the patients attribute
    public ArrayList<Patient> getPatientsOfDoctor() { return patientsOfDoctor; }
    public void setPatientsOfDoctor(ArrayList<Patient> patientsOfDoctor) { this.patientsOfDoctor = patientsOfDoctor; }

    // adding and removing patients
    public void addPatient(Patient patient) {
        patientsOfDoctor.add(patient);
    }
    public void removePatient(Patient patient) {
        patientsOfDoctor.remove(patient);
    }
    
    // method to treat a patient
    @Override
    public void treatPatient(Patient patient) {
        System.out.println("Senior Doctor " + getTname() + " is treating patient " + patient.getName());
    }
    
    //no toString method as that is not required for this class. it ccan use the one of superclass
}
class Surgeon extends Doctor{
    ArrayList<Patient> patientsOfSurgeon;
    // constructor
    public Surgeon(String name, String id, String gender, Date dateJoined, String speciality, ArrayList<Patient> patients){
        super(name, id, gender, dateJoined, speciality);
        this.patientsOfSurgeon = patients;
    }
    public Surgeon(String name, String id, String gender, Date dateJoined, String speciality){
        super(name, id, gender, dateJoined, speciality);
        this.patientsOfSurgeon = new ArrayList<>();
    }

    // getters and setters for the patients attribute
    public ArrayList<Patient> getPatientsOfSurgeon() { return patientsOfSurgeon; }  
    public void setPatientsOfSurgeon(ArrayList<Patient> patientsOfSurgeon) { this.patientsOfSurgeon = patientsOfSurgeon; }

    // adding and removing patients
    public void addPatient(Patient patient) {
        patientsOfSurgeon.add(patient);
    }
    public void removePatient(Patient patient) {
        patientsOfSurgeon.remove(patient);
    }

    // method to treat a patient
    @Override
    public void treatPatient(Patient patient) {
        System.out.println("Surgeon " + getTname() + " is treating patient " + patient.getName());
    }

}


class Patient{
    private String pname;
    private Date birthDate;
    private String pgender;
    private Date dateAdmitted;
    private String report;
    private Doctor doctor;
    private int daysAdmitted;

    // constructor with all attributes
    public Patient(String pname, Date birthDate, String pgender, Date dateAdmitted, String report, Doctor doctor, int daysAdmitted) {
        this.pname = pname;
        this.birthDate = birthDate;
        this.pgender = pgender;
        this.dateAdmitted = dateAdmitted;
        this.report = report;
        this.doctor = doctor;
        this.daysAdmitted = daysAdmitted;
    }

    // getters and setters for all attributes
    public String getName() { return pname; }
    public Date getBirthDate() { return birthDate; }
    public String getGender() { return pgender; }
    public Date getDateAdmitted() { return dateAdmitted; }
    public String getReport() { return report; }
    public Doctor getDoctor() { return doctor; }
    public int getDaysAdmitted() { return daysAdmitted; }

    public void setName(String pname) { this.pname = pname; }
    public void setBirthDate(Date birthDate) { this.birthDate = birthDate; }
    public void setGender(String pgender) { this.pgender = pgender; }
    public void setDateAdmitted(Date dateAdmitted) { this.dateAdmitted = dateAdmitted; }
    public void setReport(String report) { this.report = report; }
    public void setDoctor(Doctor doctor) { this.doctor = doctor; }
    public void setDaysAdmitted(int daysAdmitted) { this.daysAdmitted = daysAdmitted; }

}



// main testing class
public class HospitalManagement {
    public static void main(String[] args) {
        // creating hospital
        Hospital aghakhan = new Hospital("Aga Khan University Hospital", "Stadium Road, Karachi");
        
        // creating departments
        Department cardiology = new Department("Cardiology");
        
        // adding department to hospital
        aghakhan.addDepartment(cardiology);
        
        // creating dates manually using Calendar
        Calendar calendar = Calendar.getInstance();
        
        calendar.set(2024, Calendar.JUNE, 15); // 15-06-2024
        Date drFarooqJoinDate = calendar.getTime();
        
        calendar.set(2015, Calendar.APRIL, 12); // 12-04-2015
        Date nurseAishaJoinDate = calendar.getTime();
        
        calendar.set(1975, Calendar.AUGUST, 14); // 14-08-1975
        Date patientImranBirthDate = calendar.getTime();
        
        calendar.set(2023, Calendar.MARCH, 25); // 25-03-2023
        Date patientImranAdmitDate = calendar.getTime();
        
        // Create one senior doctor
        SeniorDoctor drFarooq = new SeniorDoctor(
            "Dr. Farooq Ahmed", 
            "SD001", 
            "male", 
            drFarooqJoinDate, 
            "Cardiology"
        );
        
        // creating one surgeon
        Surgeon drTariq = new Surgeon(
            "Dr. Tariq Malik", 
            "SG001", 
            "male", 
            drFarooqJoinDate, 
            "Cardiac Surgery"
        );
        
        // creating one intern with supervisor
        Intern drAmna = new Intern(
            "Dr. Amna Qureshi", 
            "IN001", 
            "female", 
            drFarooqJoinDate, 
            "General Medicine",
            drFarooq
        );
        
        // creating one nurse
        Nurse nurseAisha = new Nurse(
            "Aisha Mahmood", 
            "NR001", 
            "female", 
            nurseAishaJoinDate
        );
        
        // adidng team members to department
        cardiology.addTeamMember(drFarooq);
        cardiology.addTeamMember(drTariq);
        cardiology.addTeamMember(drAmna);
        cardiology.addTeamMember(nurseAisha);
        
        // creaitng patients
        Patient patientImran = new Patient(
            "Imran Malik", 
            patientImranBirthDate, 
            "male", 
            patientImranAdmitDate, 
            "Cardiac arrhythmia", 
            drFarooq, 
            7
        );
        
        // adding patient to hospital and doctor
        aghakhan.addPatient(patientImran);
        drFarooq.addPatient(patientImran);
        
        // demonstrating functionality
        System.out.println("Hospital: " + aghakhan.gethname());
        drFarooq.treatPatient(patientImran);
        drAmna.treatPatient(patientImran);
        drFarooq.checkPatientReport(patientImran);
        
        // demonstrating removing patient
        aghakhan.removePatient(patientImran);
        System.out.println("Patients remaining: " + aghakhan.getPatients().size());
    }
}