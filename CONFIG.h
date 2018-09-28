#pragma once
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Arduino.h>
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _DEBUG // закомментировать для выключения отладочной информации (плюётся в Serial всякой отладочной инфой)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define SERIAL_SPEED 57600  // скорость работы с Serial
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// определения типов памяти, поддерживаемых прошивкой (не менять, это просто определения)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define EEPROM_BUILTIN 1 // встроенный EEPROM
#define EEPROM_AT24C32 2 // I2C-память AT24C32 
#define EEPROM_AT24C64 3 // I2C-память AT24C64 
#define EEPROM_AT24C128 4 // I2C-память AT24C128 
#define EEPROM_AT24C256 5 // I2C-память AT24C256 
#define EEPROM_AT24C512 6 // I2C-память AT24C512 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// какую память используем (менять ниже, на одно из значений, описанных выше)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define EEPROM_USED_MEMORY EEPROM_BUILTIN // по умолчанию используем встроенную в мегу память (типы памяти см. в Configaration_Shared.h)
// если используется внешнняя память AT24C* - то ниже определяется индекс микросхемы. Например, китайский модуль часов реального времени
// с DS3231 на борту имеет модуль памяти с адресом на шине I2C 0x57, т.е. индекс такого модуля - 7, т.к. базовый адрес памяти на шине - 
// 0x50. Настройкой ниже можно указать адрес микросхемы памяти на шине I2C.
#define EEPROM_MEMORY_INDEX 0
//--------------------------------------------------------------------------------------------------------------------------------
#define SETT_HEADER1 0x1F // байты, сигнализирующие о наличии сохранённых настроек, первый
#define SETT_HEADER2 0xBF // и второй
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// типы поддерживаемых дисплеев (не менять, это просто определения)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DISPLAY_TFT 1 // 3.2 '' 480х320 на контроллере ILI9481
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// под какой дисплей собираем прошивку
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DISPLAY_USED DISPLAY_TFT
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TFT_MODEL CTE32HR  // 3.2 '' 480х320 на контроллере ILI9481
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TFT RS pin
#define TFT_RS_PIN 38
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TFT WR pin
#define TFT_WR_PIN 39
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TFT CS pin
#define TFT_CS_PIN 40
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TFT RST pin
#define TFT_RST_PIN 41
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// время в миллисекундах, после которого идёт переключение на главный экран, если какой-то экран висит долгое время
#define RESET_TO_MAIN_SCREEN_DELAY 300000
// сколько ждать инициализации дисплея, мс
#define DISPLAY_INIT_DELAY 1000
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки энкодера
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// пины энкодера и кнопка энкодера - подтянуты к питанию резисторами на 10К !!!
#define ENCODER_A_PIN A1
#define ENCODER_B_PIN A2
#define ENCODER_BUTTON_PIN A3
#define ENCODER_PPC 10 // количество импульсов на клик, подбирать для удобства
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ДАЛЕЕ - СЛУЖЕБНАЯ ИНФОРМАЦИЯ, НЕ МЕНЯТЬ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// \/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef _DEBUG
  #define DBG(s) { Serial.print((s)); }
  #define DBGLN(s) { Serial.print((s)); Serial.println(); }
#else
  #define DBG(s) (void) 0
  #define DBGLN(s) (void) 0
#endif
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CORE_COMMAND_GET F("GET=") // префикс для команды получения данных из ядра
#define CORE_COMMAND_SET F("SET=") // префикс для команды сохранения данных в ядро
#define CORE_COMMAND_ANSWER_OK F("OK=") // какой префикс будет посылаться в ответ на команду получения данных и её успешной отработке
#define CORE_COMMAND_ANSWER_ERROR F("ER=") // какой префикс будет посылаться в ответ на команду получения данных и её неуспешной отработке
#define CORE_COMMAND_PARAM_DELIMITER '|' // разделитель параметров
#define CORE_END_OF_DATA F("[END]")
#define CORE_COMMAND_DONE F("DONE")
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

