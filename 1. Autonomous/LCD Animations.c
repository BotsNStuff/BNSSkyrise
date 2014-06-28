task loadingSpin() 
{
	const ubyte DELAY = 90;
	const ubyte NUM_SYMBOLS = 4;
	const char SYMBOLS[NUM_SYMBOLS] = { '|', '/', '-', '\\' };

	while ( true )
		for ( ubyte i = 0; i < NUM_SYMBOLS; i++ ) 
        {
			displayLCDChar( 1, 0, SYMBOLS[i] );
			wait1Msec( DELAY );
		}
}

task loadingBigSpin() 
{
	const ubyte DELAY = 100;
	const ubyte NUM_SYMBOLS = 4;
	const char SYMBOLS[NUM_SYMBOLS] = { '/', ' ', '\\', '_' };
}

task loadingDick() 
{
	const ubyte DELAY = 100;
	const ubyte SHAFT_LENGTH = 14;

	while ( true )
     {
		clearLCDLine( 1 );
		for ( ubyte i = 0; i < SHAFT_LENGTH - 2; i++ ) {
			displayLCDChar( 1, 0, '8' );
			displayLCDChar( 1, i + 1, '=' );
			displayLCDChar( 1, i + 2, 'D' );
			wait1Msec( DELAY );
		}
	}
}

task winkingFace() 
{
	const ubyte DELAY = 255;
	const ubyte NUM_SYMBOLS = 2;
	const char SYMBOLS[NUM_SYMBOLS] = { ':', ';' };

	while ( true )
		for ( ubyte i = 0; i < NUM_SYMBOLS; i++ ) 
        {
			displayLCDChar( 1, 2, SYMBOLS[i] );
			displayLCDChar( 1, 3, 'D' );
			wait1Msec( DELAY );
		}
}

task main() 
{
	startTask( loadingBigSpin );

	while ( true ) 
    {

	}
}
