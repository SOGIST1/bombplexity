#ifndef RENDERING_H_
#define RENDERING_H_

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

#endif // RENDERING_H_
