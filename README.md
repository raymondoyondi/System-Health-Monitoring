# System Health Monitoring Tool 📊

A robust, cross-platform system health monitoring solution developed in **C++** and **Shell**. This tool provides real-time insights into critical system metrics, allowing users to track performance and resource allocation efficiently.

---

## 🚀 Features

* **CPU Monitoring:** Real-time tracking of CPU utilization percentages.
* **Memory Management:** Detailed analysis of used vs. available RAM.
* **Disk Usage:** Monitoring of storage capacity and disk I/O health.
* **Process Tracking:** Overview of currently running processes and their resource consumption.
* **Cross-Platform:** Designed to work seamlessly across different operating systems.
* **Lightweight:** Minimal overhead on system resources while gathering data.

---

## 🛠️ Tech Stack

* **Language:** C++ (Core logic and data processing)
* **Scripting:** Shell (System-level data extraction and automation)
* **Platform:** Linux / macOS / Windows

---

## 📋 Prerequisites

Before you begin, ensure you have the following installed:
* A C++ compiler (GCC, Clang, or MSVC)
* `CMake` (for building the project)
* Standard Shell environment (Bash/Zsh)

---

## ⚙️ Installation & Setup

1.  **Clone the Repository**
    ```bash
    git clone [https://github.com/raymondoyondi/System-Health-Monitoring.git](https://github.com/raymondoyondi/System-Health-Monitoring.git)
    cd System-Health-Monitoring
    ```

2.  **Build the Project**
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

3.  **Run the Monitor**
    ```bash
    ./SystemHealthMonitor
    ```

---

## 📊 How It Works

The application utilizes a hybrid approach to fetch system metrics:

1.  **Shell Scripts:** Triggered to interface with low-level OS APIs (like `/proc` on Linux) to gather raw data.
2.  **C++ Engine:** Processes the raw data, calculates averages, and formats the output for the user interface.

---

## 🤝 Contributing

Contributions are welcome! If you have suggestions for improvements or new features:
1. Fork the Project.
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`).
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the Branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.
   
---

## 🛡️ License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
