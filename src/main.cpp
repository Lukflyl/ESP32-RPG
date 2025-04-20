#include <Arduino.h>
#include <TFT_eSPI.h>
#include "World.h"
#include "Player.h"
#include "Camera.h"
#include "constants.h"
#include "BoundingBox.h"

TFT_eSPI tft = TFT_eSPI();  // Create an instance of the TFT_eSPI class
TFT_eSprite canvas = TFT_eSprite(&tft);

const int FPS = 60;

const int PIN_JOYSTICK_X = 13;
const int PIN_JOYSTICK_Y = 12;
const int PIN_JOYSTICK_BTN = 15;

Camera camera;
World world;
Player player(world, WORLD_SIZE * UNIT_SIZE / 2 - 50, WORLD_SIZE * UNIT_SIZE / 2, {WORLD_SIZE * UNIT_SIZE / 2, WORLD_SIZE * UNIT_SIZE / 2, 9, 0, UNIT_SIZE - 1, 2 * UNIT_SIZE - 1});
long current_time = millis();
long last_update_time = current_time;

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);  // Set screen rotation (optional)
  canvas.createSprite(tft.width(), tft.height());  // Same size as screen
  world.init();

  pinMode(PIN_JOYSTICK_X, INPUT);
  pinMode(PIN_JOYSTICK_Y, INPUT);
  pinMode(PIN_JOYSTICK_BTN, INPUT_PULLUP); // Use pull-up resistor for button
}

int convert_joystick_output(int value) {
  if (value >= 1536 && value <= 2560) {
    return 0;
  }
  if (value > 2560) {
    return map(value, 2560, 4095, 1, 96);
  }
  if (value < 1536) {
    return map(value, 0, 1536, -96, -1);
  }
  return 0;
}

//TODO: solve in camera.cpp why going to position ~[27, 6] results in out of bounds tiles
void loop() {
  current_time = millis();
  long delta_time_i = current_time - last_update_time;
  if (delta_time_i <= 1000 / FPS) {
    return;
  }
  double delta_time_d = delta_time_i / 1000.0;
  last_update_time = current_time;
  // Serial.println("FPS: " + String(1 / delta_time));

  int dx = convert_joystick_output(analogRead(PIN_JOYSTICK_X)) * delta_time_d;
  int dy = -convert_joystick_output(analogRead(PIN_JOYSTICK_Y)) * delta_time_d;
  bool buttonPressed = digitalRead(PIN_JOYSTICK_BTN) == LOW;

  player.update(dx, dy);
  camera.follow(player);

  canvas.fillSprite(TFT_RED);
  world.draw(canvas, camera);
  player.draw(canvas, camera);

  canvas.pushSprite(0, 0);
}
