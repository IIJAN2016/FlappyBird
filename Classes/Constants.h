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
static const float ROTATION_DEGREE_ACCEL     = 700;
static const float ROTATION_MAX_DEGREE       = 90;
static const float ROTATION_MIN_DEGREE       = -30;
static const float ROTATION_THRESHOLD_VELOCITY = -100;
static const std::string KEY_HIGHSCORE = "highScore";

#endif /* Constants_h */
