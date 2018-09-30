//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// НАСТРОЙКИ ПРОШИВКИ, МЕНЯТЬ ЗДЕСЬ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
// ссылка на дисплей: https://ru.aliexpress.com/item/3-2-3-5-480-320-TFT/32917044135.html?spm=a2g0s.8937460.0.0.5e332e0ePfJQmX
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DISPLAY_USED DISPLAY_TFT // под какой дисплей собираем прошивку
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки модели и пинов для TFT
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TFT_MODEL   CTE32HR   // 3.2 '' 480х320 на контроллере ILI9481
#define TFT_RS_PIN  38        // TFT RS pin
#define TFT_WR_PIN  39        // TFT WR pin
#define TFT_CS_PIN  40        // TFT CS pin
#define TFT_RST_PIN 41        // TFT RST pin

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define RESET_TO_MAIN_SCREEN_DELAY  30000 // время в миллисекундах, после которого идёт переключение на главный экран, если какой-то экран висит долгое время
#define DISPLAY_INIT_DELAY          1000  // сколько ждать инициализации дисплея, мс

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки энкодера (используется со встроенной кнопкой)
// пины энкодера и кнопка энкодера - подтянуты к питанию резисторами на 10К !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ENCODER_A_PIN       A1 // пин вывода A энкодера
#define ENCODER_B_PIN       A2 // пин вывода A энкодера
#define ENCODER_BUTTON_PIN  A3 // пин вывода кнопки энкодера
#define ENCODER_PPC         10 // количество импульсов на клик, подбирать для удобства

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки кнопок "Влево" и "Вправо" (кнопки подтянуты к питанию резисторами на 10К и срабатывают по низкому уровню !!!)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define LEFT_BUTTON_PIN   A4 // пин кнопки "Влево"
#define RIGHT_BUTTON_PIN  A5 // пин кнопка "Вправо"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки шаговика (работа в режиме STEP/DIR)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define STEP_PIN                A6  // номер пина STEP
#define DIR_PIN                 A7  // номер пина DIR
#define EN_PIN                  A8  // номер пина EN
#define MICROSTEP_DIVIDER       2   // режим делителя: 1 - полный шаг, 2 - 1/2 шага, 16 - 1/16 шага и т.п., по умолчанию
#define STEPS_PER_REVOLUTION    200 // кол-во шагов на оборот двигателя в полношаговом режиме

// максимальное кол-во оборотов двигателя в минуту (относительные скорости будут рассчитываться, исходя из этого значения). 
// сильно не увеличивать - основываясь на этом значении - подсчитывается интервал таймера !!!
#define MAX_SPEED               200 // 200 оборотов в минуту

#define DEFAULT_ROTATION_SPEED  30  // значение скорости вращения (режим "Вращение") по умолчанию, в процентах от максимальной (1-100)

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Настройки передаточного отношения
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Для примера рассмотрим передаточное отношение 2/1. Это значит, что момент силы на редукторе вырастет в два раза. При этом, чтобы сделать один оборот на ведомом
// валу - двигателю надо совершить два оборота. Передаточное отношение настраивается под ваши параметры
#define REDUCTION_MOTOR         1   // коэффициент редукции на моторе, по умолчанию (числитель, например X/Y, где X - коэффициент редукции на моторе)
#define REDUCTION_GEAR          1   // коэффициент редукции на редукторе, по умолчанию (знаменатель, например X/Y, где Y - коэффициент редукции на редукторе)

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки емкостной клавиатуры (MPR121 на I2C)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 Клавиатура подключается так:
 SCL - SCL
 SDA - SDA
 GND - GND
 VCC - 3.3В, будьте внимательны - НЕ 5В, а 3.3В !!!
 IRQ - на KEYBOARD_IRQ_PIN (настройка ниже)

  У клавиатуры 12 площадок. 10 мы используем под числа, остальные две - стирание последней набранной цифры (BACKSPACE)
  и очистка поля ввода (DELETE)

  Несмотря на то, что клавиатура поддерживает нажатие нескольких клавиш одновременно -
  прошивка при нахождении первой нажатой клавиши - дальше не анализирует.
 
 */
#define USE_KEYBOARD            // закомментировать, если не надо использовать клавиатуру для ввода значений
#define KEYBOARD_ADDRESS  0x5A  // адрес клавиатуры на шине I2C. Возможные адреса: 0x5A, 0x5B, 0x5C, 0x5D
#define KEYBOARD_IRQ_PIN  2     // номер пина, на котором будут анализироваться прерывания от клавиатуры

#define KEY_BACKSPACE     4     // номер клавиши стирания последней цифры
#define KEY_DELETE        8     // кнопка очистки поля ввода

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// привязка цифр к клавишам клавиатуры
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define KEY_1   3   // площадка 3 - клавиша 1
#define KEY_2   7   // площадка 7 - клавиша 2
#define KEY_3   11  // площадка 11 - клавиша 3
#define KEY_4   2   // площадка 2 - клавиша 4
#define KEY_5   6   // площадка 6 - клавиша 5
#define KEY_6   10  // площадка 11 - клавиша 6
#define KEY_7   1   // площадка 1 - клавиша 7
#define KEY_8   5   // площадка 5 - клавиша 8
#define KEY_9   9   // площадка 9 - клавиша 9
#define KEY_0   0   // площадка 0 - клавиша 0

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки хранения информации в EEPROM
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define ROTATION_SPEED_STORE_ADDRESS            10 // адрес хранения скорости вращения (3 байта)
#define LAST_SELECTED_MENU_STORE_ADDRESS        15 // адрес хранения последнего выбранного меню, чтобы при перезапуске кнопка этого меню была активна по умолчанию (3 байта)
#define REDUCTION_MOTOR_STORE_ADDRESS           20 // адрес хранения коэффициента редукции на моторе (3 байта)
#define REDUCTION_GEAR_STORE_ADDRESS            25 // адрес хранения коэффициента редукции на редукторе (3 байта)
#define MICROSTEP_DIVIDER_STORE_ADDRESS         30 // адрес хранения настройки микрошага (3 байта)
#define STEPS_PER_REVOLUTION_STORE_ADDRESS      35 // адрес хранения кол-ва шагов на оборот в полношаговом режиме (4 байта)
#define STEPS_STORE_ADDRESS                     40 // адрес хранения выставленного кол-ва шагов на экране шагания (4 байта)




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
#define BACKSPACE_KEY 10
#define DELETE_KEY 11
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CORE_COMMAND_GET F("GET=") // префикс для команды получения данных из ядра
#define CORE_COMMAND_SET F("SET=") // префикс для команды сохранения данных в ядро
#define CORE_COMMAND_ANSWER_OK F("OK=") // какой префикс будет посылаться в ответ на команду получения данных и её успешной отработке
#define CORE_COMMAND_ANSWER_ERROR F("ER=") // какой префикс будет посылаться в ответ на команду получения данных и её неуспешной отработке
#define CORE_COMMAND_PARAM_DELIMITER '|' // разделитель параметров
#define CORE_END_OF_DATA F("[END]")
#define CORE_COMMAND_DONE F("DONE")
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

