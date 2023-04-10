
#include <SDL.h>
#include <SDL_image.h>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include <SDL_mixer.h>
using namespace std;


const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

const int SPRITE_WIDTH = 25;
const int SPRITE_HEIGHT= 20;
int SPRITE_VELOCITY =1;

void moving(SDL_Rect& a);
void SpawningMeteoroid(SDL_Rect& MeteoroidRect);
void movingMeteoroid(SDL_Rect& meteoroid,float xMeteoroid,float yMeteoroid, float xUFO, float yUFO);

void SpawningCloud(SDL_Rect& Cloud);
void movingCloud(SDL_Rect& Cloud);


void movingFlyingFan(SDL_Rect& FlyingfanRect);
void SpawningAtomicBomb(SDL_Rect& FlyingFanRect,SDL_Rect&AtomicBombRect);
void movingFragment(SDL_Rect** a,int i);

void movingTornado(SDL_Rect& a,int g,int l);

void spawningDogCat(SDL_Rect& a,SDL_Rect& UFORect);
void movingCat(SDL_Rect& CatRect,int a);

void SpawningObject(SDL_Rect& cat,SDL_Rect& object);

bool Detecting_Collision(SDL_Rect& object,SDL_Rect& UFO);



bool init();


bool loadMedia();


void close();

SDL_Texture* loadTexture(string path );

SDL_Texture* loadColorKeyTexture(string path);

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

Mix_Music *gMusic = NULL;
Mix_Chunk* GameOverSound=NULL;


SDL_Texture* GameOver=NULL;
SDL_Texture* Waitingscreen = NULL;
SDL_Texture* LevelOne =NULL;
SDL_Texture* congrat1=NULL;
SDL_Texture* LevelTwo =NULL;
SDL_Texture* congrat2=NULL;
SDL_Texture* LevelThree=NULL;
SDL_Texture* congrat3=NULL;
SDL_Texture* LevelFour=NULL;
SDL_Texture* congrat4=NULL;
SDL_Texture* LevelFive=NULL;
SDL_Texture* congrat5=NULL;
SDL_Texture* LevelSix=NULL;
SDL_Texture* backgroundTexture=NULL;



SDL_Texture* Meteoroid[12];
SDL_Texture* spriteUFO =NULL;

SDL_Texture* Cloud[10];

SDL_Texture* FlyingFanDemo[4];
SDL_Texture* FlyingFan[4];
SDL_Texture* AtomicBomb[4];
SDL_Texture* Explosion[4];
SDL_Texture* Fragment[4][6];

SDL_Texture* Tornado[5];

SDL_Texture* Cat[10];
SDL_Texture* Dog[10];
SDL_Texture* Cat1=NULL;
SDL_Texture* Dog1=NULL;

SDL_Texture* BossState=NULL;
SDL_Texture* BossEating[3];
SDL_Texture* popcorn[5];
SDL_Texture* chocolate[5];
SDL_Texture* pizza[5];
SDL_Texture* nutella[5];

SDL_Texture* endgame[3];

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    return false;
                }
    //Create window
    gWindow = SDL_CreateWindow( "NO MERCY", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }


    return true;
}


bool loadMedia()
{

    gMusic = Mix_LoadMUS( "song.mp3" );
    GameOverSound=Mix_LoadWAV( "soundGameOver.mp3" );
    if( GameOverSound == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    endgame[0]=loadColorKeyTexture( "end/end.png" );
    endgame[1]=loadColorKeyTexture( "end/end1.png" );
    endgame[2]=loadColorKeyTexture("end/end2.png" );
    for (int i=0;i<5;i++)
    {
        popcorn[i]=loadColorKeyTexture( "LV6/popcorn.png" );
        pizza[i]=loadColorKeyTexture( "LV6/pizza.png" );
        nutella[i]=loadColorKeyTexture( "LV6/nutella.png" );
        chocolate[i]=loadColorKeyTexture( "LV6/chocolate.png" );
    }
    BossEating[0]=loadColorKeyTexture( "LV6/boss1.png" );
    BossEating[1]=loadColorKeyTexture( "LV6/boss2.png" );
    BossEating[2]=loadColorKeyTexture( "LV6/boss3.png" );
    for (int i=0;i<4;i++)
        for (int j=0;j<6;j++)
            Fragment[i][j]=loadColorKeyTexture( "LV3/Fragment.png" );
    for (int i=0;i<5;i++)
        Tornado[i]=loadColorKeyTexture( "LV4/Tornado.png" );
    for (int i=0;i<12;i++)
        Meteoroid[i]=NULL;
    for (int i=0;i<4;i++)
        AtomicBomb[i]=NULL;
    for (int i=0;i<10;i++)
        Cloud[i]=NULL;
    for (int i=0;i<4;i++)
        FlyingFan[i]=NULL;

    //Loading success flag
    bool success = true;
    Waitingscreen= loadTexture( "NoMercy!!!.png" );
    if( Waitingscreen == NULL )
    {
        printf( "Failed to load waiting screen image!\n" );
        success = false;
    }
    LevelOne = loadTexture( "waitingScreen/Level1.png" );
    if( LevelOne == NULL )
    {
        printf( "Failed to load Level 1 image!\n" );
        success = false;
    }
    congrat1 = loadTexture( "congrat/congrat1.png" );
    if( congrat1== NULL )
    {
        printf( "Failed to load congrat 1 image!\n" );
        success = false;
    }
    congrat2 = loadTexture( "congrat/congrat2.png" );
    if( congrat2== NULL )
    {
        printf( "Failed to load congrat 2 image!\n" );
        success = false;
    }
    congrat3 = loadTexture( "congrat/congrat3.png" );
    if( congrat3== NULL )
    {
        printf( "Failed to load congrat 3 image!\n" );
        success = false;
    }
    congrat4 = loadTexture( "congrat/congrat4.png" );
    if( congrat4== NULL )
    {
        printf( "Failed to load congrat 4 image!\n" );
        success = false;
    }
    congrat5 = loadTexture( "congrat/congrat5.png" );
    if( congrat5== NULL )
    {
        printf( "Failed to load congrat 5 image!\n" );
        success = false;
    }

    LevelTwo = loadTexture( "waitingScreen/Level2.png" );
    if( LevelTwo == NULL )
    {
        printf( "Failed to load Level 2 image!\n" );
        success = false;
    }
     LevelThree = loadTexture( "waitingScreen/Level3.png" );
    if( LevelThree == NULL )
    {
        printf( "Failed to load Level 3 image!\n" );
        success = false;
    }
    LevelFour = loadTexture( "waitingScreen/Level4.png" );
    if( LevelFour == NULL )
    {
        printf( "Failed to load Level 4 image!\n" );
        success = false;
    }
    LevelFive = loadTexture( "waitingScreen/Level5.png" );
    if( LevelFour == NULL )
    {
        printf( "Failed to load Level 5 image!\n" );
        success = false;
    }
    LevelSix =  loadTexture( "waitingScreen/Level6.png" );
    GameOver = loadColorKeyTexture( "GameOver.png" );
    if( GameOver == NULL )
    {
        printf( "Failed to load game over image!\n" );
        success = false;
    }
    //Load background texture
    backgroundTexture = loadTexture( "background.jpg" );
    if( backgroundTexture == NULL )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }




    //Load sprite texture
    spriteUFO = loadColorKeyTexture("UFO(2).png");
    if( spriteUFO == NULL )
    {
        printf( "Failed to load sprite UFO texture image!\n" );
        success = false;
    }
    for (int i=0;i<12;i++)
    {
    Meteoroid[i] = loadColorKeyTexture( "LV1/meteoroid.png" );
    if( Meteoroid[i] == NULL )
    {
        printf( "Failed to load meteoroid image!\n" );
        success = false;
    }
    }

    for (int i=0;i<10;i++)
    {
        Cloud[i]=loadColorKeyTexture( "LV2/cloud.png" );
         if( Cloud[i] == NULL )
        {
            printf( "Failed to load Cloud image!\n" );
            success = false;
        }
    }
    for (int i=0;i<4;i++)
    {
        AtomicBomb[i]=loadColorKeyTexture( "LV3/AtomicBomb.png" );
         if( AtomicBomb[i] == NULL )
        {
            printf( "Failed to load Cloud image!\n" );
            success = false;
        }
        Explosion[i]=loadColorKeyTexture( "LV3/Explosion.png" );
         if( Explosion[i] == NULL )
        {
            printf( "Failed to load Cloud image!\n" );
            success = false;
        }

    }

    FlyingFan[0]=loadColorKeyTexture("LV3/FlyingFan1.png");
    if( FlyingFan[0] == NULL )
    {
        printf( "Failed to load FlyingFan1 image!\n" );
        success = false;
    }
     FlyingFan[1]=loadColorKeyTexture("LV3/FlyingFan2.png");
    if( FlyingFan[0] == NULL )
    {
        printf( "Failed to load FlyingFan2 image!\n" );
        success = false;
    }
     FlyingFan[2]=loadColorKeyTexture("LV3/FlyingFan3.png");
    if( FlyingFan[0] == NULL )
    {
        printf( "Failed to load FlyingFan3 image!\n" );
        success = false;
    }
     FlyingFan[3]=loadColorKeyTexture("LV3/FlyingFan4.png");
    if( FlyingFan[0] == NULL )
    {
        printf( "Failed to load FlyingFan4 image!\n" );
        success = false;
    }

    Dog1=loadColorKeyTexture("LV5/Dog1.png");
    if( Dog1 == NULL )
    {
        printf( "Failed to load Dog1 image!\n" );
        success = false;
    }

      Cat1=loadColorKeyTexture("LV5/Cat1.png");
    if( Cat1== NULL )
    {
        printf( "Failed to load Cat1 image!\n" );
        success = false;
    }


    return success;
}
void moving (SDL_Rect& a)
{
               const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            if ( a.y >= 0)
                a.y -= SPRITE_VELOCITY;

        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            if ( a.y <=700-SPRITE_HEIGHT )
                a.y += SPRITE_VELOCITY;

        }
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
         if ( a.x >= 0)
            a.x -= SPRITE_VELOCITY;


        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
         if ( a.x <= 1000-SPRITE_WIDTH)
           a.x += SPRITE_VELOCITY;


        }
}
void SpawningMeteoroid(SDL_Rect& MeteoroidRect,SDL_Rect& UFORect)
{
    int a=(rand()+UFORect.x)%4;
    if (a==0)
    {
    MeteoroidRect.x = (rand() % 999)+1;
    MeteoroidRect.y = 0;
    }
    else if (a==1)
    {
        MeteoroidRect.x = 0;
        MeteoroidRect.y = (rand() % 699)+1;
    }
     else if (a==2)
    {
        MeteoroidRect.x = 1000-MeteoroidRect.w;
        MeteoroidRect.y = (rand() % 699)+1;
    }
     else if (a==3)
    {
        MeteoroidRect.x = (rand() % 999)+1;
        MeteoroidRect.y = 700-MeteoroidRect.h;
    }
    MeteoroidRect.w=30;
    MeteoroidRect.h=30;

}
void movingMeteoroid(SDL_Rect& meteoroid,double xMeteoroid,double yMeteoroid, double xUFO, double yUFO)
{
    if (xUFO==xMeteoroid)
        xUFO++;
    if (yUFO==yMeteoroid)
        yUFO++;
    double a=(yUFO-yMeteoroid)/((xUFO-xMeteoroid));
    double b= yUFO-a*xUFO;
    if (abs(xMeteoroid-xUFO)>=abs(yMeteoroid-yUFO))
    {
    if (xMeteoroid<xUFO)
    {
        meteoroid.x+=1;
        meteoroid.y=a*meteoroid.x+b;
    }
    else
    {
        meteoroid.x-=1;
        meteoroid.y=a*meteoroid.x+b;
    }
    }
    else
    {
        if(yMeteoroid<yUFO)
        {
             meteoroid.y+=1;
             meteoroid.x=(meteoroid.y-b)/a;

        }
        else
        {
             meteoroid.y-=1;
             meteoroid.x=(meteoroid.y-b)/a;
        }
    }

}

void SpawningCloud(SDL_Rect& Cloud,int a)
{
    Cloud.x=a*100;
    Cloud.y=0;
}
void movingCloud(SDL_Rect& Cloud)
{

            Cloud.y+=2;

}

void movingFlyingFan(SDL_Rect& FlyingFanRect,int a)
{

    FlyingFanRect.x+=a;
}
void SpawningAtomicBomb(SDL_Rect& FlyingFanRect,SDL_Rect&AtomicBombRect)
{
    AtomicBombRect.x=FlyingFanRect.x;
    AtomicBombRect.y=FlyingFanRect.y;
}
void movingAtomicBomb(SDL_Rect& AtomicBombRect)
{
    AtomicBombRect.y+=2;
}
void movingFragment(SDL_Rect** a,int i)
{
            a[i][0].x++;
            a[i][0].y--;
            a[i][1].x+=2;
            a[i][2].x++;
            a[i][2].y++;
            a[i][3].x--;
            a[i][3].y++;
            a[i][4].x-=2;
            a[i][5].x-=2;
            a[i][5].y-=2;
}

void movingTornado(SDL_Rect& a,int g,int l)
{
    a.x+=g;
    a.y+=l;

}

void spawningDogCat(SDL_Rect& a,SDL_Rect& UFORect,SDL_Rect& CloudRect)
{
    a.y=CloudRect.y;
    a.x=(rand()+UFORect.x)%998+1;
}
void movingCat(SDL_Rect& CatRect,int a)
{
    CatRect.y+=a;
}

void SpawningObject(SDL_Rect& cat,SDL_Rect& object)
{
    object.x=cat.x+150;
    object.y=cat.y+100;
}

bool Detecting_Collision(SDL_Rect& object,SDL_Rect& UFO)
{
    bool a =true;
    if (object.y+object.h-6<UFO.y||object.y+6>UFO.y+UFO.h||object.x+6>UFO.x+UFO.w||object.x+object.w-6<UFO.x)
        a=false;
    return a;
}



void close()
{
    SDL_DestroyTexture(LevelOne);
    LevelOne=NULL;
    SDL_DestroyTexture(LevelTwo);
    LevelTwo=NULL;
    SDL_DestroyTexture(LevelThree);
    LevelThree=NULL;
    SDL_DestroyTexture(LevelFour);
    LevelFour=NULL;
    SDL_DestroyTexture(LevelFive);
    LevelFive=NULL;
    SDL_DestroyTexture(LevelSix);
    LevelSix=NULL;
    SDL_DestroyTexture(congrat1);
    congrat1=NULL;
    SDL_DestroyTexture(congrat2);
    congrat2=NULL;
    SDL_DestroyTexture(congrat3);
    congrat3=NULL;
    SDL_DestroyTexture(congrat4);
    congrat4=NULL;
    SDL_DestroyTexture(congrat5);
    congrat5=NULL;
    for (int i=0;i<3;i++)
        {
            SDL_DestroyTexture(endgame[i]);
            endgame[i]=NULL;
        }
    for (int i=0;i<12;i++)
        {
            SDL_DestroyTexture (Meteoroid[i]);
            Meteoroid[i]=NULL;
        }


    for (int i=0;i<10;i++)
        {
            SDL_DestroyTexture (Cloud[i]);
            Cloud[i]=NULL;
        }

    for (int i=0;i<4;i++)
    {
        SDL_DestroyTexture (FlyingFanDemo[i]);
        FlyingFanDemo[i]=NULL;
        SDL_DestroyTexture (FlyingFan[i]);
        FlyingFan[i]=NULL;
        SDL_DestroyTexture (AtomicBomb[i]);
        AtomicBomb[i]=NULL;
        SDL_DestroyTexture (Explosion[i]);
        Explosion[i]=NULL;
        for (int j=0;j<6;j++)
            {
                SDL_DestroyTexture (Fragment[i][j]);
                Fragment[i][j]=NULL;

            }
    }
    for (int i=0;i<5;i++)
        {
            SDL_DestroyTexture (Tornado[i]);
            Tornado[i]=NULL;
        }
    for (int i=0;i<10;i++)
        {
            SDL_DestroyTexture (Cat[i]);
            SDL_DestroyTexture (Dog[i]);
            Cat[i]=NULL;
            Dog[i]=NULL;
        }
    SDL_DestroyTexture (Cat1);
    Cat1=NULL;
    SDL_DestroyTexture(Dog1);
    Dog1=NULL;
    SDL_DestroyTexture(BossState);
    BossState=NULL;
    for (int i=0;i<3;i++)
        {
            SDL_DestroyTexture (BossEating[i]);
            BossEating[i]=NULL;
        }
    for (int i=0;i<5;i++)
    {
        SDL_DestroyTexture (popcorn[i]);
        SDL_DestroyTexture (chocolate[i]);
        SDL_DestroyTexture (pizza[i]);
        SDL_DestroyTexture (nutella[i]);
        popcorn[i]=NULL;
        chocolate[i]=NULL;
        pizza[i]=NULL;
        nutella[i]=NULL;

    }
	//Free loaded image
    SDL_DestroyTexture(  backgroundTexture );
	backgroundTexture = NULL;
    SDL_DestroyTexture(  Waitingscreen );
	Waitingscreen = NULL;
	SDL_DestroyTexture(  spriteUFO );
    spriteUFO = NULL;
    SDL_DestroyTexture(GameOver);
    LevelOne= NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	Mix_FreeChunk( GameOverSound );
	Mix_FreeMusic(gMusic);
	GameOverSound=NULL;
	gMusic=NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}

SDL_Texture* loadTexture( string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
SDL_Texture* loadColorKeyTexture(string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Get the color key
        Uint32 colorkey = SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF);

        //Set color key
        SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n",path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

int main( int argc, char* args[] )
{

    int a=0;//variable to skip lv
    bool CheckGameOver=true;
//information of lv 1
    int MeteroidNum=0;
    double xMeteoroid[20],yMeteoroid[20],xUFO[20],yUFO[20];
    SDL_Rect UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
    SDL_Rect MeteoroidRect[12] ;

     for (int i=0;i<12;i++)
    {
         MeteoroidRect[i] = {-10 ,-10 , 30, 30 };
    }
    bool chunk=false;

//

//information of Lv2
    SDL_Rect CloudRect[10];
    for (int i=0;i<10;i++)
         {
             CloudRect[i]={760,760,150,100};
         }
    int wavecloud=0;
    int RandomMissingCloud = 5;
//
//information of Lv3
    int wave3=0;
    SDL_Rect FlyingFanRect[4];
    int z=2;
    for (int i=0;i<4;i++)
        {
            FlyingFanRect[i]={z,0,70,70};
            z+=300;
        }

    SDL_Rect** FragmentRect=new SDL_Rect* [4];
    for (int i=0;i<4;i++)
        FragmentRect[i]=new SDL_Rect[6];


    float angle=0;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<6;j++)
            FragmentRect[i][j]={-750,-750,30,30};
    }

    SDL_Rect AtomicBombRect[4];
    for (int i=0;i<4;i++)
        AtomicBombRect[i]={-750,-750,50,50};
    SDL_Rect ExplosionRect[4];

    for (int i=0;i<4;i++)
        ExplosionRect[i]={-750,-750,10,10};

    int MovingLeftRight[4];
    for (int i=0;i<4;i++)
        MovingLeftRight[i]=1;
    int FlyingFanState=0;
    bool explode[4];
    for (int i=0;i<4;i++)
        explode[i]=false;

//
//information of lv4
    SDL_Rect TornadoRect[5];
    for (int i=0;i<5;i++)
        TornadoRect[i]={-750,-750,200,200};
    int x[5];
    int y[5];
    int wave4=0;
    for (int i=0;i<5;i++)
        {
            x[i]=1;
            y[i]=1;
        }
    int state=0;
//
//information of LV5
    SDL_Rect CatRect[10];
    for (int i=0;i<10;i++)
        CatRect[i]={750,750,35,35};
    SDL_Rect DogRect[10];
    for (int i=0;i<10;i++)
        DogRect[i]={800,800,35,35};
    int dogCat=0;

//
//information of LV6
    int bossA=0;
    int l=1;
    SDL_Rect BossRect={350,-280,300,239};
    SDL_Rect popcornRect[5];
    SDL_Rect pizzaRect[5];
    SDL_Rect nutellaRect[5];
    SDL_Rect chocolateRect[5];
    for (int i=0;i<5;i++)
    {
        popcornRect[i]={750,750,50,50};
        pizzaRect[i]={750,750,50,80};
        nutellaRect[i]={750,750,50,60};
        chocolateRect[i]={750,750,50,80};

    }
    SDL_Rect endRect={200,10,150,150};
    SDL_Rect endRect1={50,250,300,300};
    SDL_Rect endRect2={600,250,300,300};
    int meo=0;

    int BossCat =1;
    int conditionToPass=0;

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
		if( !loadMedia() )
            {
                printf( "Failed to load media!\n" );
            }
		else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {

            if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                        Mix_PlayMusic( gMusic, -1 );
                    }
    //waiting screen
                if (a==0)
                {


                        SDL_RenderClear( gRenderer );
                        SDL_RenderCopy( gRenderer, Waitingscreen, NULL, NULL );
                        SDL_RenderPresent( gRenderer );

                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                {
                                    a++;
                                    Mix_VolumeMusic(MIX_MAX_VOLUME/10);
                                }
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;
                            }
                        }

                }
    //


    //level 1 waiting screen
                else if (a==1)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, LevelOne, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                {


                                    a++;
                                }
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                        }
                }
    //


    //level 1 playing
                else if (a==2)
                {

                    //Clear screen
                    SDL_RenderClear( gRenderer );

                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        {
                            moving(UFORect);
                        }

                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );
                    if (CheckGameOver==true)
                        {
                            for (int i=0;i<12;i++)
                                {
                                    if (MeteoroidRect[i].x<=0||MeteoroidRect[i].x>=1000||MeteoroidRect[i].y>=700||MeteoroidRect[i].y<=0)
                                        {
                                            SpawningMeteoroid(MeteoroidRect[i],UFORect);
                                            xMeteoroid[i]=MeteoroidRect[i].x;
                                            yMeteoroid[i]=MeteoroidRect[i].y;
                                            xUFO[i]=UFORect.x;
                                            yUFO[i]=UFORect.y;
                                            MeteroidNum++;
                                        }
                                }
                        }

                    if (CheckGameOver==true)
                        {
                            for (int i=0;i<12;i++)
                                {
                                    movingMeteoroid(MeteoroidRect[i],xMeteoroid[i],yMeteoroid[i],xUFO[i],yUFO[i]);
                                }
                        }

                    for (int i=0;i<12;i++)
                        {
                            SDL_RenderCopy( gRenderer, Meteoroid[i], NULL,&MeteoroidRect[i]);
                        }
                    for (int i=0;i<12;i++)
                    if (Detecting_Collision(MeteoroidRect[i],UFORect)==true)
                        {
                            CheckGameOver=false;
                            SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                            MeteroidNum=0;
                            if (chunk==false)
                                {

                                    Mix_PlayChannel( 0, GameOverSound, 0 );
                                    chunk=true;
                                }

                        }
                    //Update screen
                    if (MeteroidNum>=100)
                        {
                            a++;
                            for (int i=0;i<12;i++)
                                {
                                    MeteoroidRect[i] = {-10 ,-10 , 30, 20 };
                                }
                            UFORect = { 470, SCREEN_HEIGHT-SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT };
                            MeteroidNum=0;
                            chunk=false;

                        }
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                        {
                                    a--;
                                    CheckGameOver=true;
                                    for (int i=0;i<12;i++)
                                {
                                    MeteoroidRect[i] = {-10 ,-10 , 30, 20 };
                                }
                                    UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                                    MeteroidNum=0;
                                chunk=false;
                        }
                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                        quit=true;

                        }
                }
    //

    //congratulation Lv1
                else if (a==3)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, congrat1, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                            a++;
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;

                            }
                        }
                }
    //
    //level 2 waiting screen
                else if (a==4)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, LevelTwo, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                     while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;
                            }
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                {
                                    a++;
                                }

                        }
                }
    //
    //level 2 playing
                else if (a==5)
                {

                    SDL_RenderClear( gRenderer );

                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        moving(UFORect);

                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );
                    if (CloudRect[9-RandomMissingCloud].y>=700&&CheckGameOver==true)
                        {

                        for (int i=0;i<10;i++)
                            {
                                if(i!=RandomMissingCloud)
                                    SpawningCloud(CloudRect[i],i);

                            }
                        wavecloud++;

                        }
                    for (int i=0;i<10;i++)
                        {
                            if(i!=RandomMissingCloud&&CheckGameOver==true)
                                movingCloud(CloudRect[i]);
                        }
                    if (CloudRect[9-RandomMissingCloud].y>=700&&CheckGameOver==true)
                        {
                            int randomNum=(rand()+UFORect.x+UFORect.y)%2;
                            if (randomNum ==0)
                                {if (RandomMissingCloud<8)
                                    RandomMissingCloud+=2;
                                }
                            else
                            {
                                if (RandomMissingCloud>1)
                                    RandomMissingCloud-=2;
                            }

                        }

                    for (int i=0;i<10;i++)
                    {
                    SDL_RenderCopy( gRenderer, Cloud[i], NULL,&CloudRect[i]);
                    }
                    for (int i=0;i<10;i++)
                        if (Detecting_Collision(CloudRect[i],UFORect)==true)
                        {
                            CheckGameOver=false;
                            SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                            wavecloud=0;
                            if (chunk==false)
                                {
                                    Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                    Mix_PlayChannel( -1, GameOverSound, 0 );
                                    chunk=true;
                                }
                        }
                    if (wavecloud>=20)
                        {
                            a++;
                            UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                            for (int i=0;i<10;i++)
                            {
                                CloudRect[i]={750,750,150,100};
                            }
                            wavecloud=0;
                        }
                    SDL_RenderPresent( gRenderer );
                     while( SDL_PollEvent( &e ) != 0 )
                    {
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                        }
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                            {
                                a--;
                                CheckGameOver=true;
                                for (int i=0;i<10;i++)
                                    {
                                        CloudRect[i]={760,760,150,100};
                                    }
                                chunk=false;

                            }
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                            quit=true;

                    }


                }
    //

    //congratulation Lv2
                else if (a==6)
                 {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, congrat2, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                a++;
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;

                            }
                        }
                }
    //waiting screen Lv3
                 else if (a==7)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, LevelThree, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                     while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                {
                                    a++;
                                    CheckGameOver=true;
                                }
                        }
                }
    //level 3 Playing
                else if (a==8)
                {

                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)

                        moving(UFORect);
                    //flying object
                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );
                    for (int i=0;i<4;i++)
                        {
                            FlyingFanDemo[i]=FlyingFan[FlyingFanState/20];
                            SDL_RenderCopy( gRenderer, FlyingFanDemo[i], NULL,& FlyingFanRect[i] );
                            if (CheckGameOver==true)
                                movingFlyingFan(FlyingFanRect[i],MovingLeftRight[i]);
                            if (FlyingFanRect[i].x==930||FlyingFanRect[i].x==0)
                                MovingLeftRight[i]=-MovingLeftRight[i];
                        }
                    FlyingFanState++;
                    if (FlyingFanState>=80)
                        FlyingFanState=0;
                    //
                    //Atomic bomb
                    for (int i=0;i<4;i++)
                        if (abs(FlyingFanRect[i].x-UFORect.x)<=1&&explode[i]==false)
                            {
                                SpawningAtomicBomb(FlyingFanRect[i],AtomicBombRect[i]);
                                wave3++;
                                explode[i]=true;
                            }
                    for (int i=0;i<4;i++)
                        if (AtomicBombRect[i].y>=0)
                            if (CheckGameOver==true)
                                movingAtomicBomb(AtomicBombRect[i]);
                    for (int i=0;i<4;i++)
                        SDL_RenderCopy( gRenderer, AtomicBomb[i], NULL, &AtomicBombRect[i] );
                    for (int i=0;i<4;i++)
                        if (abs(AtomicBombRect[i].y-UFORect.y)<=1)

                            {
                                ExplosionRect[i].x=AtomicBombRect[i].x;
                                ExplosionRect[i].y=AtomicBombRect[i].y;
                                AtomicBombRect[i]={-750,-750,50,50};

                            }

                    for (int i=0;i<4;i++)
                        {
                            if (explode[i]==true)
                                if (ExplosionRect[i].y>0)
                                    if (ExplosionRect[i].w<180)
                                        if (FlyingFanState%2==0)
                                            if (CheckGameOver==true)
                                            {
                                                ExplosionRect[i].w+=6;
                                                ExplosionRect[i].h+=6;
                                                ExplosionRect[i].x-=3;
                                                ExplosionRect[i].y-=3;
                                            }
                        }


                    for (int i=0;i<4;i++)
                        {
                            if (ExplosionRect[i].x>=0&&ExplosionRect[i].w>=160)
                                for (int j=0;j<6;j++)
                                        {
                                            FragmentRect[i][j].x= ExplosionRect[i].x+60;
                                            FragmentRect[i][j].y=ExplosionRect[i].y+60;
                                        }
                            if (ExplosionRect[i].w>=170)
                                ExplosionRect[i]={-750,-750,10,10};


                        }
                      for (int i=0;i<4;i++)
                    {
                            if (FragmentRect[i][0].x>0)
                                if (CheckGameOver==true)
                                    movingFragment(FragmentRect,i);
                    }
                    for (int i=0;i<4;i++)
                    {
                        if (FragmentRect[i][0].x==1000||FragmentRect[i][0].x==0)
                        {
                            for (int j=0;j<6;j++)
                                FragmentRect[i][j]={-750,-750,30,30};
                            {explode[i]=false;}
                        }

                    }

                    for (int i=0;i<4;i++)
                        SDL_RenderCopy( gRenderer, Explosion[i], NULL, &ExplosionRect[i] );
                    for (int i=0;i<4;i++)
                        for (int j=0;j<6;j++)
                             SDL_RenderCopyEx(gRenderer, Fragment[i][j], NULL, &FragmentRect[i][j], angle, NULL, SDL_FLIP_NONE);
                    angle+=1;
                    //colliosion checking
                    for (int i=0;i<4;i++)
                        if (Detecting_Collision(FlyingFanRect[i],UFORect)==true)
                            {
                                wave3=0;
                                CheckGameOver=false;
                                SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                if (chunk==false)
                                {
                                    Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                    Mix_PlayChannel( -1, GameOverSound, 0 );
                                    chunk=true;
                                }
                            }

                    for (int i=0;i<4;i++)
                        if (Detecting_Collision(AtomicBombRect[i],UFORect)==true)
                                  {
                                    wave3=0;
                                    CheckGameOver=false;
                                    SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                    if (chunk==false)
                                        {
                                            Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                            Mix_PlayChannel( -1, GameOverSound, 0 );
                                            chunk=true;
                                        }
                                 }
                    for (int i=0;i<4;i++)
                        if (Detecting_Collision(ExplosionRect[i],UFORect)==true)
                                {
                                    wave3=0;
                                    CheckGameOver=false;
                                    SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                    if (chunk==false)
                                        {
                                            Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                            Mix_PlayChannel( -1, GameOverSound, 0 );
                                            chunk=true;
                                        }
                                }
                    for (int i=0;i<4;i++)
                        for (int j=0;j<6;j++)
                            if (Detecting_Collision(FragmentRect[i][j],UFORect)==true)
                                 {
                                    wave3=0;
                                    CheckGameOver=false;
                                    SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                    if (chunk==false)
                                        {
                                            Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                            Mix_PlayChannel( -1, GameOverSound, 0 );
                                            chunk=true;
                                        }
                                 }
                    if (wave3>=30)
                    {
                        wave3=0;
                        z=2;
                        for (int i=0;i<4;i++)
                            {
                                FlyingFanRect[i]={z,0,70,70};
                                z+=300;
                            }
                        angle=0;

                        for (int i=0;i<4;i++)
                            {
                                for (int j=0;j<6;j++)
                                FragmentRect[i][j]={-750,-750,30,30};
                            }

                        for (int i=0;i<4;i++)
                            AtomicBombRect[i]={-750,-750,50,50};

                        for (int i=0;i<4;i++)
                            ExplosionRect[i]={-750,-750,10,10};


                        for (int i=0;i<4;i++)
                                MovingLeftRight[i]=1;
                        FlyingFanState=0;
                        for (int i=0;i<4;i++)
                        explode[i]=false;
                        a++;
                        UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };


                    }

                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                                {
                                    a--;
                                    CheckGameOver=true;
                                    z=2;
                                    for (int i=0;i<4;i++)
                                        {
                                            FlyingFanRect[i]={z,0,70,70};
                                            z+=300;
                                        }
                                    angle=0;

                                    for (int i=0;i<4;i++)
                                    {
                                        for (int j=0;j<6;j++)
                                            FragmentRect[i][j]={-750,-750,30,30};
                                    }

                                    for (int i=0;i<4;i++)
                                        AtomicBombRect[i]={-750,-750,50,50};

                                    for (int i=0;i<4;i++)
                                        ExplosionRect[i]={-750,-750,10,10};


                                    for (int i=0;i<4;i++)
                                        MovingLeftRight[i]=1;
                                    FlyingFanState=0;
                                    for (int i=0;i<4;i++)
                                        explode[i]=false;
                                    chunk=false;

                                }
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                                quit=true;


                        }
                }
    //

    //congratulation Lv3
                else if (a==9)
                 {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, congrat3, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                a++;
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;

                            }
                        }
                }
     //waiting screen Lv4
                 else if (a==10)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, LevelFour, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                     while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                {
                                    a++;
                                    CheckGameOver=true;
                                }
                        }
                }
    //Level 4 playing
                else if (a==11)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        moving(UFORect);
                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );

                    for (int i=0;i<5;i++)
                        if (TornadoRect[i].h==200||TornadoRect[i].h==0)
                        {
                            SpawningMeteoroid(TornadoRect[i],UFORect);
                            wave4++;
                        }


                    for (int i=0;i<5;i++)
                    {
                        if (TornadoRect[i].x<=0||TornadoRect[i].x+TornadoRect[i].w>=1000)
                            {
                                x[i]=-x[i];
                                if (TornadoRect[i].x<=0)
                                    TornadoRect[i].x+=3;
                                if (TornadoRect[i].x+TornadoRect[i].w>=1000)
                                    TornadoRect[i].x-=3;
                            }
                        if (TornadoRect[i].y<=0||TornadoRect[i].y+TornadoRect[i].h>=700)
                            {
                                y[i]=-y[i];
                                if (TornadoRect[i].y<=0)
                                    TornadoRect[i].y+=3;
                                if (TornadoRect[i].y+TornadoRect[i].h>=700)
                                    TornadoRect[i].y-=3;
                            }
                    }
                    if (CheckGameOver==true)
                      if (FlyingFanState%20!=0)
                            for (int i=0;i<5;i++)
                                {
                                    if (TornadoRect[i].x>0&&TornadoRect[i].x<1000&&TornadoRect[i].y>0&&TornadoRect[i].y<700)
                                        movingTornado(TornadoRect[i],x[i],y[i]);
                                }
                    if(CheckGameOver==true)
                        if (state==0)
                            if (FlyingFanState%20==0)
                                for (int i=0;i<5;i++)
                                    {
                                        TornadoRect[i].w+=2;
                                        TornadoRect[i].h+=2;
                                        TornadoRect[i].x-=1;
                                        TornadoRect[i].y-=1;
                                    }
                    if (TornadoRect[0].w>=190)
                        state=1;
                    if(CheckGameOver==true)
                        if (state==1)
                            if (FlyingFanState%20==0)
                                for (int i=0;i<5;i++)
                                    {
                                        TornadoRect[i].w-=2;
                                        TornadoRect[i].h-=2;
                                        TornadoRect[i].x+=1;
                                        TornadoRect[i].y+=1;
                                    }
                    if (TornadoRect[0].w==0)
                        state=0;
                    FlyingFanState++;
                    if (FlyingFanState>=80)
                        FlyingFanState=0;


                    for (int i=0;i<5;i++)
                        SDL_RenderCopyEx( gRenderer, Tornado[i], NULL, &TornadoRect[i], angle, NULL, SDL_FLIP_NONE);
                    angle+=5;
                    for (int i=0;i<5;i++)
                        if(Detecting_Collision(TornadoRect[i],UFORect)==true)
                            {
                                CheckGameOver=false;
                                SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                if (chunk==false)
                                {
                                    Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                    Mix_PlayChannel( -1, GameOverSound, 0 );
                                    chunk=true;
                                }
                            }
                    if (wave4>=40)
                    {
                        FlyingFanState=0;
                        angle=0;
                        state=0;
                        for (int i=0;i<5;i++)
                            TornadoRect[i]={-750,-750,200,200};
                        for (int i=0;i<5;i++)
                            {
                                x[i]=1;
                                y[i]=1;
                            }
                        wave4=0;
                        a++;
                        UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                    }
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                             if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                                {
                                    a--;
                                    FlyingFanState=0;
                                    angle=0;
                                    state=0;
                                    for (int i=0;i<5;i++)
                                        TornadoRect[i]={-750,-750,200,200};
                                    for (int i=0;i<5;i++)
                                        {
                                            x[i]=1;
                                            y[i]=1;
                                        }
                                    CheckGameOver=true;
                                    wave4=0;
                                    chunk=false;
                                }
                             if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                                quit=true;


                        }
                    SDL_RenderPresent( gRenderer );

                }
    // Congratulation Lv4
                else if (a==12)
                 {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, congrat4, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                a++;
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;

                            }
                        }
                }
    //waiting screen Lv5
               else if (a==13)
                        {
                            SDL_RenderClear( gRenderer );
                            SDL_RenderCopy( gRenderer, LevelFive, NULL, NULL );
                            SDL_RenderPresent( gRenderer );
                             while( SDL_PollEvent( &e ) != 0 )
                                {
                                    if( e.type == SDL_QUIT )
                                        {
                                            quit = true;
                                        }
                                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                        {
                                            a++;
                                            CheckGameOver=true;
                                        }
                                }
                        }
    //Level 5 Playing
                else if (a==14)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        moving(UFORect);
                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );
                    if (CloudRect[0].y==760)
                        for (int i=0;i<10;i++)
                            SpawningCloud(CloudRect[i],i);
                   if (dogCat>9)
                        for (int i=0;i<10;i++)
                            {
                                CloudRect[i].y+=10;
                                dogCat=0;
                            }



                    for (int i=0;i<10;i++)
                        SDL_RenderCopy( gRenderer, Cloud[i], NULL, &CloudRect[i] );
                    //Cat
                    FlyingFanState++;
                    if (FlyingFanState>=80)
                        FlyingFanState=0;
                    for (int i=0;i<10;i++)
                        if ((CatRect[i].y>=750) && (FlyingFanState%10==0))
                            {
                                spawningDogCat(CatRect[i],UFORect,CloudRect[0]);
                                FlyingFanState++;
                            }

                    for (int i=0;i<10;i++)
                        Cat[i]=Cat1;
                    for (int i=0;i<10;i++)
                        SDL_RenderCopy( gRenderer, Cat[i], NULL, &CatRect[i] );


                    for (int i=0;i<10;i++)
                            {
                                if (CatRect[i].y-CloudRect[0].y<200)
                                    {
                                        if (CheckGameOver==true)
                                            movingCat(CatRect[i],1);
                                    }
                                else
                                    {
                                        if (CheckGameOver==true)
                                            movingCat(CatRect[i],3);
                                    }
                            }


                    //
                    //DOG

                    if (CheckGameOver==true)
                        {
                            for (int i=0;i<10;i++)
                                {

                                    if (DogRect[i].y>=650+(rand()+UFORect.x)%150)
                                        {

                                            spawningDogCat( DogRect[i],UFORect,CloudRect[0]);
                                            xMeteoroid[i]=DogRect[i].x;
                                            yMeteoroid[i]=DogRect[i].y;
                                            xUFO[i]=UFORect.x;
                                            yUFO[i]=UFORect.y;
                                            dogCat++;

                                        }
                                }
                        }
                    if (CheckGameOver==true)
                        {
                            for (int i=0;i<10;i++)
                                {
                                    movingMeteoroid(DogRect[i],xMeteoroid[i],yMeteoroid[i],xUFO[i],yUFO[i]);
                                }
                        }
                    for (int i=0;i<10;i++)
                        Dog[i]=Dog1;
                    for (int i=0;i<10;i++)
                        SDL_RenderCopy( gRenderer, Dog[i], NULL, &DogRect[i] );
                    for (int i=0;i<10;i++)
                        if (Detecting_Collision(CatRect[i],UFORect)==true||Detecting_Collision(DogRect[i],UFORect)==true||Detecting_Collision(CloudRect[i],UFORect)==true)
                            {
                                CheckGameOver=false;
                                SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                if (chunk==false)
                                {
                                    Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                    Mix_PlayChannel( -1, GameOverSound, 0 );
                                    chunk=true;
                                }
                            }
                    if (CloudRect[0].y==150)
                    {
                        a++;
                        for (int i=0;i<10;i++)
                                    {
                                        CloudRect[i]={0,z,150,100};
                                    }
                        for (int i=0;i<10;i++)
                            CatRect[i]={750,750,35,35};
                        for (int i=0;i<10;i++)
                            DogRect[i]={800,800,35,35};
                        dogCat=0;
                        UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                        FlyingFanState=0;
                    }

                    //
                      while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                             if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                            {
                                a--;
                                CheckGameOver=true;
                                for (int i=0;i<10;i++)
                                    {
                                        CloudRect[i]={760,760,150,100};
                                    }
                                for (int i=0;i<10;i++)
                                    CatRect[i]={750,750,35,35};
                                for (int i=0;i<10;i++)
                                    DogRect[i]={800,800,35,35};
                                dogCat=0;
                                UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                                chunk=false;

                            }
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                            quit=true;
                        }



                    SDL_RenderPresent( gRenderer );


                }
    //Congratulation Lv5
                 else if (a==15)
                 {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, congrat5, NULL, NULL );
                    SDL_RenderPresent( gRenderer );
                    while( SDL_PollEvent( &e ) != 0 )
                        {
                            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                a++;
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;

                            }
                        }
                }
    //waiting screen Lv6
                else if (a==16)
                {
                         SDL_RenderClear( gRenderer );
                            SDL_RenderCopy( gRenderer, LevelSix, NULL, NULL );
                            SDL_RenderPresent( gRenderer );
                             while( SDL_PollEvent( &e ) != 0 )
                                {
                                    if( e.type == SDL_QUIT )
                                        {
                                            quit = true;
                                        }
                                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
                                        {
                                            a++;
                                            CheckGameOver=true;
                                            for (int i=0;i<10;i++)
                                                SpawningCloud(CloudRect[i],i);
                                        }
                                }
                }
    //boss state 1
                else if (a==17)
                {
                    SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        moving(UFORect);
                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );

                        bossA+=l;
                        if (bossA>=74||bossA<=0)
                            l=-l;

                        BossState=BossEating[bossA/25];
                        if (CheckGameOver==true)
                            if (bossA%3==0)
                                if (BossRect.y<10)

                                    {
                                        movingCat(BossRect,1);
                                        for (int i=0;i<10;i++)
                                            movingCat(CloudRect[i],1);
                                    }

                        SDL_RenderCopy( gRenderer, BossState, NULL, &BossRect );
                        while( SDL_PollEvent( &e ) != 0 )
                            {
                                    if( e.type == SDL_QUIT )
                                        {
                                            quit = true;
                                        }
                                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                                        {
                                            a--;
                                            CheckGameOver=true;
                                            for (int i=0;i<10;i++)
                                                {
                                                    CloudRect[i]={760,760,150,100};
                                                }
                                            bossA=0;
                                            l=1;
                                            BossRect={350,-280,300,239};
                                            for (int i=0;i<5;i++)
                                            {
                                                popcornRect[i]={750,750,50,50};
                                                pizzaRect[i]={750,750,50,80};
                                                nutellaRect[i]={750,750,50,60};
                                                chocolateRect[i]={750,750,50,80};

                                            }
                                            meo=0;

                                            BossCat =1;
                                            conditionToPass=0;
                                            UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };
                                            chunk=false;


                                        }
                                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                                        quit=true;
                            }


                        for (int i=0;i<5;i++)
                            {
                                SDL_RenderCopyEx( gRenderer, nutella[i], NULL, &nutellaRect[i], angle, NULL, SDL_FLIP_NONE);
                                SDL_RenderCopyEx( gRenderer, popcorn[i], NULL, &popcornRect[i], angle, NULL, SDL_FLIP_NONE);
                                SDL_RenderCopyEx( gRenderer, pizza[i], NULL, &pizzaRect[i], angle, NULL, SDL_FLIP_NONE);
                                SDL_RenderCopyEx( gRenderer, chocolate[i], NULL, &chocolateRect[i], angle, NULL, SDL_FLIP_NONE);
                            }
                        for (int i=0;i<10;i++)
                        {
                            SDL_RenderCopy(gRenderer,Cloud[i],NULL,&CloudRect[i]);
                        }
                        angle+=2;
                        if (BossRect.y==10)
                        {
                            if (BossCat==1)
                                if (CheckGameOver==true)
                                    if (CloudRect[RandomMissingCloud].y<700)
                                        {
                                            movingCat(CloudRect[RandomMissingCloud],1);
                                            movingCat(CloudRect[(RandomMissingCloud+5)%10],1);
                                        }
                           if (BossCat==2)
                            {
                                for (int i=0;i<10;i++)
                                    if (CloudRect[i].y>290)
                                        movingCat(CloudRect[i],1);
                            }

                            if (CloudRect[RandomMissingCloud].y>=700)
                            {
                                CloudRect[RandomMissingCloud].y=290;
                                CloudRect[(RandomMissingCloud+5)%10].y=290;
                                RandomMissingCloud=(rand()+UFORect.x)%10;
                            }
                            if (BossCat==1)
                                if (nutellaRect[0].y>=700)
                                                {
                                                    SpawningObject(BossRect,nutellaRect[0]);
                                                    xMeteoroid[0]=nutellaRect[0].x;
                                                    yMeteoroid[0]=nutellaRect[0].y;
                                                    xUFO[0]=UFORect.x;
                                                    yUFO[0]=UFORect.y;

                                                }
                            if(BossCat==1)
                                for (int i=1;i<5;i++)
                                        {

                                            if (nutellaRect[i].y>=700&&nutellaRect[i-1].y>250)
                                                {

                                                    SpawningObject(BossRect,nutellaRect[i]);
                                                    xMeteoroid[i]=nutellaRect[i].x;
                                                    yMeteoroid[i]=nutellaRect[i].y;
                                                    xUFO[i]=UFORect.x;
                                                    yUFO[i]=UFORect.y;

                                                }
                                        }
                            if (CheckGameOver==true)
                                for (int i=0;i<5;i++)
                                {
                                    if (nutellaRect[i].y<750)
                                        movingMeteoroid(nutellaRect[i],xMeteoroid[i],yMeteoroid[i],xUFO[i],yUFO[i]);
                                }
                            if(BossCat==1)
                                if (popcornRect[0].y>=750&&nutellaRect[0].y>270)
                                                {

                                                    SpawningObject(BossRect,popcornRect[0]);
                                                    xMeteoroid[5]=popcornRect[0].x;
                                                    yMeteoroid[5]=popcornRect[0].y;
                                                    xUFO[5]=UFORect.x;
                                                    yUFO[5]=UFORect.y;

                                                }
                            if(BossCat==1)
                                for (int i=1;i<5;i++)
                                        {

                                            if (popcornRect[i].y>=750&&popcornRect[i-1].y>350)
                                                {

                                                    SpawningObject(BossRect,popcornRect[i]);
                                                    xMeteoroid[i+5]=popcornRect[i].x;
                                                    yMeteoroid[i+5]=popcornRect[i].y;
                                                    xUFO[i+5]=UFORect.x;
                                                    yUFO[i+5]=UFORect.y;

                                                }
                                        }
                            if (CheckGameOver==true)
                                for (int i=0;i<5;i++)
                                {
                                    if (popcornRect[i].y<750)
                                        movingMeteoroid(popcornRect[i],xMeteoroid[i+5],yMeteoroid[i+5],xUFO[i+5],yUFO[i+5]);
                                }
                            if(BossCat==1)
                                if (pizzaRect[0].y>=750&&popcornRect[0].y>270)
                                                {

                                                    SpawningObject(BossRect,pizzaRect[0]);
                                                    xMeteoroid[10]=pizzaRect[0].x;
                                                    yMeteoroid[10]=pizzaRect[0].y;
                                                    xUFO[10]=UFORect.x;
                                                    yUFO[10]=UFORect.y;

                                                }
                            if(BossCat==1)
                                for (int i=1;i<5;i++)
                                        {

                                            if (pizzaRect[i].y>=750&&pizzaRect[i-1].y>450)
                                                {

                                                    SpawningObject(BossRect,pizzaRect[i]);
                                                    xMeteoroid[i+10]=pizzaRect[i].x;
                                                    yMeteoroid[i+10]=pizzaRect[i].y;
                                                    xUFO[i+10]=UFORect.x;
                                                    yUFO[i+10]=UFORect.y;

                                                }
                                        }
                            if (CheckGameOver==true)
                                for (int i=0;i<5;i++)
                                {
                                    if (pizzaRect[i].y<750)
                                        movingMeteoroid(pizzaRect[i],xMeteoroid[i+10],yMeteoroid[i+10],xUFO[i+10],yUFO[i+10]);
                                }
                            if(BossCat==1)
                                if (chocolateRect[0].y>=750&&popcornRect[0].y>270)
                                                {

                                                    SpawningObject(BossRect,chocolateRect[0]);
                                                    xMeteoroid[15]=chocolateRect[0].x;
                                                    yMeteoroid[15]=chocolateRect[0].y;
                                                    xUFO[15]=UFORect.x;
                                                    yUFO[15]=UFORect.y;

                                                }
                            if(BossCat==1)
                                for (int i=1;i<5;i++)
                                        {

                                            if (chocolateRect[i].y>=750&&(chocolateRect[i-1].y>250))
                                                {

                                                    SpawningObject(BossRect,chocolateRect[i]);
                                                    xMeteoroid[i+15]=chocolateRect[i].x;
                                                    yMeteoroid[i+15]=chocolateRect[i].y;
                                                    xUFO[i+15]=UFORect.x;
                                                    yUFO[i+15]=UFORect.y;
                                                    conditionToPass++;

                                                }
                                        }
                            if (CheckGameOver==true)
                                for (int i=0;i<5;i++)
                                {
                                    if (chocolateRect[i].y<750)
                                        movingMeteoroid(chocolateRect[i],xMeteoroid[i+15],yMeteoroid[i+15],xUFO[i+15],yUFO[i+15]);
                                }

                            if (conditionToPass>=150)
                            {
                                BossCat=2;
                                conditionToPass=0;
                            }
                        }

                    for (int i=0;i<5;i++)
                            {
                                if (Detecting_Collision(pizzaRect[i],UFORect)==true||Detecting_Collision(popcornRect[i],UFORect)==true||Detecting_Collision(nutellaRect[i],UFORect)==true||Detecting_Collision(chocolateRect[i],UFORect)==true)
                                {
                                    CheckGameOver=false;
                                    conditionToPass=0;
                                    SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                    BossCat=1;
                                    if (chunk==false)
                                {
                                    Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                    Mix_PlayChannel( -1, GameOverSound, 0 );
                                    chunk=true;
                                }
                                }


                            }
                    for (int i=0;i<10;i++)
                            {
                                if (Detecting_Collision(CloudRect[i],UFORect)==true)
                                {
                                    CheckGameOver=false;
                                    conditionToPass=0;
                                    SDL_RenderCopy( gRenderer, GameOver, NULL,NULL);
                                    BossCat=1;
                                    if (chunk==false)
                                        {
                                            Mix_VolumeChunk(GameOverSound, MIX_MAX_VOLUME);
                                            Mix_PlayChannel( -1, GameOverSound, 0 );
                                            chunk=true;
                                        }
                                }

                            }
                    if (BossCat==2)
                    {
                        meo++;
                    }
                    if (meo==1000)
                    {
                        meo=0;
                        BossCat=3;
                    }
                    if (BossCat==3)
                    {
                        movingCat(BossRect,-1);
                        for (int i=0;i<10;i++)
                        {
                            movingCat(CloudRect[i],-1);
                        }
                        if (BossRect.y==-480)
                        {

                            a++;
                        }
                    }
                    SDL_RenderPresent(gRenderer);
                }
    //endgame
                else if (a==18)
                {
                     SDL_RenderClear( gRenderer );
                    SDL_RenderCopy( gRenderer, backgroundTexture, NULL, NULL );
                    if (CheckGameOver==true)
                        moving(UFORect);
                    SDL_RenderCopy( gRenderer, spriteUFO, NULL, &UFORect );
                    if (BossRect.y<10)
                        movingCat(BossRect,1);
                    if (BossRect.y==10)
                    {
                        if (conditionToPass<1000)
                            conditionToPass++;
                        if (conditionToPass>300)
                            SDL_RenderCopy( gRenderer, endgame[0], NULL, &endRect );
                        if (conditionToPass>600)
                            SDL_RenderCopy( gRenderer, endgame[1], NULL, &endRect1 );
                        if (conditionToPass>900)
                            SDL_RenderCopy( gRenderer, endgame[2], NULL, &endRect2 );

                    }
                    if (conditionToPass>=900)
                        CheckGameOver=false;
                    bossA+=l;
                    if (bossA>=74||bossA<=0)
                        l=-l;

                    BossState=BossEating[bossA/25];
                    SDL_RenderCopy( gRenderer, BossState, NULL, &BossRect );

                    while( SDL_PollEvent( &e ) != 0 )
                            {
                                if( e.type == SDL_QUIT )
                                    {
                                        quit = true;
                                    }
                                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1&&CheckGameOver==false)
                                        {
                                            a=0;
                                            CheckGameOver=true;
                                            for (int i=0;i<10;i++)
                                                {
                                                    CloudRect[i]={760,760,150,100};
                                                }
                                            bossA=0;
                                            l=1;
                                            BossRect={350,-280,300,239};

                                            conditionToPass=0;
                                            UFORect = { 470, 325, SPRITE_WIDTH, SPRITE_HEIGHT };


                                        }
                                    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2&&CheckGameOver==false)
                                        {
                                            quit=true;
                                            close();
                                        }


                            }
                    SDL_RenderPresent(gRenderer);
                }

            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

