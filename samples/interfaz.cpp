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
private:
	long int delay;
	long int Tmuestra;
};

void SampleListener::onInit(const Controller& controller) {
  std::cout << "Initialized" << std::endl;
  delay = 500000000000;
  Tmuestra = 0;
}


void SampleListener::onConnect(const Controller& controller) {
  std::cerr << "Connected" << std::endl;
}

void SampleListener::onDisconnect(const Controller& controller) {
  //Note: not dispatched when running in a debugger.
  std::cerr << "Disconnected" << std::endl;
}

void SampleListener::onExit(const Controller& controller) {
  std::cerr << "Exited" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {
   // Get the most recent frame and report some basic information
   const Frame frame = controller.frame();
   
   // No reconocemos si es piedra papel o tijera hasta que no se encuentren las dos manos dentro
   if (frame.hands().count() == 2) {
    Hand hand1 = frame.hands()[0];
	Hand hand2 = frame.hands()[1];

	Leap::Vector position = hand1.palmPosition();
	
	// Asignamos el jugador 1 (hand1) a la mano que esté situada a la izquierda
	// y a la que esté situada a la derecha le asignamos el jugador 2
	if (position[0] >= 0){
		hand1 = frame.hands()[1];
		hand2 = frame.hands()[0];
	}
	
	// Comprobamos que se de un cierto delay entre los frames
	if((frame.timestamp() - Tmuestra) < delay) return;
	Tmuestra = frame.timestamp();
	
	// PIEDRA --> MANO CERRADA 
	if(hand1.fingers().isEmpty()){
	  jug1_piedra = true; 
	}

	// TIJERAS --> DOS DEDOS
	if(hand1.fingers().count() == 2){
	  jug1_tijeras = true; 
	}

	// PAPEL --> MANO ABIERTA
	if(hand1.fingers().count() == 5){
	  jug1_papel = true;
	}
	  
	// PIEDRA --> MANO CERRADA
	if(hand2.fingers().isEmpty()){
	   jug2_piedra = true; 
	}

	// TIJERAS --> DOS DEDOS
	if(hand2.fingers().count() == 2){
		jug2_tijeras = true;
	}

	// PAPEL --> MANO ABIERTA
	if(hand2.fingers().count() == 5){
	  jug2_papel = true;
	}  
	jugadores_listos = true;

   }
}

void SampleListener::onFocusGained(const Controller& controller) {
  std::cerr << "Focus Gained" << std::endl;
}

void SampleListener::onFocusLost(const Controller& controller) {
  std::cerr << "Focus Lost" << std::endl;
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
   std::cerr << "Press Enter to quit..." << std::endl;
//   std::cin.get();

   // Have the sample listener receive events from the controller
   controller.addListener(listener);

   Application::Run(%form);

   // Remove the sample listener when done
   controller.removeListener(listener);

}