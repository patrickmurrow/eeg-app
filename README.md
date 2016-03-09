EEG GUI
-------

- A GUI application to allow ease of use for various tasks relating to BCI.
- User guide to be written later.

Bluetooth Headsets
------------------

- The headsets required specific channels to connect via bluetooth.
- Brainlink: channel 6.
- Muse: channel 1.
- There is probably a way to automate finding the channel. But, the
  number of possible channels is small enough to brute force. (1-30)

How to run
----------

- Make sure you have the required dependencies installed (see next).
- Run:
  $qmake
  $make
  $./build/eeg-gui

Dependencies/Install Guide
--------------------------

  QT
  --
  - Need to have Qt4.8 installed, as well qmake.
  - $sudo apt-get install build-essential
  - $sudo apt-get install libqt4-dev
  - Create the project file by running $qmake -project
  - In eeg-pro.pro, add the line "QMAKE_CXXFLAGS += -std=c++11".
  - To create the Makefile: $qmake
  - $make
  Bluetooth
  ---------
  - To use bluetooth libraries, install bluez-dev.
  - $sudo apt-get install libbluetooth-dev
  - This will install the required bluetooth headers.

Usage
-----

- Command line flags:
  - No flags: Launches GUI mode.
  - -gui, -g: Launches GUI mode.
  - -t:	      Launches CLI mode, using default bluetooth values.
  - -t [serialPath] [bluetoothAddr] [bluetoothChannel]:
       	      Launches CLI mode, using specified bluetooth values.
  - -help:    Outputs usage information.

- To launch the application with the GUI, run as normal:
  - $ ./build/eeg-gui

- To connect the device to Bluetooth:
  - Click on 'Settings' on the side bar.
  - Select the 'Bluetooth' tab.
  - Select the 'Search' button.
  - Wait for the search to find available Bluetooth devices.
  - Select the bluetooth device you want to connect to.
  - Select the 'Connect' button.

- To collect EEG data during a test environment:
  - Click on 'Test' on the side bar (should already by selected).
  - Select the test parameters on the top bar.
  - Click on 'Begin Test' to begin retrieving data.
  - There is a 'Save Data' button. File I/O has not been implemented yet.
    But, once it is, just select save data after if desired.

- To launch the application as a CLI program, run as follows:
  - $ ./build/eeg-gui -t
  - The program will automatically connect to the default headset and 
    output the EEG data it recieves to stdout.

How to contribute
-----------------

- Ensure you can build/run the current project normally.
- Read over docs/DEVELOPMENT.md
- It is necessary to familiarise yourself with the signal/slot paradigm
  that Qt uses. Consider reading the first few sections (everything before
  Meta-Object Information) of http://doc.qt.io/qt-4.8/signalsandslots.html.

Current TODO list
-----------------
 
- Fix memory leaks!
- Document code
- Implement check for command line flags
- Implement infrastructure for general program.
- File saving, automated connection to devices
- Saving data to files
- Loading data from files
- Implement better TestSlide application

Memory Leaks
------------

- It seems that Qt has some intentional memory leaks. An application with only
  a single button has a leak of about 3,928 bytes initally, with what seems
  to be a very gradual leak over time. 
- Will need to see how bad this can get, and what we may be able to fix.
- For Qt 4.8.
- Test on the Pi.

Bluetooth Threading
-------------------

- There is currently a multi-threading bug which causes the data collection
  fail. The cause is an overwrite of the file descriptor in brainlinkParser.cpp
  between thread execution. 
- This does not seem to occur on the quadcore Raspberry Pi. But does occur on
  a dualcore Mac.
- If threading bugs begin to occur during data collection, please consider
  this as a potential culprit!
