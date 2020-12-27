#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "game.h"



//quick helper fxn
SDL_Texture* loadSprite(char* path, SDL_Renderer* r){
		SDL_Surface* surf = IMG_Load(path);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(r, surf);
		SDL_FreeSurface(surf);
		return tex;
}

const SDL_Color PLAYER_1_COLOR = {.r = 255, .g = 255, .b = 255};
const SDL_Color PLAYER_2_COLOR = {.r = 50, .g = 100, .b = 255};
const SDL_Color TIE_COLOR = {.r = 100, .g = 100, .b = 100};
const SDL_Color GRID_COLOR = {.r = 255, .g = 255, .b = 255};


void render_grid(SDL_Renderer *renderer, const SDL_Color *color){
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);

	for(int i = 1; i < N; ++i){
		SDL_RenderDrawLine(renderer, i * CELL_WIDTH, 0, i* CELL_WIDTH, WINDOW_HEIGHT);
		SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, WINDOW_WIDTH, i * CELL_HEIGHT);
	}
}

void render_board(SDL_Renderer *renderer, const int *board, const SDL_Color *player_1_color, const SDL_Color *player_2_color){

}

void render_running_state(SDL_Renderer *renderer, const game_t *game){
	render_grid(renderer, &GRID_COLOR);
	render_board(renderer, game->board, &PLAYER_1_COLOR, &PLAYER_2_COLOR);
}

void render_game_over_state(SDL_Renderer *renderer, const game_t *game, const SDL_Color *color){
	render_grid(renderer, color);
	render_board(renderer, game->board, color, color);
}


void render_game(SDL_Renderer *renderer, const game_t *game){
	switch(game->state){
		case RUNNING_STATE:
			render_running_state(renderer, game);
			break;
		case PLAYER_1_WON_STATE:
			render_game_over_state(renderer, game, &PLAYER_1_COLOR);
			break;
		case PLAYER_2_WON_STATE:
			render_game_over_state(renderer, game, &PLAYER_2_COLOR);
			break;


	}
}

void click_on_cell(game_t *game, int row, int column){

}


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); // initializes SDL

	// create window
	SDL_Window* window;
	window = SDL_CreateWindow("Bombplexity",
														WINDOW_POSITION_X, WINDOW_POSITION_Y,
														WINDOW_WIDTH, WINDOW_HEIGHT,
														0); // put remarks here for fullscreen and such

	if (window == NULL){ // check window error
		printf("Could not create window: %s/n", SDL_GetError() );
		return 1;
	}


	// renderer
	SDL_Renderer* renderer = NULL;
	SDL_Texture* pearl = NULL;
	int posX = 100, posY = 100, width = 320, height = 240;

// rendering pearl
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	pearl = loadSprite("bigChungus.png", renderer);


// game state
game_t game = {
	.board = { EMPTY, EMPTY, EMPTY,
			   EMPTY, EMPTY, EMPTY,
			   EMPTY, EMPTY, EMPTY },
	.player = PLAYER_1,
	.state = RUNNING_STATE,
};


//event code
	int done = 0;
	while(game.state != QUIT_STATE){
  	SDL_Event event;
	  while(SDL_PollEvent(&event)){
	      switch (event.type){
					case SDL_QUIT:  game.state = QUIT_STATE;
	              					break;
					case SDL_MOUSEBUTTONDOWN:
												click_on_cell(&game, event.button.y / CELL_HEIGHT,
																	 event.button.x / CELL_WIDTH);
												break;

					default: {}
				}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		//SDL_RenderCopy(renderer, pearl, NULL, NULL);
		render_game(renderer, &game);
		SDL_RenderPresent(renderer);
	}


// destroys and exits
	//SDL_Delay(3000); // pause execution for 3000 milliseconds
	SDL_DestroyTexture(pearl);
  	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window); // close and destroy window

	SDL_Quit(); // quits SDL
	return 0;
}
//mingw32-make
