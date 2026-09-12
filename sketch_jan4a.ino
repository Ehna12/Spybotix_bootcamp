#include <MD_MAX72xx.h>
#include <SPI.h>

// ================= MATRIX =================
#define DATA_PIN 11
#define CLK_PIN  13
#define CS_PIN   10
#define MAX_DEVICES 1

MD_MAX72XX matrix = MD_MAX72XX(
  MD_MAX72XX::FC16_HW,
  DATA_PIN,
  CLK_PIN,
  CS_PIN,
  MAX_DEVICES
);

// ================= INPUTS =================
#define BUTTON_PIN 2
#define TRIG_PIN   3
#define ECHO_PIN   4

// ================= GAME =================
#define WIDTH 8
#define HEIGHT 8
#define BLOCK_WIDTH 8

int blockX = 0;
int blockY = 0;

bool stacked[HEIGHT][WIDTH];

// ================= ULTRASONIC LIMITS =================
const int minDist = 5;
const int maxDist = 25;

long lastValidDistance = 12;   // safe start value

// ====================================================
void setup() {
  Serial.begin(9600);
  Serial.println("System Started");

  matrix.begin();
  matrix.clear();

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (int r = 0; r < HEIGHT; r++)
    for (int c = 0; c < WIDTH; c++)
      stacked[r][c] = false;
}

// ====================================================
long getDistance() {
  long duration;
  long distance;

  // Clean trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo with timeout
  duration = pulseIn(ECHO_PIN, HIGH, 25000);

  // If no echo or noise
  if (duration < 100) {
    Serial.println("Invalid pulse");
    return lastValidDistance;
  }

  distance = duration * 0.034 / 2;

  // Reject out-of-range values
  if (distance < minDist || distance > maxDist + 5) {
    Serial.println("Out of range");
    return lastValidDistance;
  }

  lastValidDistance = distance;
  return distance;
}

// ====================================================
void drawMatrix() {
  matrix.clear();

  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      if (stacked[r][c]) {
        matrix.setPoint(7 - r, c, true);
      }
    }
  }

  for (int c = blockX; c < blockX + BLOCK_WIDTH; c++) {
    matrix.setPoint(7 - blockY, c, true);
  }
}

// ====================================================
void loop() {

  long dist = getDistance();
  dist = constrain(dist, minDist, maxDist);

  blockX = map(dist, minDist, maxDist, 0, WIDTH - BLOCK_WIDTH);

  // ===== SERIAL DEBUG =====
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.print(" cm | BlockX: ");
  Serial.println(blockX);

  drawMatrix();

  // ===== DROP BLOCK =====
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(200);

    for (int c = blockX; c < blockX + BLOCK_WIDTH; c++) {
      stacked[blockY][c] = true;
    }

    blockY++;

    if (blockY >= HEIGHT) {
      Serial.println("Game Reset");

      blockY = 0;
      for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++)
          stacked[r][c] = false;
    }

    while (digitalRead(BUTTON_PIN) == LOW);
  }

  delay(70); // ultrasonic stability
}
