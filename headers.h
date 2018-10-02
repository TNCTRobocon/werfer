#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/joystick.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include"controller.h"
#include"motor.h"

extern int srid;

#endif
