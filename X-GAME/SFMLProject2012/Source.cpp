#include<iostream>
#include<SFML\Audio.hpp>
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>
#include<sstream>	
#include<string>
using namespace std;
using namespace sf;
//bomberman:
//___________________________________________

Clock cl, bm_c, en_c[3], des_c, game_clock, bm_death_clock, game_over_clock;
int cmove = 0, cmove2 = 0, u = 0, l = 0, d = 1, r = 0, b = 1, n1 = 0, n2 = 0, n3 = 0, c2 = 0, c3 = 0, k = 0, start_des = 0, econst[3] = { 0, 0, 0 }, e_c[3] = { 0, 0, 0 }, e_c2[3] = { 0, 0, 0 }, b_c = 0, b_c2 = 0, f[3] = { 0, 0, 0 }, enemy_mov[3] = { 1, 1, 1 }, enemy_mov_c[3] = { 0, 0, 0 }, enemy_mov_c_2[3] = { 0, 0, 0 }, enemy_mov_c_3[3] = { 0, 0, 0 }, enemy_d[3] = { 0, 0, 0 }, e_end[3] = { 0, 0, 0 }, bm_d = 0, bm_end = 0, bconst = 0, dd = 0;
int bm_bomb1 = 0, bm_bomb2 = 0, bm_x = 0, bm_y = 0, bomb_uu = 0, bomb_dd = 0, bomb_ll = 0, bomb_rr = 0, gate = 0, gate_i = 0, gate_j = 0, sc = 0, lf = 2, min, sec = 60, gameover_c = 0, enemy_death_times = 0;
int bomberman_end = 0;
Time t1, bm_t, en_t[3], des_t, game_time, bm_death_time, game_over_time;
Texture maintex, bombtex, ex_c_t, ex_r_t, ex_l_t, ex_u_t, ex_d_t, window_tex, blocks_tx[3], blocks_des_tex[7], enemy_tx[6], bm_d_tx[8], gate_tx, gameover_tx;
Sprite mainsp, bombsp, ex_c_s, ex_r_s, ex_l_s, ex_u_s, ex_d_s, window_sp, blocks_sp[3], blocks_des_sp[7], enemy_sp[3], bm_d_sp[8], gate_sp, gameover_sp;
Vector2f bm_pos, bm_pos2, size(90, 30), size2(30, 90), block_pos, first, bm_pos3;
FloatRect bomb_br, bomb_br2, bmbounds, enemy_bounds[3], blocks_bounds, border_l(0, 0, 65, 600), border_r(728, 0, 72, 600), border_u(0, 0, 800, 80), border_d(0, 577, 800, 23), bomb_brr;
FloatRect bomb_u, bomb_d, bomb_l, bomb_r;
Event event;
Music bm_music, menu_music;
SoundBuffer bomb_sound_buff, bm_die_soundbuff;
Sound bomb_sound, bm_die_sound;
Text score_txt, life, time_txt, time_txt2, time_txt3;
Font font_bm;
string scc, lff;
int level1[11][13] = {
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
	{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1, 2, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 } };





void blocks_des();
void bm_block();
void bm_stop();
void background();
void bmm();
void bm_move();
void bomb();
void enemy();
void enemyd();
void enemy2();
void enemyd2();
void enemy3();
void enemyd3();
void borders();
void enemy_die();
void enemy_die2();
void enemy_die3();
void bm_die();
void texxt();
void bomberman();
void gameover();
void enemy_block();
void enemy_block2();
void enemy_block3();
void enemy_reverse();
void enemy_reverse2();
void enemy_reverse3();
void playagain_bm();

//   pacman:
//____________________________________________



Font font;
Text text;
string gamescore;
Texture pacmanTEXTURE;                                //the hero
Sprite  pacmanSPRITE;                                 //the hero

Texture livesTEXTURE;
Sprite livesSPRITE;

Texture winTEXTURE;
Sprite winSPRITE;



Texture redTEXTURE;
Sprite redSPRITE;

Texture blueTEXTURE;
Sprite blueSPRITE;

Texture pinkTEXTURE;
Sprite pinkSPRITE;

Texture orangeTEXTURE;
Sprite orangeSPRITE;

Texture levelTEXTURE;								//the background
Sprite levelSPIRITE;								//the background
//shapes on the level
// 1-BARRIERS
// FIRST ROW OF DRAWINGS 
Texture box1TEXTURE;
Sprite box1SPRITE;
Sprite box1SPRITE2;
Texture box2TEXTURE;
Sprite box2SPRITE;
Sprite box2SPRITE2;
Texture box3TEXTURE;
Sprite box3SPRITE;
// SECOND ROW OF DRAWINGS
Texture box4TEXTURE;
Sprite box4SPRITE;
Sprite box4SPRITE2;
Texture box5TEXTURE;
Sprite box5SPRITE;
Texture box6TEXTURE;
Sprite box6SPRITE;
Sprite box6SPRITE2;  // EXCEPTION ( SIXTH ROW OF DRAWINGS)
Sprite box6SPRITE3;	// NINTH ROW OF DRAWINGS
Texture box7TEXTURE;
Sprite box7SPRITE;
// THIRD ROW OF DRAWINGS
Texture box8TEXTURE;
Sprite box8SPRITE;
Texture box9TEXTURE;
Sprite box9SPRITE;
Sprite box9SPRITE2; // EXCEPTION ( SIXTH ROW OF DRAWINGS)
Sprite box9SPRITE3; // NINTH ROW OF DRAWINGS
Texture box10TEXTURE;
Sprite box10SPRITE;
// FORTH ROW OF DRAWINGS
Texture box11TEXTURE;
Sprite box11SPRITE;
// FIFTH ROW OF DRAWINGS
Texture box12TEXTURE;
Sprite box12SPRITE;
Sprite box12SPRITE2;
// SEVENTH ROW OF DRAWINGS
Texture box13TEXTURE;
Sprite box13SPRITE;
Texture box14TEXTURE;
Sprite box14SPRITE;
Texture box15TEXTURE;
Sprite box15SPRITE;
Sprite box15SPRITE2;
Texture box16TEXTURE;
Sprite box16SPRITE;
Texture box17TEXTURE;
Sprite box17SPRITE;
//EIGHTTH  ROW OF DRAWINGS
Texture box18TEXTURE;
Sprite box18SPRITE;
Texture box19TEXTURE;
Sprite box19SPRITE;
//TENTH  ROW OF DRAWINGS
Texture box20TEXTURE;
Sprite box20SPRITE;
Texture box21TEXTURE;
Sprite box21SPRITE;
Texture box22TEXTURE;
Sprite box22SPRITE;
Sprite box22SPRITE2;
Texture box23TEXTURE;
Sprite box23SPRITE;
Texture box24TEXTURE;
Sprite box24SPRITE;
//  2-making the points :
Texture pointTEXTURE[3];
Sprite pointSPRITE[3];

SoundBuffer deadBUFFER;
Sound deadSOUND;

SoundBuffer startBUFFER;
Sound startSOUND;

SoundBuffer eatBUFFER;
Sound eatSOUND;



int level[29][26] =
{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
{ 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0 },
{ 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2 },
{ 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2 },
{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
struct PacmanPosition
{
	float X;
	float Y;
}position;
float speed = 5;
float i = 260;										//starting position x
float j = 407;                                        //starting position y
char x = 's';                                         //last motion direction
int counter = 1;                                        // the motion prespector of the pacman
int dead = 1;
int lives = 3;
int counter2 = 1;										//the motion prospector of the red Enemie 
int counter3 = -14;									//the motion prospector of the orange Enemie
int counter4 = -29;    								//the motion prospector of the pink Enemie	
int counter5 = -40;    								//the motion prospector of the blue Enemie	
int ReachVectory = 0;
int score = 0;
int pacman_end = 0;

void pacmanMotion();
void pacmanDEAD();
void EnemiesMotion();
void pointsDraw();
void shapesDraw();
void collision();
void liveANDscore();
void pacman();
void playagain();


// main :
//_____________________________________________






char y;
RenderWindow window(VideoMode(800, 600), "X-Game");        //window of the game
int main()
{
	menu_music.openFromFile("music\\swf.wav");
	menu_music.play();
	menu_music.setLoop(true);
	while (window.isOpen())
	{
		pacman_end = 0;
		bomberman_end = 0;

		game_clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		Texture logoTEXTURE;
		Sprite logoSPRITE;
		logoTEXTURE.loadFromFile("images\\menu.png");
		logoSPRITE.setTexture(logoTEXTURE);
		Texture borderTEXTURE;
		Sprite borderSPRITE;


		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			y = 'l';
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			y = 'r';
		}
		if (y == 'l')
		{
			logoTEXTURE.loadFromFile("images\\left.png");
			logoSPRITE.setTexture(logoTEXTURE);
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				playagain();
				menu_music.pause();
				pacman();
				menu_music.play();
			}

		}
		if (y == 'r')
		{
			logoTEXTURE.loadFromFile("images\\right.png");
			logoSPRITE.setTexture(logoTEXTURE);
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				playagain_bm();
				menu_music.pause();
				bomberman();
				bm_music.pause();
				menu_music.play();
			}
		}
		window.clear();
		window.draw(logoSPRITE);
		window.display();


	}
}







//bomberman
//________________________________________________________________________






void bomberman()
{
	bm_music.openFromFile("music\\Bomberman (TurboGrafx-16) BGM 01.wav");
	bm_music.play();
	bm_music.setLoop(true);
	font_bm.loadFromFile("fonts\\Perfect DOS VGA 437 Win.ttf");

	bm_t = bm_c.getElapsedTime();

	window.setKeyRepeatEnabled(false);
	enemy_sp[0].setPosition(175, 103);
	enemy_sp[1].setPosition(578, 406);
	enemy_sp[2].setPosition(175, 361);
	maintex.loadFromFile("images\\bm.png");
	mainsp.setTexture(maintex);
	mainsp.setPosition(74, 103);
	window_tex.loadFromFile("images\\window2.png");
	window_sp.setTexture(window_tex);

	bomb_sound_buff.loadFromFile("sound\\bomb.voc");
	bm_die_soundbuff.loadFromFile("sound\\die.voc");
	bomb_sound.setBuffer(bomb_sound_buff);
	bm_die_sound.setBuffer(bm_die_soundbuff);

	blocks_tx[0].loadFromFile("images\\grass.png");
	blocks_tx[1].loadFromFile("images\\wall.png");
	blocks_tx[2].loadFromFile("images\\block.png");
	blocks_des_tex[0].loadFromFile("images\\blocks\\des_1.png");
	blocks_des_tex[1].loadFromFile("images\\blocks\\des_2.png");
	blocks_des_tex[2].loadFromFile("images\\blocks\\des_3.png");
	blocks_des_tex[3].loadFromFile("images\\blocks\\des_4.png");
	blocks_des_tex[4].loadFromFile("images\\blocks\\des_5.png");
	blocks_des_tex[5].loadFromFile("images\\blocks\\des_6.png");
	blocks_des_tex[6].loadFromFile("images\\blocks\\des_7.png");
	enemy_tx[0].loadFromFile("images\\Enemies\\1.png");
	enemy_tx[1].loadFromFile("images\\Enemies\\2.png");
	enemy_tx[2].loadFromFile("images\\Enemies\\3.png");
	enemy_tx[3].loadFromFile("images\\Enemies\\4.png");
	enemy_tx[4].loadFromFile("images\\Enemies\\5.png");
	bm_d_tx[0].loadFromFile("images\\bm_d_1.png");
	bm_d_tx[1].loadFromFile("images\\bm_d_2.png");
	bm_d_tx[2].loadFromFile("images\\bm_d_3.png");
	bm_d_tx[3].loadFromFile("images\\bm_d_4.png");
	bm_d_tx[4].loadFromFile("images\\bm_d_5.png");
	bm_d_tx[5].loadFromFile("images\\bm_d_6.png");
	bm_d_tx[6].loadFromFile("images\\bm_d_7.png");
	bm_d_tx[7].loadFromFile("images\\bm_d_8.png");
	gate_tx.loadFromFile("images\\gate.png");
	gameover_tx.loadFromFile("images\\gameover.png");
	gameover_sp.setTexture(gameover_tx);
	gate_sp.setTexture(gate_tx);

	for (int i = 0; i<3; i++)
	{
		blocks_sp[i].setTexture(blocks_tx[i]);

		blocks_tx[i].setSmooth(true);

	}
	for (int i = 0; i<8; i++)
	{
		blocks_des_sp[i].setTexture(blocks_des_tex[i]);
		bm_d_sp[i].setTexture(bm_d_tx[i]);
	}
	srand(time(NULL));
	for (int i = 0; i<11; i++)
	{
		for (int j = 0; j<13; j++)
		{

			if (level1[i][j] == 0 || level1[i][j] == 1)
				level1[i][j] = rand() % 2 + 0;



		}

	}


	level1[0][0] = 0;
	level1[0][1] = 0;
	level1[1][0] = 0;

	level1[5][10] = 0;
	level1[6][10] = 0;
	level1[7][10] = 0;
	level1[8][10] = 0;

	level1[6][0] = 0;
	level1[6][1] = 0;
	level1[6][2] = 0;
	level1[6][3] = 0;

	level1[0][2] = 0;
	level1[1][2] = 0;
	level1[2][2] = 0;
	level1[3][2] = 0;



	for (int i = 0; i<11; i++)
	{
		for (int j = 0; j<13; j++)
		{


			i = rand() % 11 + 0;
			j = rand() % 13 + 0;
			if (level1[i][j] == 1)
			{
				gate_i = i;
				gate_j = j;

				break;
			}
		}

		if (level1[gate_i][gate_j] == 1)
			break;
		else if (i == 10)
		{
			i = 0;
		}
	}



	blocks_sp[1].setPosition(300, 200);



	while (window.isOpen())
	{
		if (bomberman_end == 1)
			break;

		bmbounds = mainsp.getGlobalBounds();
		enemy_bounds[0] = enemy_sp[0].getGlobalBounds();
		enemy_bounds[1] = enemy_sp[1].getGlobalBounds();
		enemy_bounds[2] = enemy_sp[2].getGlobalBounds();
		enemy_bounds[2].height -= 10;
		window.clear(Color::Black);

		background();


		bmm();
		borders();
		texxt();
		enemyd();
		enemyd2();
		enemyd3();
		gameover();




		c3 = 0;


		window.draw(blocks_sp[1]);

		window.display();


		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}









	}
}




void gameover()
{

	if (mainsp.getGlobalBounds().intersects(gate_sp.getGlobalBounds()))
	if (enemy_death_times == 3)
	{
		gameover_c = 1;
	}

	game_over_time = game_over_clock.getElapsedTime();

	if (game_over_time.asSeconds() >= 4)
		game_over_clock.restart();
	if (gameover_c == 1)
	{
		game_over_time = game_over_clock.getElapsedTime();

		window.draw(gameover_sp);
		if (game_over_time.asSeconds() >= 3)
			bomberman_end = 1;

	}






}






void enemy()
{
	if (e_c[0] == 0)
	{
		en_c[0].restart();
		e_c[0] = 1;
	}
	en_t[0] = en_c[0].getElapsedTime();
	enemy_sp[0].setTexture(enemy_tx[econst[0]]);

	if (en_t[0].asMilliseconds() >= 20 + e_c2[0])
	{
		enemy_sp[0].move(0, enemy_mov[0]);
		e_c2[0] += 20;

	}
	window.draw(enemy_sp[0]);











	f[0]++;
	if (f[0] == 125)
	{
		econst[0]++;

	}
	else if (f[0] == 250)
	{
		econst[0]++;

	}
	else if (f[0] == 375)

	{
		econst[0]++;
		f[0] = 0;

	}


	if (econst[0] == 3)
		econst[0] = 0;

	if (bomb_br.intersects(enemy_sp[0].getGlobalBounds()))
	{
		e_end[0] = 1;
		econst[0] = 3;
		f[0] = 0;
	}

}


void enemy2()
{
	if (e_c[1] == 0)
	{
		en_c[1].restart();
		e_c[1] = 1;
	}
	en_t[1] = en_c[1].getElapsedTime();
	enemy_sp[1].setTexture(enemy_tx[econst[1]]);

	if (en_t[1].asMilliseconds() >= 20 + e_c2[1])
	{
		enemy_sp[1].move(0, enemy_mov[1]);
		e_c2[1] += 20;

	}
	window.draw(enemy_sp[1]);











	f[1]++;
	if (f[1] == 125)
	{
		econst[1]++;

	}
	else if (f[1] == 250)
	{
		econst[1]++;

	}
	else if (f[1] == 375)

	{
		econst[1]++;
		f[1] = 0;

	}


	if (econst[1] == 3)
		econst[1] = 0;

	if (bomb_br.intersects(enemy_sp[1].getGlobalBounds()))
	{
		e_end[1] = 1;
		econst[1] = 3;
		f[1] = 0;
	}

}

void enemy3()
{
	if (e_c[2] == 0)
	{
		en_c[2].restart();
		e_c[2] = 1;
	}
	en_t[2] = en_c[2].getElapsedTime();
	enemy_sp[2].setTexture(enemy_tx[econst[2]]);

	if (en_t[2].asMilliseconds() >= 20 + e_c2[2])
	{
		enemy_sp[2].move(enemy_mov[2], 0);
		e_c2[2] += 20;

	}
	window.draw(enemy_sp[2]);











	f[2]++;
	if (f[2] == 125)
	{
		econst[2]++;

	}
	else if (f[2] == 250)
	{
		econst[2]++;

	}
	else if (f[2] == 375)

	{
		econst[2]++;
		f[2] = 0;

	}


	if (econst[2] == 3)
		econst[2] = 0;

	if (bomb_br.intersects(enemy_sp[2].getGlobalBounds()))
	{
		e_end[2] = 1;
		econst[2] = 3;
		f[2] = 0;
	}

}




void enemyd()

{
	if (e_end[0] == 0)
	{

		enemy();
		enemy_block();
	}
	else if (e_end[0] == 1)
	if (enemy_d[0] != 1)

	{
		enemy_die();

		if (enemy_death_times == 3)
			gate_tx.loadFromFile("images\\gate2.png");

	}
}

void enemyd2()

{
	if (e_end[1] == 0)
	{

		enemy2();
		enemy_block2();
	}
	else if (e_end[1] == 1)
	if (enemy_d[1] != 1)

	{
		enemy_die2();

		if (enemy_death_times == 3)
			gate_tx.loadFromFile("images\\gate2.png");

	}
}

void enemyd3()

{
	if (e_end[2] == 0)
	{

		enemy3();
		enemy_block3();
	}
	else if (e_end[2] == 1)
	if (enemy_d[2] != 1)

	{
		enemy_die3();

		if (enemy_death_times == 3)
			gate_tx.loadFromFile("images\\gate2.png");

	}
}

void enemy_die()
{
	enemy_sp[0].setTexture(enemy_tx[econst[0]]);


	window.draw(enemy_sp[0]);



	f[0]++;
	if (f[0] == 1)
	{
		enemy_death_times++;
		sc++;

	}
	if (f[0] == 25)
	{
		econst[0]++;

	}
	else if (f[0] == 50)
	{
		econst[0]++;
		enemy_d[0] = 1;
	}



}

void enemy_die2()
{
	enemy_sp[1].setTexture(enemy_tx[econst[1]]);


	window.draw(enemy_sp[1]);



	f[1]++;
	if (f[1] == 1)
	{
		sc++;
		enemy_death_times++;
	}
	if (f[1] == 25)
	{
		econst[1]++;

	}
	else if (f[1] == 50)
	{
		econst[1]++;
		enemy_d[1] = 1;
	}



}

void enemy_die3()
{
	enemy_sp[2].setTexture(enemy_tx[econst[2]]);


	window.draw(enemy_sp[2]);



	f[2]++;
	if (f[2] == 1)
	{
		sc++;
		enemy_death_times++;
	}
	if (f[2] == 25)
	{
		econst[2]++;

	}
	else if (f[2] == 50)
	{
		econst[2]++;
		enemy_d[2] = 1;
	}



}

void enemy_reverse()
{
	if (enemy_bounds[0].intersects(blocks_bounds))
	{

		enemy_mov_c_2[0]++;

		if (enemy_mov_c_2[0] == 1)
		{
			enemy_mov[0] *= -1;

		}

		else if (enemy_mov_c_2[0] == 7)

		{
			enemy_mov_c_2[0] = 0;
		}



	}
}

void enemy_reverse2()
{
	if (enemy_bounds[1].intersects(blocks_bounds))
	{

		enemy_mov_c_2[1]++;

		if (enemy_mov_c_2[1] == 1)
		{
			enemy_mov[1] *= -1;

		}

		else if (enemy_mov_c_2[1] == 5)

		{
			enemy_mov_c_2[1] = 0;
		}



	}
}

void enemy_reverse3()
{
	if (enemy_bounds[2].intersects(blocks_bounds))
	{

		enemy_mov_c_2[2]++;

		if (enemy_mov_c_2[2] == 1)
		{
			enemy_mov[2] *= -1;

		}

		else if (enemy_mov_c_2[2] == 5)

		{
			enemy_mov_c_2[2] = 0;
		}



	}
}

void bm_die()
{


	bm_d_sp[bconst].setPosition(mainsp.getPosition());
	window.draw(bm_d_sp[bconst]);



	dd++;
	if (dd == 10)
	{
		bconst++;

	}
	else if (dd == 20)
	{
		bconst++;

	}
	else if (dd == 30)
	{
		bconst++;

	}
	else if (dd == 40)
	{
		bconst++;

	}
	else if (dd == 50)
	{
		bconst++;

	}
	else if (dd == 60)
	{
		bconst++;

	}
	else if (dd == 70)
	{
		bconst++;
		bm_end = 1;


	}

}


void borders()
{
	if (bmbounds.intersects(border_l) || bmbounds.intersects(border_r) || bmbounds.intersects(border_u) || bmbounds.intersects(border_d))
		bm_block();


	if (bomb_r.intersects(border_r))
		bomb_rr++;
	if (bomb_l.intersects(border_l))
		bomb_ll++;
	if (bomb_u.intersects(border_u))
		bomb_uu++;
	if (bomb_d.intersects(border_d))
		bomb_dd++;

	/*else if( bmbounds.intersects(bomb_brr) && t1.asSeconds()>=2 )
	bm_block();
	*/

}



void enemy_block()
{
	if (enemy_bounds[0].intersects(border_l) || enemy_bounds[0].intersects(border_r) || enemy_bounds[0].intersects(border_u) || enemy_bounds[0].intersects(border_d) || enemy_bounds[0].intersects(bomb_brr))
	{
		enemy_mov_c[0]++;

		if (enemy_mov_c[0] == 1)
		{
			enemy_mov[0] *= -1;

		}

		else if (enemy_mov_c[0] == 10)

		{
			enemy_mov_c[0] = 0;
		}
	}
	else if (enemy_bounds[0].intersects(bomb_brr))
	{
		enemy_mov_c_3[0]++;

		if (enemy_mov_c_3[0] == 1)
		{
			enemy_mov[0] *= -1;

		}

		else if (enemy_mov_c_3[0] == 10)

		{
			enemy_mov_c_3[0] = 0;
		}

	}
}

void enemy_block2()
{
	if (enemy_bounds[1].intersects(border_l) || enemy_bounds[1].intersects(border_r) || enemy_bounds[1].intersects(border_u) || enemy_bounds[1].intersects(border_d) || enemy_bounds[1].intersects(bomb_brr))
	{
		enemy_mov_c[1]++;

		if (enemy_mov_c[1] == 1)
		{
			enemy_mov[1] *= -1;

		}

		else if (enemy_mov_c[1] == 10)

		{
			enemy_mov_c[1] = 0;
		}
	}
	else if (enemy_bounds[1].intersects(bomb_brr))
	{
		enemy_mov_c_3[1]++;

		if (enemy_mov_c_3[1] == 1)
		{
			enemy_mov[1] *= -1;

		}

		else if (enemy_mov_c_3[1] == 10)

		{
			enemy_mov_c_3[1] = 0;
		}

	}
}

void enemy_block3()
{
	if (enemy_bounds[2].intersects(border_l) || enemy_bounds[2].intersects(border_r) || enemy_bounds[2].intersects(border_u) || enemy_bounds[2].intersects(border_d) || enemy_bounds[2].intersects(bomb_brr))
	{
		enemy_mov_c[2]++;

		if (enemy_mov_c[2] == 1)
		{
			enemy_mov[2] *= -1;

		}

		else if (enemy_mov_c[2] == 10)

		{
			enemy_mov_c[2] = 0;
		}
	}
	else if (enemy_bounds[2].intersects(bomb_brr))
	{
		enemy_mov_c_3[2]++;

		if (enemy_mov_c_3[2] == 1)
		{
			enemy_mov[2] *= -1;

		}

		else if (enemy_mov_c_3[2] == 10)

		{
			enemy_mov_c_3[2] = 0;
		}

	}
}

void background()
{
	int width = 74, length = 103;
	window.draw(window_sp);

	for (int i = 0; i<11; i++)
	{
		for (int j = 0; j<13; j++)
		{
			blocks_sp[level1[i][j]].setPosition(width, length);


			if (j == 0 && i == 0)
				first = blocks_sp[0].getPosition();


			blocks_bounds = blocks_sp[level1[i][j]].getGlobalBounds();

			bmbounds.height -= 20;
			bmbounds.top += 20;
			blocks_bounds.top += 5;
			blocks_bounds.height -= 5;
			blocks_bounds.width -= 5;




			if (level1[i][j] == 1 || level1[i][j] == 2)
			{
				if (bmbounds.intersects(blocks_bounds))
				{


					bm_block();
				}
				enemy_reverse();
				enemy_reverse2();
				enemy_reverse3();
			}
			blocks_bounds.width += 5;
			blocks_bounds.top -= 5;
			bmbounds.height += 20;
			bmbounds.top -= 20;
			blocks_bounds.height += 5;
			if (bomb_r.intersects(blocks_sp[1].getGlobalBounds()) || bomb_r.intersects(blocks_sp[2].getGlobalBounds()))
				bomb_rr++;
			if (bomb_u.intersects(blocks_sp[1].getGlobalBounds()) || bomb_u.intersects(blocks_sp[2].getGlobalBounds()))
				bomb_uu++;
			if (bomb_l.intersects(blocks_sp[1].getGlobalBounds()) || bomb_l.intersects(blocks_sp[2].getGlobalBounds()))
				bomb_ll++;
			if (bomb_d.intersects(blocks_sp[1].getGlobalBounds()) || bomb_d.intersects(blocks_sp[2].getGlobalBounds()))
				bomb_dd++;


			if (level1[i][j] == 0)
			{
				if (mainsp.getGlobalBounds().contains(blocks_sp[0].getGlobalBounds().left + 25, blocks_sp[0].getGlobalBounds().top + 21.5))
				{
					bm_pos3 = blocks_sp[0].getPosition();

				}
			}



			if (level1[i][j] == 1)
			{




				if (i == gate_i && j == gate_j)
				{
					gate_sp.setPosition(blocks_sp[1].getPosition());
					//cout <<i<<endl<<j<<endl;


				}

				if (bomb_br.intersects(blocks_sp[level1[i][j]].getGlobalBounds()) || bomb_br2.intersects(blocks_sp[level1[i][j]].getGlobalBounds()))

				{

					level1[i][j] = 0;
					block_pos = blocks_sp[1].getPosition();
					start_des = 1;

					if (i == gate_i && j == gate_j)
						gate++;

				}

			}

			if (i == gate_i && j == gate_j && gate == 1)
			{
				window.draw(gate_sp);
			}
			else
				window.draw(blocks_sp[level1[i][j]]);



			width += 50.5;

		}
		width = 74;

		length += 43;
	}


	if (start_des == 1 && k<7)
	{

		if (k == 0)
			des_c.restart();

		des_t = des_c.getElapsedTime();


		blocks_des_sp[k].setPosition(block_pos);
		window.draw(blocks_des_sp[k]);

		/*			if(bomb_coll<=1)
		{
		blocks_des_sp[k].setPosition(block_pos[1]);

		window.draw(blocks_des_sp[k]);
		}


		if(bomb_coll<=2)
		{
		blocks_des_sp[k].setPosition(block_pos[2]);

		window.draw(blocks_des_sp[k]);
		}
		*/

		if (des_t.asMilliseconds() >= (k * 100))
		{

			k++;
		}

	}
	else if (k >= 7)
	{
		start_des = 0;
		k = 0;

	}
}











void bmm()
{


	bomb();


	if (bmbounds.intersects(bomb_br) || bmbounds.intersects(bomb_br2))
	{
		if (t1.asMilliseconds() <= 4350 && bm_d != 1)

		{
			bm_die_sound.play();
			lf--;
			bm_d = 1;

		}
	}

	else if (bmbounds.intersects(enemy_bounds[0]) && e_end[0] != 1 && bm_d != 1)
	{
		bm_die_sound.play();
		lf--;
		bm_d = 1;


	}
	else if (bmbounds.intersects(enemy_bounds[1]) && e_end[1] != 1 && bm_d != 1)
	{
		bm_die_sound.play();
		lf--;
		bm_d = 1;


	}
	else if (bmbounds.intersects(enemy_bounds[2]) && e_end[2] != 1 && bm_d != 1)
	{
		bm_die_sound.play();
		lf--;
		bm_d = 1;


	}
	/*else
	{bm_d=0;

	}*/






	if (bm_d == 0)
	{

		bm_move();

	}
	else if (bm_d == 1)
	{
		bm_t = bm_c.getElapsedTime();
		bm_death_time = bm_death_clock.getElapsedTime();
		if (bm_end != 1)
		{
			bm_die();
			bm_death_clock.restart();
		}
		else if (bm_death_time.asSeconds() >= 2 && lf != -1)
		{
			bm_t = bm_c.getElapsedTime();
			mainsp.setPosition(74, 103);
			bm_d = 0;
			bm_end = 0;
			dd = 0;
			bconst = 0;
		}
	}

	//	if(bm_bomb1==1 && bm_bomb2!=1 )
	/*if(bmbounds.intersects(bomb_brr) ==0 && t1.asMilliseconds()>=100 )
	{

	bm_bomb2=1;

	}

	if (bm_bomb2==1 && bmbounds.intersects(bomb_brr)==1 )

	bm_block();
	*/



}

void bm_move()

{
	bm_t = bm_c.getElapsedTime();
	if (event.type == event.KeyPressed)

	{




		if (Keyboard::isKeyPressed(Keyboard::Down))

		{
			u = 0;

			r = 0;
			l = 0;


			d = 1;
			bm_y = 1;
			bm_x = 0;
			if (cmove<50)

			{

				maintex.loadFromFile("images\\bm_down.png");
				mainsp.setTexture(maintex);
				//		mainsp.move(0,1);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				cmove++;
				//sleep(milliseconds(15));
			}


			else

			{

				maintex.loadFromFile("images\\bm_down_2.png");
				mainsp.setTexture(maintex);
				//		mainsp.move(0,1);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				cmove2++;
				//	sleep(milliseconds(15));

				if (cmove2 == 50)
				{
					cmove = 0;
					cmove2 = 0;
				}
			}
		}



		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			u = 0;
			d = 0;

			l = 0;

			r = 1;
			bm_y = 0;
			bm_x = 1;
			if (cmove<50)

			{

				maintex.loadFromFile("images\\bm_right_1.png");
				mainsp.setTexture(maintex);
				//mainsp.move(1,0);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				cmove++;
				//sleep(milliseconds(15));

			}

			else

			{

				maintex.loadFromFile("images\\bm_right_2.png");
				mainsp.setTexture(maintex);
				//	mainsp.move(1,0);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				cmove2++;
				//	sleep(milliseconds(15));

				if (cmove2 == 50)
				{
					cmove = 0;
					cmove2 = 0;
				}

			}

		}



		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			u = 0;
			d = 0;
			r = 0;



			l = 1;
			bm_y = 0;
			bm_x = -1;
			if (cmove<50)

			{
				maintex.loadFromFile("images\\bm_left_1.png");
				mainsp.setTexture(maintex);
				//		mainsp.move(-1,0);
				//window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				cmove++;
				//sleep(milliseconds(15));

			}
			else
			{
				maintex.loadFromFile("images\\bm_left_2.png");
				mainsp.setTexture(maintex);
				//	mainsp.move(-1,0);
				//window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				cmove2++;
				//	sleep(milliseconds(15));

				if (cmove2 == 50)
				{
					cmove = 0;
					cmove2 = 0;
				}

			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{

			d = 0;
			r = 0;
			l = 0;

			u = 1;
			bm_y = -1;
			bm_x = 0;
			if (cmove<50)

			{
				maintex.loadFromFile("images\\bm_up_1.png");
				mainsp.setTexture(maintex);
				//	mainsp.move(0,-1);
				//window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				cmove++;
				//sleep(milliseconds(15));

			}
			else
			{
				maintex.loadFromFile("images\\bm_up_2.png");
				mainsp.setTexture(maintex);
				//	mainsp.move(0,-1);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				cmove2++;
				//	sleep(milliseconds(15));

				if (cmove2 == 50)
				{
					cmove = 0;
					cmove2 = 0;
				}

			}





		}


		/*if(b_c==0)
		{	bm_c.restart();
		b_c=1;
		}*/
		/*bm_t=bm_c.getElapsedTime();*/


		/*if(bm_t.asMilliseconds()>=10+b_c2)
		{*/
		mainsp.move(bm_x, bm_y);
		bm_x = 0;
		bm_y = 0;

		/*b_c2+=10;
		}
		*/
	}

	else
	{
		/*if(bm_t.asMilliseconds()>=10)
		{
		bm_t=bm_c.getElapsedTime();

		if(bm_t.asMilliseconds()>=10+b_c2)
		{


		b_c2+=10;
		}
		}*/
		bm_stop();

	}



}

void bm_stop()

{



	if (d>0)
	{
		maintex.loadFromFile("images\\bm.png");
		mainsp.setTexture(maintex);

		window.draw(mainsp);

	}
	else if (u>0)
	{
		maintex.loadFromFile("images\\bm_up.png");
		mainsp.setTexture(maintex);

		window.draw(mainsp);

	}
	else if (r>0)
	{
		maintex.loadFromFile("images\\bm_right.png");
		mainsp.setTexture(maintex);

		window.draw(mainsp);

	}

	else if (l>0)
	{
		maintex.loadFromFile("images\\bm_left.png");
		mainsp.setTexture(maintex);

		window.draw(mainsp);

	}




}

void	bm_block()

{
	if (d>0)
	{
		mainsp.move(0, -d);

	}
	else if (u>0)
	{
		mainsp.move(0, u);

	}
	else if (r>0)
	{
		mainsp.move(-r, 0);

	}

	else if (l>0)
	{
		mainsp.move(l, 0);

	}




}






void bomb()

{




	if (Keyboard::isKeyPressed(Keyboard::RControl))
	{
		c2++;
		bm_bomb1++;


		if (b == 1)
		{


			//	bm_pos=mainsp.getPosition();

			bm_pos2 = bm_pos3;

			cl.restart();
			t1 = cl.getElapsedTime();
			b++;
		}
	}


	else if (t1.asMilliseconds() >= 0 + n1 && b>1 && t1.asMilliseconds() <= 200 + n1  &&  t1.asSeconds() <4)
	{
		bombtex.loadFromFile("images\\bomb\\bomb_2.png");
		bombsp.setTexture(bombtex);

		bomb_brr = bombsp.getGlobalBounds();
		bomb_u = bomb_brr;
		bomb_u.top += 43;
		bomb_d = bomb_brr;
		bomb_d.top -= 43;
		bomb_l = bomb_brr;
		bomb_l.left -= 50;
		bomb_r = bomb_brr;
		bomb_r.left += 50;


		bombsp.setPosition(bm_pos2);
		window.draw(bombsp);

		if (b == 2)
		{
			if (d>0)
			{
				maintex.loadFromFile("images\\bm.png");
				mainsp.setTexture(maintex);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				///	d=0;
			}
			else if (u>0)
			{
				maintex.loadFromFile("images\\bm_up.png");
				mainsp.setTexture(maintex);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//	window.display();
				//		u=0;
			}
			else if (r>0)
			{
				maintex.loadFromFile("images\\bm_right.png");
				mainsp.setTexture(maintex);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				//	r=0;
			}

			else if (l>0)
			{
				maintex.loadFromFile("images\\bm_left.png");
				mainsp.setTexture(maintex);
				//	window.clear(Color::Black);
				window.draw(mainsp);
				//window.display();
				//		l=0;
			}
			b++;
		}

		//c2=0;


		t1 = cl.getElapsedTime();
	}

	else if (t1.asMilliseconds() >= 200 + n2 && t1.asMilliseconds()<400 + n2 && b>1 && t1.asSeconds() <4)
	{
		bombtex.loadFromFile("images\\bomb\\bomb.png");
		bombsp.setTexture(bombtex);

		bombsp.setPosition(bm_pos2);
		window.draw(bombsp);
		t1 = cl.getElapsedTime();


	}

	else if (t1.asMilliseconds() >= 400 + n3 && b>1 && t1.asMilliseconds()<600 + n3 && t1.asSeconds() <= 4)
	{
		bombtex.loadFromFile("images\\bomb\\bomb_3.png");
		bombsp.setTexture(bombtex);

		bombsp.setPosition(bm_pos2);
		window.draw(bombsp);
		t1 = cl.getElapsedTime();

	}

	else if ((t1.asMilliseconds() >= 4000 && t1.asMilliseconds() <= 4100) || (t1.asMilliseconds() >= 4200 && t1.asMilliseconds() <= 4250))
	{
		if (t1.asMilliseconds() >= 4000 && t1.asMilliseconds() <= 4100)
			bomb_sound.play();

		ex_c_t.loadFromFile("images\\bomb\\ex_center_3.png");

		ex_c_s.setTexture(ex_c_t);
		ex_r_t.loadFromFile("images\\bomb\\ex_right_end_3.png");
		ex_r_s.setTexture(ex_r_t);
		ex_l_t.loadFromFile("images\\bomb\\ex_left_end_3.png");
		ex_l_s.setTexture(ex_l_t);
		ex_u_t.loadFromFile("images\\bomb\\ex_up_end_3.png");
		ex_u_s.setTexture(ex_u_t);
		ex_d_t.loadFromFile("images\\bomb\\ex_down_end_3.png");
		ex_d_s.setTexture(ex_d_t);



		ex_c_s.setPosition(bm_pos2);
		ex_r_s.setPosition(bm_pos2.x + 30, bm_pos2.y);
		ex_l_s.setPosition(bm_pos2.x - 30, bm_pos2.y);
		ex_d_s.setPosition(bm_pos2.x, bm_pos2.y + 30);
		ex_u_s.setPosition(bm_pos2.x, bm_pos2.y - 30);


		window.draw(ex_c_s);
		if (bomb_rr == 0)
			window.draw(ex_r_s);
		if (bomb_ll == 0)
			window.draw(ex_l_s);
		if (bomb_uu == 0)
			window.draw(ex_u_s);
		if (bomb_dd == 0)
			window.draw(ex_d_s);

		bomb_br = FloatRect::Rect(bm_pos2.x, bm_pos2.y - 43, 50, 129);
		bomb_br2 = FloatRect::Rect(bm_pos2.x - 50, bm_pos2.y, 129, 50);
		t1 = cl.getElapsedTime();


	}

	else if ((t1.asMilliseconds() >= 4050 && t1.asMilliseconds() <= 4100) || (t1.asMilliseconds() >= 4150 && t1.asMilliseconds() <= 4200))
	{
		ex_c_t.loadFromFile("images\\bomb\\ex_center_2.png");
		ex_c_s.setTexture(ex_c_t);

		ex_r_t.loadFromFile("images\\bomb\\ex_right_end_2.png");
		ex_r_s.setTexture(ex_r_t);
		ex_l_t.loadFromFile("images\\bomb\\ex_left_end_2.png");
		ex_l_s.setTexture(ex_l_t);
		ex_u_t.loadFromFile("images\\bomb\\ex_up_end_2.png");
		ex_u_s.setTexture(ex_u_t);
		ex_d_t.loadFromFile("images\\bomb\\ex_down_end_2.png");
		ex_d_s.setTexture(ex_d_t);



		ex_c_s.setPosition(bm_pos2);
		ex_r_s.setPosition(bm_pos2.x + 30, bm_pos2.y);
		ex_l_s.setPosition(bm_pos2.x - 30, bm_pos2.y);
		ex_d_s.setPosition(bm_pos2.x, bm_pos2.y + 30);
		ex_u_s.setPosition(bm_pos2.x, bm_pos2.y - 30);


		window.draw(ex_c_s);
		if (bomb_rr == 0)
			window.draw(ex_r_s);
		if (bomb_ll == 0)
			window.draw(ex_l_s);
		if (bomb_uu == 0)
			window.draw(ex_u_s);
		if (bomb_dd == 0)
			window.draw(ex_d_s);
		t1 = cl.getElapsedTime();


	}

	else if ((t1.asMilliseconds() >= 4100 && t1.asMilliseconds() <= 4150))
	{
		ex_c_t.loadFromFile("images\\bomb\\ex_center_1.png");
		ex_c_s.setTexture(ex_c_t);

		ex_r_t.loadFromFile("images\\bomb\\ex_right_end_1.png");
		ex_r_s.setTexture(ex_r_t);
		ex_l_t.loadFromFile("images\\bomb\\ex_left_end_1.png");
		ex_l_s.setTexture(ex_l_t);
		ex_u_t.loadFromFile("images\\bomb\\ex_up_end_1.png");
		ex_u_s.setTexture(ex_u_t);
		ex_d_t.loadFromFile("images\\bomb\\ex_down_end_1.png");
		ex_d_s.setTexture(ex_d_t);



		ex_c_s.setPosition(bm_pos2);
		ex_r_s.setPosition(bm_pos2.x + 30, bm_pos2.y);
		ex_l_s.setPosition(bm_pos2.x - 30, bm_pos2.y);
		ex_d_s.setPosition(bm_pos2.x, bm_pos2.y + 30);
		ex_u_s.setPosition(bm_pos2.x, bm_pos2.y - 30);


		window.draw(ex_c_s);
		if (bomb_rr == 0)
			window.draw(ex_r_s);
		if (bomb_ll == 0)
			window.draw(ex_l_s);
		if (bomb_uu == 0)
			window.draw(ex_u_s);
		if (bomb_dd == 0)
			window.draw(ex_d_s);
		t1 = cl.getElapsedTime();


	}

	else if ((t1.asMilliseconds() >= 4250 && t1.asMilliseconds() <= 4300))
	{
		ex_c_t.loadFromFile("images\\bomb\\ex_center_4.png");
		ex_c_s.setTexture(ex_c_t);

		ex_r_t.loadFromFile("images\\bomb\\ex_right_end_4.png");
		ex_r_s.setTexture(ex_r_t);
		ex_l_t.loadFromFile("images\\bomb\\ex_left_end_4.png");
		ex_l_s.setTexture(ex_l_t);
		ex_u_t.loadFromFile("images\\bomb\\ex_up_end_4.png");
		ex_u_s.setTexture(ex_u_t);
		ex_d_t.loadFromFile("images\\bomb\\ex_down_end_4.png");
		ex_d_s.setTexture(ex_d_t);



		ex_c_s.setPosition(bm_pos2);
		ex_r_s.setPosition(bm_pos2.x + 30, bm_pos2.y);
		ex_l_s.setPosition(bm_pos2.x - 30, bm_pos2.y);
		ex_d_s.setPosition(bm_pos2.x, bm_pos2.y + 30);
		ex_u_s.setPosition(bm_pos2.x, bm_pos2.y - 30);


		window.draw(ex_c_s);
		if (bomb_rr == 0)
			window.draw(ex_r_s);
		if (bomb_ll == 0)
			window.draw(ex_l_s);
		if (bomb_uu == 0)
			window.draw(ex_u_s);
		if (bomb_dd == 0)
			window.draw(ex_d_s);
		t1 = cl.getElapsedTime();


	}

	else if ((t1.asMilliseconds() >= 4300 && t1.asMilliseconds() <= 4350))
	{
		ex_c_t.loadFromFile("images\\bomb\\ex_center_5.png");
		ex_c_s.setTexture(ex_c_t);

		ex_r_t.loadFromFile("images\\bomb\\ex_right_end_4.png");
		ex_r_s.setTexture(ex_r_t);
		ex_l_t.loadFromFile("images\\bomb\\ex_left_end_4.png");
		ex_l_s.setTexture(ex_l_t);
		ex_u_t.loadFromFile("images\\bomb\\ex_up_end_4.png");
		ex_u_s.setTexture(ex_u_t);
		ex_d_t.loadFromFile("images\\bomb\\ex_down_end_4.png");
		ex_d_s.setTexture(ex_d_t);




		ex_c_s.setPosition(bm_pos2);
		ex_r_s.setPosition(bm_pos2.x + 30, bm_pos2.y);
		ex_l_s.setPosition(bm_pos2.x - 30, bm_pos2.y);
		ex_d_s.setPosition(bm_pos2.x, bm_pos2.y + 30);
		ex_u_s.setPosition(bm_pos2.x, bm_pos2.y - 30);


		window.draw(ex_c_s);
		if (bomb_rr == 0)
			window.draw(ex_r_s);
		if (bomb_ll == 0)
			window.draw(ex_l_s);
		if (bomb_uu == 0)
			window.draw(ex_u_s);
		if (bomb_dd == 0)
			window.draw(ex_d_s);

		t1 = cl.getElapsedTime();


	}
	else if (t1.asMilliseconds() >= 4350)
	{
		b = 1;
		n1 = 0;
		n2 = 0;
		n3 = 0;
		bm_bomb2 = 0;
		bm_bomb1 = 0;
		bomb_br.height = NULL;
		bomb_br.width = NULL;
		bomb_br.top = NULL;
		bomb_br.left = NULL;
		bomb_br2.height = NULL;
		bomb_br2.width = NULL;
		bomb_br2.top = NULL;
		bomb_br2.left = NULL;
		bomb_brr.height = NULL;
		bomb_brr.width = NULL;
		bomb_brr.top = NULL;
		bomb_brr.left = NULL;
		//window.draw(ex_c_s);
		bomb_rr = 0;

		bomb_ll = 0;

		bomb_uu = 0;

		bomb_dd = 0;
	}

	if (b != 1)
	{
		if (t1.asMilliseconds() >= 600 + n1)
		{
			n1 += 600;
		}
		else if (t1.asMilliseconds() >= 600 + n2)
		{
			n2 += 600;
		}
		else if (t1.asMilliseconds() >= 600 + n3)
		{
			n3 += 600;
		}
	}
}




void texxt()
{

	score_txt.setFont(font_bm);

	scc = static_cast<ostringstream*>(&(ostringstream() << (sc * 100)))->str();
	score_txt.setString(scc);
	score_txt.setCharacterSize(30);
	score_txt.setColor(Color::White);
	score_txt.setPosition(55, 15);
	window.draw(score_txt);

	time_txt.setFont(font_bm);

	game_time = game_clock.getElapsedTime();

	scc = static_cast<ostringstream*>(&(ostringstream() << static_cast <int> (240 - game_time.asSeconds()) / 60))->str();
	time_txt.setString(scc);
	time_txt.setCharacterSize(30);
	time_txt.setColor(Color::White);
	time_txt.setPosition(327, 15);
	window.draw(time_txt);


	time_txt2.setFont(font_bm);
	time_txt2.setString(":");
	time_txt2.setCharacterSize(30);
	time_txt2.setColor(Color::White);
	time_txt2.setPosition(345, 15);
	window.draw(time_txt2);

	if (((static_cast<int> (sec - game_time.asSeconds())) == -1))
		sec += 60;

	time_txt3.setFont(font_bm);
	game_time = game_clock.getElapsedTime();

	scc = static_cast<ostringstream*>(&(ostringstream() << ((static_cast<int> (sec - game_time.asSeconds())))))->str();
	time_txt3.setString(scc);
	time_txt3.setCharacterSize(30);
	time_txt3.setColor(Color::White);
	time_txt3.setPosition(370, 15);
	window.draw(time_txt3);



	if (game_time.asSeconds() >= 240)
	{
		gameover_c = 1;
	}



	life.setFont(font_bm);
	game_time = game_clock.getElapsedTime();

	scc = static_cast<ostringstream*>(&(ostringstream() << (lf)))->str();
	life.setString(scc);
	life.setCharacterSize(30);
	life.setColor(Color::White);
	life.setPosition(480, 15);

	if (lf == -1)
	{
		gameover_c = 1;
	}
	else
		window.draw(life);






}




void playagain_bm()
{


	cl.restart();
	bm_c.restart();

	des_c.restart();
	game_clock.restart();
	bm_death_clock.restart();
	game_over_clock.restart();

	for (int i = 0; i<3; i++)
	{

		en_c[i].restart();

		econst[i] = 0;
		e_c[i] = 0;
		e_c2[3] = 0;
		f[i] = 0;
		enemy_mov[i] = 1;
		enemy_mov_c[i] = 0;
		enemy_mov_c_2[i] = 0; enemy_mov_c_3[i] = 0; enemy_d[3] = 0; e_end[i] = 0;

		enemy_bounds[i].height = NULL;
		enemy_bounds[i].left = NULL;
		enemy_bounds[i].top = NULL;
		enemy_bounds[i].width = NULL;


	}

	cmove = 0; cmove2 = 0; u = 0; l = 0; d = 1; r = 0; b = 1; n1 = 0; n2 = 0; n3 = 0; c2 = 0; c3 = 0; k = 0; start_des = 0; b_c = 0; b_c2 = 0; bm_d = 0; bm_end = 0; bconst = 0; dd = 0;
	bm_bomb1 = 0; bm_bomb2 = 0; bm_x = 0; bm_y = 0; bomb_uu = 0; bomb_dd = 0; bomb_ll = 0; bomb_rr = 0; gate = 0; gate_i = 0; gate_j = 0; sc = 0; lf = 2; sec = 60; gameover_c = 0; enemy_death_times = 0;
	bomberman_end = 0;

	bomb_br.height = NULL;
	bomb_br.width = NULL;
	bomb_br.top = NULL;
	bomb_br.left = NULL;
	bomb_br2.height = NULL;
	bomb_br2.width = NULL;
	bomb_br2.top = NULL;
	bomb_br2.left = NULL;
	bomb_brr.height = NULL;
	bomb_brr.width = NULL;
	bomb_brr.top = NULL;
	bomb_brr.left = NULL;
	blocks_bounds.height = NULL;
	blocks_bounds.top = NULL;
	blocks_bounds.left = NULL;
	blocks_bounds.width = NULL;
	//	Sprite mainsp,bombsp,ex_c_s,ex_r_s,ex_l_s,ex_u_s,ex_d_s,window_sp,blocks_sp[3],blocks_des_sp[7],enemy_sp[3],bm_d_sp[8],gate_sp,gameover_sp;
	/*Vector2f bm_pos,bm_pos2,size(90,30),size2(30,90),block_pos,first,bm_pos3;
	FloatRect bomb_br,bomb_br2,bmbounds,enemy_bounds[3],blocks_bounds,border_l(0,0,65,600),border_r(728,0,72,600),border_u(0,0,800,80),border_d(0,577,800,23),bomb_brr;
	FloatRect bomb_u,bomb_d,bomb_l,bomb_r;
	*/

	//Text score_txt,life,time_txt,time_txt2,time_txt3;
	//Font font_bm;
	//string scc,lff;
}










//pacman :
//_________________________________________________________________





void pacmanMotion()
{

	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))     //start of left motion
	{
		x = 'l';
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))			//start of down motion 
	{
		x = 'd';
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))                   //start of right motion 
	{
		x = 'r';
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))						//start of up motion 
	{
		x = 'u';
	}

	switch (x)
	{
		//left motion
	case 'l':
	{
				pacmanSPRITE.move(Vector2f(-speed, 0));
				if (counter == 1)
				{
					pacmanTEXTURE.loadFromFile("image\\left1.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 2)
				{
					pacmanTEXTURE.loadFromFile("image\\left2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 3)
				{
					pacmanTEXTURE.loadFromFile("image\\close.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 4)
				{
					pacmanTEXTURE.loadFromFile("image\\left2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
					counter = 0;
				}
				counter++;
				break;
	}//end of left motion
		//right motion
	case 'r':
	{
				pacmanSPRITE.move(Vector2f(speed, 0));
				if (counter == 1)
				{

					pacmanTEXTURE.loadFromFile("image\\right1.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 2)
				{
					pacmanTEXTURE.loadFromFile("image\\right2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 3)
				{
					pacmanTEXTURE.loadFromFile("image\\close.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 4)
				{
					pacmanTEXTURE.loadFromFile("image\\right2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
					counter = 0;
				}
				counter++;
				break;
	}//end of right motion
		//up motion
	case 'u':
	{
				pacmanSPRITE.move(Vector2f(0, -speed));
				if (counter == 1)
				{

					pacmanTEXTURE.loadFromFile("image\\up1.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 2)
				{
					pacmanTEXTURE.loadFromFile("image\\up2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 3)
				{
					pacmanTEXTURE.loadFromFile("image\\close.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 4)
				{
					pacmanTEXTURE.loadFromFile("image\\up2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
					counter = 0;
				}
				counter++;
				break;
	}//end of up motion
		//down motion
	case 'd':
	{
				pacmanSPRITE.move(Vector2f(0, speed));
				if (counter == 1)
				{

					pacmanTEXTURE.loadFromFile("image\\down1.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 2)
				{
					pacmanTEXTURE.loadFromFile("image\\down2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 3)
				{
					pacmanTEXTURE.loadFromFile("image\\close.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
				}
				else if (counter == 4)
				{
					pacmanTEXTURE.loadFromFile("image\\down2.png");
					pacmanSPRITE.setTexture(pacmanTEXTURE);
					counter = 0;
				}
				counter++;
				break;
	}
	}															//end of down motion
	if (position.X <= 25 && position.Y <= 279 && position.Y >= 245)
	{
		pacmanSPRITE.setPosition(Vector2f(440, 250));
	}
	else if (position.X >= 450 && position.Y >= 245 && position.Y <= 280)
	{
		pacmanSPRITE.setPosition(Vector2f(30, 250));
	}

}
void pacmanDEAD()
{
	speed = 0;
	if (x == 'u')
	{

		if (dead == 1)
		{
			pacmanTEXTURE.loadFromFile("image\\dead1-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 2)
		{
			pacmanTEXTURE.loadFromFile("image\\dead2-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 3)
		{
			pacmanTEXTURE.loadFromFile("image\\dead3-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 4)
		{
			pacmanTEXTURE.loadFromFile("image\\dead4-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 5)
		{
			pacmanTEXTURE.loadFromFile("image\\dead5-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 6)
		{
			pacmanTEXTURE.loadFromFile("image\\dead6-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 7)
		{
			pacmanTEXTURE.loadFromFile("image\\dead7-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 8)
		{
			pacmanTEXTURE.loadFromFile("image\\dead8-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 9)
		{
			pacmanTEXTURE.loadFromFile("image\\dead9-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 10)
		{
			pacmanTEXTURE.loadFromFile("image\\dead10-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 11)
		{
			pacmanTEXTURE.loadFromFile("image\\dead11-up.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
			dead = 0;
			i = 260;
			j = 407;
			x = 's';
			counter = 1;
			lives--;
			counter2 = 1;
			counter3 = -14;
			counter4 = -29;
			counter5 = -40;
		}
		dead++;
		window.draw(pacmanSPRITE);
	}







	if (x == 'd')
	{

		if (dead == 1)
		{
			pacmanTEXTURE.loadFromFile("image\\dead1-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 2)
		{
			pacmanTEXTURE.loadFromFile("image\\dead2-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 3)
		{
			pacmanTEXTURE.loadFromFile("image\\dead3-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 4)
		{
			pacmanTEXTURE.loadFromFile("image\\dead4-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 5)
		{
			pacmanTEXTURE.loadFromFile("image\\dead5-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 6)
		{
			pacmanTEXTURE.loadFromFile("image\\dead6-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 7)
		{
			pacmanTEXTURE.loadFromFile("image\\dead7-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 8)
		{
			pacmanTEXTURE.loadFromFile("image\\dead8-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 9)
		{
			pacmanTEXTURE.loadFromFile("image\\dead9-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 10)
		{
			pacmanTEXTURE.loadFromFile("image\\dead10-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 11)
		{
			pacmanTEXTURE.loadFromFile("image\\dead11-down.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
			dead = 0;
			i = 260;
			j = 407;
			x = 's';
			counter = 1;
			lives--;
			counter2 = 1;
			counter3 = -14;
			counter4 = -29;
			counter5 = -40;
		}
		dead++;
		window.draw(pacmanSPRITE);
	}








	if (x == 'r')
	{

		if (dead == 1)
		{
			pacmanTEXTURE.loadFromFile("image\\dead1-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 2)
		{
			pacmanTEXTURE.loadFromFile("image\\dead2-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 3)
		{
			pacmanTEXTURE.loadFromFile("image\\dead3-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 4)
		{
			pacmanTEXTURE.loadFromFile("image\\dead4-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 5)
		{
			pacmanTEXTURE.loadFromFile("image\\dead5-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 6)
		{
			pacmanTEXTURE.loadFromFile("image\\dead6-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 7)
		{
			pacmanTEXTURE.loadFromFile("image\\dead7-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 8)
		{
			pacmanTEXTURE.loadFromFile("image\\dead8-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 9)
		{
			pacmanTEXTURE.loadFromFile("image\\dead9-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 10)
		{
			pacmanTEXTURE.loadFromFile("image\\dead10-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 11)
		{
			pacmanTEXTURE.loadFromFile("image\\dead11-right.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
			dead = 0;
			i = 260;
			j = 407;
			x = 's';
			counter = 1;
			lives--;
			counter2 = 1;
			counter3 = -14;
			counter4 = -29;
			counter5 = -40;
		}
		dead++;
		window.draw(pacmanSPRITE);
	}







	if (x == 'l')
	{

		if (dead == 1)
		{
			pacmanTEXTURE.loadFromFile("image\\dead1-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 2)
		{
			pacmanTEXTURE.loadFromFile("image\\dead2-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 3)
		{
			pacmanTEXTURE.loadFromFile("image\\dead3-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 4)
		{
			pacmanTEXTURE.loadFromFile("image\\dead4-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
		}
		else if (dead == 5)
		{
			pacmanTEXTURE.loadFromFile("image\\dead5-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 6)
		{
			pacmanTEXTURE.loadFromFile("image\\dead6-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 7)
		{
			pacmanTEXTURE.loadFromFile("image\\dead7-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 8)
		{
			pacmanTEXTURE.loadFromFile("image\\dead8-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 9)
		{
			pacmanTEXTURE.loadFromFile("image\\dead9-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 10)
		{
			pacmanTEXTURE.loadFromFile("image\\dead10-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);

		}
		else if (dead == 11)
		{
			pacmanTEXTURE.loadFromFile("image\\dead11-left.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
			dead = 0;
			i = 260;
			j = 407;
			x = 's';
			counter = 1;
			lives--;
			counter2 = 1;
			counter3 = -14;
			counter4 = -29;
			counter5 = -40;
		}
		dead++;
		window.draw(pacmanSPRITE);
	}
}
void EnemiesMotion()
{

	//red enemy motion
	if (counter2 == 1 || counter2 == 606)
	{
		redTEXTURE.loadFromFile("image\\red-left1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.setPosition(Vector2f(242, 202));
		counter2 = 1;
	}
	//GO LEFT 1
	else if (counter2 == 2 || counter2 == 4 || counter2 == 6 || counter2 == 8 || counter2 == 10 || counter2 == 12 || counter2 == 14 || counter2 == 16 || counter2 == 28 || counter2 == 30 || counter2 == 32 || counter2 == 34 || counter2 == 36 || counter2 == 38 || counter2 == 60 || counter2 == 62 || counter2 == 64 || counter2 == 66 || counter2 == 68 || counter2 == 70 || counter2 == 72 || counter2 == 74 || counter2 == 104 || counter2 == 106 || counter2 == 108 || counter2 == 110 || counter2 == 320 || counter2 == 322 || counter2 == 324 || counter2 == 326 || counter2 == 328 || counter2 == 330 || counter2 == 332 || counter2 == 334 || counter2 == 336 || counter2 == 338 || counter2 == 340 || counter2 == 342 || counter2 == 344 || counter2 == 346 || counter2 == 348 || counter2 == 350 || counter2 == 352 || counter2 == 354 || counter2 == 356 || counter2 == 358 || counter2 == 360 || counter2 == 362 || counter2 == 364 || counter2 == 366 || counter2 == 368 || counter2 == 370 || counter2 == 372 || counter2 == 374 || counter2 == 376 || counter2 == 378 || counter2 == 380 || counter2 == 382 || counter2 == 384 || counter2 == 386 || counter2 == 388 || counter2 == 390 || counter2 == 392 || counter2 == 394 || counter2 == 396 || counter2 == 398 || counter2 == 400 || counter2 == 402 || counter2 == 404 || counter2 == 482 || counter2 == 484 || counter2 == 486 || counter2 == 488 || counter2 == 490 || counter2 == 492 || counter2 == 494 || counter2 == 496 || counter2 == 498 || counter2 == 500 || counter2 == 502 || counter2 == 504 || counter2 == 512 || counter2 == 514 || counter2 == 516 || counter2 == 518 || counter2 == 520 || counter2 == 522 || counter2 == 524 || counter2 == 526 || counter2 == 528 || counter2 == 562 || counter2 == 564 || counter2 == 566 || counter2 == 568 || counter2 == 570 || counter2 == 582 || counter2 == 584 || counter2 == 586 || counter2 == 588 || counter2 == 590 || counter2 == 602 || counter2 == 604)
	{
		redTEXTURE.loadFromFile("image\\red-left2.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(-speed, 0));
	}

	//GO LEFT 2
	else if (counter2 == 3 || counter2 == 5 || counter2 == 7 || counter2 == 9 || counter2 == 11 || counter2 == 13 || counter2 == 15 || counter2 == 17 || counter2 == 29 || counter2 == 31 || counter2 == 33 || counter2 == 35 || counter2 == 37 || counter2 == 59 || counter2 == 61 || counter2 == 63 || counter2 == 65 || counter2 == 67 || counter2 == 69 || counter2 == 71 || counter2 == 73 || counter2 == 75 || counter2 == 105 || counter2 == 107 || counter2 == 109 || counter2 == 319 || counter2 == 321 || counter2 == 323 || counter2 == 325 || counter2 == 327 || counter2 == 329 || counter2 == 331 || counter2 == 333 || counter2 == 335 || counter2 == 337 || counter2 == 339 || counter2 == 341 || counter2 == 343 || counter2 == 345 || counter2 == 347 || counter2 == 349 || counter2 == 351 || counter2 == 353 || counter2 == 355 || counter2 == 357 || counter2 == 359 || counter2 == 361 || counter2 == 363 || counter2 == 365 || counter2 == 367 || counter2 == 369 || counter2 == 371 || counter2 == 373 || counter2 == 375 || counter2 == 377 || counter2 == 379 || counter2 == 381 || counter2 == 383 || counter2 == 385 || counter2 == 387 || counter2 == 389 || counter2 == 391 || counter2 == 393 || counter2 == 395 || counter2 == 397 || counter2 == 399 || counter2 == 401 || counter2 == 403 || counter2 == 405 || counter2 == 483 || counter2 == 485 || counter2 == 487 || counter2 == 489 || counter2 == 491 || counter2 == 493 || counter2 == 495 || counter2 == 497 || counter2 == 499 || counter2 == 501 || counter2 == 503 || counter2 == 505 || counter2 == 509 || counter2 == 511 || counter2 == 513 || counter2 == 515 || counter2 == 517 || counter2 == 519 || counter2 == 521 || counter2 == 523 || counter2 == 525 || counter2 == 527 || counter2 == 529 || counter2 == 561 || counter2 == 563 || counter2 == 565 || counter2 == 567 || counter2 == 569 || counter2 == 583 || counter2 == 585 || counter2 == 587 || counter2 == 589 || counter2 == 591 || counter2 == 603 || counter2 == 605)
	{
		redTEXTURE.loadFromFile("image\\red-left1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(-speed, 0));
	}

	//GO DOWN 1
	else if (counter2 == 18 || counter2 == 20 || counter2 == 22 || counter2 == 24 || counter2 == 26 || counter2 == 39 || counter2 == 41 || counter2 == 43 || counter2 == 45 || counter2 == 47 || counter2 == 49 || counter2 == 51 || counter2 == 53 || counter2 == 55 || counter2 == 57 || counter2 == 77 || counter2 == 79 || counter2 == 81 || counter2 == 83 || counter2 == 85 || counter2 == 87 || counter2 == 95 || counter2 == 97 || counter2 == 99 || counter2 == 101 || counter2 == 103 || counter2 == 111 || counter2 == 113 || counter2 == 115 || counter2 == 117 || counter2 == 119 || counter2 == 305 || counter2 == 307 || counter2 == 309 || counter2 == 311 || counter2 == 313 || counter2 == 315 || counter2 == 317 || counter2 == 437 || counter2 == 439 || counter2 == 441 || counter2 == 443 || counter2 == 445 || counter2 == 447 || counter2 == 449 || counter2 == 451 || counter2 == 453 || counter2 == 455 || counter2 == 457 || counter2 == 459 || counter2 == 461 || counter2 == 463 || counter2 == 465 || counter2 == 467 || counter2 == 469 || counter2 == 471 || counter2 == 473 || counter2 == 475 || counter2 == 477 || counter2 == 479 || counter2 == 481 || counter2 == 571 || counter2 == 573 || counter2 == 575 || counter2 == 577 || counter2 == 579 || counter2 == 581 || counter2 == 592 || counter2 == 594 || counter2 == 596 || counter2 == 598 || counter2 == 600)
	{
		redTEXTURE.loadFromFile("image\\red-down1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(0, speed));
	}
	//GO DOWN 2

	else if (counter2 == 19 || counter2 == 21 || counter2 == 23 || counter2 == 25 || counter2 == 27 || counter2 == 40 || counter2 == 42 || counter2 == 44 || counter2 == 46 || counter2 == 48 || counter2 == 50 || counter2 == 52 || counter2 == 54 || counter2 == 56 || counter2 == 58 || counter2 == 76 || counter2 == 78 || counter2 == 80 || counter2 == 82 || counter2 == 84 || counter2 == 86 || counter2 == 96 || counter2 == 98 || counter2 == 100 || counter2 == 102 || counter2 == 112 || counter2 == 114 || counter2 == 116 || counter2 == 118 || counter2 == 120 || counter2 == 306 || counter2 == 308 || counter2 == 310 || counter2 == 312 || counter2 == 314 || counter2 == 316 || counter2 == 318 || counter2 == 438 || counter2 == 440 || counter2 == 442 || counter2 == 444 || counter2 == 446 || counter2 == 448 || counter2 == 450 || counter2 == 452 || counter2 == 454 || counter2 == 456 || counter2 == 458 || counter2 == 460 || counter2 == 462 || counter2 == 464 || counter2 == 466 || counter2 == 468 || counter2 == 470 || counter2 == 472 || counter2 == 474 || counter2 == 476 || counter2 == 478 || counter2 == 480 || counter2 == 572 || counter2 == 574 || counter2 == 576 || counter2 == 578 || counter2 == 580 || counter2 == 593 || counter2 == 595 || counter2 == 597 || counter2 == 599 || counter2 == 601)
	{
		redTEXTURE.loadFromFile("image\\red-down2.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(0, speed));
	}
	//Go right 1
	else if (counter2 == 88 || counter2 == 90 || counter2 == 92 || counter2 == 94 || counter2 == 122 || counter2 == 124 || counter2 == 126 || counter2 == 128 || counter2 == 130 || counter2 == 132 || counter2 == 134 || counter2 == 136 || counter2 == 138 || counter2 == 140 || counter2 == 142 || counter2 == 144 || counter2 == 146 || counter2 == 148 || counter2 == 150 || counter2 == 152 || counter2 == 154 || counter2 == 156 || counter2 == 158 || counter2 == 160 || counter2 == 162 || counter2 == 164 || counter2 == 166 || counter2 == 168 || counter2 == 170 || counter2 == 182 || counter2 == 184 || counter2 == 186 || counter2 == 188 || counter2 == 190 || counter2 == 202 || counter2 == 204 || counter2 == 206 || counter2 == 208 || counter2 == 210 || counter2 == 288 || counter2 == 290 || counter2 == 292 || counter2 == 294 || counter2 == 296 || counter2 == 298 || counter2 == 300 || counter2 == 420 || counter2 == 302 || counter2 == 304 || counter2 == 422 || counter2 == 424 || counter2 == 426 || counter2 == 428 || counter2 == 430 || counter2 == 432 || counter2 == 434 || counter2 == 436)
	{
		redTEXTURE.loadFromFile("image\\red-right1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(speed, 0));
	}
	//GO RIGHT 2
	else if (counter2 == 89 || counter2 == 91 || counter2 == 93 || counter2 == 123 || counter2 == 125 || counter2 == 127 || counter2 == 129 || counter2 == 131 || counter2 == 133 || counter2 == 135 || counter2 == 137 || counter2 == 139 || counter2 == 141 || counter2 == 143 || counter2 == 145 || counter2 == 147 || counter2 == 149 || counter2 == 151 || counter2 == 153 || counter2 == 155 || counter2 == 157 || counter2 == 159 || counter2 == 161 || counter2 == 163 || counter2 == 165 || counter2 == 167 || counter2 == 169 || counter2 == 181 || counter2 == 183 || counter2 == 185 || counter2 == 187 || counter2 == 189 || counter2 == 201 || counter2 == 203 || counter2 == 205 || counter2 == 207 || counter2 == 209 || counter2 == 211 || counter2 == 289 || counter2 == 291 || counter2 == 293 || counter2 == 295 || counter2 == 297 || counter2 == 299 || counter2 == 301 || counter2 == 303 || counter2 == 421 || counter2 == 423 || counter2 == 425 || counter2 == 427 || counter2 == 429 || counter2 == 431 || counter2 == 433 || counter2 == 435)
	{
		redTEXTURE.loadFromFile("image\\red-right2.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(speed, 0));

	}

	//GO UP 1
	else if (counter2 == 171 || counter2 == 173 || counter2 == 175 || counter2 == 177 || counter2 == 179 || counter2 == 191 || counter2 == 193 || counter2 == 195 || counter2 == 197 || counter2 == 199 || counter2 == 213 || counter2 == 215 || counter2 == 217 || counter2 == 219 || counter2 == 221 || counter2 == 223 || counter2 == 225 || counter2 == 227 || counter2 == 229 || counter2 == 231 || counter2 == 233 || counter2 == 235 || counter2 == 237 || counter2 == 239 || counter2 == 241 || counter2 == 243 || counter2 == 245 || counter2 == 247 || counter2 == 249 || counter2 == 251 || counter2 == 253 || counter2 == 255 || counter2 == 257 || counter2 == 259 || counter2 == 261 || counter2 == 263 || counter2 == 265 || counter2 == 267 || counter2 == 269 || counter2 == 271 || counter2 == 273 || counter2 == 275 || counter2 == 277 || counter2 == 279 || counter2 == 281 || counter2 == 283 || counter2 == 285 || counter2 == 287 || counter2 == 407 || counter2 == 409 || counter2 == 411 || counter2 == 413 || counter2 == 415 || counter2 == 417 || counter2 == 419 || counter2 == 531 || counter2 == 533 || counter2 == 535 || counter2 == 537 || counter2 == 539 || counter2 == 541 || counter2 == 543 || counter2 == 545 || counter2 == 547 || counter2 == 549 || counter2 == 551 || counter2 == 553 || counter2 == 555 || counter2 == 557 || counter2 == 559)
	{
		redTEXTURE.loadFromFile("image\\red-up2.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(0, -speed));

	}
	//GO UP 2
	else if (counter2 == 172 || counter2 == 174 || counter2 == 176 || counter2 == 178 || counter2 == 180 || counter2 == 192 || counter2 == 194 || counter2 == 196 || counter2 == 198 || counter2 == 200 || counter2 == 212 || counter2 == 214 || counter2 == 216 || counter2 == 218 || counter2 == 220 || counter2 == 222 || counter2 == 224 || counter2 == 226 || counter2 == 228 || counter2 == 230 || counter2 == 232 || counter2 == 234 || counter2 == 236 || counter2 == 238 || counter2 == 240 || counter2 == 242 || counter2 == 244 || counter2 == 246 || counter2 == 248 || counter2 == 250 || counter2 == 252 || counter2 == 254 || counter2 == 256 || counter2 == 258 || counter2 == 260 || counter2 == 262 || counter2 == 264 || counter2 == 266 || counter2 == 268 || counter2 == 270 || counter2 == 272 || counter2 == 274 || counter2 == 276 || counter2 == 278 || counter2 == 280 || counter2 == 282 || counter2 == 284 || counter2 == 286 || counter2 == 406 || counter2 == 408 || counter2 == 410 || counter2 == 412 || counter2 == 414 || counter2 == 416 || counter2 == 418 || counter2 == 530 || counter2 == 532 || counter2 == 534 || counter2 == 536 || counter2 == 538 || counter2 == 540 || counter2 == 542 || counter2 == 544 || counter2 == 546 || counter2 == 548 || counter2 == 550 || counter2 == 552 || counter2 == 554 || counter2 == 556 || counter2 == 558 || counter2 == 560)
	{

		redTEXTURE.loadFromFile("image\\red-up1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.move(Vector2f(0, -speed));
	}

	//shift to right
	else if (counter2 == 510)
	{
		redTEXTURE.loadFromFile("image\\red-left1.png");
		redSPRITE.setTexture(redTEXTURE);
		redSPRITE.setPosition(Vector2f(462, 250));

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//THE ORANGE ENEMY
	if (counter3 == -13 || counter3 == -11 || counter3 == -9 || counter3 == -7)
	{
		orangeTEXTURE.loadFromFile("image\\orange-down1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
	}

	else if (counter3 == -14 || counter3 == -12 || counter3 == -10 || counter3 == -8 || counter3 == -6)
	{
		orangeTEXTURE.loadFromFile("image\\orange-down2.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.setPosition(Vector2f(240, 260));
	}

	else if (counter3 == 1 || counter3 == 606)
	{
		orangeTEXTURE.loadFromFile("image\\orange-right1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.setPosition(Vector2f(236, 202));
		counter3 = 1;
	}
	//GO right 1
	else if (counter3 == 2 || counter3 == 4 || counter3 == 6 || counter3 == 8 || counter3 == 10 || counter3 == 12 || counter3 == 14 || counter3 == 16 || counter3 == 28 || counter3 == 30 || counter3 == 32 || counter3 == 34 || counter3 == 36 || counter3 == 38 || counter3 == 60 || counter3 == 62 || counter3 == 64 || counter3 == 66 || counter3 == 68 || counter3 == 70 || counter3 == 72 || counter3 == 74 || counter3 == 104 || counter3 == 106 || counter3 == 108 || counter3 == 110 || counter3 == 320 || counter3 == 322 || counter3 == 324 || counter3 == 326 || counter3 == 328 || counter3 == 330 || counter3 == 332 || counter3 == 334 || counter3 == 336 || counter3 == 338 || counter3 == 340 || counter3 == 342 || counter3 == 344 || counter3 == 346 || counter3 == 348 || counter3 == 350 || counter3 == 352 || counter3 == 354 || counter3 == 356 || counter3 == 358 || counter3 == 360 || counter3 == 362 || counter3 == 364 || counter3 == 366 || counter3 == 368 || counter3 == 370 || counter3 == 372 || counter3 == 374 || counter3 == 376 || counter3 == 378 || counter3 == 380 || counter3 == 382 || counter3 == 384 || counter3 == 386 || counter3 == 388 || counter3 == 390 || counter3 == 392 || counter3 == 394 || counter3 == 396 || counter3 == 398 || counter3 == 400 || counter3 == 402 || counter3 == 404 || counter3 == 482 || counter3 == 484 || counter3 == 486 || counter3 == 488 || counter3 == 490 || counter3 == 492 || counter3 == 494 || counter3 == 496 || counter3 == 498 || counter3 == 500 || counter3 == 502 || counter3 == 504 || counter3 == 512 || counter3 == 514 || counter3 == 516 || counter3 == 518 || counter3 == 520 || counter3 == 522 || counter3 == 524 || counter3 == 526 || counter3 == 528 || counter3 == 562 || counter3 == 564 || counter3 == 566 || counter3 == 568 || counter3 == 570 || counter3 == 582 || counter3 == 584 || counter3 == 586 || counter3 == 588 || counter3 == 590 || counter3 == 602 || counter3 == 604)
	{
		orangeTEXTURE.loadFromFile("image\\orange-right2.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(speed, 0));
	}
	//GO right 2
	else if (counter3 == 3 || counter3 == 5 || counter3 == 7 || counter3 == 9 || counter3 == 11 || counter3 == 13 || counter3 == 15 || counter3 == 17 || counter3 == 29 || counter3 == 31 || counter3 == 33 || counter3 == 35 || counter3 == 37 || counter3 == 59 || counter3 == 61 || counter3 == 63 || counter3 == 65 || counter3 == 67 || counter3 == 69 || counter3 == 71 || counter3 == 73 || counter3 == 75 || counter3 == 105 || counter3 == 107 || counter3 == 109 || counter3 == 319 || counter3 == 321 || counter3 == 323 || counter3 == 325 || counter3 == 327 || counter3 == 329 || counter3 == 331 || counter3 == 333 || counter3 == 335 || counter3 == 337 || counter3 == 339 || counter3 == 341 || counter3 == 343 || counter3 == 345 || counter3 == 347 || counter3 == 349 || counter3 == 351 || counter3 == 353 || counter3 == 355 || counter3 == 357 || counter3 == 359 || counter3 == 361 || counter3 == 363 || counter3 == 365 || counter3 == 367 || counter3 == 369 || counter3 == 371 || counter3 == 373 || counter3 == 375 || counter3 == 377 || counter3 == 379 || counter3 == 381 || counter3 == 383 || counter3 == 385 || counter3 == 387 || counter3 == 389 || counter3 == 391 || counter3 == 393 || counter3 == 395 || counter3 == 397 || counter3 == 399 || counter3 == 401 || counter3 == 403 || counter3 == 405 || counter3 == 483 || counter3 == 485 || counter3 == 487 || counter3 == 489 || counter3 == 491 || counter3 == 493 || counter3 == 495 || counter3 == 497 || counter3 == 499 || counter3 == 501 || counter3 == 503 || counter3 == 505 || counter3 == 509 || counter3 == 511 || counter3 == 513 || counter3 == 515 || counter3 == 517 || counter3 == 519 || counter3 == 521 || counter3 == 523 || counter3 == 525 || counter3 == 527 || counter3 == 529 || counter3 == 561 || counter3 == 563 || counter3 == 565 || counter3 == 567 || counter3 == 569 || counter3 == 583 || counter3 == 585 || counter3 == 587 || counter3 == 589 || counter3 == 591 || counter3 == 603 || counter3 == 605)
	{
		orangeTEXTURE.loadFromFile("image\\orange-right1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(speed, 0));
	}

	//GO DOWN 1
	else if (counter3 == 18 || counter3 == 20 || counter3 == 22 || counter3 == 24 || counter3 == 26 || counter3 == 39 || counter3 == 41 || counter3 == 43 || counter3 == 45 || counter3 == 47 || counter3 == 49 || counter3 == 51 || counter3 == 53 || counter3 == 55 || counter3 == 57 || counter3 == 77 || counter3 == 79 || counter3 == 81 || counter3 == 83 || counter3 == 85 || counter3 == 87 || counter3 == 95 || counter3 == 97 || counter3 == 99 || counter3 == 101 || counter3 == 103 || counter3 == 111 || counter3 == 113 || counter3 == 115 || counter3 == 117 || counter3 == 119 || counter3 == 305 || counter3 == 307 || counter3 == 309 || counter3 == 311 || counter3 == 313 || counter3 == 315 || counter3 == 317 || counter3 == 437 || counter3 == 439 || counter3 == 441 || counter3 == 443 || counter3 == 445 || counter3 == 447 || counter3 == 449 || counter3 == 451 || counter3 == 453 || counter3 == 455 || counter3 == 457 || counter3 == 459 || counter3 == 461 || counter3 == 463 || counter3 == 465 || counter3 == 467 || counter3 == 469 || counter3 == 471 || counter3 == 473 || counter3 == 475 || counter3 == 477 || counter3 == 479 || counter3 == 481 || counter3 == 571 || counter3 == 573 || counter3 == 575 || counter3 == 577 || counter3 == 579 || counter3 == 581 || counter3 == 592 || counter3 == 594 || counter3 == 596 || counter3 == 598 || counter3 == 600)
	{
		orangeTEXTURE.loadFromFile("image\\orange-down1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(0, speed));
	}
	//GO DOWN 2

	else if (counter3 == 19 || counter3 == 21 || counter3 == 23 || counter3 == 25 || counter3 == 27 || counter3 == 40 || counter3 == 42 || counter3 == 44 || counter3 == 46 || counter3 == 48 || counter3 == 50 || counter3 == 52 || counter3 == 54 || counter3 == 56 || counter3 == 58 || counter3 == 76 || counter3 == 78 || counter3 == 80 || counter3 == 82 || counter3 == 84 || counter3 == 86 || counter3 == 96 || counter3 == 98 || counter3 == 100 || counter3 == 102 || counter3 == 112 || counter3 == 114 || counter3 == 116 || counter3 == 118 || counter3 == 120 || counter3 == 306 || counter3 == 308 || counter3 == 310 || counter3 == 312 || counter3 == 314 || counter3 == 316 || counter3 == 318 || counter3 == 438 || counter3 == 440 || counter3 == 442 || counter3 == 444 || counter3 == 446 || counter3 == 448 || counter3 == 450 || counter3 == 452 || counter3 == 454 || counter3 == 456 || counter3 == 458 || counter3 == 460 || counter3 == 462 || counter3 == 464 || counter3 == 466 || counter3 == 468 || counter3 == 470 || counter3 == 472 || counter3 == 474 || counter3 == 476 || counter3 == 478 || counter3 == 480 || counter3 == 572 || counter3 == 574 || counter3 == 576 || counter3 == 578 || counter3 == 580 || counter3 == 593 || counter3 == 595 || counter3 == 597 || counter3 == 599 || counter3 == 601)
	{
		orangeTEXTURE.loadFromFile("image\\orange-down2.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(0, speed));
	}
	//Go left 1
	else if (counter3 == 88 || counter3 == 90 || counter3 == 92 || counter3 == 94 || counter3 == 122 || counter3 == 124 || counter3 == 126 || counter3 == 128 || counter3 == 130 || counter3 == 132 || counter3 == 134 || counter3 == 136 || counter3 == 138 || counter3 == 140 || counter3 == 142 || counter3 == 144 || counter3 == 146 || counter3 == 148 || counter3 == 150 || counter3 == 152 || counter3 == 154 || counter3 == 156 || counter3 == 158 || counter3 == 160 || counter3 == 162 || counter3 == 164 || counter3 == 166 || counter3 == 168 || counter3 == 170 || counter3 == 182 || counter3 == 184 || counter3 == 186 || counter3 == 188 || counter3 == 190 || counter3 == 202 || counter3 == 204 || counter3 == 206 || counter3 == 208 || counter3 == 210 || counter3 == 288 || counter3 == 290 || counter3 == 292 || counter3 == 294 || counter3 == 296 || counter3 == 298 || counter3 == 300 || counter3 == 420 || counter3 == 302 || counter3 == 304 || counter3 == 422 || counter3 == 424 || counter3 == 426 || counter3 == 428 || counter3 == 430 || counter3 == 432 || counter3 == 434 || counter3 == 436)
	{
		orangeTEXTURE.loadFromFile("image\\orange-left1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(-speed, 0));
	}
	//GO left 2
	else if (counter3 == 89 || counter3 == 91 || counter3 == 93 || counter3 == 123 || counter3 == 125 || counter3 == 127 || counter3 == 129 || counter3 == 131 || counter3 == 133 || counter3 == 135 || counter3 == 137 || counter3 == 139 || counter3 == 141 || counter3 == 143 || counter3 == 145 || counter3 == 147 || counter3 == 149 || counter3 == 151 || counter3 == 153 || counter3 == 155 || counter3 == 157 || counter3 == 159 || counter3 == 161 || counter3 == 163 || counter3 == 165 || counter3 == 167 || counter3 == 169 || counter3 == 181 || counter3 == 183 || counter3 == 185 || counter3 == 187 || counter3 == 189 || counter3 == 201 || counter3 == 203 || counter3 == 205 || counter3 == 207 || counter3 == 209 || counter3 == 211 || counter3 == 289 || counter3 == 291 || counter3 == 293 || counter3 == 295 || counter3 == 297 || counter3 == 299 || counter3 == 301 || counter3 == 303 || counter3 == 421 || counter3 == 423 || counter3 == 425 || counter3 == 427 || counter3 == 429 || counter3 == 431 || counter3 == 433 || counter3 == 435)
	{
		orangeTEXTURE.loadFromFile("image\\orange-left2.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(-speed, 0));
	}

	//GO UP 1
	else if (counter3 == -5 || counter3 == -3 || counter3 == -1 || counter3 == 171 || counter3 == 173 || counter3 == 175 || counter3 == 177 || counter3 == 179 || counter3 == 191 || counter3 == 193 || counter3 == 195 || counter3 == 197 || counter3 == 199 || counter3 == 213 || counter3 == 215 || counter3 == 217 || counter3 == 219 || counter3 == 221 || counter3 == 223 || counter3 == 225 || counter3 == 227 || counter3 == 229 || counter3 == 231 || counter3 == 233 || counter3 == 235 || counter3 == 237 || counter3 == 239 || counter3 == 241 || counter3 == 243 || counter3 == 245 || counter3 == 247 || counter3 == 249 || counter3 == 251 || counter3 == 253 || counter3 == 255 || counter3 == 257 || counter3 == 259 || counter3 == 261 || counter3 == 263 || counter3 == 265 || counter3 == 267 || counter3 == 269 || counter3 == 271 || counter3 == 273 || counter3 == 275 || counter3 == 277 || counter3 == 279 || counter3 == 281 || counter3 == 283 || counter3 == 285 || counter3 == 287 || counter3 == 407 || counter3 == 409 || counter3 == 411 || counter3 == 413 || counter3 == 415 || counter3 == 417 || counter3 == 419 || counter3 == 531 || counter3 == 533 || counter3 == 535 || counter3 == 537 || counter3 == 539 || counter3 == 541 || counter3 == 543 || counter3 == 545 || counter3 == 547 || counter3 == 549 || counter3 == 551 || counter3 == 553 || counter3 == 555 || counter3 == 557 || counter3 == 559)
	{
		orangeTEXTURE.loadFromFile("image\\orange-up2.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(0, -speed));
	}
	//GO UP 2
	else if (counter3 == -4 || counter3 == -2 || counter3 == 0 || counter3 == 172 || counter3 == 174 || counter3 == 176 || counter3 == 178 || counter3 == 180 || counter3 == 192 || counter3 == 194 || counter3 == 196 || counter3 == 198 || counter3 == 200 || counter3 == 212 || counter3 == 214 || counter3 == 216 || counter3 == 218 || counter3 == 220 || counter3 == 222 || counter3 == 224 || counter3 == 226 || counter3 == 228 || counter3 == 230 || counter3 == 232 || counter3 == 234 || counter3 == 236 || counter3 == 238 || counter3 == 240 || counter3 == 242 || counter3 == 244 || counter3 == 246 || counter3 == 248 || counter3 == 250 || counter3 == 252 || counter3 == 254 || counter3 == 256 || counter3 == 258 || counter3 == 260 || counter3 == 262 || counter3 == 264 || counter3 == 266 || counter3 == 268 || counter3 == 270 || counter3 == 272 || counter3 == 274 || counter3 == 276 || counter3 == 278 || counter3 == 280 || counter3 == 282 || counter3 == 284 || counter3 == 286 || counter3 == 406 || counter3 == 408 || counter3 == 410 || counter3 == 412 || counter3 == 414 || counter3 == 416 || counter3 == 418 || counter3 == 530 || counter3 == 532 || counter3 == 534 || counter3 == 536 || counter3 == 538 || counter3 == 540 || counter3 == 542 || counter3 == 544 || counter3 == 546 || counter3 == 548 || counter3 == 550 || counter3 == 552 || counter3 == 554 || counter3 == 556 || counter3 == 558 || counter3 == 560)
	{
		orangeTEXTURE.loadFromFile("image\\orange-up1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.move(Vector2f(0, -speed));
	}

	//shift to right
	else if (counter3 == 510)
	{
		orangeTEXTURE.loadFromFile("image\\orange-right1.png");
		orangeSPRITE.setTexture(orangeTEXTURE);
		orangeSPRITE.setPosition(Vector2f(20, 250));
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//PINK ENEMY MOTION 

	if (counter4 == -29 || counter4 == -27 || counter4 == -25 || counter4 == -23 || counter4 == -21 || counter4 == -19 || counter4 == -17 || counter4 == -15 || counter4 == -13)
	{
		pinkTEXTURE.loadFromFile("image\\pink-down1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.setPosition(Vector2f(205, 260));
	}
	else if (counter4 == -28 || counter4 == -26 || counter4 == -24 || counter4 == -22 || counter4 == -20 || counter4 == -18 || counter4 == -16 || counter4 == -14)
	{
		pinkTEXTURE.loadFromFile("image\\pink-down2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
	}
	else if (counter4 == 1 || counter4 == 631)
	{
		pinkTEXTURE.loadFromFile("image\\pink-left1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.setPosition(Vector2f(242, 202));
		counter4 = 1;
	}
	//go left pinky ^_^
	//LEFT 1
	else if (counter4 == 2 || counter4 == 4 || counter4 == 6 || counter4 == 20 || counter4 == 22 || counter4 == 24 || counter4 == 26 || counter4 == 28 || counter4 == 206 || counter4 == 208 || counter4 == 210 || counter4 == 212 || counter4 == 214 || counter4 == 216 || counter4 == 218 || counter4 == 220 || counter4 == 222 || counter4 == 330 || counter4 == 332 || counter4 == 334 || counter4 == 336 || counter4 == 338 || counter4 == 340 || counter4 == 342 || counter4 == 344 || counter4 == 346 || counter4 == 390 || counter4 == 392 || counter4 == 394 || counter4 == 396 || counter4 == 398 || counter4 == 400 || counter4 == 402 || counter4 == 404 || counter4 == 406 || counter4 == 408 || counter4 == 420 || counter4 == 422 || counter4 == 424 || counter4 == 426 || counter4 == 428 || counter4 == 430 || counter4 == 432 || counter4 == 434 || counter4 == 436 || counter4 == 438 || counter4 == 440 || counter4 == 442 || counter4 == 444 || counter4 == 446 || counter4 == 448 || counter4 == 450 || counter4 == 598 || counter4 == 600 || counter4 == 602 || counter4 == 604 || counter4 == 606 || counter4 == 608 || counter4 == 620 || counter4 == 622 || counter4 == 624 || counter4 == 626 || counter4 == 628 || counter4 == 630)
	{
		pinkTEXTURE.loadFromFile("image\\pink-left1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(-speed, 0));
	}
	//LEFT 2
	else if (counter4 == 3 || counter4 == 5 || counter4 == 7 || counter5 == 19 || counter4 == 21 || counter4 == 23 || counter4 == 25 || counter4 == 27 || counter4 == 29 || counter4 == 207 || counter4 == 209 || counter4 == 211 || counter4 == 213 || counter4 == 215 || counter4 == 217 || counter4 == 219 || counter4 == 221 || counter4 == 331 || counter4 == 333 || counter4 == 335 || counter4 == 337 || counter4 == 339 || counter4 == 341 || counter4 == 343 || counter4 == 345 || counter4 == 389 || counter4 == 391 || counter4 == 393 || counter4 == 395 || counter4 == 397 || counter4 == 399 || counter4 == 401 || counter4 == 403 || counter4 == 405 || counter4 == 407 || counter4 == 409 || counter4 == 421 || counter4 == 423 || counter4 == 425 || counter4 == 427 || counter4 == 429 || counter4 == 431 || counter4 == 433 || counter4 == 435 || counter4 == 437 || counter4 == 439 || counter4 == 441 || counter4 == 443 || counter4 == 445 || counter4 == 447 || counter4 == 449 || counter4 == 451 || counter4 == 599 || counter4 == 601 || counter4 == 603 || counter4 == 605 || counter4 == 607 || counter4 == 619 || counter4 == 621 || counter4 == 623 || counter4 == 625 || counter4 == 627 || counter4 == 629 || counter4 == 631)
	{
		pinkTEXTURE.loadFromFile("image\\pink-left2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(-speed, 0));
	}
	//go up pinky 
	//UP 1

	else if (counter4 == -4 || counter4 == -2 || counter4 == 0 || counter4 == 8 || counter4 == 10 || counter4 == 12 || counter4 == 14 || counter4 == 16 || counter4 == 18 || counter4 == 30 || counter4 == 32 || counter4 == 34 || counter4 == 36 || counter4 == 38 || counter4 == 40 || counter4 == 62 || counter4 == 64 || counter4 == 66 || counter4 == 68 || counter4 == 70 || counter4 == 72 || counter4 == 74 || counter4 == 186 || counter4 == 188 || counter4 == 190 || counter4 == 192 || counter4 == 194 || counter4 == 196 || counter4 == 198 || counter4 == 200 || counter4 == 202 || counter4 == 204 || counter4 == 224 || counter4 == 226 || counter4 == 228 || counter4 == 230 || counter4 == 232 || counter4 == 452 || counter4 == 454 || counter4 == 456 || counter4 == 458 || counter4 == 460 || counter4 == 462 || counter4 == 464 || counter4 == 466 || counter4 == 468 || counter4 == 470 || counter4 == 472 || counter4 == 474 || counter4 == 476 || counter4 == 478 || counter4 == 480 || counter4 == 482 || counter4 == 484 || counter4 == 486 || counter4 == 488 || counter4 == 490 || counter4 == 492 || counter4 == 494 || counter4 == 496 || counter4 == 498 || counter4 == 500 || counter4 == 502 || counter4 == 504 || counter4 == 506 || counter4 == 508 || counter4 == 510 || counter4 == 512 || counter4 == 610 || counter4 == 612 || counter4 == 614 || counter4 == 616 || counter4 == 618)
	{
		pinkTEXTURE.loadFromFile("image\\pink-up2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(0, -speed));
	}
	//UP2
	else if (counter4 == -5 || counter4 == -3 || counter4 == -1 || counter4 == 9 || counter4 == 11 || counter4 == 13 || counter4 == 15 || counter4 == 17 || counter4 == 31 || counter4 == 33 || counter4 == 35 || counter4 == 37 || counter4 == 39 || counter4 == 63 || counter4 == 65 || counter4 == 67 || counter4 == 69 || counter4 == 71 || counter4 == 73 || counter4 == 185 || counter4 == 187 || counter4 == 189 || counter4 == 191 || counter4 == 193 || counter4 == 195 || counter4 == 197 || counter4 == 199 || counter4 == 201 || counter4 == 203 || counter4 == 205 || counter4 == 223 || counter4 == 225 || counter4 == 227 || counter4 == 229 || counter4 == 231 || counter4 == 453 || counter4 == 455 || counter4 == 457 || counter4 == 459 || counter4 == 451 || counter4 == 453 || counter4 == 455 || counter4 == 457 || counter4 == 459 || counter4 == 461 || counter4 == 463 || counter4 == 465 || counter4 == 467 || counter4 == 469 || counter4 == 471 || counter4 == 473 || counter4 == 475 || counter4 == 477 || counter4 == 479 || counter4 == 481 || counter4 == 483 || counter4 == 485 || counter4 == 487 || counter4 == 489 || counter4 == 491 || counter4 == 493 || counter4 == 495 || counter4 == 497 || counter4 == 499 || counter4 == 501 || counter4 == 503 || counter4 == 505 || counter4 == 507 || counter4 == 509 || counter4 == 511 || counter4 == 513 || counter4 == 609 || counter4 == 611 || counter4 == 613 || counter4 == 615 || counter4 == 617)
	{
		pinkTEXTURE.loadFromFile("image\\pink-up1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(0, -speed));
	}
	//go right pinky 
	//RIGHT 1

	else if (counter4 == -11 || counter4 == -9 || counter4 == -7 || counter4 == -5 || counter4 == 41 || counter4 == 43 || counter4 == 45 || counter4 == 47 || counter4 == 49 || counter4 == 51 || counter4 == 53 || counter4 == 55 || counter4 == 57 || counter4 == 59 || counter4 == 61 || counter4 == 75 || counter4 == 77 || counter4 == 79 || counter4 == 81 || counter4 == 83 || counter4 == 85 || counter4 == 87 || counter4 == 89 || counter4 == 91 || counter4 == 93 || counter4 == 95 || counter4 == 143 || counter4 == 145 || counter4 == 147 || counter4 == 149 || counter4 == 151 || counter4 == 153 || counter4 == 155 || counter4 == 157 || counter4 == 159 || counter4 == 161 || counter4 == 163 || counter4 == 165 || counter4 == 169 || counter4 == 171 || counter4 == 173 || counter4 == 175 || counter4 == 177 || counter4 == 179 || counter4 == 181 || counter4 == 183 || counter4 == 233 || counter4 == 235 || counter4 == 237 || counter4 == 239 || counter4 == 241 || counter4 == 243 || counter4 == 245 || counter4 == 247 || counter4 == 249 || counter4 == 251 || counter4 == 253 || counter4 == 255 || counter4 == 257 || counter4 == 259 || counter4 == 261 || counter4 == 263 || counter4 == 265 || counter4 == 267 || counter4 == 269 || counter4 == 271 || counter4 == 273 || counter4 == 275 || counter4 == 277 || counter4 == 279 || counter4 == 281 || counter4 == 283 || counter4 == 285 || counter4 == 287 || counter4 == 289 || counter4 == 291 || counter4 == 293 || counter4 == 295 || counter4 == 297 || counter4 == 299 || counter4 == 301 || counter4 == 303 || counter4 == 305 || counter4 == 307 || counter4 == 309 || counter4 == 311 || counter4 == 313 || counter4 == 315 || counter4 == 317 || counter4 == 319 || counter4 == 515 || counter4 == 517 || counter4 == 519 || counter4 == 521 || counter4 == 523 || counter4 == 525 || counter4 == 527 || counter4 == 529 || counter4 == 531 || counter4 == 533 || counter4 == 535 || counter4 == 537 || counter4 == 539 || counter4 == 541 || counter4 == 543 || counter4 == 545 || counter4 == 547 || counter4 == 549 || counter4 == 551 || counter4 == 553 || counter4 == 555 || counter4 == 557 || counter4 == 559 || counter4 == 561 || counter4 == 563 || counter4 == 565)
	{
		pinkTEXTURE.loadFromFile("image\\pink-right1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(speed, 0));
	}
	//RIGHT2
	else if (counter4 == -12 || counter4 == -10 || counter4 == -8 || counter4 == -6 || counter4 == -4 || counter4 == 42 || counter4 == 44 || counter4 == 46 || counter4 == 48 || counter4 == 50 || counter4 == 52 || counter4 == 54 || counter4 == 56 || counter4 == 58 || counter4 == 60 || counter4 == 76 || counter4 == 78 || counter4 == 80 || counter4 == 82 || counter4 == 84 || counter4 == 86 || counter4 == 8 || counter4 == 90 || counter4 == 92 || counter4 == 94 || counter4 == 96 || counter4 == 144 || counter4 == 146 || counter4 == 148 || counter4 == 150 || counter4 == 152 || counter4 == 154 || counter4 == 156 || counter4 == 158 || counter4 == 160 || counter4 == 162 || counter4 == 164 || counter4 == 166 || counter4 == 168 || counter4 == 170 || counter4 == 172 || counter4 == 174 || counter4 == 176 || counter4 == 178 || counter4 == 180 || counter4 == 182 || counter4 == 184 || counter4 == 234 || counter4 == 236 || counter4 == 238 || counter4 == 240 || counter4 == 242 || counter4 == 244 || counter4 == 246 || counter4 == 248 || counter4 == 250 || counter4 == 252 || counter4 == 254 || counter4 == 256 || counter4 == 258 || counter4 == 260 || counter4 == 262 || counter4 == 264 || counter4 == 266 || counter4 == 268 || counter4 == 270 || counter4 == 272 || counter4 == 274 || counter4 == 276 || counter4 == 278 || counter4 == 280 || counter4 == 282 || counter4 == 284 || counter4 == 286 || counter4 == 288 || counter4 == 290 || counter4 == 292 || counter4 == 294 || counter4 == 296 || counter4 == 298 || counter4 == 300 || counter4 == 302 || counter4 == 304 || counter4 == 306 || counter4 == 308 || counter4 == 310 || counter4 == 312 || counter4 == 314 || counter4 == 316 || counter4 == 318 || counter4 == 514 || counter4 == 516 || counter4 == 518 || counter4 == 520 || counter4 == 522 || counter4 == 524 || counter4 == 526 || counter4 == 528 || counter4 == 530 || counter4 == 532 || counter4 == 534 || counter4 == 536 || counter4 == 538 || counter4 == 540 || counter4 == 542 || counter4 == 544 || counter4 == 546 || counter4 == 548 || counter4 == 550 || counter4 == 552 || counter4 == 554 || counter4 == 556 || counter4 == 558 || counter4 == 560 || counter4 == 562 || counter4 == 564 || counter4 == 566)
	{
		pinkTEXTURE.loadFromFile("image\\pink-right2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(speed, 0));
	}
	//go DOWN pinky 
	//DOWN 1

	else if (counter4 == 97 || counter4 == 99 || counter4 == 101 || counter4 == 103 || counter4 == 105 || counter4 == 107 || counter4 == 109 || counter4 == 111 || counter4 == 113 || counter4 == 115 || counter4 == 117 || counter4 == 119 || counter4 == 121 || counter4 == 123 || counter4 == 125 || counter4 == 127 || counter4 == 129 || counter4 == 131 || counter4 == 133 || counter4 == 135 || counter4 == 137 || counter4 == 139 || counter4 == 141 || counter4 == 321 || counter4 == 323 || counter4 == 325 || counter4 == 327 || counter4 == 329 || counter4 == 347 || counter4 == 349 || counter4 == 351 || counter4 == 353 || counter4 == 355 || counter4 == 357 || counter4 == 359 || counter4 == 361 || counter4 == 363 || counter4 == 365 || counter4 == 367 || counter4 == 369 || counter4 == 371 || counter4 == 373 || counter4 == 375 || counter4 == 377 || counter4 == 379 || counter4 == 381 || counter4 == 383 || counter4 == 385 || counter4 == 387 || counter4 == 411 || counter4 == 413 || counter4 == 415 || counter4 == 417 || counter4 == 419 || counter4 == 567 || counter4 == 569 || counter4 == 571 || counter4 == 573 || counter4 == 575 || counter4 == 577 || counter4 == 579 || counter4 == 581 || counter4 == 583 || counter4 == 585 || counter4 == 587 || counter4 == 589 || counter4 == 591 || counter4 == 593 || counter4 == 595 || counter4 == 597)
	{
		pinkTEXTURE.loadFromFile("image\\pink-down1.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(0, speed));
	}
	//DOWN 2
	else if (counter4 == 98 || counter4 == 102 || counter4 == 104 || counter4 == 106 || counter4 == 108 || counter4 == 110 || counter4 == 112 || counter4 == 114 || counter4 == 116 || counter4 == 118 || counter4 == 120 || counter4 == 122 || counter4 == 124 || counter4 == 126 || counter4 == 128 || counter4 == 130 || counter4 == 132 || counter4 == 134 || counter4 == 136 || counter4 == 138 || counter4 == 140 || counter4 == 142 || counter4 == 320 || counter4 == 322 || counter4 == 324 || counter4 == 326 || counter4 == 328 || counter4 == 348 || counter4 == 350 || counter4 == 352 || counter4 == 354 || counter4 == 356 || counter4 == 358 || counter4 == 360 || counter4 == 362 || counter4 == 364 || counter4 == 366 || counter4 == 368 || counter4 == 370 || counter4 == 372 || counter4 == 374 || counter4 == 376 || counter4 == 378 || counter4 == 380 || counter4 == 382 || counter4 == 384 || counter4 == 386 || counter4 == 388 || counter4 == 410 || counter4 == 412 || counter4 == 414 || counter4 == 416 || counter4 == 418 || counter4 == 570 || counter4 == 568 || counter4 == 570 || counter4 == 572 || counter4 == 574 || counter4 == 576 || counter4 == 578 || counter4 == 580 || counter4 == 582 || counter4 == 584 || counter4 == 586 || counter4 == 588 || counter4 == 590 || counter4 == 592 || counter4 == 594 || counter4 == 596)
	{
		pinkTEXTURE.loadFromFile("image\\pink-down2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.move(Vector2f(0, speed));
	}
	//SHIFT PINKY
	else if (counter4 == 167)
	{
		pinkTEXTURE.loadFromFile("image\\pink-right2.png");
		pinkSPRITE.setTexture(pinkTEXTURE);
		pinkSPRITE.setPosition(Vector2f(20, 250));
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//blue motion 

	if (counter5 == -39 || counter5 == -37 || counter5 == -35 || counter5 == -33 || counter5 == -31 || counter5 == -29 || counter5 == -27 || counter5 == -25 || counter5 == -23 || counter5 == -21 || counter5 == -19 || counter5 == -17 || counter5 == -15 || counter5 == -13)
	{
		blueTEXTURE.loadFromFile("image\\blue-down1.png");
		blueSPRITE.setTexture(blueTEXTURE);
	}
	else if (counter5 == -40 || counter5 == -38 || counter5 == -36 || counter5 == -34 || counter5 == -32 || counter5 == -30 || counter5 == -28 || counter5 == -26 || counter5 == -24 || counter5 == -22 || counter5 == -20 || counter5 == -18 || counter5 == -16 || counter5 == -14)
	{
		blueTEXTURE.loadFromFile("image\\blue-down2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.setPosition(Vector2f(273, 260));

	}
	else if (counter5 == 1 || counter5 == 631)
	{
		blueTEXTURE.loadFromFile("image\\blue-right1.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.setPosition(Vector2f(235, 202));
		counter5 = 1;
	}
	//go right blue 
	//right 1
	else if (counter5 == 2 || counter5 == 4 || counter5 == 6 || counter5 == 19 || counter5 == 20 || counter5 == 22 || counter5 == 24 || counter5 == 26 || counter5 == 28 || counter5 == 206 || counter5 == 208 || counter5 == 210 || counter5 == 212 || counter5 == 214 || counter5 == 216 || counter5 == 218 || counter5 == 220 || counter5 == 222 || counter5 == 330 || counter5 == 332 || counter5 == 334 || counter5 == 336 || counter5 == 338 || counter5 == 340 || counter5 == 342 || counter5 == 344 || counter5 == 346 || counter5 == 390 || counter5 == 392 || counter5 == 394 || counter5 == 396 || counter5 == 398 || counter5 == 400 || counter5 == 402 || counter5 == 404 || counter5 == 406 || counter5 == 408 || counter5 == 420 || counter5 == 422 || counter5 == 424 || counter5 == 426 || counter5 == 428 || counter5 == 430 || counter5 == 432 || counter5 == 434 || counter5 == 436 || counter5 == 438 || counter5 == 440 || counter5 == 442 || counter5 == 444 || counter5 == 446 || counter5 == 448 || counter5 == 450 || counter5 == 598 || counter5 == 600 || counter5 == 602 || counter5 == 604 || counter5 == 606 || counter5 == 608 || counter5 == 620 || counter5 == 622 || counter5 == 624 || counter5 == 626 || counter5 == 628 || counter5 == 630)
	{
		blueTEXTURE.loadFromFile("image\\blue-right1.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(speed, 0));
	}
	//right 2
	else if (counter5 == 3 || counter5 == 5 || counter5 == 7 || counter5 == 21 || counter5 == 23 || counter5 == 25 || counter5 == 27 || counter5 == 29 || counter5 == 207 || counter5 == 209 || counter5 == 211 || counter5 == 213 || counter5 == 215 || counter5 == 217 || counter5 == 219 || counter5 == 221 || counter5 == 331 || counter5 == 333 || counter5 == 335 || counter5 == 337 || counter5 == 339 || counter5 == 341 || counter5 == 343 || counter5 == 345 || counter5 == 389 || counter5 == 391 || counter5 == 393 || counter5 == 395 || counter5 == 397 || counter5 == 399 || counter5 == 401 || counter5 == 403 || counter5 == 405 || counter5 == 407 || counter5 == 409 || counter5 == 421 || counter5 == 423 || counter5 == 425 || counter5 == 427 || counter5 == 429 || counter5 == 431 || counter5 == 433 || counter5 == 435 || counter5 == 437 || counter5 == 439 || counter5 == 441 || counter5 == 443 || counter5 == 445 || counter5 == 447 || counter5 == 449 || counter5 == 451 || counter5 == 599 || counter5 == 601 || counter5 == 603 || counter5 == 605 || counter5 == 607 || counter5 == 619 || counter5 == 621 || counter5 == 623 || counter5 == 625 || counter5 == 627 || counter5 == 629 || counter5 == 631)
	{
		blueTEXTURE.loadFromFile("image\\blue-right2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(speed, 0));
	}
	//go up pinky 
	//UP 1

	else if (counter5 == -4 || counter5 == -2 || counter5 == 0 || counter5 == 8 || counter5 == 10 || counter5 == 12 || counter5 == 14 || counter5 == 16 || counter5 == 18 || counter5 == 30 || counter5 == 32 || counter5 == 34 || counter5 == 36 || counter5 == 38 || counter5 == 40 || counter5 == 62 || counter5 == 64 || counter5 == 66 || counter5 == 68 || counter5 == 70 || counter5 == 72 || counter5 == 74 || counter5 == 186 || counter5 == 188 || counter5 == 190 || counter5 == 192 || counter5 == 194 || counter5 == 196 || counter5 == 198 || counter5 == 200 || counter5 == 202 || counter5 == 204 || counter5 == 224 || counter5 == 226 || counter5 == 228 || counter5 == 230 || counter5 == 232 || counter5 == 452 || counter5 == 454 || counter5 == 456 || counter5 == 458 || counter5 == 460 || counter5 == 462 || counter5 == 464 || counter5 == 466 || counter5 == 468 || counter5 == 470 || counter5 == 472 || counter5 == 474 || counter5 == 476 || counter5 == 478 || counter5 == 480 || counter5 == 482 || counter5 == 484 || counter5 == 486 || counter5 == 488 || counter5 == 490 || counter5 == 492 || counter5 == 494 || counter5 == 496 || counter5 == 498 || counter5 == 500 || counter5 == 502 || counter5 == 504 || counter5 == 506 || counter5 == 508 || counter5 == 510 || counter5 == 512 || counter5 == 610 || counter5 == 612 || counter5 == 614 || counter5 == 616 || counter5 == 618)
	{
		blueTEXTURE.loadFromFile("image\\blue-up2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(0, -speed));
	}
	//UP2
	else if (counter5 == -5 || counter5 == -3 || counter5 == -1 || counter5 == 9 || counter5 == 11 || counter5 == 13 || counter5 == 15 || counter5 == 17 || counter5 == 31 || counter5 == 33 || counter5 == 35 || counter5 == 37 || counter5 == 39 || counter5 == 63 || counter5 == 65 || counter5 == 67 || counter5 == 69 || counter5 == 71 || counter5 == 73 || counter5 == 185 || counter5 == 187 || counter5 == 189 || counter5 == 191 || counter5 == 193 || counter5 == 195 || counter5 == 197 || counter5 == 199 || counter5 == 201 || counter5 == 203 || counter5 == 205 || counter5 == 223 || counter5 == 225 || counter5 == 227 || counter5 == 229 || counter5 == 231 || counter5 == 453 || counter5 == 455 || counter5 == 457 || counter5 == 459 || counter5 == 451 || counter5 == 453 || counter5 == 455 || counter5 == 457 || counter5 == 459 || counter5 == 461 || counter5 == 463 || counter5 == 465 || counter5 == 467 || counter5 == 469 || counter5 == 471 || counter5 == 473 || counter5 == 475 || counter5 == 477 || counter5 == 479 || counter5 == 481 || counter5 == 483 || counter5 == 485 || counter5 == 487 || counter5 == 489 || counter5 == 491 || counter5 == 493 || counter5 == 495 || counter5 == 497 || counter5 == 499 || counter5 == 501 || counter5 == 503 || counter5 == 505 || counter5 == 507 || counter5 == 509 || counter5 == 511 || counter5 == 513 || counter5 == 609 || counter5 == 611 || counter5 == 613 || counter5 == 615 || counter5 == 617)
	{
		blueTEXTURE.loadFromFile("image\\blue-up1.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(0, -speed));
	}
	//go LEFT BLUE
	//left 1

	else if (counter5 == -11 || counter5 == -9 || counter5 == -7 || counter5 == 41 || counter5 == 43 || counter5 == 45 || counter5 == 47 || counter5 == 49 || counter5 == 51 || counter5 == 53 || counter5 == 55 || counter5 == 57 || counter5 == 59 || counter5 == 61 || counter5 == 75 || counter5 == 77 || counter5 == 79 || counter5 == 81 || counter5 == 83 || counter5 == 85 || counter5 == 87 || counter5 == 89 || counter5 == 91 || counter5 == 93 || counter5 == 95 || counter5 == 143 || counter5 == 145 || counter5 == 147 || counter5 == 149 || counter5 == 151 || counter5 == 153 || counter5 == 155 || counter5 == 157 || counter5 == 159 || counter5 == 161 || counter5 == 163 || counter5 == 165 || counter5 == 169 || counter5 == 171 || counter5 == 173 || counter5 == 175 || counter5 == 177 || counter5 == 179 || counter5 == 181 || counter5 == 183 || counter5 == 233 || counter5 == 235 || counter5 == 237 || counter5 == 239 || counter5 == 241 || counter5 == 243 || counter5 == 245 || counter5 == 247 || counter5 == 249 || counter5 == 251 || counter5 == 253 || counter5 == 255 || counter5 == 257 || counter5 == 259 || counter5 == 261 || counter5 == 263 || counter5 == 265 || counter5 == 267 || counter5 == 269 || counter5 == 271 || counter5 == 273 || counter5 == 275 || counter5 == 277 || counter5 == 279 || counter5 == 281 || counter5 == 283 || counter5 == 285 || counter5 == 287 || counter5 == 289 || counter5 == 291 || counter5 == 293 || counter5 == 295 || counter5 == 297 || counter5 == 299 || counter5 == 301 || counter5 == 303 || counter5 == 305 || counter5 == 307 || counter5 == 309 || counter5 == 311 || counter5 == 313 || counter5 == 315 || counter5 == 317 || counter5 == 319 || counter5 == 515 || counter5 == 517 || counter5 == 519 || counter5 == 521 || counter5 == 523 || counter5 == 525 || counter5 == 527 || counter5 == 529 || counter5 == 531 || counter5 == 533 || counter5 == 535 || counter5 == 537 || counter5 == 539 || counter5 == 541 || counter5 == 543 || counter5 == 545 || counter5 == 547 || counter5 == 549 || counter5 == 551 || counter5 == 553 || counter5 == 555 || counter5 == 557 || counter5 == 559 || counter5 == 561 || counter5 == 563 || counter5 == 565)
	{
		blueTEXTURE.loadFromFile("image\\blue-left1.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(-speed, 0));
	}
	//LEFT 2
	else if (counter5 == -12 || counter5 == -10 || counter5 == -8 || counter5 == -6 || counter5 == 42 || counter5 == 44 || counter5 == 46 || counter5 == 48 || counter5 == 50 || counter5 == 52 || counter5 == 54 || counter5 == 56 || counter5 == 58 || counter5 == 60 || counter5 == 76 || counter5 == 78 || counter5 == 80 || counter5 == 82 || counter5 == 84 || counter5 == 86 || counter5 == 8 || counter5 == 90 || counter5 == 92 || counter5 == 94 || counter5 == 96 || counter5 == 144 || counter5 == 146 || counter5 == 148 || counter5 == 150 || counter5 == 152 || counter5 == 154 || counter5 == 156 || counter5 == 158 || counter5 == 160 || counter5 == 162 || counter5 == 164 || counter5 == 166 || counter5 == 168 || counter5 == 170 || counter5 == 172 || counter5 == 174 || counter5 == 176 || counter5 == 178 || counter5 == 180 || counter5 == 182 || counter5 == 184 || counter5 == 234 || counter5 == 236 || counter5 == 238 || counter5 == 240 || counter5 == 242 || counter5 == 244 || counter5 == 246 || counter5 == 248 || counter5 == 250 || counter5 == 252 || counter5 == 254 || counter5 == 256 || counter5 == 258 || counter5 == 260 || counter5 == 262 || counter5 == 264 || counter5 == 266 || counter5 == 268 || counter5 == 270 || counter5 == 272 || counter5 == 274 || counter5 == 276 || counter5 == 278 || counter5 == 280 || counter5 == 282 || counter5 == 284 || counter5 == 286 || counter5 == 288 || counter5 == 290 || counter5 == 292 || counter5 == 294 || counter5 == 296 || counter5 == 298 || counter5 == 300 || counter5 == 302 || counter5 == 304 || counter5 == 306 || counter5 == 308 || counter5 == 310 || counter5 == 312 || counter5 == 314 || counter5 == 316 || counter5 == 318 || counter5 == 514 || counter5 == 516 || counter5 == 518 || counter5 == 520 || counter5 == 522 || counter5 == 524 || counter5 == 526 || counter5 == 528 || counter5 == 530 || counter5 == 532 || counter5 == 534 || counter5 == 536 || counter5 == 538 || counter5 == 540 || counter5 == 542 || counter5 == 544 || counter5 == 546 || counter5 == 548 || counter5 == 550 || counter5 == 552 || counter5 == 554 || counter5 == 556 || counter5 == 558 || counter5 == 560 || counter5 == 562 || counter5 == 564 || counter5 == 566)
	{
		blueTEXTURE.loadFromFile("image\\blue-left2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(-speed, 0));
	}
	//go DOWN BLUE 
	//DOWN 1

	else if (counter5 == 97 || counter5 == 99 || counter5 == 101 || counter5 == 103 || counter5 == 105 || counter5 == 107 || counter5 == 109 || counter5 == 111 || counter5 == 113 || counter5 == 115 || counter5 == 117 || counter5 == 119 || counter5 == 121 || counter5 == 123 || counter5 == 125 || counter5 == 127 || counter5 == 129 || counter5 == 131 || counter5 == 133 || counter5 == 135 || counter5 == 137 || counter5 == 139 || counter5 == 141 || counter5 == 321 || counter5 == 323 || counter5 == 325 || counter5 == 327 || counter5 == 329 || counter5 == 347 || counter5 == 349 || counter5 == 351 || counter5 == 353 || counter5 == 355 || counter5 == 357 || counter5 == 359 || counter5 == 361 || counter5 == 363 || counter5 == 365 || counter5 == 367 || counter5 == 369 || counter5 == 371 || counter5 == 373 || counter5 == 375 || counter5 == 377 || counter5 == 379 || counter5 == 381 || counter5 == 383 || counter5 == 385 || counter5 == 387 || counter5 == 411 || counter5 == 413 || counter5 == 415 || counter5 == 417 || counter5 == 419 || counter5 == 567 || counter5 == 569 || counter5 == 571 || counter5 == 573 || counter5 == 575 || counter5 == 577 || counter5 == 579 || counter5 == 581 || counter5 == 583 || counter5 == 585 || counter5 == 587 || counter5 == 589 || counter5 == 591 || counter5 == 593 || counter5 == 595 || counter5 == 597)
	{
		blueTEXTURE.loadFromFile("image\\blue-down1.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(0, speed));
	}
	//DOWN 2
	else if (counter5 == 98 || counter5 == 102 || counter5 == 104 || counter5 == 106 || counter5 == 108 || counter5 == 110 || counter5 == 112 || counter5 == 114 || counter5 == 116 || counter5 == 118 || counter5 == 120 || counter5 == 122 || counter5 == 124 || counter5 == 126 || counter5 == 128 || counter5 == 130 || counter5 == 132 || counter5 == 134 || counter5 == 136 || counter5 == 138 || counter5 == 140 || counter5 == 142 || counter5 == 320 || counter5 == 322 || counter5 == 324 || counter5 == 326 || counter5 == 328 || counter5 == 348 || counter5 == 350 || counter5 == 352 || counter5 == 354 || counter5 == 356 || counter5 == 358 || counter5 == 360 || counter5 == 362 || counter5 == 364 || counter5 == 366 || counter5 == 368 || counter5 == 370 || counter5 == 372 || counter5 == 374 || counter5 == 376 || counter5 == 378 || counter5 == 380 || counter5 == 382 || counter5 == 384 || counter5 == 386 || counter5 == 388 || counter5 == 410 || counter5 == 412 || counter5 == 414 || counter5 == 416 || counter5 == 418 || counter5 == 570 || counter5 == 568 || counter5 == 570 || counter5 == 572 || counter5 == 574 || counter5 == 576 || counter5 == 578 || counter5 == 580 || counter5 == 582 || counter5 == 584 || counter5 == 586 || counter5 == 588 || counter5 == 590 || counter5 == 592 || counter5 == 594 || counter5 == 596)
	{
		blueTEXTURE.loadFromFile("image\\blue-down2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.move(Vector2f(0, speed));
	}
	//SHIFT BLUE
	else if (counter5 == 167)
	{
		blueTEXTURE.loadFromFile("image\\blue-left2.png");
		blueSPRITE.setTexture(blueTEXTURE);
		blueSPRITE.setPosition(Vector2f(462, 250));
	}
	/////////////////////////////////////////////////////////////////
	//stop moving all enemies
	if (!(counter2 == 1000 && counter3 == 1000 && counter4 == 1000 && counter5 == 1000))
	{
		counter2++;
		counter3++;
		counter4++;
		counter5++;
	}
	window.draw(redSPRITE);
	window.draw(orangeSPRITE);
	window.draw(pinkSPRITE);
	window.draw(blueSPRITE);

}
void pointsDraw()                                  //drowing the points 
{

	FloatRect BOX = pacmanSPRITE.getGlobalBounds();
	pointTEXTURE[0].loadFromFile("image\\point1.png");
	pointTEXTURE[1].loadFromFile("image\\point2.png");
	pointTEXTURE[2].loadFromFile("image\\point3.png");
	pointSPRITE[0].setTexture(pointTEXTURE[0]);

	pointSPRITE[1].setTexture(pointTEXTURE[1]);
	pointSPRITE[2].setTexture(pointTEXTURE[2]);
	float width = 31;
	float length = 36;
	for (int k = 0; k<29; k++)
	{
		for (int kk = 0; kk<26; kk++)
		{
			pointSPRITE[level[k][kk]].setPosition(width, length);
			window.draw(pointSPRITE[level[k][kk]]);
			width += 17.5;
			if (level[k][kk] == 0)
			{
				FloatRect PointBOX = pointSPRITE[0].getGlobalBounds();
				if (BOX.intersects(PointBOX))
				{
					eatBUFFER.loadFromFile("sound\\eat.wav");
					eatSOUND.setBuffer(eatBUFFER);
					eatSOUND.play();
					level[k][kk] = 2;
					ReachVectory++;
					score += 10;
				}
			}
		}
		width = 31;
		length += 17.25;
	}
}
void shapesDraw()
{
	// FIRST ROW OF DRAWINGS 
	box1TEXTURE.loadFromFile("image\\2.png");
	box1SPRITE.setTexture(box1TEXTURE);
	box1SPRITE.setPosition(Vector2f(51, 53.25));
	window.draw(box1SPRITE);

	box2TEXTURE.loadFromFile("image\\1.png");
	box2SPRITE.setTexture(box2TEXTURE);
	box2SPRITE.setPosition(Vector2f(136, 53.25));
	window.draw(box2SPRITE);

	box3TEXTURE.loadFromFile("image\\11.png");
	box3SPRITE.setTexture(box3TEXTURE);
	box3SPRITE.setPosition(Vector2f(241, 15.5));
	window.draw(box3SPRITE);

	box1SPRITE2.setTexture(box2TEXTURE);
	box1SPRITE2.setPosition(Vector2f(293.5, 53.25));
	window.draw(box1SPRITE2);

	box2SPRITE2.setTexture(box1TEXTURE);
	box2SPRITE2.setPosition(Vector2f(398.5, 53.25));
	window.draw(box2SPRITE2);
	// SECOND ROW OF DRAWINGS
	box4TEXTURE.loadFromFile("image\\3.png");
	box4SPRITE.setTexture(box4TEXTURE);
	box4SPRITE.setPosition(Vector2f(51, 122.25));
	window.draw(box4SPRITE);

	box5TEXTURE.loadFromFile("image\\6.png");
	box5SPRITE.setTexture(box5TEXTURE);
	box5SPRITE.setPosition(Vector2f(136, 122.25));
	window.draw(box5SPRITE);

	box6TEXTURE.loadFromFile("image\\10.png");
	box6SPRITE.setTexture(box6TEXTURE);
	box6SPRITE.setPosition(Vector2f(188.5, 122.25));
	window.draw(box6SPRITE);

	box7TEXTURE.loadFromFile("image\\5.png");
	box7SPRITE.setTexture(box7TEXTURE);
	box7SPRITE.setPosition(Vector2f(346, 122.25));
	window.draw(box7SPRITE);

	box4SPRITE2.setTexture(box4TEXTURE);
	box4SPRITE2.setPosition(Vector2f(398.5, 122.25));
	window.draw(box4SPRITE2);
	// THIRD ROW OF DRAWINGS
	box8TEXTURE.loadFromFile("image\\7.png");
	box8SPRITE.setTexture(box8TEXTURE);
	box8SPRITE.setPosition(Vector2f(152, 174));
	window.draw(box8SPRITE);

	box9TEXTURE.loadFromFile("image\\17.png");
	box9SPRITE.setTexture(box9TEXTURE);
	box9SPRITE.setPosition(Vector2f(241, 138));
	window.draw(box9SPRITE);

	box10TEXTURE.loadFromFile("image\\4.png");
	box10SPRITE.setTexture(box10TEXTURE);
	box10SPRITE.setPosition(Vector2f(296.25, 174));
	window.draw(box10SPRITE);
	// FORTH ROW OF DRAWINGS
	box11TEXTURE.loadFromFile("image\\12.png");
	box11SPRITE.setTexture(box11TEXTURE);
	box11SPRITE.setPosition(Vector2f(188.5, 227));
	window.draw(box11SPRITE);
	// FIFTH ROW OF DRAWINGS
	box12TEXTURE.loadFromFile("image\\8.png");
	box12SPRITE.setTexture(box12TEXTURE);
	box12SPRITE.setPosition(Vector2f(136, 277.5));
	window.draw(box12SPRITE);

	box12SPRITE2.setTexture(box12TEXTURE);
	box12SPRITE2.setPosition(Vector2f(346, 277.5));
	window.draw(box12SPRITE2);
	// SIXTH ROW OF DRAWINGS
	box6SPRITE2.setTexture(box6TEXTURE);
	box6SPRITE2.setPosition(Vector2f(188.5, 329.25));
	window.draw(box6SPRITE2);

	box9SPRITE2.setTexture(box9TEXTURE);
	box9SPRITE2.setPosition(Vector2f(241, 345));
	window.draw(box9SPRITE2);
	// SEVENTH ROW OF DRAWINGS
	box13TEXTURE.loadFromFile("image\\15.png");
	box13SPRITE.setTexture(box13TEXTURE);
	box13SPRITE.setPosition(Vector2f(51, 381));
	window.draw(box13SPRITE);

	box14TEXTURE.loadFromFile("image\\21.png");
	box14SPRITE.setTexture(box14TEXTURE);
	box14SPRITE.setPosition(Vector2f(83.5, 398.25));
	window.draw(box14SPRITE);

	box15TEXTURE.loadFromFile("image\\9.png");
	box15SPRITE.setTexture(box15TEXTURE);
	box15SPRITE.setPosition(Vector2f(136, 381));
	window.draw(box15SPRITE);

	box17TEXTURE.loadFromFile("image\\16.png");
	box17SPRITE.setTexture(box17TEXTURE);
	box17SPRITE.setPosition(Vector2f(398.5, 382.5));
	window.draw(box17SPRITE);

	box15SPRITE2.setTexture(box15TEXTURE);
	box15SPRITE2.setPosition(Vector2f(293.5, 381));
	window.draw(box15SPRITE2);

	box16TEXTURE.loadFromFile("image\\22.png");
	box16SPRITE.setTexture(box16TEXTURE);
	box16SPRITE.setPosition(Vector2f(398.5, 398.25));
	window.draw(box16SPRITE);
	// EIGHTTH ROW OF DRAWINGS
	box18TEXTURE.loadFromFile("image\\14.png");
	box18SPRITE.setTexture(box18TEXTURE);
	box18SPRITE.setPosition(Vector2f(13.5, 432.75));
	window.draw(box18SPRITE);

	box19TEXTURE.loadFromFile("image\\13.png");
	box19SPRITE.setTexture(box19TEXTURE);
	box19SPRITE.setPosition(Vector2f(451, 432.75));
	window.draw(box19SPRITE);
	// NINTH ROW OF DRAWINGS
	box6SPRITE3.setTexture(box6TEXTURE);
	box6SPRITE3.setPosition(Vector2f(188.5, 432.75));
	window.draw(box6SPRITE3);

	box9SPRITE3.setTexture(box9TEXTURE);
	box9SPRITE3.setPosition(Vector2f(241, 449.5));
	window.draw(box9SPRITE3);
	// TENTH ROW OF DRAWINGS

	box23TEXTURE.loadFromFile("image\\19.png");
	box23SPRITE.setTexture(box23TEXTURE);
	box23SPRITE.setPosition(Vector2f(293.5, 484.5));
	window.draw(box23SPRITE);

	box24TEXTURE.loadFromFile("image\\20.png");
	box24SPRITE.setTexture(box24TEXTURE);
	box24SPRITE.setPosition(Vector2f(50, 484.5));
	window.draw(box24SPRITE);

	box22TEXTURE.loadFromFile("image\\18.png");
	box22SPRITE.setTexture(box22TEXTURE);
	box22SPRITE.setPosition(Vector2f(135, 432.75));
	window.draw(box22SPRITE);

	box22SPRITE2.setTexture(box22TEXTURE);
	box22SPRITE2.setPosition(Vector2f(345, 432.75));
	window.draw(box22SPRITE2);
}
void collision()
{

	FloatRect BOX = pacmanSPRITE.getGlobalBounds();
	BOX.width -= 5;
	BOX.left += 2.5;
	BOX.height -= 5;
	BOX.top += 2.5;
	FloatRect REDBOX = redSPRITE.getGlobalBounds();
	FloatRect BLUEBOX = blueSPRITE.getGlobalBounds();
	FloatRect ORANGEBOX = orangeSPRITE.getGlobalBounds();
	FloatRect PINKBOX = pinkSPRITE.getGlobalBounds();
	FloatRect BOX1 = box1SPRITE.getGlobalBounds();
	FloatRect BOX2 = box2SPRITE.getGlobalBounds();
	FloatRect BOX3 = box3SPRITE.getGlobalBounds();
	FloatRect BOX4 = box4SPRITE.getGlobalBounds();
	FloatRect BOX5 = box5SPRITE.getGlobalBounds();
	FloatRect BOX6 = box6SPRITE.getGlobalBounds();
	FloatRect BOX7 = box7SPRITE.getGlobalBounds();
	FloatRect BOX8 = box8SPRITE.getGlobalBounds();
	FloatRect BOX9 = box9SPRITE.getGlobalBounds();
	FloatRect BOX10 = box10SPRITE.getGlobalBounds();
	FloatRect BOX11 = box11SPRITE.getGlobalBounds();
	FloatRect BOX12 = box12SPRITE.getGlobalBounds();
	FloatRect BOX13 = box13SPRITE.getGlobalBounds();
	FloatRect BOX14 = box14SPRITE.getGlobalBounds();
	FloatRect BOX15 = box15SPRITE.getGlobalBounds();
	FloatRect BOX16 = box16SPRITE.getGlobalBounds();
	FloatRect BOX17 = box17SPRITE.getGlobalBounds();
	FloatRect BOX18 = box18SPRITE.getGlobalBounds();
	FloatRect BOX19 = box19SPRITE.getGlobalBounds();
	FloatRect BOX20 = box20SPRITE.getGlobalBounds();
	FloatRect BOX21 = box21SPRITE.getGlobalBounds();
	FloatRect BOX22 = box22SPRITE.getGlobalBounds();
	FloatRect BOX23 = box23SPRITE.getGlobalBounds();
	FloatRect BOX24 = box24SPRITE.getGlobalBounds();
	FloatRect BOX25 = box1SPRITE2.getGlobalBounds();
	FloatRect BOX26 = box2SPRITE2.getGlobalBounds();
	FloatRect BOX27 = box4SPRITE2.getGlobalBounds();
	FloatRect BOX28 = box6SPRITE2.getGlobalBounds();
	FloatRect BOX29 = box6SPRITE3.getGlobalBounds();
	FloatRect BOX30 = box9SPRITE2.getGlobalBounds();
	FloatRect BOX31 = box9SPRITE3.getGlobalBounds();
	FloatRect BOX32 = box12SPRITE2.getGlobalBounds();
	FloatRect BOX33 = box15SPRITE2.getGlobalBounds();
	FloatRect BOX34 = box22SPRITE2.getGlobalBounds();
	if (BOX.intersects(BOX1) || BOX.intersects(BOX2) || BOX.intersects(BOX3) || BOX.intersects(BOX4) || BOX.intersects(BOX5) || BOX.intersects(BOX6) || BOX.intersects(BOX7) || BOX.intersects(BOX8) || BOX.intersects(BOX9) || BOX.intersects(BOX10) || BOX.intersects(BOX11) || BOX.intersects(BOX12) || BOX.intersects(BOX13) || BOX.intersects(BOX14) || BOX.intersects(BOX15) || BOX.intersects(BOX16) || BOX.intersects(BOX17) || BOX.intersects(BOX18) || BOX.intersects(BOX19) || BOX.intersects(BOX20) || BOX.intersects(BOX21) || BOX.intersects(BOX22) || BOX.intersects(BOX23) || BOX.intersects(BOX24) || BOX.intersects(BOX25) || BOX.intersects(BOX26) || BOX.intersects(BOX27) || BOX.intersects(BOX28) || BOX.intersects(BOX29) || BOX.intersects(BOX30) || BOX.intersects(BOX31) || BOX.intersects(BOX32) || BOX.intersects(BOX33) || BOX.intersects(BOX34) || (position.Y <= 20) || (position.Y >= 510) || (position.X <= 20) || (position.X >= 460) || (position.X <= 104 && position.Y >= 152 && position.Y <= 248) || (position.X <= 103 && position.Y >= 267 && position.Y <= 350) || (position.X >= 385 && position.Y >= 152 && position.Y <= 248) || (position.X >= 385 && position.Y >= 267 && position.Y <= 350))
	{
		if (x == 'd')
		{
			pacmanTEXTURE.loadFromFile("image\\down1.png");
			pacmanSPRITE.move(Vector2f(0, -speed));
		}
		else if (x == 'u')
		{
			pacmanTEXTURE.loadFromFile("image\\up1.png");
			pacmanSPRITE.move(Vector2f(0, speed));
		}
		else if (x == 'r')
		{
			pacmanTEXTURE.loadFromFile("image\\right1.png");
			pacmanSPRITE.move(Vector2f(-speed, 0));
		}
		else if (x == 'l')
		{
			pacmanTEXTURE.loadFromFile("image\\left1.png");
			pacmanSPRITE.move(Vector2f(speed, 0));
		}
	}
	else
	{
		pacmanMotion();
	}
	if (BOX.intersects(REDBOX) || BOX.intersects(BLUEBOX) || BOX.intersects(ORANGEBOX) || BOX.intersects(PINKBOX))
	{
		counter2 = 1000;
		counter3 = 1000;
		counter4 = 1000;
		counter5 = 1000;
		deadBUFFER.loadFromFile("sound\\Dead.wav");
		deadSOUND.setBuffer(deadBUFFER);
		deadSOUND.play();
		pacmanDEAD();
	}

}
void liveANDscore()
{
	if (lives == 3)
	{
		livesTEXTURE.loadFromFile("image\\lives3.png");
		livesSPRITE.setTexture(livesTEXTURE);
		livesSPRITE.setPosition(Vector2f(10, 560));
	}
	else if (lives == 2)
	{
		livesTEXTURE.loadFromFile("image\\lives2.png");
		livesSPRITE.setTexture(livesTEXTURE);
		livesSPRITE.setPosition(Vector2f(10, 560));

	}
	else if (lives == 1)
	{
		livesTEXTURE.loadFromFile("image\\lives1.png");
		livesSPRITE.setTexture(livesTEXTURE);
		livesSPRITE.setPosition(Vector2f(10, 560));

	}
	else if (lives == 0)
	{
		livesTEXTURE.loadFromFile("image\\game over.png");
		livesSPRITE.setTexture(livesTEXTURE);
		pacman_end = 1;
	}
	font.loadFromFile("font\\BLKCHCRY.TTF");
	text.setFont(font);
	gamescore = static_cast<ostringstream*>(&(ostringstream() << (score)))->str();
	text.setString(gamescore);
	text.setPosition(Vector2f(370, 550));
	text.setColor(Color::White);
	window.draw(livesSPRITE);
	window.draw(text);


	if (ReachVectory == 244)
	{
		pacman_end = 1;
	}

}
void pacman()
{
	score = 0;
	lives = 3;
	ReachVectory == 0;
	while (window.isOpen())
	{
		if (pacman_end == 1)
			break;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			playagain();
		}

		window.clear();
		//backgroung drawing
		levelTEXTURE.loadFromFile("image\\level.png");
		levelSPIRITE.setTexture(levelTEXTURE);
		window.draw(levelSPIRITE);
		//happens only once 
		if (x == 's')
		{
			startBUFFER.loadFromFile("sound\\start.wav");
			startSOUND.setBuffer(startBUFFER);
			startSOUND.play();
			pacmanSPRITE.setPosition(Vector2f(i, j));
			pacmanTEXTURE.loadFromFile("image\\left1.png");
			pacmanSPRITE.setTexture(pacmanTEXTURE);
			x = 'l';
			speed = 5;
		}
		//get the position of the pacman
		position.X = pacmanSPRITE.getPosition().x;
		position.Y = pacmanSPRITE.getPosition().y;
		pointsDraw();
		collision();
		shapesDraw();
		window.draw(pacmanSPRITE);
		EnemiesMotion();
		liveANDscore();
		window.display();
	}
}
void playagain()
{
	int level[29][26] =
	{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 0 },
	{ 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0 },
	{ 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2 },
	{ 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 0, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	struct PacmanPosition
	{
		float X;
		float Y;
	}position;
	float speed = 5;
	float i = 260;										//starting position x
	float j = 407;                                        //starting position y
	char x = 's';                                         //last motion direction
	int counter = 1;                                        // the motion prespector of the pacman
	int dead = 1;
	int lives = 3;
	int counter2 = 1;										//the motion prospector of the red Enemie 
	int counter3 = -14;									//the motion prospector of the orange Enemie
	int counter4 = -29;    								//the motion prospector of the pink Enemie	
	int counter5 = -40;    								//the motion prospector of the blue Enemie	
	int ReachVectory = 0;
	int score = 0;
	int pacman_end = 0;
}