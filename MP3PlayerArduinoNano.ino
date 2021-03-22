/***************************************************
  DFPlayer - A Mini MP3 Player For Arduino
  <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
  This example shows the basic function of library for DFPlayer.

  Created 2016-12-07
  By [Angelo qiao](Angelo.qiao@dfrobot.com)

  GNU Lesser General Public License.
  See <http://www.gnu.org/licenses/> for details.
  All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
  1.Connection and Diagram can be found here
  <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
  2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int maxSongs  = 0;
int buttonPin = 7;
int fileNr = 1;
int buttonDebounceTimeInMs = 50; // debounced the button click for xxx ms
int playTimeInMs = 15 * 1000; // Length for playing music in ms = 15 sec.
int fileCountsInFolder = 0;

void printDetail(uint8_t type, int value);

class MP3FileStructure {
  public:
    MP3FileStructure()
      : playFolderName(FolderName::COMMON)
    {
    };

    enum FolderName {
      TECHNO = 1,
      CHRISTMAS = 2,
      COMMON = 3
    };
    FolderName playFolderName;

    int fileCountTechno = 4;
    int fileCountChristmas = 5;
    int fileCountCommon = 6;

    inline int getMaxFolderCount() {
      switch (playFolderName) {
        case FolderName::TECHNO: return fileCountTechno;
        case FolderName::CHRISTMAS: return fileCountChristmas;
        default: return fileCountCommon;
      }
    }
};

MP3FileStructure mp3FileStructure;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // Taster wird mit internem Pullup-Widerstand verwendet

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  //MP3-Player settings
  myDFPlayer.setTimeOut(500); //Timeout serial 500ms
  myDFPlayer.volume(30); //Set volume value. From 0 to 30
  //(0 = Normal, 1 = Pop, 2 = Rock, 3 = Jazz, 4 = Classic, 5 = Bass)
  myDFPlayer.EQ(1); //Equalizer normal
  //retrieves the number of Songs found in the SD.
  maxSongs = myDFPlayer.readFileCounts(DFPLAYER_DEVICE_SD);

  Serial.println();
  Serial.print("Numbers of mp3 files from SD: ");
  Serial.println(maxSongs);
}

void loop()
{
  static unsigned long timer = millis();
  if (digitalRead(buttonPin) == LOW) {    // wenn der Taster gedrückt wird
    timer = millis();
    Serial.println(F("play file nr: "));
    Serial.println(fileNr);
    myDFPlayer.playLargeFolder(mp3FileStructure.playFolderName, fileNr);           // spiele das erste MP3 von der SD-Karte
    fileNr++;
    if (fileNr == mp3FileStructure.getMaxFolderCount())
      fileNr = 1;
    fileCountsInFolder = myDFPlayer.readFileCountsInFolder(01);
    Serial.println(F("readFileCountsInFolder: "));
    Serial.println(fileCountsInFolder);
  }
  delay(buttonDebounceTimeInMs);

  if (millis() - timer > playTimeInMs) {
    myDFPlayer.stop();  //Play next mp3 every 3 second.
  }

  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
