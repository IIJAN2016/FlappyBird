//
//  Constants.h
//  FlappyBird
//
//  Created by Ken Watanabe on 2016/05/12.
//
//

#ifndef Constants_h
#define Constants_h

static const float GRAVITY_ACCEL      = -1000.0f;
static const float JUMP_SPEED         = 300.0f;
static const float SCROLL_SPEED_X     = 120.0f;
static const float OBSTACLE_INIT_X    = 300.0f;
static const float OBSTACLE_MIN_Y     = 200.0f;
static const float OBSTACLE_MAX_Y     = 400.0f;
static const float OBSTACLE_TIME_SPAN = 1.35f;
static const int   OBSTACLE_LIMIT     = 5;
static const float SOUND_VOLUME       = 0.5f;

static const std::string SOUND_SWOOSHING = "sfx_swooshing.mp3";
static const std::string SOUND_DIE = "sfx_die.mp3";
static const std::string SOUND_HIT = "sfx_hit.mp3";
static const std::string SOUND_POINT = "sfx_point.mp3";
static const std::string SOUND_WING = "sfx_wing.mp3";

#endif /* Constants_h */
