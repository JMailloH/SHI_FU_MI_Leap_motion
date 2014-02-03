/******************************************************************************\
* Copyright (C) 2012-2013 Leap Motion, Inc. All rights reserved.               *
* Leap Motion proprietary and confidential. Not for distribution.              *
* Use subject to the terms of the Leap Motion SDK Agreement available at       *
* https://developer.leapmotion.com/sdk_agreement, or another agreement         *
* between Leap Motion and you, your company or other organization.             *
\******************************************************************************/

#include <iostream>
#include "interfaz.h"
#include "Leap.h"
using namespace Leap;


class SampleListener : public Listener {
  public:
    virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);
};

void SampleListener::onInit(const Controller& controller) {
  std::cout << "Initialized" << std::endl;
}


void SampleListener::onConnect(const Controller& controller) {
  std::cout << "Connected" << std::endl;
/*  controller.enableGesture(Gesture::TYPE_CIRCLE);
  controller.enableGesture(Gesture::TYPE_KEY_TAP);
  controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
  controller.enableGesture(Gesture::TYPE_SWIPE);
*/  
}

void SampleListener::onDisconnect(const Controller& controller) {
  //Note: not dispatched when running in a debugger.
  std::cout << "Disconnected" << std::endl;
}

void SampleListener::onExit(const Controller& controller) {
  std::cout << "Exited" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {
  // Get the most recent frame and report some basic information
  const Frame frame = controller.frame();
  		
  /*std::cout << "Frame id: " << frame.id()
            << ", timestamp: " << frame.timestamp()
            << ", hands: " << frame.hands().count()
            << ", fingers: " << frame.fingers().count()
            << ", tools: " << frame.tools().count()
            << ", gestures: " << frame.gestures().count() << std::endl;
	*/

   // ************************************************************* //
   // ******************* DETECCIÓN DE GESTOS ********************* //
   // ************************************************************* //

   if (!frame.hands().isEmpty()) {
    // Get the first hand
    const Hand hand1 = frame.hands()[0];

	// CUATRO DEDOS
	if(hand1.fingers().count() == 1){
		listo1 = true;
	}

	// PIEDRA --> MANO CERRADA 
	if(hand1.fingers().isEmpty()){
	  piedra1 = true; 
	}
	// TIJERAS --> DOS DEDOS
	if(hand1.fingers().count() == 2){
	  tijeras1 = true; 
	}
	// PAPEL --> MANO ABIERTA
	if(hand1.fingers().count() == 5){
	  papel1 = true;
	}
	
	
	if (frame.hands().count() == 2){
      const Hand hand2 = frame.hands()[1];
	  
	  // CUATRO DEDOS
	  if(hand2.fingers().count() == 1){
		 listo2 = true;
	  }
	  
	  
	  // PIEDRA --> MANO CERRADA
	  if(hand2.fingers().isEmpty()){
	     piedra2 = true; 
	  }

	  // TIJERAS --> DOS DEDOS
	  if(hand2.fingers().count() == 2){
		 tijeras2 = true;
	  }

	  // PAPEL --> MANO ABIERTA
	  if(hand2.fingers().count() == 5){
		  papel2 = true;
	  }
	}   

   }
}

void SampleListener::onFocusGained(const Controller& controller) {
  std::cout << "Focus Gained" << std::endl;
}

void SampleListener::onFocusLost(const Controller& controller) {
  std::cout << "Focus Lost" << std::endl;
}






using namespace System;
using namespace System ::Windows::Forms;
[STAThread]
void main(array<String^>^ arg) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   //TestForma es el nombre del proyecto
   Sample::interfaz form;

   // Create a sample listener and controller
   SampleListener listener;
   Controller controller;

   // Keep this process running until Enter is pressed
   std::cout << "Press Enter to quit..." << std::endl;
   std::cin.get();

   // Have the sample listener receive events from the controller
   controller.addListener(listener);

   Application::Run(%form);

   // Remove the sample listener when done
   controller.removeListener(listener);

}