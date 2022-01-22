// Need G4P library
import g4p_controls.*;
// You can remove the PeasyCam import if you are not using
// the GViewPeasyCam control or the PeasyCam library.
//import peasy.*;


public void setup() {
  size(480, 320, JAVA2D);
  createGUI();
  customGUI();
  colorMode(HSB);
  // Place your setup code here
}

int D = 50;
color col;
public void draw() {
  background(230);
  fill(col);
  circle(300, 160, D);       // Дорисовываем круг который будем менять с помощью ползунка
  
}

// Use this method to add additional statements
// to customise the GUI controls
public void customGUI() {
}
