#include "../CommandsEnum.h"
#include "MovementController.h"

MovementController::MovementController()
{
	MIN_SPEED = constants.min_speed;
	MAX_SPEED = constants.max_speed;

	pinMode(constants.left_engine_enable, OUTPUT);
	pinMode(constants.left_engine_straight_pin, OUTPUT);
	pinMode(constants.left_engine_reverse_pin, OUTPUT);
	pinMode(constants.right_engine_straight_pin, OUTPUT);
	pinMode(constants.right_engine_reverse_pin, OUTPUT);
	pinMode(constants.right_engine_enable, OUTPUT);

	stop_moving();
}

void MovementController::exec(ConnectingDevice *device, String command) {
	switch (command[1])
	{
	case forward:
		move_forward();
		break;
	case back:
		move_back();
		break;
	case left:
		turn_left();
		break;
	case right: 
		turn_right();
		break;
	case stop:
		stop_moving();
		break;
	case forward_speed:
		move_forward(parse_command(command, 2, command.length()));
		break;
	case forward_time:
		move_forward(MAX_SPEED, parse_command(command, 2, command.length()));
		break;
	case back_speed:
		move_back(parse_command(command, 2, command.length()));
		break;
	case track_set_speed:
		choose_track_set_speed(parse_command(command, 2, constants.commands_delimetr, 2));
		break;
	default:
		break;
	}
	
}


void MovementController::move_forward() {
	left_track_control(forward_direction, MAX_SPEED);
	right_track_control(forward_direction, MAX_SPEED);
}

void MovementController::move_forward(int speed) {
	left_track_control(forward_direction, speed);
	right_track_control(forward_direction, speed);
}

void MovementController::move_forward(int speed, int time_ms) {
	left_track_control(forward_direction, speed);
	right_track_control(forward_direction, speed);
	delay(time_ms);
	stop_moving();
}

void MovementController::move_back() {
	left_track_control(back_direction, MAX_SPEED);
	right_track_control(back_direction, MAX_SPEED);
}

void MovementController::move_back(int speed) {
	left_track_control(back_direction, speed);
	right_track_control(back_direction, speed);
}

void MovementController::turn_left() {
	left_track_control(forward_direction, MAX_SPEED);
	right_track_control(back_direction, MAX_SPEED);
}

void MovementController::turn_right() {
	left_track_control(back_direction, MAX_SPEED);
	right_track_control(forward_direction, MAX_SPEED);
}

void MovementController::stop_moving() {
	analogWrite(constants.left_engine_enable, MIN_SPEED);
	analogWrite(constants.right_engine_enable, MIN_SPEED);
	digitalWrite(constants.left_engine_straight_pin, LOW);
	digitalWrite(constants.left_engine_reverse_pin, LOW);
	digitalWrite(constants.right_engine_straight_pin, LOW);
	digitalWrite(constants.right_engine_reverse_pin, LOW);
}

void MovementController::choose_track_set_speed(int trackID, int speed) {
	switch (trackID)
	{
	case left_track:
		left_track_control(forward_direction, speed);
		break;
	case right_track:
		right_track_control(forward_direction, speed);
		break;
	default:
		break;
	}
}

void MovementController::choose_track_set_speed(int* arr) {
	switch (arr[0])
	{
	case left_track:
		left_track_control(forward_direction, arr[1]);
		break;
	case right_track:
		right_track_control(forward_direction, arr[1]);
		break;
	default:
		break;
	}
}

void MovementController::left_track_control(bool direction, int speed) {
	analogWrite(constants.left_engine_enable, speed);
	switch (direction) {
	case forward_direction:
		digitalWrite(constants.left_engine_straight_pin, LOW);
		digitalWrite(constants.left_engine_reverse_pin, HIGH);
		break;
	
	case back_direction:
		digitalWrite(constants.left_engine_straight_pin, HIGH);
		digitalWrite(constants.left_engine_reverse_pin, LOW);
		break;
	}
}

void MovementController::right_track_control(bool direction, int speed) {
	analogWrite(constants.right_engine_enable, speed);
	switch (direction) {
	case forward_direction:
		digitalWrite(constants.right_engine_straight_pin, LOW);
		digitalWrite(constants.right_engine_reverse_pin, HIGH);
		break;

	case back_direction:
		digitalWrite(constants.right_engine_straight_pin, HIGH);
		digitalWrite(constants.right_engine_reverse_pin, LOW);
		break;
	}
}

MovementController::~MovementController()
{
}