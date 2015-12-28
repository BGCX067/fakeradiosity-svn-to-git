
CREATE_PLAYER
{
	name = "playerone",
	meshfile = "Data/ship.3ds",
	inputconfigname = "InputConfig1",
	speedvertical		= 12.0,
	speedhorizontal		= 25.0,
	angleupmove			= 45.0,
	angledownmove		= -45.0,
	speedtoangleupmove	=3.1,
	speedtoangledownmove=3.1,
	speedtoanglezero=3.1,
	deadzone			=0.05,
	explode_sound = "explode.ogg",
	collisionradius = 0.5,
}

CREATE_INPUT_CONFIG
{
	name = "InputConfig1",
	keyup = X.KEY_KEY_Z,
	keydown = X.KEY_KEY_S,
	keyright = X.KEY_KEY_D,
	keyleft = X.KEY_KEY_Q,
	keyshoot = X.KEY_SPACE,
	joyport=0,
} 

CREATE_WEAPON
{
	name = "Weapon1",
	speed = 15,
	move = X.CWeapon.FORWARD,
	frequency = 500,
	shooter = X.CWeapon.PLAYER,
	shoot_sound = "smudge.wav",
	collisionradius = 1.0,
}
CREATE_LEVEL
{
--	music="data/x.ogg",
	music="data/solid90.wav",
	sound=0,
	
}