#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Logger {
private:
    struct LogEntry {
        string message;
        int severity;
        string module;
    };

    vector<LogEntry> logs;
    const size_t MAX_LOG_COUNT = 1000;
    string auditorSecret = "secure123";

    const int INFO = 0;
    const int WARNING = 1;
    const int ERROR = 2;

    void addLog(const string& msg, int severity, const string& module) {
        if (logs.size() >= MAX_LOG_COUNT) {
            logs.erase(logs.begin());
        }
        logs.push_back({msg, severity, module});
    }

public:
    void logInfo(const string& msg, const string& module = "System") {
        addLog(msg, INFO, module);
        cout << "[INFO][" << module << "] " << msg << endl;
    }

    void logWarning(const string& msg, const string& module = "System") {
        addLog(msg, WARNING, module);
        cout << "[WARN][" << module << "] " << msg << endl;
    }

    void logError(const string& msg, const string& module = "System") {
        addLog(msg, ERROR, module);
        cout << "[ERROR][" << module << "] " << msg << endl;
    }

    vector<string> getLogs(const string& secret) const {
        vector<string> formattedLogs;
        if (secret != auditorSecret) {
            formattedLogs.push_back("Unauthorized access attempted");
            return formattedLogs;
        }

        for (const auto& entry : logs) {
            string severityStr;
            if (entry.severity == INFO) severityStr = "INFO";
            else if (entry.severity == WARNING) severityStr = "WARN";
            else if (entry.severity == ERROR) severityStr = "ERROR";
            
            formattedLogs.push_back("[" + severityStr + "][" + entry.module + "] " + entry.message);
        }
        return formattedLogs;
    }

    size_t getLogCount() const {
        return logs.size();
    }
};

int main() {
    Logger logger;

    logger.logInfo("System initialized", "Startup");
    logger.logWarning("Low memory detected", "MemoryManager");
    logger.logError("Database connection failed", "Database");
    logger.logInfo("User logged in", "Authentication");
    logger.logWarning("Invalid API request", "Network");

    cout << "\nUnauthorized access attempt:" << endl;
    auto unauthorizedLogs = logger.getLogs("wrongpassword");
    for (const auto& log : unauthorizedLogs) {
        cout << log << endl;
    }

    cout << "\nAuthorized audit:" << endl;
    auto auditLogs = logger.getLogs("secure123");
    for (const auto& log : auditLogs) {
        cout << log << endl;
    }

    cout << "\nTotal logs stored: " << logger.getLogCount() << endl;

    return 0;
}
