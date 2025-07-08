/*
 * Nidra EEG Headset - ESP32 + TGAM1 + Bluetooth
 * Reads data from TGAM1 EEG module and forwards it via Serial/Bluetooth
 * For use with NeuroSky-compatible apps like Brainwave Visualizer
 */

// Define TGAM1 connection (Serial1)
#define RXD1 16   // TGAM TX → ESP32 RX
#define TXD1 17   // Optional, if you want to send back data

void setup() {
  Serial.begin(115200);           // Debugging via USB
  Serial1.begin(57600, SERIAL_8N1, RXD1, TXD1);  // TGAM module

  Serial.println("Nidra EEG Headset Initialized");
}

void loop() {
  // Read data from TGAM1 and forward to Serial Monitor or external BT stream
  while (Serial1.available()) {
    uint8_t eegByte = Serial1.read();

    // Forward EEG data for debugging / logging
    Serial.write(eegByte);  // Or send to Bluetooth if set up
  }
}
