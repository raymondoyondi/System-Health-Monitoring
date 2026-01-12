#!/bin/bash

# Set thresholds
cpuThreshold=80
memoryThreshold=80
diskSpaceThreshold=80
activeProcessesThreshold=100

# Set log file
logFile="system_health.log"

# Monitor system health
cpuUsage=$(top -bn1 | grep 'Cpu(s)' | awk '{print $2}' | awk -F. '{print $1}')
memoryUsage=$(free -m | awk 'NR==2{printf "%s", $3*100/$2 }' | sed 's/%//g')
diskSpaceUsage=$(df -h --output=pcent / | awk 'NR==2 {print $1}' | sed 's/%//g')
activeProcesses=$(ps -ef | wc -l)

# Log system health information
echo "[$(date)] System Health Dashboard:" >> $logFile
echo "------------------------" >> $logFile
echo "CPU Usage: $cpuUsage%" >> $logFile
echo "Memory Usage: $memoryUsage%" >> $logFile
echo "Disk Space Usage: $diskSpaceUsage%" >> $logFile
echo "Active Processes: $activeProcesses" >> $logFile
echo "------------------------" >> $logFile

# Display simple dashboard
echo "System Health Dashboard:"
echo "------------------------"
echo "CPU Usage: $cpuUsage%"
echo "Memory Usage: $memoryUsage%"
echo "Disk Space Usage: $diskSpaceUsage%"
echo "Active Processes: $activeProcesses"
echo "------------------------"

# Send email alerts if thresholds are exceeded
if (( $(echo "$cpuUsage > $cpuThreshold" | bc -l) )); then
    echo "CPU usage exceeded $cpuThreshold%" | mailx -s "CPU Usage Alert" dev.ckshetty@gmail.com
fi
if (( $(echo "$memoryUsage > $memoryThreshold" | bc -l) )); then
    echo "Memory usage exceeded $memoryThreshold%" | mailx -s "Memory Usage Alert" dev.ckshetty@gmail.com
fi
if (( $(echo "$diskSpaceUsage > $diskSpaceThreshold" | bc -l) )); then
    echo "Disk space usage exceeded $diskSpaceThreshold%" | mailx -s "Disk Space Alert" dev.ckshetty@gmail.com
fi
if (( activeProcesses > activeProcessesThreshold )); then
    echo "Active processes exceeded $activeProcessesThreshold" | mailx -s "Active Processes Alert" dev.ckshetty@gmail.com
fi
