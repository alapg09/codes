# 📌 Remote Health Monitoring System

## Project Overview
The **Remote Health Monitoring System** is designed to assist doctors and patients in tracking health conditions remotely. It enables patient registration, appointment scheduling, vitals monitoring, and feedback exchange.

---

## Project Structure
RemoteHealthMonitoringSystem/
│── src/                       # Source Code
│   ├── UserManagement/                  # User management classes
│   │   ├── User.java
│   │   ├── Patient.java
│   │   ├── Doctor.java
│   │   ├── Administrator.java
│   ├── HealthDataHandling/                # Vitals and medical history
│   │   ├── VitalSign.java
│   │   ├── VitalsDatabase.java
│   ├── AppointmentScheduling/           # Appointment scheduling
│   │   ├── Appointment.java
│   │   ├── AppointmentManager.java
│   ├── DoctorPatientInteraction/           # Doctor-patient interactions
│   │   ├── Feedback.java
│   │   ├── Prescription.java
│   │   ├── MedicalHistory.java
│   ├── Main.java                  # Main entry point for execution
│── bin/                       # Compiled Java bytecode
│── README.md                  # Instructions to run the project
│── RemotePatientMonitoringSystem.docx/          # Word file containing screenshots for verification

## How to run
The following commands will be run on the terminal to run the main file:
1. 
    javac Main.java
2.  
    java Main

## Prerequisites
- **Java JDK 17+** installed
- **VS Code with Java Extension Pack** (or any Java IDE)