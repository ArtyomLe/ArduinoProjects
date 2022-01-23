import controlP5.*;
ControlP5 cp5;

void setup() {
 size(400, 600);
 cp5 = new ControlP5(this);
 cp5.setFont(createFont("Ubuntu", 20));
 cp5.addButton("btn").setPosition(10, 10).setSize(100, 30).setLabel("button 1");
 cp5.addSlider("slider").setPosition(10, 50).setSize(180, 30).setLabel("size");

}

void btn() {
 println("click");
}

void draw() {
 background(120);
}
