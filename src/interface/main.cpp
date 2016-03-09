#include <QApplication>
#include <QtGui>
#include "../eeg/dummy/dummyHS.hpp"
#include "../eeg/brainlink/brainlinkHS.hpp"
#include "../eeg/openBCI/openBCIHS.hpp"
#include "../util/eeg/eegManager.hpp"
#include "./eeg-app/eegappmenu.h"

#include "bluetoothConnectThread.hpp"
#include "../../fft/fftCalc.hpp"

/**
 * printUsage
 *
 * Outputs usage information.
 */
void printUsage() {
  printf("Usage:\n");
  printf("\n");
  printf("No flags:\n\tLaunches EEG GUI application.\n");
  printf("\n");
  printf("-gui, -g:\n\tLaunches EEG GUI application.\n");
  printf("\n");
  printf("-t:\n\tLaunches command line application\n");
  printf("\twith default bluetooth parameters.\n");
  printf("\n");
  printf("-t [serialPath] [bluetoothAddr] [bluetoothChannel]");
  printf(":\n\tLaunches command line application with ");
  printf("specified bluetooth parameters.\n");
  printf("\n");
  printf("-help:\n\tOutputs usage information.\n");    
}

/**
 * useGuiMode
 *
 * Determines if GUI mode should be used according to CLI
 * flags. IF the first command line argument is '-gui' or '-g'
 * then this will return true.
 *
 * @param argv The arguments from CLI.
 * @return True if the first argument is '-gui' or '-g'.
 */
bool useGuiMode(char *argv[]) {
  return strcmp(argv[1], "-gui") == 0 ||
    strcmp(argv[1], "-g") == 0;
}

/**
 * useHelpMode
 *
 * Determines if Help mode should be used according to CLI 
 * flags. If the first command line argument is '-help' then
 * this will return true.
 *
 * @param argv The arguments from CLI
 * @return True if the first argument is '-help'
 */
bool useHelpMode(char *argv[]) {
  return strcmp(argv[1], "-help") == 0;
}

/**
 * useCLIMode
 *
 * Determines if CLI mode should be used according to CLI flags.
 * If the first command line argument is '-t' then will be true.
 *
 * @param argv The arguments from CLI
 * @return True if the first argument is '-t'
 */
bool useCLIMode(char *argv[]) {
  return strcmp(argv[1], "-t") == 0;
}

/**
 * The structure of this call here implies a structural
 * change to the = 0 application will be required. No worries.
 *
 * @TODO: Implement command line flag reading.
 *        For now, will just process a single flag and
 *        boot into CLI mode.
 */
int main(int argc, char *argv[]) {


  
  QApplication app(argc, argv);

  if (argc < 2) {
        FFTCalc *fft_app = new FFTCalc();
        int samples = fft_app->getNumSamples();
        //EEGHeadset *h = new MuseHS();
        EEGHeadset *h = new OpenBCIHS();
        EEGManager *em = new EEGManager(8, h, samples);
        fft_app = new FFTCalc(em, true);
        return app.exec();
  } else if (strcmp(argv[1], "-fc") == 0) {
        FFTCalc *fft_app = new FFTCalc();
        int samples = fft_app->getNumSamples();
        //EEGHeadset *h = new MuseHS();
        EEGHeadset *h = new OpenBCIHS();
        EEGManager *em = new EEGManager(8, h, samples);
        fft_app = new FFTCalc(em, false);
        return app.exec();
    }else if (strcmp(argv[1], "-e") == 0) {
        EEGAppMenu *window = new EEGAppMenu(0);
        window->resize(245, 365);
        window->move(300, 300);
        window->setWindowTitle("");
        window->show();
        return app.exec();
  }  else if (useHelpMode(argv)) {
    printUsage();
    return EXIT_SUCCESS;
  }else {
    printf("Invalid flag, printing usage:\n");
    printUsage();
    return EXIT_FAILURE;
  }
}

