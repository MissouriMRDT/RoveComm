# RoveComm Manifest

## Core Board

**IP**: 192.168.2.110

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **DriveLeftRight** | 3000 | `FLOAT_T` | 2 | [LeftSpeed, RightSpeed] (-1, 1)-> (-100%, 100%) |
| **DriveIndividual** | 3001 | `FLOAT_T` | 6 | [LF, LM, LR, RF, RM, RR] (-1, 1)-> (-100%, 100%) |
| **WatchdogOverride** | 3002 | `UINT8_T` | 1 | [0-override off, 1-override on] |
| **LeftDriveGimbalIncrement** | 3003 | `INT16_T` | 1 | [Tilt](degrees -180-180) |
| **RightDriveGimbalIncrement** | 3004 | `INT16_T` | 1 | [Tilt](degrees -180-180) |
| **LeftMainGimbalIncrement** | 3005 | `INT16_T` | 2 | [Pan, Tilt](degrees -180-180) |
| **RightMainGimbalIncrement** | 3006 | `INT16_T` | 2 | [Pan, Tilt](degrees -180-180) |
| **BackDriveGimbalIncrement** | 3007 | `INT16_T` | 1 | [Tilt](degrees -180-180) |
| **LEDRGB** | 3008 | `UINT8_T` | 3 | [R, G, B] (0, 255) |
| **LEDPatterns** | 3009 | `UINT8_T` | 1 | [Pattern] (Enum) |
| **StateDisplay** | 3010 | `UINT8_T` | 1 | [Teleop, Autonomy, Reached Goal] (enum) |
| **Brightness** | 3011 | `UINT8_T` | 1 | Set Brightness (0-255) |
| **SetWatchdogMode** | 3012 | `UINT8_T` | 1 | 0: Teleop, 1: Autonomy |
| **LEDText** | 3013 | `CHAR` | 256 | Set the message to display on the lighting panel; null terminator ends string early |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **DriveSpeeds** | 3100 | `FLOAT_T` | 6 | [LF, LM, LR, RF, RM, RR] (-1, 1)-> (-100%, 100%) |
| **IMUData** | 3101 | `FLOAT_T` | 3 | [Roll, Pitch, Yaw] degrees |
| **AccelerometerData** | 3102 | `FLOAT_T` | 3 | [xAxis, yAxis, zAxis] Accel in m/s^2 |

## PMS Board

**IP**: 192.168.2.102

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **EStop** | 4000 | `UINT8_T` | 1 | Power off all systems except network (PMS will stay on) |
| **Suicide** | 4001 | `UINT8_T` | 1 | Power off all systems including network, cannot recover without physical reboot (PMS will stay on) |
| **Reboot** | 4002 | `UINT8_T` | 1 | Cycle all systems including network off and back on (PMS will stay on) |
| **EnableBus** | 4003 | `UINT8_T` | 1 | [Motor, Core, Aux] (bitmasked) [1-Enable, 0-No change] |
| **DisableBus** | 4004 | `UINT8_T` | 1 | [Motor, Core, Aux] (bitmasked) [1-Disable, 0-No change] |
| **SetBus** | 4005 | `UINT8_T` | 1 | [Motor, Core, Aux] (bitmasked) [1-Enable, 0-Disable] |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **PackCurrent** | 4100 | `FLOAT_T` | 1 | Total current draw from battery |
| **PackVoltage** | 4101 | `FLOAT_T` | 1 | Pack voltage |
| **CellVoltage** | 4102 | `FLOAT_T` | 6 | C1, C2, C3, C4, C5, C6 |
| **AuxCurrent** | 4103 | `FLOAT_T` | 1 | Current draw by aux systems (before 12V buck) |
| **MiscCurrent** | 4104 | `FLOAT_T` | 3 | Current draw from other devices (CS1, CS2, CS3) |
| **BusStatus** | 4105 | `UINT8_T` | 1 | [Motor, Core, Aux, Network] (bitmasked) [1-Enabled, 0-Disabled] |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **PackOvercurrent** | 4200 | `UINT8_T` | 1 | Higher current draw than the battery can support. Rover will Reboot automatically |
| **CellUndervoltage** | 4201 | `UINT8_T` | 1 | (bitmasked) [1-Undervolt, 0-OK]. Rover will EStop automatically |
| **CellCritical** | 4202 | `UINT8_T` | 1 | (bitmasked) [1-Critical, 0-OK]. Rover will Suicide automatically |
| **AuxOvercurrent** | 4203 | `UINT8_T` | 1 | Aux system current draw too high. Rover will disable Aux bus automatically |

## Nav Board

**IP**: 192.168.2.104

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **GPSLatLonAlt** | 6100 | `DOUBLE_T` | 3 | [Lat, Long, Alt] [(-90, 90), (-180, 180)(deg), (0, 1000)] |
| **IMUData** | 6101 | `FLOAT_T` | 3 | [Pitch, Yaw, Roll] [(-90, 90), (0, 360), (-90, 90)] (deg) |
| **CompassData** | 6102 | `FLOAT_T` | 1 | [Heading] [ 0, 360 ] |
| **SatelliteCountData** | 6103 | `UINT8_T` | 1 | [Number of satellites] |
| **AccelerometerData** | 6104 | `FLOAT_T` | 3 | [xAxis, yAxis, zAxis] Accel in m/s^2 |
| **AccuracyData** | 6105 | `FLOAT_T` | 5 | [horizontal_accur, vertical_accur, heading_accur, fix_type, is_differentia] [meters, meters, degrees, ublox_navpvt fix type (http://docs.ros.org/en/noetic/api/ublox_msgs/html/msg/NavPVT.html), boolean] |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **GPSLockError** | 6200 | `UINT8_T` | 1 |  |

## BaseStationNav Board

**IP**: 192.168.100.112

## SignalStack Board

**IP**: 192.168.100.101

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **OpenLoop** | 7000 | `INT16_T` | 1 | Motor decipercent [-1000, 1000] |
| **SetAngleTarget** | 7001 | `FLOAT_T` | 1 | [Heading] [0, 360) |
| **SetGPSTarget** | 7002 | `DOUBLE_T` | 4 | [Rover Lat, Rover Long, Basestation Lat, Basestation Long] [Lat:(-90, 90), Long:(-180, 180)] (deg) |
| **WatchdogOverride** | 7003 | `UINT8_T` | 1 | [0-override off, 1-override on] |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **CompassAngle** | 7100 | `FLOAT_T` | 1 | [Heading] [0, 360) |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **WatchdogStatus** | 7200 | `UINT8_T` | 1 | (1-Watchdog timeout, 0-OK) |

## Arm Board

**IP**: 192.168.2.107

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **OpenLoop** | 8000 | `INT16_T` | 6 | [X, Y1, Y2, Z, P, R] Motor decipercent [-1000, 1000] |
| **SetPosition** | 8001 | `FLOAT_T` | 6 | [X, Y1, Y2, Z, P, R] (in, in, in, in, deg, deg) |
| **IncrementPosition** | 8002 | `FLOAT_T` | 5 | [X, Y, Z, P, R] (in, in, in, deg, deg, deg) |
| **SetIK** | 8003 | `FLOAT_T` | 5 | [X, Y, Z, P, R] (in, in, in, deg, deg) |
| **IncrementIK_RoverRelative** | 8004 | `FLOAT_T` | 5 | [X, Y, Z, P, R] (in, in, in, deg, deg) |
| **IncrementIK_WristRelative** | 8005 | `FLOAT_T` | 5 | [X, Y, Z, P, R] (in, in, in, deg, deg) |
| **Laser** | 8006 | `UINT8_T` | 1 | [0-disable, 1-enable] |
| **Solenoid** | 8007 | `UINT8_T` | 1 | [0-retract, 1-extend] |
| **Gripper** | 8008 | `INT16_T` | 1 | Motor decipercent [-1000, 1000] |
| **WatchdogOverride** | 8009 | `UINT8_T` | 1 | [0-override off, 1-override on] |
| **LimitSwitchOverride** | 8010 | `UINT16_T` | 1 | [X+, X-, Y1+, Y1-, Y2+, Y2-, Z+, Z-, P+, P-] (0-override off, 1-override on) (bitmasked) |
| **CalibrateEncoder** | 8011 | `UINT8_T` | 1 | [X, Y1, Y2, Z, P, R1, R2] (1-calibrate, 0-no action) (bitmasked) |
| **SelectGripper** | 8012 | `UINT8_T` | 1 | Toggle gripper and roll motors controlled by other packets; 0-Gripper1, 1-Gripper2 |
| **SoftLimitOverride** | 8013 | `UINT8_T` | 1 | [X+, X-, Y1+, Y1-, Y2+, Y2-, Z+, Z-, P+, P-] (0-override off, 1-override on) (bitmasked) |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **Positions** | 8100 | `FLOAT_T` | 7 | [X, Y1, Y2, Z, Pitch, Roll1, Roll2] (in, in, in, in, deg, deg, deg) |
| **Coordinates** | 8101 | `FLOAT_T` | 5 | [X, Y, Z, P, R] (in, in, in, deg, deg) |
| **LimitSwitchTriggered** | 8102 | `UINT16_T` | 1 | [X+, X-, Y1+, Y1-, Y2+, Y2-, Z+, Z-, Pitch+, Pitch-] (0-off, 1-on) (bitmasked) |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **WatchdogStatus** | 8200 | `UINT8_T` | 1 | (1-Watchdog timeout, 0-OK) |

## ScienceActuation Board

**IP**: 192.168.2.108

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **ScoopAxis_OpenLoop** | 9000 | `INT16_T` | 1 | Motor decipercent [-1000, 1000] |
| **SensorAxis_OpenLoop** | 9001 | `INT16_T` | 1 | Motor decipercent [-1000, 1000] |
| **ScoopAxis_SetPosition** | 9002 | `FLOAT_T` | 1 | Absolute position (in) |
| **SensorAxis_SetPosition** | 9003 | `FLOAT_T` | 1 | Absolute position (in) |
| **ScoopAxis_IncrementPosition** | 9004 | `FLOAT_T` | 1 | (in) |
| **SensorAxis_IncrementPosition** | 9005 | `FLOAT_T` | 1 | (in) |
| **LimitSwitchOverride** | 9006 | `UINT8_T` | 1 | [ScoopAxis+, ScoopAxis-, SensorAxis+, SensorAxis-] (0-override off, 1-override on) (bitmasked) |
| **Auger** | 9007 | `INT16_T` | 1 | Motor decipercent [-1000, 1000] |
| **Microscope** | 9008 | `UINT8_T` | 1 | [0-180] (degrees) |
| **WatchdogOverride** | 9010 | `UINT8_T` | 1 | [0-override off, 1-override on] |
| **CalibrateEncoder** | 9011 | `UINT8_T` | 1 | [ScoopAxis, SensorAxis, Proboscis] (1-calibrate, 0-no action) (bitmasked) |
| **RequestHumidity** | 9012 | `UINT8_T` | 1 | Request the humidity of the instrument |
| **AugerGimbalIncrement** | 9013 | `INT16_T` | 2 | [Pan, Tilt](degrees -180-180) |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **Positions** | 9100 | `FLOAT_T` | 2 | [ScoopAxis, SensorAxis] (in) |
| **LimitSwitchTriggered** | 9101 | `UINT8_T` | 1 | [ScoopAxis+, ScoopAxis-, SensorAxis+, SensorAxis-] (0-off, 1-on) (bitmasked) |
| **Humidity** | 9102 | `FLOAT_T` | 1 | [Humidity] (relative humidity %) |
| **AugerSpeed** | 9103 | `FLOAT_T` | 1 | (in/s) |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **WatchdogStatus** | 9200 | `UINT8_T` | 1 | (1-Watchdog timeout, 0-OK) |
| **AugerStalled** | 9201 | `UINT8_T` | 1 | (1-Stalled, 0-OK) |

## Autonomy Board

**IP**: 192.168.3.100

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **StartAutonomy** | 11000 | `UINT8_T` | 1 |  |
| **DisableAutonomy** | 11001 | `UINT8_T` | 1 |  |
| **AddPositionLeg** | 11002 | `DOUBLE_T` | 2 | [Lat, Lon] |
| **AddMarkerLeg** | 11003 | `DOUBLE_T` | 2 | [Lat, Lon] |
| **AddObjectLeg** | 11004 | `DOUBLE_T` | 2 | [Lat, Lon] |
| **ClearWaypoints** | 11005 | `UINT8_T` | 1 |  |
| **SetMaxSpeed** | 11006 | `FLOAT_T` | 1 | A multiplier from 0.0 to 1.0 that will scale the max power effort of Autonomy |
| **SetLoggingLevels** | 11007 | `UINT8_T` | 3 | [Enum (AUTONOMYLOG), Enum (AUTONOMYLOG), Enum (AUTONOMYLOG)] {Console, File, RoveComm} |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **CurrentState** | 11100 | `UINT8_T` | 1 | Enum (AUTONOMYSTATE) |
| **ReachedGoal** | 11101 | `UINT8_T` | 1 |  |
| **CurrentLog** | 11102 | `CHAR` | 255 | String version of most current error log |

## Camera1 Board

**IP**: 192.168.4.100

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **ChangeCameras** | 12000 | `UINT8_T` | 2 | Change which camera a feed is looking at. [0] is the feed, [1] is the camera to view. |
| **TakePicture** | 12001 | `UINT8_T` | 2 | Take a picture with the current camera. [0] is the camera to take a picture with. [1] tells the camera whether to restart the stream afterwards. |
| **ToggleStream1** | 12002 | `UINT8_T` | 2 | Stop the current camera stream. [0] is the camera to stop streaming. [1] is whether to restart the stream. |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **AvailableCameras** | 12100 | `UINT8_T` | 1 | Bitmask values for which cameras are able to stream. LSB is Camera 0, MSB is Camera 7. |
| **StreamingCameras** | 12101 | `UINT8_T` | 4 | Which cameras the system is currently streaming on each port |
| **PictureTaken1** | 12102 | `UINT8_T` | 1 | Picture has been taken. |

### Errors

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **CameraUnavailable** | 12200 | `UINT8_T` | 1 | Camera has errored and stopped streaming. [0] is ID of camera as an integer (not bitmask). |

## Camera2 Board

**IP**: 192.168.4.101

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **TakePicture** | 13001 | `UINT8_T` | 1 | Take a picture with the current camera. [0] is the camera to take a picture with. [1] tells the camera whether to restart the stream afterwards. |
| **ToggleStream2** | 13002 | `UINT8_T` | 2 | Stop the current camera stream. [0] is the camera to stop streaming. [1] is whether to restart the stream. |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **PictureTaken2** | 13100 | `UINT8_T` | 1 | Picture has been taken. |

## IRSpectrometer Board

**IP**: 192.168.3.104

## Instruments Board

**IP**: 192.168.3.105

### Commands

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **EnableLEDs** | 16000 | `UINT8_T` | 1 | [Green, White] [1-Enabled, 0-Disabled] (bitmasked) |
| **RequestRamanReading** | 16001 | `UINT32_T` | 1 | Start a Raman reading, with the provided integration time (milliseconds) |
| **RequestReflectanceReading** | 16002 | `UINT32_T` | 1 | Start a Reflectance reading, with the provided integration time (milliseconds) |
| **RequestTemperature** | 16003 | `UINT8_T` | 1 | Request the temperature of the instrument |

### Telemetry

| name | dataId | type | count | description |
| :--- | ------ | ---- | ----- | ----------- |
| **RamanReading_Part1** | 16100 | `UINT16_T` | 500 | Raman CCD elements 1-500 |
| **RamanReading_Part2** | 16101 | `UINT16_T` | 500 | Raman CCD elements 501-1000 |
| **RamanReading_Part3** | 16102 | `UINT16_T` | 500 | Raman CCD elements 1001-1500 |
| **RamanReading_Part4** | 16103 | `UINT16_T` | 500 | Raman CCD elements 1501-2000 |
| **RamanReading_Part5** | 16104 | `UINT16_T` | 48 | Raman CCD elements 2001-2048 |
| **ReflectanceReading** | 16105 | `UINT8_T` | 288 | Reflectance CCD elements 1-288 |
| **Temperature** | 16106 | `INT8_T` | 1 | [Temperature] (degrees C) |

