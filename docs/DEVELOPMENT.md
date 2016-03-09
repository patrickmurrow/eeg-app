Development Guide
-----------------

- Last updated 08 October 2015.
- Author: Philip Hodder
- This file contains a high-level description of each class,
  how the classes interact, and what features the provide 
  to the application as a whole.
- Note: There are some largish changes being made in eegRefactor branch,
  this will cause some structural changes to the program. See
  <EEG Subsystem Architecture>.
- *When adding new files to the application* make sure to add them
  to the project file 'eeg-gui.pro'. Then run $qmake to generate a
  new Makefile.

Program Architecture
--------------------

- The various subsystems of the program are listed below. Including
  information about components, structure, and tips for modifying the
  code base.

EEG Subsystem Architecture
--------------------------

- The EEG subsystem is currently being refactored. We will go over the
  current subsystem, and then specify the intended changes (hopefully 
  implemented during October/November). The difference implementations are
  contained in separate git branches.
- Current Subsystem (master branch)
  - Components:
    - EEGDisplayWidget
    - EEGDisplayCProxy
    - EEGDataDelete
    - DisplayContainer
    - BrainlinkHS
    - BrainlinkSerial
    - BrainlinkParser
  - Interactions
    - The Application creates a DisplayContainer and EEGDisplayWidget.
      The EEGDisplayWidget is responsible for drawing EEGData and
      performing graphical-based changes to the data (such as highlight
      and delete).
    - The EEGDisplayCProxy and various Brainlink classes are used to perform
      EEG data reading and forwarding to the application (EEGDisplayWidget).
    - EEGDataDelete creates object representations of delete operations on data
      so that they can undone via an undo-stack.
  - Issues:
    - EEGDisplayWidget is a 'God' class. Making it impossible to do some
      fundamental EEG operations without the GUI.
    - Headset abstraction isn't very clear.
    - There is no way to pass the EEG data around outside of EEGDisplayWidget.

- The main difference between the old subsystem and the new subsystem is
  that more functionality has been abstracted. The EEG is now saved in 
  its own data structure(EEGData). The EEGDisplayWidget has less functionality, and
  the EEGManager has become the interface between the application and
  library.
- New Subsystem (eegRefactor branch)
  - Components:
    - DisplayContainer
    - EEGDisplayWidget
    - EEGDataDelete
    - EEGManager
    - EEGData
    - HeadsetManager
    - BrainlinkHS
    - BrainlinkSerial
    - BrainlinkParser
  - Interactions
    - EEGData is a container for the all the data read in. Provides basic support
      for multi-channel use.
    - EEGManager is the main class involved in EEGData collection.
      It starts/stops the eeg data flow and stores it into the EEGData.
      Extracts some of the functionality from master EEGDisplayWidget.
    - HeadsetManager is a reimplementation of EEGDisplayCProxy. Allowing
      for better defined abstraction of headsets. The common link
      between any headsets that may be used and the higher level
      components of the program.

- Modifying:
  - I (Phil) *WILL* ensure the refactor is complete by November.
  - Modifying to be defined.

Bluetooth Subsystem Architecture
--------------------------------

- Reponsible for finding, creating, and maintaining Bluetooth
  connections.

- Util Components:
  - BluetoothConnectThread
  - BluetoothItem
  - BluetoothManager
  - BluetoothSearchThread
- Interface Components:
  - BluetoothButtonbar
  - BluetoothDisplayWidget
  - SettingsBluetoothTab
- Interactions:
  - The Interface with typically interact with the Util via the 
    BluetoothManager. The BluetoothManager provides a common interface
    between the UI and lower level activities.
  - The BluetoothItem is the data structure that is passed between the 
    utilities and interface. Containing information about Bluetooth 
    devices available to interact with.
  - The BluetoothSearchThread and BluetoothConnectThread are threads
    which are responsible for Searching and Connecting to Bluetooth 
    devices.

- Modifiying:
  - If you want to implement some new networking funcitonality,
    ensure you create the functionality in a thread so the application
    doesn't block.
  - BluetoothManager should be the interface for calling any networking
    behaviours.
  - Should it be required, consider creating an internal representation of
    BluetoothItem (like EEGData).
  - Qt4 does *not* have Bluetooth libraries provided by Qt, so used BlueZ or
    BASH. If necessary, attempt the basic funcitonality in an independent
    application.
  - Scripts belong in the scripts/ directory in the project. 

Testing Subsystem
-----------------

- The Testing Subsystem is currently much smaller than the
  Bluetooth and EEG subsystems. It is responsible for display
  visual queues to the user, while recording EEG data, and saving
  relevant markers into the data.
- Components:
  - TestWindow
  - TestSlide
- Interactions:
  - The TestWindow is a full screen window, containing the
    TestSlides ot present. Iterating over each slide
    based on the particular slide paramters (such as time to live).
- Limitations:
  - Not fully fleshed out or abstracted. Creating a slide show currently
    involves changing code in TestWindow.cpp. Creating one via text input
    or a ui would be handy when used more frequently.
  - The name of the subsystem seems kind of ambiguous, perhaps a
    renaming during a refactor may be appropriate.

- Modifying:
  - Basic modifications to the test slides can be done in testWindow.cpp.
  - Simply add/remove slides as done in the TestWindow constructor.
  - More complicated modifications may warrant some thought/refactoring.

Interface
---------

- The GUI uses Qt4. The widget hierarchy (ignoring basic components) is:
  - MainMenu
    - TestTab
      - DisplayContainer
        - EEGDisplayWidget
	  - <See EEG subsection>
      - TestWindow
      	- TestSlide
    - SettingsTab
      - SettingsGeneralTab
      - SettingsBluetoothTab
      	- BluetoothDisplayWidget
	  - BluetoothItem
	- BluetoothButtonBar
    - ViewerTab
      - DisplayContainer
      	- EEGDisplayWidget
	  - <See EEG subsection>

TestTab vs ViewerTab?
---------------------

- There are some obvious similarities between TestTab and ViewerTab.
  The existence of the two tabs *is* intentional.
- TestTab is responsible for collecting data and saving it.
- ViewerTab is responsible for loading data and manipulating it.
- Most of ViewerTabs functionality has not been implemented yet. This
  is mainly because it is dependent on a few other features. Specifically,
  having file I/O working. Since file I/O is not yet implmented, no
  ViewerTab. 

Command Line Interface
----------------------

- The barebones of a command line interface application are in the works.
- It is dependent on the EEG refactor being completed (see EEG Subsystem).
- Modifying:
  - Given the small size of the command line interface processing, implementing
    new functionality should only involve changing flags in main.cpp,
    commandLineApp.cpp, and respective method calls.
  - Keep in mind this is dependent on other subsections of the application.
    So, ensure the unlying functionality exists first.

Recommended Reading
-------------------

- Qt signals and slots:
  http://doc.qt.io/qt-4.8/signalsandslots.html
- BlueZ:
  https://people.csail.mit.edu/albert/bluez-intro/c404.html
