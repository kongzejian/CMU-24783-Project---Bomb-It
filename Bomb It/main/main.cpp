#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <iostream>

#include "yspng.h"
#include "fssimplewindow.h"
#include "bitmap.h"
#include "character.h"
#include "Game.h"
#include "yssimplesound.h"
#include "yssimplesound.h"
int main(void)
{	
	YsSoundPlayer soundPlayer1;
	YsSoundPlayer soundPlayer2;
	YsSoundPlayer::SoundData menuSound;
	YsSoundPlayer::SoundData backgroundSound;
	if(YSOK == menuSound.LoadWav("../Bomb it/soundEffect/Menu.wav")) 
		{
		std::cout << "success to read "  << std::endl;
		soundPlayer1.Start();
		}
		else
		{
		std::cout << "Failed to read "  << std::endl;
		}
	if(YSOK == backgroundSound.LoadWav("../Bomb it/soundEffect/background.wav")) 
		{
		std::cout << "success to read "  << std::endl;
		soundPlayer2.Start();
		}
		else
		{
		std::cout << "Failed to read "  << std::endl;
		}
	soundPlayer1.PlayBackground(menuSound);
	Game game;
	while(game.Menu() == 0);
	while(true != game.MustTerminate())
	{	soundPlayer1.Stop(menuSound);
		soundPlayer2.PlayBackground(backgroundSound);
		game.RunOneStep();
		game.Draw();
	}
	return 0;
}