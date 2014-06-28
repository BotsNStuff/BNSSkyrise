// BNS Autonomous Selector
// Made By Harrison Freni of Team 2150D
// Protected Under the LGPL V3

int count = 0;

// This is how we calculate the battery's life in minutes
// Change to 2000 for Small Battery, Leave at 3000 for Regular
int battery = 3000;

// This is how we determine battery life in minutes
// Change this depending on your motor count
// For most teams this should be left at the same place
int motorCount = 10;

// This is the code that actually calculates the battery's life in minutes
// Do not change this code, or it WILL mess up the readings
int motorAmperage = motorCount*(amperagePerMotor);

//This code clears LCD lines
void LCDClear()
{
	clearLCDLine(0);
	clearLCDLine(1);
}

void waitForRelease()
{
	while (nLCDButtons != 0){}
}

int topLevel()
{
	bool selected = false;
	int menu = -1;
	LCDClear();
	while (!selected)
	{
		displayLCDCenteredString(0, "<Auton Select>");
		displayLCDCenteredString(1, "<Batt|Sensors");
		if (nLCDButtons == 1) 
		{
			waitForRelease();
			menu = 0;
			picked2 = true;
		}
		if (nLCDButtons == 4) 
		{
			waitForRelease();
			menu = 2;
			picked2 = true;
		}
		if (nLCDButtons == 2) 
		{
			waitForRelease();
			menu = 1;
			picked2 = true;
		}
	}
	return menu;
}

int sideSelector()
{
	bool selected2 = false;
	LCDClear();
	while (!selected2)
	{
		// This Code Controls How Autonomii are selected
		displayLCDCenteredString(1, "Select")
		if (nLCDButtons == 1) 
		{
			waitForRelease();
			count--;
			if (count < 0) 
			{
				count = SIDE_SELECT;
			}
		}
		if (nLCDButtons == 4) 
		{
			waitForRelease();
			count++;
			if (count > SIDE_SELECT) 
			{
				count = 0;
			}
		}
		if (nLCDButtons == 2) 
		{
			waitForRelease();
			menu = 3;
			selected2 = true;
		}
		// This tells our code what to run for certain autonomii
		switch (count)
		{
			//This Code Runs an Autonomous
			case 0: 
			{
				displayLCDCenteredString(0, "");
				break;
			}

			//This Code Runs an Autonomous
			case 1:
			{
				displayLCDCenteredString(0, "");
				break;
			}

			//This Code Runs an Autonomous
			case 2:
			{
				displayLCDCenteredString(0, "");
				break;
			}

			//This Code Runs an Autonomous
			case 3:
			{
				displayLCDCenteredString(0, "");
				break;
			}
		}
	}
	return 0;
}

int codeSelector()
{
	bool selected3 = false;
	LCDClear();
	while (!selected3)
	{
		// This Code Controls How Autonomii are selected
		displayLCDCenteredString(1, "Select")
			if (nLCDButtons == 1)
			{
			waitForRelease();
			count--;
			if (count < 0)
			{
				count = STARTING_POS;
			}
			}
		if (nLCDButtons == 4)
		{
			waitForRelease();
			count++;
			if (count > STARTING_POS)
			{
				count = 0;
			}
		}
		if (nLCDButtons == 2)
		{
			waitForRelease();
			picked = true;
		}

		// This tells our code what to run for certain autonomii
		switch (count)
			{
				//This Code Runs an Autonomous
			case 0:
			{
				displayLCDCenteredString(0, "");
				break;
			}

				//This Code Runs an Autonomous
			case 1:
			{
				displayLCDCenteredString(0, "");
				break;
			}

				//This Code Runs an Autonomous
			case 2:
			{
				displayLCDCenteredString(0, "");
				break;
			}

				//This Code Runs an Autonomous
			case 3:
			{
				displayLCDCenteredString(0, "");
				break;
			}
		}
	}
	return 3;
}

int batteryLife()
{
	//Calculate battery life by taking (mAH)/(mA)*0.7
	bool selected4 = false;
	LCDClear();
	while (!selected4)
	{
		// This Code Controls How Autonomii are selected
		displayLCDCenteredString(1, "Select")
			if (nLCDButtons == 1)
			{
			waitForRelease();
			count--;
			if (count < 0)
			{
				count = BATTERY_INFO;
			}
			}
		if (nLCDButtons == 4)
		{
			waitForRelease();
			count++;
			if (count > BATTERY_INFO)
			{
				count = 0;
			}
		}
		if (nLCDButtons == 2)
		{
			waitForRelease();
			picked = true;
		}

		// This tells our code what to run for certain autonomii
		switch (count)
		{
			//This Code Runs an Autonomous
		    case 0:
		    {
			    displayLCDCenteredString(0, "");
			    break;
		    }

			    //This Code Runs an Autonomous
		    case 1:
		    {
			    displayLCDCenteredString(0, "");
			    break;
		    }
		}
	}
}

int sensorInfo()
{
	// Display Sensor info
	// 2 Pages
	//Calculate battery life by taking (mAH)/(mA)*0.7
	bool selected4 = false;
	LCDClear();
	while (!selected4)
	{
		// This Code Controls How Autonomii are selected
		displayLCDCenteredString(1, "Select")
			if (nLCDButtons == 1)
			{
			waitForRelease();
			count--;
			if (count < 0)
			{
				count = SENSOR_PAGES;
			}
			}
		if (nLCDButtons == 4)
		{
			waitForRelease();
			count++;
			if (count > SENSOR_PAGES)
			{
				count = 0;
			}
		}
		if (nLCDButtons == 2)
		{
			waitForRelease();
			picked = true;
		}

		// This tells our code what to run for certain autonomii
		switch (count)
		{
			//This Code Runs an Autonomous
		    case 0:
		    {
			    displayLCDCenteredString(0, "");
			    break;
		    }

			    //This Code Runs an Autonomous
		    case 1:
		    {
			    displayLCDCenteredString(0, "");
			    break;
		    }
		}
	}
}