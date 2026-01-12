#include <cstring>
#include <iostream>

#include <string>

#include <sys/statvfs.h>
#include <unistd.h>

float getCPUUsage() {
    std::string command = "top -bn1 | grep 'Cpu(s)' | awk '{print $2}' | awk -F. '{print $1}'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -2.0;
    float cpuUsage;
    fscanf(pipe, "%f", &cpuUsage);
    pclose(pipe);
    return cpuUsage;
}

float getMemoryUsage() {
    std::string command = "free -m | awk 'NR==2{printf \"%s\", $3*100/$2 }'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -1.0;
    float memoryUsage;
    fscanf(pipe, "%f", &memoryUsage);
    pclose(pipe);
    return memoryUsage;
}

float getDiskSpaceUsage() {
    std::string command = "df -h --output=pcent / | awk '{print $1}' | sed 's/%//g'";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -1.0;
    float diskSpaceUsage;
    fscanf(pipe, "%f", &diskSpaceUsage);
    pclose(pipe);
    return diskSpaceUsage;
}

int getActiveProcesses() {
    std::string command = "ps -ef | wc -l";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return -1;
    int activeProcesses;
    fscanf(pipe, "%d", &activeProcesses);
    pclose(pipe);
    return activeProcesses;
}

// Function to send email alert using mailx
void sendEmailAlert(const std::string& subject, const std::string& body) {
    std::string command = "echo '" + body + "' | mailx -s '" + subject + "' dev.ckshetty@gmail.com";
    if (system(command.c_str()) != 0) {
        std::cerr << "Error sending email alert: " << strerror(errno) << std::endl;
    } else {
        std::cout << "Email alert sent successfully!" << std::endl;
    }
}

int main() {
    // Set thresholds
    float cpuThreshold = 80.0;
    float memoryThreshold = 80.0;
    float diskSpaceThreshold = 80.0;
    int activeProcessesThreshold = 100;

    // Monitor system health
    float cpuUsage = getCPUUsage();
    float memoryUsage = getMemoryUsage();
    float diskSpaceUsage = getDiskSpaceUsage();
    int activeProcesses = getActiveProcesses();

    // Print system health information in a dashboard format
    std::cout << "System Health Dashboard:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;
    std::cout << "Memory Usage: " << memoryUsage << "%" << std::endl;
    std::cout << "Disk Space Usage: " << diskSpaceUsage << "%" << std::endl;
    std::cout << "Active Processes: " << activeProcesses << std::endl;
    std::cout << "------------------------" << std::endl;


    // Send email alerts if thresholds are exceeded
    if (cpuUsage > cpuThreshold) {
        sendEmailAlert("CPU Usage Alert", "CPU usage exceeded " + std::to_string(cpuThreshold) + "%");
    }
    if (memoryUsage > memoryThreshold) {
        sendEmailAlert("Memory Usage Alert", "Memory usage exceeded " + std::to_string(memoryThreshold) + "%");
    }
    if (diskSpaceUsage > diskSpaceThreshold) {
        sendEmailAlert("Disk Space Alert", "Disk space usage exceeded " + std::to_string(diskSpaceThreshold) + "%");
    }
    if (activeProcesses > activeProcessesThreshold) {
        sendEmailAlert("Active Processes Alert", "Active processes exceeded " + std::to_string(activeProcessesThreshold));
    }

    return 0;
}
