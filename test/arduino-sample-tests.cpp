#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"

#include "../arduino-sample.ino"

using ::testing::Return;
using::testing::_;

TEST(setup, test) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  SerialMock* serialMock = serialMockInstance();

  EXPECT_CALL(*serialMock, begin(9600));
  EXPECT_CALL(*serialMock, println("Hello world."));
  setup();
  
  releaseSerialMock();
  releaseArduinoMock();
}

TEST(loop, pushed) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  SerialMock* serialMock = serialMockInstance();
  
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(true));
  EXPECT_CALL(*serialMock, print("2 * 5 =="));
  EXPECT_CALL(*serialMock, println(10, 10)); // The , 10 is for base 10!
  loop();
  
  releaseSerialMock();
  releaseArduinoMock();
}

TEST(loop, not_pushed) {
  SerialMock* serialMock = serialMockInstance();
  ArduinoMock* arduinoMock = arduinoMockInstance();
  
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(false));
  EXPECT_CALL(*serialMock, println("Not pushed."));
  loop();
  
  releaseSerialMock();
  releaseArduinoMock();
}

TEST(doubler, unittest) {
  EXPECT_EQ(doubler(5), 10);
  EXPECT_EQ(doubler(0), 0);
  EXPECT_EQ(doubler(-10), -20);
  EXPECT_EQ(doubler(1), 2);
  EXPECT_EQ(doubler(1000), 2000);
}
