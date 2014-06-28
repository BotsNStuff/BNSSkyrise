//////////////////////////////////////
// Based on code by Daniel Centore. //
//   Overhauled by Jordan Kiesel.   //
//////////////////////////////////////

task userDriveHolo()
{
  const TVexJoysticks Y_AXIS = Ch3; // y-axis joystick channel
  const TVexJoysticks X_AXIS = Ch4; // x-axis joystick channel
  const TVexJoysticks R_AXIS = Ch1; // rotation joystick channel
  const tMotor FL_MOTOR = port1; // front-left motor port/name
  const tMotor FR_MOTOR = port2; // front-right motor port/name
  const tMotor BL_MOTOR = port3; // back-left motor port/name
  const tMotor BR_MOTOR = port4; // back-right motor port/name
  const tSensors GYRO = in1; // gyroscopic sensor port/name

  bool doUseGyro = true; // enable gyroscopic sensor

  signed byte joyY,joyX,joyR = 0;
  float t,y,x,r = 0;
  float wheelSpeed[4] = {0, 0, 0, 0};
  float maxSpeed = 0;

  while(true)
  {
    // ==== collect joystick & sensor values ====
    joyY = vexRT[Y_AXIS];
    joyX = vexRT[X_AXIS];
    joyR = vexRT[R_AXIS];
    if(doUseGyro)
      t = SensorValue[GYRO]/10;

    // ==== adjust for gyro angle ====
    y = joyY*cosDegrees(t) - joyX*sinDegrees(t);
    x = joyY*sinDegrees(t) + joyX*cosDegrees(t);
    r = joyR;

    // ==== calculate speeds ====
    wheelSpeed[0] = y + x + r; // front-left
    wheelSpeed[1] = y - x - r; // front-right
    wheelSpeed[2] = y - x + r; // back-left
    wheelSpeed[3] = y + x - r; // back-right

    // ==== normalize ====
    for (ubyte i=0; i<4; i++)
      if (abs(wheelSpeed[i]) > maxSpeed)
        maxSpeed = abs(wheelSpeed[i]);
    for (ubyte i=0; i<4; i++)
      wheelSpeed[i] *= 127/maxSpeed;

    // ==== update motor speeds ====
    motor[FL_MOTOR] = wheelSpeed[0];
    motor[FR_MOTOR] = wheelSpeed[1];
    motor[BL_MOTOR] = wheelSpeed[2];
    motor[BR_MOTOR] = wheelSpeed[3];
  }
}

task main()
{
	startTask(userDriveHolo);
}
