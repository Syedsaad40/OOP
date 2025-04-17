#include<iostream>
#include<string>
#include<vector>
using namespace std;

class PatientRecord {
private:
    string name;
    string ID;
    string DOB;
    string history;
    string currentTreatments;
    vector<string> billingDetails;

public:
    PatientRecord(string a, string b, string c, string d, string e) : 
        name(a), ID(b), DOB(c), history(d), currentTreatments(e) {}

    void getPublicData() {
        cout << "Patient Data:" << endl;
        cout << "Name:" << name << endl;
        cout << "ID:" << ID << endl;
        cout << "Date Of Birth:" << DOB << endl;
    }

    void getMedicalData() {
        cout << "Medical history:" << history << endl;
        cout << "Current Treatments:" << currentTreatments << endl;
    }

    void updateMedicalHistory(string a, string b) {
        history = a;
        currentTreatments = b;
        cout << "Medical records updated" << endl;
    }

    void addBillingDetail(string detail) {
        billingDetails.push_back(detail);
    }

    void viewBillingDetails() {
        for (const auto& detail : billingDetails) {
            cout << detail << endl;
        }
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
private:
    PatientRecord* record;

public:
    Doctor(PatientRecord* rec) : record(rec) {}

    void viewMedicalData() {
        record->getMedicalData();
    }

    void updatePatientHistory(string history, string treatments) {
        record->updateMedicalHistory(history, treatments);
    }
};

class Billing {
private:
    PatientRecord* record;

public:
    Billing(PatientRecord* rec) : record(rec) {}

    void addBill(string detail) {
        record->addBillingDetail(detail);
    }

    void viewBills() {
        record->viewBillingDetails();
    }
};

class Receptionist {
private:
    PatientRecord* record;

public:
    Receptionist(PatientRecord* rec) : record(rec) {}

    void viewPublicData() {
        record->getPublicData();
    }
};

int main() {
    PatientRecord patient("John Doe", "P1001", "01/01/1980", "None", "None");

    Doctor dr(&patient);
    Billing billing(&patient);
    Receptionist receptionist(&patient);

    cout << "Doctor's access:" << endl;
    dr.viewMedicalData();
    dr.updatePatientHistory("Allergy: Penicillin", "Antihistamines");

    cout << "\nBilling's access:" << endl;
    billing.addBill("Consultation: $200");
    billing.addBill("Medication: $50");
    billing.viewBills();

    cout << "\nReceptionist's access:" << endl;
    receptionist.viewPublicData();

    return 0;
}