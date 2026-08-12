
# 🏥 ZAOMS + OdorTrace

### Zone-Aware Adaptive Hospital Odor Management & Source Tracking System

> **Sense → Contextualize → Identify → Respond → Verify → Learn**

ZAOMS + OdorTrace is a smart hospital facility-management system designed to detect abnormal odor events, identify their likely source zone, trigger an appropriate response, verify whether the problem has been resolved, and generate actionable maintenance insights.

The system focuses on hospital environments such as **Dirty Utility/Sluice Rooms, Biomedical Waste Areas, Washrooms, Linen Rooms, Corridors, and Patient Wards**.

---

## 🎯 Problem

Hospital odor problems are often discovered only after:

- Patients or staff complain
- Housekeeping manually investigates the area
- The odor has already spread
- The source is difficult to identify
- There is no measurement of whether the problem was actually resolved

Existing solutions such as conventional HVAC, smart bins, and standalone odor-control devices generally operate independently and provide limited **context, source localization, and post-treatment verification**.

---

## 💡 Our Solution

ZAOMS + OdorTrace combines environmental sensing, sensor fusion, zone intelligence, response automation, and verification into one platform.

```text
Sensors
   ↓
Detect Abnormal Pattern
   ↓
Contextualize Event
   ↓
Identify / Locate Source
   ↓
Dynamic Response
   ↓
Verify Clearance
   ↓
Maintenance Intelligence
````

### Core capabilities

* Multi-sensor odor-event detection
* Hospital zone monitoring
* Likely source localization
* Occupancy-aware response
* Dynamic ventilation control
* Time-to-Clear measurement
* Removal-efficiency estimation
* Estimated filter-health monitoring
* Maintenance alerts
* Centralized dashboard
* Historical event tracking

---

# 🧠 System Architecture

```text
┌─────────────────────────────────────────┐
│           SENSOR LAYER                  │
│ H₂S │ NH₃ │ TVOC │ Temp │ Humidity      │
│ PIR │ Door │ Differential Pressure       │
└──────────────────┬──────────────────────┘
                   ↓
┌─────────────────────────────────────────┐
│          EDGE INTELLIGENCE              │
│              ESP32                      │
│                                         │
│ Baseline Tracking                       │
│ Event Detection                         │
│ Sensor Fusion                           │
│ Context Analysis                        │
└──────────────────┬──────────────────────┘
                   ↓
┌─────────────────────────────────────────┐
│          RESPONSE ENGINE                │
│                                         │
│ Dynamic Exhaust                         │
│ Carbon Filtration                       │
│ Occupancy-aware Control                 │
└──────────────────┬──────────────────────┘
                   ↓
┌─────────────────────────────────────────┐
│          VERIFICATION                   │
│                                         │
│ Time-to-Clear                            │
│ Removal Efficiency                       │
│ Event Resolution                         │
└──────────────────┬──────────────────────┘
                   ↓
┌─────────────────────────────────────────┐
│          DASHBOARD                      │
│                                         │
│ Live Zones │ Events │ Analytics         │
│ Hospital Map │ Maintenance              │
└─────────────────────────────────────────┘
```

---

# 🔬 Sensor Layer

The prototype uses environmental sensors as **odor-event trend indicators**.

| Sensor                | Purpose                         |
| --------------------- | ------------------------------- |
| H₂S                   | Organic/waste-related gas trend |
| NH₃                   | Waste/urine-related gas trend   |
| TVOC                  | Broad chemical/VOC trend        |
| Temperature           | Environmental correction        |
| Humidity              | Environmental correction        |
| PIR                   | Occupancy detection             |
| Door/Reed Switch      | Door/bin activity               |
| Differential Pressure | Airflow/filter monitoring       |

> Sensors are used for environmental monitoring and trend detection. They are not medical diagnostic instruments.

---

# 🔄 Closed-Loop Control

Unlike a simple:

```text
Gas detected → Fan ON
```

our system uses:

```text
Gas anomaly
     ↓
Context analysis
     ↓
Response
     ↓
Measure gas decay
     ↓
Verify clearance
     ↓
Log result
```

### Example

If an abnormal gas pattern occurs in the Dirty Utility Room:

```text
H₂S ↑
NH₃ ↑
Door opened
Occupancy detected
       ↓
Odor Event Detected
       ↓
Increase Exhaust
       ↓
Activate Filtration
       ↓
Monitor Gas Decay
       ↓
Calculate Time-to-Clear
       ↓
Mark Event Resolved
```

---

# 📊 Dashboard

The web dashboard provides a centralized view of the hospital environment.

### Overview

Displays:

* Total monitored zones
* Safe zones
* Warning zones
* Critical zones
* Active odor events
* Average Time-to-Clear
* Removal efficiency
* Estimated filter health

### Live Zones

Each zone provides:

```text
Zone: Dirty Utility Room

H₂S:       Elevated
NH₃:       Elevated
TVOC:      Normal

Occupancy: Detected
Fan:       72%
Filter:    76%

Status:    CRITICAL
```

### Odor Events

Each event records:

* Event ID
* Zone
* Severity
* Likely source
* Confidence
* Sensor readings
* Response
* Time-to-Clear
* Removal efficiency
* Resolution status

### Hospital Map

Zones are represented using status indicators:

```text
🟢 SAFE
🟡 WARNING
🔴 CRITICAL
```

---

# 📐 Verification Metrics

## Time-to-Clear

Measures how long an odor-event indicator takes to return toward its baseline.

```text
Tclear = Baseline Recovery Time - Event Detection Time
```

Example:

```text
Event detected:       14:32:10
Baseline recovered:   14:34:44

Time-to-Clear:        2m 34s
```

## Removal Efficiency

The prototype estimates:

```text
E = ((Cinitial - Cfinal) / Cinitial) × 100
```

Example:

```text
Initial concentration = 100
Final concentration   = 18

Removal Efficiency = 82%
```

---

# 🛠️ Technology Stack

### Frontend

* React
* TypeScript
* Vite
* Tailwind CSS
* Recharts
* Lucide React

### Embedded

* ESP32
* Gas sensors
* Environmental sensors
* PIR sensor
* Door/reed sensor
* Fan controller

### Communication

* MQTT
* Wi-Fi

### Planned Backend

* Node.js / FastAPI
* PostgreSQL / Time-series database
* MQTT broker

---

# 🧪 Simulation Mode

The dashboard includes a simulated odor-event workflow for demonstration.

Click:

**`SIMULATE ODOR EVENT`**

The system will:

1. Increase simulated H₂S
2. Increase simulated NH₃
3. Change the affected zone to Critical
4. Increase fan speed
5. Activate filtration
6. Display the gas spike
7. Simulate gas reduction
8. Calculate Time-to-Clear
9. Calculate Removal Efficiency
10. Mark the event as Resolved
11. Add the event to history

This allows the complete system workflow to be demonstrated before real sensor integration.

---

# 🚀 Getting Started

## Prerequisites

* Node.js 18+
* npm

## Installation

```bash
git clone https://github.com/YOUR_USERNAME/zaoms-odortrace.git

cd zaoms-odortrace

npm install
```

## Run Development Server

```bash
npm run dev
```

Open the local development URL shown in the terminal.

---

# 📁 Project Structure

```text
zaoms-odortrace/
│
├── public/
│
├── src/
│   ├── components/
│   ├── pages/
│   ├── layouts/
│   ├── services/
│   ├── hooks/
│   ├── types/
│   ├── data/
│   └── utils/
│
├── package.json
├── tsconfig.json
├── vite.config.ts
└── README.md
```

---

# 🔌 Future Hardware Integration

The current dashboard uses mock data.

The planned real-time architecture is:

```text
H₂S ───────┐
NH₃ ───────┤
TVOC ──────┤
PIR ───────┤
Door ──────┤
Temp/RH ───┘
      ↓
    ESP32
      ↓
    MQTT
      ↓
   Backend
      ↓
   Database
      ↓
   Dashboard
```

The frontend is structured so that mock data can later be replaced with real API/MQTT telemetry.

---

# 🏥 Safety

This project is intended for **hospital facility management and environmental monitoring**.

### Safety principles

* No disease diagnosis
* No infection diagnosis from odor
* No medical claims
* No ozone generation in the MVP
* Environmental sensors are treated as trend indicators
* Safety-critical control should remain local to the edge device
* Sensor/network failures should result in a safe operating state

---

# 🌟 Innovation

The innovation is not simply using gas sensors or IoT.

The proposed system combines:

```text
Multi-Sensor Detection
        +
Context Awareness
        +
Zone Source Localization
        +
Dynamic Response
        +
Closed-Loop Verification
        +
Maintenance Intelligence
```

This transforms a conventional air-quality monitoring system into a **hospital facility-management decision and response platform**.

---

# 🏆 Hackathon Demonstration

The prototype demonstrates:

```text
DETECT
   ↓
IDENTIFY
   ↓
LOCATE
   ↓
ALERT
   ↓
RESPOND
   ↓
VERIFY
   ↓
MAINTAIN
```

### Example

A simulated odor event occurs near the Biomedical Waste Area.

The dashboard detects the abnormal sensor pattern, identifies the affected zone, displays the event severity, activates the simulated ventilation response, tracks gas recovery, calculates Time-to-Clear and Removal Efficiency, and records the event for maintenance.

---

# 🔮 Future Scope

* Real ESP32 sensor integration
* Multiple distributed sensor nodes
* MQTT real-time telemetry
* AI-based odor-source classification
* Advanced source localization
* Predictive maintenance
* Hospital HVAC integration
* BACnet/Modbus integration
* Mobile notifications
* Automated maintenance-ticket generation
* Historical anomaly learning

---

# ⚠️ Current Limitations

The current version is a **hackathon prototype**.

It uses simulated data and/or low-cost environmental sensors and therefore should not be treated as a certified hospital safety or exposure-monitoring system.

Real-world deployment would require:

* Sensor calibration
* Medical/hospital engineering validation
* Safety testing
* HVAC integration testing
* Appropriate regulatory and facility approvals

---

## Circuit Design

# IoT Smart Environmental & Safety Monitoring System

This project is an IoT-based environmental monitoring and safety automation system. It monitors air quality, temperature, humidity, and motion to automatically trigger active ventilation and safety mechanisms.

## Circuit Diagram

<p align="center">
  <img src="images/circuit-diagram.png" alt="IoT Monitoring Circuit Diagram" width="850">
</p>

## Hardware Components

The system utilizes the following components as shown in the schematic:

### Core Microcontroller
* **ESP32 NodeMCU Development Board** – Handles sensor data, logic execution, and Wi-Fi connectivity.

### Sensors
* **DHT22 / DHT11** – Measures ambient temperature and relative humidity.
* **MQ-Series Gas Sensors (x2)** – Detects smoke, LPG, carbon monoxide, or flammable gases.
* **PIR Motion Sensor (HC-SR501)** – Detects presence or movement in the monitored area.

### Actuators & Power
* **12V DC Cooling Fan** – Provides automated ventilation when gas or temperature thresholds are exceeded.
* **12V Solenoid Valve / Linear Actuator** – Triggers physical safety cut-offs or locks.
* **Power Transistors / MOSFETs & Diodes** – Used to safely switch the high-current 12V fan and solenoid from the ESP32 logic pins.
* **DC Barrel Jack Adapter** – Supplies external 12V power to the high-draw actuators.
---

## 👥 Team

**Project:** ZAOMS + OdorTrace
**Domain:** IoT • Embedded Systems • AI • Smart Hospital Facility Management

---

## 📜 License

This project is currently developed as a hackathon prototype.

```
```
