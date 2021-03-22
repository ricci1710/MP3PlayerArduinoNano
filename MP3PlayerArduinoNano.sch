EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v2.x A1
U 1 1 605735C1
P 5350 3900
F 0 "A1" H 5350 2811 50  0001 C CNN
F 1 "Arduino_Nano_v2.x" H 5350 2811 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5350 3900 50  0001 C CIN
F 3 "https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf" H 5350 3900 50  0001 C CNN
	1    5350 3900
	-1   0    0    1   
$EndComp
$Comp
L ImmEDV:DFPlayer-Mini U2
U 1 1 60575059
P 7700 3200
F 0 "U2" H 7675 3365 50  0001 C CNN
F 1 "DFPlayer-Mini" H 7675 3273 50  0000 C CNN
F 2 "ImmEDV:DFPlayer-Mini" H 7700 3300 50  0001 C CNN
F 3 "https://docs.google.com/document/d/1Uv94e0WPfezpZ8d-haeFUi1B-xd71attlAxIofRI21Q/edit#heading=h.ttaem4m0qfvo" H 7700 3300 50  0001 C CNN
	1    7700 3200
	1    0    0    -1  
$EndComp
$Comp
L ImmEDV:LM2596S U1
U 1 1 6057688D
P 3800 2500
F 0 "U1" H 3825 2615 50  0001 C CNN
F 1 "LM2596S" H 3825 2523 50  0000 C CNN
F 2 "ImmEDV:LM2596S" H 3800 2600 50  0001 C CNN
F 3 "https://docs.google.com/document/d/1rc8Wvo1SLA614EZ_NBS8fxWZb8ZP31bu-gGQDDy2hK8/edit#heading=h.alf27cyawf5b" H 3800 2600 50  0001 C CNN
	1    3800 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:Speaker LS1
U 1 1 60577A73
P 7550 4300
F 0 "LS1" H 7720 4296 50  0000 L CNN
F 1 "Speaker 3W" H 7720 4205 50  0000 L CNN
F 2 "Connector:FanPinHeader_1x03_P2.54mm_Vertical" H 7550 4100 50  0001 C CNN
F 3 "~" H 7540 4250 50  0001 C CNN
	1    7550 4300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 6057874E
P 6350 3800
F 0 "SW1" H 6350 4067 50  0001 C CNN
F 1 "Klingelknopf" H 6350 3975 50  0000 C CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx01_Slide_6.7x4.1mm_W7.62mm_P2.54mm_LowProfile" H 6350 3800 50  0001 C CNN
F 3 "~" H 6350 3800 50  0001 C CNN
	1    6350 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0101
U 1 1 60579A8B
P 3300 2600
F 0 "#PWR0101" H 3300 2450 50  0001 C CNN
F 1 "+12V" H 3315 2773 50  0000 C CNN
F 2 "" H 3300 2600 50  0001 C CNN
F 3 "" H 3300 2600 50  0001 C CNN
	1    3300 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6057A9A0
P 3300 2850
F 0 "#PWR0102" H 3300 2600 50  0001 C CNN
F 1 "GND" H 3305 2677 50  0000 C CNN
F 2 "" H 3300 2850 50  0001 C CNN
F 3 "" H 3300 2850 50  0001 C CNN
	1    3300 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2600 3300 2650
Wire Wire Line
	3300 2650 3400 2650
Wire Wire Line
	3300 2850 3300 2750
Wire Wire Line
	3300 2750 3400 2750
Wire Wire Line
	5850 3800 6050 3800
Wire Wire Line
	6650 3800 6650 3900
Wire Wire Line
	6650 3900 6950 3900
Wire Wire Line
	7200 4000 7200 4300
Wire Wire Line
	7200 4300 7350 4300
Wire Wire Line
	7200 3800 7150 3800
Wire Wire Line
	7150 3800 7150 4400
Wire Wire Line
	7150 4400 7350 4400
Wire Wire Line
	5350 2750 5350 2900
Wire Wire Line
	4250 2750 5350 2750
Wire Wire Line
	5850 3500 7200 3500
Wire Wire Line
	6850 2650 6850 3300
Wire Wire Line
	6850 3300 7200 3300
Wire Wire Line
	4250 2650 6850 2650
Wire Wire Line
	6850 3300 6850 5150
Wire Wire Line
	6850 5150 5450 5150
Wire Wire Line
	5450 5150 5450 4900
Connection ~ 6850 3300
Wire Wire Line
	5350 2750 6950 2750
Wire Wire Line
	6950 2750 6950 3900
Connection ~ 5350 2750
Connection ~ 6950 3900
Wire Wire Line
	6950 3900 7200 3900
Wire Wire Line
	5850 3400 7200 3400
$EndSCHEMATC
